import pygame
from time import time
import numpy as np

def getBezierValue(time, prev_value, next_value, a, b):
    b_val = (1 - time)**2 * a + 2 * time * (1 - time) * b + time**2
    return prev_value + (next_value - prev_value) * b_val

class KeyFrameVariable:
    def __init__(self, value, keyframes):
        self.value = value
        self.keyframes = keyframes
        self.currentTime = 0
        self.currentKeyFrame = 0
        self.absTime = time()

    def update(self):
        actualTime = time()
        dt = actualTime - self.absTime 
        self.absTime = actualTime
        self.currentTime += dt
        nextKeyFrame = (self.currentKeyFrame + 1) % len(self.keyframes)
        if(self.currentTime > self.keyframes[nextKeyFrame]['time']):
            self.currentKeyFrame += 1
            if self.currentKeyFrame == len(self.keyframes):
                self.currentKeyFrame = 0
                self.currentTime -= self.keyframes[-1]['time']
            nextKeyFrame = (self.currentKeyFrame + 1) % len(self.keyframes)
        normalized_time = (self.currentTime - self.keyframes[self.currentKeyFrame]['time'])/(self.keyframes[nextKeyFrame]['time'] - self.keyframes[self.currentKeyFrame]['time'])
        length =  getBezierValue(normalized_time, self.keyframes[self.currentKeyFrame]['value'], self.keyframes[nextKeyFrame]['value'], 0.0, 1.0)
        return length
length = 500

keyframeVariable = KeyFrameVariable(length, [{'time': 0, 'value': 300}, {'time': 1.0, 'value': 500}, {'time': 2.0, 'value': 450}, {'time': 3.0, 'value': 300}])

# pygame setup
pygame.init()
screen = pygame.display.set_mode((1280, 720))
clock = pygame.time.Clock()
running = True

while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    screen.fill("purple")
    length = keyframeVariable.update()
    pygame.draw.rect(screen, "red", (100, length, 100, 100))
    pygame.display.flip()
    clock.tick(60)

pygame.quit()
import pygame
import time
import numpy as np

def comb(n, k):
    return np.math.factorial(n) / (np.math.factorial(k) * np.math.factorial(n - k))

def getBezierValue(time, prev_value, next_value, a, b):
    b_val = (1 - time)**2 * a + 2 * time * (1 - time) * b + time**2
    return prev_value + (next_value - prev_value) * b_val

class KeyFrameVariable:
    def __init__(self, value, keyframes):
        self.value = value
        self.keyframes = keyframes
        self.currentTime = 0
        self.currentKeyFrame = 0

    def update(self, dt):
        self.currentTime += dt
        if self.currentTime >= self.keyframes[self.currentKeyFrame]['time']:
            while self.currentTime >= self.keyframes[self.currentKeyFrame]['time']:
                self.currentKeyFrame += 1
                if self.currentKeyFrame >= len(self.keyframes):
                    self.currentKeyFrame = 0
                    self.currentTime -= self.keyframes[-1]['time']
                    dt = self.currentTime
            self.value = self.keyframes[self.currentKeyFrame]['value']
        else:
            self.value = getBezierValue(dt/(self.keyframes[self.currentKeyFrame + 1]['time'] - self.keyframes[self.currentKeyFrame]['time']), self.keyframes[self.currentKeyFrame - 1]['value'], self.keyframes[self.currentKeyFrame]['value'], 0.3, 0.7)
        return self.value

length = 500

keyframeVariable = KeyFrameVariable(length, [{'time': 0, 'value': 500}, {'time': 1.0, 'value': 300}, {'time': 2.0, 'value': 200}, {'time': 3.0, 'value': 300}])

# pygame setup
pygame.init()
screen = pygame.display.set_mode((1280, 720))
clock = pygame.time.Clock()
running = True

ti = time.time()
while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    screen.fill("purple")
    #actual logic
    tf = time.time()
    dt = tf - ti
    ti = tf
    length = keyframeVariable.update(dt)
    pygame.draw.rect(screen, "red", (100, length, 100, 100))
    pygame.display.flip()
    clock.tick(60)

pygame.quit()
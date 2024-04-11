import pygame
from math import cos, sin, pi
class AnimBone:
    def __init__(self, x, y, length, angle, parent = None):
        self.relx = x
        self.rely = y
        self.x = 0
        self.y = 0
        self.length = length
        self.angle = angle
        self.parent = parent
        self.children = []
    
    def update(self):
        if self.parent:
            self.x = self.parent.x + self.parent.length*cos(self.parent.angle*pi/180) + self.relx
            self.y = self.parent.y + self.parent.length*sin(self.parent.angle*pi/180) + self.rely
        else:
            self.x = self.relx
            self.y = self.rely
        for child in self.children:
            child.update()

    def draw(self, screen):
        pygame.draw.line(screen, "red", (self.x, self.y), (self.x + self.length*cos(self.angle*pi/180), self.y + self.length*sin(self.angle*pi/180)), width = 3)

bones = []
rootBone = AnimBone(1000, 300, 100, 90)
bones.append(rootBone)
bones.append(AnimBone(0, 0, 70, 20, rootBone))
bones.append(AnimBone(0, 0, 80, 60, rootBone))
bones.append(AnimBone(0, 0, 50, 30, bones[1]))
bones.append(AnimBone(0, 0, 60, 50, bones[1]))
bones.append(AnimBone(0, 0, 40, 40, bones[2]))
bones.append(AnimBone(0, 0, 30, 10, bones[2]))
bones[1].children = [bones[3], bones[4]]
bones[2].children = [bones[5], bones[6]]
rootBone.children = [bones[1], bones[2]]


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

    #actual logic
    rootBone.update()
    for bone in bones:
        bone.draw(screen)

    
    mx, my = pygame.mouse.get_pos()

    pygame.display.flip()
    clock.tick(60)

pygame.quit()
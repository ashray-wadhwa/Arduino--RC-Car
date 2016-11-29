#!/usr/bin/env python 
import serial 
import pygame
from pygame.locals import *
ser=serial.Serial('COM3' ,9600) 
pygame.init()
screen = pygame.display.set_mode((640, 480))
pygame.display.set_caption('Pygame Caption')
pygame.mouse.set_visible(0)
done=False
while not done:
   for event in pygame.event.get():
      if (event.type == KEYDOWN):
         if event.key==K_UP:
            ser.write('w')
         elif event.key==K_DOWN:
            ser.write('s')
         elif event.key==K_SPACE:
            ser.write('t')
         elif event.key==K_LEFT:
            ser.write('a')
         elif event.key==K_RIGHT:
            ser.write('d')
         elif event.key==K_1:
            ser.write('h')
         elif (event.key == K_ESCAPE):
            done = True
pygame.quit()

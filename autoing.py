import pyautogui as p
from time import sleep

sleep(5)

crs = p.locateCenterOnScreen("crs.png",confidence=0.8)
p.moveTo(crs,duration=3)

# n = 0

# while n != 100:
#     p.click()
#     n = n + 1



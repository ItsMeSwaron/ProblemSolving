import pyautogui
from time import sleep

# while True:
#     print(pyautogui.position())

# res = pyautogui.locateOnScreen("booming.png")

# print(res)
# MoveIt = pyautogui.center(res)

# pyautogui.moveTo(MoveIt)


# ------------------------------------ #

# sleep(5)

# while True:

sleep(1)



# while True:

res = pyautogui.locateCenterOnScreen("gcrm.png",confidence=0.8)
pyautogui.moveTo(res,duration=2)

pyautogui.click()

# pyautogui.doubleClick()

# pyautogui.moveTo(100,600,5)

# pyautogui.dragTo(0,0,2,button="right")




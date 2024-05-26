import pyautogui as p
from time import sleep

sleep(5)

# p.dragTo(25,68,duration=6,button="left")

p.hotkey("ctrl","a")
p.hotkey("ctrl","c")
p.moveTo(526,856,duration=3)
p.click()
p.hotkey("ctrl","v")

import pyautogui
from time import sleep

n = input()
N = int(n)
i = 1
j = 1

sleep(5)

pyautogui.write(n)
pyautogui.press("enter")

while N != 0:
    i = j
    while i != 0:
        pyautogui.write("#")
        i -= 1

    pyautogui.press("enter")
    N -= 1
    j += 1

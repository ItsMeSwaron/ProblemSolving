import pyautogui as machine
from time import sleep

addressVS = machine.locateCenterOnScreen("vscod.png",confidence=0.8)
machine.moveTo(addressVS,duration=1)
machine.click()

sleep(1)

addressGC = machine.locateCenterOnScreen("gcrm.png",confidence=0.8)
machine.moveTo(addressGC,duration=1)
machine.doubleClick()

sleep(3)

addressSrc = machine.locateCenterOnScreen("src.png",confidence=0.8)
machine.moveTo(addressSrc,duration=1)
machine.click()
machine.write("messenger")
machine.press("enter")

sleep(3)

addressMSNGR = machine.locateCenterOnScreen("messenger.png",confidence=0.8)
machine.moveTo(addressMSNGR,duration=1)
machine.click()

sleep(5)

addressSRCMSG = machine.locateCenterOnScreen("srcmsg.png",confidence=0.8)
machine.moveTo(addressSRCMSG,duration=1)
machine.click()
machine.write("Proshun")

sleep(2)

addressPROSHUN = machine.locateCenterOnScreen("proshun.png",confidence=0.8)
machine.moveTo(addressPROSHUN,duration=1)
machine.click()

sleep(5)

addressCONT = machine.locateCenterOnScreen("conti.png",confidence=0.8)
machine.moveTo(addressCONT,duration=1)
machine.click()

sleep(5)

addressAa = machine.locateCenterOnScreen("Aa.png",confidence=0.8)
machine.moveTo(addressAa,duration=1)
machine.click()
machine.write("Hello there")

sleep(2)

addressArrow = machine.locateCenterOnScreen("arrow.png",confidence=0.8)
machine.moveTo(addressArrow,duration=1)
machine.click()




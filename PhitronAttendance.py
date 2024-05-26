import pyautogui as machine
from time import sleep

addressVS = machine.locateCenterOnScreen("vscod.png",confidence=0.8)
machine.moveTo(addressVS,duration=1)
machine.click()

sleep(1)

addressGC = machine.locateCenterOnScreen("gcrm.png",confidence=0.8)
machine.moveTo(addressGC,duration=1)
machine.doubleClick()

sleep(4)

addressSrc = machine.locateCenterOnScreen("src.png",confidence=0.8)
machine.moveTo(addressSrc,duration=1)
machine.click()
machine.write("https://docs.google.com/forms/d/e/1FAIpQLSffnKO7ld0iW3VUzo0F73egvzbenIIqxcReVNb_nsOl1kHa3w/viewform")
machine.press("enter")

sleep(3)

addressEmail = machine.locateCenterOnScreen("email.png",confidence=0.8)
machine.moveTo(addressEmail,duration=1)
machine.click()
machine.write("swaron3214@gmail.com")

sleep(1)

addressCalen = machine.locateCenterOnScreen("calen.png",confidence=0.8)
machine.moveTo(addressCalen,duration=1)
machine.click()

sleep(1)

addressCalendar = machine.locateCenterOnScreen("calendar.png",confidence=0.8)
machine.moveTo(addressCalendar,duration=1)
machine.click()

sleep(1)

addressName = machine.locateCenterOnScreen("name.png",confidence=0.8)
machine.moveTo(addressName,duration=1)
machine.click() 
machine.write("Ejaz Uddin Swaron")

sleep(1)
machine.scroll(-800)

addressLang = machine.locateCenterOnScreen("pyt.png",confidence=0.8)
machine.moveTo(addressLang,duration=1)
machine.click()

sleep(1)

addressMent = machine.locateCenterOnScreen("ratin.png",confidence=0.8)
machine.moveTo(addressMent,duration=1)
machine.click()

sleep(1)

addressWeek = machine.locateCenterOnScreen("week.png",confidence=0.9)
machine.moveTo(addressWeek,duration=1)
machine.click()
machine.scroll(-1000)

sleep(1)

addressAns = machine.locateCenterOnScreen("ans.png",confidence=0.8)
machine.moveTo(addressAns,duration=1)
machine.click()
machine.write("M7")


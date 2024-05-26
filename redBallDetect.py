# import pyautogui as P
# from time import sleep

# sleep(9)

# while True:
#     addressRedBall = P.locateCenterOnScreen("lal.png",confidence=0.3,region=[0,242,1000,1000])
    
#     if addressRedBall:
#         P.moveTo(addressRedBall)
#         P.click()



import pyautogui as P
from time import sleep  # Import the time module

initial_sleep = 9
click_interval = 0
ball_search_timeout = 5

while True:
    sleep(initial_sleep)

    while True:
        try:
            addressRedBall = P.locateCenterOnScreen("lal.png", confidence=0.8)
            if addressRedBall:
                P.moveTo(addressRedBall)
                P.click()
                sleep(click_interval)
            else:
                print("Ball not found. Waiting...")
                start_time = time.time()  # Corrected line with import
                while time.time() - start_time < ball_search_timeout:
                    if P.locateCenterOnScreen("lal.png", confidence=0.8):
                        break
                if time.time() - start_time >= ball_search_timeout:
                    print("Timed out waiting for a new ball.")
                    break
        except Exception as e:
            print(e)
            sleep(click_interval)

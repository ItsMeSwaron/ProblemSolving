from ast import arg


def Fun(**kwargs):
    for key, value in kwargs.items():
        print(key,"-",value)


Fun(me = 5, amirul = 10, sakib = 15)

def Funning(*args):
    for argz in args:
        print(argz)


Funning(10,20,30)
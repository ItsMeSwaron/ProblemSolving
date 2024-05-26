N = input()

Arr = input()
MainArr = []

for num in Arr.split():
    MainArr.append(int(num))
    
UltaArr = MainArr[::-1]

if UltaArr == MainArr:
    print("YES")
else:
    print("NO")

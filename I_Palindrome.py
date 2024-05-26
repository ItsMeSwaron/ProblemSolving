num1 = input()
reverse = num1[::-1]

k = 0
start = 0

while k < len(reverse):
    
    if reverse[k] == "0":
        start += 1
    else:
        break

    k += 1

while start < len(reverse):

    print(reverse[start], end = '')

    start += 1

print()

if num1 == reverse:
    print("YES")
else:
    print("NO")
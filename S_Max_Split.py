S = input()

A = []

i = 0
while i != len(S):
    A.append(S[i]) 
    i += 1

count = 0
k = 0
while k != len(S):
    if A[k] == "L":
        if k+1 != len(S) and A[k+1] == "R":
            count += 1
    k += 1

print(count)            

left = 0
right = 0

def printer(left,right):
    while left != 0:
        print("L",end="")
        left -= 1
    while right != 0:
        print("R",end="")
        right -= 1
    print()

j = 0
while j != len(S):
    if A[j] == "L":
        j += 1
        left += 1
    elif A[j] == "R":
        j+= 1
        right += 1

    if left == right and left > 0 and right > 0:
        printer(left,right)
        left = 0
        right = 0



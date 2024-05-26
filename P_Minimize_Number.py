N = input()

A = input()

IntA = []

for i in A.split():
    IntA.append(int(i))

index = 0
count = 0

while True:

    if IntA[index] % 2 != 0:
        break
    else:
        IntA[index] = IntA[index]/2
    
    index += 1

    if index == len(IntA):
        count += 1
        index = 0

print(count)
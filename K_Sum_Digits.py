num = input()

A = int(input())
tmp = []

while A != 0:
    tmp.append(A%10)
    A = A//10

Ans = 0

for numz in tmp:
    Ans = Ans + numz

print(Ans)
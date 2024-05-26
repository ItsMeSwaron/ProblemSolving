Line = input()

Words = []

for word in Line.split():
    Words.append(word)

UltaWordz = []

for word in Words:
    UltaWordz.append(word[::-1])

print(*UltaWordz)
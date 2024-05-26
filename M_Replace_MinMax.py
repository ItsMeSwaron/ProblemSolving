N = input()

valz = input()
Ans = valz.split()
AnsInt = [int(x) for x in Ans]

Boro = max(AnsInt) 
BoroIndex = AnsInt.index(max(AnsInt))

Choto = min(AnsInt) 
ChotoIndex = AnsInt.index(min(AnsInt))

AnsInt[BoroIndex],AnsInt[ChotoIndex] = AnsInt[ChotoIndex],AnsInt[BoroIndex]

print(*AnsInt)
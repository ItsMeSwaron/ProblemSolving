N = input() # just show

Seq = input()
IntSeq = []

for i in Seq.split():
    IntSeq.append(int(i))

IntSeq.sort()

index = 0
detect = 0
k = 0
work = 0

for i in IntSeq:

    if k+1 < len(IntSeq) and IntSeq[k] == IntSeq[k+1]:
        k += 1
        continue

    while index < len(IntSeq):
    
        if IntSeq[index] == i:
            detect += 1
        
        index += 1
    
    if detect > i:

        work = work + (detect - i)
    
    elif detect < i:
        
        work += detect

    index = 0
    detect = 0
    k += 1

print(work)
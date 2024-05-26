user = input()

A, B = user.split()

start = int(A)
end = int(B)

i = 0

Signal = 0

Answer = []

while start <= end:

    index = str(start)

    while i < len(index):

        if index[i] != "4" and index[i] != "7":
            Signal = 1
        
        i += 1
    
    if Signal == 0:

        Answer.append(str(start))

    start += 1
    Signal = 0
    i = 0

if not Answer:
    print(-1)
else:
    FinalAnswer = ' '.join(Answer)
    print(FinalAnswer)





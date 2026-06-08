n = int(input())
arr = []

for i in range(n):
    arr.append(int(input()))

symList = [["I", 1], ["IV", 4], ["V", 5], ["IX", 9], ["X", 10], ["XL", 40], ["L", 50], ["XC", 90], ["C", 100], ["CD", 400], ["D", 500], ["CM", 900], ["M", 1000]]

i = 0

while i < n:
    ans = ""
    for sym, val in reversed(symList):
        if arr[i] // val:
            count = arr[i] // val
            ans += (count * sym)
            arr[i] %= val
    i += 1
    print(ans)
     
    

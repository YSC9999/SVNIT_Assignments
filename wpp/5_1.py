f = int(input("Give the value: "))
s = int(input("Give the value: "))
xor = 0
for i in range(f,s+1):
    for j in range(i,s+1):
        if i^j>xor:
           xor = i^j
print(xor)
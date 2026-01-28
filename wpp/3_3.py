a = int(input("Enter the number of cases: "))
ans = []
for i in range(a):
    h=0
    b = int(input("Give the number of cycles: "))
    for j in range(0,b+1):
        if j%2==1:
            h*=2
        else:
            h+=1
    ans.append(h)
for i in ans:
    print(i)
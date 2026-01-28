def num(a):
    i=a
    ans=0
    while(i!=0):
        mod = i%10
        if mod != 0:
            if a%mod ==0:
                ans+=1
        i=i//10
    print(ans)
no = int(input("No of test cases: "))
i = 0
list1=[]
while(i<no):
    var = int(input("Give numbers: "))
    list1.append(var)
    i+=1
for i in list1:
    num(i)
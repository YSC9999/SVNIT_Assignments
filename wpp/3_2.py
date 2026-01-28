def fibo(a):
    if a==1:
        return 0
    if a==2:
        return 1
    fib = fibo(a-1)+fibo(a-2)
    return fib
def res(list1):
    for i in list1:
        fib = True
        j=1
        while(i>=fibo(j)):
            if(i==fibo(j)):
                print("IsFibo")
                fib = False
                break
            j+=1
        if(fib):
               print("NotFibo")
no = int(input("No of cases: "))
i=0
list1 = []
while(i<no):
    var = int(input("Give the number: "))
    list1.append(var)
    i+=1
res(list1)
def dig(a):
    if a<10:
        print(a)
        return
    i=0
    while(a!=0):
        i+=a%10
        a=a//10
    dig(i)
num = int(input("Give the number: "))
dig(num)
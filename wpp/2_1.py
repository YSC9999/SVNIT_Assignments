string = input("Give a string: ")
j=0
for i in string:
    if j%2==1:
        i = i.upper()
    j+=1
    print(i,end="")
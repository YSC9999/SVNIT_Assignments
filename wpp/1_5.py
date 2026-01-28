i=1
lis = []
while i<=10:
    name = input("Enter name: ")
    while(len(name)>15):
        print("Give a name less than 15 characters")
        name = input("Enter name: ")
    name = name[::-1]
    lis.append(name)
    i+=1
print(lis)
def calcu(a):
    list1 = list(a)
    cal = 0
    for i in range(len(list1)):
        if(ord(list1[i])>ord(list1[-i-1])):
            cal+=ord(list1[i])-ord(list1[-i-1])
            list1[i] = list1[-i-1]
        elif(ord(list1[i])<ord(list1[-i-1])):
            cal+=ord(list1[-i-1])-ord(list1[i])
            list1[-i-1] = list1[i]
    return cal
no = int(input("Give no of cases: "))
list1 =[]
i = 0
while(i<no):
    ch = input("Give the string: ")
    list1.append(calcu(ch))
    i+=1
for i in list1:
    print(i)
def between(s,e):
    cal=0
    if s**0.5 == int(s**0.5) and e**0.5 == int(e**0.5):
        cal+=1
    cal+=int(e**0.5)-int(s**0.5)
    return cal
no = int(input("Give no of cases: "))
i = 0
list1=[]
while(i<no):
    s = int(input("Give the starting number: "))
    e = int(input("Give the ending number: "))
    list1.append(between(s,e))
    i+=1
for i in list1:
    print(i)
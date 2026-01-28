import random as r
list1 = [r.randint(0,1) for i in range(100)]
s=0
a=0
for i in list1:
    if i==0:
        s+=1
    else:
        if a<s:
            a = s
        s = 0
if a<s:
    a = s
print(list1)
print(a)
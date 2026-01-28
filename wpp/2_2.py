print("ENTER STOP WHEN COMPLETED")
pn = input("Give the name of product: ")
dict1 = {}
while(pn!="STOP"):
    pr = int(input("Give the price of the product: "))
    dict1[pn] = pr
    pn = input("Give the name of product: ")
print("ENTER STOP WHEN COMPLETED")
pn = input("Give the name of product to be searched: ")
while(pn!="STOP"):
    print(f"price of {pn} is {dict1[pn]}")
    pn = input("Give the name of product to be searched: ")
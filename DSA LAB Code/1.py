n = int(input("Enter number of elements : "))
#a=[1,4,2,5,3,6]
#b=[9,14,0,5,2,16]
j=1
a=[]
print("Enter elements of A:")
for i in range(n):
   a.append(int(input(f"Enter element at {i} of A : ")))
print("Enter elements of B:")
b=[]
for i in range(n):
   b.append(int(input(f"Enter element at {i} of B : ")))
a=list(map(lambda x: x-1,a))
t=list(x for x in b)
while len(a)>0:
    x=t[a[0]%len(t)]
    s=b.remove(x)
    a.pop(0)
    print(f"After {j}th deletion",b)
    j+=1
a=1
def tailfact(n,a):
    if n==0 or n==1:
        return a
    else:
        return tailfact(n-1,n*a)
        

n=int(input("Enter the Number: "))
print(tailfact(n,a))

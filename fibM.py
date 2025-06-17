table={}
a=[]
def fibM(n):
    if n==0 or n==1:
        return n;
    else:
        if n not in table:
            
            table[n]=fibM(n-1)+fibM(n-2)
            
        return table[n]

n=int(input("enter the number of fib series: "))
for i in range(n):
    a.append(fibM(i))
print(a)
    

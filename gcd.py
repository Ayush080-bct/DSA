def Gcd(a, b):
    if b == 0:
        return a
    else:
        while(b!=0):
          r=a%b
          a=b
          b=r
        return a


a = int(input("Enter the first number: "))
b = int(input("Enter the second number: "))

print("GCD is:", Gcd(a, b))

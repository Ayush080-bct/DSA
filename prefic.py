def prefixeval(exp):
    stack = []
    a = exp.split()
    for i in reversed(a):  # scan from right to left
        if i.isdigit():
            stack.append(int(i))   # convert string → int
        else:
            op1 = stack.pop()
            op2 = stack.pop()
            if i == '+':
                result = op1 + op2
            elif i == '-':
                result = op1 - op2
            elif i == '*':
                result = op1 * op2
            elif i == '/':
                result = op1 / op2
            elif i == '^':
                result = op1 ** op2   # exponent
            else:
                raise ValueError(f"Unknown operator: {i}")
            stack.append(result)
    return stack[0]

exp = input("Enter the expression : ")
print("Result : ", prefixeval(exp))

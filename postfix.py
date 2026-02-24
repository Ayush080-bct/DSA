def evalpostfix(expression):
    stack = []
    a = expression.split()

    for i in a:
        if i.isdigit():
            stack.append(int(i))
        else:
            op1= stack.pop()
            op2 = stack.pop()

            if i == '+':
                stack.append(op2 + op1)
            elif i == '-':
                stack.append(op2 - op1)
            elif i == '*':
                stack.append(op2 * op1)
            elif i == '/':
                stack.append(op2 / op1)
            elif i == '^':
                stack.append(op2 ** op1)
            else:
                raise ValueError(f"Unknown operator: {i}")
    
    return stack[0]

expr = input("Enter the expression: ")
print("Result:", evalpostfix(expr))

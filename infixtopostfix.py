def precedence(op):
    if op =='+' or op == '-':
        return 1
    elif op=='*' or op=='/':
        return 2
    elif op=='^' or op=='$':
        return 3
    else :
        return 0
    
    
def infixtopostfix(tokens):
    a=[]
    stack=[]
    for token in tokens:

        if token.isdigit() or token.isalpha():
            a.append(token)
        elif token=='(':
            stack.append(token)
        elif token==')':
            while(stack and stack[-1] != '('):
                  a.append(stack.pop())
            stack.pop()
        else:
            while(stack and precedence(stack[-1])>=precedence(token)):
                a.append(stack.pop())
            stack.append(token)
    while stack:
        a.append(stack.pop())
    return a

        






Exp=input("Enter the expression with space to sepearted data : ")
tokens=Exp.split()
print("The postfix expression is:  ",infixtopostfix(tokens))        
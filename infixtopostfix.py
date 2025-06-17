
def infixtopostfix(token):
    a=[]
    stack=[]
    for token in tokens:
        if token.isdigit():
            a.append(token)
        elif token=='(':
            stack.append(token)
        elif token==')':
            while stack:
                top=stack.pop()
                if top=='(':
                    break
                else:
                    a.append(top)
                    
        






Exp=input("Enter the expression with space to sepearted data : ")
tokens=Exp.split()
print("The postfix expression is:  ",infixtopostfix(tokens))        
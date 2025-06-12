#include<stdio.h>
#include<ctype.h>//for using idigit(),which checks a character is a digit or not
#include<math.h>

#define maxsize 10
struct stack

{
    float data[maxsize];
   int tos;
};
float pop(struct stack*s)
{
    if(s->tos==-1)
    {
        printf("Stack Underflow\n");
        return -1;
    }
    float element;
    element=s->data[s->tos];
    s->tos--;
    return element; 
    
}
void push(struct stack *s,float element){
    if(s->tos==maxsize-1)
    {
        printf("Stack overflow\n");
        return;
    }
    s->tos++;
    s->data[s->tos]=element;

}
int main()
{
    struct stack s;
    s.tos=-1;
    int i,n;
    char expression[100];
    
  
    printf("Enter the Expression: ");
    

    
    scanf(" %s",expression);

    float op1,op2,op3,op4,result;
    for(i=0;i<5;i++){
        if(isdigit(expression[i]))
        {
         push(&s,(float)(expression[i]-'0'));/*xpression-'0' 0 is also character,it will have ascii value
          and by type casting we convert character into floating value for example expression[i] is 5 as a c
          character its ascii value is 53 ,53-48(ascii value of 0)=5 which is integer value*/
        }
        else {
           op1=pop(&s);
           op2=pop(&s);
           op3=pop(&s);
           op4=pop(&s);
           switch((char)(expression[i]))
           {
            case '+':
              result=op2*10+op1+op4*10+op3;
              break;
            case '-':
              result=op2-op1;
              break;
            case '/':
              result=op2/op1;
              break;
            case '*':
              result=op2*op1;
              break;
            case '^':
            case '$':
              result=pow(op2,op1);
              break;
            default:
                printf("Invalid character: %c\n",expression[i]);
                return 1;
                    
           }
           push(&s,result);
        }
  
}
    printf("Result of postfix expression: %.2f\n", pop(&s));
    return 0;
}
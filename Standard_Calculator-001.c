#include <stdio.h>
int main()
{
    int Expression[50];
    printf("Enter : ");
    gets(Expression);
    for(int i = 0;i < 50;++i)
    {
        switch (Expression[i])
        {
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            break;
        case '^':
        case '/':
        case '*':
            if(i == 0)
            {
                printf("Variable must be before these expressions");
            }
            if(Expression[i+1] == '^' || Expression[i+1] == '/' || Expression[i+1] == '*')
            {
                printf("These expressions cannot be placed one after the other.");
            }
            break;
        case '+':
        case '-':
            if(Expression[i+1] == '^' || Expression[i+1] == '/' || Expression[i+1] == '*')
            {   printf("These expressions cannot be placed one after the other.");
            }else if(Expression[i+1] == '+' || Expression[i+1] == '-')
            {   if(Expression[i+2] == '+' || Expression[i+2] == '-')
                {printf("These expressions cannot be placed one after the other.");}
            }
            break;
        default:
            break;
        }
    }
    return 0;
}
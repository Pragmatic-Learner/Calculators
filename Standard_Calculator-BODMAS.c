#include <stdio.h>
#include <ctype.h>
int stdCalc();

char symbol;
int varInteger, answer;

int main()
{
    char Expression[49];
    int count_Var, indexExp;

StartCalculator:

    symbol = NULL;
    count_Var = 0;indexExp = 0;varInteger = 0;answer = 0;
    printf("Enter : "); scanf("%s", Expression);

analyze_EXPRESSION:

    switch (isdigit(Expression[indexExp]))
    {
        case 0://The array index contains punct OR void
            switch (ispunct(Expression[indexExp]))
            {
                case 0:
                    break;
                default:
                ++count_Var;
                    switch (count_Var)
                    {
                        case 1:
                            break;
                        default:        //printf("Symbol%d = %c\n", count_Var-1, symbol);
                            stdCalc();
                            varInteger = 0;
                            break;
                    }
                    symbol = Expression[indexExp];
                    break;
            }
            break;
        default://The array index contains digit
            switch (count_Var)
            {
                case 0:
                    answer = (answer * 10) + (int)(Expression[indexExp] - '0');
                    break;
                default:
                    varInteger = (varInteger * 10) + (int)(Expression[indexExp] - '0');
                    break;
            }
            break;
    }

    ++indexExp;


    if (Expression[indexExp] != NULL || indexExp > sizeof(Expression))
    {
        goto analyze_EXPRESSION;
    }
                //printf("Symbol%d = %c\n", count_Var, symbol);
    stdCalc();

    printf("Answer = %d\n", answer);

    printf("Redo ? [ R to REDO | Any other to EXIT ] : ");
    scanf(" %c", &symbol);
    if (symbol == 'R')
    {
        printf("\e[1;1H\e[2J");
        goto StartCalculator;
    }
    
    printf("Exiting\a");
    usleep(500000);
    printf(".");
    usleep(500000);
    printf(".");
    usleep(500000);
    printf(".");
    usleep(300000);
    return 0;
}

int stdCalc()
{
    switch (symbol)
    {
        case '/':
            switch (varInteger)
            {
                case 0:
                    printf("\nError.  Cannot divide by zero");
                    break;
                default:
                    answer /= varInteger;
                    break;
            }
            break;
        case '*':
            answer *= varInteger;
            break;
        case '+':
            answer += varInteger;
            break;
        case '-':
            answer -= varInteger;
            break;
        default:
            printf("ERROR!!!      Symbol = |%c|\n", symbol);
            break;
    }
}
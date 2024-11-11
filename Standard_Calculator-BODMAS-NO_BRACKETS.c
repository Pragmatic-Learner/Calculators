#include <stdio.h>
int Application_Start_Message(), Expression_Decoder(), VARIABLES_COUNTER(int *var);
char ERROR_CHECKER(int error_index);

char expression[49];
int NumberOfSymbols = 0, NumberOfChar;
int main()
{
    int index = 0, indexDown = 0, passNum = 0;
    Application_Start_Message();
    gets(expression);

    ERROR_CHECKER(0);

    /*int variables[NumberOfSymbols];*/int variables[24];

    /*CODE*/
}

int Application_Start_Message()
{
    printf("Standard Calculator ~ BODMAS Implemented | ( B ) rackets not usable\n");
    printf("Enter : ");
}
char ERROR_CHECKER(int error_index)
{
    switch (expression[error_index])
    {
        case '0':case '1':case '2':case '3':case '4':case '5':case '6':case '7':case '8':case '9':
            break;
        case '/':case '*':case '+':
            switch (error_index)
            {
                case 0:
                    printf("There must be a varriable first...\n Number = %d", error_index);
                    return 'E';
            }
        case '-':
            switch (expression[error_index + 1])
            {
                case '/':
                case '*':
                case '+':
                case '-':
                    printf("Symbol cannot be followed by symbol...\n Number = %d", error_index);
                    return 'E';
            }
            ++NumberOfSymbols;
            break;
        case '\0':
            ++NumberOfSymbols;
            NumberOfChar = error_index;
            return 'G';
        default:
            printf("! ERROR !\n!!!!! INVALID CHARACTER INPUT !!!\n! ERROR !\n");
            return 'E';
    }
    ERROR_CHECKER(error_index + 1);
}
int VARIABLES_COUNTER(int *var)
{
    int Index_Exp = 0, Index_Var = 0;
loop:
    for(Index_Exp = 0;Index_Exp < NumberOfChar;++Index_Exp)
    {
        switch (expression[Index_Exp])
        {
            case '0':case '1':case '2':case '3':case '4':case '5':case '6':case '7':case '8':case '9':
                var[Index_Var] = (var[Index_Var] * 10) + (int)(expression[Index_Var] - '0');
                break;
            default:
                ++Index_Var;
                break;
        }
    }
    switch (Index_Exp)
    {
        case 48:
            break;
        default:
            goto loop;
    }
}
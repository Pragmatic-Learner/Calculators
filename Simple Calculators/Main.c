#include <stdio.h>
int errors = 0;
int OperatorProcessing(int VarNum1, int varNum2, char Operator)
{
	switch (Operator)
	{
	case '^':
		return VarNum1 ^ varNum2;
	case '/':
		return VarNum1 / varNum2;
	case '*':
		return VarNum1 * varNum2;
	case '+':
		return VarNum1 + varNum2;
	case '-':
		return VarNum1 - varNum2;
	default:
		errors = 1;
		return 1;
	}
}
int main()
{
	float varNum[3];
	char operatorANDexit;
calculator_Repeater:
	printf("Value 1 : ");
	scanf_s("%f", &varNum[0]);
	printf("Value 2 : ");
	scanf_s("%f", &varNum[1]);
	input_Operator:
	printf("Operator : ");
	scanf_s(" %c", &operatorANDexit);
	varNum[3] = OperatorProcessing(varNum[0], varNum[1], operatorANDexit);
	if (errors == 1)
	{
		printf("Invalid Operator Input!!!!");
		goto input_Operator;
	}
	printf("Result : %f", varNum[2]);
	printf("\nWill you exit[Press X] or repeat[Press O]:--");
	scanf_s(" %c", &operatorANDexit);
	if (operatorANDexit == 'O')
	{
		goto calculator_Repeater;
	}
	return 0;

}
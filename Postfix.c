#include <stdio.h> 
#include <stdlib.h> 

int postfix(char*); // �������� 
int priority(char); // �M�w�B��l�u������ 
void evalPf(char postfix[]);
double cal(double, char, double);

int main(void) { 
    char input[80]; 
    printf("��J��ǹB�⦡�G"); 
    scanf("%s", input); 
    evalPf(input); 

    return 0; 
} 

int postfix(char* infix) { 
    int i = 0, top = 0; 
    char stack[80] = {'\0'}; 
    char op; 

    while(1) { 
        op = infix[i]; 

        switch(op) { 
            case '\0': 
                while(top > 0) { 
                    printf("%c", stack[top]); 
                    top--; 
                } 
                printf("\n"); 
                return 0; 
            // �B��l���| 
            case '(': 
                if(top < (sizeof(stack) / sizeof(char))) { 
                    top++; 
                    stack[top] = op; 
                } 
                break; 
            case '+': case '-': case '*': case '/': 
                while(priority(stack[top]) >= priority(op)) { 
                    printf("%c", stack[top]); 
                    top--; 
                } 
                // �s�J���| 
                if(top < (sizeof(stack) / sizeof(char))) { 
                    top++; 
                    stack[top] = op; 
                } 
                break; 
            // �J ) ��X�� ( 
            case ')': 
                while(stack[top] != '(') { 
                    printf("%c", stack[top]); 
                    top--; 
                } 
                top--;  // ����X( 
                break; 
            // �B�⤸������X 
            default: 
                printf("%c", op); 
                break; 
        } 
        i++; 
    } 
} 


void evalPf(char* postfix) { 
    double stack[80] = {0.0}; 
    char temp[2]; 
    char token; 
    int top = 0, i = 0; 

    temp[1] = '\0'; 

    while(1) { 
        token = postfix[i]; 
        switch(token) { 
            case '\0': 
                printf("ans = %f\n", stack[top]); 
                return; 
            case '+': case '-': case '*': case '/': 
                stack[top-1] = cal(stack[top], token, stack[top-1]); 
                top--; 
                break; 
            default: 
                if(top < sizeof(stack) / sizeof(float)) { 
                    temp[0] = postfix[i]; 
                    top++; 
                    stack[top] = atof(temp); 
                } 
                break; 
        } 
        i++; 
    } 
} 

double cal(double p1, char op, double p2) { 
    switch(op) { 
        case '+': 
            return p1 + p2; 
        case '-': 
            return p1 - p2; 
        case '*': 
            return p1 * p2; 
        case '/': 
            return p1 / p2;
    } 
}
//-----------------------------------------------
int priority(char op) { 
    int p; 

    switch(op) { 
       case '+': case '-': 
            p = 1; 
            break; 
        case '*': case '/': 
            p = 2; 
            break; 
        default: 
            p = 0; 
            break; 
    } 

    return p; 
} 

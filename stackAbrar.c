#include<stdio.h>

char stack[500];
int top = -1;

// void push(char x) {
//     if (top == 500 - 1) {
//         printf("Overflow\n");
//         return;
//     }

//     top = top + 1;
//     stack[top] = x;
// }

char pop() {
    if (top == -1) {
        printf("Underflow\n");
        return -1;
    }

    char val = stack[top];
    top = top - 1;

    return val;
}

int peek() {
    if (top == -1) return -1;
    return stack[top];
}

int main()
{
    for(int i=0;i<5;i++)
    {
        scanf("%c", &stack[i]);
    }
    
    for(int i=0;i<5;i++)
    {
        printf("%c", stack[i]);
    }

    printf("\n\n%d", top);
    
    return 0;
}
#include <stdio.h>
#define STACK_SIZE 15

void push(char s[], int *top, char item) {
    (*top)++;
    s[*top] = item;
}

char pop(char s[], int *top) {
    return s[(*top)--];
}

int pr(char op) {
    switch(op) {
        case '#': return 0;
        case '(': return 1;
        case '+': return 2;
        case '-': return 2;
        case '*': return 3;
        case '/': return 3;
        default: return 0;
    }
}

int main() {
    char s[STACK_SIZE];
    int top = -1;
    char str[30], postfix[30];
    int i = 0, j = 0;

    push(s, &top, '#');
    printf("Enter infix expression: ");
    scanf("%s", str);

    while (str[i] != '\0') {
        if (str[i] != '+' && str[i] != '-' && str[i] != '*' && str[i] != '/' && str[i] != '(' && str[i] != ')') {
            postfix[j++] = str[i];
        } else if (str[i] == '(') {
            push(s, &top, str[i]);
        } else if (str[i] == ')') {
            while (s[top] != '(') {
                postfix[j++] = pop(s, &top);
            }
            pop(s, &top);
        } else {
            while (pr(str[i]) <= pr(s[top])) {
                postfix[j++] = pop(s, &top);
            }
            push(s, &top, str[i]);
        }
        i++;
    }

    while (top > 0) {
        postfix[j++] = pop(s, &top);
    }

    postfix[j] = '\0';
    printf("Postfix expression: %s\n", postfix);  
    return 0;  
}

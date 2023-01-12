#include <iostream>
#include <string>
using namespace std;

struct stack {
    int top;
    char items[100];
} s;

void push(char x) {
    s.items[++s.top] = x;
}

char pop() {
    if (s.top == -1)
        return -1;
    else
        return s.items[s.top--];
}

int precedence(char x) {
    if (x == '(')
        return 0;
    if (x == '+' || x == '-')
        return 1;
    if (x == '*' || x == '/')
        return 2;
    if (x == '^')
        return 3;
    return 0;
}

int main() {
    string exp;
    cout << "Enter an infix expression: ";
    cin >> exp;

    int l = exp.length();
    string postfix = "";
    s.top = -1;

    for (int i = 0; i < l; i++) {
        if (exp[i] >= 'a' && exp[i] <= 'z' || exp[i] >= 'A' && exp[i] <= 'Z')
            postfix += exp[i];

        else if (exp[i] == '(')
            push(exp[i]);

        else if (exp[i] == ')') {
            while (s.items[s.top] != '(')
                postfix += pop();
            pop();
        } else {
            while (precedence(s.items[s.top]) >= precedence(exp[i]) && s.top != -1)
                postfix += pop();
            push(exp[i]);
        }
    }

    while (s.top != -1)
        postfix += pop();

    cout << "Postfix expression: " << postfix << endl;
    return 0;
}

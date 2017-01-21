#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>

int eval(int a, int b, char op);
bool isOp(char ch);

int main() {
    char *str = get_string();
    int value = 0;
    char op = '+';
    char nums[100];
    int ncount = 0;
    
    for (int i=0; i < strlen(str); i++) {
        // Handle the strings starting with negative numbers
        if (i==0 && str[i] == '-') {
            value = 0 - (str[i+1] - '0');
            i++;
            continue;
        }
        // If we encounter a new operator, evaluate the old one
        if (isOp(str[i]))  {
            value = eval(value, atoi(nums), op);
            op = str[i];
            ncount = 0;
        }
        // If we get a digit, add it to our array of digits, which we will evaluate later
        else if(isdigit(str[i])) {
            nums[ncount++] = str[i];
            nums[ncount] = '\0';
        }
        
        // If we reach the end of the string, evaluate the expression
        if (str[i+1] == '\0') {
            value = eval(value, atoi(nums), op);
        }
    }
    printf("%d\n", value);
    return 0;
}

int eval(int a, int b, char op) {
    int res = 0;
    switch (op) {
        case '+':
            res = a + b;
        break;
        case '-':
            res = a - b;
        break;
    }
    return res;
}

bool isOp(char ch) {
    if (ch == '-' || ch == '+') return true;
    return false;
}


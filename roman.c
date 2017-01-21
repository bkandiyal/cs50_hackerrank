#include <stdio.h>
#include <string.h>
#include <cs50.h>

int convert(char ch);

int main()
{
    char *str = get_string();
    int len = strlen(str);
    int val = 0;
    
    for (int i=0; i < len; i++) {
        int n = convert(str[i]);
        int next = (i+1 < len) ? convert(str[i+1]) : 0; // Check the value of the next roman character
        
        if (n >= next) {
            val += n;
        }
        else {
            val += next - n;
            i++;
        }
    }
    
    printf("%d\n", val);
}

int convert(char ch)
{
    switch(ch) {
        case 'I':
            return 1;
        break;
        case 'V':
            return 5;
        break;
        case 'X':
            return 10;
        break;
        case 'L':
            return 50;
        break;
        case 'C':
            return 100;
        break;
        case 'D':
            return 500;
        break;
        case 'M':
            return 1000;
        break;
        default:
            return 0;
    }
}

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>

int main()
{
    char *str = get_string();
    int len = strlen(str);
    
    char tmp[100];
    char prev = ' ';
    
    for (int i=0; i < len; i++) 
    {
        // If previous character was a whitespace then we're at the start of the word otherwise just continue the loop
        if (prev != ' ') { 
            prev = str[i]; 
            continue; 
        }
        
        // We're at the start of the sentence, make the first letter uppercase
        if (i == 0) { 
            str[i] = toupper(str[i]);
            /*int j = 1;
            while(true) {
                str[j] = tolower(str[j]);
                if (str[j+1] == ' ' || str[j+1] == '\0') break;
                j++;
            }*/
            prev = str[i]; 
            continue; 
        }
        
        int k = 0;
        for(int j=i; j < len; j++,k++) {
            tmp[k] = str[j];
            if (str[j+1] == '\0' || str[j+1] == ' ') break;
        }
        tmp[k+1] = '\0';
        
        // Copy 3 characters of the string into our tmp variable
        //strncpy(tmp, str+i, 3);
        //tmp[3] = '\0'; // Make the last character null so it plays well with strlen and other string functions
        for (int j=0; j < strlen(tmp); j++) 
            tmp[j] = tolower(tmp[j]); // Convert our temporary string to lowercase

        // If we don't match with these words then make the first letter uppercase
        if (strcmp(tmp, "the") && strcmp(tmp, "and") && strcmp(tmp, "but") && strcmp(tmp, "of")) {
            str[i] = toupper(str[i]);
            /*int j=i+1;
            while (true) {
                str[j] = tolower(str[j]);
                if (str[j+1] == '\0' || str[j+1] == ' ') break;
                j++;
            }*/
        } /*else {
            int j=i;
            while (true) {
                str[j] = tolower(str[j]);
                if (str[j+1] == '\0' || str[j+1] == ' ') break;
                j++;
            }
        }*/
        
        // Save the character at the current position so we can use it in the next iteration
        prev = str[i];
    }
    
    // Capitalize the first letter of the last word
    int j = len-1;
    while(j >= 0) {
        if(str[j-1] == ' ') {
            str[j] = toupper(str[j]);
            break;
        }
        
        j--;
    }
    
    printf("%s\n", str);
    return 0;
}

#include <cs50.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int letter = 0;  // letter count
    int word = 0;    // word count
    int longest = 0;   // longest word
    
    char* str = get_string();
    int len = strlen(str);

    // count longest word and number of words
    for (int i = 0; i <= len; i++) {
        // if char increase letter
        if (!isspace(str[i]) && str[i] != '\0') {
            letter++;
        } 
        
        // if space (or null) && letter count is > 0; have a word
        else if ((isspace(str[i]) || str[i] == '\0') && (letter > 0)) {
                word++;
                if (letter > longest) {
                    longest = letter;  
                }
                letter = 0;    // reset letter count
            }
        }

      
    ////// build frame ////////
    letter = 0;   // reset letter count for use in 2D array
    int cursor = 0;
    int right_space = 0;
    
    // frame height
    for (int i = 0; i < (2+word); i++) {
        
        if (i == 0 || i == ((2+word) - 1)) {     // if first or last row 
            // frame width
            for (int j = 0; j < (4+longest); j++) {
                printf("%c", '#');
            }
            printf("%c",'\n');
        }
        else {                               // NOT first or last row
            // frame width
            printf("%c", '#');               // left hash
            printf("%c", ' ');               // left space
            for (int l = cursor; l <= len; l++) {  // word
                if (!isspace(str[l]) && str[l] != '\0') {
                    letter++;
                    printf("%c", str[l]);

                }
                else if ((isspace(str[l]) || str[l] == '\0') && (letter > 0)) {
                    // calculate right_space before resetting letter
                    right_space = (4+longest) - (3 + letter);   // total width - (word length + 2 hashes + 1 left space)
                    letter = 0;
                    cursor = l;
                    break;
                }
            }
            
            for (int m = 0; m < right_space; m++) {     // right spaces
         
                printf("%c", ' ');
            }
            printf("%c", '#');                   // right hash
            printf("%c",'\n');

            
        }
        
    }
    
        
    
    
    return 0;
}

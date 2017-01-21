#include <cs50.h>   // change this to #include "cs50.h" when submitting b/c of way it's installed on hackkerank site???? double check this
#include <string.h>
#include <stdio.h>

// prototype
char* get_filler(int pos);

int main(void)
{
    int pos = 0;
    char* filler;
    
    char *tok;
    int count = 0;  // Word count
    //int len = 0; // Used to increment the char* pointer
    
    // grab string - cs50.h function
    char* input = get_string();   

    // if empty string
    if (input == NULL || strlen(input) == 0)
    {
        printf("There is no box\n");
        return 0; // Just return from here because nothing more todo
    }
    // else string exists
    else
    {
        tok = strtok(input, " ");  
        count++; // Increment the word counter
        if (strcmp("cat", tok) == 0) { // If we found a cat
            pos = count; // Save it's position
        } else {
            while(true){
                tok = strtok(NULL, " ");  // Get next word in the string
                if (tok != NULL) { // If a word exists
                  //  len += strlen(tok)+1; // Increment by length of the current word + 1 (for space)
                    count++; // Increment the word counter
                    if (strcmp("cat", tok) == 0) { // If we found a cat
                        pos = count; // Save it's position
                        break; // Exit the loop
                    }
                } else {
                    break; // Exit the loop because we're at the end of the string
                }    
            }
        }
        
        if (pos == 0)
            printf("No cat yet\n");
        else {
            filler = get_filler(pos);
            printf("The cat is the %d%s item in the box\n", pos, filler);
        }
    }
    return 0;
}

// I had to change this function a little bit because it was failing some test cases, more specifically the ones having position as 111-119
// I'm not sure my changes will work on the main test cases but it passes the sample test cases. - Bhaskar
char* get_filler(int pos)
{
    char* filler = "th";
    
    int d = pos % 100; // Get the last two digits
    if (!(10 < d && d < 20)) { // Check if we're not in the range of 11 - 19 as those numbers always have a 'th' suffix
        switch (d % 10)
        {
            case 1:
                filler = "st";
                break;
            case 2:
                filler = "nd";
                break;
            case 3:
                filler = "rd";
                break;
        }
    }
    return filler;
}

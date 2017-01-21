#include <cs50.h>
#include <string.h>
#include <stdio.h>

int main(void)
{
    int n, m;
    
    scanf("%d%d", &n, &m);
    
    int map[n][m]; // Store the rooms as a 2D array of integers to make our life a bit easier
    char buf[m];
    
    for(int i=0; i < n; i++) {
        scanf("%s", buf);
        for(int j=0; j < strlen(buf); j++) {
            map[i][j] = buf[j] - '0';
        }
    }

    int rooms;
    scanf("%d", &rooms);
    
    int count = 0;
    int prev = 0;
    bool found = false;

    // Count the number of consecutive 0s
    for(int i=0; i < n; i++) {
        count = 0;
        prev = 0;
        for(int j=0; j < m; j++) {
            if (map[i][j] == 0) {
                if (prev == 0)
                    count++;
                else
                    count = 1;
                if (count >= rooms) {
                    found = true;
                    break;
                }
            }
            prev = map[i][j];
        }
        if (found) break;
    }
    
    if (found)
        printf("1\n");
    else
        printf("0\n");
    return 0;
}


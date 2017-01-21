#include <cs50.h>
#include <string.h>
#include <stdio.h>

int main(void)
{
    int t, d, f;
    scanf("%d", &t);
    scanf("%d", &d);
  
    for (int i = 0; i < d; i++) {
        scanf("%d", &f);

        t = t - f;    // subtract amount eat each day
    
        if(t <= 0 && i+1 <= d) {
            printf("%d",i);
            return 0;
        }
    } 
    
    if (t >=0)
       printf("Happy Cat!"); 
    return 0;
    
}

#include <stdio.h>
#include <cs50.h>

typedef struct _Rectangle Rectangle;

struct _Rectangle {
    float w, h;
    float topleft[2];
    float bottomright[2];
};

float intersect(Rectangle r1, Rectangle r2);
float max(float a, float b);
float min(float a, float b);

int main()
{
 
    Rectangle r1, r2;
    
    scanf("%f%f%f%f", &r1.topleft[0], &r1.topleft[1], &r1.w, &r1.h);
    scanf("%f%f%f%f", &r2.topleft[0], &r2.topleft[1], &r2.w, &r2.h);

    r1.bottomright[0] = r1.topleft[0] + r1.w;
    r1.bottomright[1] = r1.topleft[1] + r1.h;
    
    r2.bottomright[0] = r2.topleft[0] + r2.w;
    r2.bottomright[1] = r2.topleft[1] + r2.h;
    
    printf("%.2f", intersect(r1, r2));
    return 0;
}

float intersect(Rectangle r1, Rectangle r2) {
    float xo = max(0.0, min(r1.bottomright[0], r2.bottomright[0]) - max(r1.topleft[0], r2.topleft[0]));
    float yo = max(0.0, min(r1.bottomright[1], r2.bottomright[1]) - max(r1.topleft[1], r2.topleft[1]));
    return xo * yo;
}

float max(float a, float b) {
    return (a > b) ? a : b;
}

float min(float a, float b) {
    return (a < b) ? a : b;
}

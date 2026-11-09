#include <stdio.h>
#include <stdlib.h>

int main()
{
    double pi = 3.142;
    double Radius, area;
    printf("Enter Radius\n");
    scanf("%lf", &Radius);

    area = pi * Radius * Radius;
    printf("The area is %lf\n", area);

    return 0;
}

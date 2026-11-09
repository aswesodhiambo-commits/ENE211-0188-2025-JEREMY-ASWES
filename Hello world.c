#include <stdio.h>
#include <stdlib.h>

int main()
{
    char userName[50];

    printf("Please enter username\n");
    scanf("%s", &userName);
    printf("Hello %s", userName);
    return 0;
}

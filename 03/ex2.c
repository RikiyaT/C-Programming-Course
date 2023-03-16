#include <stdio.h>
#include <string.h>

int main(void){
    char fn[100];
    char ln[100];

    printf("Input your first name: ");
    scanf("%s", fn);

    printf("Input your last name: ");
    scanf("%s", ln);

    printf("Your name is %s %s.\n", fn, ln);
    printf("First name length: %lu.\n", strlen(fn));
    printf("Last name length: %lu.\n", strlen(ln));
    
    return 0;
}
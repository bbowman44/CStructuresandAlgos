#include <stdio.h>
#include <string.h>

int main()
{
    char hw[30];
    char expected[] = "Hello World";

    printf("Please type the phrase 'Hello World'\n");
    fgets(hw, sizeof(hw), stdin);
    hw[strcspn(hw, "\n")] = 0;

    int result = strcmp(hw, expected);

    if (result == 0)
    {
        printf("Correct!");
        getchar();
        return 0;
    }
    printf("Incorrect!");
    return -1;
}
#include "main.h"

int main() {
    int count1 = _printf("Hello, world!\n");
    int count2 = _printf("My favorite letter is %c\n", 'Q');
    int count3 = _printf("My favorite programming language is %s\n", "C");
    int count4 = _printf("The percentage is %.2f%%\n", 75.0);
    printf("Count1: %d\nCount2: %d\nCount3: %d\nCount4: %d\n",
           count1, count2, count3, count4);
    return 0;
}
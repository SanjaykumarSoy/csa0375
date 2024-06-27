#include <stdio.h>
#include <string.h>

int findNeedleInHaystack(char *haystack, char *needle) {
    char *found = strstr(haystack, needle);
    return found ? found - haystack : -1;
}

int main() {
    char haystack[] = "hello world";
    char needle[] = "world";

    int index = findNeedleInHaystack(haystack, needle);

    printf("Index of needle in haystack: %d\n", index);

    return 0;
}

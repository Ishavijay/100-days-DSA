/*A secret system stores code names in forward order.
 To display them in mirror format, you must transform the given code name so that
  its characters appear in the opposite order.*/
#include <stdio.h>
#include <string.h>

char* revstr(char string[]) {
    int n = strlen(string) - 1;   // length (ignore '\n')
    
    for (int i = 0; i < n; i++, n--) {
        char temp = string[i];
        string[i] = string[n];
        string[n] = temp;
    }
    return string;
}

int main() {
    char str[100];
    fgets(str, sizeof(str), stdin);
    printf("%s", revstr(str));
    return 0;
}

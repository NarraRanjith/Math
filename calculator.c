#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *data = getenv("QUERY_STRING");
    if(data == NULL) {
        printf("Content-Type:text/html\n\n");
        printf("<html><body>Error! Form data not found.</body></html>");
        return 1;
    }

    int num1, num2, result;
    char operator[10];
    
    sscanf(data, "num1=%d&operator=%s&num2=%d", &num1, operator, &num2);

    if(strcmp(operator, "add") == 0) {
        result = num1 + num2;
    } else if(strcmp(operator, "subtract") == 0) {
        result = num1 - num2;
    } else if(strcmp(operator, "multiply") == 0) {
        result = num1 * num2;
    } else if(strcmp(operator, "divide") == 0) {
        if(num2 != 0) {
            result = num1 / num2;
        } else {
            printf("Content-Type:text/html\n\n");
            printf("<html><body>Error! Division by zero.</body></html>");
            return 1;
        }
    }

    printf("Content-Type:text/html\n\n");
    printf("<html><body>");
    printf("<h2>Result: %d</h2>", result);
    printf("</body></html>");

    return 0;
}


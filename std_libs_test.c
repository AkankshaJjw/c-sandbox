
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <assert.h>
#include <stdarg.h>
#include <time.h>

/* ctype.h example - Testing characters */
void test_characters() {
    char c;

    /* Check for alphanumeric character */
    c = 'A';
    if (isalnum(c))
        printf("%c is alphanumeric\n", c);
    else
        printf("%c is not alphanumeric\n", c);

    /* Check for digit */
    c = '9';
    if (isdigit(c))
        printf("%c is a digit\n", c);
    else
        printf("%c is not a digit\n", c);

    /* Check for printable character */
    c = '\n';
    if (isprint(c))
        printf("%c is printable\n", c);
    else
        printf("%c is not printable\n", c);
}

/* stdlib.h example - Utility functions */
void utility_examples() {
    const char *num_str = "12345";
    int num;

    /* Convert string to integer */
    num = atoi(num_str);
    printf("atoi: %s -> %d\n", num_str, num);

    /* Generate random number */
    srand((unsigned int)time(NULL));
    printf("Random number: %d\n", rand());
}

/* assert.h example - Diagnostic */
void test_assert(int x) {
    assert(x > 0 && "x must be positive");
}

/* stdarg.h example - Variable argument lists */
int sum_of_ints(int count, ...) {
    int sum = 0;
    va_list args;

    va_start(args, count);
    for (int i = 0; i < count; ++i) {
        sum += va_arg(args, int);
    }
    va_end(args);

    return sum;
}

/* time.h example - Time functions */
void time_examples() {
    time_t rawtime;
    struct tm * timeinfo;

    /* Get current time */
    time(&rawtime);
    /* Convert time to local time format */
    timeinfo = localtime(&rawtime);
    printf("Current local time and date: %s", asctime(timeinfo));
}

int main() {
    /* ctype.h example function call */
    test_characters();

    /* stdlib.h example function calls */
    utility_examples();

    /* assert.h example function call */
    test_assert(10);

    /* stdarg.h example function call */
    printf("Sum of ints: %d\n", sum_of_ints(4, 10, 20, 30, 40));

    /* time.h example function call */
    time_examples();

    return 0;
}

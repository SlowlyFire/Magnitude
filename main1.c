#include <stdio.h>
#include "ex2.h"

int main() {
    printf("multi of 10 and 5 in magnitude method: %d\n", multi(10, 5));
    printf("adding of -1 to 4 in magnitude method: %d\n", add(-1, 4));
    printf("subtraction of 8 to -3 in magnitude method: %d\n", sub(8, -3));
    printf("checking equality of 4 and 4 in magnitude method: %d\n", equal(4, 4));
    printf("checking inequality of 4 and 4 in magnitude method: %d\n", greater(4, 4));
    printf("result of 1*(3+5) in magnitude method: %d\n", multi(1, add(3, 5)));
}
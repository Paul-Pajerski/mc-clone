// controls.c

#include <stdio.h>
#include "controls.h"

void print_key(int key) {
    if (key == 87) {
        printf("%s", "Move Forward");
    }

    if (key == 83) {
        printf("%s", "Move Backwards");
    }

    if (key == 65) {
        printf("%s", "Move Left");
    }

    if (key == 68) {
        printf("%s", "Move Right");
    }

    if (key == 32) {
        printf("%s", "Spacebar");
    }

    if (key == 340) {
        printf("%s", "Shift");
    }

    if (key == 256) {
        printf("%s", "Escape key");
    }

    printf("%s", "\n");
    // printf("Hello from the second file!\n");
}

int add(int a, int b) {
    return a + b;
}
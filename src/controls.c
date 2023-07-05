// controls.c

#include <stdio.h>
#include "controls.h"

int print_key(int key) {
    int x = 0, y = 0;

    if (key == 87) {
        // printf("%s", "Move Forward");
        y+=1;
    }

    if (key == 83) {
        // printf("%s", "Move Backwards");
        y-=1;
    }

    if (key == 65) {
        // printf("%s", "Move Left");
        x-=1;
    }

    if (key == 68) {
        // printf("%s", "Move Right");
        x+=1;
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

    // printf("%s", "\n");
    // x, y
    
   // return ;
    // printf("Hello from the second file!\n");
}

int add(int a, int b) {
    return a + b;
}
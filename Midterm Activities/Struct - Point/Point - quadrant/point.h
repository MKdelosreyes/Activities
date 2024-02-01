#include <math.h>

typedef struct Point {
    int x;
    int y;

    // TODO create quadrant method here
    int quadrant() {
        if(x > 0 && y > 0)
            return 1;
        else if(x < 0 && y > 0)
            return 2;
        else if(x < 0 && y < 0)
            return 3;
        else if(x > 0 && y < 0)
            return 4;
        else if(x == 0 && y == 0)
            return 0;
        else
            return -1;
    }
} Point;

//typedef Point point;
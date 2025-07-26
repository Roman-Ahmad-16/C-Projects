#include <graphics.h>
#include <conio.h>

int main() {
    int gd = DETECT, gm;
    char path[] = "";
    initgraph(&gd, &gm, path);
    circle(320, 240, 200);
    getch();
    closegraph();
    return 0;
}


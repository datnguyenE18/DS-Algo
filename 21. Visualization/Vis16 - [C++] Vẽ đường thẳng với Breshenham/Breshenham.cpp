/*sử dụng thuật toán Breshenham để vẽ đường thẳng*/

#include <iostream>
#include <graphics.h>
//#include <bits/stdc++.h>
using namespace std;

int colorRedBlue = BLUE;

// k < -1:
void Gen_line1(int x1, int y1, int x2, int y2, int color){
    int x, y, dx, dy, D;
    x = x1; y = y1;
    dx = abs(x2 - x); dy = abs(y2 - y1);
    D = 2*dx + dy;
    putpixel(x, y, color);

    while(x != x2){
        if (D >= 0) {
            D += 2*dx;
        } else {
            D += 2*(dx + dy);
            x--;
        }
        y++;
        putpixel(x, y, color);
    }
}

// -1 <= k < 0
void Gen_line2(int x1, int y1, int x2, int y2, int color){
    int x, y, dx, dy, D;
    x = x1; y = y1;
    dx = abs(x2 - x1); dy = abs(y2 - y1);
    D = 2*dy + dx;
    putpixel(x, y, color);

    while(y != y2){
        if (D >= 0) {
            D += 2*dy;
        } else{
            D += 2*(dx + dy);
            y--;
        }
        x++;
        putpixel(x, y, color);
    }
}

// 0 < k <= 1
void Gen_line3(int x1, int y1, int x2, int y2, int color){
    int x, y, dx, dy, D;
    x = x1; y = y1;
    dx = abs(x2 - x1); dy = abs(y2 - y1);
    D = 2*dy - dx;
    putpixel(x, y, color);

    while (y != y2) {
        if(D < 0){
            D += 2*dy;
        } else{
            D += 2*(dy - dx);
            y++;
        }
        x++;
        putpixel(x, y, color);
    }
}

// k > 1
void Gen_line4(int x1, int y1, int x2, int y2, int color){
    int x, y, dx, dy, D;
    x = x1; y = y1;
    dx = abs(x2 -x1); dy = abs(y2 - y1);
    D = 2*dx - dy;
    putpixel(x, y, color);

    while( x != x2 ){
        if(D < 0){
            D += 2*dx;
        } else{
            D += 2*(dx - dy);
            x++;
        }
        y++;
        putpixel(x, y, color);
    }
}

int main(){
    int gd,gm=VGA; gd=DETECT;
    initgraph(&gd,&gm,NULL);
    setbkcolor(WHITE);
    Gen_line1(50,150, 300, 200);
    getchar();
    return 0;
}
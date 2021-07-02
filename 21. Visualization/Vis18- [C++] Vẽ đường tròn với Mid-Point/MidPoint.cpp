/*sử dụng thuật toán Breshenham để vẽ đường thẳng*/

#include <iostream>
#include <graphics.h>
//#include <bits/stdc++.h>
using namespace std;

int colorRedBlue = BLUE;

void Gen_circle(int xo, int yo, int r, int color){
    int x, y, D;
    x = 0; y = r;
    D = 1 - r;

    while(x <= y){
        putpixel(x + xo, y + yo, color);
        if (D < 0){
            D += 2*x + 3;
        } else{
            D += 2*(x - y) + 5;
            y--;
        }
        x++;
    }
}

int main(){
    int gd,gm=VGA; gd=DETECT;
    initgraph(&gd,&gm,NULL);
    setbkcolor(WHITE);
    Gen_circle(2, 3, 10, 200);
    getchar();
    return 0;
}
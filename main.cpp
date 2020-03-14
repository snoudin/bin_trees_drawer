#include "mainwindow.h"
#include "dialog.h"
#include "dialog.cpp"

#include <QApplication>
#include <algorithm>
#include <cstdlib>
#include <random>
#include <queue>
#include <ctime>
#include <cmath>

struct Tree{
    int depth = -1, root = -1, len1 = -1, len2 = -1;
    float angle = -1;
};

Tree fractal, input;

void setrand(){

    std::srand(unsigned(std::time(0)));
    if (input.depth == -1)
        fractal.depth = rand() % 20 + 1;
    if (input.root == -1)
        fractal.root = rand() % 125 + 25;
    if (input.len1 == -1)
        fractal.len1 = rand() % (fractal.root - 10) + 8;
    if (input.len2 == -1)
        fractal.len2 = rand() % (fractal.root - 10) + 8;
    if (input.angle == (float)-1)
        fractal.angle = rand() % 270;
}

std :: queue<QLine> to_draw;

void build(){
    struct edge{
        float x1, y1, angle, len;
        int depth;
    };
    std :: queue<edge> q;
    edge root = {400, 500, M_PI_2, (float)fractal.root, 0};
    q.push(root);
    while (!q.empty()){
        edge cur = q.front();
        to_draw.push(QLine(cur.x1, cur.y1, cur.x1 + cur.len * cosf(cur.angle), cur.y1 - cur.len * sinf(cur.angle)));
        if (q.front().depth < fractal.depth){
            edge child1, child2;
            float x2 = cur.x1 + cur.len * cosf(cur.angle), y2 = cur.y1 - sinf(cur.angle) * cur.len;
            float len1 = ((float)fractal.len1 / fractal.root) * cur.len,
                    len2 = ((float)fractal.len2 / fractal.root) * cur.len;
            float child1_angle = cur.angle + M_PI - fractal.angle / 180 * M_PI, child2_angle = cur.angle + M_PI_2 - fractal.angle / 180 * M_PI;
            len1 = std :: min(500, (int)len1);
            len2 = std :: min(500, (int)len2);
            if (abs(800 - x2) <= 800 && abs(y2 - 250) <= 500){
                child1 = {x2, y2, child1_angle, len1, cur.depth + 1};
                child2 = {x2, y2, child2_angle, len2, cur.depth + 1};
            }
            if (len1 >= 1)
                q.push(child1);
            if (len2 >= 1)
                q.push(child2);
        }
        q.pop();
    }

}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}


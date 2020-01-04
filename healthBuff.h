//
// Created by nanan on 5/6/2019.
//
/*
HealthBuff class is used to create the health pack as a reward for getting zombies
capacity to more than 10

Default Constructor
HealthBuff()

Constructor that takes in int x and y to randomnize where the health pack is produced
HealthBuff(int x, int y)

void method that draws the healthpack
void draw()

void method that moves the healthpack as the background moves to make the character to get to it
void move()

int method that returns the top left X coordinates
int getLeftX() const;

int method that returns the top Right X coordinates
int getRightX() const;

int method that returns the top Y coordinates
int getTopY() const;

int method that returns the Bottom Y coordinates
int getBottomY() const;

*/
#ifndef FINALPROJECT_DARKWHITE_HEALTHBUFF_H
#define FINALPROJECT_DARKWHITE_HEALTHBUFF_H

#include "rect.h"
#include "shapes.h"
#include <vector>

using namespace std;

class HealthBuff {
private:
    int addX, addY;
    vector<Shape*> fullPack;
    Rect mainBuff, verticalBar, horizontalBar;

public:
    HealthBuff();
    HealthBuff(int x, int y);
    void draw();
    void move(int x, int y);

    int getLeftX() const;
    int getRightX() const;
    int getTopY() const;
    int getBottomY() const;
    point getPoint() const;
};


#endif //FINALPROJECT_DARKWHITE_HEALTHBUFF_H

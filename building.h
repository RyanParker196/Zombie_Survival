//
// Created by Harry Makovsky on 5/2/19.
//

/*
This is a class that creates the actual building in the game.

    Constructor
    Building();

    Constructor that takes interger x
    Building(int centerX);

    Constructor that takes integer x and integer height
    Building(int centerX,unsigned int height);

    void method that draws the building
    void draw();

    void method that takes in int x and y and moves the building along as the character moves
    void move(int x, int y);

    int mthod that returns the right coordinates    
    int getRightX();

    int method that returns the left coordinates
    int getLeftX();

    void method that takes in int center to reset
    void reset(int centerX);

*/

#ifndef FINALPROJECT_DARKWHITE_BUILDING_H
#define FINALPROJECT_DARKWHITE_BUILDING_H

#include "shapes.h"
#include "rect.h"


class Building {
private:
    unsigned int height;
    unsigned int width;
    int randHeight;
    int randColor;
    double randColorDoub;
    point center;
    Rect building, window1,window2;

public:
    Building();
    Building(int centerX);
    Building(int centerX,unsigned int height);

    void move(int x, int y);
    void draw();

    unsigned int getHeight();

    point getCenter();

    int getRightX();
    int getLeftX();

    void reset(int centerX);


};


#endif //FINALPROJECT_DARKWHITE_BUILDING_H
//
// Created by Harry Makovsky on 5/2/19.
//
/*
This class is used ot create the city backgrouond city for the entire game. This class
also moves the background left to right as the man character moves away fromt the 
zombies.

	Constructor;
	Background();

	Method that draw the road, and the buildings
	void draw();

	void method that moves the background left
	void moveLeft

	void method that moves the background right
	void moveRight
*/

#ifndef FINALPROJECT_DARKWHITE_BACKGROUND_H
#define FINALPROJECT_DARKWHITE_BACKGROUND_H

#include "shapes.h"
#include "graphics.h"
#include "rect.h"
#include "building.h"
#include <vector>

using namespace std;


class Background {
private:
    double WIDTH;
    Rect road,line1,line2;
    vector<Building*> buildings;

public:

    Background();
    void draw();

    void moveLeft();
    void moveRight();


    vector<Building*> getBuildings();


};


#endif //FINALPROJECT_DARKWHITE_BACKGROUND_H

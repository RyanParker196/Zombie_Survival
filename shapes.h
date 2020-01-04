//
// Used Lisa Dion Graphics-Starter lab starter code
//

#ifndef SHAPES_SHAPES_H
#define SHAPES_SHAPES_H

#include "graphics.h"

// Your Shape class goes here

struct point{
    int x;
    int y;
};

struct color{
    double red;
    double green;
    double blue;
};

class Shape{
protected:

    point middle;

    color fill;

public:
    Shape();
    Shape(color col, point middle);

    point getCenter();
    void setCenter(int newX, int newY);

    void moveCenter(int changeX,int changeY);

    color getColor();
    void setColor(double newRed,double newGreen, double newBlue);


    //Method that calculates the area of any given shape object, implemented in the individual shape classes
    //virtual void overlapping() const =0;

    //Method that will eventually draw the shape based on its shape type, size, and color
    virtual void draw() const = 0;


    virtual ~Shape();


};

#endif //SHAPES_SHAPES_H
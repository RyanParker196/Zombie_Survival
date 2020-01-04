//
// Created by Harry Makovsky on 2/21/19.
//

#ifndef SHAPES_CIRCLE_H
#define SHAPES_CIRCLE_H

#include "shapes.h"
#include <cmath>

const double pi=3.14159265;

class Circle : public Shape{
private:
    double radius;


public:
    Circle();
    Circle(color col, point middle, double rad);

    double getRadius();
    void setRadius(double rad);

    virtual void draw() const override;




};


#endif //SHAPES_CIRCLE_H

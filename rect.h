//
// Created by Harry Makovsky on 2/21/19.
//
/*
The rect class draws a rectangle shape
    
    Default Constructor
    Rect();

    Constructor that holds a color fill, point center, int withd and int height
    Rect(color fill, point center, unsigned int width, unsigned int height);

    int method that returns the center x point in int form
    int getCenterX() const;

    int method that returns the left x point in int form
    int getLeftX() const;

    int method that returns the right x point in int form
    int getRightX() const;

    int method that returns the center y point in int form
    int getCenterY() const;

    int method that returns the top y point in int form
    int getTopY() const;

    int method that returns the bottom y point in int form
    int getBottomY() const;

    point method that returns the center coordinates
    point getCenter() const;

    double method that returns the the red color point
    double getRed() const;

    double method that returns the the green color point
    double getGreen() const;

    double method that returns the the blue color point
    double getBlue() const;

    color method that returns the the rgb point
    color getFill() const;

    unsigned int getWidth() const;
    unsigned int getHeight() const;

    void setColor(double red, double green, double blue);
    void setColor(color fill);
    void move(int deltaX, int deltaY);
    void resize(unsigned int width, unsigned int height);
    void setCenter(int x, int y);

    virtual void draw() const override;


*/
#ifndef GRAPHICS_STARTER_RECT_H
#define GRAPHICS_STARTER_RECT_H

#include "shapes.h"
#include "rect.h"

class Rect : public Shape{
private:
    color fill;
    point center;
    unsigned int width;
    unsigned int height;

public:
    Rect();
    Rect(color fill, point center, unsigned int width, unsigned int height);

    int getCenterX() const;
    int getLeftX() const;
    int getRightX() const;
    int getCenterY() const;
    int getTopY() const;
    int getBottomY() const;
    point getCenter() const;

    double getRed() const;
    double getGreen() const;
    double getBlue() const;
    color getFill() const;

    unsigned int getWidth() const;
    unsigned int getHeight() const;

    void setColor(double red, double green, double blue);
    void setColor(color fill);
    void move(int deltaX, int deltaY);
    void resize(unsigned int width, unsigned int height);
    void setCenter(int x, int y);

    virtual void draw() const override;

};



#endif //SHAPES_RECTANGLE_H

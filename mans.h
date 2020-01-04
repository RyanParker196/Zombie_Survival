//
// Created by Harry Makovsky on 4/15/19.
//

/*
 * Mans class
 *
 * This class is used to create the character in zombies. The class will contain instructions
 * on how to draw their body and also have information about their position and speed
 *
 *     Mans();
 *     Mans constructor which initializes the mans body
 *
 *     void draw();
 *     Method that draws the dudes body in the game at his initial position
 *
 *     void move(double x,double y);
 *     moves the dude by x and y
 *     int getBottomY();
 *     returns bottom y coordinate
 *     int getCenterX();
 *     returns center x coordinate
 *     double getVelocity() const;
 *     returns velocity
 *     void setVelocity(double);
 *     sets velocity
 *     void resetPos();
 *     set mans position to initial position

 *
 */

#ifndef FINALPROJECT_RED_DUDE_H
#define FINALPROJECT_RED_DUDE_H

#include "rect.h"
#include "shapes.h"
#include "circle.h"
#include <vector>
#include "zombie.h"



using namespace std;


class Mans {
private:

    int health;
    vector<Shape*> wholeBody;
    Rect body,arms,leg1,leg2;
    Circle head;
    double velocityX,velocityY;
    Rect barrel,handle;
    bool facingRight;

    int buffX,buffY;


public:
    Mans();
    Mans(int menu);

    void draw();
    void move(double x,double y);

    int getHealth() const;
    void setHealth(int health);
    int getBottomY();
    int getTopY();
    int getLeftX();
    int getRightX();


    int getCenterY();
    int getCenterX();

    point getCenter();

    double getVelocityX() const;
    void setVelocityX(double v);
    double getVelocityY() const;
    void setVelocityY(double v);

    void resetPos();

    bool isFacingRight();
    void setFacingRight(bool right);

    void turnLeft();
    void turnRight();

    point getBarrelCoords();


};


#endif //FINALPROJECT_RED_DUDE_H

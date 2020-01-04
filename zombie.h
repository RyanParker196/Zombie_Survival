//
// Created by Harry Makovsky on 5/2/19.
//

#ifndef FINALPROJECT_DARKWHITE_ZOMBIE_H
#define FINALPROJECT_DARKWHITE_ZOMBIE_H

#include "rect.h"
#include "shapes.h"
#include "circle.h"
#include <vector>
#include "string"
/*
 * Zombie class
 *
 * This class is used to create the zombies. The class will contain instructions
 * on how to draw their body and also have information about their position and speed
 *
 *     Zombie();
 *     Zombie constructor which initializes the mans body
 *
 *     void draw();
 *     Method that draws the zombies body in the game

 *     void move(double x,double y);
 *     moves the zombie x and y
 *     int getBottomY();
 *     returns bottom y coordinate
 *     int getTopY();
 *     returns top y coordinate
 *     int getRightX();
 *     returns right x coordinate
 *     int getLeftX();
 *     returns left x coordinate
 *
 *     int getCenterX();
 *     returns center X coordinate
 *     int getCenterY();
 *     returns center Y coordinate
 *
 *     void chase(point)
 *     zombies chase man's center
 *     void setSpeed(double);
 *     sets speed of zombie
 *     void turnRight()
 *     turns zombie right if they are to left of man
 *     void turnLeft()
 *     turns zombie left if they are to right of man
 *
 *

 *
 */



class Zombie {
    std::string shirt;
    std::vector<Shape*> wholeBody;
    Rect body,arms,leg1,leg2;
    Circle head;
    double velocityX,velocityY;

    double speed;

    bool facingRight;

    int buffX,buffY;


public:
    Zombie();
    Zombie(int x, int y);


    void draw();
    void move(double x,double y);
    void destroy();

    int getBottomY();
    int getTopY();
    int getLeftX();
    int getRightX();
    int getCenterY();
    int getCenterX();

    double getVelocityX() const;
    void setVelocityX(double v);
    double getVelocityY() const;
    void setVelocityY(double v);

    void chase(point centerMans);

    void resetPos();

    bool isFacingRight();
    void setFacingRight(bool right);

    void turnLeft();
    void turnRight();

    double getSpeed();
    void setSpeed(double newS);


};


#endif //FINALPROJECT_DARKWHITE_ZOMBIE_H

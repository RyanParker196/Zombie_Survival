//
// Created by Ryan on 5/4/2019.
//

/*
	Bullet class makes just the amor that is shot from the gun

	Constructor that takes in a point p
	Bullet(point p)

	void method that takes int v move the bullet towards the direction the character is facing 
	void move(int v)
	
	void method that draws the bullet
	void draw()

	void method that takes an int v and set the velocity of the bullet
	void setVelocity(int v)

	int method that returns the velocity of the bullet
	int getVelocity()

*/

#ifndef FINALPROJECT_DARKWHITE_BULLET_H
#define FINALPROJECT_DARKWHITE_BULLET_H

#include "Circle.h"


//TODO: if somebody holds F the bullet fire rate gets way to fast
class Bullet {
private:
    Circle shot;
    int velocity;
public:
    Bullet(point p);
    void move(int v);
    void draw();
    int getVelocity();
    void setVelocity(int v);
    point getLocation();


};


#endif //FINALPROJECT_DARKWHITE_BULLET_H

//
// Created by Harry Makovsky on 4/15/19.
//

#include "mans.h"
#include "zombie.h"
#include <math.h>

#include <string>

using namespace std;



Mans::Mans(){

    health = 300;
    buffX=190;
    buffY=50;

    //guns
    barrel=Rect({1.0,1.0,1.0},{267+buffX,260+buffY},8,3);
    handle=Rect({1.0,1.0,1.0},{265+buffX,263+buffY},3,4);
    //arms
    arms = Rect({0.0,0.0,0.4},{260+buffX,263+buffY},15,6);
    //chest
    body= Rect({0.0,0.0,0.4},{250+buffX,268+buffY},15,20);
    //head
    head= Circle({1.0,0.0,1.0},{250+buffX,252+buffY},7);
    //leg1
    leg1= Rect({1.0,0.6,0.2},{248+buffX,282+buffY},6,20);
    //leg2
    leg2=  Rect({1.0,0.6,0.2},{252+buffX,282+buffY},5,20);

    //Polymorphism creation of vector
    wholeBody.emplace_back(&arms);

    wholeBody.emplace_back(&head);
    wholeBody.emplace_back(&leg1);
    wholeBody.emplace_back(&leg2);
    wholeBody.emplace_back(&body);
    wholeBody.emplace_back(&barrel);
    wholeBody.emplace_back(&handle);

    velocityX=0;
    velocityY=0;

    facingRight=true;

}
Mans::Mans(int menu){

    health = 300;
    buffX=-150;
    buffY=-218;

    //guns
    barrel=Rect({1.0,1.0,1.0},{267+buffX,260+buffY},8,3);
    handle=Rect({1.0,1.0,1.0},{265+buffX,263+buffY},3,4);
    //arms
    arms = Rect({0.0,0.0,0.4},{260+buffX,263+buffY},15,6);
    //chest
    body= Rect({0.0,0.0,0.4},{250+buffX,268+buffY},15,20);
    //head
    head= Circle({1.0,0.0,1.0},{250+buffX,252+buffY},7);
    //leg1
    leg1= Rect({1.0,0.6,0.2},{248+buffX,282+buffY},6,20);
    //leg2
    leg2=  Rect({1.0,0.6,0.2},{252+buffX,282+buffY},5,20);

    //Polymorphism creation of vector
    wholeBody.emplace_back(&arms);

    wholeBody.emplace_back(&head);
    wholeBody.emplace_back(&leg1);
    wholeBody.emplace_back(&leg2);
    wholeBody.emplace_back(&body);
    wholeBody.emplace_back(&barrel);
    wholeBody.emplace_back(&handle);

    velocityX=0;
    velocityY=0;

    facingRight=true;

}


void Mans::draw(){

    //Polymorphism draws from vector of different shape objects
    for(Shape *shape: wholeBody){
        shape->draw();
    }
    glColor3f(1,1,1);

    glRasterPos2i(body.getCenterX()-20,body.getCenterY()+4);

    string shirt= "  M";

    for (char &letter : shirt){
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, letter);
    }

}

void Mans::move(double x, double y){
    //Moves each body part
    body.move(x,y);
    head.moveCenter(x,y);
    leg1.move(x,y);
    leg2.move(x,y);
    arms.move(x,y);
    barrel.move(x,y);
    handle.move(x,y);
}

int Mans::getBottomY() {
    return body.getBottomY();
}


double Mans::getVelocityX()const {
    return velocityX;
}
void Mans::setVelocityX(double v) {
    velocityX=v;
}

double Mans::getVelocityY()const {
    return velocityY;
}
void Mans::setVelocityY(double v) {
    velocityY=v;
}

void Mans::resetPos(){

    body.move(0,250-body.getCenterY());
    head.moveCenter(0,243-head.getCenter().y);
    leg1.move(0,247-leg1.getCenterY());
    leg2.move(0,253-leg2.getCenterY());
    arms.move(0,253-arms.getCenterY());
}

int Mans::getCenterY() {
    return body.getCenterY();
}
int Mans::getCenterX(){
    return body.getCenterX();
}

//barrel=Rect({1.0,1.0,1.0},{267,260},8,3);
//handle=Rect({1.0,1.0,1.0},{265,263},3,4);

//arms = Rect({1.0,0.0,1.0},{260,263},15,6);

//body= Rect({1.0,0.0,1.0},{250,268},15,20);

void Mans::turnLeft(){
    if(facingRight){
        barrel.setCenter(barrel.getCenterX()-2*(barrel.getCenterX()-body.getCenterX()),barrel.getCenterY());
        handle.setCenter(handle.getCenterX()-2*(handle.getCenterX()-body.getCenterX()),handle.getCenterY());
        arms.setCenter(arms.getCenterX()-2*(arms.getCenterX()-body.getCenterX()),arms.getCenterY());
        facingRight=false;
    }
}

void Mans::turnRight(){
    if(!facingRight){
        barrel.setCenter(barrel.getCenterX()+2*(body.getCenterX()-barrel.getCenterX()),barrel.getCenterY());
        handle.setCenter(handle.getCenterX()+2*(body.getCenterX()-handle.getCenterX()),handle.getCenterY());
        arms.setCenter(arms.getCenterX()+2*(body.getCenterX()-arms.getCenterX()),arms.getCenterY());
        facingRight=true;
    }
}


bool Mans::isFacingRight(){
    return facingRight;
}
void Mans::setFacingRight(bool isRight){
    facingRight=isRight;
}

point Mans::getBarrelCoords(){
    return {barrel.getCenterX(),barrel.getCenterY()};
}

point Mans::getCenter() {
    return body.getCenter();
}

int Mans::getHealth() const {
    return health;
}

void Mans::setHealth(int health) {
    this->health = health;
}

int Mans::getTopY() {
    return body.getTopY()-14;
}
int Mans::getLeftX() {
    return body.getLeftX();
}

int Mans::getRightX() {
    return body.getRightX();
}




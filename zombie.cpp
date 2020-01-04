//
// Created by Harry Makovsky on 5/2/19.
//

#include "zombie.h"


#include <string>

using namespace std;



Zombie::Zombie(){
    shirt= "  Z";
    buffX=0;
    buffY=0;

    //arms
    arms = Rect({0.24,0.42,0.25},{260+buffX,263+buffY},15,6);
    //chest
    body= Rect({0.24,0.42,0.25},{250+buffX,268+buffY},15,20);
    //head
    head= Circle({0.24,0.42,0.25},{250+buffX,252+buffY},7);
    //leg1
    leg1= Rect({0.24,0.42,0.25},{248+buffX,282+buffY},6,20);
    //leg2
    leg2=  Rect({0.24,0.42,0.25},{252+buffX,282+buffY},5,20);

    //Polymorphism creation of vector
    wholeBody.emplace_back(&arms);
    wholeBody.emplace_back(&body);
    wholeBody.emplace_back(&head);
    wholeBody.emplace_back(&leg1);
    wholeBody.emplace_back(&leg2);


    velocityX=0;
    velocityY=0;

    speed=1.5;



    facingRight=true;

}




void Zombie::draw(){

    //Polymorphism draws from vector of different shape objects
    for(Shape *shape: wholeBody){
        shape->draw();
    }
    glColor3f(1,1,1);

    glRasterPos2i(body.getCenterX()-20,body.getCenterY()+4);



    for (char &letter : shirt){
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, letter);
    }

}

void Zombie::chase(point centerMans){
    int distX= centerMans.x-body.getCenterX();
    int distY= centerMans.y-body.getCenterY();

    if(distX>0){
        move(speed,0);
    }
    if(distX<0){
        move(-speed,0);
    }

    if(distY<0){
        move(0,-speed);
    }

    if(distY>0){
        move(0,speed);
    }

}

void Zombie::move(double x, double y){
    //Moves each body part
    body.move(x,y);
    head.moveCenter(x,y);
    leg1.move(x,y);
    leg2.move(x,y);
    arms.move(x,y);

}




double Zombie::getVelocityX()const {
    return velocityX;
}
void Zombie::setVelocityX(double v) {
    velocityX=v;
}

double Zombie::getVelocityY()const {
    return velocityY;
}
void Zombie::setVelocityY(double v) {
    velocityY=v;
}

void Zombie::resetPos(){

    body.move(0,250-body.getCenterY());
    head.moveCenter(0,243-head.getCenter().y);
    leg1.move(0,247-leg1.getCenterY());
    leg2.move(0,253-leg2.getCenterY());
    arms.move(0,253-arms.getCenterY());
}

int Zombie::getCenterY() {
    return body.getCenterY();
}
int Zombie::getCenterX(){
    return body.getCenterX();
}


void Zombie::turnLeft(){
    if(facingRight){
        arms.setCenter(arms.getCenterX()-2*(arms.getCenterX()-body.getCenterX()),arms.getCenterY());
        facingRight=false;
    }
}

void Zombie::turnRight(){
    if(!facingRight){

        arms.setCenter(arms.getCenterX()+2*(body.getCenterX()-arms.getCenterX()),arms.getCenterY());
        facingRight=true;
    }
}


bool Zombie::isFacingRight(){
    return facingRight;
}
void Zombie::setFacingRight(bool isRight){
    facingRight=isRight;
}
int Zombie::getBottomY() {
    return leg1.getBottomY();
}
int Zombie::getTopY() {
    return body.getTopY()-14;
}

int Zombie::getLeftX() {
    return body.getLeftX();
}

int Zombie::getRightX() {
    return body.getRightX();
}

void Zombie::destroy() {
    body.resize(0,0);
    arms.resize(0,0);
    leg1.resize(0,0);
    leg2.resize(0,0);
    head.setRadius(0);
    shirt = "";
}

double Zombie::getSpeed(){
    return speed;
}

void Zombie::setSpeed(double newS){
    speed=newS;
}

Zombie::Zombie(int x, int y) {
    shirt= "  Z";
    buffX=0;
    buffY=0;

    //arms
    arms = Rect({0.24,0.42,0.25},{x+260+buffX,y+263+buffY},15,6);
    //chest
    body= Rect({0.24,0.42,0.25},{x+250+buffX,y+268+buffY},15,20);
    //head
    head= Circle({0.24,0.42,0.25},{x+250+buffX,y+252+buffY},7);
    //leg1
    leg1= Rect({0.24,0.42,0.25},{x+248+buffX,y+282+buffY},6,20);
    //leg2
    leg2=  Rect({0.24,0.42,0.25},{x+252+buffX,y+282+buffY},5,20);

    //Polymorphism creation of vector
    wholeBody.emplace_back(&arms);
    wholeBody.emplace_back(&body);
    wholeBody.emplace_back(&head);
    wholeBody.emplace_back(&leg1);
    wholeBody.emplace_back(&leg2);


    velocityX=0;
    velocityY=0;

    speed=1.5;

    facingRight=true;
}


//
// Created by Harry Makovsky on 5/2/19.
//

#include "building.h"

//262 is the bottom of the building

Building::Building(){
    width=150;
    randHeight= rand() % 100 + 150;
    randColor = rand()% 10;
    randColorDoub = .1 * randColor;


    height= randHeight;

    center={375,int(262-(height/2))};

    building= Rect({randColorDoub*.5,randColorDoub*.1,randColorDoub*.9},center,width,height);

    window1= Rect({0.4,0.5,0.6},{center.x-30,center.y-20},20,20);
    window2= Rect({0.4,0.5,0.6},{center.x+30,center.y-20},20,20);


}

Building::Building(int centerX){
    width=150;
    randHeight= rand() % 150 + 100;
    randColor = rand()% 10;
    randColorDoub = .1 * randColor;
    height= randHeight;

    center={centerX,int(262-(height/2))};

    building= Rect({randColorDoub*.5,randColorDoub*.1,randColorDoub*.9},center,width,height);

    window1= Rect({0.4,0.5,0.6},{center.x-30,center.y-20},20,20);
    window2= Rect({0.4,0.5,0.6},{center.x+30,center.y-20},20,20);


}

Building::Building(int centerX, unsigned int height){
    width=150;

    center={centerX,int(262-(height/2))};

    building= Rect({randColorDoub,randColorDoub,randColorDoub},center,width,height);

    window1= Rect({0.4,0.5,0.6},{center.x-30,center.y-20},20,20);
    window2= Rect({0.4,0.5,0.6},{center.x+30,center.y-20},20,20);


}


void Building::move(int x, int y){

    building.move(x,y);
    window1.move(x,y);
    window2.move(x,y);
}

void Building::draw(){
    building.draw();
    window1.draw();
    window2.draw();
}

int Building::getRightX() {
    return building.getCenterX() + 75;
}

int Building::getLeftX() {
    return building.getCenterX() - 75;
}

point Building::getCenter(){
    return center;
}
unsigned int Building::getHeight(){
    return height;
}

void Building::reset(int centerX) {


}
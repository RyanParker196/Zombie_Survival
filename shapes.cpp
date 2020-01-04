//
// Used Lisa Dion Graphics-Starter lab starter code
// Draw function is overridden in rect and circle classes
//

#include "shapes.h"

Shape::Shape(){
    middle={0,0};
    fill={0,0,0};


}

Shape::Shape(color col, point middle){
    this -> middle = middle;
    fill= col;

}

point Shape::getCenter(){
    return middle;
}

void Shape::setCenter(int newX, int newY){
    middle.x=newX;
    middle.y=newY;
}

void Shape::moveCenter(int changeX,int changeY){
    middle.x+=changeX;
    middle.y+=changeY;
}

color Shape::getColor(){
    return fill;
}

void Shape::setColor(double newRed,double newGreen, double newBlue){
    fill.red=newRed;
    fill.green=newGreen;
    fill.blue=newBlue;
}

Shape::~Shape(){

}
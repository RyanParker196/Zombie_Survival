//
// Created by Harry Makovsky on 2/21/19.
//

#include "circle.h"
#define _USE_MATH_DEFINES
using namespace std;

Circle::Circle(){

}

Circle::Circle(color col, point middle, double rad) : Shape(col, middle){
    setRadius(rad);
}

double Circle::getRadius(){
    return radius;

}
void Circle::setRadius(double rad){
    if (rad>0){
        radius=rad;
    }
    else{
        radius=1;
    }
}

void Circle::draw() const{
    glBegin(GL_TRIANGLE_FAN);

    //Create initial center point glVertex2i(cirX, cirY);
    //set radius and initialize x and y variables
    float radius = this->radius;
    float xGen, yGen;

    glColor3f(fill.red, fill.green, fill.blue);
    //for all 360 degrees, use sin and cos to determine x and y
    for(int angle = 0; angle <= 360; angle++){
        xGen = middle.x + float(cos(angle*(pi/180)) * radius);
        yGen = middle.y + float(sin(angle*(pi/180)) * radius);

        //create a vertex for the given angle
        glVertex2i(xGen, yGen);
    }
    glEnd();
}
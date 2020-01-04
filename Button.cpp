/*
 * Button class creates a rectangular button using the rect class.
 * Used Lisa Dion Graphics-Starter lab starter code
 *
 * This sets the color of the text on the box and draws it one, and draws a box using rect.
 * */

#include "Button.h"
#include "graphics.h"
using namespace std;

/************ Button **************/

Button::Button() {
    originalFill = {0,0,0};
    hoverFill = {box.getRed()+0.5, box.getGreen()+0.5, box.getBlue()+0.5};
    pressFill = {box.getRed()-0.5, box.getGreen()-0.5, box.getBlue()-0.5};
}
Button::Button(Rect box, string label) {
    this->box = box;
    this->label = label;
    originalFill = box.getFill();
    hoverFill = {box.getRed()+0.5, box.getGreen()+0.5, box.getBlue()+0.5};
    pressFill = {box.getRed()-0.5, box.getGreen()-0.5, box.getBlue()-0.5};
}

void Button::draw() {
    box.draw();
    glColor3f(1,1,1);
    //glRasterPos2i(50,200);
    glRasterPos2i(box.getCenterX()-(4*label.length()), box.getCenterY()+7);
    for (char &letter : label) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, letter);
    }
}

/* Returns true if the coordinate is inside the box */
bool Button::isOverlapping(int x, int y) const {

    if (x > box.getLeftX() && x < box.getRightX() && y > box.getTopY() && y < box.getBottomY()) {
        return true;
    }
    else {
        return false; // Placeholder for compilation
    }
}


/* Change color of the box when the user is hovering over it */
void Button::hover() {
    box.setColor(hoverFill);
}

/* Change color of the box when the user is clicking on it */
void Button::pressDown() {
    box.setColor(pressFill);
}

/* Change the color back when the user is not clicking/hovering */
void Button::release() {
    box.setColor(originalFill);
}

/* Execute whatever the Button is supposed to do */
void Button::click(function<void()> callback) {
    callback();
}

Button::~Button(){

}
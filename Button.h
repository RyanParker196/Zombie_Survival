//
// Created by Lisa Dion on 11/6/18.
//

#ifndef GRAPHICS_STARTER_BUTTON_H
#define GRAPHICS_STARTER_BUTTON_H

#include "rect.h"
#include <string>
#include <functional>

using std::string;

class Button { 
private:
    /* Assume Rect includes color, center, width, height */
    Rect box;
    std::string label;
    color originalFill, hoverFill, pressFill;

public:
    Button();
    Button(Rect box, string label);
    /* Uses OpenGL to draw the box with the label on top */
    virtual void draw();

    /* Returns true if the coordinate is inside the box */
    bool isOverlapping(int x, int y) const;

    /* Change color of the box when the user is hovering over it */
    void hover();

    /* Change color of the box when the user is clicking on it */
    void pressDown();

    /* Change the color back when the user is not clicking/hovering */
    void release();

    /* Execute whatever the Button is supposed to do */
    virtual void click(std::function<void()> callback);

    virtual ~Button();
};


#endif //GRAPHICS_STARTER_BUTTON_H

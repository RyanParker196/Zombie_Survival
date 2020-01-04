//
// Created by Harry Makovsky on 2/21/19.
//

#include "rect.h"
#include "graphics.h"
#include <iostream>
#include <vector>

/********** Rect *************/

Rect::Rect() {
    fill = {0, 0, 0};
    center = {0, 0};
    width = 50;
    height = 50;
}

Rect::Rect(color fill, point center, unsigned int width, unsigned int height) {
    this->fill = fill;
    this->center = center;
    this->width = width;
    this->height = height;
}

int Rect::getCenterX() const {
    return center.x;
}

int Rect::getLeftX() const {
    return center.x - (width / 2);
}

int Rect::getRightX() const {
    return center.x + (width / 2);
}

int Rect::getCenterY() const {
    return center.y;
}

int Rect::getTopY() const {
    return center.y - (height / 2);
}

int Rect::getBottomY() const {
    return center.y + (height / 2);
}

point Rect::getCenter() const {
    return center;
}

double Rect::getRed() const {
    return fill.red;
}

double Rect::getGreen() const {
    return fill.green;
}

double Rect::getBlue() const {
    return fill.blue;
}

color Rect::getFill() const {
    return fill;
}

unsigned int Rect::getWidth() const {
    return width;
}

unsigned int Rect::getHeight() const {
    return height;
}

void Rect::setColor(double red, double green, double blue) {
    fill = {red, green, blue};
}

void Rect::setColor(color fill) {
    this->fill = fill;
}

void Rect::move(int deltaX, int deltaY) {
    center.x += deltaX;
    center.y += deltaY;
}

void Rect::resize(unsigned int width, unsigned int height) {
    this->width = width;
    this->height = height;
}

void Rect::draw() const {
    // TODO: Implement
    glColor3f(getRed(), getGreen(), getBlue());
    glBegin(GL_QUADS);
    glVertex2i(getLeftX(), getTopY());
    glVertex2i(getRightX(), getTopY());
    glVertex2i(getRightX(), getBottomY());
    glVertex2i(getLeftX(), getBottomY());

    glEnd();

    // Don't forget to set the color to the fill field
}

void Rect::setCenter(int x, int y) {
    center = {x, y};
}

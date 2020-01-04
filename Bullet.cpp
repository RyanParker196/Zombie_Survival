//
// Created by Ryan on 5/4/2019.
//

#include "Bullet.h"


Bullet::Bullet(point p) {
    shot = Circle({1.0,1.0,1.0},{p},5);
    velocity = 10;
}

void Bullet::move(int v) {
    shot.moveCenter(v,0);
}

void Bullet::draw() {
    shot.draw();
}

int Bullet::getVelocity() {
    return velocity;
}

void Bullet::setVelocity(int v) {
    velocity = v;
}

point Bullet::getLocation() {
    return this->shot.getCenter();
}

//
// Created by nanan on 5/6/2019.
//

#include "healthBuff.h"
#include <string>

using namespace std;

HealthBuff::HealthBuff(){
    addX = 10;
    addY = 10;
    //main pack
    mainBuff = Rect({1.0,1.0,1.0},{250+addX, 250+addY}, 20,20);
    horizontalBar = Rect({1.0,0.0,0.0},{250+addX, 250+addY}, 20,10);
    verticalBar = Rect({1.0,0.0,0.0},{250+addX, 250+addY}, 10,20);

    fullPack.emplace_back(&mainBuff);
    fullPack.emplace_back(&horizontalBar);
    fullPack.emplace_back(&verticalBar);

}

HealthBuff::HealthBuff(int x, int y) {
    addX=10;
    addY =10;
    mainBuff = Rect({1.0,1.0,1.0},{x+addX, y+addY}, 20,20);
    horizontalBar = Rect({1.0,0.0,0.0},{x+addX, y+addY}, 20,10);
    verticalBar = Rect({1.0,0.0,0.0},{x+addX, y+addY}, 10,20);

    fullPack.emplace_back(&mainBuff);
    fullPack.emplace_back(&horizontalBar);
    fullPack.emplace_back(&verticalBar);


}

void HealthBuff::draw() {
    for (Shape *shape: fullPack){
        shape->draw();
    }

}

void HealthBuff::move(int x, int y) {
    mainBuff.move(x,y);
    horizontalBar.move(x,y);
    verticalBar.move(x,y);
}

int HealthBuff::getLeftX() const {
    return  mainBuff.getLeftX();
}

int HealthBuff::getRightX() const{
    return mainBuff.getRightX();
}

int HealthBuff::getTopY() const{
    return mainBuff.getTopY();
}

int HealthBuff::getBottomY() const{
    return mainBuff.getBottomY();
}

point HealthBuff::getPoint() const {
    return mainBuff.getCenter();
}

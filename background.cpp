//
// Created by Harry Makovsky on 5/2/19.
//

#include "background.h"

using namespace std;


Background::Background(){
    WIDTH=900;
    road=Rect({0.512,0.512,0.512},{450,350},900,176);



    line1=Rect({1.0,0.9,0.0},{450,346},900,6);
    line2=Rect({1.0,0.9,0.0},{450,354},900,6);

    for(int i=-75; i<=975 ; i+=150){
        buildings.push_back(new Building(i));
    }


}

void Background::draw(){
    road.draw();
    line1.draw();
    line2.draw();

    for(Building* build: buildings){
        build->draw();
    }
}


void Background::moveLeft(){
    for(Building* build: buildings){
        build->move(-3,0);

        if(build->getRightX()<0){

            //build->reset(build->getCenter().x);
            build->move(1050,0);
        }

    }

}
void Background::moveRight(){
    for(Building* build: buildings){
        build->move(3,0);

        if(build->getLeftX()>900){

            //build->reset(build->getCenter().x);
            build->move(-1050,0);
        }
    }

}

vector<Building*> Background::getBuildings() {
    return buildings;
}
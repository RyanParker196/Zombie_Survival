#include "graphics.h"
#include <iostream>
#include <vector>
#include "Button.h"
#include "mans.h"
#include <iomanip>
#include "circle.h"
#include "background.h"
#include "zombie.h"
#include "Bullet.h"
#include "algorithm"
#include "cstdlib"
#include "ctime"
#include "healthBuff.h"

using namespace std;

const int WIDTH = 900, HEIGHT = 500;
GLdouble width= WIDTH, height= HEIGHT;
int wd;

vector<Bullet> shots;
vector<Zombie*> zombies;
vector<HealthBuff*> buffs;


//Number of zombies on screen, starting at 1
int zombieCap = 0;

//Number for how many buffs to spawn
int buffCap = 0;

//Create main character
Mans man;

// Create backround
Background background;

//Create Sidewalk
Rect sidewalk;

//Variable initialization's for grenade and kill count
double nadeRegen=0;

bool splode=false;

double splodeTime=0;

double zombieTime=0;

int killCount=0;
int highScore;

//drawing animation for grenade
Circle splodeAnimate1,splodeAnimate2,splodeAnimate3;

//enum for different screen window's
enum screen{start,game,results,instructions};

// project starts on start screen
screen curr=start;

// declaring all collision methods
void checkCollisionB(Bullet &bullet);
void checkCollisionZ(Zombie* zom);
void checkCollisionH(HealthBuff *healthBuff);

// declaring zombies and menu man for start screen animation
Mans menuMans=Mans(0);
Zombie menuZom1,menuZom2,menuZom3,menuZom4;



void init() {
    //plays audio file
    //For this to work audio.py and Thriller.mp3 needs to be moved inside of cmake-build-debug
    system("python audio.py");


    //used random for zombie spawning
    srand(time(0));
    curr=start;
    menuZom2.move(150,0);
    menuZom3.move(50,100);
    menuZom4.move(0,200);

    sidewalk=Rect({.2,.2,.2},{450,469},900,62);

}

/* Initialize OpenGL Graphics */
void initGL() {
    // Set "clearing" or background color
    glClearColor(0.7f, 0.2f, 0.2f, 0.0f); // Black and opaque
}

/* Handler for window-repaint event. Call back when the window first appears and
 whenever the window needs to be re-painted. */

void display(){

    //Making all messages for use in different screens
    string hp = "Health: "+to_string(man.getHealth());
    string message = "Zombie Survival";
    string message1 = "Results";
    string message2 = "Instructions";
    string message3 = "One man is left to fight for his life against the zombie hoard!";
    string message4 = "Use the arrow key's to move the man up/down and left/right";
    string message5 = "Press 'f' to shoot and 'g' to use a grenade. Press 's' to pause game.";
    string message6 = "Don't waste your grenade, you can only use one every few seconds";
    string message7 = "Pick up health packs for bonus HP, and Survive for as long as possible";
    string killCountString = "You Killed:      "+to_string(killCount)+"      Zombies";

    // Making all the buttons
    Rect playRec({0.5,0.8,0.5},{450,150},150,40);
    Button play(playRec,"Play");

    Rect instructRec({0.5,0.8,0.5},{450,220},150,40);
    Button instructBut(instructRec,"Instructions");
    Rect backMainRec({0.5,0.8,0.5},{450,400},150,40);
    Button backMain(backMainRec,"Back to Main");
    Rect quitRec({0.5,0.8,0.5},{450,270},150,40);
    Button quit(quitRec,"Quit");

    // tell OpenGL to use the whole window for drawing
    glViewport(0, 0, width, height);



    // do an orthographic parallel projection with the coordinate
    // system set to first quadrant, limited by screen/window size

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, width, height, 0.0, -1.f, 1.f);

    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer with current clearing color

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);



    switch(curr){
        case start:
            //drawing zombies and man for start screen animation
            menuMans.draw();
            menuZom1.draw();
            menuZom2.draw();
            menuZom3.draw();
            menuZom4.draw();

            glColor3f(1,1,1);

            //writing title of game on start screen
            glRasterPos2i(370,100);
            for (char &letter : message){
                glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, letter);
            }

            // drawing buttons
            play.draw();

            instructBut.draw();
            break;
        case game:
            // draws backround

            background.draw();

            // randomly spawns health packs
            if (buffs.size() < buffCap){
                int x,y;
                int random = randNum(1,6);

                if (random == 1){
                    x = 100;
                    y = 280;
                }
                if (random == 2){
                    x=150;
                    y=400;
                }
                if (random == 3){
                    x=700;
                    y=300;
                }
                if (random ==4 ){
                    x=250;
                    y=400;
                }
                if (random == 5){
                    x=600;
                    y=290;
                }
                if (random ==6 ){
                    x=150;
                    y=410;
                }
                HealthBuff* hb = new HealthBuff(x,y);
                buffs.push_back(hb);
            }

            // draw's all health packs
            for (HealthBuff* hb: buffs){
                hb->draw();
            }

            if (man.getHealth() > 0){
                man.draw();
            }

            if (zombies.size() < zombieCap){
                //random spawn for zombie x and y
                int x,y;
                int random = randNum(1,12);

                if (random == 1){
                    x = 0;
                    y = 0;
                }
                if (random == 2){
                    x=100;
                    y=100;
                }
                if (random == 3){
                    x=150;
                    y=200;
                }
                if (random ==4 ){
                    x=250;
                    y=400;
                }
                if (random ==5 ){
                    x=700;
                    y=350;
                }
                if (random ==6 ){
                    x=300;
                    y=100;
                }
                if (random ==7 ){
                    x=300;
                    y=0;
                }
                if (random ==8 ){
                    x=700;
                    y=0;
                }
                if (random ==9 ){
                    x=350;
                    y=100;
                }
                if (random ==10 ){
                    x=450;
                    y=450;
                }
                if (random ==11 ){
                    x=450;
                    y=0;
                }
                if (random ==12 ){
                    x=700;
                    y=0;
                }
                Zombie *zom = new Zombie(x,y);
                zombies.push_back(zom);
            }
            for (Zombie *zombie : zombies){
                zombie->draw();
            }
            for (Bullet bullet : shots){
                bullet.draw();
            }
            // draw sidwalk
            sidewalk.draw();

            //writes man's hp in game
            glColor3f(1,1,1);
            glRasterPos2i(50,470);
            for (char &letter : hp){
                glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, letter);
            }
            // writes the number of zombies on the screen currently
            glColor3f(1,1,1);
            glRasterPos2i(730,470);
            for (char &letter : "Zombies: "+to_string(zombieCap)){
                glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, letter);
            }
            //writes the number of zombies player has killed on the screen
            glColor3f(1,1,1);
            glRasterPos2i(190,470);
            for (char &letter : "Kills: "+to_string(killCount)){
                glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, letter);
            }

            // if nade is avaible for player to use, writes it on the screen
            if(nadeRegen>=50) {
                glColor3f(1, 0, 0);
                glRasterPos2i(400, 470);
                string nadeReady = "NADE READY";
                for (char &letter : nadeReady) {
                    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, letter);
                }
            }
            //draws the grenade animation depending on location of the man
            if(splodeTime>=0 and splodeTime<=.9) {
                splodeAnimate1 = Circle({1.0, 1.0, 0.0}, {man.getCenterX(), man.getCenterY()}, 30);
                splodeAnimate1.draw();
            }
            if(splodeTime>=.9 and splodeTime<=1.8) {
                splodeAnimate2 = Circle({1.0, 0.7, 0.0}, {man.getCenterX(), man.getCenterY()}, 60);
                splodeAnimate2.draw();
            }
            if(splodeTime>=1.8 and splodeTime<=2.7) {
                splodeAnimate3 = Circle({1.0, 0.0, 0.0}, {man.getCenterX(), man.getCenterY()}, 100);
                splodeAnimate3.draw();
            }

            break;
        case results:
            // writes results title

            for (Zombie *zombie : zombies){
                zombie->draw();
            }

            glColor3f(1,1,1);
            glRasterPos2i(350,100);
            for (char &letter : message1){
                glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, letter);
            }
            //write player's score
            glColor3f(1,1,1);
            glRasterPos2i(350,150);
            for (char &letter : killCountString){
                glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, letter);
            }
            quit.draw();
            break;
        case instructions:

            //All these messages write the title and paragraph of instructions for the game
            glColor3f(1,1,1);
            glRasterPos2i(350,100);
            for (char &letter : message2){
                glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, letter);
            }
            glColor3f(1, 1, 1);
            glRasterPos2i(275, 150);
            for (char &letter : message3) {
                glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, letter);
            }
            glColor3f(1, 1, 1);
            glRasterPos2i(275, 170);
            for (char &letter : message4) {
                glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, letter);
            }
            glColor3f(1, 1, 1);
            glRasterPos2i(275, 190);
            for (char &letter : message5) {
                glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, letter);
            }
            glColor3f(1, 1, 1);
            glRasterPos2i(275, 210);
            for (char &letter : message6) {
                glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, letter);
            }
            glColor3f(1, 1, 1);
            glRasterPos2i(275, 230);
            for (char &letter : message7) {
                glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, letter);
            }
            //draws the back to main button
            backMain.draw();
    }
    // Call helper functions depending on the screen we want to display


    glFlush();  // Render now
}

// http://www.theasciicode.com.ar/ascii-control-characters/escape-ascii-code-27.html
void kbd(unsigned char key, int x, int y)
{
    //escape key exits window
    if (key == 27) {
        //deleting c style pointers
        for (Zombie* zom: zombies){
            delete zom;
        }
        glutDestroyWindow(wd);
        exit(0);
    }
    // use g for grenade
    if(key==103){
        //logic for grenade
        if(nadeRegen>=50) {    // if grenade is available
            splode=true;      // if explosion happened
            splodeTime=0;    // start explosion time to zero

            //if zombies are in radius of explosion kill them
            for (Zombie *zom: zombies) {
                double distX = man.getCenterX() - zom->getCenterX();
                double distY = man.getCenterY() - zom->getCenterY();

                double distX2 = distX * distX;
                double distY2 = distY * distY;

                double dist = sqrt(distX2 + distY2);

                if (dist < 100) {
                    zombies.erase(std::remove(zombies.begin(), zombies.end(), zom), zombies.end());
                    killCount++;
                }

            }
            nadeRegen=0;
        }
    }

    //s to pause
    if(key==115){
        curr=start;
    }

    //f to shoot
    if(key==102){
        point p = man.getBarrelCoords();
        Bullet shot(p);
        shots.push_back(shot);
    }

    glutPostRedisplay();
}

void kbdS(int key, int x, int y) {
    switch(key) {

        // movement controls for the man with arrow keys
        case GLUT_KEY_DOWN:

            if(man.getVelocityY()<3){
                man.setVelocityY(man.getVelocityY()+3);
            }
            break;

        case GLUT_KEY_LEFT:
            man.turnLeft();

            if(man.getVelocityX()>-3){
                man.setVelocityX(man.getVelocityX()-3);
            }

            break;

        case GLUT_KEY_RIGHT:
            man.turnRight();

            if(man.getVelocityX()<3) {
                man.setVelocityX(man.getVelocityX() + 3);
            }
            break;

        case GLUT_KEY_UP:

            if(man.getVelocityY()>-3) {
                man.setVelocityY(man.getVelocityY() - 3);
            }

            break;
    }

    glutPostRedisplay();
}

void cursor(int x, int y) {

    glutPostRedisplay();
}

// button will be GLUT_LEFT_BUTTON or GLUT_RIGHT_BUTTON
// state will be GLUT_UP or GLUT_DOWN
void mouse(int button, int state, int x, int y) {
    //declaring necessary strings and buttons
    string message = "Zombie Survival";
    string message1 = "Results";
    string message2 = "Instructions";
    Rect playRec({0.5,0.8,0.5},{450,150},150,40);
    Button play(playRec,"Play");

    Rect instructRec({0.5,0.8,0.5},{450,220},150,40);
    Button instructBut(instructRec,"Instructions");
    Rect backMainRec({0.5,0.8,0.5},{450,400},150,40);
    Button backMain(backMainRec,"Back to Main");
    Rect quitRec({0.5,0.8,0.5},{450,270},150,40);
    Button quit(quitRec,"Quit");

    //play button on click goes to game
    if (state == GLUT_DOWN &&
        button == GLUT_LEFT_BUTTON &&
        play.isOverlapping(x, y) && curr==start) {
        play.pressDown();
        curr=game;

    }
    else{
        play.release();
    }

    // quit button will quit the game
    if (state == GLUT_DOWN &&
        button == GLUT_LEFT_BUTTON &&
        quit.isOverlapping(x, y) && curr==results) {
        quit.pressDown();
        for (Zombie* zom: zombies){
            delete zom;
        }
        glutDestroyWindow(wd);
        exit(0);
    }
    else{
        quit.release();
    }
    // instruction button will take user to instruction page
    if (state == GLUT_DOWN &&
        button == GLUT_LEFT_BUTTON &&
        instructBut.isOverlapping(x, y) && curr==start) {
        instructBut.pressDown();
        curr=instructions;
    }
    else{
        instructBut.release();
    }
    // back to main menu will take user from instruction back to main menu
    if (state == GLUT_DOWN &&
        button == GLUT_LEFT_BUTTON &&
        backMain.isOverlapping(x, y) && curr==instructions) {
        backMain.pressDown();
        curr=start;

    }
    else{
        backMain.release();
    }
}
void timer(int dummy) {
    switch(curr){

        case start:
            //menu animation timer for movement
            menuZom1.chase(menuMans.getCenter());
            menuZom2.chase(menuMans.getCenter());

            menuZom3.chase(menuMans.getCenter());
            menuZom4.chase(menuMans.getCenter());

            // keeps menu zombies confined to certain distances
            if(menuMans.getCenterY()==50 and menuMans.getCenterX()<799){
                menuMans.move(3,0);
                menuMans.turnRight();
            }
            else if(menuMans.getCenterY()<398 and menuMans.getCenterX()==799){
                menuMans.move(0,3);
            }
            else if(menuMans.getCenterY()==398 and menuMans.getCenterX()>100){
                menuMans.move(-3,0);
                menuMans.turnLeft();
            }
            else if(menuMans.getCenterY()>50 and menuMans.getCenterX()==100){
                menuMans.move(0,-3);
            }



            break;
        case game:
            // checks hp packs collision
            for(HealthBuff *healthBuff: buffs){
                checkCollisionH(healthBuff);
            }

            // ends game if mans health is less than zero
            if (man.getHealth() < 0){
                curr = results;
            }

            //zombies collision
            for (Zombie* zom: zombies){
                checkCollisionZ(zom);
            }

            //bullet movement and collision
            for (Bullet &bullet : shots) {
                if (bullet.getLocation().x == man.getBarrelCoords().x) {
                    if (man.isFacingRight()) {
                        bullet.setVelocity(10);
                    } else {
                        bullet.setVelocity(-10);
                    }
                    bullet.move(bullet.getVelocity());
                }else{
                    bullet.move(bullet.getVelocity());
                }
                checkCollisionB(bullet);
            }

            //character movement
            if(man.getCenterY()>= 275 && man.getCenterY()<=425){
                man.move(0,man.getVelocityY());
            }
            else if(man.getCenterY()<=275){
                if(man.getVelocityY()>=0){
                    man.move(0,man.getVelocityY());
                }
            }
            else if(man.getCenterY()>=425){
                if(man.getVelocityY()<=0){
                    man.move(0,man.getVelocityY());
                }
            }
            if(man.getCenterX()>= 400 && man.getCenterX()<=500){
                man.move(man.getVelocityX(),0);
            }
            else if(man.getCenterX()<=400){
                if(man.getVelocityX()>=0){
                    man.move(man.getVelocityX(),0);
                }
                else if(man.getVelocityX()<=0){
                    for (Zombie *zom: zombies) {
                        zom->move(3,0);
                    }
                    background.moveRight();
                    for(HealthBuff *buff:buffs){
                        buff->move(3, 0);
                    }
                }
            }
            else if(man.getCenterX()>=500){
                if(man.getVelocityX()<=0){
                    man.move(man.getVelocityX(),0);
                }
                else if(man.getVelocityX()>=0){
                    for (Zombie *zom: zombies) {
                        zom->move(-3,0);
                    }
                    background.moveLeft();
                    for(HealthBuff *buff:buffs){
                        buff->move(-3, 0);
                    }

                }
            }
            //zombie movement
            for (Zombie *zom: zombies) {
                zom->chase(man.getCenter());
            }

            //turning left or right depending on man's location
            for (Zombie *zom: zombies) {
                if(zom->getCenterX()>man.getCenterX()){
                    zom->turnLeft();
                }
                else if (zom->getCenterX()<man.getCenterX()){
                    zom->turnRight();
                }
            }
            // zombie's velocity logic
            for (Zombie *zom: zombies) {
                if(zombieCap>10 and zombieCap <20){
                    zom->setSpeed(1.8);
                }
                else if(zombieCap>20 and zombieCap <30){
                    zom->setSpeed(2.1);
                }
                else if(zombieCap>30){
                    zom->setSpeed(2.5);
                }

            }




            break;
        case results:

            if(zombieTime<20){
                for (Zombie *zombie : zombies){
                    zombie->move(1,0);
                    zombie->turnRight();
                }
                zombieTime+=1;
            }
            else if(zombieTime>=20 and zombieTime<40){
                for (Zombie *zombie : zombies){
                    zombie->move(-1,0);
                    zombie->turnLeft();

                }
                zombieTime+=1;
            }
            else if(zombieTime==40){
                zombieTime=0;
            }


            break;
        case instructions:
            break;

    }

    // grenade and explosion refresh rates
    nadeRegen+=.3;
    splodeTime+=.3;

    glutPostRedisplay();
    glutTimerFunc(30, timer, dummy);
}

// timer for zombie
void zombieTimer(int t){
    if(curr==game){
        zombieCap++;
    }


    glutPostRedisplay();
    glutTimerFunc(2500, zombieTimer, t);
}

// health pack timer
void HBuffTimer(int t){
    if(zombieCap > 10){
        buffCap++;
    }

    glutPostRedisplay();
    glutTimerFunc(6250, HBuffTimer, t);
}

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {

    init();

    // Initialize GLUT
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_RGBA);

    glutInitWindowSize((int)width, (int)height);

    // Position the window's initial top-left corner
    /* create the window and store the handle to it */
    glutInitWindowPosition(-200,-100);

    wd = glutCreateWindow("DARKWHITE" /* title */ );

    // Register callback handler for window re-paint event
    glutDisplayFunc(display);

    // Our own OpenGL initialization
    initGL();

    // register keyboard press event processing function
    // works for numbers, letters, spacebar, etc.

    glutKeyboardFunc(kbd);

    // register special event: function keys, arrows, etc.
    glutSpecialFunc(kbdS);

    // handles mouse movement
    glutPassiveMotionFunc(cursor);

    // handles mouse click
    glutMouseFunc(mouse);

    // handles timer
    glutTimerFunc(0, timer, 0);
    glutTimerFunc(0, zombieTimer, 0);
    glutTimerFunc(0,HBuffTimer, 0);

    // Enter the event-processing loop
    glutMainLoop();

    return 0;
}

// implementation of collision methods
void checkCollisionB(Bullet &bullet){
    for (Zombie *zom: zombies){
        if (bullet.getLocation().x > zom->getLeftX() && bullet.getLocation().x < zom->getRightX()){
            if (bullet.getLocation().y < zom->getBottomY() && bullet.getLocation().y > zom->getTopY()){
                //if bullet hits zom
                zombies.erase(std::remove(zombies.begin(), zombies.end(), zom), zombies.end());
                killCount++;
            }
        }
    }
}
void checkCollisionZ(Zombie* zom){
    if (zom->getCenterX()<=man.getCenterX()+8 and zom->getCenterX()>man.getCenterX()-8){
        if (zom->getCenterY()<=man.getCenterY()+8 and zom->getCenterY()>man.getCenterY()-8){
            man.setHealth(man.getHealth()-1);
            cout << man.getHealth() << endl;
        }

    }
}

void checkCollisionH(HealthBuff* healthBuff){
    if (man.getCenterX() > healthBuff->getLeftX()  && man.getCenterX() < healthBuff->getRightX() ){
        if (man.getCenterY() < healthBuff->getBottomY()  && man.getCenterY() > healthBuff->getTopY() ){
            man.setHealth(man.getHealth()+20);
            buffs.erase(std::remove(buffs.begin(), buffs.end(), healthBuff), buffs.end());
        }

    }

    if (man.getLeftX() > healthBuff->getLeftX()  && man.getLeftX() < healthBuff->getRightX() ){
        if (man.getCenterY() < healthBuff->getBottomY()  && man.getCenterY() > healthBuff->getTopY() ){
            man.setHealth(man.getHealth()+20);
            buffs.erase(std::remove(buffs.begin(), buffs.end(), healthBuff), buffs.end());
        }

    }

    if (man.getRightX() > healthBuff->getLeftX()  && man.getRightX() < healthBuff->getRightX() ){
        if (man.getCenterY() < healthBuff->getBottomY()  && man.getCenterY() > healthBuff->getTopY() ){
            man.setHealth(man.getHealth()+20);
            buffs.erase(std::remove(buffs.begin(), buffs.end(), healthBuff), buffs.end());
        }

    }

    if (man.getCenterX() > healthBuff->getLeftX()  && man.getCenterX() < healthBuff->getRightX() ){
        if (man.getCenterY() - 17 < healthBuff->getBottomY()  && man.getCenterY()-17  > healthBuff->getTopY() ){
            man.setHealth(man.getHealth()+20);
            buffs.erase(std::remove(buffs.begin(), buffs.end(), healthBuff), buffs.end());
        }

    }

    if (man.getCenterX() > healthBuff->getLeftX()  && man.getCenterX() < healthBuff->getRightX() ){
        if (man.getCenterY() + 18 < healthBuff->getBottomY()  && man.getCenterY()+18  > healthBuff->getTopY() ){
            man.setHealth(man.getHealth()+20);
            buffs.erase(std::remove(buffs.begin(), buffs.end(), healthBuff), buffs.end());
        }

    }
}

int randNum(int min, int max)
{
    return rand() % max + min;
}
//
//  main.cpp
//  COMP330-Assignment1
//
//  Created by Evan Hollins on 3/14/18.
//  Copyright © 2018 Evan Hollins. All rights reserved.
//

#include "main.h"

struct Globals {
    int mouse_x = -1;
    int mouse_y = -1;
    bool releasingWater = false;
} globals;

void init(void)   /* initialization function  */
{
    // Enable blending
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
    background = new Color(BACKGROUND_R,
                           BACKGROUND_G,
                           BACKGROUND_B,
                           BACKGROUND_A);
    helicopter = new Helicopter(WINDOW_SIZE_X/2,
                                WINDOW_SIZE_Y/2,
                                HELICOPTER_SIZE);
    
    lake = new Lake(WINDOW_SIZE_X - WINDOW_SIZE_X / 10,
                    WINDOW_SIZE_Y - WINDOW_SIZE_Y / 10,
                    40,
                    new Color(0.44, 0.63, 0.93));
    waterBar = new WaterBar(WINDOW_SIZE_X - WINDOW_SIZE_X / 10,
                            WINDOW_SIZE_Y / 20,
                            90,
                            20,
                            new Color(0.44, 0.63, 0.93));
    
    glClearColor(background->getR(),
                 background->getG(),
                 background->getB(),
                 background->getA()); /* set background color */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, WINDOW_SIZE_X, WINDOW_SIZE_Y, 0); /* defines world window */
}

void update(int v) {
    // If mouse is in screen
    if(globals.mouse_x > 0 && globals.mouse_y > 0) {
        
        helicopter->setTargetAngle(deg(atan2(globals.mouse_y - helicopter->getY(),
                                             globals.mouse_x - helicopter->getX())));
        
        helicopter->setSpeed(sqrt(pow(globals.mouse_y - helicopter->getY(), 2.0) +
                                  pow(globals.mouse_x - helicopter->getX(), 2.0)));
        helicopter->setTargetX(globals.mouse_x);
        helicopter->setTargetY(globals.mouse_y);
        
        if(lake->contains(helicopter->getX(), helicopter->getY())) {
            waterBar->increaseFilled(WATER_FILL_RATE);
        } else {
            if(globals.releasingWater && !waterBar->isEmpty()) {
                waterBar->decreaseFilled(WATER_RELEASE_RATE);
            }
        }
        
    } else {
        helicopter->setSpeed(0);
    }
    helicopter->update();
    
    glutPostRedisplay();
    glutTimerFunc(MILLISECONDS_PER_SECOND / FRAMERATE, update, 0);
}

void displayCB(void) /* display callback function,
                      called for initial display and
                      whenever redisplay needed */
{
    glClear( GL_COLOR_BUFFER_BIT); /* clear the screen window */
    glClearColor(background->getR(),
                 background->getG(),
                 background->getB(),
                 background->getA()); /* set background color */
    lake->draw();
    waterBar->draw();
    helicopter->draw();
    glutSwapBuffers();
}
/* keyboard callback function,
 called on key press */
void keyCB(unsigned char key, int x, int y) {
    switch (key) {
        case 'q':
            exit(0);
            break;
        case ' ':
            globals.releasingWater = true;
            break;
        default:
            break;
    }
}

void keyUp(unsigned char key, int x, int y) {
    switch (key) {
        case ' ':
            globals.releasingWater = false;
            break;
            
        default:
            break;
    }
}

void mouse(int x, int y) {
    // If mouse is out of screen, set to be negative.
    if(WINDOW_SIZE_X - x >= 0 && WINDOW_SIZE_Y - y >= 0) {
        globals.mouse_x = x;
        globals.mouse_y = y;
    } else {
        globals.mouse_x = -1;
        globals.mouse_y = -1;
    }
}

int main(int argc, char *argv[]) {
    glutInit(&argc, argv); /* initialize GLUT system */
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(WINDOW_SIZE_X, WINDOW_SIZE_Y);
    glutCreateWindow("COMP330 Assignment 1"); /* create screen window */
    glutDisplayFunc(displayCB); /* register display callback function*/
    glutKeyboardFunc(keyCB); /* register keyboard callback function*/
    glutKeyboardUpFunc(keyUp);
    glutPassiveMotionFunc(mouse);
    glutMotionFunc(mouse);
    glutTimerFunc(0, update, 0);     // First timer call immediately
    init();      /* call init */
    glutMainLoop(); /* show screen window, call display and
                     start processing events... */
    /* execution never reaches this point */
    return 0;
}

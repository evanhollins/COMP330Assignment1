//
//  main.cpp
//  COMP330-Assignment1
//
//  Created by Evan Hollins on 3/14/18.
//  Copyright © 2018 Evan Hollins. All rights reserved.
//

#include "main.h"

struct Globals {
    int mouse_x;
    int mouse_y;
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
    
    glClearColor(background->getR(),
                 background->getG(),
                 background->getB(),
                 background->getA()); /* set background color */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, WINDOW_SIZE_X, 0, WINDOW_SIZE_Y); /* defines world window */
}

void update(int v) {
    helicopter->setAngle(-atan2(globals.mouse_y - helicopter->getY(),
                                globals.mouse_x - helicopter->getX())
                         * 180 / M_PI);
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
    helicopter->draw();
    glutSwapBuffers();
}

void keyCB(unsigned char key, int x, int y) /* keyboard callback function,
                                             called on key press */
{
    if (key == 'q') {
        exit(0);
    }
    
}

void mouse(int x, int y) {
    globals.mouse_x = x;
    globals.mouse_y = y;
}

int main(int argc, char *argv[]) {
    glutInit(&argc, argv); /* initialize GLUT system */
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(WINDOW_SIZE_X, WINDOW_SIZE_Y);
    glutCreateWindow("COMP330 Assignment 1"); /* create screen window */
    glutDisplayFunc(displayCB); /* register display callback function*/
    glutKeyboardFunc(keyCB); /* register keyboard callback function*/
    glutPassiveMotionFunc(mouse);
    glutMotionFunc(mouse);
    glutTimerFunc(0, update, 0);     // First timer call immediately
    init();      /* call init */
    glutMainLoop(); /* show screen window, call display and
                     start processing events... */
    /* execution never reaches this point */
    return 0;
}

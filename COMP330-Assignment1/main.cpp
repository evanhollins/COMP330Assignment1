//
//  main.cpp
//  COMP330-Assignment1
//
//  Created by Evan Hollins on 3/14/18.
//  Copyright © 2018 Evan Hollins. All rights reserved.
//

#include "main.h"

void init(void)   /* initialization function  */
{
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
    glColor3f(1.0, 1.0, 1.0); /* set drawing color to white */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 400, 0, 500); /* defines world window */
}

void displayCB(void) /* display callback function,
                      called for initial display and
                      whenever redisplay needed */
{
    glClear( GL_COLOR_BUFFER_BIT); /* clear the screen window */
    helicopter->draw();
    glFlush(); /* Complete any pending operations */
}

void keyCB(unsigned char key, int x, int y) /* keyboard callback function,
                                             called on key press */
{
    if (key == 'q')
        exit(0);
}

int main(int argc, char *argv[]) {
    glutInit(&argc, argv); /* initialize GLUT system */
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(WINDOW_SIZE_X, WINDOW_SIZE_Y);
    glutCreateWindow("COMP330 Assignment 1"); /* create screen window */
    glutDisplayFunc(displayCB); /* register display callback function*/
    glutKeyboardFunc(keyCB); /* register keyboard callback function*/
    init();      /* call init */
    glutMainLoop(); /* show screen window, call display and
                     start processing events... */
    /* execution never reaches this point */
    return 0;
}

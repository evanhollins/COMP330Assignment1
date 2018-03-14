//
//  main.cpp
//  COMP330-Assignment1
//
//  Created by Evan Hollins on 3/14/18.
//  Copyright © 2018 Evan Hollins. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <GLUT/GLUT.h>
using namespace std;

#include "main.h"
#include "Color.h"

struct Globals {
    Color background;
} globals;

void init(void)   /* initialization function  */
{
    globals.background.setR(BACKGROUND_R);
    globals.background.setG(BACKGROUND_G);
    globals.background.setB(BACKGROUND_B);
    globals.background.setA(BACKGROUND_A);
    
    glClearColor(globals.background.getR(), globals.background.getG(), globals.background.getB(), globals.background.getA()); /* set background color */
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
    glutInitWindowSize(400, 500); /* width=400pixels height=500pixels */
    glutCreateWindow("Triangle"); /* create screen window */
    glutDisplayFunc(displayCB); /* register display callback function*/
    glutKeyboardFunc(keyCB); /* register keyboard callback function*/
    init();      /* call init */
    glutMainLoop(); /* show screen window, call display and
                     start processing events... */
    /* execution never reaches this point */
    return 0;
}

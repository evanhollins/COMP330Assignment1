//
//  main.cpp
//  COMP330-Assignment1
//
//  Created by Evan Hollins on 3/14/18.
//  Copyright © 2018 Evan Hollins. All rights reserved.
//

#include "main.h"

struct Globals {
    int mouseX = -1;
    int mouseY = -1;
    int mouseDownX = -1;
    int mouseDownY = -1;
    bool draggingMouse = false;
    bool draggingMouseStartedInHelicopter = false;
    bool helicopterFlying = true;
    bool releasingWater = false;
    bool running = true;
} globals;

enum MENU {
    EXIT,
    RESET
};

void init(void)   /* initialization function  */
{
    // Enable blending
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
    background = new Color(BACKGROUND_R,
                           BACKGROUND_G,
                           BACKGROUND_B,
                           BACKGROUND_A);
    
    map = new Map(WINDOW_SIZE_X, WINDOW_SIZE_Y);
    
    helicopter = new Helicopter(WINDOW_SIZE_X/2,
                                WINDOW_SIZE_Y/2,
                                HELICOPTER_SIZE);
    
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
    if(!globals.running) {
        return;
    }
    
    if(!globals.helicopterFlying) {
        helicopter->land();
    } else if(globals.draggingMouse &&
       globals.draggingMouseStartedInHelicopter) {
        helicopter->takeoff();
        
        helicopter->setTargetAngle(deg(atan2(globals.mouseY - helicopter->getY(),
                                             globals.mouseX - helicopter->getX())));
        
        helicopter->setSpeed(sqrt(pow(globals.mouseY - helicopter->getY(), 2.0) +
                                  pow(globals.mouseX - helicopter->getX(), 2.0)));
        helicopter->setTargetX(globals.mouseX);
        helicopter->setTargetY(globals.mouseY);
    }
    
    if(map->inLake(helicopter->getX(), helicopter->getY())) {
        waterBar->increaseFilled(WATER_FILL_RATE);
    } else {
        if(globals.releasingWater && !waterBar->isEmpty()) {
            waterBar->decreaseFilled(WATER_RELEASE_RATE);
        }
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
    map->draw();
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

void menuCB(int menu) {
    switch (menu) {
        case EXIT:
            exit(0);
            break;
        case RESET:
            cout << "reset" << endl;
            
        default:
            break;
    }
    globals.running = true;
}

void mouseMotion(int x, int y) {
    if(globals.mouseDownX >= 0 && globals.mouseDownY >= 0) {
        if(sqrt(
                pow(globals.mouseDownX - x, 2) + pow(globals.mouseDownY - y, 2))
           > MOUSE_CLICK_DEADBAND) {
            globals.draggingMouse = true;
            if(helicopter->contains(globals.mouseDownX, globals.mouseDownY)) {
                globals.draggingMouseStartedInHelicopter = true;
            }
        }
    }
    globals.mouseX = x;
    globals.mouseY = y;
}

void mousePassiveMotion(int x, int y) {
    // If mouse is out of screen, set to be negative.
    if(WINDOW_SIZE_X - x >= 0 && WINDOW_SIZE_Y - y >= 0 && x >= 0 && y >= 0) {
        globals.mouseX = x;
        globals.mouseY = y;
    } else {
        globals.mouseX = -1;
        globals.mouseY = -1;
    }
}

void handleClick(int x, int y) {
    if(map->inBase(x, y) && map->inBase(helicopter->getX(),
                                              helicopter->getY())) {
        globals.helicopterFlying = !globals.helicopterFlying;
    }
}

void mouseClicked(int button, int state, int x, int y) {
    switch (button) {
        case GLUT_RIGHT_BUTTON:
            cout << "right button" << endl;
            break;
        case GLUT_LEFT_BUTTON:
            if(state == GLUT_DOWN) {
                globals.mouseDownX = x;
                globals.mouseDownY = y;
            } else if(state == GLUT_UP) {
                if(!globals.draggingMouse) {
                    handleClick(x, y);
                }
                globals.mouseDownX = -1;
                globals.mouseDownY = -1;
                globals.draggingMouse = false;
                globals.draggingMouseStartedInHelicopter = false;
            }
            break;
            
        default:
            break;
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
    glutPassiveMotionFunc(mousePassiveMotion);
    glutMotionFunc(mouseMotion);
    glutMouseFunc(mouseClicked);
    
    // Right Click Menu
    glutCreateMenu(menuCB);
    glutAddMenuEntry("Exit", EXIT);
    glutAddMenuEntry("Reset", RESET);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    
    glutTimerFunc(0, update, 0);     // First timer call immediately
    init();      /* call init */
    glutMainLoop(); /* show screen window, call display and
                     start processing events... */
    /* execution never reaches this point */
    return 0;
}

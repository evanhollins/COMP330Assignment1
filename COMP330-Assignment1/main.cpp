//
//  main.cpp
//  COMP330-Assignment1
//
//  Created by Evan Hollins on 3/14/18.
//  Copyright © 2018 Evan Hollins. All rights reserved.
//

#include "main.h"

struct Globals {
    int windowX = WINDOW_SIZE_X;
    int windowY = WINDOW_SIZE_Y;
    int mouseX = -1;
    int mouseY = -1;
    int mouseDownX = -1;
    int mouseDownY = -1;
    bool draggingMouse = false;
    bool draggingMouseStartedInHelicopter = false;
    bool helicopterFlying = true;
    bool releasingWater = false;
    bool fillingWater = false;
    bool running = true;
} globals;

enum MENU {
    EXIT,
    RESET,
    PAUSE,
    RESUME
};

void init(void)   /* initialization function  */
{
    srand((unsigned int) time(NULL));
    
    // Enable blending
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
    map = new Map(globals.windowX, globals.windowY);
    
    helicopter = new Helicopter(globals.windowX/2,
                                globals.windowY/2,
                                HELICOPTER_SIZE);
    
    waterBar = new Bar(globals.windowX + WATERBAR_X,
                            WATERBAR_Y,
                            WATERBAR_SIZE_X,
                            WATERBAR_SIZE_Y, Color::WATER, "Water");

    fuelBar = new Bar(globals.windowX + FUELBAR_X,
                       FUELBAR_Y,
                       FUELBAR_SIZE_X,
                       FUELBAR_SIZE_Y, Color::FUEL, "Fuel");
    fuelBar->setFilled(1.0);
}

void reset() {
    delete map;
    delete helicopter;
    delete waterBar;
    delete fuelBar;
    init();
}

void update(int v) {
    if(globals.running) {
        
        if(fuelBar->isEmpty()) {
            helicopter->land();
            globals.helicopterFlying = false;
        } else if(globals.draggingMouse &&
           globals.draggingMouseStartedInHelicopter) {
            globals.helicopterFlying = true;
            helicopter->takeoff();
            helicopter->setTargetX(globals.mouseX);
            helicopter->setTargetY(globals.mouseY);
        }
        
        if(!globals.helicopterFlying) {
            helicopter->setTargetX(helicopter->getX());
            helicopter->setTargetY(helicopter->getY());
            helicopter->land();
        }
        
        if(globals.fillingWater) {
            if(map->inLake(helicopter->getX(), helicopter->getY())) {
                waterBar->increaseFilled(WATER_FILL_RATE);
            } else {
                globals.fillingWater = false;
            }
        } else if(globals.releasingWater) {
            waterBar->decreaseFilled(WATER_RELEASE_RATE);
            helicopter->dropWater();
            map->water(helicopter->getX(), helicopter->getY());
            globals.releasingWater = false;
        }
        
        if(map->inBase(helicopter->getX(), helicopter->getY()) && !globals.helicopterFlying) {
            fuelBar->increaseFilled(FUEL_FILL_RATE);
        } else {
            fuelBar->decreaseFilled(FUEL_RELEASE_RATE);
        }
        
        helicopter->update();
        map->update();
        
        glutPostRedisplay();
    }
    
    
    glutTimerFunc(MILLISECONDS_PER_SECOND / FRAMERATE, update, 0);
}

void displayCB(void) /* display callback function,
                      called for initial display and
                      whenever redisplay needed */
{
    glClear( GL_COLOR_BUFFER_BIT); /* clear the screen  window */
    glClearColor(background.r,
                 background.g,
                 background.b,
                 background.a); /* set background color */
    map->draw();
    waterBar->draw();
    fuelBar->draw();
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
        case 'p':
            globals.running = false;
            break;
        case 'r':
            globals.running = true;
            break;
        case 'w':
            reset();
            break;
        case ' ':
            break;
        default:
            break;
    }
}

void keyUp(unsigned char key, int x, int y) {
    switch (key) {
        case ' ':
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
            reset();
        case PAUSE:
            globals.running = false;
            break;
        case RESUME:
            globals.running = true;
            break;
        default:
            break;
    }
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
    if(globals.windowX - x >= 0 && globals.windowY - y >= 0 && x >= 0 && y >= 0) {
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
        globals.helicopterFlying = false;
    } else if(helicopter->contains(x, y) && map->inLake(helicopter->getX(), helicopter->getY())) {
        globals.fillingWater = true;
    } else if(helicopter->contains(x, y) && !waterBar->isEmpty()) {
        globals.releasingWater = true;
    }
}

void handleReshape(int x, int y) {
    if(x < WINDOW_MIN_SIZE_X || y < WINDOW_MIN_SIZE_Y) {
        glutReshapeWindow(max(x, WINDOW_MIN_SIZE_X), max(y, WINDOW_MIN_SIZE_Y));
        return;
    }
    
    globals.windowX = x;
    globals.windowY = y;
    glClearColor(background.r,
                 background.g,
                 background.b,
                 background.a); /* set background color */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0,0, x, y);
    gluOrtho2D(0, globals.windowX, globals.windowY, 0); /* defines world window */
    
    map->changeSize(x, y);
    fuelBar->update(globals.windowX + FUELBAR_X, FUELBAR_Y);
    waterBar->update(globals.windowX + WATERBAR_X, WATERBAR_Y);
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
    glutAddMenuEntry("Exit (q)", EXIT);
    glutAddMenuEntry("Reset (w)", RESET);
    glutAddMenuEntry("Pause (p)", PAUSE);
    glutAddMenuEntry("Resume (r)", RESUME);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    
    glutTimerFunc(0, update, 0);     // First timer call immediately
    init();      /* call init */
    glutReshapeFunc(handleReshape);
    glutMainLoop(); /* show screen window, call display and
                     start processing events... */
    /* execution never reaches this point */
    return 0;
}

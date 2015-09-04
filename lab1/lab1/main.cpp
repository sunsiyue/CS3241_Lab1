// CS3241Lab1.cpp : Defines the entry point for the console application.
#include <cmath>
#include <iostream>

/* header files for xcode */
#include <OpenGL/gl.h>
#include <GLUT/GLUT.h>

/* header files for lab machine */
//#include "GL\glut.h"

using namespace std;

GLfloat PI = 3.14;
float alpha = 0.0, k=1;
float tx = 0.0, ty=0.0;


void drawATriangle(void) {
    glBegin(GL_POLYGON);
        //glColor3f(1.0,0.0,0.0);
        glVertex2f(-1, -1);
        //glColor3f(0.0,1.0,0.0);
        glVertex2f(0, 1);
        //glColor3f(0.0,0.0,1.0);
        glVertex2f(1, -1);
    glEnd();
}

void drawAnotherTriangle(void) {
    glBegin(GL_POLYGON);
    //glColor3f(1.0,0.0,0.0);
    glVertex2f(1, -1);
    //glColor3f(0.0,1.0,0.0);
    glVertex2f(2, 1);
    //glColor3f(0.0,0.0,1.0);
    glVertex2f(3, -1);
    glEnd();
}

void drawLine(void) {
    glBegin(GL_LINE);
    glVertex2f(3, 3);
    glVertex2f(3, -3);
    glEnd();
}



void drawFork()
{

drawLine();
glPushMatrix();
glTranslatef(0,0.5,0);
glPushMatrix();
glRotatef(-45,0,0,1);
drawLine();
glPopMatrix();

glPushMatrix();
glPopMatrix();
glPopMatrix();
}

void display(void)
{
    glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
    
	glPushMatrix();
    
	//controls transformation
	glScalef(k, k, k);	
		
	glRotatef(alpha, 0, 0, 1);
	glTranslatef(tx, ty, 0);
	//draw your stuff here
    drawATriangle();
    glTranslatef(4,0,0);
    glScalef(2.0f, 2.0f, 0);
    
    drawATriangle();
    
    drawFork();
    
	glPopMatrix();
	glFlush ();
}





void reshape (int w, int h)
{
	glViewport (0, 0, (GLsizei) w, (GLsizei) h);
    
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
    
	glOrtho(-10, 10, -10, 10, -10, 10);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void init(void)
{
	glClearColor (1.0, 1.0, 1.0, 1.0);
	glShadeModel (GL_SMOOTH);
}



void keyboard (unsigned char key, int x, int y)
{
	//keys to control scaling - k
	//keys to control rotation - alpha
	//keys to control translation - tx, ty
	switch (key) {
            
		case 'a':
			alpha+=10;
			glutPostRedisplay();
            break;
            
		case 'd':
			alpha-=10;
			glutPostRedisplay();
            break;
            
		case 'q':
			k+=0.1;
			glutPostRedisplay();
            break;
            
		case 'e':
			if(k>0.1)
				k-=0.1;
			glutPostRedisplay();
            break;
            
		case 'z':
			tx-=0.1;
			glutPostRedisplay();
            break;
            
		case 'c':
			tx+=0.1;
			glutPostRedisplay();
            break;
            
		case 's':
			ty-=0.1;
			glutPostRedisplay();
            break;
            
		case 'w':
			ty+=0.1;
			glutPostRedisplay();
            break;
            
		default:
            break;
	}
}

int main(int argc, char **argv)
{
	cout<<"CS3241 Lab 1\n\n";
	cout<<"+++++CONTROL BUTTONS+++++++\n\n";
	cout<<"Scale Up/Down: Q/E\n";
	cout<<"Rotate Clockwise/Counter-clockwise: A/D\n";
	cout<<"Move Up/Down: W/S\n";
	cout<<"Move Left/Right: Z/C\n";
    
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize (600, 600);
	glutInitWindowPosition (50, 50);
	glutCreateWindow (argv[0]);
	init ();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	//glutMouseFunc(mouse);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
    
	return 0;
}

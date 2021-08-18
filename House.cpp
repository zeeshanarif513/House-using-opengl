// House.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include<GL/glut.h>
#include <iostream>

void myInit() {
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0, 0.0, 0.0);
	glPointSize(4.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 640.0, 0.0, 480.0);
	glClear(GL_COLOR_BUFFER_BIT);
}

void house(int xpeak,int ypeak,int width,int height) {
	glBegin(GL_LINE_STRIP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2i(xpeak, ypeak);
	glVertex2i(xpeak + (0.6*width), ypeak - (0.4*height));
	glVertex2i(xpeak + (0.6*width), ypeak - height);
	glVertex2i(xpeak - (0.4*width), ypeak - height);
	glVertex2i(xpeak - (0.4*width), ypeak - (0.4*height));
	glVertex2i(xpeak, ypeak);
	//chimni
	glVertex2i(xpeak - (0.15*width), ypeak - (0.15*height));
	glVertex2i(xpeak - (0.15*width), ypeak);
	glVertex2i(xpeak - (0.3*width), ypeak);
	glVertex2i(xpeak - (0.3*width), ypeak - (0.3*height));
	glEnd();
	glFlush();

	//door
	glBegin(GL_LINE_STRIP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2i(xpeak - (0.25*width), ypeak - height);
	glVertex2i(xpeak - (0.25*width), ypeak - height+(0.45*height));
	glVertex2i(xpeak + (0.05*width), ypeak - height + (0.45*height));
	glVertex2i(xpeak + (0.05*width), ypeak - height);
	glEnd();
	glFlush();

	//window
	glBegin(GL_LINE_STRIP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2i(xpeak + (0.15*width), ypeak - height + (0.4*height));
	glVertex2i(xpeak + (0.325*width), ypeak - height + (0.4*height));
	glVertex2i(xpeak + (0.325*width), ypeak - height + (0.575*height));
	glVertex2i(xpeak + (0.15*width), ypeak - height + (0.575*height));
	glVertex2i(xpeak + (0.15*width), ypeak - height + (0.4*height));
	glEnd();
	glFlush();
}
void myDisplay() {
	house(70, 120, 60, 80);
	house(170, 220, 130, 180);
	house(250, 430, 100, 100);
	house(450, 430, 200, 300);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(100, 50);
	glutCreateWindow("Dots in opengl");
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
}


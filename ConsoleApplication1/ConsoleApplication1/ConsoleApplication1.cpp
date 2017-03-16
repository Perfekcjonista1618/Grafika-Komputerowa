// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdafx.h"
#include <cmath>
#ifdef __APPLE__

#include <GLUT/glut.h>

#else

#include <GL/glut.h>

#endif

GLfloat x_1 = 100.0f;

GLfloat y_1 = 150.0f;

GLsizei rsize = 45;



GLfloat xstep = 0.4f;

GLfloat ystep = 0.4f;


GLfloat windowWidth;

GLfloat windowHeight;

void RenderScene(void) {

	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(1.0f, 1.0f, 1.0f);

	int triangleAmount = 5;
	GLfloat twicePi = 2.0f * 3.14;

	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(x_1, y_1);

	for (int i = 0; i <= triangleAmount; i++)
	{
		glVertex2f(
			x_1 + (10.0*sin(i*twicePi / triangleAmount)) * 5,
			y_1 + (10.0*cos(i*twicePi / triangleAmount)) * 5);
	}
	glEnd();
	glFlush();

	glutSwapBuffers();
}
void TimerFunction(int value) {

	if (x_1 > windowWidth - rsize || x_1 - rsize < 0)

		xstep = -xstep;


	if (y_1 > windowHeight - rsize || y_1 - rsize < 0)

		ystep = -ystep;


	if (x_1 > windowWidth - rsize)

		x_1 = windowWidth - rsize - 1;


	if (y_1 > windowHeight - rsize)

		y_1 = windowHeight - rsize - 1;


	x_1 += xstep * 10;

	y_1 += ystep * 10;

	glutPostRedisplay();

	glutTimerFunc(33, TimerFunction, 1);

}
void SetupRC(void) 
{

	glClearColor(0.25f, 0.0f, 1.0f, 1.0f);

}
void ChangeSize(GLsizei w, GLsizei h) {

	if (h == 0)
		h = 1;

	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();

	if (w <= h)

	{
		windowHeight = 250.0f*h / w;

		windowWidth = 250.0f;
	}

	else

	{
		windowWidth = 250.0f*w / h;

		windowHeight = 250.0f;
	}

	glOrtho(0.0f, windowWidth, 0.0f, windowHeight, 1.0f, -1.0f);

	glMatrixMode(GL_MODELVIEW);

	glLoadIdentity();
}
void main(int argc, char* argv[]) {

	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

	glutInitWindowSize(800, 600);

	glutCreateWindow("Bounce");

	glutDisplayFunc(RenderScene);

	glutReshapeFunc(ChangeSize);

	glutTimerFunc(33, TimerFunction, 1);

	SetupRC();

	glutMainLoop();

}
#include <GL\freeglut.h>
#include <math.h> 
#include <time.h>
#include <cstdlib>
#define PI 3.14159265

GLfloat ctrlpoints[4][3] = {
		{ -1, -1, 0.0}, { -0.5, 0.5, 0.0},
		{0, 0.7, 0.0}, {1, 0.5, 0.0} };

void display() {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
	glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 4, &ctrlpoints[0][0]);
	glEnable(GL_MAP1_VERTEX_3);
	int i;
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0, 1.0);
	glBegin(GL_LINE_STRIP);
	for (i = 0; i <= 30; i++)
		glEvalCoord1f((GLfloat)i / 30.0);
	glEnd();
	glPointSize(5.0);
	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_POINTS);
	for (i = 0; i < 4; i++)
		glVertex3fv(&ctrlpoints[i][0]);
	glEnd();
	glFlush();
}

int main(int argc, char * argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Ex 2.4.1");
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
#include<iostream>
#include<gl/GLUT.h>
#include"project.h"
#include"rotate.h"
#include"coord.h"
#include"reset.h"
using namespace std;

coord c[16]= {
	{50, 50, 50, 50},
	{-50, 50, 50, 50}, 
	{-50, -50, 50, 50}, 
	{50, -50, 50, 50}, 
	{50, 50, -50, 50}, 
	{-50, 50, -50, 50}, 
	{-50, -50, -50, 50}, 
	{50, -50, -50, 50}, 
	{50, 50, 50, -50}, 
	{-50, 50, 50, -50}, 
	{-50, -50, 50, -50}, 
	{50, -50, 50, -50}, 
	{50, 50, -50, -50}, 
	{-50, 50, -50, -50}, 
	{-50, -50, -50, -50}, 
	{50, -50, -50, -50}, 
};

double speed = 0.001;

void display(){
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );//I do as the sample code says
	
	if (speed > 0)
		rotate(c, speed);
	project(c);

	glutSwapBuffers();//I do as sample code commands
}

void kbin(unsigned char key, int x, int y){
	if(key == '\x1b')//esc key
		exit(0);
	else if(key == 'w')//w
		glRotatef(-1, 1, 0, 0);
	else if(key == 'a')//a
		glRotatef(-1, 0, 1, 0);
	else if(key == 's')//s
		glRotatef(1, 1, 0, 0);
	else if(key == 'd')//d
		glRotatef(1, 0, 1, 0);
	else if(key == 'q')//q
		glRotatef(1, 0, 0, 1);
	else if(key == 'e')//e
		glRotatef(-1, 0, 0, 1);
	else if(key == '0')//0
		speed = 0;
	else if(key == '1')//1
		speed = 0.0001;
	else if(key == '2')//2
		speed = 0.0005;
	else if(key == '3')//3
		speed = 0.001;
	else if(key == '4')//4
		speed = 0.003;
	else if(key == 'r')//r
		reset(c);
}

int main(int argc, char* argv[]){
	//initialize
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition ( 0, 0 ) ;
	glutInitWindowSize ( 675, 675 ) ;
	glutCreateWindow( "Tesseract" );
	glOrtho(-100, 100, -100, 100, 100, -100);
	glRotatef(45, -1, 1, 0);
	
	//functions
	glutDisplayFunc(display);
	glutKeyboardFunc(kbin);
	glutIdleFunc(display);

	//loop
	glutMainLoop();

	return 0;
}

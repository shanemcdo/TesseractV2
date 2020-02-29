#include<iostream>
#include<gl/GLUT.h>
#include"project.h"
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

void display(){
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );//I do as the sample code says
	
	glRotatef(0.01, 0, 1, 0);
	project(c);

	glutSwapBuffers();//I do as sample code commands
}

void kbin(unsigned char key, int x, int y){
	if(key == '\x1b')//esc key
		exit(0);
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

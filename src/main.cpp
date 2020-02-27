#include<iostream>
#include<gl/GLUT.h>
#include"coord.h"
using namespace std;

void display(){
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );//I do as the sample code says

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
	
	//functions
	glutDisplayFunc(display);
	glutKeyboardFunc(kbin);
	glutIdleFunc(display);

	//loop
	glutMainLoop();

	return 0;
}

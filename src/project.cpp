#include<gl/GLUT.h>
#include"project.h"
#include"coord.h"

void cube(coord p[8])
{
	for(int i = 0;i < 4; i++)
	{
		//first square
		glBegin(GL_LINES);
			glVertex3f(p[i].x, p[i].y, p[i].z);
			glVertex3f(p[(i+1)%4].x, p[(i+1)%4].y, p[(i+1)%4].z);
		glEnd();
		//second squre
		glBegin(GL_LINES);
			glVertex3f(p[i+4].x, p[i+4].y, p[i+4].z);
			glVertex3f(p[((i+1)%4)+4].x, p[((i+1)%4)+4].y, p[((i+1)%4)+4].z);
		glEnd();
		//connecting lines
		glBegin(GL_LINES);
			glVertex3f(p[i].x, p[i].y, p[i].z);
			glVertex3f(p[i+4].x, p[i+4].y, p[i+4].z);
		glEnd();
	}//for i
}//cube

void draw(coord p[16]){
	//color
	glColor3f(0.125, 0.698, 667);

	//print both cubes
	cube(p);
	cube(p+8);
	
	//print connecting lines
	for(int i = 0; i < 8; i++)
	{
		glBegin(GL_LINES);
			glVertex3f(p[i].x,p[i].y,p[i].z);
			glVertex3f(p[i+8].x,p[i+8].y,p[i+8].z);
		glEnd();
	}//for i
}

void project(coord p[16]){
	coord projected[16];
	for (int i = 0; i < 16; i++){
		double distance = 140;//keep this number > p[i].w or the lines wont connect properly
		double w = 75 / (distance - p[i].w);
		projected[i].x = p[i].x * w;
		projected[i].y = p[i].y * w;
		projected[i].z = p[i].z * w;
	}
	draw(projected);
	
}

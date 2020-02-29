#include<gl/GLUT.h>
#include"rotate.h"
#include"coord.h"
#include"math.h"

void rotateZW(coord c[], double angle){
	for(int i = 0; i < 16; i++){
		c[i].z = c[i].z * cos(angle) - c[i].w * sin(angle);
		c[i].w = c[i].z * sin(angle) + c[i].w * cos(angle);
	}
}

void rotateXY(coord c[], double angle){
	angle /= 2;
	for(int i = 0; i < 16; i++){
		c[i].x = c[i].x * cos(angle) + c[i].y * sin(angle);
		c[i].y = c[i].x * -sin(angle) + c[i].y * cos(angle);
	}
}

void rotate(coord c[], double angle){
	rotateZW(c, angle);
	rotateXY(c, angle);
}

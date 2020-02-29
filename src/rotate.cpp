#include<gl/GLUT.h>
#include"rotate.h"
#include"coord.h"
#include"math.h"

void rotate(coord c[]){
	double angle = 0.001;
	for(int i = 0; i < 16; i++){
		c[i].z = c[i].z * cos(angle) - c[i].w * sin(angle);
		c[i].w = c[i].w * sin(angle) + c[i].z * cos(angle);
	}
}

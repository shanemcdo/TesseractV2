#include<GL/glut.h>
#include"coord.h"
#include"reset.h"

void reset(coord c[]){
	c[0] = coord(50, 50, 50, 50);
	c[1] = coord(-50, 50, 50, 50);
	c[2] = coord(-50, -50, 50, 50);
	c[3] = coord(50, -50, 50, 50);
	c[4] = coord(50, 50, -50, 50);
	c[5] = coord(-50, 50, -50, 50);
	c[6] = coord(-50, -50, -50, 50);
	c[7] = coord(50, -50, -50, 50);
	c[8] = coord(50, 50, 50, -50);
	c[9] = coord(-50, 50, 50, -50);
	c[10] = coord(-50, -50, 50, -50);
	c[11] = coord(50, -50, 50, -50);
	c[12] = coord(50, 50, -50, -50);
	c[13] = coord(-50, 50, -50, -50);
	c[14] = coord(-50, -50, -50, -50);
	c[15] = coord(50, -50, -50, -50);
}

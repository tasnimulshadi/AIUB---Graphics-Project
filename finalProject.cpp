#include<windows.h>
#include<math.h>
#include<cstdio>
#include <GL/gl.h>
#include <GL/glut.h>
#define PI 3.14


GLfloat positionBus = 0.0f;
GLfloat speedBus = 0.03f;

GLfloat positionSun = 0.0f;
GLfloat speedSun = 0.002f;

GLfloat positionCloud = 0.0f;
GLfloat speedCloud = 0.005f;

GLfloat positionBoat1 = 0.0f;
GLfloat speedBoat1 = 0.01f;

GLfloat positionBoat2 = 0.0f;
GLfloat speedBoat2 = 0.02f;

GLfloat positionCar1 = 0.0f;
GLfloat speedCar1 = 0.05f;

GLfloat positionCar2 = 0.0f;
GLfloat speedCar2 = 0.04f;







void updateBus(int value) {
    if(positionBus <-8.0)
        positionBus = 8.0f;
    positionBus -= speedBus;
	glutPostRedisplay();
	glutTimerFunc(1, updateBus, 0);
}

void updateCloud(int value) {
    if(positionCloud <-5.0)
        positionCloud = 5.0f;
    positionCloud -= speedCloud;
	glutPostRedisplay();
	glutTimerFunc(1, updateCloud, 0);
}

void updateBoat1(int value) {
    if(positionBoat1 <-6.0)
        positionBoat1 = 6.0f;
    positionBoat1 -= speedBoat1;
	glutPostRedisplay();
	glutTimerFunc(1, updateBoat1, 0);
}

void updateBoat2(int value) {
    if(positionBoat2 > 6.0)
        positionBoat2 = -6.0f;
    positionBoat2 += speedBoat2;
	glutPostRedisplay();
	glutTimerFunc(1, updateBoat2, 0);
}

void updateSun(int value) {
    if(positionSun <-4.0)
        positionSun = 1.0f;
    positionSun -= speedSun;
	glutPostRedisplay();
	glutTimerFunc(1, updateSun, 0);
}

void updateCar1(int value) {
    if(positionCar1 > 6.0)
        positionCar1 = -6.0f;
    positionCar1 += speedCar1;
	glutPostRedisplay();
	glutTimerFunc(1, updateCar1, 0);
}

void updateCar2(int value) {
    if(positionCar2 <-6.0)
        positionCar2 = 6.0f;
    positionCar2 -= speedCar2;
	glutPostRedisplay();
	glutTimerFunc(1, updateCar2, 0);
}





void Sky(){
glPushMatrix();
    glColor3ub(128, 255, 255);
	glBegin(GL_QUADS);
	glVertex2f(-5,4);
	glVertex2f(-5,.5);
	glVertex2f(5,.5);
	glVertex2f(5,4);
	glEnd();
glPopMatrix();
}


void Circle(float x,float y,float rad,int r,int g,int b){
	int triangleAmount = 100; //# of triangles used to draw circle
	GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(r,g,b);
		glVertex2f(x, y); // center of circle
		for(int i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (rad * cos(i *  twicePi / triangleAmount)),
			    y + (rad * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

}

void Sun(){

glPushMatrix();
    glTranslatef(0.0f,positionSun, 0.0f);
	Circle(-1,4,.4,255,255,0);
glPopMatrix();

glPushMatrix();


}

void Clouds(){

glPushMatrix();
    glTranslatef(positionCloud,0.0f, 0.0f);

    Circle(-2.5,3.5,.3,255,255,255);
    Circle(-2.9,3.3,.3,255,255,255);
    Circle(-2.65,2.95,.3,255,255,255);
    Circle(-2,3.4,.3,255,255,255);
    Circle(-2.2,3.2,.3,255,255,255);

	Circle(2.26,3.04,.3,255,255,255);
	Circle(1.8,3,.3,255,255,255);
    Circle(1.6,3.4,.3,255,255,255);

glPopMatrix();

}


void Building1(){

glColor3ub(255,140,26);
	glBegin(GL_QUADS);
	glVertex2f(-5,3);
	glVertex2f(-5,.5);
	glVertex2f(-3.9,.5);
	glVertex2f(-3.9,3);
	glEnd();
glColor3ub(204, 102, 0);
	glBegin(GL_QUADS);
	glVertex2f(-3.9,3);
	glVertex2f(-3.9,.5);
	glVertex2f(-3.7,.5);
	glVertex2f(-3.7,2.7);
	glEnd();
//windows
glColor3ub(220,220,220);
	glBegin(GL_QUADS);
	glVertex2f(-4.85,2.8);
	glVertex2f(-4.85,2.4);
	glVertex2f(-4.5,2.4);
	glVertex2f(-4.5,2.8);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(-4.4,2.8);
	glVertex2f(-4.4,2.4);
	glVertex2f(-4.05,2.4);
	glVertex2f(-4.05,2.8);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(-4.85,2.2);
	glVertex2f(-4.85,1.8);
	glVertex2f(-4.5,1.8);
	glVertex2f(-4.5,2.2);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(-4.85,1.6);
	glVertex2f(-4.85,1.2);
	glVertex2f(-4.5,1.2);
	glVertex2f(-4.5,1.6);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(-4.85,1);
	glVertex2f(-4.85,.5);
	glVertex2f(-4.5,.5);
	glVertex2f(-4.5,1);
	glEnd();

}

void Building2(){

glColor3ub(153,51, 153);
	glBegin(GL_QUADS);
	glVertex2f(-4.6,2.5);
	glVertex2f(-4.6,.5);
	glVertex2f(-3.5,.5);
	glVertex2f(-3.5,2.5);
	glEnd();
glColor3ub(172, 57, 115);
	glBegin(GL_QUADS);
	glVertex2f(-3.5,2.5);
	glVertex2f(-3.5,.5);
	glVertex2f(-3.3,.5);
	glVertex2f(-3.3,2.2);
	glEnd();
//windows
glColor3ub(220,220,220);
	glBegin(GL_QUADS);
	glVertex2f(-4.45,2.3);
	glVertex2f(-4.45,1.9);
	glVertex2f(-4.1,1.9);
	glVertex2f(-4.1,2.3);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(-4,2.3);
	glVertex2f(-4,1.9);
	glVertex2f(-3.65,1.9);
	glVertex2f(-3.65,2.3);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(-4.45,1.7);
	glVertex2f(-4.45,1.3);
	glVertex2f(-4.1,1.3);
	glVertex2f(-4.1,1.7);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(-4,1.7);
	glVertex2f(-4,1.3);
	glVertex2f(-3.65,1.3);
	glVertex2f(-3.65,1.7);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(-4.45,1.1);
	glVertex2f(-4.45,.7);
	glVertex2f(-4.1,.7);
	glVertex2f(-4.1,1.1);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(-4,1.1);
	glVertex2f(-4,.7);
	glVertex2f(-3.65,.7);
	glVertex2f(-3.65,1.1);
	glEnd();

}

void Building3(){

glColor3ub(102, 153, 0);
	glBegin(GL_QUADS);
	glVertex2f(-2.6,2.5);
	glVertex2f(-2.6,.5);
	glVertex2f(-1.5,.5);
	glVertex2f(-1.5,2.5);
	glEnd();
glColor3ub(136, 136, 68);
	glBegin(GL_QUADS);
	glVertex2f(-1.5,2.5);
	glVertex2f(-1.5,.5);
	glVertex2f(-1.3,.5);
	glVertex2f(-1.3,2.2);
	glEnd();
//windows
glColor3ub(220,220,220);
	glBegin(GL_QUADS);
	glVertex2f(-2.45,2.3);
	glVertex2f(-2.45,1.9);
	glVertex2f(-2.1,1.9);
	glVertex2f(-2.1,2.3);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(-2,2.3);
	glVertex2f(-2,1.9);
	glVertex2f(-1.65,1.9);
	glVertex2f(-1.65,2.3);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(-2.45,1.7);
	glVertex2f(-2.45,1.3);
	glVertex2f(-2.1,1.3);
	glVertex2f(-2.1,1.7);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(-2,1.7);
	glVertex2f(-2,1.3);
	glVertex2f(-1.65,1.3);
	glVertex2f(-1.65,1.7);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(-2.45,1.1);
	glVertex2f(-2.45,.7);
	glVertex2f(-2.1,.7);
	glVertex2f(-2.1,1.1);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(-2,1.1);
	glVertex2f(-2,.7);
	glVertex2f(-1.65,.7);
	glVertex2f(-1.65,1.1);
	glEnd();

}

void Building4(){

glColor3ub(0,128,102);
	glBegin(GL_QUADS);
	glVertex2f(-1.1,2.5);
	glVertex2f(-1.1,.5);
	glVertex2f(0,.5);
	glVertex2f(0,2.5);
	glEnd();
glColor3ub(0, 102,82);
	glBegin(GL_QUADS);
	glVertex2f(0,2.5);
	glVertex2f(0,.5);
	glVertex2f(.2,.5);
	glVertex2f(.2,2.2);
	glEnd();

//windows
glColor3ub(220,220,220);
	glBegin(GL_QUADS);
	glVertex2f(-.95,2.3);
	glVertex2f(-.95,1.9);
	glVertex2f(-.6,1.9);
	glVertex2f(-.6,2.3);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(-.5,2.3);
	glVertex2f(-.5,1.9);
	glVertex2f(-.15,1.9);
	glVertex2f(-.15,2.3);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(-.95,1.7);
	glVertex2f(-.95,1.3);
	glVertex2f(-.6,1.3);
	glVertex2f(-.6,1.7);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(-.5,1.7);
	glVertex2f(-.5,1.3);
	glVertex2f(-.15,1.3);
	glVertex2f(-.15,1.7);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(-.95,1.1);
	glVertex2f(-.95,.7);
	glVertex2f(-.6,.7);
	glVertex2f(-.6,1.1);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(-.5,1.1);
	glVertex2f(-.5,.7);
	glVertex2f(-.15,.7);
	glVertex2f(-.15,1.1);
	glEnd();

}

void Building6(){

glColor3ub(255,102,102);
	glBegin(GL_QUADS);
	glVertex2f(1.7,2.7);
	glVertex2f(1.7,.5);
	glVertex2f(1.9,.5);
	glVertex2f(1.9,3);
	glEnd();
glColor3ub(255,80,80);
	glBegin(GL_QUADS);
	glVertex2f(1.9,3);
	glVertex2f(1.9,.5);
	glVertex2f(3,.5);
	glVertex2f(3,3);
	glEnd();
//windows
glColor3ub(220,220,220);
	glBegin(GL_QUADS);
	glVertex2f(2.05,2.8);
	glVertex2f(2.05,2.4);
	glVertex2f(2.4,2.4);
	glVertex2f(2.4,2.8);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(2.5,2.8);
	glVertex2f(2.5,2.4);
	glVertex2f(2.85,2.4);
	glVertex2f(2.85,2.8);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(2.05,2.2);
	glVertex2f(2.05,1.8);
	glVertex2f(2.4,1.8);
	glVertex2f(2.4,2.2);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(2.5,2.2);
	glVertex2f(2.5,1.8);
	glVertex2f(2.85,1.8);
	glVertex2f(2.85,2.2);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(2.05,1.6);
	glVertex2f(2.05,1.2);
	glVertex2f(2.4,1.2);
	glVertex2f(2.4,1.6);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(2.5,1.6);
	glVertex2f(2.5,1.2);
	glVertex2f(2.85,1.2);
	glVertex2f(2.85,1.6);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(2.05,1);
	glVertex2f(2.05,.5);
	glVertex2f(2.4,.5);
	glVertex2f(2.4,1);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(2.5,1);
	glVertex2f(2.5,.5);
	glVertex2f(2.85,.5);
	glVertex2f(2.85,1);
	glEnd();

}

void Building7(){

glColor3ub(204, 122,0);
	glBegin(GL_QUADS);
	glVertex2f(3.8,3.2);
	glVertex2f(3.8,.5);
	glVertex2f(4,.5);
	glVertex2f(4,3.5);
	glEnd();
glColor3ub(255, 153, 0);
	glBegin(GL_QUADS);
	glVertex2f(4,3.5);
	glVertex2f(4,.5);
	glVertex2f(5,.5);
	glVertex2f(5,3.5);
	glEnd();
//windows
glColor3ub(220, 220, 220);
	glBegin(GL_QUADS);
	glVertex2f(4.15,3.3);
	glVertex2f(4.15,2.9);
	glVertex2f(4.5,2.9);
	glVertex2f(4.5,3.3);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(4.6,3.3);
	glVertex2f(4.6,2.9);
	glVertex2f(4.95,2.9);
	glVertex2f(4.95,3.3);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(4.15,2.7);
	glVertex2f(4.15,2.3);
	glVertex2f(4.5,2.3);
	glVertex2f(4.5,2.7);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(4.6,2.7);
	glVertex2f(4.6,2.3);
	glVertex2f(4.95,2.3);
	glVertex2f(4.95,2.7);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(4.15,2.1);
	glVertex2f(4.15,1.7);
	glVertex2f(4.5,1.7);
	glVertex2f(4.5,2.1);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(4.6,2.1);
	glVertex2f(4.6,1.7);
	glVertex2f(4.95,1.7);
	glVertex2f(4.95,2.1);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(4.15,1.5);
	glVertex2f(4.15,1.1);
	glVertex2f(4.5,1.1);
	glVertex2f(4.5,1.5);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(4.6,1.5);
	glVertex2f(4.6,1.1);
	glVertex2f(4.95,1.1);
	glVertex2f(4.95,1.5);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(4.15,.9);
	glVertex2f(4.15,.7);
	glVertex2f(4.5,.7);
	glVertex2f(4.5,.9);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(4.6,.9);
	glVertex2f(4.6,.7);
	glVertex2f(4.95,.7);
	glVertex2f(4.95,.9);
	glEnd();

}

void Building8(){

glColor3ub(0, 102,34);
	glBegin(GL_QUADS);
	glVertex2f(3.1,2.2);
	glVertex2f(3.1,.5);
	glVertex2f(3.3,.5);
	glVertex2f(3.3,2.5);
	glEnd();
glColor3ub(0, 153, 51);
	glBegin(GL_QUADS);
	glVertex2f(3.3,2.5);
	glVertex2f(3.3,.5);
	glVertex2f(4.4,.5);
	glVertex2f(4.4,2.5);
	glEnd();
//windows
glColor3ub(220, 220, 220);
	glBegin(GL_QUADS);
	glVertex2f(3.45,2.3);
	glVertex2f(3.45,1.9);
	glVertex2f(3.8,1.9);
	glVertex2f(3.8,2.3);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(3.9,2.3);
	glVertex2f(3.9,1.9);
	glVertex2f(4.25,1.9);
	glVertex2f(4.25,2.3);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(3.45,1.7);
	glVertex2f(3.45,1.3);
	glVertex2f(3.8,1.3);
	glVertex2f(3.8,1.7);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(3.9,1.7);
	glVertex2f(3.9,1.3);
	glVertex2f(4.25,1.3);
	glVertex2f(4.25,1.7);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(3.45,1.1);
	glVertex2f(3.45,.7);
	glVertex2f(3.8,.7);
	glVertex2f(3.8,1.1);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(3.9,1.1);
	glVertex2f(3.9,.7);
	glVertex2f(4.25,.7);
	glVertex2f(4.25,1.1);
	glEnd();


}


float clock_X,clock_Y;
float secondCounter=0.0;
float minuteCounter=0.0;
float hourCounter=0.0;
float clock_Timer=40;

void Clock(){

//bg circle 1
	glPushMatrix();
	glTranslatef(0.95,2.5,0);
        glBegin(GL_TRIANGLE_FAN);
            glColor3ub(100,150,255);
            for(float i=0;i<=2*3.14;i+=0.0001)
            {
                clock_X=0.6*sin(i);
                clock_Y=0.6*cos(i);
                glVertex2f(clock_X,clock_Y);
            }
        glEnd();
	glPopMatrix();

	//bg circle 2
	glPushMatrix();
	glTranslatef(0.95,2.5,0);
        glBegin(GL_TRIANGLE_FAN);
            glColor3ub(150,150,150);
            for(float i=0;i<=2*3.14;i+=0.0001)
            {
                clock_X=0.55*sin(i);
                clock_Y=0.55*cos(i);
                glVertex2f(clock_X,clock_Y);
            }
        glEnd();
	glPopMatrix();

	//clock hand hour
    glPushMatrix();
    glLoadIdentity();
        glTranslatef(0.188,0.63,0);
        glRotatef(hourCounter,0.0,0.0,-1.0);
        if(minuteCounter>=360){
            hourCounter+=clock_Timer;
            minuteCounter=0;
        }
        glBegin(GL_POLYGON);
            glColor3ub(255,255,0);
            glVertex2f(0,0);
            glVertex2f(0,0.05);
            glVertex2f(0.01,0.07);
            glVertex2f(0.02,0.05);
        glEnd();
    glPopMatrix();

    //clock hand minute
    glPushMatrix();
    glLoadIdentity();
        glTranslatef(0.188,0.63,0);
        glRotatef(minuteCounter,0.0,0.0,-1.0);
        if(secondCounter>=360){
            minuteCounter+=clock_Timer;
            secondCounter=0;
        }
        glBegin(GL_POLYGON);
            glColor3ub(255,255,255);
            glVertex2f(0,0);
            glVertex2f(0,0.075);
            glVertex2f(0.0075,0.09);
            glVertex2f(0.015,0.075);
        glEnd();
    glPopMatrix();

    //clock hand second
    glPushMatrix();
        glLoadIdentity();
        glTranslatef(0.188,0.63,0);
        glRotatef(secondCounter,0.0,0.0,-1.0);
        secondCounter+=clock_Timer;
        glBegin(GL_POLYGON);
            glColor3ub(255,0,0);
            glVertex2f(0,0);
            glVertex2f(0,0.1);
            glVertex2f(0.005,0.11);
            glVertex2f(0.01,0.1);
        glEnd();
    glPopMatrix();

	//middle circle 1
	glPushMatrix();
	glTranslatef(0.95,2.5,0);
	glBegin(GL_TRIANGLE_FAN);
		glColor3ub(0,0,255);
		for(float i=0;i<=2*3.14;i+=0.0001)
		{
			clock_X=0.06*sin(i);
			clock_Y=0.06*cos(i);
			glVertex2f(clock_X,clock_Y);
		}
	glEnd();
	glPopMatrix();

	//glutSwapBuffers();

}

void ClockTower(){

glColor3ub(230, 0, 115);
	glBegin(GL_QUADS);
	glVertex2f(.3,3); //TOP LEFT
	glVertex2f(.3,.5); //BOTTOM LEFT
	glVertex2f(1.6,.5); //BOTTOM RIGHT
	glVertex2f(1.6,3); //TOP RIGHT
	glEnd();
	glBegin(GL_QUADS);
	glVertex2f(.5,3.2); //TOP LEFT
	glVertex2f(.4,3); //BOTTOM LEFT
	glVertex2f(1.5,3); //BOTTOM RIGHT
	glVertex2f(1.4,3.2); //TOP RIGHT
	glEnd();
	glBegin(GL_QUADS);
	glVertex2f(.7,3.4); //TOP LEFT
	glVertex2f(.6,3.2); //BOTTOM LEFT
	glVertex2f(1.3,3.2); //BOTTOM RIGHT
	glVertex2f(1.2,3.4); //TOP RIGHT
	glEnd();
	glBegin(GL_QUADS);
	glVertex2f(.9,3.6); //TOP LEFT
	glVertex2f(.8,3.4); //BOTTOM LEFT
	glVertex2f(1.1,3.4); //BOTTOM RIGHT
	glVertex2f(1.0,3.6); //TOP RIGHT
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(0.95,3.6);
	glVertex2f(0.95,4);
	glEnd();

////windows
glColor3ub(220,220,220);
	glBegin(GL_QUADS);
	glVertex2f(.55,1.8);
	glVertex2f(.55,1.4);
	glVertex2f(.9,1.4);
	glVertex2f(.9,1.8);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(1,1.8);
	glVertex2f(1,1.4);
	glVertex2f(1.35,1.4);
	glVertex2f(1.35,1.8);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(.55,1.2);
	glVertex2f(.55,.8);
	glVertex2f(.9,.8);
	glVertex2f(.9,1.2);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(1,1.2);
	glVertex2f(1,.8);
	glVertex2f(1.35,.8);
	glVertex2f(1.35,1.2);
	glEnd();

//clock
    //Clock();



}







void Road_Divider(float x,float y,float z){

glPushMatrix();
glTranslatef(x,y,z);

    glColor3ub(220,220,220);
	glBegin(GL_QUADS);
	glVertex2f(-5,-2);
	glVertex2f(-5,-2.3);
	glVertex2f(5,-2.3);
	glVertex2f(5,-2);
	glEnd();

	//border Black
    glColor3ub(0,0,0);
    float qx=-4;
	for(int i=0;i<6;i++){
        glBegin(GL_QUADS);
        glVertex2f(qx,-2);
        glVertex2f(qx,-2.3);
        glVertex2f(qx+1,-2.3);
        glVertex2f(qx+1,-2);
        qx+=2;
        glEnd();
	}

glPopMatrix();

}

void Road_Lines(float x,float y,float z){

glPushMatrix();
glTranslatef(x,y,z);
    glLineWidth(5.5);
    glColor3ub(255, 255, 255);

    float lsx=-4.4,lex=-4.1,ly=-1.5;
    for(int i=0;i<11;i++){
        glBegin(GL_LINES);
        glVertex2f(lsx,ly);
        glVertex2f(lex,ly);
        lsx+=1;
        lex+=1;
        glEnd();
    }
glPopMatrix();

}

void Road(){

glColor3ub(166, 166, 166);
	glBegin(GL_QUADS);
	glVertex2f(-5,.2);
	glVertex2f(-5,-2);
	glVertex2f(5,-2);
	glVertex2f(5,.2);
	glEnd();

    //divider bottom, middle, top
    Road_Divider(0,0,0);
    Road_Divider(0,1.25,0);
    Road_Divider(0,2.5,0);

    //lines
    Road_Lines(0,0,0);
    Road_Lines(0,1.2,0);


}

void Car1(){

glPushMatrix();
glTranslatef(positionCar1,0.0, 0.0f);

  glBegin(GL_QUADS);
{
    glColor3f(204, 0, 102); //red
    glVertex2f(0.3f,0.1f);
    glVertex2f(0.3f,-0.2f);
    glVertex2f(-0.6f,-0.2f);
    glVertex2f(-0.6f,0.1f);
    glEnd();
}
  glBegin(GL_QUADS);
{
    glColor3f(153, 255, 51);
    glVertex2f(0.15f,0.1f);
    glVertex2f(0.0f,0.32f);
    glVertex2f(-0.35f,0.32f);
    glVertex2f(-0.45f,0.1f);
    glEnd();
}

  //wheel
glColor3f(0.0f,0.0f,0.0f);
    int ib;
    GLfloat xb=0.05f; GLfloat yb=-.2f; GLfloat radiusb =.12f;
	int triangleAmountb = 20;
	GLfloat twicePib = 2.0f * PI;
   glBegin(GL_TRIANGLE_FAN);
		glVertex2f(xb, yb);
		for(ib = 0; ib <= triangleAmountb;ib++)
            {
			glVertex2f(
                xb + (radiusb * cos(ib *  twicePib / triangleAmountb)),
			    yb + (radiusb * sin(ib * twicePib / triangleAmountb))
			          );
            }
	glEnd();

	glColor3f(0.0f,0.0f,0.0f);
    int jb;
    GLfloat pb=-0.35f; GLfloat qb=-0.2f; GLfloat radb =.12f;
	int triangleAmtb = 20;
	GLfloat twicepib = 2.0f * PI;
   glBegin(GL_TRIANGLE_FAN);
		glVertex2f(pb, qb);
		for(jb = 0; jb <= triangleAmtb;jb++)
            {
			glVertex2f(
                pb + (radb * cos(jb *  twicepib / triangleAmtb)),
			    qb + (radb * sin(jb * twicepib / triangleAmtb))
			          );
            }
	glEnd();

	glColor3f(1.0f,1.0f,1.0f);

   GLfloat radi =.08f;

   glBegin(GL_TRIANGLE_FAN);
		glVertex2f(xb, yb);
		for(ib = 0; ib <= triangleAmountb;ib++)
            {
			glVertex2f(
                xb + (radi * cos(ib *  twicePib / triangleAmountb)),
			    yb + (radi * sin(ib * twicePib / triangleAmountb))
			          );
            }
	glEnd();



   glBegin(GL_TRIANGLE_FAN);
		glVertex2f(pb, qb);
		for(jb = 0; jb <= triangleAmtb;jb++)
            {
			glVertex2f(
                pb + (radi * cos(jb *  twicepib / triangleAmtb)),
			    qb + (radi * sin(jb * twicepib / triangleAmtb))
			          );
            }
	glEnd();

glPopMatrix();

}

void Car2(){

glPushMatrix();
glTranslatef(positionCar2,0.0, 0.0f);

  glBegin(GL_QUADS);
    glColor3f(1.0f,0.67f,0.0f);
    glVertex2f(0.3f,-1.0f);
    glVertex2f(0.3f,-1.3f);
    glVertex2f(-0.6f,-1.3f);
    glVertex2f(-0.6f,-1.0f);
    glEnd();

  glBegin(GL_QUADS);
    glColor3f(0.6f, 0.8f, 1.0f);
    glVertex2f(0.15f,-1.0f);
    glVertex2f(0.0f,-.80f);
    glVertex2f(-0.35f,-.80f);
    glVertex2f(-0.45f,-1.0f);
    glEnd();
//wheel
glColor3f(0.0f,0.0f,0.0f);
   GLfloat xbp=0.05f; GLfloat ybp=-1.3f;
   GLfloat radiusb =.12f;
   int triangleAmountb = 20;
    int ib;
    GLfloat twicePib = 2.0f * PI;
   glBegin(GL_TRIANGLE_FAN);
		glVertex2f(xbp, ybp);
		for(ib = 0; ib <= triangleAmountb;ib++)
            {
			glVertex2f(
                xbp + (radiusb * cos(ib *  twicePib / triangleAmountb)),
			    ybp + (radiusb * sin(ib * twicePib / triangleAmountb))
			          );
            }
	glEnd();

	glColor3f(0.0f,0.0f,0.0f);
    GLfloat pbp=-0.35f; GLfloat qbp=-1.3f;
    GLfloat radb =.12f;
    int jb;
    int triangleAmtb = 20;
	GLfloat twicepib = 2.0f * PI;
   glBegin(GL_TRIANGLE_FAN);
		glVertex2f(pbp, qbp);
		for(jb = 0; jb <= triangleAmtb;jb++)
            {
			glVertex2f(
                pbp + (radb * cos(jb *  twicepib / triangleAmtb)),
			    qbp + (radb * sin(jb * twicepib / triangleAmtb))
			          );
            }
	glEnd();

	glColor3f(1.0f,1.0f,1.0f);
    GLfloat radi =.08f;

   glBegin(GL_TRIANGLE_FAN);
		glVertex2f(xbp, ybp);
		for(ib = 0; ib <= triangleAmountb;ib++)
            {
			glVertex2f(
                xbp + (radi * cos(ib *  twicePib / triangleAmountb)),
			    ybp + (radi * sin(ib * twicePib / triangleAmountb))
			          );
            }
	glEnd();


   glBegin(GL_TRIANGLE_FAN);
		glVertex2f(pbp, qbp);
		for(jb = 0; jb <= triangleAmtb;jb++)
            {
			glVertex2f(
                pbp + (radi * cos(jb *  twicepib / triangleAmtb)),
			    qbp + (radi * sin(jb * twicepib / triangleAmtb))
			          );
            }
	glEnd();

glPopMatrix();

}

void Bus(){


glPushMatrix();
glTranslatef(positionBus,0.0, 0.0f);
  glBegin(GL_QUADS);
    glColor3ub(179, 255, 102);
    glVertex2f(3.0f,-1.8f);
    glVertex2f(4.5f,-1.8f);
    glVertex2f(4.5f,-1.6f);
    glVertex2f(3.0f,-1.6f);
    glEnd();

   glBegin(GL_QUADS);
    glVertex2f(3.2f,-1.6f);
    glVertex2f(4.5f,-1.6f);
    glVertex2f(4.5f,-1.1f);
    glVertex2f(3.2f,-1.1f);
    glEnd();

     glBegin(GL_QUADS);
   glColor3ub(0, 51, 77);
    glVertex2f(3.4f,-1.6f);
    glVertex2f(3.55f,-1.6f);
    glVertex2f(3.55f,-1.3f);
    glVertex2f(3.4f,-1.3f);
    glEnd();

         glBegin(GL_QUADS);
    glVertex2f(3.6f,-1.6f);
    glVertex2f(3.8f,-1.6f);
    glVertex2f(3.8f,-1.4f);
    glVertex2f(3.6f,-1.4f);
    glEnd();

           glBegin(GL_QUADS);
    glVertex2f(3.9f,-1.6f);
    glVertex2f(4.1f,-1.6f);
    glVertex2f(4.1f,-1.4f);
    glVertex2f(3.9f,-1.4f);
    glEnd();

           glBegin(GL_QUADS);
    glVertex2f(4.2f,-1.6f);
    glVertex2f(4.4f,-1.6f);
    glVertex2f(4.4f,-1.4f);
    glVertex2f(4.2f,-1.4f);
    glEnd();

////

     glBegin(GL_QUADS);
    glVertex2f(3.3f,-1.3f);
    glVertex2f(3.3f,-1.3f);
    glVertex2f(3.5f,-1.2f);
    glVertex2f(3.5f,-1.2f);
    glEnd();

         glBegin(GL_QUADS);
   glColor3ub(0, 51, 77);
    glVertex2f(3.6f,-1.3f);
    glVertex2f(3.8f,-1.3f);
    glVertex2f(3.8f,-1.2f);
    glVertex2f(3.6f,-1.2f);
    glEnd();

           glBegin(GL_QUADS);
    glVertex2f(3.9f,-1.3f);
    glVertex2f(4.1f,-1.3f);
    glVertex2f(4.1f,-1.2f);
    glVertex2f(3.9f,-1.2f);
    glEnd();

           glBegin(GL_QUADS);
    glVertex2f(4.2f,-1.3f);
    glVertex2f(4.4f,-1.3f);
    glVertex2f(4.4f,-1.2f);
    glVertex2f(4.2f,-1.2f);
    glEnd();

    glBegin(GL_QUADS);
   glColor3ub(230, 255, 255);
    glVertex2f(3.0f,-1.6f);
    glVertex2f(3.2f,-1.6f);
    glVertex2f(3.2f,-1.4f);
    glVertex2f(3.0f,-1.4f);
    glEnd();

       glBegin(GL_TRIANGLES);
    glVertex2f(3.0f,-1.4f);
    glVertex2f(3.2f,-1.4f);
    glVertex2f(3.2f,-1.1f);
   glEnd();


     glBegin(GL_QUADS);
   glColor3ub(1,0,0);
    glVertex2f(3.1f,-1.7f);
    glVertex2f(3.3f,-1.7f);
    glVertex2f(3.3f,-1.4f);
    glVertex2f(3.1f,-1.4f);
    glEnd();

   //wheel
glColor3f(0,0,0);
   GLfloat xbpr=3.4f; GLfloat ybpr=-1.8f,radbw=.13,radiw=.09;
   int triangleAmountb = 20;
    int ib;
    GLfloat twicePib = 2.0f * PI;

   glBegin(GL_TRIANGLE_FAN);
		glVertex2f(xbpr, ybpr);
		for(ib = 0; ib <= triangleAmountb;ib++)
            {
			glVertex2f(
                xbpr + (radbw * cos(ib *  twicePib / triangleAmountb)),
			    ybpr + (radbw * sin(ib * twicePib / triangleAmountb))
			          );
            }
	glEnd();

	glColor3f(0,0,0);

    GLfloat pbpt=4.2f; GLfloat qbpt=-1.8f;
    int jb;
    int triangleAmtb = 20;
	GLfloat twicepib = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
		glVertex2f(pbpt, qbpt);
		for(jb = 0; jb <= triangleAmtb;jb++)
            {
			glVertex2f(
                pbpt + (radbw * cos(jb *  twicepib / triangleAmtb)),
			    qbpt + (radbw * sin(jb * twicepib / triangleAmtb))
			          );
            }
	glEnd();

	glColor3f(1,1,1);


   glBegin(GL_TRIANGLE_FAN);
		glVertex2f(xbpr, ybpr);
		for(ib = 0; ib <= triangleAmountb;ib++)
            {
			glVertex2f(
                xbpr + (radiw * cos(ib *  twicePib / triangleAmountb)),
			    ybpr + (radiw * sin(ib * twicePib / triangleAmountb))
			          );
            }
	glEnd();


   glBegin(GL_TRIANGLE_FAN);
		glVertex2f(pbpt, qbpt);
		for(jb = 0; jb <= triangleAmtb;jb++)
            {
			glVertex2f(
                pbpt + (radiw * cos(jb *  twicepib / triangleAmtb)),
			    qbpt + (radiw * sin(jb * twicepib / triangleAmtb))
			          );
            }
	glEnd();
	glPopMatrix();



}


void River(){

glColor3ub(35, 200, 255);
	glBegin(GL_QUADS);
	glVertex2f(-5,-2.3);
	glVertex2f(-5,-4);
	glVertex2f(5,-4);
	glVertex2f(5,-2.3);
	glEnd();


}

void Boat1(){

glPushMatrix();
glTranslatef(positionBoat1,0.0, 0.0f);

glColor3ub(0,0,0);
    glBegin(GL_TRIANGLES);
    glVertex2f(2.8,-3);
	glVertex2f(2.5,-2.8);
	glVertex2f(2.7,-3.2);
	glEnd();

	glBegin(GL_QUADS);
	glVertex2f(2.8,-3);
	glVertex2f(2.7,-3.2);
	glVertex2f(3.6,-3.2);
	glVertex2f(3.5,-3);
	glEnd();

	glBegin(GL_TRIANGLES);
     glVertex2f(3.5,-3);
	glVertex2f(3.6,-3.2);
	glVertex2f(3.8,-2.8);
    glEnd();

glColor3ub(204, 51, 0);
    glBegin(GL_TRIANGLES);
    glVertex2f(2.8,-3);
	glVertex2f(3,-3);
	glVertex2f(2.9,-2.7);
	glEnd();
glColor3ub(12,153,13);
    glBegin(GL_QUADS);
    glVertex2f(2.9,-2.7);
	glVertex2f(3,-3);
	glVertex2f(3.5,-3);
    glVertex2f(3.4,-2.7);
	glEnd();
glPopMatrix();


}

void Boat2(){

glPushMatrix();
glTranslatef(positionBoat2,0.0, 0.0f);


glColor3ub(12,134,143);
    glBegin(GL_TRIANGLES);
    glVertex2f(-2.8,-2.5);
	glVertex2f(-2.5,-2.3);
	glVertex2f(-2.7,-2.7);
	glEnd();

	glBegin(GL_QUADS);
	glVertex2f(-2.8,-2.5);
	glVertex2f(-2.7,-2.7);
	glVertex2f(-3.6,-2.7);
	glVertex2f(-3.5,-2.5);
	glEnd();

	glBegin(GL_TRIANGLES);
     glVertex2f(-3.5,-2.5);
	glVertex2f(-3.6,-2.7);
	glVertex2f(-3.8,-2.3);
    glEnd();

glColor3ub(12,13,13);
    glBegin(GL_TRIANGLES);
    glVertex2f(-2.8,-2.5);
	glVertex2f(-3,-2.5);
	glVertex2f(-2.9,-2.2);
	glEnd();
glColor3ub(12,153,13);
    glBegin(GL_QUADS);
    glVertex2f(-2.9,-2.2);
	glVertex2f(-3,-2.5);
	glVertex2f(-3.5,-2.5);
    glVertex2f(-3.4,-2.2);
	glEnd();

	glPopMatrix();


}






void display() {

    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
    gluOrtho2D(-5,5,-4,4);

    //Sky, Sun, Clouds
    Sky();
    Sun();

    Clouds();

    //Buildings
    Building1();
    Building2();
    Building3();
    Building4();
    ClockTower();
    Building6();
    Building7();
    Building8();

    //River & Road
    River();
    Road();

    //Vehicles
    Car1();
    Car2();
    Bus();
    Boat1();
    Boat2();

    Clock();

    glFlush();
}






int main(int argc,char**argv)
{
    glutInit(&argc,argv);
    glutInitWindowSize(1200,960);
    glutCreateWindow("City View");
    glutDisplayFunc(display);
    glutTimerFunc(1, updateCloud, 0);
    glutTimerFunc(1, updateCar1, 0);
    glutTimerFunc(1, updateCar2, 0);
    glutTimerFunc(1, updateBus, 0);
    glutTimerFunc(1, updateBoat1, 0);
    glutTimerFunc(1, updateBoat2, 0);
    glutTimerFunc(1, updateSun, 0);

    glutMainLoop();

    return 0;
}

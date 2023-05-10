/*#include<iostream>
#include<stdlib.h>
#ifdef __APPLE__
#include<openGL/openGL.h>
#include<GLUT/glut.h>
#else
#include<GL/glut.h>
#endif

using namespace std;

float ballX = -0.8f;
float ballY = -0.3f;
float ballZ = -1.2f;

static int flag=1;
void drawBall(void) {
        glColor3f(1,1,0); //set ball colour                                                        is gl
        glTranslatef(ballX,ballY,ballZ); //moving it toward the screen a bit on creation           is gl

        glutSolidSphere (0.05, 30, 30); //create ball. and is                    glut

}
void keyPress(int key, int x, int y)
{
      if(key==GLUT_KEY_RIGHT)
        ballX += 0.05f;
        if(ballX>1.0f){
            ballX=-0.8f;
        }
    if(key==GLUT_KEY_LEFT)
        ballX  -= 0.05f;

	 if(key==GLUT_KEY_UP)
        ballY += 0.05f;
        if(ballY>0.6){
            ballY=-0.3f;
        }
    if(key==GLUT_KEY_DOWN)
        ballY  -= 0.05f;
    glutPostRedisplay(); //----------------------->>  IMP
}
//Called when the window is resized
void handleResize(int w, int h) {
    //Tell OpenGL how to convert from coordinates to pixel values
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION); //Switch to setting the camera perspective
    //Set the camera perspective
    glLoadIdentity(); //Reset the camera
    gluPerspective(45.0,                  //The camera angle
                   (double)w / (double)h, //The width-to-height ratio
                   1.0,                   //The near z clipping coordinate
                   200.0);                //The far z clipping coordinate
}

void drawScene()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
  //  glClearColor(bgColR,bgColG,bgColB,0.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    //drawing the SUN
    glPushMatrix();
        drawBall();
    glPopMatrix();
    //drawing the Mount Avarest

    glutSwapBuffers();
}

int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
    glutInitWindowSize(400,400);
    glutCreateWindow("ball game");
    glutDisplayFunc(drawScene);
    //glutFullScreen();                to make full screen
    glutSpecialFunc(keyPress);
    glutReshapeFunc(handleResize);
    //glutTimerFunc(25, update, 0);
    glutMainLoop();
    return 0;
}
*/



/*

                                                                       //THIS IS THE SUN CODE
#include<iostream>
#include<stdlib.h>
#ifdef __APPLE__
#include<openGL/openGL.h>
#include<GLUT/glut.h>
#else
#include<GL/glut.h>
#endif

using namespace std;

float ballX = -0.8f;
float ballY = -0.3f;
float ballZ = -1.2f;
float colR=3.0;
float colG=1.5;
float colB=1.0;
float bgColR=0.0;
float bgColG=0.0;
float bgColB=0.0;

static int flag=1;

void drawBall(void) {
        glColor3f(colR,colG,colB); //set ball colour
        glTranslatef(ballX,ballY,ballZ); //moving it toward the screen a
                                       //bit on creation
        glutSolidSphere (0.05, 30, 30); //create ball.
}

//Called when the window is resized
void handleResize(int w, int h) {
    //Tell OpenGL how to convert from coordinates to pixel values
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION); //Switch to setting the camera perspective
    //Set the camera perspective
    glLoadIdentity(); //Reset the camera
    gluPerspective(45.0,(double)w / (double)h,1.0,200.0);//The camera angle//The width-to-height ratio //The near&far z clipping coordinate
}

void drawScene()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glClearColor(bgColR,bgColG,bgColB,0.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    //Add ambient light
    GLfloat ambientColor[] = {0.2f, 0.2f, 0.2f, 1.0f}; //Color (0.2, 0.2, 0.2)
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);
    //Add positioned light
    GLfloat lightColor0[] = {0.5f, 0.5f, 0.5f, 1.0f}; //Color (0.5, 0.5, 0.5)
    GLfloat lightPos0[] = {4.0f, 0.0f, 8.0f, 1.0f}; //Positioned at (4, 0, 8)
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor0);
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);
    //Add directed light
    GLfloat lightColor1[] = {0.5f, 0.2f, 0.2f, 1.0f}; //Color (0.5, 0.2, 0.2)
    //Coming from the direction (-1, 0.5, 0.5)
    GLfloat lightPos1[] = {-1.0f, 0.5f, 0.5f, 0.0f};
    glLightfv(GL_LIGHT1, GL_DIFFUSE, lightColor1);
    glLightfv(GL_LIGHT1, GL_POSITION, lightPos1);
    //drawing the SUN
    glPushMatrix();
        drawBall();
    glPopMatrix();
    glutSwapBuffers();
}
//float _angle = 30.0f;
void update(int value) {
    if(ballX>0.9f)
    {
        ballX = -0.8f;
        ballY = -0.3f;
        flag=1;
        colR=2.0;
        colG=1.50;
        colB=1.0;
        bgColB=0.0;
    }
    if(flag)
    {
    ballX += 0.001f;
    ballY +=0.0007f;
    colR-=0.001;
    //colG+=0.002;
    colB+=0.005;
    bgColB+=0.001;
       if(ballX>0.01)
       {
           flag=0;
       }
    }
    if (!flag)
    {
        ballX += 0.001f;
        ballY -=0.0007f;
        colR+=0.001;
        colB-=0.01;
        bgColB-=0.001;
        if(ballX<-0.3)
       {
           flag=1;
       }
    }
    glutPostRedisplay(); //Tell GLUT that the display has changed
    //Tell GLUT to call update again in 25 milliseconds
    glutTimerFunc(25, update, 0);
}

int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
    glutInitWindowSize(400,400);
    glutCreateWindow("Sun");
    glutDisplayFunc(drawScene);
    //glutFullScreen();
    glutReshapeFunc(handleResize);
    glutTimerFunc(25, update, 0);
    glutMainLoop();
    return(0);
}
*/


#include <GL/glut.h>
void display();
void update(int);

float sx = -1.0 ;
float sy = -1.0 ;
float sz = -1.0 ;


int main(int argc, char** argv)
{
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE );

	//glutInitWindowPosition(100,100);

	glutInitWindowSize(500,500);

	glutCreateWindow("Window");

	glutDisplayFunc(display);

	glutTimerFunc(100, update, 0);

	glutMainLoop();
	return 0 ;

}

void draw_sun()
{
	glPushMatrix();
	glTranslatef(sx, sy, sz);
	glColor3f(1.0,0.5,0.0);
	glutSolidSphere(0.1,100,100);
	glPopMatrix();
}

void draw_mountains()
{
	glPushMatrix();
	glBegin(GL_POLYGON);
		glColor3f(1.0*sy,1.0 * sy,0.0);
		glVertex3f(-1.0,-1.0,0.0);
		glColor3f(0.5,0.2,0.0);
		glVertex3f(-0.5,0.0,0.0);
		glVertex3f(0.0,-1.0,0.0);
	glEnd();
	glBegin(GL_POLYGON);
		glColor3f(0.0,1.0 * sy,0.0);
		glVertex3f(0.0,-1.0,0.0);
		glColor3f(0.5,0.2,0.0);
		glVertex3f(0.5,0.0,0.0);
		glVertex3f(1.0,-1.0,0.0);
	glEnd();
	glPopMatrix();

}

void display()
{
	glClearColor(0.0,0.2 * sy * 20 ,0.3 * sy * 10, 1.0);
	//glClearColor(0.0,0.0 ,0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	draw_sun();
	draw_mountains();
	glutSwapBuffers();
}

void update(int)
{
	if (sx < 0.0)
	{
		sx = sx + 0.01;
		sy = sy + 0.015;
	}
	else
	{
		sx = sx + 0.01 ;
		sy = sy -0.015;
	}
	glutPostRedisplay();
	glutTimerFunc(100,update, 0);
}


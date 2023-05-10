#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
GLfloat xRotate,yRotate,zRotate;
int flag=1;

void init(void)
{
    glClearColor(0,0,0,0);    //give background colour to our window
    //0 0 0 0 is black
}

void display()
{
    glMatrixMode(GL_MODELVIEW);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
        glTranslatef(0.0,0.0,-10.5);
    //glPointSize(10.0);                     mostly float not needed now
    //glColor3f(1.0,0.0,0.0,0.0);
    //cannot write transformation function in gl_begin

    glRotatef(xRotate,1.0,0.0,0.0);
    glRotatef(yRotate,0.0,1.0,0.0);
    glRotatef(zRotate,0.0,0.0,1.0);
    glScalef(1.40,1.40,1.40);

    glBegin(GL_QUADS);  //beginning to start polygon

    glColor3f(0.0f,1.0f,0.0f);
    glVertex3f( 1.0f,1.0f,-1.0f);
    glVertex3f(-1.0f,1.0f,-1.0f);
    glVertex3f(-1.0f,1.0f, 1.0f);
    glVertex3f( 1.0f,1.0f, 1.0f);

    glColor3f(1.0f,0.5f,0.0f);
    glVertex3f(1.0f,-1.0f,-1.0f);
    glVertex3f(-1.0f,-1.0f,-1.0f);
    glVertex3f(-1.0f,-1.0f,1.0f);
    glVertex3f(1.0f,-1.0f,1.0f);

    glColor3f(1.0f,0.0f,0.0f);
    glVertex3f( 1.0f, 1.0f,1.0f);
    glVertex3f(-1.0f, 1.0f,1.0f);
    glVertex3f(-1.0f,-1.0f,1.0f);
    glVertex3f( 1.0f,-1.0f,1.0f);

    glColor3f(1.0f,1.0f,0.0f);
    glVertex3f( 1.0f, 1.0f,-1.0f);
    glVertex3f(-1.0f, 1.0f,-1.0f);
    glVertex3f(-1.0f,-1.0f,-1.0f);
    glVertex3f( 1.0f,-1.0f,-1.0f);

    glColor3f( 0.0f, 0.0f, 1.0f);
    glVertex3f(-1.0f,1.0f,-1.0f);
    glVertex3f(-1.0f,1.0f,-1.0f);
    glVertex3f(-1.0f,1.0f,1.0f);
    glVertex3f(-1.0f,1.0f,1.0f);

    glColor3f(1.0f,0.0f,1.0f);
    glVertex3f(1.0f,1.0f,-1.0f);
    glVertex3f(1.0f,1.0f,1.0f);
    glVertex3f(1.0f,-1.0f,1.0f);
    glVertex3f(1.0f,-1.0f,-1.0f);
    glEnd();

    //glBegin(GL_TRIANGLES);
    //glColor3f(1.0,0.0,1.0);
    //glVertex2f(x_position+25,200);
    //glColor3f(1.0,0.0,0.0);
    //glVertex2f(x_position+75,300);
    //glColor3f(0.0,1.0,0.0);
    //glVertex2f(x_position+100,200);
    //glEnd();

    glFlush();
}
void reshape(int x,int y)
{
    if(x==0 || y==0) return;
    glViewport(0,0,x,y);            //use whole window

    glMatrixMode(GL_PROJECTION);    //clear projection matrix
    glLoadIdentity();

    //gluOrtho2D(0,500,0,500);             //2D orthogonal projection
    gluPerspective(40.0,(GLdouble)x/(GLdouble)y,0.5,20.0);
    glMatrixMode(GL_MODELVIEW);
    glViewport(0,0,x,y);
}

void animation()
{

    glutPostRedisplay();
    yRotate+=0.01;
    xRotate+=0.02;
    display();
}
int main(int argc,char** argv){
    //initialize communication in window and appearance

    glutInit(&argc,argv);     //initialize glut functions and glut library

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);  //glut_single for simple models and rgb is color model

    glutInitWindowPosition(0,0);
    glutInitWindowSize(100,100);

    glutCreateWindow("window ");
    glutDisplayFunc(display);

    glutReshapeFunc(reshape);           //viewport

    glutIdleFunc(animation);  //set animation

    init();  //hold output on screen
    glutMainLoop();
    return 0;

}





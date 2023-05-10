/*#define GLUT_DISABLE_ATEXIT_HACK
#include <windows.h>
#include <GL\glut.h>

void init(void)
{
    //glClearColor(0.0,0.0,0.0,1.0);
    //glMatrixMode(GL_PROJECTION);
    //gluOrtho2D(0.0,500.0,0.0,500.0);
}
void pixel(){
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    //glColor3f(0.0,1.0,0.0);
    glPointSize(10.0);
    glBegin(GL_POINT);
        glVertex2f(100,100);
    glEnd();
    glFlush();
}
int main(int argc,char ** argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(500,500);
    glutCreateWindow("first opengl");
    glutDisplayFunc(pixel);
    init();
    glutMainLoop();
    return 0;
}
*/

#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>

void display();

void init()
{
    glClearColor(0.0,1.0,1.0,1.0);
}
void reshape(int w,int h)
{
    glViewport(0,0,(GLsizei)w,(GLsizei)h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();  //after matrix

    gluOrtho2D(-10,10,-10,10);
    glMatrixMode(GL_MODELVIEW);
    /*  glPointSize(10.0);
        glBegin(GL_POINTS);
        glVertex2f(5,5);
        glVertex2f(-5,-5);
        glEnd();
        glFlush();             */
}
int main(int argc,char**argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB);

    glutInitWindowPosition(200,100);
    glutInitWindowSize(500,500);

    //glutDisplayFunc(display);    wrong do after window creation

    glutCreateWindow("window1");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    init();
    glutMainLoop();
    //return 0;
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();  //resets matrix in all transpormation


    glBegin(GL_POLYGON);

    glVertex2f(0.0,5.0);
    glVertex2f(4.0,-3.0);
    glVertex2f(-4.0,-3.0);

    glEnd();
    glFlush();
}


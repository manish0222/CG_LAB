#include <iostream>
#define GLUT_DISABLE_ATEXIT_HACK
#include <windows.h>
#include <GL/glut.h>
using namespace std;

int main(int argc,char** argv)
{
    glutInit(&argc,argv)   //initialise glut
    glutInitWindowPosition(50,100);        //set top left display window position
    glutInitWindowSize(500,500);   //set width and height of window
    glutCreateWindow("fisrtopengl");
    return 0;
}

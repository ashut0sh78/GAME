#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include"hplpf.h"
#include<stdlib.h>
#define COLUMNS 70
#define ROWS 70
#define FPS 10
bool gameOver=false;
extern short sDirection;
int score=0;
void display();
void keyboard(int, int, int);
void reshape(int, int);
void timer_callback(int);
void init()
{
    glClearColor(1.0,1.0,0.0,1.0);
    initGrid(COLUMNS,ROWS);
}
int main(int argc, char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB| GLUT_DOUBLE);
    glutInitWindowSize(700,700);
    glutCreateWindow("SLYTHRIN");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(0,timer_callback,0);
    glutSpecialFunc(keyboard);
    init();
    glutMainLoop();
    return 0;
}
int index=0;
void display()
{
 glClear(GL_COLOR_BUFFER_BIT);
 drawGrid();
 drawSnape();
 drawFood();
 glutSwapBuffers();
 if(gameOver)
 {
     char _s[10];
     itoa(score,_s,10);
     char ans[50]="Your Score: ";
     strcat(ans,_s);
     MessageBox(NULL,ans,"GAME OVER",0);
     exit(0);
 }
}
void reshape(int w, int h)
{
    glViewport(0,0,(GLsizei)w,(GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0,COLUMNS,0.0,ROWS,-1.0,1.0);
    glMatrixMode(GL_MODELVIEW);
}
void timer_callback(int)
{
    glutPostRedisplay();
    glutTimerFunc(1000/FPS,timer_callback,0);
}
void keyboard(int key, int , int)
{
   switch(key)
   {

   case GLUT_KEY_UP:
    if(sDirection!=DOWN)
        sDirection=UP;
    break;
    case GLUT_KEY_DOWN:
     if(sDirection!=UP)
        sDirection=DOWN;
    break;
    case GLUT_KEY_RIGHT:
     if(sDirection!=LEFT)
        sDirection=RIGHT;
    break;
    case GLUT_KEY_LEFT:
     if(sDirection!=RIGHT)
        sDirection=LEFT;
    break;

   }
}

#include "openGL_Widget.h"
#include <GL/glu.h>
#include <QColorDialog>
#include<QMouseEvent>

#include<fstream>
using namespace std;
openGL_Widget::openGL_Widget(QWidget *parent) :
    QGLWidget(parent)
{
    setFormat(QGLFormat(QGL::DoubleBuffer|QGL::DepthBuffer));

 nSca=-50.0;
}

void openGL_Widget::initializeGL(){
    qglClearColor(Qt::gray);
    glEnable(GL_LIGHTING);
         // двухсторонний расчет освещения
         glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
         // автоматическое приведение нормалей к
         // единичной длине
         glEnable(GL_NORMALIZE);
    glShadeModel(GL_FLAT);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glEnable (GL_COLOR_MATERIAL);}

void openGL_Widget::paintGL(){
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT); // чистим буфер

if(f!=NULL){
    draw(f);
}

}

void openGL_Widget::resizeGL(int w, int h){
    //Устанавливаем точку обзора. Последние два параметры одинаковы -
    // чтобы не нарушать пропорции у широких экранов
    glViewport(0, 0, w, h);
    //Устанавливаем режим матрицы
    glMatrixMode(GL_PROJECTION);
    //Загружаем матрицу
    glLoadIdentity();
    GLfloat x=GLfloat(w)/h;
    glFrustum(-x,x,-1.0,1.0,3.0,500.0);
    glMatrixMode(GL_MODELVIEW);
}
void openGL_Widget::draw(QString f){
filen=f.toLocal8Bit().data();
    fstream file(filen, ios::in | ios::binary);
    GLfloat light0_diffuse[] = {1.0, 1.0, 1.0};
                GLfloat light0_direction[] = {0.0, 0.0, 2.0, 0.0};
                glEnable(GL_LIGHT0);
                glLightfv(GL_LIGHT0, GL_DIFFUSE, light0_diffuse);
                glLightfv(GL_LIGHT0, GL_POSITION, light0_direction);
    unsigned char header[80];
    int kol;
short int r;
    file.read((char*)&header, sizeof(header));
    file.read((char*)&kol,sizeof(kol));
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glScalef(0.2, 0.2, 0.2);
    glTranslatef(0.0,0.0,nSca);

    glRotatef(posX,1.0,0.0,0.0);
    glRotatef(posY,0.0,1.0,0.0);
    glRotatef(posY,0.0,0.0,1.0);

        for(int i=0;i<kol;i++){
            float vn1,vn2,vn3,vt1,vt2,vt3;
    file.read((char*)&vn1,sizeof(vn1));
    file.read((char*)&vn2,sizeof(vn2));
    file.read((char*)&vn3,sizeof(vn3));
        glLoadName(i);
        glBegin(GL_TRIANGLES);


        for(int j=0;j<3;j++){


            file.read((char*)&vt1,sizeof(vt1));
            file.read((char*)&vt2,sizeof(vt2));
            file.read((char*)&vt3,sizeof(vt3));
            glVertex3f(vt1,vt2,vt3);

       }
         glNormal3f(vn1,vn2,vn3);
       file.read((char*)&r,sizeof(r));
       glColor4ubv((GLubyte *)&r);
        glEnd();
    }


}
void openGL_Widget::mousePressEvent(QMouseEvent *event){
    lastPos=event->pos();
}
void openGL_Widget::mouseMoveEvent(QMouseEvent *event){
    GLfloat dx=GLfloat(event->x()-lastPos.x())/width();
     GLfloat dy=GLfloat(event->y()-lastPos.y())/height();
     if(event->buttons()&Qt::LeftButton){
         posX+=180*dy;
         posY+=180*dx;
         updateGL();
     }
     if(event->buttons()&Qt::RightButton){

     }
     lastPos=event->pos();
}
/*virtual*/void openGL_Widget::wheelEvent(QWheelEvent* pe)
{
   if ((pe->delta())>0) scale_plus(); else if ((pe->delta())<0) scale_minus();

   updateGL(); // обновление изображения
}
void openGL_Widget::scale_plus() // приблизить сцену
{
   nSca = nSca*1.1;
}

void openGL_Widget::scale_minus() // удалиться от сцены
{
   nSca = nSca/1.1;
}

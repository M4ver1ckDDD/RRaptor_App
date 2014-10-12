#ifndef OPENGL_WIDGET_H
#define OPENGL_WIDGET_H

#include <QGLWidget>
#include <GL/glu.h>
class openGL_Widget : public QGLWidget
{
    Q_OBJECT
public:
    explicit openGL_Widget(QWidget *parent = 0);
QString f;
void skrolling(float t){
    posX+=180*t;
    posY+=180*t;
    updateGL();
}

protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void wheelEvent(QWheelEvent* pe);

private:
    void draw(QString f);
    void scale_plus();     // приблизить сцену
          void scale_minus();    // удалиться от сцены
     GLfloat nSca;
    GLfloat posX;
    GLfloat posY;
    GLfloat posZ;

    QPoint lastPos;
   char *filen;
};



#endif // GLWIDGET_H

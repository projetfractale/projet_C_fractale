#ifndef FENETREMANDELBROT_H
#define FENETREMANDELBROT_H

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPixmap>
#include <QPainter>
#include <QPen>
#include <QMouseEvent>
#include <QEvent>
#include <QPoint>
#include "moninterfacegraphique.h"
#include "math.h"

class fenetremandelbrot : public QWidget
{
    Q_OBJECT
public:
    explicit fenetremandelbrot(QWidget *parent = 0);

    moninterfacegraphique* getView();
    QGraphicsScene* getScene();
    QPixmap getPixmap();


signals:


public slots:
    void zoom(int, int, int, int );


protected:
    QGraphicsScene *scene;
    moninterfacegraphique *view;
    QPixmap pixmap;
    int inter1;
    int inter2;
    int inter3;
    int inter4;


};

#endif // FENETREMANDELBROT_H

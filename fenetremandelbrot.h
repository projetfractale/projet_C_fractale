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
    ~fenetremandelbrot();
    QGraphicsView* getView();
    QGraphicsScene* getScene();
    QPixmap getPixmap();


signals:
    void click(const QPoint&);
    void clickdrag(int,int,int,int);

public slots:
    void zoom(int, int, int, int );
    void intermediaire(const QPoint&);

protected:
    QGraphicsScene *scene;
    QGraphicsView *view;
    QPixmap pixmap;
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseReleaseEvent(QMouseEvent *event);
    int inter1;
    int inter2;
    int inter3;
    int inter4;


};

#endif // FENETREMANDELBROT_H

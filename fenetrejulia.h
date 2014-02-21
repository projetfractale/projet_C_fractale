#ifndef FENETREJULIA_H
#define FENETREJULIA_H

#include <QLCDNumber>
#include <QSlider>
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
#include <QGridLayout>
#include <QGraphicsPixmapItem>

class fenetrejulia : public QWidget
{
    Q_OBJECT
public:
    explicit fenetrejulia(QWidget *parent = 0);
    QGraphicsView* getView();
    QGraphicsScene* getScene();
    QPixmap getPixmap();
    QSlider* getSliderV();
    QSlider* getSliderH();
    QLCDNumber* getboxV();
    QLCDNumber* getboxH();


signals:

public slots:
    void changerCompteurH(int);
    void changerCompteurV(int);
    void change_view_selon_X(int);
    void change_view_selon_Y(int);

protected:
    QGraphicsScene *scene;
    QGraphicsView *view;
    QPixmap pixmap;
    QSlider *sliderH;
    QSlider *sliderV;
    QLCDNumber *BoxH;
    QLCDNumber *BoxV;
    int x;
    int y;

};

#endif // FENETREJULIA_H


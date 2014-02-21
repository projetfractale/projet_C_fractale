#ifndef FENETREBUDDHA_H
#define FENETREBUDDHA_H

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPixmap>
#include <QPainter>
#include <QPen>
#include <QMouseEvent>
#include <QEvent>
#include <QPoint>

class fenetrebuddha : public QWidget
{
    Q_OBJECT
public:
    explicit fenetrebuddha(QWidget *parent = 0);
    QGraphicsView* getView();
    QGraphicsScene* getScene();
    QPixmap getPixmap();

signals:

public slots:

protected:
    QGraphicsScene *scene;
    QGraphicsView *view;
    QPixmap pixmap;

};

#endif // FENETREBUDDHA_H

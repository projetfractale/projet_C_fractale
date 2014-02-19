#ifndef MONINTERFACEGRAPHIQUE_H
#define MONINTERFACEGRAPHIQUE_H
#include <QMouseEvent>
#include <QEvent>
#include <QPoint>
#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>

class moninterfacegraphique : public QGraphicsView
{
    Q_OBJECT
public:
    explicit moninterfacegraphique(QWidget *parent = 0);
    int getinter1();
    int getinter2();
    int getinter3();
    int getinter4();

signals:
    void click_view(const QPoint&);
    void clickdrag_view(int,int,int,int);

public slots:
    void intermediaire_view(const QPoint&);

protected:
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseReleaseEvent(QMouseEvent *event);
    int inter1_view;
    int inter2_view;
    int inter3_view;
    int inter4_view;


};

#endif // MONINTERFACEGRAPHIQUE_H

#include "moninterfacegraphique.h"

moninterfacegraphique::moninterfacegraphique(QWidget *parent) :
    QGraphicsView(parent),
{
    QObject::connect(this,SIGNAL(click_view(const QPoint&)),this,SLOT(intermediaire(const QPoint&)));
}

void moninterfacegraphique::mousePressEvent(QMouseEvent *event)
{
    const QPoint p = event->pos();
    emit click_view(p);
}

void moninterfacegraphique::mouseReleaseEvent(QMouseEvent *event)
{
    const QPoint p = event->pos();
    inter3_view = p.x();
    inter4_view = p.y();
    emit clickdrag_view(inter1_view,inter2_view,inter3_view,inter4_view);

}

void moninterfacegraphique::intermediaire_view(const QPoint &cible)
{
    inter1_view = cible.x();
    inter2_view = cible.y();
}

int moninterfacegraphique::getinter1()
{
    return inter1_view;
}

int moninterfacegraphique::getinter2()
{
    return inter2_view;
}

int moninterfacegraphique::getinter3()
{
    return inter3_view;
}

int moninterfacegraphique::getinter4()
{
    return inter4_view;
}

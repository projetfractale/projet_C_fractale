#include "fenetrebuddha.h"

fenetrebuddha::fenetrebuddha(QWidget *parent) :
    QWidget(parent), pixmap(1200,1200)
{
    setFixedSize(1100,650);
    QGraphicsScene *scene = new QGraphicsScene();
    QGraphicsView *view = new QGraphicsView(scene,this);
    for (int i=-600;i<=600;i++)  //on commence par un carré
    {
        for (int j=-600;j<=600;j++)
        {
            int iteration_max = 25;
            int pixel_x=0;
            int pixel_y=0;
            double x=0;
            double y=0;
            double a=0;
            int h=0;
            int dummy=0;
            double liste_buddha_x[25]={0};  //ici 25 est l'itération maximale
            double liste_buddha_y[25]={0};
            while (h<iteration_max && x*x+y*y<4)
            {
                a=x;
                x=x*x-y*y+((double)i)/300;
                y=2*a*y+((double)j)/300;
                liste_buddha_x[h]=x;
                liste_buddha_y[h]=y;
                h++;
            }
            if (h<iteration_max)
            {
                for (int k=0; k<=h;k++)
                {
                    QPainter *p_fractale_3 = new QPainter(&pixmap);
                    p_fractale_3->setPen(QPen(Qt::black));
                    pixel_x=300*liste_buddha_x[k]+600;
                    pixel_y=300*liste_buddha_y[k]+600;
                    p_fractale_3->drawPoint(pixel_x,pixel_y);
                    delete p_fractale_3;
                }
            }
            else
            {
                dummy=1;
            }
        }
    }
    scene->addPixmap(pixmap);
    view->move(10,10);
}

QPixmap fenetrebuddha::getPixmap()
{
    return pixmap;
}

QGraphicsScene* fenetrebuddha::getScene()
{
    return scene;
}

QGraphicsView* fenetrebuddha::getView()
{
    return view;
}

#include "fenetremandelbrot.h"

fenetremandelbrot::fenetremandelbrot(QWidget *parent) :
    QWidget(parent) , pixmap(1200,1200)
{
    inter1 = 0;
    inter2 = 0;
    inter3 = 0;
    inter4 = 0;
    setFixedSize(1100,650);
    QGraphicsScene *scene = new QGraphicsScene();
    //moninterfacegraphique *view = new moninterfacegraphique(scene,this);
    QGraphicsView *view = new QGraphicsView(scene,this);
    QPainter *p_fractale = new QPainter(&pixmap);
    //le compteur est initialisé à 0. Il va servir à l'it_max
    int a[2];
    int c[2];
    a[0]=0;
    a[1]=0;
    c[0]=1200;
    c[1]=1200; // On commence par le carré classique
    vector<vector<int> > mandelbrot = Mandelbrot(100, a, c); //ici l'iteration max est 100.
    int compteur = 0;
    while (compteur<1200*1200)
    {
        if (mandelbrot[compteur][2]==100) //100 est l'iteration max ici
        {
            p_fractale->setPen(QPen(Qt::black));
            p_fractale->drawPoint(mandelbrot[compteur][0],mandelbrot[compteur][1]);
        }
        if (1<=mandelbrot[compteur][2] && mandelbrot[compteur][2]<15)
        {
            p_fractale->setPen(QPen(Qt::darkBlue));
            p_fractale->drawPoint(mandelbrot[compteur][0],mandelbrot[compteur][1]);
        }
        if (15<=mandelbrot[compteur][2] && mandelbrot[compteur][2]<30)
        {
            p_fractale->setPen(QPen(Qt::blue));
            p_fractale->drawPoint(mandelbrot[compteur][0],mandelbrot[compteur][1]);
        }
        if (30<=mandelbrot[compteur][2] && mandelbrot[compteur][2]<45)
        {
            p_fractale->setPen(QPen(Qt::darkCyan));
            p_fractale->drawPoint(mandelbrot[compteur][0],mandelbrot[compteur][1]);
        }
        if (45<=mandelbrot[compteur][2] && mandelbrot[compteur][2]<100)
        {
            p_fractale->setPen(QPen(Qt::cyan));
            p_fractale->drawPoint(mandelbrot[compteur][0],mandelbrot[compteur][1]);
        }
        compteur++;
    }
    delete p_fractale;
    scene->addPixmap(pixmap);
    view->move(10,10);
    QObject::connect(this,SIGNAL(click_view(const QPoint&)),view,SLOT(intermediaire_view(const QPoint&))); //Si je mets this à la place de view en premiere instance alors j'utilise la librairie classique et alors le zoom se fera sur la fentre et non sur le view
    QObject::connect(this,SIGNAL(clickdrag_view(int,int,int,int)),this,SLOT(zoom(int,int,int,int)));
}

fenetremandelbrot::~fenetremandelbrot()
{
    delete view;
    delete scene;
}

QPixmap fenetremandelbrot::getPixmap()
{
    return pixmap;
}

QGraphicsScene* fenetremandelbrot::getScene()
{
    return scene;
}

QGraphicsView* fenetremandelbrot::getView()
{
    return view;
}

void fenetremandelbrot::zoom(int a0,int a1,int c0,int c1)
{
    QPainter *p_fractale_zoom = new QPainter(&pixmap);
    int a[2];
    a[0]=a0;
    a[1]=a1;
    int c[2];
    c[0]=c0;
    c[1]=c1;
    //le compteur est initialisé à 0. Il va servir à l'it_max
    vector<vector<int> > mandelbrot = Mandelbrot(100, a, c); //ici l'iteration max est 100.
    int compteur = 0;
    while (compteur<1200*1200)
    {
        if (mandelbrot[compteur][2]==100) //100 est l'iteration max ici
        {
            p_fractale_zoom->setPen(QPen(Qt::black));
            p_fractale_zoom->drawPoint(mandelbrot[compteur][0],mandelbrot[compteur][1]);
        }
        if (1<=mandelbrot[compteur][2] && mandelbrot[compteur][2]<15)
        {
            p_fractale_zoom->setPen(QPen(Qt::darkBlue));
            p_fractale_zoom->drawPoint(mandelbrot[compteur][0],mandelbrot[compteur][1]);
        }
        if (15<=mandelbrot[compteur][2] && mandelbrot[compteur][2]<30)
        {
            p_fractale_zoom->setPen(QPen(Qt::blue));
            p_fractale_zoom->drawPoint(mandelbrot[compteur][0],mandelbrot[compteur][1]);
        }
        if (30<=mandelbrot[compteur][2] && mandelbrot[compteur][2]<45)
        {
            p_fractale_zoom->setPen(QPen(Qt::darkCyan));
            p_fractale_zoom->drawPoint(mandelbrot[compteur][0],mandelbrot[compteur][1]);
        }
        if (45<=mandelbrot[compteur][2] && mandelbrot[compteur][2]<100)
        {
            p_fractale_zoom->setPen(QPen(Qt::cyan));
            p_fractale_zoom->drawPoint(mandelbrot[compteur][0],mandelbrot[compteur][1]);
        }
        compteur++;
    }
    delete p_fractale_zoom;
}

void fenetremandelbrot::mousePressEvent(QMouseEvent *event)
{
    const QPoint p = event->pos();
    emit click(p);
}

void fenetremandelbrot::mouseReleaseEvent(QMouseEvent *event)
{
    const QPoint p = event->pos();
    inter3 = p.x();
    inter4 = p.y();
    emit clickdrag(inter1,inter2,inter3,inter4);

}

void fenetremandelbrot::intermediaire(const QPoint &cible)
{
    inter1 = cible.x();
    inter2 = cible.y();
}

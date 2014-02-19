#include "fenetrejulia.h"

fenetrejulia::fenetrejulia(QWidget *parent) :
    QWidget(parent) , pixmap(1200,1200)
{
    inter1 = 0;
    inter2 = 0;
    inter3 = 0;
    inter4 = 0;
    setFixedSize(1100,650);
    QGraphicsScene *scene = new QGraphicsScene();
    moninterfacegraphique *view = new moninterfacegraphique(scene,this);
    QPainter *p_fractale = new QPainter(&pixmap);
    //le compteur est initialisé à 0. Il va servir à l'it_max
    int a[2];
    int c[2];
    int b[2];
    a[0]=0;
    a[1]=0;
    c[0]=1200;
    c[1]=1200; // On commence par le carré classique
    b[0]=620;
    b[1]=610;
    vector<vector<int> > julia = Julia(100, a, c, b); //ici l'iteration max est 100.
    int compteur = 0;
    while (compteur<1200*1200)
    {
        if (julia[compteur][2]==100) //100 est l'iteration max ici
        {
            p_fractale->setPen(QPen(Qt::black));
            p_fractale->drawPoint(julia[compteur][0],julia[compteur][1]);
        }
        if (1<=julia[compteur][2] && julia[compteur][2]<15)
        {
            p_fractale->setPen(QPen(Qt::darkBlue));
            p_fractale->drawPoint(julia[compteur][0],julia[compteur][1]);
        }
        if (15<=julia[compteur][2] && julia[compteur][2]<30)
        {
            p_fractale->setPen(QPen(Qt::blue));
            p_fractale->drawPoint(julia[compteur][0],julia[compteur][1]);
        }
        if (30<=julia[compteur][2] && julia[compteur][2]<45)
        {
            p_fractale->setPen(QPen(Qt::darkCyan));
            p_fractale->drawPoint(julia[compteur][0],julia[compteur][1]);
        }
        if (45<=julia[compteur][2] && julia[compteur][2]<100)
        {
            p_fractale->setPen(QPen(Qt::cyan));
            p_fractale->drawPoint(julia[compteur][0],julia[compteur][1]);
        }
        compteur++;
    }
    delete p_fractale;
    scene->addPixmap(pixmap);
    view->move(10,10);
    QObject::connect(view,SIGNAL(click_view(const QPoint&)),view,SLOT(intermediaire_view(const QPoint&)));
    QObject::connect(view,SIGNAL(clickdrag_view(int,int,int,int)),this,SLOT(zoom(int,int,int,int)));
}

fenetrejulia::~fenetrejulia()
{
    delete view;
    delete scene;
}

QPixmap fenetrejulia::getPixmap()
{
    return pixmap;
}

QGraphicsScene* fenetrejulia::getScene()
{
    return scene;
}

QGraphicsView* fenetrejulia::getView()
{
    return view;
}

void fenetrejulia::zoom(int a0,int a1,int c0,int c1)
{
    QPainter *p_fractale_zoom = new QPainter(&pixmap);
    int a[2];
    a[0]=a0;
    a[1]=a1;
    int c[2];
    c[0]=c0;
    c[1]=c1;
    //le compteur est initialisé à 0. Il va servir à l'it_max
    vector<vector<int> > julia = Julia(100, a, c, b); //ici l'iteration max est 100.
    int compteur = 0;
    while (compteur<1200*1200)
    {
        if (julia[compteur][2]==100) //100 est l'iteration max ici
        {
            p_fractale_zoom->setPen(QPen(Qt::black));
            p_fractale_zoom->drawPoint(julia[compteur][0],julia[compteur][1]);
        }
        if (1<=julia[compteur][2] && julia[compteur][2]<15)
        {
            p_fractale_zoom->setPen(QPen(Qt::darkBlue));
            p_fractale_zoom->drawPoint(julia[compteur][0],julia[compteur][1]);
        }
        if (15<=julia[compteur][2] && julia[compteur][2]<30)
        {
            p_fractale_zoom->setPen(QPen(Qt::blue));
            p_fractale_zoom->drawPoint(julia[compteur][0],julia[compteur][1]);
        }
        if (30<=julia[compteur][2] && julia[compteur][2]<45)
        {
            p_fractale_zoom->setPen(QPen(Qt::darkCyan));
            p_fractale_zoom->drawPoint(julia[compteur][0],julia[compteur][1]);
        }
        if (45<=julia[compteur][2] && julia[compteur][2]<100)
        {
            p_fractale_zoom->setPen(QPen(Qt::cyan));
            p_fractale_zoom->drawPoint(julia[compteur][0],julia[compteur][1]);
        }
        compteur++;
    }
    delete p_fractale_zoom;
}

void fenetrejulia::mousePressEvent(QMouseEvent *event)
{
    const QPoint p = event->pos();
    emit click(p);
}

void fenetrejulia::mouseReleaseEvent(QMouseEvent *event)
{
    const QPoint p = event->pos();
    inter3 = p.x();
    inter4 = p.y();
    emit clickdrag(inter1,inter2,inter3,inter4);

}

void fenetrejulia::intermediaire(const QPoint &cible)
{
    inter1 = cible.x();
    inter2 = cible.y();
}



//sliders



julia::julia(double reel,double im) : fractale()
{
    c_real = reel;
    c_im = im;
    QSlider *sliderV = new QSlider(Qt::Vertical,this);
    QSlider *sliderH = new QSlider(Qt::Horizontal,this);

    sliderH->setRange(0,1200);

    sliderV->setRange(0,1200);

    QLCDNumber *BoxH = new QLCDNumber(3,this);
    QLCDNumber *BoxV = new QLCDNumber(3,this);

    BoxH->display(-2);
    BoxV->display(2);

    QObject::connect(sliderH,SIGNAL(valueChanged(int)),this,SLOT(changerCompteurH(int)));
    QObject::connect(sliderV,SIGNAL(valueChanged(int)),this,SLOT(changerCompteurV(int)));
}

julia::~julia()
{
    delete BoxH;
    delete BoxV;
    delete sliderH;
    delete sliderV;
}

void julia::changerCompteurH(int horiz)
{
    double horiz_help = ((double)horiz/300)-2;
    BoxH->display(horiz_help);
}

void julia::changerCompteurV(int vertic)
{
    double vertic_help = 2-((double)vertic/300);
    BoxV->display(vertic_help);
}

QSlider* julia::getSliderH()
{
    return sliderH;
}

QSlider* julia::getSliderV()
{
    return sliderV;
}
QLCDNumber* julia::getboxH()
{
    return BoxH;
}

QLCDNumber* julia::getboxV()
{
    return BoxV;
}

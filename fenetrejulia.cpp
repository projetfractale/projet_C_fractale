#include "fenetrejulia.h"

fenetrejulia::fenetrejulia(QWidget *parent) :
    QWidget(parent) , pixmap(1200,1200)
{

    x = 0;
    y = 0;

    setFixedSize(1100,650);

    QSlider *sliderV = new QSlider(Qt::Vertical,this);
    QSlider *sliderH = new QSlider(Qt::Horizontal,this);

    sliderH->setRange(0,1200);

    sliderV->setRange(0,1200);

    QLCDNumber *BoxH = new QLCDNumber(3,this);
    QLCDNumber *BoxV = new QLCDNumber(3,this);

    BoxH->display(0);
    BoxV->display(0);


    QGraphicsScene *scene = new QGraphicsScene();
    QGraphicsView *view = new QGraphicsView(scene,this);


    QPainter *p_fractale = new QPainter(&pixmap);
    //le compteur est initialisé à 0. Il va servir à l'it_max
    int a[2];
    int c[2];
    int b[2];
    a[0]=0;
    a[1]=0;
    c[0]=1200;
    c[1]=1200; // On commence par le carré classique
    b[0]=x;
    b[1]=y; //On démarre avec un choix par défaut qui correspond à ce point ci (0,0)
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

    view->move(40,40);
    sliderH->move(10,0);
    sliderV->move(0,10);
    BoxH->move(30,0);
    BoxV->move(0,30);


    QObject::connect(sliderH,SIGNAL(valueChanged(int)),BoxH,SLOT(display(int)));
    QObject::connect(sliderV,SIGNAL(valueChanged(int)),BoxV,SLOT(display(int)));
    QObject::connect(sliderH,SIGNAL(valueChanged(int)),this,SLOT(change_view_selon_X(int)));
    QObject::connect(sliderV,SIGNAL(valueChanged(int)),this,SLOT(change_view_selon_Y(int)));
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


void fenetrejulia::changerCompteurH(int horiz)
{
    double horiz_help = ((double)horiz/300)-2;
    this->getboxH()->display(horiz_help);
}

void fenetrejulia::changerCompteurV(int vertic)
{
    double vertic_help = 2-((double)vertic/300);
    this->getboxV()->display(vertic_help);
}

void fenetrejulia::change_view_selon_X(int nouveau_x)
{
    int b[2];
    int a[2];
    int c[2];
    b[0] = nouveau_x;
    b[1] = y;
    a[0]=0;
    a[1]=0;
    c[0]=1200;
    c[1]=1200;
    QPainter *p_fractale_X = new QPainter(&pixmap);
    vector<vector<int> > julia_X = Julia(100, a, c, b); //ici l'iteration max est 100.
    int compteur = 0;
    while (compteur<1200*1200)
    {
        if (julia_X[compteur][2]==100) //100 est l'iteration max ici
        {
            p_fractale_X->setPen(QPen(Qt::black));
            p_fractale_X->drawPoint(julia_X[compteur][0],julia_X[compteur][1]);
        }
        if (1<=julia_X[compteur][2] && julia_X[compteur][2]<15)
        {
            p_fractale_X->setPen(QPen(Qt::darkBlue));
            p_fractale_X->drawPoint(julia_X[compteur][0],julia_X[compteur][1]);
        }
        if (15<=julia_X[compteur][2] && julia_X[compteur][2]<30)
        {
            p_fractale_X->setPen(QPen(Qt::blue));
            p_fractale_X->drawPoint(julia_X[compteur][0],julia_X[compteur][1]);
        }
        if (30<=julia_X[compteur][2] && julia_X[compteur][2]<45)
        {
            p_fractale_X->setPen(QPen(Qt::darkCyan));
            p_fractale_X->drawPoint(julia_X[compteur][0],julia_X[compteur][1]);
        }
        if (45<=julia_X[compteur][2] && julia_X[compteur][2]<100)
        {
            p_fractale_X->setPen(QPen(Qt::cyan));
            p_fractale_X->drawPoint(julia_X[compteur][0],julia_X[compteur][1]);
        }
        compteur++;
    }
    delete p_fractale_X;
    scene->clear();
    scene->addPixmap(pixmap);

}

void fenetrejulia::change_view_selon_Y(int nouveau_y)
{
    int b[2];
    int a[2];
    int c[2];
    b[0] = x;
    b[1] = nouveau_y;
    a[0]=0;
    a[1]=0;
    c[0]=1200;
    c[1]=1200;
    QPainter *p_fractale_Y = new QPainter(&pixmap);
    vector<vector<int> > julia_Y = Julia(100, a, c, b); //ici l'iteration max est 100.
    int compteur = 0;
    while (compteur<1200*1200)
    {
        if (julia_Y[compteur][2]==100) //100 est l'iteration max ici
        {
            p_fractale_Y->setPen(QPen(Qt::black));
            p_fractale_Y->drawPoint(julia_Y[compteur][0],julia_Y[compteur][1]);
        }
        if (1<=julia_Y[compteur][2] && julia_Y[compteur][2]<15)
        {
            p_fractale_Y->setPen(QPen(Qt::darkBlue));
            p_fractale_Y->drawPoint(julia_Y[compteur][0],julia_Y[compteur][1]);
        }
        if (15<=julia_Y[compteur][2] && julia_Y[compteur][2]<30)
        {
            p_fractale_Y->setPen(QPen(Qt::blue));
            p_fractale_Y->drawPoint(julia_Y[compteur][0],julia_Y[compteur][1]);
        }
        if (30<=julia_Y[compteur][2] && julia_Y[compteur][2]<45)
        {
            p_fractale_Y->setPen(QPen(Qt::darkCyan));
            p_fractale_Y->drawPoint(julia_Y[compteur][0],julia_Y[compteur][1]);
        }
        if (45<=julia_Y[compteur][2] && julia_Y[compteur][2]<100)
        {
            p_fractale_Y->setPen(QPen(Qt::cyan));
            p_fractale_Y->drawPoint(julia_Y[compteur][0],julia_Y[compteur][1]);
        }
        compteur++;
    }
    delete p_fractale_Y;
    //scene->addPixmap(pixmap)->setPixmap(pixmap);
    scene->clear();
    scene->addPixmap(pixmap);


}

QSlider* fenetrejulia::getSliderH()
{
    return sliderH;
}

QSlider* fenetrejulia::getSliderV()
{
    return sliderV;
}
QLCDNumber* fenetrejulia::getboxH()
{
    return BoxH;
}

QLCDNumber* fenetrejulia::getboxV()
{
    return BoxV;
}

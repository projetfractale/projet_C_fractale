#include <QApplication>
#include <QImage>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QPixmap>
#include <QPainter>
#include <QPen>

#include "fenetremandelbrot.h"
#include "fenetrejulia.h"
#include "fenetrebuddha.h"

int main(int argc,char *argv[])
{
    QApplication app(argc,argv);

    fenetremandelbrot essai;
    essai.show();

    return app.exec();
}

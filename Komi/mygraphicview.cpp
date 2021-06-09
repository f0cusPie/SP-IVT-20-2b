#include "mygraphicview.h"


MyPoint::MyPoint(QObject *parent)
    : QObject(parent), QGraphicsItem()
{

}

MyPoint::~MyPoint()
{

}
QRectF MyPoint::boundingRect() const
{
    return QRectF(0,0,100,100);
}
void MyPoint::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    int x1 = -70, y1 = 135, x2 = 70, y2 = 145, x3 = 0, y3 = -165, x4 = 240, y4 = 15, x5 = -160, y5 = -15, x6 = -200, y6 = -145, x7 = 140 , y7 = -95;

    painter->setBrush(Qt::green);
    painter->drawLine(x1+25, y1+25, x5+25, y5+25);
    painter->drawLine(x1+25, y1+25, x2+25, y2+25);
    painter->drawLine(x4+25, y4+25, x2+25, y2+25);
    painter->drawLine(x4+25, y4+25, x7+25, y7+25);
    painter->drawLine(x6+25, y6+25, x5+25, y5+25);
    painter->drawLine(x6+25, y6+25, x3+25, y3+25);
    painter->drawLine(x2+25, y2+25, x3+25, y3+25);
    painter->drawLine(x2+25, y2+25, x1+25, y1+25);
    painter->drawLine(x5+25, y5+25, x7+25, y7+25);
    painter->drawLine(x3+25, y3+25, x7+25, y7+25);
    painter->drawEllipse(QRectF(x1, y1, 50, 50));
    painter->drawEllipse(QRectF(x2, y2, 50, 50));
    painter->drawEllipse(QRectF(x3, y3, 50, 50));
    painter->drawEllipse(QRectF(x4, y4, 50, 50));
    painter->drawEllipse(QRectF(x5, y5, 50, 50));
    painter->drawEllipse(QRectF(x6, y6, 50, 50));
    painter->drawEllipse(QRectF(x7, y7, 50, 50));
    painter->setPen(Qt::black);
    painter->drawText(x1+22, y1+28, "1");
    painter->drawText(x2+22, y2+28, "4");
    painter->drawText(x3+22, y3+28, "6");
    painter->drawText(x4+22, y4+28, "2");
    painter->drawText(x5+22, y5+28, "5");
    painter->drawText(x6+22, y6+28, "3");
    painter->drawText(x7+22, y7+28, "7");
    painter->setPen(Qt::gray);
    painter->drawText(((x1+x2)/2)+10,((y1+y2)/2)+10, "26");
    painter->drawText(((x1+x5)/2)+10,((y1+y5)/2)+10, "9");
    painter->drawText(((x5+x6)/2)+10,((y5+y6)/2)+10, "13");
    painter->drawText(((x6+x3)/2)+10,((y6+y3)/2)+10, "5");
    painter->drawText(((x3+x7)/2)+10,((y3+y7)/2)+10, "19");
    painter->drawText(((x7+x4)/2)+10,((y7+y4)/2)+10, "23");
    painter->drawText(((x4+x2)/2)+10,((y4+y2)/2)+10, "17");
    painter->drawText(((x3+x2)/2)+10,((y3+y2)/2)+20, "42");
    painter->drawText(((x5+x7)/2)+10,((y5+y7)/2)+10, "30");




        Q_UNUSED(option);
        Q_UNUSED(widget);
}

/* Переопределив метод перехвата события нажатия кнопки мыши,
 * добавляем посылку СИГНАЛА от объекта
 * */

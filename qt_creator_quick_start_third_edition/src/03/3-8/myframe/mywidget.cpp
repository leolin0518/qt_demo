#include "mywidget.h"
#include "ui_mywidget.h"
#include <QPixmap>
#include <QMovie>

MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);

    ui->frame->setFrameShape(QFrame::Box);
    ui->frame->setFrameShadow(QFrame::Sunken);
    // 以上两个函数可以使用setFrameStyle(QFrame::Box | QFrame::Sunken)代替
    ui->frame->setLineWidth(5);
    ui->frame->setMidLineWidth(10);

    QFont font;
    font.setFamily("华文行楷");
    font.setPointSize(20);
    font.setBold(true);
    font.setItalic(true);
    ui->label->setFont(font);

    QString string = tr("标题太长，需要进行省略xxxxxx！");
    QString str = ui->label->fontMetrics().elidedText(string, Qt::ElideRight, 180);
    ui->label->setText(str);

    //ui->label->setPixmap(QPixmap("D:/linbo/qt_creator_quick_book/src/03/3-8/logo.png"));
    //D:\linbo\qt_creator_quick_book\src\03\3-8

    QMovie *movie = new QMovie("D:/linbo/qt_creator_quick_book/src/03/3-8/donghua.gif");
    ui->label->setMovie(movie);                  // 在标签中添加动画
    movie->start();

}

MyWidget::~MyWidget()
{
    delete ui;
}

#include "manager.h"
#include "ui_manager.h"
#include "staticbutton.h"

Manager::Manager(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Manager)
{

    staticButton sb(":/image/close.png",true);
    sb.move(200,100);
    sb.setToolTip("hool");

}


Manager::~Manager()
{
    delete ui;
}


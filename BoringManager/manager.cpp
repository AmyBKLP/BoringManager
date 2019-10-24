#include "manager.h"
#include "ui_manager.h"

Manager::Manager(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Manager)
{


}


Manager::~Manager()
{
    delete ui;
}


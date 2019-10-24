#ifndef MANAGER_H
#define MANAGER_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class Manager; }
QT_END_NAMESPACE

class Manager : public QWidget
{
    Q_OBJECT

public:
    Manager(QWidget *parent = 0);
    ~Manager();


private:
    Ui::Manager *ui;


};
#endif // MANAGER_H

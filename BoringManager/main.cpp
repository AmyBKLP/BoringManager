#include "manager.h"
#include "pnglineedit.h"
#include <QApplication>


#include "userlogin.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
 //   Manager w;
 //   w.show();
 //   pngLineedit pl(":/image/person.png");
 //   pl.show();

    staticButton minbtn;
    //minbtn.setCursorEnabled(true);
    minbtn.setOneButtonInfo(":/main/min.png");

    minbtn.show();


  //minbtn->setOneButtonInfo(":/main/min.png");
//    userLogin ul;
//    ul.show();
    return a.exec();
}

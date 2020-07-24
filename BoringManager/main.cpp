#include "manager.h"
#include "pnglineedit.h"
#include "staticbutton.h"

#include <QApplication>


#include "userlogin.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Manager w;
    w.show();

 //   pngLineedit pl(":/image/person.png");
 //   pl.show();

  //  userLogin ul;
  //  ul.show();
  //  staticButton sb(":/image/close.png");
  //  sb.show();
    return a.exec();
}

#include <QDesktopWidget>
#include <QApplication>


#include "login.h"
 #include <QSound>

 
void center(QWidget &widget)
{
    int x, y;
    int screenWidth, screenHeight;

    int WIDTH = 600;
    int HEIGHT = 700;

    QDesktopWidget *desktop = QApplication::desktop();
    screenWidth = desktop->width();
    screenHeight = desktop->height();

    x = (screenWidth - WIDTH) / 2;
    y = (screenHeight - HEIGHT) / 2;
    widget.setGeometry(x, y, WIDTH, HEIGHT);
    widget.setFixedSize(WIDTH, HEIGHT);

}





int main(int argc, char *argv[])
{

    QApplication app(argc, argv);


    LogIn theGame;
   // if ((theGame.readDataBase())) ///first validate if information form db.txt is read well if it return true than create
   // {
    theGame.show();
 
    center(theGame);


    return app.exec();

    //}

}

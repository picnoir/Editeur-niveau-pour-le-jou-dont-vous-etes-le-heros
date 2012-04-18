#include "MainWindow.hpp"
#include <QtGui>
#include <QApplication>
int main(int argc, char** argv)
{
  QApplication app(argc,argv);
  QTextCodec::setCodecForCStrings(QTextCodec::codecForName("utf8"));
  MainWindow mainWindow;
  mainWindow.show();
  return app.exec();
}

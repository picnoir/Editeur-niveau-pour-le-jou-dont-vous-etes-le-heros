#ifndef MAINWINDOW
#define MAINWINDOW
#include <QMainWindow>
#include <QWidget>
class MainWindow:public QMainWindow
{
protected:
  QWidget* _centralWidget;

public:
  MainWindow();
  ~MainWindow();
};
#endif

#include "MainWindow.hpp"
#include "CentralWidget.hpp"
MainWindow::MainWindow()
{
  _centralWidget=new CentralWidget(this);
  setCentralWidget(_centralWidget);
}

MainWindow::~MainWindow()
{
  if(_centralWidget!=NULL)
    _centralWidget->deleteLater();
}

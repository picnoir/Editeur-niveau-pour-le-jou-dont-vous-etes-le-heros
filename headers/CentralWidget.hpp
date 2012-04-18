#include <QWidget>
#include <QList>
#include <QLineEdit>
#include <QTextEdit>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include "MainWindow.hpp"
class CentralWidget:public QWidget
{
  Q_OBJECT
protected:
  QTextEdit* _texte;
  QList<QTextEdit*> _textesEffets;
  QList<QLineEdit*> _textesBoutons;
  QList<QLineEdit*> _liens;
  QList<QLineEdit*> _cp;
  QList<QLineEdit*> _hp;
  QLabel* _lien;
  QLabel* _text;
  QLabel* _textBouton;
  QLabel* _textEffect;
  QLabel* _hpl;
  QLabel* _cpl;
  QLabel* _nomFichier;
  QLineEdit* _nom;
  QGridLayout* _layout;
  MainWindow* _mainWindowPtr;
  QPushButton* _bouton;
public slots:
  void creerFichier();
public:
  CentralWidget(MainWindow* ptr);
  ~CentralWidget();
};

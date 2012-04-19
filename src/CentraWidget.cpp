#include "CentralWidget.hpp"
#include <QMessageBox>
#include <QFileDialog>
#include "tinyxml.h"
CentralWidget::CentralWidget(MainWindow* ptr):_mainWindowPtr(ptr)
{
  int i;
  QString str;
  _layout=new QGridLayout;
  _text=new QLabel("Texte:");
  _layout->addWidget(_text,0,1);
  _texte=new QTextEdit;
  _layout->addWidget(_texte,0,2);
  _nomFichier=new QLabel("Nom du fichier:");
  _layout->addWidget(_nomFichier,0,3);
  _fileButton=new QPushButton("...");
  _layout->addWidget(_fileButton,0,5);
  _nom=new QLineEdit;
  _layout->addWidget(_nom,0,4);
  _lien=new QLabel("Lien");
  _textBouton=new QLabel("Texte Bouton");
  _textEffect=new QLabel("Texte effet");
  _hpl=new QLabel("Effet sur HP");
  _cpl=new QLabel("Effet sur CP");
  _layout->addWidget(_textBouton,1,1);
  _layout->addWidget(_lien,1,2);
  _layout->addWidget(_hpl,1,3);
  _layout->addWidget(_cpl,1,4);
  _layout->addWidget(_textEffect,1,5);
  for(i=0;i<4;++i)
    {
      _textesBoutons.append(new QLineEdit);
      _layout->addWidget(_textesBoutons[i],i+2,1);
      _liens.append(new QLineEdit);
      _layout->addWidget(_liens[i],i+2,2);
      _hp.append(new QLineEdit);
      _layout->addWidget(_hp[i],i+2,3);
      _cp.append(new QLineEdit);
      _layout->addWidget(_cp[i],i+2,4);
      _textesEffets.append(new QTextEdit);
      _layout->addWidget(_textesEffets[i],i+2,5);
    }
  _bouton=new QPushButton("Enregistrer");
  _layout->addWidget(_bouton,7,5);
  this->setLayout(_layout);
  QObject::connect(_bouton,SIGNAL(clicked()),this,SLOT(creerFichier()));
  QObject::connect(_fileButton,SIGNAL(clicked()),this,SLOT(naviguer()));
}

CentralWidget::~CentralWidget()
{
  int i;
  delete _lien;
  delete _text;
  delete _fileButton;
  delete _textBouton;
  delete _textEffect;
  delete _hpl;
  delete _cpl;
  delete _nomFichier;
  delete _nom;
  for(i=0;i<4;++i)
    {
      delete _textesEffets[i];
      delete _textesBoutons[i];
      delete _cp[i];
      delete _hp[i];
    }
  delete _layout;
}

void CentralWidget::naviguer()
{
QString fichier = QFileDialog::getSaveFileName(this, "Enregistrer un fichier", QString(), "Niveau XML (*xml)");
 QObject::connect(this,SIGNAL(setFileLocation(const QString &)),_nom,SLOT(setText(const QString &)));
 emit setFileLocation(fichier);
}

void CentralWidget::creerFichier()
{
  int i;
  TiXmlDocument doc(_nom->text().toStdString());
  TiXmlElement level("level");
  level.SetAttribute("type","fourChoices");
  level.SetAttribute("text",_texte->toPlainText().toStdString());
  doc.InsertEndChild(level);
  doc.SaveFile(_nom->text().toStdString());
  TiXmlElement* elem=doc.FirstChildElement();
  TiXmlElement choice("choice");
  for(i=0;i<4;++i)
    {
      choice.SetAttribute("enonce",_textesBoutons[i]->text().toStdString());
      choice.SetAttribute("textEffect",_textesEffets[i]->toPlainText().toStdString());
      choice.SetAttribute("effectHp",_hp[i]->text().toStdString());
      choice.SetAttribute("effectCp",_cp[i]->text().toStdString());
      choice.SetAttribute("link",_liens[i]->text().toStdString());
      elem->InsertEndChild(choice);
    }
  doc.SaveFile(_nom->text().toStdString());
  QMessageBox::information(this, "Sauver fichier", "Le fichier à été sauvé.");
}

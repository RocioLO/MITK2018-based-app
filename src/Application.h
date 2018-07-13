#ifndef MY_Application_H
#define MY_Application_H

//GUI Files
#include <QMainWindow>
#include <ui_app.h>

#include <mitkStandaloneDataStorage.h>




class Application :  public QMainWindow
{
  // this is needed for all Qt objects that should have a Qt meta-object
  // (everything that derives from QObject and wants to have signal/slots)
  Q_OBJECT

public:
  
  explicit Application(QWidget *parent=0);
  ~Application();

  Ui_App  *ui;
  
  ///GENERAL
  QmitkStdMultiWidget *m_multiWidget;
  
  

  // we create a data storage for each tab in the app
  mitk::StandaloneDataStorage::Pointer m_data_storage;
 
 
public slots: 
// declarations for simbiofetal.cpp
  void onloadFilesButton1Clicked();
  
  
  void Initialize();
  void LoadData(QString);
  void CreateConnections();
  void SetupMultiwidget(QmitkStdMultiWidget *multiWidget, mitk::StandaloneDataStorage::Pointer data_storage);

  
  protected:
  
 
};

#endif // Application


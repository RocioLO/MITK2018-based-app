//#include "simbiofetal.h"
#include "Application.h"
#include "QmitkRegisterClasses.h"

#include <usModule.h> //to access resources directory
#include <usGetModuleContext.h>

#include <QApplication>

int main(int argc, char **argv)
{
 QApplication app (argc, argv);

 QmitkRegisterClasses();
 
 // Initialize
 Application fetalapp;
 //SimbioFetal sf;
 fetalapp.Initialize();
 //sf.Initialize(); 

 //QT connections
 fetalapp.CreateConnections();
 //sf.CreateConnections();
 
 
 fetalapp.showMaximized(); 
 //sf.showMaximized(); //TO show the window maximized. 
 //sf.show();

 return app.exec();
}

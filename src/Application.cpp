#include <Application.h>
#include <QFileDialog>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QmitkIOUtil.h>
#include <QmitkStdMultiWidget.h>
#include <QtConcurrent>
#include <QCoreApplication>
#include <QmitkProgressBar.h>
#include <mitkProgressBar.h>
#include <QmitkRenderWindow.h>

#include <mitkProperties.h>
#include <mitkColorProperty.h>
#include <mitkPointSet.h>
#include <mitkRotationOperation.h>
#include <mitkInteractionConst.h> //To perform Rotation Operations


Application::Application(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui_App)
//    ui(new Ui::Ui_SimbioFetal)
{
     ui->setupUi(this);
       
}

Application::~Application()
{
    delete ui;
}

void Application::Initialize(){

 
  //Data Storages for each tab
  //Application MyObject;
  m_data_storage = mitk::StandaloneDataStorage::New();
  
   m_multiWidget = ui->QstdMultiWidget;
 
   this->SetupMultiwidget(m_multiWidget,m_data_storage);
   // Initialize views as axial, sagittal, coronar (from
  // top-left to bottom)
  
  // m_multiWidget->SetDepartmentLogoPath("");
  m_multiWidget->AddDisplayPlaneSubTree();
  m_multiWidget->AddPlanesToDataStorage();
  m_multiWidget->EnableStandardLevelWindow();
  m_multiWidget->SetWidgetPlaneModeToSlicing (true);
  // m_multiWidget->EnablePositionTracking();
  
  m_multiWidget->SetWidgetPlanesVisibility(true);
  // mitk::SliceNavigationController * snc = m_multiWidget->GetTimeNavigationController ();
  // int steps = 	snc->GetSlice()->GetSteps();
  // MITK_INFO << "--------- Steppers before: " << steps;


  
}

void Application::CreateConnections(){
// QT CONNECTIONS
 
 connect(ui->loadFilesButton1, SIGNAL (clicked()), this, SLOT (onloadFilesButton1Clicked()));
 

}

//***************** MRI_TAB *************************
void Application::onloadFilesButton1Clicked(){
//This function loads the MITK scene ready to fill all data storage

  QString filename = QFileDialog::getOpenFileName(this, 
  "Open Image", 
  "/home/rlopez/Data/PROJECTS/FETAL/ImagesPlacenta/", 
  "All Images (*)"); 
  // Start the computation.
  if (!filename.isNull()){
    
    this->LoadData(filename);
     mitk::RenderingManager::GetInstance()->InitializeViewsByBoundingObjects(m_data_storage);   
   
  }
}


void Application::LoadData(QString fileName){
    
   QmitkIOUtil::Load(fileName,*m_data_storage, dynamic_cast<QWidget*>(m_multiWidget));
    
    
}


void Application::SetupMultiwidget(QmitkStdMultiWidget *multiWidget, mitk::StandaloneDataStorage::Pointer data_storage){
  //3D background colors
  mitk::ColorProperty::Pointer upperColor = mitk::ColorProperty::New(0.41,0.53,0.86);
  mitk::ColorProperty::Pointer lowerColor = mitk::ColorProperty::New(0.65,0.74,0.93);
   // Tell the m_multiWidget which DataStorage to rende
  multiWidget->SetDataStorage(data_storage);
  multiWidget->EnableGradientBackground();
  multiWidget->SetGradientBackgroundColorForRenderWindow(upperColor->GetColor(),lowerColor->GetColor(),3);
}


#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    if ( initConfigFile() )
    {
        bInitFailure = true;
        return;
    }

    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::initConfigFile( void )
{
    bool bRetVal = false;
    do
    {
        bRetVal = (bool)configFileManager.ReadXmlFile( PATH_TO_CONFIG_FILE );
        if( bRetVal )
            break;

        bRetVal = configFileManager.ProcessConfigFile();

    }while( 0 );

    return bRetVal;
}

bool MainWindow::initFailure( void )
{
    return bInitFailure;
}


void MainWindow::on_buttonOpenPath_1_clicked()
{

}


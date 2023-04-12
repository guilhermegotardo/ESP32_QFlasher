#include "mainwindow.h"
#include "ui_mainwindow.h"

#ifdef QT_DEBUG
#include <QDebug>
#endif


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    if ( initConfigFile() )
    {
        bInitFailure = true;
        return;
    }

#ifdef QT_DEBUG
OpenFileInitPath = "C:/Users/Guilherme/D2/Dev/Projetos/023 - ESP QFlash/ESP32-QFlash/data";
#endif
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
    QStringList fileNames;

    openFileDialog = new QFileDialog(this,"Open File", OpenFileInitPath, "XML Files (*.xml)");
    if ( openFileDialog->exec() )
    {
        fileNames =  openFileDialog->selectedFiles();
#ifdef QT_DEBUG
        qDebug() << fileNames.at(0);
#endif
        ui->linePathForFile_1->setText( fileNames.at(0) );
    }

}


void MainWindow::on_buttonFlash_1_clicked()
{

}


#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    configFileManager.ReadXmlFile( PATH_TO_CONFIG_FILE );
    configFileManager.ProcessConfigFile();

    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


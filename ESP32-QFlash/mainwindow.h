#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>

#include "configfilemanager.h"
#include "devicefilemanager.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    bool initConfigFile( void );
    bool getInitFailure( void );

    bool initDeviceFile( void );
    bool getDeviceFileFailure( void );

private slots:
    void on_buttonOpenPath_1_clicked();

    void on_buttonFlash_1_clicked();

private:
    Ui::MainWindow *ui;
    ConfigFileManager configFileManager;
    DeviceFileManager deviceFileManager;
    QFileDialog *openFileDialog;


private:
    bool bInitFailure;
    bool bDeviceFileFailure;

    QString OpenFileInitPath;



};
#endif // MAINWINDOW_H

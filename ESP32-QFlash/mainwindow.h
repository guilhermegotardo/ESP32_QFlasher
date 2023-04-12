#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "configfilemanager.h"

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
    bool initFailure( void );

private slots:
    void on_buttonOpenPath_1_clicked();

private:
    Ui::MainWindow *ui;
    ConfigFileManager configFileManager;

    bool bInitFailure = false;
};
#endif // MAINWINDOW_H

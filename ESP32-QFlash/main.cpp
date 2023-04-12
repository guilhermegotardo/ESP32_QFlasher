#include "mainwindow.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QMessageBox>
#include <QCoreApplication>

void showFailureMessage( void )
{
    QMessageBox failureMsgBox(QMessageBox::Critical,"Error","Error reading configuration file",
                              QMessageBox::Ok,nullptr,Qt::Dialog);
    failureMsgBox.exec();
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "ESP32-QFlash_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    MainWindow w;

    if( w.getInitFailure() )
    {
        showFailureMessage();
        return 0;
    }
    w.show();
    return a.exec();
}

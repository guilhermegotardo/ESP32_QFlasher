#ifndef DEVICEFILEMANAGER_H
#define DEVICEFILEMANAGER_H

#include <QMap>
#include <QString>
#include "filemanager.h"


#define Args_N          "Args"

#define Type_N          "Type"
#define Command_N       "Command"
#define Value_N         "Value"

#define Files_N         "Files"
#define BinaryFiles_N   "BinaryFiles"
#define File_N          "File"
#define KeyFile_N       "KeyFile"
#define BurnKey_N       "BurnKey"
#define KeyFile_N       "KeyFile"

#define Static_N        "static"
#define Dynamic_N       "dynamic"


class DeviceFileManager : public FileManager
{
public:
    DeviceFileManager();
    ~DeviceFileManager();

    bool setCommandFromFile( QString Command );
    QString getCommandToEspFlash( void );

public:
    bool isValidDeviceFileNode( QDomNode Node );
    bool insertNodeValueOnLocalMap( QDomNode Node );
    file_result_t ProcessDeviceFile( void );
    file_result_t ProcessArgsNode( QDomElement ArgsNode );


private:
    QString CommandToEspFlash;
    QMap<QString, QString> ArgsMap;
};

#endif // DEVICEFILEMANAGER_H

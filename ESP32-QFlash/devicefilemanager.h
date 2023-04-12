#ifndef DEVICEFILEMANAGER_H
#define DEVICEFILEMANAGER_H

#include "filemanager.h"

class DeviceFileManager : public FileManager
{
public:
    DeviceFileManager();
    ~DeviceFileManager();

    bool setCommandFromFile( QString Command );
    QString getCommandToEspFlash( void );

    file_result_t ProcessDeviceFile( void );
    file_result_t ProcessArgsNode( QDomElement ArgsNode );

private:
    QString CommandToEspFlash;
};

#endif // DEVICEFILEMANAGER_H

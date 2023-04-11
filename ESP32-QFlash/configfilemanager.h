#ifndef CONFIGFILEMANAGER_H
#define CONFIGFILEMANAGER_H

#include "filemanager.h"

class ConfigFileManager : public FileManager
{


public:
    ConfigFileManager();
    ~ConfigFileManager();
    bool setConfigurations( QString NodeName,QString Value );
    bool setVersion( QString Value );

    file_result_t ProcessConfigFile( void );


private:
    QString Version;

};

#endif // CONFIGFILEMANAGER_H

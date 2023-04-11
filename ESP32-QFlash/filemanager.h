#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include "typedefs.h"

#include <QFile>
#include <QDomDocument>


class FileManager
{
public:
    FileManager( void );
    ~FileManager( void );
    file_result_t ReadRawFile( QString PathToFile );
    file_result_t ReadXmlFile( QString PathToFile );

protected:
    QFile *rawFile = NULL;
    QDomDocument *xmlDomFile = NULL;

private:

};

#endif // FILEMANAGER_H

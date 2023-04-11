#include <QDebug>
#include "filemanager.h"

FileManager::FileManager( void )
{
    rawFile = new QFile ;
    xmlDomFile = new QDomDocument;
}

FileManager::~FileManager( void )
{
    rawFile->close();
    delete rawFile;
    delete xmlDomFile;
}

file_result_t FileManager::ReadRawFile( QString PathToFile )
{
    file_result_t fRetVal = FILE_OK;

    do
    {
        if( rawFile == NULL)
        {
            fRetVal = FILE_NULL;
            break;
        }

        if( !QFile::exists( PathToFile ) )
        {
            fRetVal = FILE_NOT_EXIST;
            break;
        }

        rawFile->setFileName( PathToFile );

        if( !rawFile->open( QIODevice::ReadOnly | QIODevice::Text ) )
        {
            fRetVal = FILE_OPEN_ERROR;
            break;
        }

    }while( 0 );

    return fRetVal;

}

file_result_t FileManager::ReadXmlFile( QString PathToFile )
{
    file_result_t fRetVal = FILE_OK;


    do
    {
        if( rawFile == NULL)
        {
            fRetVal = FILE_NULL;
            break;
        }

        fRetVal = ReadRawFile( PathToFile );

        if( fRetVal != FILE_OK)
            break;


#ifdef QT_DEBUG
        QString qsErrorMsg;
        int iErrorLine, iErrorColumn;

        if (!xmlDomFile->setContent( rawFile, &qsErrorMsg, &iErrorLine, &iErrorColumn ) )
        {
            rawFile->close();
            fRetVal = XML_FILE_SET_ERROR;
            qDebug() << "Error reading XML file: " << qsErrorMsg << " at line " << iErrorLine << " column " << iErrorColumn;
            break;
        }
#else
        if ( !xmlDomFile->setContent( rawFile ) )
        {
            rawFile->close();
            fRetVal = XML_FILE_SET_ERROR;
            break;
        }

#endif

    }while( 0 );

    return fRetVal;

}




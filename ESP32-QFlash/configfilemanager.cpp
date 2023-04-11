#include <QtDebug>

#include "configfilemanager.h"

ConfigFileManager::ConfigFileManager()
{

}

ConfigFileManager::~ConfigFileManager()
{

}

bool ConfigFileManager::setConfigurations( QString NodeName,QString Value )
{
    bool bRetVal = false;
    do
    {
        if( "VER" == NodeName )
        {
            bRetVal = setVersion( Value );
            break;
        }

    }while( 0 );

    return bRetVal;
}

bool ConfigFileManager::setVersion( QString Value )
{
    bool bRetVal = false;

    if( "FULL" == Value || "PRODUCTION" == Value)
    {
        Version = Value;
        bRetVal = true;
    }

    return bRetVal;
}


file_result_t ConfigFileManager::ProcessConfigFile( void )
{
    file_result_t fRetVal = FILE_OK;
    QDomElement xmlRoot, xmlElement;
    xmlRoot = xmlDomFile->documentElement();

    for(QDomNode n = xmlRoot.firstChild(); !n.isNull(); n = n.nextSibling())
    {
        xmlElement = n.toElement();
        setConfigurations( n.nodeName(), xmlElement.text() );
    }

    return fRetVal;
}


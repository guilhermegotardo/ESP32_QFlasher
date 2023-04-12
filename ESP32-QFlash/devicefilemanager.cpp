#include "devicefilemanager.h"

DeviceFileManager::DeviceFileManager()
{

}

DeviceFileManager::~DeviceFileManager()
{

}

bool DeviceFileManager::setCommandFromFile( QString Command )
{
    bool bRetVal = false;

    CommandToEspFlash = Command;

    return bRetVal;
}

QString DeviceFileManager::getCommandToEspFlash( void )
{
    return CommandToEspFlash;
}

file_result_t DeviceFileManager::ProcessDeviceFile( void )
{
    file_result_t fRetVal = FILE_OK;
    QDomElement xmlRoot, xmlElement;
    xmlRoot = xmlDomFile->documentElement();

    do
    {
        if ( xmlRoot.nodeName().isEmpty() || xmlRoot.nodeName().isNull() )
        {
            fRetVal = FILE_NULL;
            break;
        }

        ProcessArgsNode( xmlRoot );

    }while( 0 );

    return fRetVal;
}

file_result_t DeviceFileManager::ProcessArgsNode( QDomElement ArgsNode )
{
    file_result_t fRetVal = FILE_OK;
    QDomElement xmlElement;
#ifdef QT_DEBUG
    QString NodeName,NodeValue;
#endif

        for(QDomNode n = ArgsNode.firstChild(); !n.isNull(); n = n.nextSibling())
        {
            xmlElement = n.toElement();
#ifdef QT_DEBUG
            NodeName = n.nodeName();
            NodeValue = xmlElement.text();
#endif
        }
    return fRetVal;
}


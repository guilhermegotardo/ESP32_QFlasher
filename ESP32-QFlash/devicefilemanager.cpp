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

bool DeviceFileManager::isValidDeviceFileNode( QDomNode Node )
{
    bool bRetVal = false;
    QDomElement xmlElement;
#ifdef QT_DEBUG
    QString NodeName,NodeValue;
#endif

    xmlElement = Node.toElement();
#ifdef QT_DEBUG
    NodeName = Node.nodeName();
    NodeValue = xmlElement.text();
#endif

    do
    {
        if( "" == Node.nodeName() || NULL == Node.nodeName() )
        {
            break;
        }

        bRetVal = true;

    }while ( 0 );

    return bRetVal;
}

bool DeviceFileManager::insertNodeValueOnLocalMap( QDomNode Node )
{
    bool bRetVal = false, isStatic = false;
    QDomElement xmlElement;
    QDomNode n;
    QString NodeCommand,NodeValue;

//    Node = Node.firstChild();

    n = Node.firstChildElement( Type_N );
    xmlElement = n.toElement();
    do
    {
        if( n.isNull() )
            break;

        if( xmlElement.text() == Static_N )
            isStatic = true;

        n = Node.firstChildElement( Command_N );

        if( n.isNull() )
            break;

        xmlElement = n.toElement();
        NodeCommand = xmlElement.text();

        n = Node.firstChildElement( Value_N );

        if( n.isNull() )
            break;

        xmlElement = n.toElement();

        NodeValue = xmlElement.text();

        ArgsMap.insert( NodeCommand, NodeValue );

    }while( 0 );

    return bRetVal;
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

        fRetVal = this->ProcessArgsNode( xmlRoot );

        if( FILE_OK != fRetVal )
            break;


    }while( 0 );

    return fRetVal;
}

file_result_t DeviceFileManager::ProcessArgsNode( QDomElement ArgsNode )
{
    file_result_t fRetVal = XML_NODE_NOT_FOUND;
    QDomElement xmlElement;
    QDomNode n;
#ifdef QT_DEBUG
    QString NodeName,NodeValue;
#endif

    do
    {
        n = ArgsNode.firstChildElement( Args_N );

        if( n.isNull() )
        {
            break;
        }

        for(n = n.firstChild(); !n.isNull(); n = n.nextSibling())
        {
            if( !this->isValidDeviceFileNode( n ) )
            {
                continue;
            }
            xmlElement = n.toElement();

#ifdef QT_DEBUG
            NodeName = n.nodeName();
            NodeValue = xmlElement.text();
#endif

            this->insertNodeValueOnLocalMap( n );
        }

    }while( 0 );

    return fRetVal;
}


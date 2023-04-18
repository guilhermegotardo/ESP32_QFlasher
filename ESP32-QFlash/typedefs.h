#ifndef TYPEDEFS_H
#define TYPEDEFS_H


/*
 * DEFINES
 */

//PATH to FILES
#define PATH_TO_CONFIG_FILE  "data/config.xml"



typedef enum
{
    FILE_OK = 0,
    FILE_NOT_EXIST,
    FILE_OPEN_ERROR,
    FILE_NULL,
    XML_FILE_SET_ERROR,
    XML_NODE_NOT_FOUND,

}file_result_t;


#endif // TYPEDEFS_H

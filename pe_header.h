/**
  ******************************************************************************
  * @file           : pe_header.h
  * @author         : dell
  * @brief          : None
  * @attention      : None
  * @date           : 2023/11/7
  ******************************************************************************
  */



#ifndef PROJECT_PE_HEADER_H
#define PROJECT_PE_HEADER_H
#include "string"
#include <windows.h>
class pe_header {
public:
 void load_file(std::string path);
private:
    std::string file_path;
    IMAGE_DOS_HEADER dosHeader;
    IMAGE_NT_HEADERS32 ntHeaders32;
    IMAGE_FILE_HEADER fileHeader;
    IMAGE_OPTIONAL_HEADER32 optionalHeader32;
};


#endif //PROJECT_PE_HEADER_H

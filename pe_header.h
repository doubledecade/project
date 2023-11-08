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
#include "vector"
class pe_header {
public:
 void load_file(std::string path);
private:
    std::string file_path;
    IMAGE_DOS_HEADER dosHeader;
    IMAGE_NT_HEADERS32 ntHeaders32;
    IMAGE_NT_HEADERS64 ntHeaders64;
    IMAGE_FILE_HEADER fileHeader;
    std::vector<IMAGE_SECTION_HEADER> section_header_vec;
    int digit=0; //0 是32位，1是64位
};


#endif //PROJECT_PE_HEADER_H

/**
  ******************************************************************************
  * @file           : pe_header.cpp
  * @author         : dell
  * @brief          : None
  * @attention      : None
  * @date           : 2023/11/7
  ******************************************************************************
  */



#include <fstream>
#include <iostream>
#include "pe_header.h"

void pe_header::load_file(std::string _path) {
    file_path=_path;
    std::ifstream file(file_path, std::ios::binary);
    if(file.is_open()){
        file.read(reinterpret_cast<char*>(&dosHeader), sizeof(IMAGE_DOS_HEADER));
        if(dosHeader.e_magic == IMAGE_DOS_SIGNATURE){
            file.seekg(dosHeader.e_lfanew+sizeof (DWORD), std::ios::beg); // 定位到PE文件头
            //判断是32位还是64位
            WORD Machine;
            file.read(reinterpret_cast<char*>(&Machine), sizeof(WORD));
            file.seekg(dosHeader.e_lfanew, std::ios::beg);
            if(Machine==IMAGE_FILE_MACHINE_I386){
                //32位
                file.read(reinterpret_cast<char*>(&ntHeaders32), sizeof(IMAGE_NT_HEADERS32));
                digit=0;

            } else if(Machine==IMAGE_FILE_MACHINE_AMD64){
                //64位
                file.read(reinterpret_cast<char*>(&ntHeaders64), sizeof(IMAGE_NT_HEADERS64));
                digit=1;

            }

            // 输出一些基本信息
           // std::cout << "Machine: 0x" << std::hex << ntHeaders32.FileHeader.Machine << std::dec << std::endl;
//            std::cout << "Number of Sections: " << ntHeaders32.FileHeader.NumberOfSections << std::endl;
//            std::cout << "SizeOfOptionalHeader: " << ntHeaders32.FileHeader.SizeOfOptionalHeader << std::endl;
//            std::cout << "Magic: " << ntHeaders32.OptionalHeader.Magic << std::endl;
            std::cout<<"is PE"<<std::endl;
        } else{
            std::cout<<"is not PE"<<std::endl;
        }
    }
}

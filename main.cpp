#include <iostream>

#include <fstream>
#include <vector>
#include "pe_header.h"
#include "string.h"
#if 0
void test(){
    std::ifstream file("example.exe", std::ios::binary); // 打开PE文件，替换为您的PE文件路径

    if (file.is_open()) {
        DosHeader dosHeader;
        file.read(reinterpret_cast<char*>(&dosHeader), sizeof(DosHeader));

        if (dosHeader.e_magic == 0x5A4D) { // 检查DOS头部标识 ("MZ")
            file.seekg(dosHeader.e_lfanew, std::ios::beg); // 定位到PE文件头

            FileHeader fileHeader;
            file.read(reinterpret_cast<char*>(&fileHeader), sizeof(FileHeader));

            // 输出一些基本信息
            std::cout << "Machine: 0x" << std::hex << fileHeader.Machine << std::dec << std::endl;
            std::cout << "Number of Sections: " << fileHeader.NumberOfSections << std::endl;
            std::cout << "TimeDateStamp: " << fileHeader.TimeDateStamp << std::endl;

            // 读取节头
            std::vector<SectionHeader> sectionHeaders(fileHeader.NumberOfSections);
            file.read(reinterpret_cast<char*>(sectionHeaders.data()), sizeof(SectionHeader) * fileHeader.NumberOfSections);

            // 输出节头信息
            std::cout << "Section Headers:" << std::endl;
            for (const auto& section : sectionHeaders) {
                std::cout << "Name: " << section.Name << std::endl;
                // 输出其他节头信息...
            }
        } else {
            std::cerr << "不是有效的PE文件" << std::endl;
        }

        file.close();
    } else {
        std::cerr << "无法打开文件" << std::endl;
    }
}

int main() {
    std::ifstream file("example.exe", std::ios::binary); // 打开PE文件，替换为您的PE文件路径

    if (file.is_open()) {
        FileHeader fileHeader;
        file.seekg(60, std::ios::beg); // PE文件头的偏移量是60字节
        file.read(reinterpret_cast<char*>(&fileHeader), sizeof(FileHeader));

        // 计算节区头的偏移量
        int sectionHeaderOffset = 60 + sizeof(FileHeader);
        file.seekg(sectionHeaderOffset, std::ios::beg);

        // 读取节区头
        std::vector<SectionHeader> sectionHeaders(fileHeader.NumberOfSections);
        file.read(reinterpret_cast<char*>(sectionHeaders.data()), sizeof(SectionHeader) * fileHeader.NumberOfSections);

        // 输出每个节区头的信息
        for (const auto& section : sectionHeaders) {
            std::cout << "Name: " << section.Name << std::endl;
            std::cout << "Virtual Address: " << section.VirtualAddress << std::endl;
            std::cout << "Size of Raw Data: " << section.SizeOfRawData << std::endl;
            // 输出其他节区头信息...
        }

        file.close();
    } else {
        std::cerr << "无法打开文件" << std::endl;
    }

    return 0;
}
#else
int main(){
    pe_header test;

    //test.load_file("D:\\Everything\\Everything.exe");
    test.load_file("D:/Wireshark/capinfos.exe");
    //test.load_file("C:\\Users\\dell\\Desktop\\2.pcap");
    return 0;
}
#endif
#include <iostream>

#include <fstream>
#include <vector>

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
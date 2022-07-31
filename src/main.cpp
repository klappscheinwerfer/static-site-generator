#include <iostream>
#include <string>
#include <vector>
#include <filesystem>
#include <fstream>

#include "sitetree.hpp"

void deleteDirectoryContents(const std::string& dir_path);

int main(int argc, char *argv[]) {

    // Parse arguments

    std::string inputPath, outputPath;

    for (int i = 1; i < argc - 1; i++) {
        if(std::string("-i").compare(argv[i]) == 0) {
            inputPath = argv[i + 1];
        }
        if(std::string("-o").compare(argv[i]) == 0) {
            outputPath = argv[i + 1];
        }
    }

    // Validate input and output paths

    if (!std::filesystem::exists(inputPath)) {
        std::cout << inputPath << ": No such file or directory\n";
        return 1;
    }
    if (!std::filesystem::exists(outputPath)) {
        std::cout << outputPath << ": No such file or directory\n";
        return 2;
    }

    // Clear output folder
    deleteDirectoryContents(outputPath);

    // Load site structure

    std::vector<std::vector<std::string>> site;
    std::ifstream siteFile(inputPath + "site.xml");
    if(siteFile.is_open()) {
        std::string text;
        while (getline(siteFile, text)) {
            //std::cout << text << "\n";
        }
        siteFile.close();
    }

    // Load copylist

    std::vector<std::string> copylist;
    std::ifstream clist(inputPath + "copylist");
    if(clist.is_open()) {
        std::string text;
        while (getline(clist, text)) {
            if (text.at(0) != '#') {
                copylist.push_back(text);
            }
        }
        clist.close();
    }

    // Copy all files in copylist

    for(unsigned int i = 0; i < copylist.size(); i++) {
        std::filesystem::path ifpath = inputPath + copylist[i];
        std::filesystem::path ofpath = outputPath + copylist[i];
        std::filesystem::path pofpath = ofpath.parent_path();
        std::filesystem::create_directories(pofpath);
        std::filesystem::copy_file(ifpath, ofpath);
    }

    return 0;
}

void deleteDirectoryContents(const std::string& dir_path) {
    for (const auto& entry : std::filesystem::directory_iterator(dir_path)) {
        std::filesystem::remove_all(entry.path());
    }
}

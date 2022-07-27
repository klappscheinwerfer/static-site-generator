#include <iostream>
#include <string>
#include <vector>
#include <filesystem>
#include <fstream>

void recursiveCopy (std::filesystem::path src, std::filesystem::path dest);

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

    // Load copylist

    std::vector<std::string> copylist;
    std::ifstream clist(inputPath + "copylist");
    if(clist.is_open()) {
        std::string text;
        while (getline(clist, text)) {
            copylist.push_back(text);
        }
        clist.close();
    }

    for(unsigned int i = 0; i < copylist.size(); i++) {
        std::cout << copylist[i] << "\n";
    }
    std::cout.flush();

    //recursiveCopy(inputPath, outputPath);

    return 0;
}

/*void recursiveCopy (std::filesystem::path src, std::filesystem::path dest) {
    return;
}*/

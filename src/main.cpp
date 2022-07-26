#include <iostream>
#include <string>
#include <filesystem>

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

    return 0;
}

#include <iostream>
#include <string>

int main(int argc, char *argv[]) {

    // Parse arguments

    std::string inputPath = "";
    std::string outputPath = "";

    for (int i = 0; i < argc; i++) {
        std::cout << argv[i] << "\n";
        /*if(std::string("-i").compare(argv[i])) {
            std::cout << argv[i + 1];
        }*/
    }

    return 0;
}

#include <iostream>
#include <fstream>
#include <iomanip>
#include <bitset>

void binDump(const std::string& inputFileName, const std::string& outputFileName, int wordsPerLine = 8) {
    std::ifstream inputFile(inputFileName, std::ios::binary);
    if (!inputFile) {
        std::cerr << "Error opening input file: " << inputFileName << std::endl;
        return;
    }

    std::ofstream outputFile(outputFileName);
    if (!outputFile) {
        std::cerr << "Error opening output file: " << outputFileName << std::endl;
        return;
    }

    char byte;
    int wordCount = 0;
    while (inputFile.read(&byte, sizeof(byte))) {
        outputFile << std::bitset<8>(byte) << ' ';
        wordCount++;

        if (wordCount >= wordsPerLine) {
            outputFile << '\n';
            wordCount = 0;
        }
    }

    if (wordCount != 0) {  // Ensure there's a final newline if needed
        outputFile << '\n';
    }

    inputFile.close();
    outputFile.close();

    std::cout << "bindump complete" << std::endl;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <input file name> <output file name>" << std::endl;
        return 1;
    }

    binDump(argv[1], argv[2]);

    return 0;
}

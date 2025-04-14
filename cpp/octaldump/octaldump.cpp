#include <iostream>
#include <fstream>
#include <iomanip>

void octalDump(const std::string& inputFileName, const std::string& outputFileName, int bytesPerLine = 8) {
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
    int byteCount = 0;
    while (inputFile.read(&byte, sizeof(byte))) {
        outputFile << std::oct << std::setw(3) << std::setfill('0') << (static_cast<unsigned int>(byte) & 0xFF) << ' ';
        byteCount++;

        if (byteCount >= bytesPerLine) {
            outputFile << '\n';
            byteCount = 0;
        }
    }

    if (byteCount != 0) {  // Ensure there's a final newline if needed
        outputFile << '\n';
    }

    inputFile.close();
    outputFile.close();

    std::cout << "octaldump complete" << std::endl;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <input file name> <output file name>" << std::endl;
        return 1;
    }

    octalDump(argv[1], argv[2]);

    return 0;
}

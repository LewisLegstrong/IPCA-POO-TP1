#include "../inc/file_manipulation.hpp"

void writeNewFile(std::string fileName, std::string bufferToWrite) {
    std::fstream myFile;
    myFile.open(fileName, std::ios::out);
    if(myFile.is_open()){
        myFile << bufferToWrite;
        myFile.close(); // Close file
    }
}

void appendToFile(std::string fileName, std::string bufferToWrite) {
    std::fstream myFile;
    myFile.open(fileName, std::ios::app);
    if(myFile.is_open()){
        myFile << bufferToWrite;
        myFile.close(); // Close file
    }
}

void readFile(std::string fileName) {
    std::fstream myFile;
    myFile.open(fileName, std::ios::in);
    if(myFile.is_open()){
        std::string line; // Variable to store the text from the line
        while (getline(myFile, line)) { // Inside the loop 'while', we use getline to read line from 'myFile' and we store the line in 'line', until there are no more lines to read
            std::cout << line << std::endl; // Line output
        }
    }
}

int main() {

    writeNewFile("file.txt", "Matricula: ");
    writeNewFile("carro.txt", "Marca: ");
    appendToFile("file.txt", "69-CU-69");
    appendToFile("carro.txt", "Ferrari");
    readFile("file.txt");
    readFile("carro.txt");

	return 0;
}
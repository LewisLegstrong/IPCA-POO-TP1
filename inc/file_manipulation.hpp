#ifndef _FILE_MANIPULATION_HPP_
#define _FILE_MANIPULATION_HPP_

#include <iostream>
#include <string>
#include <fstream> // To be able to read and write from files

void writeNewFile(std::string fileName, std::string bufferToWrite);

void appendToFile(std::string fileName, std::string bufferToWrite);

void readFile(std::string fileName);

#endif // _FILE_MANIPULATION_HPP_
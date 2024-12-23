#ifndef _FILE_MANIPULATION_HPP_
#define _FILE_MANIPULATION_HPP_

#include <iostream>
#include <string>
#include <fstream> // To be able to read and write from files

/// @brief Simple function to write a new file
/// @param fileName 
/// @param bufferToWrite 
void writeNewFile(std::string fileName, std::string bufferToWrite);

/// @brief Simple function to append to a file, not destroying the content on an existing one if it exists
/// @param fileName 
/// @param bufferToWrite 
void appendToFile(std::string fileName, std::string bufferToWrite);

/// @brief simple function to read from a file
/// @param fileName 
void readFile(std::string fileName);

#endif // _FILE_MANIPULATION_HPP_
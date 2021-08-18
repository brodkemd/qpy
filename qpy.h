#ifndef QPY_H
#define QPY_H
#include "../lib/lib.h"

// the string that you want to use to link the indentifier to the instance
// I set it as a single space because I do not want to type anything else
std::string linker = " ";

// list the indentifiers that you want removed from the code files
std::vector<std::string> indentifiers = {"QCircuit", "Qbit", "Cbit", "Qbits", "Cbits", "Qgate"};

#endif 

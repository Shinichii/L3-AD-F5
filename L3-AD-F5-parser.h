#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
#include <algorithm>
#include <string>


#ifdef DEBUG_MODE_ENABLED
#define DEBUG_MSG(X) do {std::cout << (X) << std::endl;} while (0)
#else
#define DEBUG_MSG(X) 
#endif 

bool openFile(const std::string chemin);
bool closeFile(const std::string chemin, std::ifstream F);

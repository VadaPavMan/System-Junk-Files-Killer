#include <iostream>
#include <filesystem>
#include <fstream>
#include <cstdlib>
#include "file.hpp"
using namespace std;

int main()
{
  // Variable Declarations
  int numb;
  const char* tempPathCStr = getenv("TEMP");
    if (!tempPathCStr)
    {
        cerr << "Error: Unable to retrieve the TEMP directory." << endl;
        return 1;
    }
    const string tempPath(tempPathCStr);
  cout << R"(
    
      _             _     ____    _  ___ _ _           
     | |_   _ _ __ | | __/ ___|  | |/ (_) | | ___ _ __       
  _  | | | | | '_ \| |/ /\___ \  | ' /| | | |/ _ \ '__|
 | |_| | |_| | | | |   <  ___) | | . \| | | |  __/ |   
  \___/ \__,_|_| |_|_|\_\|____/  |_|\_\_|_|_|\___|_|   
                                                       
                            
)" << endl;

  cout << "\033[1;33mCreator:\033[0m \033[1m@VadaPavMan\033[0m\n\033[1;33mGithub Account:\033[0m \033[1mhttps://github.com/VadaPavMan\033[0m\n"
       << endl;
  cout << "\033[38;5;202m\033[1mChoose What Operation You Want To Perform: " << endl;
  cout << "\033[38;5;81m\033[1m1. System Junk Files Remover." << endl;
  cout << "2. Bug Log Tracking." << endl;
  cout << "3. Android Bug Log Tracking." << endl;
  cout << "4. Exit.\n\033[0m" << endl;

  cout<<"Enter The Number Of The Operation: ";
  cin >> numb;

  if (numb == 1)
  {
    file_deletion(tempPath);
  }

  return 0;
}
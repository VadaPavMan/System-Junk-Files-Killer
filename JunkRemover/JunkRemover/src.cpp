#include <iostream>
#include <filesystem>
#include <fstream>
#include <cstdlib>
#include "file.hpp"
using namespace std;
namespace fs = std::filesystem;

int main()
{
  // Variable Declarations
  int numb;
  const char *tempPathCStr = getenv("TEMP");
  if (!tempPathCStr)
  {
    cerr << "Error: Unable to retrieve the TEMP directory." << endl;
    return 1;
  }
  const string tempPath(tempPathCStr);

  const char *systemrootCStr = getenv("SystemRoot");
  if (!systemrootCStr)
  {
    cerr << "Error: Unable to retrieve the TEMP directory." << endl;
    return 1;
  }
  const string PrefetchPath = string(systemrootCStr) + "\\Prefetch";
  const string sys32temp = string(systemrootCStr) + "\\System32\\temp";
  const string tempInternetFilesPath = string(systemrootCStr) + "\\Temporary Internet Files";
  const string inetCachePath = string(systemrootCStr) + "\\INetCache";
  const string recentsPath = string(systemrootCStr) + "\\Recent";
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

  cout << "Enter The Number Of The Operation: ";
  cin >> numb;

  if (numb == 1)
  {
    cout<<"\033Starting Junk File Cleanup..\n\033[0m"<<endl;
    if(fs::exists(tempPath))
    {
      cout<<"\033Cleaning TEMP Directory: \n\033[0m"<<tempPath<<endl;
      file_deletion(tempPath);
    }
    else
    {
      cout<<"TEMP Directory Not Found. \033[38;5;202m\033[1mError\033[0m"<<endl;
    }
  }

  return 0;
}
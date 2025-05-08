#include <iostream>
#include <filesystem>
#include <fstream>
#include <cstdlib>
#include <thread>
#include <chrono>
#include "windows.h"
#include "conio.h"
#include "src.hpp"
using namespace std;
namespace fs = std::filesystem;

int main()
{
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

    cout << "\033[1;33mStarting Junk File Cleanup..\n\033[0m" << endl;
    cout << "Do You Want To Proceed [Y/N]: ";
    int ver = prompt();
    if (fs::exists(tempPath))
    {
      cout << "\033[1;33mCleaning TEMP Directory: \n\033[0m" << tempPath << endl;
      file_deletion(tempPath, ver);
    }
    else
    {
      cout << "TEMP Directory Not Found. \033[38;5;202m\033[1mError\033[0m" << endl;
    }
    if (fs::exists(PrefetchPath))
    {
      cout << "\033[1;33mCleaning Prefetch Directory: \n\033[0m" << PrefetchPath << endl;
      file_deletion(PrefetchPath, ver);
    }
    else
    {
      cout << "Prefetch Directory Not Found. \033[38;5;202m\033[1mError\033[0m" << endl;
    }
    if (fs::exists(sys32temp))
    {
      cout << "\033[1;33mCleaning Temp Directory: \n\033[0m" << sys32temp << endl;
      file_deletion(sys32temp, ver);
    }
    else
    {
      cout << "Temp Directory Not Found. \033[38;5;202m\033[1mError\033[0m" << endl;
    }
    if (fs::exists(tempInternetFilesPath))
    {
      cout << "\033[1;33mCleaning TempInternet Directory: \n\033[0m" << tempInternetFilesPath << endl;
      file_deletion(tempInternetFilesPath, ver);
    }
    else
    {
      cout << "TempInternet Directory Not Found. \033[38;5;202m\033[1mError\033[0m" << endl;
    }
    if (fs::exists(inetCachePath))
    {
      cout << "\033[1;33mCleaning INetCache Directory: \n\033[0m" << inetCachePath << endl;
      file_deletion(inetCachePath, ver);
    }
    else
    {
      cout << "INetCache Directory Not Found. \033[38;5;202m\033[1mError\033[0m" << endl;
    }
    if (fs::exists(recentsPath))
    {
      cout << "\033[1;33mCleaning Recents Directory: \n\033[0m" << recentsPath << endl;
      file_deletion(recentsPath, ver);
    }
    else
    {
      cout << "Recents Directory Not Found. \033[38;5;202m\033[1mError\033[0m" << endl;
    }

    cout << "\033[32m\033[1m\nIf Some Files & Folders Not Present In Your Windows, It Will Throw Folder Not Found Error.\033[0m" << endl;
    cout << "\033[32m\033[1mNo Need Worry As Other Unnecessary Files Will Be Deleted.\033[0m" << endl;
  }
  else if (numb == 3)
  {
    const string url = "https://sourceforge.net/projects/adb-driver/files/adb-setup-1.4.3.exe/download";

    char *userProfile = getenv("USERPROFILE");
    if (userProfile == nullptr)
    {
      cerr << "Error: Unable to get user profile path.\n";
      return 1;
    }

    string downloadPath = string(userProfile) + "\\Downloads\\adb-setup-1.4.3.exe";

    cout << "\033[1;33mBefore, Recording Logs.\033[0m" << endl;
    cout << "\033[1;33mHere Are The Thing You Need To Ensure: \n\033[0m" << endl;

    cout << "\033[38;5;81m\033[1m1. In Your Mobile Device, Turn On Developer Mode Option.\033[0m" << endl;
    cout << "\033[38;5;81m\033[1m2. In Developer Mode, Look For USB Debugging Option. \033[1;33m[Enable It]\033[0m" << endl;
    cout << "\033[38;5;81m\033[1m3. Now Connect Your Phone With PC, Via USB Cable.\033[0m" << endl;
    cout << "\033[1;33mHit Enter\033[0m";
    getch();

    cout<<"\033[1m\nChecking For ADB Drivers..."<<endl;
    if (CheckADB())
    {
      cout << "\033[32m\033[1mADB Drivers Are Installed And Accessible.\033[0m" << endl;
      CheckInstalled(0);
    }
    else
    {
      cout << "ADB Drivers Are Not Installed." << endl;
      cout << "Would You Like To Download And Install The ADB Drivers [Y/N]: ";
      int ver = prompt();

      DownloadADB(url, downloadPath, ver);
      CheckInstalled(ver);
    }
  }

  return 0;
}
#include <fstream>
#include <iostream>
#include <filesystem>
#include <windows.h>
#include <cstdlib>
#include <chrono>
#include <thread>
#include <string>
#include "src.hpp"

using namespace std;

void log(const string &message, int delay_ms = 30)
{
    cout << message << endl;
    this_thread::sleep_for(chrono::milliseconds(delay_ms));
}

void file_deletion(const string &filePath, int ver)
{
    if (filesystem::exists(filePath))
    {
        if (ver == 1)
        {
            try
            {
                for (const auto &entry : filesystem::directory_iterator(filePath))
                {
                    try
                    {
                        filesystem::remove_all(entry);
                        log("Deleted: " + entry.path().string());
                    }
                    catch (const filesystem::filesystem_error &e)
                    {
                        log("Unable to delete: " + entry.path().string() +
                            " - " + e.what());
                    }
                }
                log("\033[32m\033[1m\nFile Deletion Completed.\033[0m");
                log("\033[32m\033[1m\nSome Files Might Not Have Been Deleted If They Were In Use.\033[0m");
            }
            catch (const exception &e)
            {
                log("An unexpected error occurred: " + string(e.what()));
            }
        }
        else if (ver == 0)
        {
            cout << "Operation Closed." << endl;
            return;
        }
    }
    else
    {
        log(filePath + " Path Does Not Exist. Retry With System Administrator.");
    }
}

bool CheckADB()
{
    string basePath = "C:\\adb\\";
    for(auto i = 0; i < 5; i++)
    {
        if(filesystem::exists(basePath))
        {
            return true;  
        }
        this_thread::sleep_for(chrono::seconds(1));
    }

    if(!filesystem::exists(basePath))
    {
        return false;
    }

    return false;
}

void openURL(const std::string &url)
{
    ShellExecute(nullptr, "open", url.c_str(), nullptr, nullptr, SW_SHOWNORMAL);
}

void executeFile(const std::string &filePath)
{
    ShellExecute(nullptr, "open", filePath.c_str(), nullptr, nullptr, SW_SHOWNORMAL);
}

bool prompt()
{
    char ch;
    cin >> ch;

    if (ch == 'Y' || ch == 'y')
    {
        return true;
    }
    else if (ch == 'N' || ch == 'n')
    {
        return false;
    }
    else
    {
        cout << "Invalid Input." << endl;
        prompt();
    }

    return false;
}

int DownloadADB(const string &url, string &DownloadPath, int ver)
{
    if (ver == 1)
    {
        log("\033[1;33mOpening Download Link In The Browser...\n\033[0m", 2000);
        openURL(url);

        cout << "\033[1mWaiting For The File To Download...\n";
        bool filefound = false;
        for (int i = 0; i < 30; ++i)
        {
            if (filesystem::exists(DownloadPath))
            {
                filefound = true;
                break;
            }
            this_thread::sleep_for(chrono::seconds(1));
        }

        if(filefound)
        {
            cout<<"ABD Installer Found: \033[1;33m"<<DownloadPath<<"\n\033[0m";
            cout<<"Executing Installer...\n";
            executeFile(DownloadPath);
            cout<<"\033[1;33mType 'Y' And Hit Enter In Installation Terminal To Procced.\033[0m"<<endl;
        }
        else
        {
            cerr << "\033[38;5;202m\033[1mError: The File Was Not Downloaded In Time. Please Try Again Or Install Manually.\n\033[0m";
        }
    }
    else if (ver == 0)
    {
        cout << "Operation Closed. \033[38;5;202m\033[1mError Permission Denied.\033[0m" << endl;
        return 1;
    }

    return 0;
}

int CheckInstalled(int ver = 0)
{
    string basePath = "C:\\adb\\";
    bool folderFound = false;
    log("\033[1mVerifying File Path...", 2000);
    for(auto i = 0; i < 60; i++)
    {
        if(filesystem::exists(basePath))
        {
            folderFound = true;
            break;
        }
        this_thread::sleep_for(chrono::seconds(1));
    }
    if(folderFound && ver == 1)
    {
        cout<<"\033[32m\033[1mInstallation Complete.\033[0m";
    }
    else if(folderFound && ver == 0)
    {
        cout<<"\033[1mFile Path Found: \033[1;33m"<<basePath<<"\033[0m"<<endl;
    }
    else
    {
        cout<<"\033[38;5;202m\033[1mError File Path Not Found. Install ADB Drivers Properly.\033[0m";
        return 1;
    }

    return 0;
}
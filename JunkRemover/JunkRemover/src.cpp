#include <fstream>
#include <iostream>
#include <filesystem>
#include <windows.h>
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

bool CheckASDK()
{
    if (system("abd --version > null 2>&1") == 0)
    {
        return true;
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
            cout<<"ABD Installer Found: "<<DownloadPath<<"\n";
            cout<<"Executing Installer...\n";
            executeFile(DownloadPath);
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

int CheckInstalled()
{
    string basePath = "C:\\adb\\";
    log("Checking File Path...", 2000);
    if(filesystem::exists(basePath))
    {
        cout<<"\033[32m\033[1mInstallation Complete.\033[0m";
    }
    else
    {
        cout<<"\033[38;5;202m\033[1mError File Path Not Found. Install ADB Drivers Properly.\033[0m";
        return 1;
    }

    return 0;
}
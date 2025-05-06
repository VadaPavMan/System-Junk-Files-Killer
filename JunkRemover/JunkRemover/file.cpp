#include <fstream>
#include <iostream>
#include <filesystem>
#include <chrono>
#include <thread>
#include <string>
#include "file.hpp"

using namespace std;

void log(const string &message, int delay_ms = 100)
{
    cout << message << endl;
    this_thread::sleep_for(chrono::milliseconds(delay_ms));
}

void file_deletion(const string &filePath)
{
    char ver;
    if (filesystem::exists(filePath))
    {
        log("Do You Want To Proceed [Y/N]: ");
        cin >> ver;
        if (ver == 'y' || ver == 'Y')
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
        else if( ver == 'n' || ver == 'N')
        { 
            cout<<"Operation Closed."<<endl;
            return;
        }
        else
        { 
            cout<<"Invalid Input. "<<endl;
            file_deletion(filePath);
        }
    }
    else
    {
        log(filePath + " Path Does Not Exist. Retry With System Administrator.");
    }
}

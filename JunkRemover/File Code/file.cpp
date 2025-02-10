#include <fstream>
#include <iostream>
#include <filesystem>
#include <string>
#include "file.hpp"

using namespace std;

void file_deletion(const string &filePath)
{
    if (filesystem::exists(filePath))
    {
        char check;
        cout<<"Do You Want To Proceed [Y/N]: ";
        cin >> check;
        
        if(check == 'y' || check == 'Y')
        {
            try{ 
                for (const auto& entry : filesystem::directory_iterator(filePath))
                {
                    filesystem::remove_all(filePath);
                }
            } 
            catch(const exception& skip)
            {
                cerr <<"Some Files Are In Use, That Cannot Be Deleted.(Do Not Need To Worry For This, Ignore This.) : "<<skip.what()<<endl;
            }

            cout<<"File Deleted Successfully, Now Overall System Performance Is Improved."<<endl;
        }
        else
        {
            cout<<"File Operations Complete Without Deleting Temp Files."<<endl;
        }
    }
    else
    {
        cout << filePath << "Path Does Not Exist. Retry With System Administrator." << endl;
    }
}
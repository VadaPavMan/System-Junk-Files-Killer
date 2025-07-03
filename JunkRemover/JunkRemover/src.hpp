#ifndef FILE_DEL
#define FILE_DEL

#include <fstream>
#include <iostream>
#include <filesystem>
#include <cstdlib>
#include <conio.h>
#include <string>
using namespace std;

void file_deletion(const string& filePath, int ver);
void openURL(const std::string& url);
void executeFile(const std::string& filePath);

int DownloadADB(const string &url, string &DownloadPath, int ver);
int CheckInstalled(int ver);

bool CheckADB();
bool prompt();
bool isDeviceConnected();
int executeLog(bool devicecheck);

#endif
#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
using namespace std;
int main()
{
    fstream acf,config,acftemp;
    string dir, dir1, dir2, dele;
    int appid;
    cout << "Enter the App ID of the game having the fake update: ";
    cin >> appid;
    config.open("Config.txt", ios::in);
    if (config.is_open())
    {
        config.seekg(0, ios::beg);
        getline(config, dir, '\n');
        config.close();
    }
    else
    {
        cout << "Config.txt doesn't exist! Make one and come back!";
        return 0;
    }
    dir1 = dir + "\\appmanifest_" + to_string(appid) + ".acf";
    dir2 = dir + "\\tappmanifest_" + to_string(appid) + ".acf";
    acf.open(dir1, ios::in);
    if (acf.is_open())
    {
        acftemp.open(dir2, ios::out);
        while (getline(acf, dele)) {
            if (dele.find("BytesToDownload") != string::npos)
            {
                acftemp << "	\"BytesToDownload\"		\"0\"" << "\n";
                continue;
            }
            if (dele.find("BytesDownloaded") != string::npos)
            {
                acftemp << "	\"BytesDownloaded\"		\"0\"" << "\n";
                continue;
            }
            if (dele.find("StagingFolder") == string::npos)
                acftemp << dele << "\n";
        }
        acf.close();
        acftemp.close();
        remove(dir1.c_str());
        rename(dir2.c_str(), dir1.c_str());
    }
    else
    {
        cout << "ERROR: File not found! Following could be the reasons:\n\n1. Invalid app-id= "<<appid<<"\n2.Incorrect location to steamapps: "<<dir1;
        return 0;
    }
    return 0;
}

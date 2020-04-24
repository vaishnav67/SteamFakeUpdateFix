#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
    fstream acf,config;
    string dir, dele;
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
    dir = dir + "\\appmanifest_" + to_string(appid) + ".acf";
    acf.open(dir);
    if (acf.is_open())
    {
        while (getline(acf, dele)) {
            if (dele.find() != string::npos) {
                cout << line << endl;
            }
        }
    }
    else
    {
        cout << "ERROR: File not found! Following could be the reasons:\n\n1. Invalid app-id= "<<appid<<"\n2.Incorrect location to steamapps: "<<dir;
        return 0;
    }
    return 0;
}

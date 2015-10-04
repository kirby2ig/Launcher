#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
using namespace std;

const string home = getenv("HOME");
const string directory = home + "/.minecraft_launcher";
const string launcherJar = directory + "/Launcher.jar";
const string niceCMD = "/usr/bin/nice -20";
const string command = niceCMD + " java -jar " + launcherJar;

void launch()
{
    system(command.c_str());
}

void setupFiles()
{
    struct stat s;
    bool dirExists = (stat(directory.c_str(), &s) == 0) && (((s.st_mode) & S_IFMT) == S_IFDIR);
    bool jarExists = (stat (launcherJar.c_str(), &s) == 0);
    if(!dirExists)
    {
        //Make Directory
        cout << "Creating Dir" << endl;
        string mkdir = "mkdir " + directory;
        system(mkdir.c_str());
        setupFiles();
        return;
    }
    if(!jarExists)
    {
        //Download Jar
        cout << "Downloading Jar" << endl;
        string curl = "/usr/bin/curl -o " + launcherJar + " https://s3.amazonaws.com/Minecraft.Download/launcher/Minecraft.jar";
        system(curl.c_str());
        setupFiles();
        return;
    }
    cout << "Returning" << endl;
}

void print()
{
    cout << home << endl;
    cout << directory << endl;
    cout << launcherJar << endl;
}

int main()
{
    print();
    setupFiles();
    launch();
    return 0;
}

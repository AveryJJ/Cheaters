#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <iostream>
#include "directory.h"
#include "file.h"

using namespace std;

directory::directory(int argc, char* argument[])
{
   dirPath = string(argument[1]);
   files = vector<string>();
   finddir(dirPath, files);
}
int directory::finddir (string dir, vector<string> &files)
{
   DIR *dp;
   struct dirent *dirp;
   if((dp  = opendir(dir.c_str())) == NULL)
   {
      cout << "Error(" << errno << ") opening " << dir << endl;
      return errno;
   }

   while ((dirp = readdir(dp)) != NULL)
   {
      files.push_back(string(dirp->d_name));
   }

   for(unsigned int i = 0;i < files.size();i++)
   {
     if((files[i] == "."))
     {
       files.erase(files.begin()+i);
     }
     if(files[i] == "..")
     {
       files.erase(files.begin()+i);
     }
   }
   closedir(dp);
   return 0;
}
void directory::printDirectory()
{
   for(unsigned int i = 0; i < files.size(); i++)
   {
      cout << i << ". " << files[i] << endl;
   }
 }

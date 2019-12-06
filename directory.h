#ifndef _DIRECTORY_H
#define _DIRECTORY_H
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <iostream>

using namespace std;
class directory
{
   private:
      vector<string> files;
      string dirPath;
   public:
      directory(int argc, char* argument[]);

      int finddir (string dir, vector<string> &files);
      string get_dirPath()
      {
         return dirPath;
      }
      vector<string> get_file()
      {
         return files;
      }
      void printDirectory();
};

#endif

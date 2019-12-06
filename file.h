#ifndef _FILE_H
#define _FILE_H
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <queue>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

class file
{
   private:
      string fileName;
   public:
      file(string nameOfFile);
      string get_fileName() const;

};
#endif

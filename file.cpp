#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <iostream>
#include <queue>
#include "file.h"

using namespace std;

file::file(string nameOfFile)
{
   fileName = nameOfFile;
}
string file::get_fileName() const
{
   return fileName;
}

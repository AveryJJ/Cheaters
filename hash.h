#ifndef _HASH_H
#define _HASH_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <list>
#include <iostream>

using namespace std;

class hash
{
   private:
      struct info
      {
         int fileIndex;
		 string fileName;
		 info *next;
      };
   public:
	         info *table[578821];
      // Constructor for hashTables
      hash();
      //returns position in hashTable given some key.
      int hashFunction(string key);

      int countOccurances(int i, int j);

      void insertInfo(string key, int fileIndex);


       /* parses vector of words into chunks of length chunkLength*/
       void printFile();
};
#endif

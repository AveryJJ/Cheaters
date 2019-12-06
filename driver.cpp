#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include "directory.h"
#include "file.h"
#include "hash.h"
#include <fstream>
using namespace std;

int main(int argc, char*  argv[])
{
	hash Hashing;
	directory dir(argc, argv);
	int chunkLength = atoi(argv[2]);
	int weighting = atoi(argv[3]);

	for(unsigned int k=0; k < dir.get_file().size(); k++)
	{
		vector <string> queue;

		int startIndex = 0;
		int endIndex = 0;
		int sizeOfQueue = 0;

		string temp;
		string contents;

		file primaryFile(dir.get_file()[k]);
		int fileIndex = k;

		string path = dir.get_dirPath() + "/" + primaryFile.get_fileName();
		string fileLineContent;
		ifstream myfile(path.c_str());
		if(myfile.is_open())
		{
			while(getline(myfile, fileLineContent))
			{
				startIndex = 0;
				for(int i = 0; fileLineContent[i] != NULL; i++)
				{
					if((fileLineContent[i] == 32) || (fileLineContent[i+1] == NULL) || i+1 == fileLineContent.size())
					{
						endIndex = i;
						for(int j = startIndex; j <= endIndex; j++)
						{
							if((fileLineContent[j] >= 65 && fileLineContent[j] <= 90) || (fileLineContent[j] >= 97 && fileLineContent[j] <=122) || (fileLineContent[j] >= 48 && fileLineContent[j] <= 57))
							{
								char currChar = fileLineContent[j];
								if(currChar >= 97 && currChar <=122)
								{
									currChar = (currChar - 32);
								}
								temp = temp + currChar;
							}
						}
						if(sizeOfQueue != chunkLength)
						{
							queue.push_back(temp);
							temp.clear();
							sizeOfQueue = sizeOfQueue + 1;
						}
						else
						{
							for(unsigned int i = 0; i < queue.size(); i++)
							{
								contents = contents + queue[i];
							}
							queue.push_back(temp);
							temp.clear();
							Hashing.insertInfo(contents, k);
							queue.erase(queue.begin());
							contents.clear();
						}
						startIndex = endIndex+1;
					}
				}
				for(unsigned int i = 0; i < queue.size(); i++)
				{
					contents = contents + queue[i];
				}
				queue.push_back(temp);
				temp.clear();

				Hashing.insertInfo(contents, k);
				queue.erase(queue.begin());
				contents.clear();
			}
			myfile.close();
		}
	}

	for(int i = (dir.get_file().size()-1); i >= 1; i--)
	{
		for(int j = i-1; j >= 0; j--)
		{
			int num = Hashing.countOccurances(i,j);

			if(num > weighting)
			{
				cout << num << " :" << dir.get_file()[i] << ", " << dir.get_file()[j] << endl;
			}
		}
	}

}

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <list>
#include <math.h>
#include <iostream>
#include <fstream>
#include "hash.h"

using namespace std;

hash::hash()
{
	for(int i = 0; i < 578821; i++)
	{
		table[i] = NULL;
	}
}
int hash::hashFunction(string key)
{
	int keys = key.length();
	unsigned int num = 0;
	for(int i = 0; i < keys; i++)
	{
		num += int(key[i] * pow(7,i));

	}
	num = num%578821;

	return num;
}
void hash::insertInfo(string key, int fileIndex)
{
	int index = hashFunction(key);
	info* temp = new info;
	temp->fileIndex = fileIndex;
	temp->next = NULL;
	temp->fileName = key;
	if(table[index] != NULL)
	{
		if(table[index]->fileIndex != fileIndex)
		{

			info* extra = table[index];
			table[index] = temp;
			temp->next = extra;
		}
		else
		{
			return;
		}
	}
	else
	{
		table[index] = temp;
	}
}

int hash::countOccurances(int i, int j)
{

	int num=0;
	for(int k=0; k < 578821; k++)
	{

		if(table[k] != NULL)
		{
			info* last = table[k];
			info* it = table[k];
			while(last != NULL)
			{
				if(last->fileIndex == i)
				{
					it = last->next;
					while(it != NULL)
					{
						if(it->fileIndex == j)
						{
							num = num + 1;
						}
						it = it->next;
					}
					last = last->next;
				}
				else
				{
					last = last->next;
				}
			}
		}
	}
	return num;
}

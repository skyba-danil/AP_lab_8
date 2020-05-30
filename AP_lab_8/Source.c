#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXW 100
#define LEN 15

int chekWords(char word1[], char word2[]);
int hidenChek(char word1[], char word2[]);
void freeDArr(char** arr, const int size);

int main()
{
	int count = 0;
	char** allWords, buf[LEN], ** sameLattersWords;
	allWords = (char**)malloc(MAXW * sizeof(char*));
	if (allWords == NULL)
	{
		puts("NO memory for allWords!");
		return 1;
	}
	for (int i = 0;i < MAXW;i++)
	{
		allWords[i] = (char*)malloc(LEN * sizeof(char) + 1);
		if (allWords[i] == NULL)
		{
			puts("NO memory for allWords!");
			return 1;
		}
		if (*gets_s(allWords[i], LEN) != '\0') {
			count = i + 1;
			allWords[i + 1] = NULL;
		}
		else
			break;
	}

	sameLattersWords = (char**)malloc(count * sizeof(char*));
	for (int i = 0;i < count;i++)
		sameLattersWords[i] = (char*)malloc(LEN * sizeof(char) + 1);
	strcpy_s(sameLattersWords[0], LEN + 1, allWords[0]);
	int n = 1;
	for (int k = 1;k < count;k++)
	{
		if (chekWords(sameLattersWords[0], allWords[k]))
		{
			strcpy_s(sameLattersWords[n], LEN + 1, allWords[k]);
			n++;
		}
	}
	while (n)
	{
		puts(*sameLattersWords);
		sameLattersWords++;
		n--;
	}
	freeDArr(allWords, count);
}

void freeDArr(char** arr,const int size)
{
	for (int i = 0; i < size; i++)
	{
		free(arr[i]);
	}
	free(arr);
}

int chekWords(char word1[], char word2[])
{
	if (hidenChek(word1,word2))
	{
		if (hidenChek(word2,word1))
		{
			return 1;
		}
	}
	return 0;
}

int hidenChek(char word1[], char word2[])
{
	int chek = 0;
	for (int i = 0;word1[i] != '\0';i++)
	{
		for (int k = 0; word2[k] != '\0';k++)
		{
			if (word1[i] == word2[k])
			{
				chek = 1;
				break;
			}
			chek = 0;
		}
		if (!chek)
		{
			return 0;
		}
	}
	return 1;
}
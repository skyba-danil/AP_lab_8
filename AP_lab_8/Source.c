#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXW 101
#define LEN 15

int chekWords(char word1[], char word2[]);

int main()
{
	char** allWords, buf[LEN], ** sameLattersWords;
	allWords = (char**)malloc(MAXW * sizeof(char*));
	if (allWords == NULL)
	{
		puts("NO memory for allWords!");
		return 1;
	}
	for(int i = 0;i < MAXW;i++)
	allWords[i] = (char*)malloc(LEN * sizeof(char)+1);
	int i = 0;
	while (i < MAXW-1 && *gets_s(buf, LEN) != '\0')
	{
		strcpy_s(allWords[i], LEN+1,buf);
		i++;
	}

	allWords[++i] = NULL;
	sameLattersWords = (char**)malloc(MAXW * sizeof(char*));
	for (int i = 0;i < MAXW;i++)
		sameLattersWords[i] = (char*)malloc(LEN * sizeof(char) + 1);
	strcpy_s(sameLattersWords[0], LEN + 1, allWords[0]);
	int n = 1;
	for (int k = 1;allWords[k] != NULL;k++)
	{
		if (chekWords(sameLattersWords[0], allWords[k]))
		{
			strcpy_s(sameLattersWords[n], LEN + 1, allWords[k]);
			n++;
		}
	}
	free(allWords);
	while (n)
	{
		puts(*sameLattersWords);
		sameLattersWords++;
		n--;
	}
}

int chekWords(char word1[], char word2[])
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
	for (int i = 0;word2[i] != '\0';i++)
	{
		for (int k = 0; word1[k] != '\0';k++)
		{
			if (word1[k] == word2[i])
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
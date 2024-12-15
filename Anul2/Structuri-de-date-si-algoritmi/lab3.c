#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "timer.h"

int countChar (char* s, char c)
{
	int count = 0;
	for (int i = 0; s[i]; i++)
		if (s[i] == c)
			count++;
	return count;
}

void topFreqTime(char* s)
{
	int max = 0;
	char charMax;
	while (*s)
	{
		int cnt = countChar(s, *s);
		if (cnt > max)
		{
			max = cnt;
			charMax = *s;
		}
		s++;
	}
}

void topFreqMem(char* s)
{
	int fq[26] = {0};
	for (int i = 0; s[i]; i++)
		fq[s[i]]++;
	int max = 0;
	char charMax;
	for (int i = 0; i < 26; i++)
		if (fq[i] > max)
		{
			max = fq[i];
			charMax = (char)i;
		}
}

int main(void)
{
	float time1, time2;
	char s[10000];
	for (int i = 0; i < 10000; i++)
		s[i] = 'A' + rand() % 26;
	s[10000 - 1] = '\0';
	starton();
	topFreqTime(s);
	time1 = startoff();
	starton();
	topFreqMem(s);
	time2 = startoff();
	printf("%f %f\n", time1, time2);
	return 0;
}
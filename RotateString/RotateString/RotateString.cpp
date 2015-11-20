#include <iostream>
#include<stdio.h>
#include <fstream>
#include<string.h>
#include<vector>
using namespace std;
void Reverse(char* pstart, char* pend)
{
	if (pstart == NULL || pend == NULL)
		return;
	while (pstart < pend)
	{
		char temp = *pstart;
		*pstart = *pend;
		*pend = temp;
		pstart++, pend--;
	}
}
char* ReverseSentence(char *pdata)
{
	if (pdata == NULL)
		return NULL;
	char *pstart = pdata;
	char *pend = pdata;
	while (*pend != '\0')
		pend++;
	pend--;

	//反转句子
	Reverse(pstart, pend);

	//反转每个单词
	pstart = pend = pdata;
	while (*pstart != '\0')
	{
		if (*pstart == ' ')
		{
			pstart++;
			pend++;
		}
		else if (*pend == ' ' || *pend == '\0')
		{
			Reverse(pstart, --pend);
			pstart = ++pend;
		}
		else
		{
			pend++;
		}
	}
	return pdata;
}
int main()
{
	ofstream fout("Textout.txt");
	ifstream fin("Textin.txt");
	if (!fin) //打开文件失败
	{
		cout << "文件打开失败" << endl;
		return 1;
	}
	//读文件
	char buff[100];
	while (fin.getline(buff, 100))//文件指针指向字符‘\n’的下一个
		{
			cout << buff << endl;
			ReverseSentence(buff);
			fout << buff<< endl;
		}
	delete[] buff;
	fin.close();
	fout.close();

	//char sentence1[] = "student a am I";
	//ReverseSentence(sentence1);
	//fprintf(stderr, "%s", sentence1);
	//fprintf(stderr, "\n");
	//char sentence2[] = "threatre the to go will I";
	//ReverseSentence(sentence2);
	//fprintf(stderr, "%s", sentence2);
	//fprintf(stderr, "\n");


	//string str1 = "0123456789";
	////求出字符串的长度
	//int len = str1.length();
	//for (int i = 0; i<len / 2; i++)
	//{
	//	//前后交换
	//	char temp = str1[i];
	//	str1[i] = str1[len - i - 1];
	//	str1[len - i - 1] = temp;
	//}
	////输出交换后的字符串
	//cout << str1.c_str() << endl;

	return 0;

}



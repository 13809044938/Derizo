﻿/*有你这种程序员真丢脸啊*/
#include <iostream>
#include <time.h>
#include <string>
#include <fstream>

std::ofstream inFile;  // inFile an ifstream object (P.160) （这是个啥）

int InitializationData()
{
	using namespace std;
	ofstream file{ "data.txt" };  //创建一个文件
	auto Name = "None", Target = "None";
	int Target_Money = 0, Your_Money = 0, Left_Money = 0, Completeness = 0;  //定义并初始化各个数据，（可以考虑使用类与对象）
	inFile.open("data.txt");
	inFile << Name << endl << Target << endl << Target_Money << endl << Your_Money;
	return 0;
}

int WriteData(char Name, char Target, int Target_Money, int Your_Money)
{
	using namespace std;
	
	inFile.open("data.txt");
	if (inFile.is_open())
	{
		return 0;
	}
	else
	{
		inFile << Name << endl << Target << endl << Target_Money << endl << Your_Money;
		inFile.close();
		return 1;
	}
	
}

int CheckData()
{
	std::ifstream inFile;  
	inFile.open("data.txt");  //inFile used to read data.txt (P.161)
	if (!inFile.is_open())
	{
		return 1;  //如果找不到目标文件就返回1
	}
	else
	{
		if (inFile.eof())
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	inFile.close();
}

int main()
{
	using namespace std;

	char Name;
	int CheckDataReturn = CheckData();

	cout << "Derizo-您的生活目标小助手" << endl << endl;  //主菜单的文字啥的，目前没有完成
	if (CheckDataReturn == 1)
	{
		cout << "系统没有找到您的数据文件，您可能新用户？如果是，请按Enter，如果不是，请关闭软件。" << endl;
		getchar();
		cout << "欢迎！Derizo是您的生活目标小助手，您可以在此记录您的目标，还有完成多少等指标。事不宜迟，当您准备好后，请按Enter以开始。" << endl;
		getchar();
		system("cls");
		InitializationData();
		cout << "首先，你的名字是？" << endl;
		cin >> Name;
		cout << "很好，接下来交给我们……" << endl;

	}

	return 0;
}

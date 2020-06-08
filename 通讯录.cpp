#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
using namespace std;

static int m = 0;

class PhoNumBook
{
public:
	string name[20];
	string Birth[20];
	string PhoNum[20];
	string Addr[20];
	string WorkPlc[20];
};

void print()
{
	char s[20];
	char q;
	int i = 0;
	ifstream FILE;
	FILE.open("通讯录.txt", ios_base::in);
	cout << "以下为全部联系人信息:" << endl;
	while (FILE.getline(s,20))
	{
		cout << s << endl;
	}
	FILE.close();
	cout << "点击任意键返回主菜单: ";
	{
		cin >> q;
	}

}

void add()
{
	string name, Birth, PhoNum, Addr, WorkPlc;

	int temp = 1, i = 0;

	fstream FILE;
	FILE.open("通讯录.txt", ios_base::out | ios_base::app);
	while (temp)
	{
		int i = m;
		int n = 1;

		cout << "请输入添加联系人的信息：" << endl;

		cout << "姓名：";
		cin >> name;

		cout << "出生日期：";
		cin >> Birth;

		cout << "电话号码：";
		cin >> PhoNum;

		cout << "地址：";
		cin >> Addr;

		cout << "工作地址：";
		cin >> WorkPlc;

		FILE << PhoNum << endl;
		FILE << name << endl;
		FILE << "出生日期：" << Birth << endl;
		FILE << "电话号码：" << PhoNum << endl;
		FILE << "地址：" << Addr << endl;
		FILE << "工作地址：" << WorkPlc << endl;
		FILE << endl;

		m++;
		i++;

		while (n)
		{
			cout << "添加成功！机主信息已成功保存在当前目录的txt本文文档下." << endl;
			cout << "是否继续添加：" << endl << "1.是" << endl << "0.否" << endl;
			cin >> temp;
			if (temp == 1 || temp == 0)
			{
				n = 0;
			}
		}
	}
	FILE.close();
}

void mySpecicalStrcpy(char* arr, string str)
{
	char* chArr = new char[str.length()];
	strcpy(chArr, str.c_str());

	while (*chArr != '\0')
	{
		if (*chArr == ' ' || *chArr == '\n')
		{
			++chArr;
			continue;
		}
		*arr++ = *chArr++;
	}
	*arr = '\0';
}

void find()
{
	char sname[100], s[100];
	ifstream FILE;

	FILE.open("通讯录.txt", ios_base::in);
	FILE.seekg(0, ios::beg);

	cout << "请输入要查找的联系人：";

	cin.getline(sname, 100);

	char* snameArr = new char[100];
	mySpecicalStrcpy(snameArr, sname);

	while (!FILE.getline(s,100).eof())
	{
		if (strcmp(snameArr, s) == 0)
		{
			cout << "找到了！信息如下：" << endl;

			cout << s << endl;
			for (int i = 1; i <= 4; ++i)
			{
				FILE.getline(s,100);
				cout << s << endl;
			}
			break;
		}
	}
	FILE.close();
}

void find2()
{
	char sPhoNum[100], se[100];
	fstream FILE;
	FILE.open("通讯录.txt", ios_base::in);
	FILE.seekg(0, ios::beg);
	cout << "通过电话号码查找机主: " << endl;

	cout << "请输入要查找联系人的号码:";
	cin.getline(sPhoNum, '%');

	char* sPhoNumArr = new char[100];
	mySpecicalStrcpy(sPhoNumArr, sPhoNum);

	while (!FILE.getline(se,100).eof())
	{
		if (strcmp(sPhoNumArr, se) == 0)
		{
			cout << "找到了！信息如下：" << endl;
			cout << se << endl;

			for (int i = 1; i <= 4; ++i)
			{
				FILE.getline(se, 100);
				cout << se << endl;
			}
			break;
		}
	}
	FILE.close();
}

void Delete()
{
	string str = "通讯录.txt";
	ofstream ofs(str.c_str());
	if (ofs.good())
	{
		remove(str.c_str());
	}
}

int main()
{

	system("color 3F");

	int n;
	char ch[25] = "通讯录.txt";

	fstream f;

loop1:

	cout << "选项:" << endl << "1.通过姓名查找机主" << endl;
	cout << "2.通过电话号码查询机主" << endl << "3.增加电话号码" << endl << "4.清空通讯录" << endl << "5.显示所有号码" << endl << "6.退出程序" << endl << "请输入选项: ";

	cin >> n;

	if (n == 1)
	{
		find();
		goto loop1;
	}

	if (n == 2)
	{
		find2();
		goto loop1;
	}

	if (n == 3)
	{
		add();
		goto loop1;
	}

	if (n == 4)
	{
		Delete();
		goto loop1;
	}

	if (n == 5)
	{
		print();
		goto loop1;
	}

	if (n == 6)
	{
		goto loop2;
	}

	else
	{
		cout << "输入错误！请重新输入：" << endl;
		goto loop1;
	}

loop2:
	char exit;
	cout << "感谢你的使用！请按任意键退出！" << endl;
	cin >> exit;
	return 0;
}
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
	FILE.open("ͨѶ¼.txt", ios_base::in);
	cout << "����Ϊȫ����ϵ����Ϣ:" << endl;
	while (FILE.getline(s,20))
	{
		cout << s << endl;
	}
	FILE.close();
	cout << "���������������˵�: ";
	{
		cin >> q;
	}

}

void add()
{
	string name, Birth, PhoNum, Addr, WorkPlc;

	int temp = 1, i = 0;

	fstream FILE;
	FILE.open("ͨѶ¼.txt", ios_base::out | ios_base::app);
	while (temp)
	{
		int i = m;
		int n = 1;

		cout << "�����������ϵ�˵���Ϣ��" << endl;

		cout << "������";
		cin >> name;

		cout << "�������ڣ�";
		cin >> Birth;

		cout << "�绰���룺";
		cin >> PhoNum;

		cout << "��ַ��";
		cin >> Addr;

		cout << "������ַ��";
		cin >> WorkPlc;

		FILE << PhoNum << endl;
		FILE << name << endl;
		FILE << "�������ڣ�" << Birth << endl;
		FILE << "�绰���룺" << PhoNum << endl;
		FILE << "��ַ��" << Addr << endl;
		FILE << "������ַ��" << WorkPlc << endl;
		FILE << endl;

		m++;
		i++;

		while (n)
		{
			cout << "��ӳɹ���������Ϣ�ѳɹ������ڵ�ǰĿ¼��txt�����ĵ���." << endl;
			cout << "�Ƿ������ӣ�" << endl << "1.��" << endl << "0.��" << endl;
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

	FILE.open("ͨѶ¼.txt", ios_base::in);
	FILE.seekg(0, ios::beg);

	cout << "������Ҫ���ҵ���ϵ�ˣ�";

	cin.getline(sname, 100);

	char* snameArr = new char[100];
	mySpecicalStrcpy(snameArr, sname);

	while (!FILE.getline(s,100).eof())
	{
		if (strcmp(snameArr, s) == 0)
		{
			cout << "�ҵ��ˣ���Ϣ���£�" << endl;

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
	FILE.open("ͨѶ¼.txt", ios_base::in);
	FILE.seekg(0, ios::beg);
	cout << "ͨ���绰������һ���: " << endl;

	cout << "������Ҫ������ϵ�˵ĺ���:";
	cin.getline(sPhoNum, '%');

	char* sPhoNumArr = new char[100];
	mySpecicalStrcpy(sPhoNumArr, sPhoNum);

	while (!FILE.getline(se,100).eof())
	{
		if (strcmp(sPhoNumArr, se) == 0)
		{
			cout << "�ҵ��ˣ���Ϣ���£�" << endl;
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
	string str = "ͨѶ¼.txt";
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
	char ch[25] = "ͨѶ¼.txt";

	fstream f;

loop1:

	cout << "ѡ��:" << endl << "1.ͨ���������һ���" << endl;
	cout << "2.ͨ���绰�����ѯ����" << endl << "3.���ӵ绰����" << endl << "4.���ͨѶ¼" << endl << "5.��ʾ���к���" << endl << "6.�˳�����" << endl << "������ѡ��: ";

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
		cout << "����������������룺" << endl;
		goto loop1;
	}

loop2:
	char exit;
	cout << "��л���ʹ�ã��밴������˳���" << endl;
	cin >> exit;
	return 0;
}
#pragma once

#include<iostream>
#include<string>

using namespace std;

class Document
{
public:
	virtual ~Document() {}
	virtual string get_name() = 0;
};

class TextDocument : public Document
{
public:
	string get_name() override
	{
		return "�������� ��������";
	}
};

class GraphicDocument : public Document
{
public:
	string get_name() override
	{
		return "����������� ��������";
	}
};

class ExcelDocument : public Document
{
public:
	string get_name() override
	{
		return "�xcel ��������";
	}
};

class PDFDocument : public Document
{
public:
	string get_name() override
	{
		return "PDF ��������";
	}
};

class Editor
{
public:
	virtual ~Editor() {}
	virtual Document* creat_document() = 0;
	Document* creat()
	{
		Document* document = this->creat_document();
		return document;
	}
	virtual void menu_editor(string n) = 0;

};

class TextEditor : public Editor
{
	string name;
public:

	Document* creat_document() override
	{
		return new TextDocument;
	}
	void menu_editor(string n)  override
	{
		while (true)
		{
			system("cls");
			cout << "�������� - " << n << " :\n" << endl;
			cout << "1. �������� �����\n" << "2. �������� �����\n" << "3. ���������� �����\n"
				<< "4. ���������� ��� ����� ������\n" << "5. ������\n" << "6. ��������\n" << endl;
			cout << "��� �����: ";
			int var;
			cin >> var;
			switch (var)
			{
			case 1:
				system("cls");
				cout << "������� ��� �����: ";
				cin >> name;
				name = name + ".txt";
				cout << "�������� ���� " << name << " ������!" << endl;
				system("pause");
				break;
			case 2:
				system("cls");
				cout << "������� ��� �����: ";
				cin >> name;
				name = name + ".txt";
				cout << "�������� ���� " << name <<" ������!" << endl;
				system("pause");
				break;
			case 3:
				system("cls");
				cout << "������� ��� �����: ";
				cin >> name;
				name = name + ".txt";
				cout << "���� " << name << " ��������!" << endl;
				system("pause");
				break;
			case 4:
				system("cls");
				cout << "������� ����� ��� �����: ";
				cin >> name;
				name = name + ".txt";
				cout << "���� " << name << " �������� ��� ����� ������!" << endl;
				system("pause");
				break;
			case 5:
				system("cls");
				cout << "������� ��� ����� ��� ������: ";
				cin >> name;
				name = name + ".txt";
				cout << "���� " << name << " ���������!" << endl;
				system("pause");
				break;
			case 6:
				return;
				break;
			default:
				break;
			}
		}
	}

};

class GraphicEditor : public Editor
{
	string name;
public:

	Document* creat_document() override
	{
		return new GraphicDocument;
	}
	void menu_editor(string n)  override
	{
		while (true)
		{
			system("cls");
			cout << "�������� - " << n << " :\n" << endl;
			cout << "1. �������� �����\n" << "2. �������� �����\n" << "3. ���������� �����\n"
				<< "4. ���������� ��� ����� ������\n" << "5. ������\n" << "6. ��������\n" << endl;
			cout << "��� �����: ";
			int var;
			cin >> var;
			switch (var)
			{
			case 1:
				system("cls");
				cout << "������� ��� �����: ";
				cin >> name;
				name = name + ".jpg";
				cout << "����������� ���� " << name << " ������!" << endl;
				system("pause");
				break;
			case 2:
				system("cls");
				cout << "������� ��� �����: ";
				cin >> name;
				name = name + ".jpg";
				cout << "����������� ���� " << name << " ������!" << endl;
				system("pause");
				break;
			case 3:
				system("cls");
				cout << "������� ��� �����: ";
				cin >> name;
				name = name + ".jpg";
				cout << "���� " << name << " ��������!" << endl;
				system("pause");
				break;
			case 4:
				system("cls");
				cout << "������� ����� ��� �����: ";
				cin >> name;
				name = name + ".jpg";
				cout << "���� " << name << " �������� ��� ����� ������!" << endl;
				system("pause");
				break;
			case 5:
				system("cls");
				cout << "������� ��� ����� ��� ������: ";
				cin >> name;
				name = name + ".jpg";
				cout << "���� " << name << " ���������!" << endl;
				system("pause");
				break;
			case 6:
				return;
				break;
			default:
				break;
			}
		}
	}

};

class ExcelEditor : public Editor
{
	string name;
public:

	Document* creat_document() override
	{
		return new ExcelDocument;
	}
	void menu_editor(string n)  override
	{
		while (true)
		{
			system("cls");
			cout << "�������� - " << n << " :\n" << endl;
			cout << "1. �������� �����\n" << "2. �������� �����\n" << "3. ���������� �����\n"
				<< "4. ���������� ��� ����� ������\n" << "5. ������\n" << "6. ��������\n" << endl;
			cout << "��� �����: ";
			int var;
			cin >> var;
			switch (var)
			{
			case 1:
				system("cls");
				cout << "������� ��� �����: ";
				cin >> name;
				name = name + ".xlsx";
				cout << "Excel ���� " << name << " ������!" << endl;
				system("pause");
				break;
			case 2:
				system("cls");
				cout << "������� ��� �����: ";
				cin >> name;
				name = name + ".xlsx";
				cout << "Excel ���� " << name << " ������!" << endl;
				system("pause");
				break;
			case 3:
				system("cls");
				cout << "������� ��� �����: ";
				cin >> name;
				name = name + ".xlsx";
				cout << "���� " << name << " ��������!" << endl;
				system("pause");
				break;
			case 4:
				system("cls");
				cout << "������� ����� ��� �����: ";
				cin >> name;
				name = name + ".xlsx";
				cout << "���� " << name << " �������� ��� ����� ������!" << endl;
				system("pause");
				break;
			case 5:
				system("cls");
				cout << "������� ��� ����� ��� ������: ";
				cin >> name;
				name = name + ".xlsx";
				cout << "���� " << name << " ���������!" << endl;
				system("pause");
				break;
			case 6:
				return;
				break;
			default:
				break;
			}
		}
	}

};

class PDFEditor : public Editor
{
	string name;
public:

	Document* creat_document() override
	{
		return new PDFDocument;
	}
	void menu_editor(string n)  override
	{
		while (true)
		{
			system("cls");
			cout << "�������� - " << n << " :\n" << endl;
			cout << "1. �������� �����\n" << "2. �������� �����\n" << "3. ���������� �����\n"
				<< "4. ���������� ��� ����� ������\n" << "5. ������\n" << "6. ��������\n" << endl;
			cout << "��� �����: ";
			int var;
			cin >> var;
			switch (var)
			{
			case 1:
				system("cls");
				cout << "������� ��� �����: ";
				cin >> name;
				name = name + ".pdf";
				cout << "PDF ���� " << name << " ������!" << endl;
				system("pause");
				break;
			case 2:
				system("cls");
				cout << "������� ��� �����: ";
				cin >> name;
				name = name + ".pdf";
				cout << "PDF ���� " << name << " ������!" << endl;
				system("pause");
				break;
			case 3:
				system("cls");
				cout << "������� ��� �����: ";
				cin >> name;
				name = name + ".pdf";
				cout << "���� " << name << " ��������!" << endl;
				system("pause");
				break;
			case 4:
				system("cls");
				cout << "������� ����� ��� �����: ";
				cin >> name;
				name = name + ".pdf";
				cout << "���� " << name << " �������� ��� ����� ������!" << endl;
				system("pause");
				break;
			case 5:
				system("cls");
				cout << "������� ��� ����� ��� ������: ";
				cin >> name;
				name = name + ".pdf";
				cout << "���� " << name << " ���������!" << endl;
				system("pause");
				break;
			case 6:
				return;
				break;
			default:
				break;
			}
		}
	}

};


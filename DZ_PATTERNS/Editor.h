#pragma once

#include<iostream>
#include<string>
#include<fstream>
#include <cstdio>

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
	virtual string create_file() = 0;
	virtual string open_file() = 0;
	virtual void save_file() = 0;
	virtual void save_new_name_file() = 0;
	virtual void print() = 0;


};

class TextEditor : public Editor
{
	string name_;
	string data_;
public:
	~TextEditor() {}
	Document* creat_document() override
	{
		return new TextDocument;
	}
	string create_file() override
	{
		system("cls");
		cout << "�������� �����" << endl;
		cout << "--------------\n" << endl;
		cout << "������� ��� �����: ";
		cin >> name_;
		name_ = name_ + ".txt";
		ofstream out(name_, ios::out);
		out.close();
		cout << "������ �������� ���� " << name_ << " ������!" << endl;
		system("pause");
		return this->name_;
	}
	string open_file() override
	{
		system("cls");
		cout << "�������� ���������� �����:\n" << endl;
		cout << "1. �������� ������ ���������� �����\n" << "2. �������� ������� �����\n" << endl;
		cout << "��� �����: ";
		int var;
		cin >> var;
		switch (var)
		{
		case 1:
		{
			system("cls");
			ifstream in(this->name_, ios::in);
			if (in.is_open())
			{
				if (!in.eof())
				{
					in >> this->data_;
				}
				cout << "�������� ���� " << this->name_ << " ������!\n"
					<< "������ ���������� ������ � ���� ������" << endl;
			}
			else
				cout << "���� �� ������!" << endl;
			in.close();
			system("pause");
			return this->data_;
			break;
		}
		case 2:
		{
			system("cls");
			cout << "������� ��� �����: ";
			cin >> this->name_;
			this->name_ = this->name_ + ".txt";
			string data;
			ifstream in(this->name_, ios::in);
			if (in.is_open())
			{
				if (!in.eof())
				{
					char buf[1200];
					in.getline(buf, 1200);
					char* buff = new char[strlen(buf) + 1];
					strcpy(buff, buf);
					data = buff;
				}
				cout << "�������� ���� " << this->name_ << " ������!\n"
					<< "������ ���������� ������ � ���� ������" << endl;
			}
			else
				cout << "���� �� ������!" << endl;
			in.close();
			system("pause");
			return this->data_ = data;
			break;
		}
		default:
			break;
		}

	}
	void save_file() override
	{
		system("cls");
		cout << "���������� �����" << endl;
		cout << "----------------\n" << endl;
		cout << "������� ��� �����: ";
		cin >> this->name_;
		this->name_ = this->name_ + ".txt";
		ofstream out(this->name_, ios::out);
		string data;
		char* d = new char;
		cin.ignore();
		cout << "������� ������ ��� ������ � ����: " << endl;
		cin.getline(d, 1200);
		data = d;
		out << data;
		out.close();
		this->data_ = data;
		cout << "���� " << this->name_ << " ��������!" << endl;
		system("pause");
	}
	void save_new_name_file() override
	{
		system("cls");
		cout << "���������� ����� ��� ����� ������" << endl;
		cout << "---------------------------------\n" << endl;

		string name2;
		bool f = true;
		while (f)
		{
			cout << "������� ����� ��� �����: ";
			cin >> name2;
			name2 = name2 + ".txt";
			if (this->name_ != name2)
				f = false;
			else
				f = true;
		}
		ofstream out(name2, ios::out);
		out << this->data_;
		out.close();
		cout << "������ ���������� ����� " << this->name_ << " �������� ��� ����� ������ - " << name2 << endl;
		system("pause");

	}
	void print() override
	{
		system("cls");
		cout << "������ ������ �� �����" << endl;
		cout << "----------------------\n" << endl;
		string name;
		cout << "������� ��� ����� ��� ������: ";
		cin >> name;
		name = name + ".txt";
		string data;
		ifstream in(name, ios::in);
		if (in.is_open())
		{
			char buf[1200];
			in.getline(buf, 1200);
			char* buff = new char[strlen(buf) + 1];
			strcpy(buff, buf);
			data = buff;
		}
		else
			cout << "���� �� ������!" << endl;
		in.close();
		system("cls");
		cout << "������ ������ �� �����" << endl;
		cout << "--------------------------------------------------\n" << endl;
		cout << data << endl << endl;
		cout << "--------------------------------------------------" << endl;
		cout << "���� " << name << " ���������!" << endl;
		system("pause");
	}
	void menu_editor(string n)  override
	{
		while (true)
		{
			system("cls");
			cout << "�������� - " << n << ":\n" << endl;
			cout << "1. �������� �����\n" << "2. �������� �����\n" << "3. ���������� �����\n"
				<< "4. ���������� ��� ����� ������\n" << "5. ������\n" << "6. ��������\n" << endl;
			cout << "��� �����: ";
			int var;
			cin >> var;
			switch (var)
			{
			case 1:
			{
				create_file();
				break;
			}
			case 2:
			{
				open_file();
				break;
			}
			case 3:
			{
				save_file();
				break;
			}
			case 4:
			{
				save_new_name_file();
				break;
			}
			case 5:
			{
				print();
				break;
			}
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
	string name_;
	string data_;
public:
	~GraphicEditor() {}
	Document* creat_document() override
	{
		return new GraphicDocument;
	}
	string create_file() override
	{
		system("cls");
		cout << "������ ����������� ���� " << name_ << " ������!" << endl;
		system("pause");
		return this->name_;
	}
	string open_file() override
	{
		system("cls");
		cout << "����������� ���� " << this->name_ << " ������!\n"
			<< "������ ���������� ������ � ���� ������" << endl;
		system("pause");
		return this->data_;
	}
	void save_file() override
	{
		system("cls");
		cout << "���� " << this->name_ << " ��������!" << endl;
		system("pause");
	}
	void save_new_name_file() override
	{
		system("cls");
		cout << "������ ������������ ����� " << this->name_ << " �������� ��� ����� ������ - " << endl;
		system("pause");

	}
	void print() override
	{
		system("cls");
		cout << "���� " << name_ << " ���������!" << endl;
		system("pause");
	}
	void menu_editor(string n)  override
	{
		while (true)
		{
			system("cls");
			cout << "�������� - " << n << ":\n" << endl;
			cout << "1. �������� �����\n" << "2. �������� �����\n" << "3. ���������� �����\n"
				<< "4. ���������� ��� ����� ������\n" << "5. ������\n" << "6. ��������\n" << endl;
			cout << "��� �����: ";
			int var;
			cin >> var;
			switch (var)
			{
			case 1:
			{
				create_file();
				break;
			}
			case 2:
			{
				open_file();
				break;
			}
			case 3:
			{
				save_file();
				break;
			}
			case 4:
			{
				save_new_name_file();
				break;
			}
			case 5:
			{
				print();
				break;
			}
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
	string name_;
	string data_;
public:
	~ExcelEditor() {}
	Document* creat_document() override
	{
		return new ExcelDocument;
	}
	string create_file() override
	{
		system("cls");
		cout << "������ Excel ���� " << name_ << " ������!" << endl;
		system("pause");
		return this->name_;
	}
	string open_file() override
	{
		system("cls");
		cout << "Excel ���� " << this->name_ << " ������!\n"
			<< "������ ���������� ������ � ���� ������" << endl;
		system("pause");
		return this->data_;
	}
	void save_file() override
	{
		system("cls");
		cout << "���� " << this->name_ << " ��������!" << endl;
		system("pause");
	}
	void save_new_name_file() override
	{
		system("cls");
		cout << "������ Excel ����� " << this->name_ << " �������� ��� ����� ������ - " << endl;
		system("pause");

	}
	void print() override
	{
		system("cls");
		cout << "���� " << name_ << " ���������!" << endl;
		system("pause");
	}
	void menu_editor(string n)  override
	{
		while (true)
		{
			system("cls");
			cout << "�������� - " << n << ":\n" << endl;
			cout << "1. �������� �����\n" << "2. �������� �����\n" << "3. ���������� �����\n"
				<< "4. ���������� ��� ����� ������\n" << "5. ������\n" << "6. ��������\n" << endl;
			cout << "��� �����: ";
			int var;
			cin >> var;
			switch (var)
			{
			case 1:
			{
				create_file();
				break;
			}
			case 2:
			{
				open_file();
				break;
			}
			case 3:
			{
				save_file();
				break;
			}
			case 4:
			{
				save_new_name_file();
				break;
			}
			case 5:
			{
				print();
				break;
			}
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
	string name_;
	string data_;
public:
	~PDFEditor() {}
	Document* creat_document() override
	{
		return new PDFDocument;
	}
	string create_file() override
	{
		system("cls");
		cout << "������ PDF ���� " << name_ << " ������!" << endl;
		system("pause");
		return this->name_;
	}
	string open_file() override
	{
		system("cls");
		cout << "PDF ���� " << this->name_ << " ������!\n"
			<< "������ ���������� ������ � ���� ������" << endl;
		system("pause");
		return this->data_;
	}
	void save_file() override
	{
		system("cls");
		cout << "���� " << this->name_ << " ��������!" << endl;
		system("pause");
	}
	void save_new_name_file() override
	{
		system("cls");
		cout << "������ PDF ����� " << this->name_ << " �������� ��� ����� ������ - " << endl;
		system("pause");

	}
	void print() override
	{
		system("cls");
		cout << "���� " << name_ << " ���������!" << endl;
		system("pause");
	}
	void menu_editor(string n)  override
	{
		while (true)
		{
			system("cls");
			cout << "�������� - " << n << ":\n" << endl;
			cout << "1. �������� �����\n" << "2. �������� �����\n" << "3. ���������� �����\n"
				<< "4. ���������� ��� ����� ������\n" << "5. ������\n" << "6. ��������\n" << endl;
			cout << "��� �����: ";
			int var;
			cin >> var;
			switch (var)
			{
			case 1:
			{
				create_file();
				break;
			}
			case 2:
			{
				open_file();
				break;
			}
			case 3:
			{
				save_file();
				break;
			}
			case 4:
			{
				save_new_name_file();
				break;
			}
			case 5:
			{
				print();
				break;
			}
			case 6:
				return;
				break;
			default:
				break;
			}
		}
	}

};

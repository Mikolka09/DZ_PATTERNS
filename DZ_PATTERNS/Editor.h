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
		return "Тектовый документ";
	}
};

class GraphicDocument : public Document
{
public:
	string get_name() override
	{
		return "Графический документ";
	}
};

class ExcelDocument : public Document
{
public:
	string get_name() override
	{
		return "Еxcel документ";
	}
};

class PDFDocument : public Document
{
public:
	string get_name() override
	{
		return "PDF документ";
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
		cout << "СОЗДАНИЕ ФАЙЛА" << endl;
		cout << "--------------\n" << endl;
		cout << "Введите имя файла: ";
		cin >> name_;
		name_ = name_ + ".txt";
		ofstream out(name_, ios::out);
		out.close();
		cout << "Пустой тектовый файл " << name_ << " создан!" << endl;
		system("pause");
		return this->name_;
	}
	string open_file() override
	{
		system("cls");
		cout << "Открытие текстового файла:\n" << endl;
		cout << "1. Открытие только созданного файла\n" << "2. Открытие другого файла\n" << endl;
		cout << "Ваш выбор: ";
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
				cout << "Тектовый файл " << this->name_ << " открыт!\n"
					<< "Можете продолжить работу с этим файлом" << endl;
			}
			else
				cout << "Файл не найден!" << endl;
			in.close();
			system("pause");
			return this->data_;
			break;
		}
		case 2:
		{
			system("cls");
			cout << "Введите имя файла: ";
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
				cout << "Тектовый файл " << this->name_ << " открыт!\n"
					<< "Можете продолжить работу с этим файлом" << endl;
			}
			else
				cout << "Файл не найден!" << endl;
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
		cout << "СОХРАНЕНИЕ ФАЙЛА" << endl;
		cout << "----------------\n" << endl;
		cout << "Введите имя файла: ";
		cin >> this->name_;
		this->name_ = this->name_ + ".txt";
		ofstream out(this->name_, ios::out);
		string data;
		char* d = new char;
		cin.ignore();
		cout << "Введите данные для записи в файл: " << endl;
		cin.getline(d, 1200);
		data = d;
		out << data;
		out.close();
		this->data_ = data;
		cout << "Файл " << this->name_ << " сохранен!" << endl;
		system("pause");
	}
	void save_new_name_file() override
	{
		system("cls");
		cout << "СОХРАНЕНИЕ ФАЙЛА ПОД НОВЫМ ИМЕНЕМ" << endl;
		cout << "---------------------------------\n" << endl;

		string name2;
		bool f = true;
		while (f)
		{
			cout << "Введите новое имя файла: ";
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
		cout << "Данные текстового файла " << this->name_ << " сохранен под новым именем - " << name2 << endl;
		system("pause");

	}
	void print() override
	{
		system("cls");
		cout << "ПЕЧАТЬ ДАННЫХ ИЗ ФАЙЛА" << endl;
		cout << "----------------------\n" << endl;
		string name;
		cout << "Введите имя файла для печати: ";
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
			cout << "Файл не найден!" << endl;
		in.close();
		system("cls");
		cout << "ПЕЧАТЬ ДАННЫХ ИЗ ФАЙЛА" << endl;
		cout << "--------------------------------------------------\n" << endl;
		cout << data << endl << endl;
		cout << "--------------------------------------------------" << endl;
		cout << "Файл " << name << " напечатан!" << endl;
		system("pause");
	}
	void menu_editor(string n)  override
	{
		while (true)
		{
			system("cls");
			cout << "Редактор - " << n << ":\n" << endl;
			cout << "1. Создание файла\n" << "2. Открытие файла\n" << "3. Сохранение файла\n"
				<< "4. Сохранение под новым именем\n" << "5. Печать\n" << "6. Закрытие\n" << endl;
			cout << "Ваш выбор: ";
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
		cout << "Пустой графический файл " << name_ << " создан!" << endl;
		system("pause");
		return this->name_;
	}
	string open_file() override
	{
		system("cls");
		cout << "Графический файл " << this->name_ << " открыт!\n"
			<< "Можете продолжить работу с этим файлом" << endl;
		system("pause");
		return this->data_;
	}
	void save_file() override
	{
		system("cls");
		cout << "Файл " << this->name_ << " сохранен!" << endl;
		system("pause");
	}
	void save_new_name_file() override
	{
		system("cls");
		cout << "Данные графического файла " << this->name_ << " сохранен под новым именем - " << endl;
		system("pause");

	}
	void print() override
	{
		system("cls");
		cout << "Файл " << name_ << " напечатан!" << endl;
		system("pause");
	}
	void menu_editor(string n)  override
	{
		while (true)
		{
			system("cls");
			cout << "Редактор - " << n << ":\n" << endl;
			cout << "1. Создание файла\n" << "2. Открытие файла\n" << "3. Сохранение файла\n"
				<< "4. Сохранение под новым именем\n" << "5. Печать\n" << "6. Закрытие\n" << endl;
			cout << "Ваш выбор: ";
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
		cout << "Пустой Excel файл " << name_ << " создан!" << endl;
		system("pause");
		return this->name_;
	}
	string open_file() override
	{
		system("cls");
		cout << "Excel файл " << this->name_ << " открыт!\n"
			<< "Можете продолжить работу с этим файлом" << endl;
		system("pause");
		return this->data_;
	}
	void save_file() override
	{
		system("cls");
		cout << "Файл " << this->name_ << " сохранен!" << endl;
		system("pause");
	}
	void save_new_name_file() override
	{
		system("cls");
		cout << "Данные Excel файла " << this->name_ << " сохранен под новым именем - " << endl;
		system("pause");

	}
	void print() override
	{
		system("cls");
		cout << "Файл " << name_ << " напечатан!" << endl;
		system("pause");
	}
	void menu_editor(string n)  override
	{
		while (true)
		{
			system("cls");
			cout << "Редактор - " << n << ":\n" << endl;
			cout << "1. Создание файла\n" << "2. Открытие файла\n" << "3. Сохранение файла\n"
				<< "4. Сохранение под новым именем\n" << "5. Печать\n" << "6. Закрытие\n" << endl;
			cout << "Ваш выбор: ";
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
		cout << "Пустой PDF файл " << name_ << " создан!" << endl;
		system("pause");
		return this->name_;
	}
	string open_file() override
	{
		system("cls");
		cout << "PDF файл " << this->name_ << " открыт!\n"
			<< "Можете продолжить работу с этим файлом" << endl;
		system("pause");
		return this->data_;
	}
	void save_file() override
	{
		system("cls");
		cout << "Файл " << this->name_ << " сохранен!" << endl;
		system("pause");
	}
	void save_new_name_file() override
	{
		system("cls");
		cout << "Данные PDF файла " << this->name_ << " сохранен под новым именем - " << endl;
		system("pause");

	}
	void print() override
	{
		system("cls");
		cout << "Файл " << name_ << " напечатан!" << endl;
		system("pause");
	}
	void menu_editor(string n)  override
	{
		while (true)
		{
			system("cls");
			cout << "Редактор - " << n << ":\n" << endl;
			cout << "1. Создание файла\n" << "2. Открытие файла\n" << "3. Сохранение файла\n"
				<< "4. Сохранение под новым именем\n" << "5. Печать\n" << "6. Закрытие\n" << endl;
			cout << "Ваш выбор: ";
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

//Editor* ed = nullptr;
//Document* doc = nullptr;
//cout << "РАБОТА С ФАЙЛАМИ" << endl;
//cout << "----------------\n" << endl;
//cout << "Выберите формат файла\n" << endl;
//cout << "1. Текстовый\n" << "2. Графический\n" << "3. Excel\n"
//<< "4. PDF\n" << "5. Выход\n" << endl;
//cout << "Ваш выбор: ";
//int var;
//cin >> var;
//switch (var)
//{
//case 1:
//	ed = new TextEditor;
//	break;
//case 2:
//	ed = new GraphicEditor;
//	break;
//case 3:
//	ed = new ExcelEditor;
//	break;
//case 4:
//	ed = new PDFEditor;
//	break;
//case 5:
//	exit(0);
//default:
//	break;
//}
//doc = ed->creat();
//string name = doc->get_name();
//ed->menu_editor(name);

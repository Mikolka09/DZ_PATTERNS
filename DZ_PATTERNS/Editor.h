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
			cout << "Редактор - " << n << " :\n" << endl;
			cout << "1. Создание файла\n" << "2. Открытие файла\n" << "3. Сохранение файла\n"
				<< "4. Сохранение под новым именем\n" << "5. Печать\n" << "6. Закрытие\n" << endl;
			cout << "Ваш выбор: ";
			int var;
			cin >> var;
			switch (var)
			{
			case 1:
				system("cls");
				cout << "Введите имя файла: ";
				cin >> name;
				name = name + ".txt";
				cout << "Тектовый файл " << name << " создан!" << endl;
				system("pause");
				break;
			case 2:
				system("cls");
				cout << "Введите имя файла: ";
				cin >> name;
				name = name + ".txt";
				cout << "Тектовый файл " << name <<" открыт!" << endl;
				system("pause");
				break;
			case 3:
				system("cls");
				cout << "Введите имя файла: ";
				cin >> name;
				name = name + ".txt";
				cout << "Файл " << name << " сохранен!" << endl;
				system("pause");
				break;
			case 4:
				system("cls");
				cout << "Введите новое имя файла: ";
				cin >> name;
				name = name + ".txt";
				cout << "Файл " << name << " сохранен под новым именем!" << endl;
				system("pause");
				break;
			case 5:
				system("cls");
				cout << "Введите имя файла для печати: ";
				cin >> name;
				name = name + ".txt";
				cout << "Файл " << name << " напечатан!" << endl;
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
			cout << "Редактор - " << n << " :\n" << endl;
			cout << "1. Создание файла\n" << "2. Открытие файла\n" << "3. Сохранение файла\n"
				<< "4. Сохранение под новым именем\n" << "5. Печать\n" << "6. Закрытие\n" << endl;
			cout << "Ваш выбор: ";
			int var;
			cin >> var;
			switch (var)
			{
			case 1:
				system("cls");
				cout << "Введите имя файла: ";
				cin >> name;
				name = name + ".jpg";
				cout << "Графический файл " << name << " создан!" << endl;
				system("pause");
				break;
			case 2:
				system("cls");
				cout << "Введите имя файла: ";
				cin >> name;
				name = name + ".jpg";
				cout << "Графический файл " << name << " открыт!" << endl;
				system("pause");
				break;
			case 3:
				system("cls");
				cout << "Введите имя файла: ";
				cin >> name;
				name = name + ".jpg";
				cout << "Файл " << name << " сохранен!" << endl;
				system("pause");
				break;
			case 4:
				system("cls");
				cout << "Введите новое имя файла: ";
				cin >> name;
				name = name + ".jpg";
				cout << "Файл " << name << " сохранен под новым именем!" << endl;
				system("pause");
				break;
			case 5:
				system("cls");
				cout << "Введите имя файла для печати: ";
				cin >> name;
				name = name + ".jpg";
				cout << "Файл " << name << " напечатан!" << endl;
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
			cout << "Редактор - " << n << " :\n" << endl;
			cout << "1. Создание файла\n" << "2. Открытие файла\n" << "3. Сохранение файла\n"
				<< "4. Сохранение под новым именем\n" << "5. Печать\n" << "6. Закрытие\n" << endl;
			cout << "Ваш выбор: ";
			int var;
			cin >> var;
			switch (var)
			{
			case 1:
				system("cls");
				cout << "Введите имя файла: ";
				cin >> name;
				name = name + ".xlsx";
				cout << "Excel файл " << name << " создан!" << endl;
				system("pause");
				break;
			case 2:
				system("cls");
				cout << "Введите имя файла: ";
				cin >> name;
				name = name + ".xlsx";
				cout << "Excel файл " << name << " открыт!" << endl;
				system("pause");
				break;
			case 3:
				system("cls");
				cout << "Введите имя файла: ";
				cin >> name;
				name = name + ".xlsx";
				cout << "Файл " << name << " сохранен!" << endl;
				system("pause");
				break;
			case 4:
				system("cls");
				cout << "Введите новое имя файла: ";
				cin >> name;
				name = name + ".xlsx";
				cout << "Файл " << name << " сохранен под новым именем!" << endl;
				system("pause");
				break;
			case 5:
				system("cls");
				cout << "Введите имя файла для печати: ";
				cin >> name;
				name = name + ".xlsx";
				cout << "Файл " << name << " напечатан!" << endl;
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
			cout << "Редактор - " << n << " :\n" << endl;
			cout << "1. Создание файла\n" << "2. Открытие файла\n" << "3. Сохранение файла\n"
				<< "4. Сохранение под новым именем\n" << "5. Печать\n" << "6. Закрытие\n" << endl;
			cout << "Ваш выбор: ";
			int var;
			cin >> var;
			switch (var)
			{
			case 1:
				system("cls");
				cout << "Введите имя файла: ";
				cin >> name;
				name = name + ".pdf";
				cout << "PDF файл " << name << " создан!" << endl;
				system("pause");
				break;
			case 2:
				system("cls");
				cout << "Введите имя файла: ";
				cin >> name;
				name = name + ".pdf";
				cout << "PDF файл " << name << " открыт!" << endl;
				system("pause");
				break;
			case 3:
				system("cls");
				cout << "Введите имя файла: ";
				cin >> name;
				name = name + ".pdf";
				cout << "Файл " << name << " сохранен!" << endl;
				system("pause");
				break;
			case 4:
				system("cls");
				cout << "Введите новое имя файла: ";
				cin >> name;
				name = name + ".pdf";
				cout << "Файл " << name << " сохранен под новым именем!" << endl;
				system("pause");
				break;
			case 5:
				system("cls");
				cout << "Введите имя файла для печати: ";
				cin >> name;
				name = name + ".pdf";
				cout << "Файл " << name << " напечатан!" << endl;
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


#include<iostream>
#include<string>
#include"Editor.h"

using namespace std;


int main()
{
	setlocale(0, "");

	Editor* ed = nullptr;
	Document* doc = nullptr;
	cout << "РАБОТА С ФАЙЛАМИ" << endl;
	cout << "----------------\n" << endl;
	cout << "Выберите формат файла\n" << endl;
	cout << "1. Текстовый\n" << "2. Графический\n" << "3. Excel\n"
		<< "4. PDF\n" << "5. Выход\n" << endl;
	cout << "Ваш выбор: ";
	int var;
	cin >> var;
	switch (var)
	{
	case 1:
		ed = new TextEditor;
		break;
	case 2:
		ed = new GraphicEditor;
		break;
	case 3:
		ed = new ExcelEditor;
		break;
	case 4:
		ed = new PDFEditor;
		break;
	case 5:
		exit(0);
	default:
		break;
	}
	doc = ed->creat();
	string name = doc->get_name();
	ed->menu_editor(name);

	system("pause");
}
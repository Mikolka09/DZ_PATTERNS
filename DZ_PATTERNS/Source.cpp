#include<iostream>
#include<string>
#include"Editor.h"

using namespace std;


int main()
{
	setlocale(0, "");

	Editor* ed = nullptr;
	Document* doc = nullptr;
	cout << "������ � �������" << endl;
	cout << "----------------\n" << endl;
	cout << "�������� ������ �����\n" << endl;
	cout << "1. ���������\n" << "2. �����������\n" << "3. Excel\n"
		<< "4. PDF\n" << "5. �����\n" << endl;
	cout << "��� �����: ";
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
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include"Editor.h"
#include<Windows.h>
#include"Vectorina.h"

using namespace std;


int main()
{
	setlocale(0, "");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << "\n\n\n" << endl;
	cout << "\t\tПодождите пожалуйста, Викторина загружается:\n" << endl;
	cout << "\t\t\t\t";
	for (size_t i = 0; i < 10; i++)
	{
		cout << "*";
		Sleep(500);
	}
	system("cls");
	cout << "\n\n\n" << endl;
	cout << "\t\tДОБРО ПОЖАЛОВАТЬ НА МАЛЕНЬКУЮ ВИКТОРИНУ!!!" << endl;
	cout << "\t\t------------------------------------------\n" << endl;
	cout << "\tПРАВИЛА: На каждый вопрос Викторины у Вас будет только ТРИ попытки ответить правильно.\n"
		<< "\t\t Если Вы используете все ТРИ попытки, Вы ПРОИГРАЕТЕ!!!\n"
		<< "\t\t Если ответите на все вопросы правильно получите приз - \n"
		<<"\t\t ПОПОЛНЕНИЕ МОБИЛЬНОГО ТЕЛЕФОНА НА 1000 ГРН.\n" << endl;
	cout << "\t\t Желаете поучаствовать?" << endl;
	cout << "\t\t   1.ДА      2.НЕТ" << endl;
	cout << "\t\t Ваш выбор: ";
	int var;
	cin >> var;
	cin.ignore();
	switch (var)
	{
	case 1:
	{
		QustionsProxy* qp = new QustionsProxy;	
		AnswersProxy* ans = new AnswersProxy;
		int n = 1;
		bool res = true;
		while (n != 6)
		{
			bool cont = true;
			while (cont)
			{
				if (IQustions::count == 3)
				{
					res = false;
					break;
				}
				else
				{
					system("cls");
					cout << "\n\n\n";
					cout << "Вопрос номер - " << n << endl << endl;
					cout << qp->getQustion(n) << endl << endl;
					cout << "Ваше ответ: ";
					char buf[30];
					cin.getline(buf, 30);
					char* buff = new char[strlen(buf) + 1];
					strcpy(buff, buf);
					string answer;
					answer = buff;
					if (answer == ans->getAnswers(n))
					{
						cont = false;
						n++;
					}
					else
						cont = true;
				}

			}
			if (res == false)
				n = 6;
			
		}
		if (res == false)
		{
			system("cls");
			cout << "\n\n\n";
			cout << "\t\tУПС!!! ВЫ ПРОГРАЛИ!!! МОЖЕТ ПОВЕЗЕТ В СЛЕДУЮЩИЙ РАЗ!!!\n" << endl;
		}
		else
		{
			system("cls");
			cout << "\n\n\n";
			cout << "\t\tПОЗДРАВЛЯЮ ВЫ ВЫГРАЛИ!! МОЖЕТЕ ПОЛУЧИТЬ ПРИЗ!!\n" << endl;
			cout << "\t\tВведите свой номер телефона: ";
			string tel;
			cin >> tel;
			system("cls");
			cout << "\n\n\n" << endl;
			cout << "\t\tДЕНЬГИ ОТПРАВЛЕНЫ НА ВАШ НОМЕР ТЕЛЕФОНА - " << tel << endl << endl;
			cout << "\t\tСПАСИБО ЗА ИГРУ!!\n" << endl;
		}
		break;
	}
	case 2:
		exit(0);
		break;
	default:
		break;
	}

	system("pause");
}
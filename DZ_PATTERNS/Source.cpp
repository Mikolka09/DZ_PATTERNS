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
	switch (var)
	{
	case 1:
	{
		QustionsProxy* qp = new QustionsProxy;	
		
		int n = 1;
		bool res = true;
		while (n != 6)
		{
			bool cont = true;
			while (cont)
			{
				if (IVectorina::count == 3)
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
					string answer;
					cin >> answer;
					if (answer == qp->getAnswers(n))
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
			int tel;
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
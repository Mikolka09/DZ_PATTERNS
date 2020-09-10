#pragma once

#include<iostream>
#include<string>
#include<fstream>
#include <map>

using namespace std;


class IVectorina
{

public:
	static int count;
	virtual string getQustion(int nomer) = 0;
	virtual string getAnswers(int nomer) = 0;
};

int IVectorina::count = 0;


class Qustions : public IVectorina
{
	map<int, string> qustions;
public:
	Qustions()
	{
		qustions[1] = "1. Как называется первый голливудский цветной фильм?";
		qustions[2] = "2. В каком городе был открыт первый кинотеатр?";
		qustions[3] = "3. Какая кинопремия вручается в Каннах?";
		qustions[4] = "4. Какой советский фильм считается первым цветным фильмом?";
		qustions[5] = "5. Этот фильм называют самым известным деревенским детективом СССР. Что это за фильм?";
	}
	
	string getQustion(int nomer) override
	{
		if (qustions.count(nomer))
		{
			count++;
			return qustions[nomer];
		}
		else
			return "no qustions";
	}

};

class Answers :IVectorina
{
	map<int, string> answers;
public:
	Answers()
	{
		answers[1] = "Жертвы моря";
		answers[2] = "Париж";
		answers[3] = "Золотая пальмовая ветвь";
		answers[4] = "Броненосец Потемкин";
		answers[5] = "Анискин";
	}
	string getAnswers(int nomer) override
	{
		if (answers.count(nomer))
			return answers[nomer];
		else
			return "no answer";
	}
};

class QustionsProxy : IVectorina
{
	map<int, string> qustions_cash;
	Qustions* qus;
public:
	string getAnswers(int nomer) override {}
	string getQustion(int nomer) override
	{
		if (qustions_cash.count(nomer))
		{
			count++;
			return qustions_cash[nomer];
		}
		else
		{
			qus = new Qustions;
			string qustion = qus->getQustion(nomer);
			qustions_cash[nomer] = qustion;
			delete qus;
			return qustion;
		}

	}

};

class AnswersProxy : IVectorina
{
	map<int, string> answers_cash;
	Answers* ans;

public:
	string getQustion(int nomer) override {}
	string getAnswers(int nomer) override
	{
		if (answers_cash.count(nomer))
			return answers_cash[nomer];
		else
		{
			ans = new Answers;
			string answer = ans->getAnswers(nomer);
			answers_cash[nomer] = answer;
			delete ans;
			return answer;
		}
	}
};

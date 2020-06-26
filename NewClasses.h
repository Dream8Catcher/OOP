#ifndef NEWCLASSES_H
#define NEWCLASSES_H
/*
1) Классы: 	abstract Processor(Clock, value, virtual calcValue), 
			Computer(coefficient, PC_mark, virtual calcValue), 
			ComputerWithMonitor(monitor_mark, monitor_value, diagonal, calcValue)

2) in main creat: Monitor* list = new Monitor[5]; + заполнить список вручную
3) list[1].getName()
4) Список инициализации, глубокое копирование, деструктор, методы
5) Перегрузить: ввод\вывод, присваивания, + & - на число
*/

#include <iostream>
#include <cassert>
#include <cstring>

using std::ostream;
using std::istream;
using std::cout;
using std::cin;
using std::endl;

class  Processor
{
private:
	double clock;
	double value;

public:
	//Список инициализации
	explicit Processor(double _clock, double _val) : clock( _clock ), value(_val)
    {}
    Processor(){}
    ~Processor(){}

	//Глубокое копирование
	Processor(const Processor& source);

	//Присваивание
	Processor& operator = (const Processor& source);

	//Ввод\вывод через >>\<<	
	friend ostream& operator << (ostream& out, Processor &_s);
	friend istream& operator >> (istream &in, Processor &_s);

	virtual void calcValue() = 0;

	void setValue(double _v){ value = _v;}
	double getValue(){ return value;}
	double getClock() { return clock; }

};

class Computer : public Processor
{
private:
	int coefficient;
	char* PC_mark;
	int PC_mark_len;

public:

	int getCoefficient() { return coefficient; }
	char* getPC_mark() { return PC_mark; }
	virtual void calcValue ()
	{
		setValue(coefficient*getClock());
	}
	Computer(){}
	//Список инициализации
	Computer (int _coef, const char* _mark, double _clock, double _val) : Processor(_clock, _val), coefficient(_coef)
	{
		assert(_mark);

		PC_mark_len = strlen(_mark)+1;
		PC_mark = new char[PC_mark_len];
		
		for (int i = 0; i < PC_mark_len; ++i)
			PC_mark[i] = _mark[i];

		PC_mark[PC_mark_len] = '\0';

		calcValue();
	}

	//Глубокое копирование
	Computer(const Computer& source);

	//Присваивание
	Computer& operator = (const Computer& source);

	// + & - на число
	void operator + (double _value) { setValue(getValue() + _value); }
	void operator - (double _value) { setValue(getValue() - _value); }

	//Ввод\вывод через >>\<<
	friend ostream& operator << (ostream& out, Computer &_s);
	friend istream& operator >> (istream &in, Computer &_s);

	~Computer(){ 
		delete[] PC_mark;
	}
};

class ComputerWithMonitor : public Computer
{
private:
	char* monitor_mark;
	int m_mark_len;
	int monitor_value;
	double diagonal;

public:
	//Список инициализации
	ComputerWithMonitor (char* m_mark, int m_value, double _diag, int _coef, const char* pc_mark, double _clock, double _val) 
	: Computer(_coef, pc_mark, _clock, _val), monitor_mark(m_mark), monitor_value(m_value), diagonal(_diag)
	{
		assert(m_mark);

		m_mark_len = strlen(m_mark)+1;
		monitor_mark = new char[m_mark_len];
		
		for (int i = 0; i < m_mark_len; ++i)
			monitor_mark[i] = m_mark[i];

		monitor_mark[m_mark_len] = '\0';

		calcValue();
	}

	//Глубокое копирование
	ComputerWithMonitor(const ComputerWithMonitor& source);

	//Присваивание
	ComputerWithMonitor& operator = (const ComputerWithMonitor& source);

	//Ввод\вывод через >>\<<
	friend ostream& operator << (ostream& out, ComputerWithMonitor &_s);
	friend istream& operator >> (istream &in, ComputerWithMonitor &_s);

	// + & - на число
	void operator + (double _value) { setValue(getValue() + _value); }
	void operator - (double _value) { setValue(getValue() - _value); }

	~ComputerWithMonitor(){ 
		delete[] monitor_mark;
	}

	virtual void calcValue ()
	{
		setValue(getCoefficient() * getClock() + monitor_value);
	}
};
#endif
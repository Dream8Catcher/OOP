#ifndef NEWCLASSES_H
#define NEWCLASSES_H

#include <iostream>
//#include <cstring>

using std::ostream;
using std::istream;

class  Processor
{
private:
	char* m_name;
	double m_clock;
	double m_value;

public:
	// Конструктор
	Processor(const char* _n = "undefined", double _c = 0., double _val = 0.);
	
	// Глубокое копирование
	Processor(const Processor& src);

	// Присваивание
	Processor& operator = (const Processor& src);

	// Деструктор
	virtual ~Processor();

	//Ввод\вывод через >>\<<	
	friend ostream& operator << (ostream& out, const Processor &_s);
	friend istream& operator >> (istream& in, Processor &_s);

	virtual /*double*/ void calcValue();

	void setValue(double _v)
	{ m_value = _v; }
	double getValue() const
	{ return m_value; }
	double getClock() const 
	{ return m_clock; }

};

class Computer : public Processor
{
private:
	char* PC_mark;
	int coefficient;

public:
	// Конструкторы
	Computer (const char* _mark = "undefined", int _coef = 0, 
			  const char* _name = "undefined", double _c = 0., double _val = 0.);
	Computer (const char* _mark, int _coef, const Processor& _src);
	//Глубокое копирование
	Computer(const Computer& src);

	//Присваивание
	Computer& operator = (const Computer& src);

	//Ввод\вывод через >>\<<
	friend ostream& operator << (ostream& out, const Computer &_s);
	friend istream& operator >> (istream &in, Computer &_s);

	~Computer();
	// + & - на число
	/*Computer*/void operator + (double _value) { setValue(getValue() + _value); }
	/*Computer*/void operator - (double _value) { setValue(getValue() - _value); }

	virtual /*double*/ void calcValue ()
	{
		setValue(coefficient*getClock());
	}
	int getCoefficient() const { return coefficient; }
	char* getPC_mark() const { return PC_mark; }
};

#endif
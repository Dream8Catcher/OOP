#include "newclasses.h"
#include <iostream>
#include <cstring>

using std::ostream;
using std::istream;
using std::cout;
using std::cin;
using std::endl;

/******************Processor******************/
// Конструктор
Processor::Processor(const char* _n, double _c, double _val) : m_clock(_c), m_value(_val)
{
	m_name = new char[std::strlen(_n)+1];
	std::strcpy(m_name, _n);
}

// Глубокое копирование
Processor::Processor(const Processor& src)
{
	m_name = new char[std::strlen(src.m_name)+1];
	std::strcpy(m_name, src.m_name);

	m_clock = src.m_clock;
	m_value = src.m_value;	
}

// Присваивание
Processor& Processor::operator = (const Processor& src)
{
	if (this == &src) return *this;
	delete [] m_name;
	if (src.m_name)
	{
		m_name = new char[std::strlen(src.m_name)+1];
		std::strcpy(m_name, src.m_name);	
	}
	m_clock = src.m_clock;
	m_value = src.m_value;
	return *this;
}

// Деструктор
Processor::~Processor()
{
	delete [] m_name;
}

// Ввод\вывод через >>\<<
ostream& operator << (ostream& out, const Processor & _s)
{
	out << "m_clock: " << _s.m_clock << "\tvalue: " << _s.m_value << endl;
	return out;
}

istream& operator >> (istream &in, Processor &_s)
{
	//cout << "Name is: "; in.getline(in, _s.m_name);
	cout << "\nClock is: "; in >> _s.m_clock;
	cout << "\nValue is: "; in >> _s.m_value;
	return in;
}

/*double*/ 
void Processor::calcValue()
{
	setValue(m_value / m_clock);
	//return (m_value / m_clock);
}

/******************Computer******************/
// Конструкторы
Computer::Computer (const char* _mark, int _coef, 
			  		const char* _name, double _c, double _val) 
			  			: Processor(_name, _c, _val), coefficient(_coef)
	{
		if (_mark){
			PC_mark = new char[strlen(_mark)+1];
			std::strcpy(PC_mark, _mark);
		}
		else
			PC_mark = nullptr;
		calcValue();
	}
Computer::Computer (const char* _mark, int _coef, const Processor& _src) 
					: Processor(_src), coefficient(_coef)
{
	if (_mark){
		PC_mark = new char[strlen(_mark)+1];
		std::strcpy(PC_mark, _mark);
	}
	else
		PC_mark = nullptr;
	calcValue();
}
// Глубокое копирование
Computer::Computer(const Computer& src) : Processor(src), coefficient(src.coefficient)
{
	if (src.PC_mark)
	{
		PC_mark = new char[strlen(src.PC_mark+1)];
		std::strcpy(PC_mark, src.PC_mark);
	}
	else 
		PC_mark = nullptr;
}

// Присваивание
Computer& Computer::operator = (const Computer& src)
{
	if (&src == this) return *this;
	Processor::operator=(src);
	delete [] PC_mark;
	PC_mark = new char[strlen(src.PC_mark+1)];
	std::strcpy(PC_mark, src.PC_mark);
	return *this;
}

// Ввод\вывод через >>\<<
ostream& operator << (ostream& out, const Computer & _s)
{
	out << (const Processor&) _s;
	out << "\nPC_mark: " << _s.PC_mark << "\nCoefficient: " << _s.coefficient << endl;

	return out;
}

istream& operator >> (istream &in, Computer &_s)
{
	in >> (Processor&) _s;
	cout << "PC_mark is: "; //in.getline(in, *(_s.PC_mark), in.widen('\n'));
	cout << "\nCoefficient is: "; 
	in >> _s.coefficient;

	return in;
}

Computer::~Computer()
{
	delete [] PC_mark;
}

/******************ComputerWithMonitor******************/
// Глубокое копирование
// ComputerWithMonitor::ComputerWithMonitor(const ComputerWithMonitor& src)
// {
// 	m_mark_len = src.m_mark_len;

// 	if (src.monitor_mark)
// 	{
// 		monitor_mark = new char[m_mark_len];
		
// 		for (int i = 0; i < m_mark_len; ++i)
// 			monitor_mark[i]=src.monitor_mark[i];
// 	}
// 	else	{
// 		monitor_mark = NULL;
// 	}
// }

// //Присваивание
// ComputerWithMonitor& ComputerWithMonitor::operator = (const ComputerWithMonitor& src)
// {
// 	if (this == &src) return *this;
// 	delete [] monitor_mark;

// 	monitor_value = src.monitor_value;
// 	diagonal = src.diagonal;
// 	m_mark_len = src.m_mark_len;

// 	if (src.monitor_mark)
// 	{
// 		monitor_mark = new char[m_mark_len];
		
// 		for (int i = 0; i < m_mark_len; ++i)
// 			monitor_mark[i] = src.monitor_mark[i];
// 	}
// 	else	monitor_mark = NULL;

// 	return *this;
// }

// // Ввод\вывод через >>\<<
// ostream& operator << (ostream& out, ComputerWithMonitor & _s)
// {
// 	// out << (Computer &) _s;
// 	out << "m_clock: " << _s.getClock() << "\tvalue: " << _s.getValue() << endl;
// 	out << "coefficient: " << _s.getCoefficient() << "\nPC mark: " << _s.getPC_mark() << endl;
// 	return out;
// }

// istream& operator >> (istream &in, ComputerWithMonitor &_s)
// {
// 	in >> _s.monitor_mark;
// 	in >> _s.monitor_value;
// 	in >> _s.diagonal;
// 	return in;
// }
/*
1) Классы: 	abstract Processor(Clock, value, virtual calcValue), 
			Computer(coefficient, PC_mark, virtual calcValue), 
			ComputerWithMonitor(monitor_mark, monitor_value, diagonal, calcValue)

2) in main creat: Monitor* list = new Monitor[5]; + заполнить список вручную
3) list[1].getName()
4) Список инициализации, глубокое копирование, деструктор, методы
5) Перегрузить: ввод\вывод, присваивания, + & - на число
*/

#include "newclasses.h"
#include <iostream>
#include <cassert>
#include <cstring>

using std::ostream;
using std::istream;
using std::cout;
using std::cin;
using std::endl;

/******************Processor******************/
// Глубокое копирование
Processor::Processor(const Processor& source)
{
	clock = source.clock;
	value = source.value;	
}

// Присваивание
Processor& Processor::operator = (const Processor& source)
{
	if (this == &source) return *this;
	clock = source.clock;
	value = source.value;
	return *this;
}

// Ввод\вывод через >>\<<
ostream& operator << (ostream& out, Processor & _s)
{
	out << "clock: " << _s.getClock() << "\tvalue: " << _s.getValue() << endl;
	return out;
}

istream& operator >> (istream &in, Processor &_s)
{
	in >> _s.clock;
	in >> _s.value;
	return in;
}

/******************Computer******************/
// Глубокое копирование
Computer::Computer(const Computer& source)
{
	coefficient = source.coefficient;
	PC_mark_len = source.PC_mark_len;
	//clock = source.clock;
	//value = source.value;

	if (source.PC_mark)
	{
		PC_mark = new char[PC_mark_len];
		
		for (int i = 0; i < PC_mark_len; ++i)
			PC_mark[i]=source.PC_mark[i];
	}
	else	PC_mark = NULL;
}

// Присваивание
Computer& Computer::operator = (const Computer& source)
{
	if (this == &source) return *this;
	delete [] PC_mark;

	coefficient = source.coefficient;
	PC_mark_len = source.PC_mark_len;

	if (source.PC_mark)
	{
		PC_mark = new char[PC_mark_len];
		
		for (int i = 0; i < PC_mark_len; ++i)
			PC_mark[i]=source.PC_mark[i];
	}
	else	PC_mark = NULL;

	return *this;
}

// Ввод\вывод через >>\<<
ostream& operator << (ostream& out, Computer & _s)
{
	out << "clock: " << _s.getClock() << "\tvalue: " << _s.getValue() << endl;
	out << "coefficient: " << _s.getCoefficient() << "\nPC mark: " << _s.getPC_mark() << endl;
	return out;
}

istream& operator >> (istream &in, Computer &_s)
{
	//in >> _s.clock;
	//in >> _s.value;
	in >> _s.coefficient;
	in >> _s.PC_mark;
	return in;
}

/******************ComputerWithMonitor******************/
// Глубокое копирование
ComputerWithMonitor::ComputerWithMonitor(const ComputerWithMonitor& source)
{
	m_mark_len = source.m_mark_len;

	if (source.monitor_mark)
	{
		monitor_mark = new char[m_mark_len];
		
		for (int i = 0; i < m_mark_len; ++i)
			monitor_mark[i]=source.monitor_mark[i];
	}
	else	{
		monitor_mark = NULL;
	}
}

//Присваивание
ComputerWithMonitor& ComputerWithMonitor::operator = (const ComputerWithMonitor& source)
{
	if (this == &source) return *this;
	delete [] monitor_mark;

	monitor_value = source.monitor_value;
	diagonal = source.diagonal;
	m_mark_len = source.m_mark_len;

	if (source.monitor_mark)
	{
		monitor_mark = new char[m_mark_len];
		
		for (int i = 0; i < m_mark_len; ++i)
			monitor_mark[i] = source.monitor_mark[i];
	}
	else	monitor_mark = NULL;

	return *this;
}

// Ввод\вывод через >>\<<
ostream& operator << (ostream& out, ComputerWithMonitor & _s)
{
	out << "clock: " << _s.getClock() << "\tvalue: " << _s.getValue() << endl;
	out << "coefficient: " << _s.getCoefficient() << "\nPC mark: " << _s.getPC_mark() << endl;
	return out;
}

istream& operator >> (istream &in, ComputerWithMonitor &_s)
{
	in >> _s.monitor_mark;
	in >> _s.monitor_value;
	in >> _s.diagonal;
	return in;
}
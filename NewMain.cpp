/*
1) Классы: 	Processor(Clock, value, virtual calcValue), 
			Computer(coefficient, PC_mark, virtual calcValue), 
			ComputerWithMonitor(monitor_mark, monitor_value, diagonal, calcValue)

2) in main creat: Monitor* list = new Monitor[5]; + заполнить список вручную
3) list[1].getName()
4) Список инициализации, глубокое копирование, деструктор, методы
5) Перегрузить: ввод\вывод, присваивания, + & - на число
*/


#include <iostream>
#include "NewClasses.h"

int main(){
	const char* mark = "SyncMaster";
	int coeff = 5;
	double clock = 1.4;
	double value = 14.0;
	Computer comp = Computer(coeff, mark, clock, value);
	cout << "value before: " << comp.getValue() << endl;
	comp + 6;
	cout <<  "value after: " << comp.getValue();
	cout << comp << endl;
	return 0;
}
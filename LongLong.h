//создать класс LongLong для работы с целыми числами из 64 бит число должно быть представлено двумя полями: 
//long - старшая часть, unsigned long - младшая часть должны быть реализованы операции сложения, умножения и сравнения

#pragma once
#include <iostream>
#include <string>
#include <cmath>
#include <sstream>
class LongLong
{
private:
	long int higher;
	unsigned long int lower;
	int count;
	bool minus; //false - минуса нет, true - есть
	int Scale(int);
	long int Merge();
public:
	LongLong();
	LongLong(long int _higher, unsigned long int _lower, int _count);

	std::string toString();

	void Set_higher(long int);
	void Set_lower(unsigned long int);
	void Set_count(int);

	long int Get_higher();
	unsigned long int Get_lower();
	int Get_count();

	LongLong operator + (LongLong);
	LongLong operator * (LongLong);
	bool operator > (LongLong);
	bool operator < (LongLong);
	bool operator == (LongLong);
};


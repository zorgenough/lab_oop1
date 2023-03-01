//������� ����� LongLong ��� ������ � ������ ������� �� 64 ��� ����� ������ ���� ������������ ����� ������: 
//long - ������� �����, unsigned long - ������� ����� ������ ���� ����������� �������� ��������, ��������� � ���������

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
	bool minus; //false - ������ ���, true - ����
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


#include "LongLong.h"

int LongLong::Scale(int count)
{
	int scale = 1;
	for (int i = 0; i < count; i++)
	{
		scale *= 10;
	}
	return scale;
}

long int LongLong::Merge()
{
	if (minus)
	{
		return higher * Scale(count) - lower;
	}
	else
	{
		return higher* Scale(count) + lower;
	}
}

LongLong::LongLong()
{
	higher = 0;
	lower = 0;
	count = 1;
	minus = false;
}

LongLong::LongLong(long int _higher, unsigned long int _lower, int _count)
{
	higher = _higher;
	lower = _lower;
	minus = higher < 0;
	count = _count;
}

std::string LongLong::toString()
{
	std::stringstream stream;
	stream << higher;
	std::string low = std::to_string(lower);
	int low_size = low.size();
	while (count > low_size)
	{
		low = '0' + low;
		low_size++;
	}
	stream << low;
	std::string str;
	stream >> str;
	return str;
}

void LongLong::Set_higher(long int _higher)
{
	higher = _higher;
}

void LongLong::Set_lower(unsigned long int _lower)
{
	lower = _lower;
}

void LongLong::Set_count(int _count)
{
	count = _count;
}

long int LongLong::Get_higher()
{
	return higher;
}

unsigned long int LongLong::Get_lower()
{
	return lower;
}

int LongLong::Get_count()
{
	return count;
}

LongLong LongLong::operator+(LongLong object)
{
	long int first = Merge();
	long int second = object.Merge();
	long int result = first + second;
	LongLong temp;
	if (count > object.count)
	{
		temp.count = count;
	}
	else
	{
		temp.count = object.count;
	}
	temp.lower = abs(result % Scale(temp.count));
	temp.higher = result / Scale(temp.count);
	temp.minus = temp.higher < 0;
	return temp;
}

LongLong LongLong::operator*(LongLong object)
{
	long int first = Merge();
	long int second = object.Merge();
	long int result = first * second;
	LongLong temp;
	if (count > object.count)
	{
		temp.count = count;
	}
	else
	{
		temp.count = object.count;
	}
	temp.lower = abs(result % Scale(temp.count));
	temp.higher = result / Scale(temp.count);
	temp.minus = temp.higher < 0;
	return temp;
}

bool LongLong::operator>(LongLong object)
{
	long int first = Merge();
	long int second = object.Merge();
	return first > second;
}

bool LongLong::operator<(LongLong object)
{
	long int first = Merge();
	long int second = object.Merge();
	return first < second;
}

bool LongLong::operator==(LongLong object)
{
	long int first = Merge();
	long int second = object.Merge();
	return first == second;
}

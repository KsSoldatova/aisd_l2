#include <iostream>
#include <cstdlib>
#include <math.h>
#include <conio.h>
#include <complex>
using namespace std;


template <typename T>
class Broken_Line
{
private:
	struct Points
	{
		T x = 0, y = 0;
	};
	Points* line = NULL;
	int size = 0, more_number = 0;

public:
	Broken_Line<T>(int size = 0)
	{
		if (size == 0)
		{
			this->size = size;
			return;
		}
		more_number = size * 2;
		line = new Points[more_number];
		this->size = size;
	}
	int Get_size() const { return size; }
	int Get_more_points() const { return more_number; }


	friend std::ostream& operator << (std::ostream& os, const Broken_Line point)
	{
		for (int i = 0; i < point.Get_size(); i++)
		{
			os << '(' << point[i].x << ';' << point[i].y << ')' << endl;

		}
		return os;
	}
	

	Points operator [] (int other_point) const //для чтения
	{
		if (other_point >= 0 && other_point < size)
			return (line[other_point]);
		throw "!invalid index!";
	}

	Points& operator [] (int other_point) //для записи
	{
		if (other_point >= 0 && other_point < size)
			return (line[other_point]);
		throw "!invalid index!";
	}

	Broken_Line operator +(Broken_Line& other) //сложение двух линий
	{
		if (this->size + other.Get_size() >= this->more_number)
		{
			this->more_number = (this->Get_more_points() + other.Get_size());
			Broken_Line* tmpline = new Broken_Line[this->Get_more_points()];
			tmpline = this;
			*this = *tmpline;
		}
		for (int i = 0, j = this->size; i < other.Get_size(); i++, j++)
		{
			this->line[j] = other[i];
		}
		this->size += other.Get_size();
		return *this;
	}

	Broken_Line operator +(Points& point)//сложение линии и точки, добавление точки в конец
	{
		this->size++;
		if (this->Get_size() == this->Get_more_points())
		{
			this->more_number *= 2;
			Broken_Line* tmpline = new Broken_Line[this->Get_more_points()];
			tmpline = this;
			*this = *tmpline;
		}
		(*this)[this->Get_size() - 1] = point;
		return *this;
	}
	friend Broken_Line operator +(Points& point, Broken_Line& tmp_line)//сложение линии и точки, добавление точки в начало
	{
		tmp_line.size++;
		if (tmp_line.Get_size() == tmp_line.Get_more_points())
		{
			tmp_line.more_number *= 2;
			Broken_Line* tline = new Broken_Line[tmp_line.Get_more_points()];
			tline = &tmp_line;
			tmp_line = *tline;
		}
		for (int i = tmp_line.Get_size() - 1; i != 0; i--)
		{
			tmp_line[i] = tmp_line[i - 1];
		}
		tmp_line[0] = point;
		return tmp_line;
	}
	Broken_Line operator =(const Broken_Line& tmp_line)
	{
		for (int i = 0; i < tmp_line.Get_size(); i++)
		{
			(*this)[i] = tmp_line[i];
		}
		return *this;
	}
	bool operator == (const Broken_Line& other_line)
	{
		if (this->Get_size() == other_line.Get_size())
		{
			for (int i = 0; i < this->Get_size(); i++)
			{
				if ((*this)[i].x != other_line[i].x || (*this)[i].y != other_line[i].y)
					return false;
			}
			return true;
		}
		return false;
	}
	bool operator != (const Broken_Line& other_line)
	{
		if (this->Get_size() == other_line.Get_size())
		{
			for (int i = 0; i < this->Get_size(); i++)
			{
				if ((*this)[i].x != other_line[i].x || (*this)[i].y != other_line[i].y)
					return true;
			}
			return false;
		}
		return true;
	}
};
//template <class T>
//std::ostream& Broken_Line<std::complex<float>>::operator >> (std::ostream& os, const Broken_Line<std::complex<float>>point)
//{
//	for (int i = 0; i < point.Get_size(); i++)
//	{
//		os >> point[i].x.real();
//		os >> point[i].x.imag();
//		os >> point[i].y.real();
//		os >> point[i].y.imag();
//	}
//	return os;
//}
//template <class T>
//std::ostream& operator >> (std::ostream& os, const Broken_Line<std::complex<double>>point)
//{
//	for (int i = 0; i < point.Get_size(); i++)
//	{
//		os >> point[i].x.real();
//		os >> point[i].x.imag();
//		os >> point[i].y.real();
//		os >> point[i].y.imag();
//	}
//	return os;
//}
template <class T>
Broken_Line<std::complex<float>> operator +(Broken_Line<std::complex<float>>& other) //сложение двух линий
{
	if (this->size + other.Get_size() >= this->more_number)
	{
		this->more_number = (this->Get_more_points() + other.Get_size());
		Broken_Line<std::complex<float>>* tmpline = new Broken_Line<std::complex<float>>[this->Get_more_points()];
		tmpline = this;
		*this = *tmpline;
	}
	for (int i = 0, j = this->size; i < other.Get_size(); i++, j++)
	{
		this->line[j] = other[i];
	}
	this->size += other.Get_size();
	return *this;
}


template <class T>
Broken_Line<T> CreatingLine(Broken_Line<T>& start_line) {
	T x, y;
	for (int i = 0; i < start_line.Get_size(); i++)
	{
		std::cout << endl << "Enter the coordinates of the point:" << endl;
		std::cout << endl << "x = ";
		std::cin >> x;
		std::cout << endl << "y = ";
		std::cin >> y;
		start_line[i].x = x;
		start_line[i].y = y;
	}
	return start_line;
}
template <class T>
Broken_Line<std::complex<T>> CreatingLine(Broken_Line<std::complex<T>>& start_line) {
	complex<T> x = 0, y = 0;
	for (int i = 0; i < start_line.Get_size(); i++)
	{
		cout << endl << "Enter the coordinates of the point:" << endl;
		cout << "x: ";
		cin >> x;
		cout << "y: ";
		cin >> y;
		start_line[i].x = x;
		start_line[i].y = y;
	}
	return start_line;
}
//template <class T>
//Broken_Line<std::complex<double>> CreatingLine(Broken_Line<std::complex<double>>& start_line) {
//	complex<double> x = 0, y = 0;
//	for (int i = 0; i < start_line.Get_size(); i++)
//	{
//		cout << endl << "Enter the coordinates of the point:" << endl;
//		cout << "x: ";
//		cin >> x;
//		cout << "y: ";
//		cin >> y;
//		start_line[i].x = x;
//		start_line[i].y = y;
//	}
//	return start_line;
//}

template <class T>
int IndexPoint(Broken_Line<T>& start_line, bool flag)
{
	system("cls");
	flag = true;
	int index = 0;
	while (flag)
	{
		int choice = 0;
		while (flag)
		{
			std::cout << endl << "Enter index:" << endl;
			std::cin >> index;
			try {
				if (index <= 0 || index > start_line.Get_size()) throw "!There is no such index point!";
				flag = false;
			}
			catch (const char* ex)
			{
				std::cout << ex << endl;
				std::cout << endl << "Try again" << endl;
			}
		}
		flag = true;
		while (flag)
		{
			try {
				std::cout << "Select:" << endl;
				std::cout << "1) Read coordinates";
				std::cout << "   2) Change coordinates" << endl;
				cin >> choice;
				if (choice != 1 && choice != 2) throw"!There is no such index point";
				flag = false;
			}
			catch (const char* ex)
			{
				std::cout << ex << endl;
				std::cout << endl << "Try again" << endl;
			}
		}
		if (choice == 1) cout << "Coordinates: " << "(" << start_line[index - 1].x << ";" << start_line[index - 1].y << ")" << endl << endl;
		if (choice == 2)
		{
			T x = 0, y = 0;
			std::cout << "Enter x: ";
			std::cin >> x;
			std::cout << "Enter y: ";
			std::cin >> y;
			start_line[index - 1].x = x;
			start_line[index - 1].y = y;
			std::cout << start_line << endl;
			std::cout << "Coordinates of the point with index " << index << " = (" << start_line[index - 1].x << "; " << start_line[index - 1].y << ")" << endl << endl;
		}
		break;
	}
	return -1;
}
template <class T>
int IndexPoint(Broken_Line<std::complex<float>>& start_line, bool flag)
{
	system("cls");
	flag = true;
	int index = 0;
	while (flag)
	{
		int choice = 0;
		while (flag)
		{
			std::cout << endl << "Enter index:" << endl;
			std::cin >> index;
			try {
				if (index <= 0 || index > start_line.Get_size()) throw "!There is no such index point!";
				flag = false;
			}
			catch (const char* ex)
			{
				std::cout << ex << endl;
				std::cout << endl << "Try again" << endl;
			}
		}
		flag = true;
		while (flag)
		{
			try {
				std::cout << "Select:" << endl;
				std::cout << "1) Read coordinates";
				std::cout << "   2) Change coordinates" << endl;
				cin >> choice;
				if (choice != 1 && choice != 2) throw"!There is no such index point";
				flag = false;
			}
			catch (const char* ex)
			{
				std::cout << ex << endl;
				std::cout << endl << "Try again" << endl;
			}
		}
		if (choice == 1) cout << "Coordinates: " << "(" << "(" << start_line[index - 1].x << ")" << "," << "(" << start_line[index - 1].y << ")" << ")" << endl;
		if (choice == 2)
		{
			complex<float> x = 0, y = 0;
			cout << "x: ";
			cin >> x;
			cout << "y: ";
			cin >> y;
			start_line[index - 1].x = x;
			start_line[index - 1].y = y;
			std::cout << start_line << endl;
			std::cout << "Coordinates of the point with index " << index << " = (" << "(" << start_line[index - 1].x << "," << "(" << start_line[index - 1].y << ")" << ")" << endl << endl;
		}
		break;
	}
	return -1;
}
template <class T>
int IndexPoint(Broken_Line<std::complex<double>>& start_line, bool flag)
{
	system("cls");
	flag = true;
	int index = 0;
	while (flag)
	{
		int choice = 0;
		while (flag)
		{
			std::cout << endl << "Enter index:" << endl;
			std::cin >> index;
			try {
				if (index <= 0 || index > start_line.Get_size()) throw "!There is no such index point!";
				flag = false;
			}
			catch (const char* ex)
			{
				std::cout << ex << endl;
				std::cout << endl << "Try again" << endl;
			}
		}
		flag = true;
		while (flag)
		{
			try {
				std::cout << "Select:" << endl;
				std::cout << "1) Read coordinates";
				std::cout << "   2) Change coordinates" << endl;
				cin >> choice;
				if (choice != 1 && choice != 2) throw"!There is no such index point";
				flag = false;
			}
			catch (const char* ex)
			{
				std::cout << ex << endl;
				std::cout << endl << "Try again" << endl;
			}
		}
		if (choice == 1) cout << "Coordinates: " << "(" << "(" << start_line[index - 1].x << ")" << "," << "(" << start_line[index - 1].y << ")" << ")" << endl;
		if (choice == 2)
		{
			complex<double> x = 0, y = 0;
			cout << "x: ";
			cin >> x;
			cout << "y: ";
			cin >> y;
			start_line[index - 1].x = x;
			start_line[index - 1].y = y;
			std::cout << start_line << endl;
			std::cout << "Coordinates of the point with index " << index << " = (" << "(" << start_line[index - 1].x << "," << "(" << start_line[index - 1].y << ")" << ")" << endl << endl;
		}
		break;
	}
	return -1;
}

template <class T>
int SumLine(Broken_Line<T>& start_line, bool flag)
{
	int choice = 0;
	bool flag1 = true;
	flag = true;
	int n = 0;
	std::cout << "Point coordinates of the first broken line" << endl;
	cout << start_line;
	while (flag1)
	{
		try {
			std::cout << "Press the second broken line " << endl;
			flag = true;

			while (flag)
			{
				try
				{
					std::cout << "Number of points: ";
					cin >> n;
					if (n < 2) throw "The numbers of points must be >= 2";
					flag = false;
				}
				catch (const char* ex)
				{
					std::cout << ex << endl;
					std::cout << endl << "Try again" << endl;
				}
			}
		}
		catch (const char* ex)
		{
			std::cout << ex << endl;
			std::cout << endl << "Try again" << endl;
		}
		Broken_Line<T> tmp_line(n);
		Broken_Line<T> new_line = CreatingLine(tmp_line);
		flag1 = false;
		std::cout << "Point coordinates of the second broken line" << endl;
		cout << new_line;
		start_line = start_line + new_line;
		std::cout << endl << "Result: " << endl;
		cout << start_line;
		break;
	}
	return -1;
}
template <class T>
int SumLine(Broken_Line<std::complex<float>>& start_line, bool flag)
{
	int choice = 0;
	bool flag1 = true;
	flag = true;
	int n = 0;
	std::cout << "Point coordinates of the first broken line" << endl;
	cout << start_line;
	while (flag1)
	{
		try {
			std::cout << "Press the second broken line " << endl;
			flag = true;

			while (flag)
			{
				try
				{
					std::cout << "Number of points: ";
					cin >> n;
					if (n < 2) throw "The numbers of points must be >= 2";
					flag = false;
				}
				catch (const char* ex)
				{
					std::cout << ex << endl;
					std::cout << endl << "Try again" << endl;
				}
			}
		}
		catch (const char* ex)
		{
			std::cout << ex << endl;
			std::cout << endl << "Try again" << endl;
		}
		Broken_Line<complex<float>> tmp_line(n);
		Broken_Line<complex<float>>new_line = CreatingLine(tmp_line);
		flag1 = false;
		std::cout << "Point coordinates of the second broken line" << endl;
		cout << new_line;
		start_line = start_line + new_line;
		std::cout << endl << "Result: " << endl;
		cout << start_line;
		break;
	}
	return -1;
}
template <class T>
int SumLine(Broken_Line<std::complex<double>>& start_line, bool flag)
{
	int choice = 0;
	bool flag1 = true;
	flag = true;
	int n = 0;
	std::cout << "Point coordinates of the first broken line" << endl;
	cout << start_line;
	while (flag1)
	{
		try {
			std::cout << "Press the second broken line " << endl;
			flag = true;

			while (flag)
			{
				try
				{
					std::cout << "Number of points: ";
					cin >> n;
					if (n < 2) throw "The numbers of points must be >= 2";
					flag = false;
				}
				catch (const char* ex)
				{
					std::cout << ex << endl;
					std::cout << endl << "Try again" << endl;
				}
			}
		}
		catch (const char* ex)
		{
			std::cout << ex << endl;
			std::cout << endl << "Try again" << endl;
		}
		Broken_Line<complex<double>> tmp_line(n);
		Broken_Line<complex<double>> new_line = CreatingLine(tmp_line);
		flag1 = false;
		std::cout << "Point coordinates of the second broken line" << endl;
		cout << new_line;
		start_line = start_line + new_line;
		std::cout << endl << "Result: " << endl;
		cout << start_line;
		break;
	}
	return -1;
}

template <class T>
int SumPoint_Line(Broken_Line<T>& start_line, bool flag)
{
	int choice = 0;
	flag = true;
	while (flag)
	{
		T x = 0, y = 0;
		std::cout << "Press coordinates of the point which want to add: " << endl;
		std::cout << "x = ";
		cin >> x;
		std::cout << "y = ";
		cin >> y;
		Broken_Line<T> point(1);
		point[0].x = x;
		point[0].y = y;
		Broken_Line<T> tmp_line = point[0] + start_line;
		cout << tmp_line;
		start_line = tmp_line;
		flag = true;
	}
	return -1;
}
template <class T>
int SumPoint_Line(Broken_Line<std::complex<float>>& start_line, bool flag)
{
	int choice = 0;
	flag = true;
	while (flag)
	{
		complex<float> x = 0, y = 0;
		std::cout << "Press coordinates of the point which want to add: " << endl;
		cout << "x: ";
		cin >> x;
		cout << "y: ";
		cin >> y;
		Broken_Line<complex<float>> point(1);
		point[0].x = x;
		point[0].y = y;
		Broken_Line<complex<float>> tmp_line = point[0] + start_line;
		cout << tmp_line;
		start_line = tmp_line;
		flag = true;
	}
	return -1;
}
template <class T>
int SumPoint_Line(Broken_Line<std::complex<double>>& start_line, bool flag)
{
	int choice = 0;
	flag = true;
	while (flag)
	{
		complex<double> x = 0, y = 0;
		std::cout << "Press coordinates of the point which want to add: " << endl;
		cout << "x: ";
		cin >> x;
		cout << "y: ";
		cin >> y;
		Broken_Line<complex<double>> point(1);
		point[0].x = x;
		point[0].y = y;
		Broken_Line<complex<double>> tmp_line = point[0] + start_line;
		cout << tmp_line;
		start_line = tmp_line;
		flag = true;
	}
	return -1;
}

template <class T>
int SumLine_Point(Broken_Line<T>& start_line, bool flag)
{
	int choice = 0;
	flag = true;
	while (flag)
	{
		T x = 0, y = 0;
		std::cout << "Press coordinates of the point which want to add: " << endl;
		std::cout << "x = ";
		std::cin >> x;
		std::cout << "y = ";
		std::cin >> y;
		Broken_Line<T> point(1);
		point[0].x = x;
		point[0].y = y;
		Broken_Line<T> tmp_line = start_line + point[0];
		start_line = tmp_line;
		cout << tmp_line;
		flag = true;
	}
	return -1;
}
template <class T>
int SumLine_Point(Broken_Line<std::complex<float>>& start_line, bool flag)
{
	int choice = 0;
	flag = true;
	while (flag)
	{
		complex<float> x = 0, y = 0;
		std::cout << "Press coordinates of the point which want to add: " << endl;
		cout << "x: ";
		cin >> x;
		cout << "y: ";
		cin >> y;
		Broken_Line<std::complex<float>> point(1);
		point[0].x = x;
		point[0].y = y;
		Broken_Line<complex<float>> tmp_line = start_line + point[0];
		start_line = tmp_line;
		cout << tmp_line;
		flag = true;
	}
	return -1;
}
template <class T>
int SumLine_Point(Broken_Line<std::complex<double>>& start_line, bool flag)
{
	int choice = 0;
	flag = true;
	while (flag)
	{
		complex<double> x = 0, y = 0;
		std::cout << "Press coordinates of the point which want to add: " << endl;
		cout << "x: ";
		cin >> x;
		cout << "y: ";
		cin >> y;
		Broken_Line<complex<double>> point(1);
		point[0].x = x;
		point[0].y = y;
		Broken_Line<complex<double>> tmp_line = start_line + point[0];
		start_line = tmp_line;
		cout << tmp_line;
		flag = true;
	}
	return -1;
}

template <class T>
int LenLine(Broken_Line<T>& start_line)
{
	int choice = 0;
	double len = 0;
	cout << start_line << endl;
	for (int i = 0; (i + 1) < start_line.Get_size(); i++)
		len += pow(pow(abs(start_line[i + 1].x - start_line[i].x), 2) + pow(abs(start_line[i + 1].y - start_line[i].y), 2), 0.5);
	std::cout << "Length of the line: " << len << endl;
	return -1;
}
template <class T>
int LenLine(Broken_Line<std::complex<float>>& start_line)
{
	int choice = 0;
	double len = 0, a = 0, b = 0, c = 0, d = 0, e = 0, f = 0, g = 0, h = 0;
	cout << start_line << endl;
	for (int i = 0; (i + 1) < start_line.Get_size(); i++)
	{
		a = start_line[i + 1].x.real() - start_line[i].x.real();
		b = start_line[i + 1].x.imag() - start_line[i].x.imag();
		c = pow(a, 2) - pow(b, 2);
		d = 2 * a * b; //*i
		e = start_line[i + 1].y.real() - start_line[i].y.real();
		f = start_line[i + 1].y.imag() - start_line[i].y.imag();
		g = pow(e, 2) - pow(f, 2);
		h = 2 * e * f; //*i
		len += sqrt(sqrt(pow(c + g, 2) + pow(d + h, 2)));
	}
	cout << "Length of the line: " << len << endl;
	return -1;
}
template <class T>
int LenLine(Broken_Line<std::complex<double>>& start_line)
{
	int choice = 0;
	double len = 0, a = 0, b = 0, c = 0, d = 0, e = 0, f = 0, g = 0, h = 0;
	cout << start_line << endl;
	for (int i = 0; (i + 1) < start_line.Get_size(); i++)
	{
		a = start_line[i + 1].x.real() - start_line[i].x.real();
		b = start_line[i + 1].x.imag() - start_line[i].x.imag();
		c = pow(a, 2) - pow(b, 2);
		d = 2 * a * b; //*i
		e = start_line[i + 1].y.real() - start_line[i].y.real();
		f = start_line[i + 1].y.imag() - start_line[i].y.imag();
		g = pow(e, 2) - pow(f, 2);
		h = 2 * e * f; //*i
		len += sqrt(sqrt(pow(c + g, 2) + pow(d + h, 2)));
	}
	cout << "Length of the line: " << len << endl;
	return -1;
}

template <class T>
int Compare(Broken_Line<T>& start_line)
{
	int choice = 0;
	T x = 0, y = 0;
	bool flag1 = true, flag = true;
	int n = 0;
	std::cout << "Point coordinates of the first broken line" << endl;
	cout << start_line;
	while (flag1)
	{
		choice = _getch();
		if (choice == 8) return choice;
		try {
			std::cout << "Press the second broken line " << endl;
			flag = true;

			while (flag)
			{
				try
				{
					std::cout << "Number of points: ";
					std::cin >> n;
					if (n < 2) throw "The numbers of points must be >= 2";
					flag = false;
					flag1 = false;
				}
				catch (const char* ex)
				{
					std::cout << ex << endl;
					std::cout << endl << "Try again" << endl;
				}
			}
		}
		catch (const char* ex)
		{
			std::cout << ex << endl;
			std::cout << endl << "Try again" << endl;
		}

		Broken_Line<T> tmp_line(n);
		Broken_Line<T> new_line = CreatingLine(tmp_line);
		flag1 = false;
		cout << new_line;
		if (start_line == new_line) cout << "The broken lines are equal!" << endl;
		if (start_line != new_line) cout << "The broken lines are unequal!" << endl;
		flag1 = true;
	}
	return -1;
}
template <class T>
int Compare(Broken_Line<std::complex<float>>& start_line)
{
	int choice = 0;
	complex<float> x = 0, y = 0;
	bool flag1 = true, flag = true;
	int n = 0;
	std::cout << "Point coordinates of the first broken line" << endl;
	cout << start_line;
	while (flag1)
	{
		choice = _getch();
		if (choice == 8) return choice;
		try {
			std::cout << "Press the second broken line " << endl;
			flag = true;

			while (flag)
			{
				try
				{
					std::cout << "Number of points: ";
					std::cin >> n;
					if (n < 2) throw "The numbers of points must be >= 2";
					flag = false;
					flag1 = false;
				}
				catch (const char* ex)
				{
					std::cout << ex << endl;
					std::cout << endl << "Try again" << endl;
				}
			}
		}
		catch (const char* ex)
		{
			std::cout << ex << endl;
			std::cout << endl << "Try again" << endl;
		}

		Broken_Line<complex<float>> tmp_line(n);
		Broken_Line<complex<float>> new_line = CreatingLine(tmp_line);
		flag1 = false;
		cout << new_line;
		if (start_line == new_line) cout << "The broken lines are equal!" << endl;
		else cout << "The broken lines are unequal!" << endl;
		flag1 = true;
	}
	return -1;
}
template <class T>
int Compare(Broken_Line<std::complex<double>>& start_line)
{
	int choice = 0;
	complex<double> x = 0, y = 0;
	bool flag1 = true, flag = true;
	int n = 0;
	std::cout << "Point coordinates of the first broken line" << endl;
	cout << start_line;
	while (flag1)
	{
		choice = _getch();
		if (choice == 8) return choice;
		try {
			std::cout << "Press the second broken line " << endl;
			flag = true;

			while (flag)
			{
				try
				{
					std::cout << "Number of points: ";
					std::cin >> n;
					if (n < 2) throw "The numbers of points must be >= 2";
					flag = false;
					flag1 = false;
				}
				catch (const char* ex)
				{
					std::cout << ex << endl;
					std::cout << endl << "Try again" << endl;
				}
			}
		}
		catch (const char* ex)
		{
			std::cout << ex << endl;
			std::cout << endl << "Try again" << endl;
		}
		Broken_Line<complex<double>> tmp_line(n);
		Broken_Line<complex<double>> new_line = CreatingLine(tmp_line);
		flag1 = false;
		cout << new_line;
		if (start_line == new_line) cout << "The broken lines are equal!" << endl;
		else cout << "The broken lines are unequal!" << endl;
		flag1 = true;
	}
	return -1;
}

void menu0()
{
	system("cls");
	std::cout << endl << "Choose where you want to start" << endl << endl;
	std::cout << "1. Create a broken line" << endl;
	std::cout << "2. Build a first letter of my surname" << endl;
	std::cout << "3. Complete the job" << endl;

}

void menu1()
{
	std::cout << endl << endl << "Next choice: " << endl;
	std::cout << "1. Broken lines concatenation" << endl;
	std::cout << "2. Add the point to the line (add a point at the finish of the line)" << endl;
	std::cout << "3. Add the line to the point (add a point at the start of the line)" << endl;
	std::cout << "4. Calculate the length of the line" << endl;
	std::cout << "5. Compare broken lines" << endl;
	std::cout << "6. Know/change point coordinates of the broken line" << endl;
	std::cout << "7. Back to main menu" << endl;
}

template <class T>
void CreateLetter(T x, T y, Broken_Line<T>& line)
{
	T tmp = 2;
	T tmp1 = 4;
	line[0].x = x;
	line[0].y = y;
	line[1].x = x - tmp;
	line[1].y = y;
	line[2].x = x - tmp;
	line[2].y = y + tmp1;
	line[3].x = x;
	line[3].y = y + tmp1;
	cout << line;
}
template <class T>
void CreateLetter(complex<float> x, complex<float> y, Broken_Line<complex<float>>& line)
{
	line[0].x = x;
	line[0].y = y;
	line[1].x.real() = x.real() - 2;
	line[1].x.imag() = x.real() - 2;
	line[1].y = y;
	line[2].x.real() = x.real() - 2;
	line[2].x.imag() = x.real() - 2;
	line[2].y.real() = y.real() + 4;
	line[2].y.imag() = y.imag() + 4;
	line[3].x = x;
	line[4].y.real() = y.real() + 4;
	line[4].y.imag() = y.imag() + 4;
	cout << line;
}
template <class T>
void CreateLetter(complex<double> x, complex<double> y, Broken_Line<complex<double>>& line)
{
	line[0].x = x;
	line[0].y = y;
	line[1].x.real() = x.real() - 2;
	line[1].x.imag() = x.real() - 2;
	line[1].y = y;
	line[2].x.real() = x.real() - 2;
	line[2].x.imag() = x.real() - 2;
	line[2].y.real() = y.real() + 4;
	line[2].y.imag() = y.imag() + 4;
	line[3].x = x;
	line[4].y.real() = y.real() + 4;
	line[4].y.imag() = y.imag() + 4;
	cout << line;
}

template <class T>
Broken_Line<T>& MyLetter(bool flag)
{
	Broken_Line<T> line(5);
	int choice = 0;
	T x = 0, y = 0;
	system("cls");
	flag = true;
	std::cout << "Press coordinaes of the first point" << endl;
	std::cout << "x = ";
	cin >> x;
	std::cout << "y = ";
	cin >> y;
	CreateLetter(x, y, line);
	return line;
}
template <class T>
Broken_Line <std::complex<float>>& MyLetterCF(bool flag)
{
	Broken_Line <std::complex<float>> line(5);
	int choice = 0;
	complex<float>  x = 0, y = 0;
	system("cls");
	flag = true;
	std::cout << "Press coordinaes of the first point" << endl;
	cout << "x: ";
	cin >> x;
	cout << "y: ";
	cin >> y;
	CreateLetter(x, y, line);
	return line;
}
template <class T>
Broken_Line <std::complex<double>>& MyLetterCD(bool flag)
{
	Broken_Line <std::complex<double>> line(5);
	int choice = 0;
	complex<double>  x = 0, y = 0;
	system("cls");
	flag = true;
	std::cout << "Press coordinaes of the first point" << endl;
	cout << "x: ";
	cin >> x;
	cout << "y: ";
	cin >> y;
	CreateLetter(x, y, line);
	return line;
}

template <class T>
bool JobWithLine(bool flag, bool flag1, int choice, Broken_Line<T>& start_line)
{
	menu1();
	flag = true;
	while (flag)
	{
		try {
			std::cin >> choice;
			if (choice > 8 || choice < 1) throw "!There is no such option!";
			flag = false;
		}
		catch (const char* ex)
		{
			std::cout << ex << endl;
			std::cout << endl << "Try again" << endl;
		}
	}
	if (choice == 1)
		if (SumLine(start_line, flag) == 8) flag1 = true;
	if (choice == 2)
		if (SumLine_Point(start_line, flag) == 8) flag1 = true;
	if (choice == 3)
		if (SumPoint_Line(start_line, flag) == 8) flag1 = true;
	if (choice == 4)
		if (LenLine(start_line) == 8) flag1 = true;
	if (choice == 5)
		if (Compare(start_line) == 8) flag1 = true;
	if (choice == 6)
		if (IndexPoint(start_line, flag) == 8) flag1 = true;
	if (choice == 7)
	{
		flag = true;
		flag1 = false;
	}
	return flag1;
}
template <class T>
bool JobWithLine(bool flag, bool flag1, int choice, Broken_Line<complex<float>>& start_line)
{
	menu1();
	flag = true;
	while (flag)
	{
		try {
			std::cin >> choice;
			if (choice > 8 || choice < 1) throw "!There is no such option!";
			flag = false;
		}
		catch (const char* ex)
		{
			std::cout << ex << endl;
			std::cout << endl << "Try again" << endl;
		}
	}

	if (choice == 1)
		if (SumLine(start_line, flag) == 8) flag1 = true;
	if (choice == 2)
		if (SumLine_Point(start_line, flag) == 8) flag1 = true;
	if (choice == 3)
		if (SumPoint_Line(start_line, flag) == 8) flag1 = true;
	if (choice == 4)
		if (LenLine(start_line) == 8) flag1 = true;
	if (choice == 5)
		if (Compare(start_line) == 8) flag1 = true;
	if (choice == 6)
		if (IndexPoint(start_line, flag) == 8) flag1 = true;
	if (choice == 7)
	{
		flag = true;
		flag1 = false;
	}
	return flag1;
}
template <class T>
bool JobWithLine(bool flag, bool flag1, int choice, Broken_Line<complex<double>>& const start_line)
{
	menu1();
	flag = true;
	while (flag)
	{
		try {
			std::cin >> choice;
			if (choice > 8 || choice < 1) throw "!There is no such option!";
			flag = false;
		}
		catch (const char* ex)
		{
			std::cout << ex << endl;
			std::cout << endl << "Try again" << endl;
		}
	}

	if (choice == 1)
		if (SumLine(start_line, flag) == 8) flag1 = true;
	if (choice == 2)
		if (SumLine_Point(start_line, flag) == 8) flag1 = true;
	if (choice == 3)
		if (SumPoint_Line(start_line, flag) == 8) flag1 = true;
	if (choice == 4)
		if (LenLine(start_line) == 8) flag1 = true;
	if (choice == 5)
		if (Compare(start_line) == 8) flag1 = true;
	if (choice == 6)
		if (IndexPoint(start_line, flag) == 8) flag1 = true;
	if (choice == 7)
	{
		flag = true;
		flag1 = false;
	}
	return flag1;
}


int main()
{
	int choice = 0;
	int type = 0;
	bool flag = true, flag1 = true;
	while (flag)
	{
		menu0();
		std::cout << "Choice: ";
		std::cin >> choice;
		switch (choice)
		{
		case 1:
		{
			flag = true;
			int n = 0;

			while (flag)
			{
				try
				{
					std::cout << "Number of points: ";
					std::cin >> n;
					if (n < 2) throw "The numbers of points muct be >= 2";
					flag = false;
				}
				catch (const char* ex)
				{
					std::cout << ex << endl;
					std::cout << endl << "Try again" << endl;
				}
			}
			std::cout << "Press 1 to work with int" << endl;
			cout << "Press 2 to work with float" << endl;
			cout << "Press 3 to work with double" << endl;         //Тут запрос с чем работать
			cout << "Press 4 to work with complex float" << endl;
			cout << "Press 5 to work with complex double" << endl;
			cout << "Press 6 to exit the program" << endl;
			cin >> type;
			flag = true;
			flag1 = true;

			if (type == 1) {
				Broken_Line<int> tmp_line(n);
				Broken_Line<int> start_line = CreatingLine<int>(tmp_line);
				while (flag1)
					flag1 = JobWithLine(flag, flag1, choice, start_line);
				break;

			}
			else if (type == 2) {
				Broken_Line<float> tmp_line(n);
				Broken_Line<float> start_line = CreatingLine<float>(tmp_line);

				while (flag1)
					flag1 = JobWithLine(flag, flag1, choice, start_line);
				break;
			}
			else if (type == 3) {
				Broken_Line<double> tmp_line(n);
				Broken_Line<double> start_line = CreatingLine<double>(tmp_line);

				while (flag1)
					flag1 = JobWithLine(flag, flag1, choice, start_line);
				break;
			}
			else if (type == 4) {
				Broken_Line<std::complex<float>> tmp_line(n);
				Broken_Line<std::complex<float>> start_line = CreatingLine<std::complex<float>>(tmp_line);

				while (flag1)
					flag1 = JobWithLine<std::complex<float>>(flag, flag1, choice, start_line);
				break;
			}
			else if (type == 5) {
				Broken_Line<std::complex<double>>tmp_line(n);
				Broken_Line<std::complex<double>> start_line = CreatingLine<std::complex<double>>(tmp_line);

				while (flag1)
					flag1 = JobWithLine<std::complex<double>>(flag, flag1, choice, start_line);
				break;
			}

		}
		case 2:
		{
			cout << "Press 1 to work with int" << endl;
			cout << "Press 2 to work with float" << endl;
			cout << "Press 3 to work with double" << endl;         //Тут запрос с чем работать
			cout << "Press 4 to work with complex float" << endl;
			cout << "Press 5 to work with complex double" << endl;
			cout << "Press 6 to exit the program" << endl;
			int type;
			cin >> type;
			flag = true;
			flag1 = true;
			if (type == 1) {
				Broken_Line<int> line = MyLetter<int>(flag);
				while (flag1)
					flag1 = JobWithLine(flag, flag1, choice, line);
				break;

			}
			if (type == 2) {
				Broken_Line<float> line = MyLetter<float>(flag);
				while (flag1)
					flag1 = JobWithLine(flag, flag1, choice, line);
				break;
			}
			if (type == 3) {
				Broken_Line<double> line = MyLetter<double>(flag);
				while (flag1)
					flag1 = JobWithLine(flag, flag1, choice, line);
				break;
			}
			else if (type == 4) {
				Broken_Line<std::complex<float>> line = MyLetterCF<std::complex<float>>(flag);
				while (flag1)
					flag1 = JobWithLine<std::complex<float>>(flag, flag1, choice, line);
				break;
			}
			else if (type == 5) {
				Broken_Line<std::complex<double>> line = MyLetterCD<std::complex<double>>(flag);
				while (flag1)
					flag1 = JobWithLine<std::complex<double>>(flag, flag1, choice, line);
				break;
			}
		}
		case 3:
		{
			return 0;
		}
		default:
			try {
				if (choice != 1 && choice != 2) throw "!There is no such option!";
			}
			catch (const char* ex)
			{
				std::cout << ex << endl;
				std::cout << endl << "Try again" << endl;
			}
			break;
		}
	}
}

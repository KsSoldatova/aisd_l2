#include <iostream>
#include <cstdlib>
#include <math.h>
#include <conio.h>

using namespace std;


template<class C>
class Complex {
private:
	struct PointsC
	{
		C reX = 0, imX = 0, reY = 0, imY = 0;
	};
	PointsC* line = NULL;
	int size = 0, more_number = 0;
public:
	Complex<C>(int size = 0)
	{
		if (size == 0)
		{
			this->size = size;
			return;
		}
		more_number = size * 2;
		line = new PointsC[more_number];
		this->size = size;
	}
	int Get_size() const { return size; }
	int Get_more_points() const { return more_number; }
	Complex operator +(Complex& other) //конкатенация двух линий 
	{
		if (this->size + other.Get_size() >= this->more_number)
		{
			this->more_number = (this->Get_more_points() + other.Get_size());
			Complex* tmpline = new Complex[this->Get_more_points()];
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

	Complex operator +(PointsC& point)//сложение ломаной и точки, добавление в конец 
	{
		this->size++;
		if (this->Get_size() == this->Get_more_points())
		{
			this->more_number *= 2;
			Complex* tmpline = new Complex[this->Get_more_points()];
			tmpline = this;
			*this = *tmpline;
		}
		(*this)[this->Get_size() - 1] = point;
		return *this;
	}

	friend Complex operator +(PointsC& point, Complex& tmp_line)//сложение точки и ломанной, добавление в начало
	{
		tmp_line.size++;
		if (tmp_line.Get_size() == tmp_line.Get_more_points())
		{
			tmp_line.more_number *= 2;
			Complex* tline = new Complex[tmp_line.Get_more_points()];
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
	PointsC operator [] (int other_point) const //для чтения
	{
		if (other_point >= 0 && other_point < size)
			return (line[other_point]);
		throw "!invalid index!";
	}
	PointsC& operator [] (int other_point) //для записи
	{
		if (other_point >= 0 && other_point < size)
			return (line[other_point]);
		throw "!invalid index!";
	}

	friend ostream& operator<<(ostream& out, Complex& a)
	{
		for (int i = 0; i < a.Get_size(); i++)
		{
			out << "[" << i + 1 << "]" << "(" << "(" << a[i].reX << ";" << a[i].imX << ")" << "," << "(" << a[i].reY << ";" << a[i].imY << ")" << ")" << endl;

		}
		return out;
	}
	Complex operator=(const Complex& other)
	{
		for (int i = 0; i < other.Get_size(); i++)
		{
			(*this)[i].reX = other[i].reX;
			(*this)[i].reY = other[i].reY;
			(*this)[i].imX = other[i].imX;
			(*this)[i].imY = other[i].imY;
		}
		return *this;
	}

	bool operator == (const Complex& other)
	{
		if (this->Get_size() == other.Get_size())
		{
			for (int i = 0; i < this->Get_size(); i++)
			{
				if ((*this)[i].reX != other[i].reX || (*this)[i].reY != other[i].reY || (*this)[i].imX != other[i].imX || (*this)[i].imY != other[i].imY)
					return false;
			}
			return true;
		}
		return false;
	}
	bool operator != (const Complex& other)
	{
		if (this->Get_size() == other.Get_size())
		{
			for (int i = 0; i < this->Get_size(); i++)
			{
				if ((*this)[i].reX != other[i].reX || (*this)[i].reY != other[i].reY || (*this)[i].imX != other[i].imX || (*this)[i].imY != other[i].imY)
					return true;
			}
			return false;
		}
		return true;
	}

};


template <typename T>
class broken_line
{
private:
	struct Points
	{
		T x = 0, y = 0;
	};
	Points* line = NULL;
	int size = 0, more_number = 0;

public:
	broken_line<T>(int size = 0)
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


	friend std::ostream& operator << (std::ostream& os, const broken_line point)
	{
		for (int i = 0; i < point.Get_size(); i++)
		{
			os << '(' << point[i].x << ';' << point[i].y << ')' << endl;

		}
		return os;
	}


	Points operator [] (int other_point) const //for reading
	{
		if (other_point >= 0 && other_point < size)
			return (line[other_point]);
		throw "!invalid index!";
	}
	Points& operator [] (int other_point) //for writing
	{
		if (other_point >= 0 && other_point < size)
			return (line[other_point]);
		throw "!invalid index!";
	}

	broken_line operator +(broken_line& other) //конкатенация двух линий 
	{
		if (this->size + other.Get_size() >= this->more_number)
		{
			this->more_number = (this->Get_more_points() + other.Get_size());
			broken_line* tmpline = new broken_line[this->Get_more_points()];
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

	broken_line operator +(Points& point)//сложение ломаной и точки, добавление в конец 
	{
		this->size++;
		if (this->Get_size() == this->Get_more_points())
		{
			this->more_number *= 2;
			broken_line* tmpline = new broken_line[this->Get_more_points()];
			tmpline = this;
			*this = *tmpline;
		}
		(*this)[this->Get_size() - 1] = point;
		return *this;
	}
	friend broken_line operator +(Points& point, broken_line& tmp_line)////сложение точки и ломанной, добавление в начало
	{
		tmp_line.size++;
		if (tmp_line.Get_size() == tmp_line.Get_more_points())
		{
			tmp_line.more_number *= 2;
			broken_line* tline = new broken_line[tmp_line.Get_more_points()];
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
	broken_line operator =(const broken_line& tmp_line)
	{
		for (int i = 0; i < tmp_line.Get_size(); i++)
		{
			(*this)[i] = tmp_line[i];
		}
		return *this;
	}
	bool operator == (const broken_line& other_line)
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
	bool operator != (const broken_line& other_line)
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



template <class T>
broken_line<T> CreatingLine(broken_line<T>& start_line) {
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

template <class C>
Complex<C> CreatingLineC(Complex<C> start_line) {
	C x1 = 0, x2 = 0, y1 = 0, y2 = 0;
	for (int i = 0; i < start_line.Get_size(); i++)
	{
		cout << endl << "Enter the coordinates of the point:" << endl;
		cout << "x1: ";
		cin >> x1;
		cout << "x2: ";
		cin >> x2;
		cout << "y1: ";
		cin >> y1;
		cout << "y2: ";
		cin >> y2;
		start_line[i].reX = x1;
		start_line[i].imX = x2;
		start_line[i].reY = y1;
		start_line[i].imY = y2;
	}
	return start_line;
}


template <class T>
int IndexPoint(broken_line<T>& start_line, bool flag)
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
			std::cout << "Enter х: ";
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
template <class C>
int IndexPointC(Complex<C>& start_line, bool flag)
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
		if (choice == 1) cout << "Coordinates: " << "(" << "(" << start_line[index - 1].reX << ";" << start_line[index - 1].imX << ")" << "," << "(" << start_line[index - 1].reY << ";" << start_line[index - 1].imY << ")" << ")" << endl;
		if (choice == 2)
		{
			C x1 = 0, x2 = 0, y1 = 0, y2 = 0;
			std::cout << "Enter х1: ";
			std::cin >> x1;
			std::cout << "Enter x2: ";
			std::cin >> x2;
			std::cout << "Enter y1: ";
			std::cin >> y1;
			std::cout << "Enter y2: ";
			std::cin >> y2;
			start_line[index - 1].reX = x1;
			start_line[index - 1].imX = x2;
			start_line[index - 1].reY = y1;
			start_line[index - 1].imY = y2;
			std::cout << start_line << endl;
			std::cout << "Coordinates of the point with index " << index << " = (" << "(" << start_line[index - 1].reX << ";" << start_line[index - 1].imX << ")" << "," << "(" << start_line[index - 1].reY << ";" << start_line[index - 1].imY << ")" << ")" << endl << endl;
		}
		break;
	}
	return -1;
}
template <class T>
int SumLine(broken_line<T>& start_line, bool flag)
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
		broken_line<T> tmp_line(n);
		broken_line<T> new_line = CreatingLine(tmp_line);
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
template <class C>
int SumLineC(Complex<C>& start_line, bool flag)
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
		Complex<C> tmp_line(n);
		Complex<C> new_line = CreatingLineC(tmp_line);
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
int SumPoint_Line(broken_line<T>& start_line, bool flag)
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
		broken_line<T> point(1);
		point[0].x = x;
		point[0].y = y;
		broken_line<T> tmp_line = point[0] + start_line;
		cout << tmp_line;
		start_line = tmp_line;
		flag = true;
	}
	return -1;
}
template <class C>
int SumPoint_LineC(Complex<C>& start_line, bool flag)
{
	int choice = 0;
	flag = true;
	while (flag)
	{
		C x1 = 0, x2 = 0, y1 = 0, y2 = 0;
		std::cout << "Press coordinates of the point which want to add: " << endl;
		std::cout << "x1 = ";
		cin >> x1;
		std::cout << "x2 = ";
		cin >> x2;
		std::cout << "y1 = ";
		cin >> y1;
		std::cout << "y2 = ";
		cin >> y2;
		Complex<C> point(1);
		point[0].reX = x1;
		point[0].imX = x2;
		point[0].reY = y1;
		point[0].imY = y2;
		Complex<C> tmp_line = point[0] + start_line;
		cout << tmp_line;
		start_line = tmp_line;
		flag = true;
	}
	return -1;
}

template <class T>
int SumLine_Point(broken_line<T>& start_line, bool flag)
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
		broken_line<T> point(1);
		point[0].x = x;
		point[0].y = y;
		broken_line<T> tmp_line = start_line + point[0];
		start_line = tmp_line;
		cout << tmp_line;
		flag = true;
	}
	return -1;
}
template <class C>
int SumLine_PointC(Complex<C>& start_line, bool flag)
{
	int choice = 0;
	flag = true;
	while (flag)
	{
		C x1 = 0, x2 = 0, y1 = 0, y2 = 0;
		std::cout << "Press coordinates of the point which want to add: " << endl;
		std::cout << "x1 = ";
		std::cin >> x1;
		std::cout << "x2 = ";
		std::cin >> x2;
		std::cout << "y1 = ";
		std::cin >> y1;
		std::cout << "y2 = ";
		std::cin >> y2;
		Complex<C> point(1);
		point[0].reX = x1;
		point[0].imX = x2;
		point[0].reY = y1;
		point[0].imY = y2;
		Complex<C> tmp_line = start_line + point[0];
		start_line = tmp_line;
		cout << tmp_line;
		flag = true;
	}
	return -1;
}
template <class T>
int LenLine(broken_line<T>& start_line)
{
	int choice = 0;
	double len = 0;
	cout << start_line << endl;
	for (int i = 0; (i + 1) < start_line.Get_size(); i++)
		len += pow(pow(abs(start_line[i + 1].x - start_line[i].x), 2) + pow(abs(start_line[i + 1].y - start_line[i].y), 2), 0.5);
	std::cout << "Length of the line: " << len << endl;
	return -1;
}
template <class C>
int LenLineC(Complex<C>& start_line)
{
	int choice = 0;
	double len = 0, a = 0, b = 0, c = 0, d = 0, e = 0, f = 0, g = 0, h = 0;
	cout << start_line << endl;
	for (int i = 0; (i + 1) < start_line.Get_size(); i++)
	{
		a = start_line[i + 1].reX - start_line[i].reX; //действительная часть
		b = start_line[i + 1].imX - start_line[i].imX;//мнимая часть
		c = pow(a, 2) - pow(b, 2);
		d = 2 * a * b; //*i
		e = start_line[i + 1].reY - start_line[i].reY; //действительная часть
		f = start_line[i + 1].imY - start_line[i].imY;//мнимая часть
		g = pow(e, 2) - pow(f, 2);
		h = 2 * e * f; //*i
		len += sqrt(sqrt(pow(c + g, 2) + pow(d + h, 2)));
	}
	cout << "Length of the line: " << len << endl;
	return -1;
}
template <class T>
int Compare(broken_line<T>& start_line)
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

		broken_line<T> tmp_line(n);
		broken_line<T> new_line = CreatingLine(tmp_line);
		flag1 = false;
		cout << new_line;
		if (start_line == new_line) cout << "The broken lines are equal!" << endl;
		if (start_line != new_line) cout << "The broken lines are unequal!" << endl;
		flag1 = true;
	}
	return -1;
}
template <class C>
int CompareC(Complex<C>& start_line)
{
	int choice = 0;
	C x1 = 0, x2 = 0, y1 = 0, y2 = 0;
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

		Complex<C> tmp_line(n);
		Complex<C> new_line = CreatingLineC(tmp_line);
		flag1 = false;
		cout << new_line;
		if (start_line == new_line) cout << "The broken lines are equal!" << endl;
		if (start_line != new_line) cout << "The broken lines are unequal!" << endl;
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
void CreateLetter(T x, T y, broken_line<T>& line)
{
	line[0].x = x;
	line[0].y = y;
	line[1].x = x - 2;
	line[1].y = y;
	line[2].x = x - 2;
	line[2].y = y + 4;
	line[3].x = x;
	line[3].y = y + 4;
	cout << line;
}
template <class C>
void CreateLetterC(C x1, C x2, C y1, C y2, Complex<C>& line)
{
	line[0].reX = x1;
	line[0].imX = x2;
	line[0].reY = y1;
	line[0].imY = y2;
	line[1].reX = x1-2;
	line[1].imX = x2-2;
	line[1].reY = y1;
	line[1].imY = y2;
	line[2].reX = x1 - 2;
	line[2].imX = x2 - 2;
	line[2].reY = y1 + 4;
	line[2].imY = y2 + 4;
	line[3].reX = x1;
	line[3].imX = x2;
	line[3].reY = y1 + 4;
	line[3].imY = y2 + 4;
	cout << line;
}

template <class T>
broken_line<T>& MyLetter(bool flag)
{
	broken_line<T> line(5);
	int choice = 0;
	T x = 0, y = 0;
	system("cls");
	flag = true;
	std::cout << "Press coordinaes of the first point" << endl;
	std::cout << "х = ";
	cin >> x;
	std::cout << "y = ";
	cin >> y;
	CreateLetter(x, y, line);
	return line;
}

template <class C>
Complex<C>& MyLetterC(bool flag)
{
	Complex<C> line(5);
	int choice = 0;
	C  x1 = 0, x2 = 0, y1 = 0, y2 = 0;
	system("cls");
	flag = true;
	std::cout << "Press coordinaes of the first point" << endl;
	std::cout << "х1 = ";
	cin >> x1;
	std::cout << "х2 = ";
	cin >> x2;
	std::cout << "y1 = ";
	cin >> y1;
	std::cout << "y2 = ";
	cin >> y2;
	CreateLetterC(x1, x2, y1, y2, line);
	return line;
}

template <class T>
bool JobWithLine(bool flag, bool flag1, int choice, broken_line<T>& start_line)
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
template <class C>
bool JobWithLineC(bool flag, bool flag1, int choice, Complex<C>& start_line)
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
		if (SumLineC(start_line, flag) == 8) flag1 = true;
	if (choice == 2)
		if (SumLine_PointC(start_line, flag) == 8) flag1 = true;
	if (choice == 3)
		if (SumPoint_LineC(start_line, flag) == 8) flag1 = true;
	if (choice == 4)
		if (LenLineC(start_line) == 8) flag1 = true;
	if (choice == 5)
		if (CompareC(start_line) == 8) flag1 = true;
	if (choice == 6)
		if (IndexPointC(start_line, flag) == 8) flag1 = true;
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
			std::cout << "Choice data type: 1 - int, 2 - float, 3 - double, 4 - complex float, 5 - complex double: ";
			std::cin >> type;
			flag = true;
			flag1 = true;

			if (type == 1) {
				broken_line<int> tmp_line(n);
				broken_line<int> start_line = CreatingLine<int>(tmp_line);
				while (flag1)
					flag1 = JobWithLine(flag, flag1, choice, start_line);
				break;

			}
			else if (type == 2) {
				broken_line<float> tmp_line(n);
				broken_line<float> start_line = CreatingLine<float>(tmp_line);

				while (flag1)
					flag1 = JobWithLine(flag, flag1, choice, start_line);
				break;
			}
			else if (type == 3) {
				broken_line<double> tmp_line(n);
				broken_line<double> start_line = CreatingLine<double>(tmp_line);

				while (flag1)
					flag1 = JobWithLine(flag, flag1, choice, start_line);
				break;
			}
			else if (type == 4) {
				Complex<float> tmp_line(n);
				Complex<float> start_line = CreatingLineC<float>(tmp_line);

				while (flag1)
					flag1 = JobWithLineC(flag, flag1, choice, start_line);
				break;
			}
			else if (type == 5) {
				Complex<double>tmp_line(n);
				Complex<double> start_line = CreatingLineC<double>(tmp_line);

				while (flag1)
					flag1 = JobWithLineC(flag, flag1, choice, start_line);
				break;
			}

		}
		case 2:
		{
			std::cout << "Choice data type:1 - int, 2 - float, 3 - double, 4 - complex float, 5 - complex double\n";
			std::cin >> type;
			flag = true;
			flag1 = true;
			if (type == 1) {
				broken_line<int> line = MyLetter<int>(flag);
				while (flag1)
					flag1 = JobWithLine(flag, flag1, choice, line);
				break;

			}
			if (type == 2) {
				broken_line<float> line = MyLetter<float>(flag);
				while (flag1)
					flag1 = JobWithLine(flag, flag1, choice, line);
				break;
			}
			if (type == 3) {
				broken_line<double> line = MyLetter<double>(flag);
				while (flag1)
					flag1 = JobWithLine(flag, flag1, choice, line);
				break;
			}
			else if (type == 4) {
				Complex<float> line = MyLetterC<float>(flag);
				while (flag1)
					flag1 = JobWithLineC(flag, flag1, choice, line);
				break;
			}

			else if (type == 5) {
				Complex<double> line = MyLetterC<double>(flag);
				while (flag1)
					flag1 = JobWithLineC(flag, flag1, choice, line);
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

template class Complex <float>;
template class Complex<double>;
template class broken_line <int>;
template class broken_line<float>;
template class broken_line<double>;
//============================================================================
// Name        : CLASSES.cpp
// Author      : Usama Zafar
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<cstring>
#include<string.h>
using namespace std;
class RetailItem
{
	string description;
	int units;
	double price;
public:
	RetailItem()
	{
		description = "";
		units = 0;
		price = 0.0;
	}
	RetailItem(string des, int u, double p)
	{
		description = des;
		units = u;
		price = p;
	}
	void setDescription(string s)
	{
		int lenght = 0;
		for (int i = 0; s[i] != '\0'; i++)
		{
			lenght++;
		}
		if (lenght <= 50)
		{
			description = s;
		}
	}

	string getDescription()
	{
		return description;
	}

	void setUnits(int u)
	{
		if (u >= 0)
		{
			units = u;
		}
	}

	int getUnits()
	{
		return units;
	}

	void setPrice(double p)
	{
		if (p >= 5)
		{
			price = p;
		}
	}

	double getPrice()
	{
		return price;
	}

	~RetailItem()
	{
		cout << "Destructor called";
	}
};
void SetRetailArray(RetailItem arr[], int size, string descriptions[], int units[], double p[])
{
	for (int i = 0; i<size; i++)
	{
		arr[i].setDescription(descriptions[i]);
		arr[i].setUnits(units[i]);
		arr[i].setPrice(p[i]);
	}
}
void getRetailArray(RetailItem arr[], int size)
{
	for (int i = 0; i<size; i++)
	{
		arr[i].getDescription();
		cout << "Units :" << arr[i].getUnits();
		cout << "Price :" << arr[i].getPrice();
	}
}

class Point
{
	int x;
	int y;
public:
	Point()
	{
		x = y = 0;
	}
	Point(int x1, int y1)
	{
		x = x1;
		y = y1;
	}
	~Point()
	{
		cout << "Destructor called";
	}

	int getX()  {
		return x;
	}

	void setX(int x) {
		this->x = x;
	}

	int getY()  {
		return y;
	}

	void setY(int y) {
		this->y = y;
	}
};
class Line
{
	Point P1, P2;
public:
	const Point& getP1()
	{
		return P1;
	}
	const Point& getP2()
	{
		return P2;
	}
	Line(const Point &p1, const Point &p2)
	{
		P1 = p1;
		P2 = p2;
	}
	Line(int x1, int y1, int x2, int y2)
	{
		P1.setX(x1);
		P1.setY(y1);
		P1.setX(x2);
		P1.setY(y2);
	}
	double getSlope()
	{
		return ((P2.getY() - P1.getY()) / (P2.getX() - P1.getX()));
	}
};
class Circle
{
	double radius;
	double pi;
public:
	Circle()
	{
		radius = 0.0;
		pi = 14159;
	}
	Circle(double r)
	{
		radius = r;
	}
	void setRadius(int Radius)
	{
		radius = Radius;
	}
	double getRadius()
	{
		return radius;
	}
	double getArea()
	{
		return  pi * radius *radius;
	}
	double getDiameter()
	{
		return radius * 2;
	}
	double getCircumference()
	{
		return  2 * pi * radius;
	}
	~Circle()
	{
		cout << " Destructor is executing";
	}
};
class Complex
{
	double real;
	double imaginary;
public:
	Complex()
	{
		real = 0.0;
		imaginary = 0.0;
	}
	Complex(double r, double i)
	{
		real = r;
		imaginary = i;
	}

	double getImaginary() const {
		return imaginary;
	}

	void setImaginary(double imaginary) {
		this->imaginary = imaginary;
	}

	double getReal() const {
		return real;
	}

	void setReal(double real) {
		this->real = real;
	}
	Complex add(Complex c)
	{
		Complex newcomplex;
		newcomplex.setReal(this->real + c.getReal());
		newcomplex.setImaginary(this->imaginary + c.getImaginary());
		return newcomplex;
	}
	Complex subtract(Complex c)
	{
		Complex newcomplex;
		newcomplex.setReal(this->real - c.getReal());
		newcomplex.setImaginary(this->imaginary - c.getImaginary());
		return newcomplex;
	}
	Complex multiply(Complex c)
	{
		Complex newcomplex;
		newcomplex.setReal(this->real * c.getReal());
		newcomplex.setImaginary(this->imaginary * c.getImaginary());
		return newcomplex;
	}
};
class GroceryItemOrder
{
	string name;
	int quantity;
	double pricePerUnit;
public:
	GroceryItemOrder()
	{
		name = "";
		quantity = 0;
		pricePerUnit = 0.0;
	}

	GroceryItemOrder(string name, int quantity, double pricePerUnit)
	{
		this->name = name;
		this->quantity = quantity;
		this->pricePerUnit = pricePerUnit;
	}

	double getCost()
	{
		double Temporary = (quantity * pricePerUnit);
		return Temporary;
	}

	const string& getName()  {
		return name;
	}

	void setName(const string& n) {
		name = n;
	}

	double getPricePerUnit()  {
		return pricePerUnit;
	}

	void setPricePerUnit(double ppu) {
		pricePerUnit = ppu;
	}

	int getQuantity()  {
		return quantity;
	}

	void setQuantity(int Q) {
		quantity = Q;
	}
	~GroceryItemOrder(){

	}
};

class GroceryList
{
	GroceryItemOrder * GroceryItems[10];//dynamically allocation of 10 Items
	int size;
public:
	GroceryList()
	{
		size = 0;
	}
	void add(GroceryItemOrder item)
	{
		if (size < 10){
			GroceryItems[size] = new GroceryItemOrder(item.getName(), item.getQuantity(), item.getPricePerUnit());//Addition of Each new item
			size++;
		}

	}
	double getTotalCost()
	{
		double Temporary = 0;
		for (int i = 0; i<size; i++)
			Temporary += GroceryItems[i]->getCost();//cost of every GroceryItems to Add
		return Temporary;
	}

	~GroceryList(){
		for (int i = 0; i<size; i++)
			delete GroceryItems[i];//deallocation of memory
	}
};




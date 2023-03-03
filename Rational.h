#pragma once
#include <iostream>
#include <algorithm>
using namespace std;

class Rational
{
private:
	int numerator;
	int denominator;
	int gcd(int a, int b) {
		if (a == 0 ||b == 0)
			return 0;
		else if (a == b)
			return a;
		else if (a > b)
			return gcd(a - b, b);
		else return gcd(a, b - a);
	}
	void normalize()
	{
		if (numerator == 0)
		{
			numerator == 0;
			denominator = 1;
			cout << "\n\t\tThe Rational number that will be entered will be 0/1 due to";
			cout << "\n\t\tthe value of the numerator = 0\n\n";
			return;
		}

		if (numerator == 0 && denominator < 0)
		{
			numerator == 0;
			denominator *= -1;
		}

		if (denominator < 0)
		{
			denominator *= -1;
			numerator *= -1;
		}

		int temp = gcd(abs(numerator), abs(denominator));
		
		numerator /= temp;
		denominator /= temp;

	}
public:
	class ZeroDenominator 
	{
	private:
		string rational;
	public:
		ZeroDenominator()
		{}

		ZeroDenominator(Rational r)
		{
			rational = r.toString();
		}

		string toString()
		{
			return rational;
		}
	};

	Rational()
	{
		numerator = 0;
		denominator = 1;
	}

	string toString()
	{
		return to_string(numerator) + "/" + to_string(denominator);
	}

	Rational(int newN, int newD)
	{
		numerator = newN;
		denominator = newD;
		if (denominator == 0)
			throw ZeroDenominator(*this);

		normalize();
	}

	int getNumerator() const
	{
		return numerator;
	}

	void setNumerator(int newN)
	{
		numerator = newN;
		normalize();
	}

	int getDenominator() const
	{
		return denominator;
	}

	void setDenominator(int newD)
	{
		denominator = newD;
		if (denominator == 0)
			throw ZeroDenominator(*this);

		normalize();
	}

	friend bool operator ==(const Rational& obj1, const Rational& obj2)
	{
		return (obj1.numerator * obj2.denominator) == (obj2.numerator * obj1.denominator);
	}
	

	friend bool operator <(const Rational& obj1, const Rational& obj2)
	{
		return (obj1.numerator * obj2.denominator) < (obj2.numerator * obj1.denominator);
	}

	friend ostream& operator << (ostream& out,  Rational obj)
	{
		out << obj.toString();
		return out;
	}

};
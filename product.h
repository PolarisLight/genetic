#pragma once
#include <bits\stdc++.h>

using namespace std;

#define GENELONG 8
#define VARIA 9999
#define CROSSO 90

#define COMBI 50

inline int getrand(int MIN_VALUE, int MAX_VALUE)
{
	assert(MIN_VALUE < MAX_VALUE);
	return rand() % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE;
}
double power(double base, int exp);
class Person
{
private:
	static int num;
	float gene[GENELONG][2] = { 0 };
	float Haploid[GENELONG] = { 0 };
public:
	Person();
	Person(float g[8][2]);
	Person(const Person &obj);
	~Person();
	void show();
	float* Meiosis();
	Person birth(const Person& other);
};

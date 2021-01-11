#include "product.h"

double power(double base, int exp)
{
	if (exp == 0)
		return 1;
	if (exp == 1)
		return base;
	double result;
	result = power(base, exp >> 1);
	result *= result;
	if (exp & 0x1 == 1)
		result *= base;
	return result;
}

Person::Person()
{
	num++;
	for (int i = 0; i < GENELONG; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			this->gene[i][j] = (rand() % 1000) / 1000.0;
		}
	}
	

}

Person::Person(float g[8][2])
{
	num++;
	for (int i = 0; i < GENELONG; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			this->gene[i][j] = g[i][j];
		}
	}
}

Person::Person(const Person& p)
{
	num++;
	for (int i = 0; i < GENELONG; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			this->gene[i][j] = p.gene[i][j];
		}
	}
}

Person::~Person()
{
	num--;
}
void Person::show()
{
	std::cout << "==============" << std::endl;
	for (int i = 0; i < GENELONG; i++)
	{
		printf("|%.2f || %.2f|\n", this->gene[i][0], this->gene[i][1]);
		std::cout << "|-----||-----|" << std::endl;
	}
	std::cout << "==============" << std::endl;
}

float *Person::Meiosis()
{
	float tempgene[GENELONG][2] = { 0 };
	for (int i = 0; i < GENELONG; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			tempgene[i][j] = this->gene[i][j];
		}
	}
	for (int i = 0; i < GENELONG; i++)
	{
		if (getrand(0, 100) > CROSSO)
		{
			int start, end;
			start = getrand(0, 10 - 1);
			end = start;
			while (getrand(0, 100) > 40)
			{
				if (start == 9)
				{
					end = 9;
					break;
				}
				end++;
				if (end == 9)
					break;
			};
			int gene1 = tempgene[i][0] * 1000, gene2 = tempgene[i][1] * 1000;
			int length = end - start + 1;
			int base1 = power(2, length) - 1;
			base1 = base1 << start;
			int base2 = 1023 - base1;
			int temp1, temp2, temp3, temp4;
			temp1 = gene1 & base1;
			temp2 = gene2 & base1;
			gene1 &= base2;
			gene2 &= base2;
			gene1 |= temp2;
			gene2 |= temp1;
			tempgene[i][0] = gene1 / 1000.0;
			tempgene[i][1] = gene2 / 1000.0;
		}
	}
	for (int i = 0; i < GENELONG; i++)
	{
		if (getrand(0, 100) > COMBI)
		{ 
			float temp = tempgene[i][0];
			tempgene[i][0] = tempgene[i][1];
			tempgene[i][1] = temp;
		}
	}
	if (getrand(0, 100) > 50)
	{
		for (int i = 0; i < GENELONG; i++)
		{
			Haploid[i]= this->gene[i][0];
		}
	}
	else
	{
		for (int i = 0; i < GENELONG; i++)
		{
			Haploid[i] = this->gene[i][1];
		}
	}
	for (int i = 0; i < GENELONG; i++)
	{
		if (getrand(0, 10000) > VARIA)
		{
			int temp = Haploid[i] * 1000;
			int place = getrand(0, 9);
			int mask = 1 << place;
			temp = (temp & ~mask) | (temp ^ mask);
			Haploid[i] = temp / 1000.0;
		}
	}
	return Haploid;
}

Person Person::birth(const Person& other)
{
	float newgene[GENELONG][2] = { 0 };
	for (int i = 0; i < GENELONG; i++)
	{
		newgene[i][0] = this->Haploid[i];
		newgene[i][0] = other.Haploid[i];
	}
	Person child = Person(newgene);
	return child;
}
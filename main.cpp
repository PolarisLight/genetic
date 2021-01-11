#include <bits\stdc++.h>
#include "product.h"
#include <Windows.h>


int Person::num = 0;

int main()
{
	srand(time(0));

	Person person[10];
	int start, end;
	start = getrand(0, 10 - 1);
	end = start;
	while (getrand(0,100)>40)
	{
		if (start == 9)
		{
			end = 9;
			break;
		}
		end++;
		if (end == 9)
			break;
	} ;
	int gene1 = 654, gene2 = 454;
	int length = end - start + 1;
	cout << "start:" << start << "\tend:" << end << "\tlength:" << length << endl;
	int base1 = power(2, length) - 1;
	base1 = base1 << start;
	cout << "base1:"<<bitset<10>(base1) << endl;
	int base2 = 1023 - base1;
	cout << "base2:" << bitset<10>(base2) << endl;
	int temp1, temp2, temp3, temp4;
	cout << bitset<10>(gene1) << endl;
	cout << bitset<10>(gene2) << endl;
	temp1 = gene1 & base1;
	temp2 = gene2 & base1;
	gene1 &= base2;
	gene2 &= base2;
	gene1 |= temp2;
	gene2 |= temp1;
	std::cout << std::bitset<10>(gene1) << std::endl;
	std::cout << std::bitset<10>(gene2) << std::endl;
	system("pause");
	return 0;
}

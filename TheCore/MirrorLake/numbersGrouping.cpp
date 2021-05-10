/*
You are given an array of integers that you want distribute between several groups. The first group should contain numbers from 1 to 104,
the second should contain those from 104 + 1 to 2 * 104, ...,
the 100th one should contain numbers from 99 * 104 + 1 to 106 and so on.

All the numbers will then be written down in groups to the text file in such a way that:

the groups go one after another;
each non-empty group has a header which occupies one line;
each number in a group occupies one line.
Calculate how many lines the resulting text file will have.

Example

For a = [20000, 239, 10001, 999999, 10000, 20566, 29999], the output should be
numbersGrouping(a) = 11.

The numbers can be divided into 4 groups:

239 and 10000 go to the 1st group (1 ... 104);
10001 and 20000 go to the second 2nd (104 + 1 ... 2 * 104);
20566 and 29999 go to the 3rd group (2 * 104 + 1 ... 3 * 104);
groups from 4 to 99 are empty;
999999 goes to the 100th group (99 * 104 + 1 ... 106).
Thus, there will be 4 groups (i.e. four headers) and 7 numbers, so the file will occupy 4 + 7 = 11 lines.
*/

/*
You are given an array of integers that you want distribute between several groups.
The first group should contain numbers from 1 to 104, the second should contain those from 104 + 1 to 2 * 104, ...,
the 100th one should contain numbers from 99 * 104 + 1 to 106 and so on.

All the numbers will then be written down in groups to the text file in such a way that :

the groups go one after another;
each non - empty group has a header which occupies one line;
each number in a group occupies one line.
Calculate how many lines the resulting text file will have.

Example

For a = [20000, 239, 10001, 999999, 10000, 20566, 29999], the output should be
numbersGrouping(a) = 11.

The numbers can be divided into 4 groups:

239 and 10000 go to the 1st group(1 ... 104);
10001 and 20000 go to the second 2nd(104 + 1 ... 2 * 104);
20566 and 29999 go to the 3rd group(2 * 104 + 1 ... 3 * 104);
groups from 4 to 99 are empty;
999999 goes to the 100th group(99 * 104 + 1 ... 106).
Thus, there will be 4 groups(i.e.four headers) and 7 numbers, so the file will occupy 4 + 7 = 11 lines.
*/

#include <iostream>
#include <vector>
#include <map>

using  namespace std;

#define ll long long

ll numberth(ll n)
{
	if (n <= pow(10, 4))
		return 1;

	int digits = n / pow(10, 4);
	if (n > digits * pow(10, 4) && n <= ((digits + 1) * pow(10, 4)))
	{
		return digits + 1;
	}
	return digits;
}

bool isExist(map<ll, ll> grouping, ll value)
{
	for (map<ll, ll>::iterator run = grouping.begin(); run != grouping.end(); run++)
	{
		if (run->first == numberth(value))
			return true;
	}
	return false;
}

int numbersGrouping(vector<int> a) {

	map<ll, ll> numbers_Grouping;

	int len = a.size();

	for (auto i : a)
	{
		ll digit = numberth(i);

		if (isExist(numbers_Grouping, i) == false)
		{
			numbers_Grouping.insert(make_pair(digit, 1));
		}
	}
	return  numbers_Grouping.size() + len;
}


int main ()
{
	              //    2     1     -      99      -      3      -
	vector<int> a = { 629331440, 494232287, 136272236, 273050203, 434470602, 578856790, 415897234, 966510740, 460572448,
	390601670, 656646086, 990687321, 94779681, 439389814, 621806166, 389349001, 619737138, 72112342, 943964832, 209248844,
	410529154, 179744122, 109498075, 470133382, 384808947, 265438855, 957869901, 198106795, 369266892, 373181217, 285933178,
	404144322, 177314269, 868322471, 966591040, 210800389, 948207480, 938683342, 508844544, 444923069, 450556727, 354970474,
	969260313, 670387566, 199153186, 321033095, 50409663, 722374610, 578470832, 123616739, 39278224, 323213274, 908279195,
	429594353, 563038045, 499215908, 637318359, 597941946, 925217519, 615157350, 818984131, 502451407, 951625218, 177425017,
	614671069, 492546513, 431972731, 974981867, 438550378, 969803542, 111214977, 705287873, 697346808, 980965347, 256156127,
	183254413, 315410288, 710199567, 1257361, 732631481, 719752645, 711132059, 773404229, 394266157, 640920785, 607172585,
	214329305, 844989000, 880094155, 22115870, 935012242, 228822777, 16224959, 711171706, 37406857, 980125095, 246102805,
	990976248, 474483642, 393584803 }; // output have to be 16315
	// 1th = 239, 10000
	// 2th = 10001, 20000,
	// 3th = 20566, 29999
	// 99th = 99999
	cout << numbersGrouping(a) << "\n"; 
	return 0;
}

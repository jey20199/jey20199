#include <iostream>
#include <set>
#include<ctime>
#include <fstream>
#include <algorithm>
#include <functional> // greater
#include <vector>
#include <deque>
#include <map>
using namespace std;

//bool find(multiset<int>& ms, int value)
//{
//	for (auto el : ms)
//	{
//		if (el == value)
//			return true;
//	}
//	return false;
//}
template <typename T>
void printVec(vector<T> v)
{
	for (auto el : v)
	{
		cout << el << " ";
	}
	cout << endl;
}
bool isEven(int a)
{
	return a % 2 == 0; // 4 % 2
}
int randomT()
{
	return rand() % 50 + 50;
}
class Random {
	int min;
	int max;
public:
	Random(int min, int max) : min(min), max(max) {
		if (max < min)
		{
			swap(this->min, this->max);
		}
	}

	int operator()()
	{
		return rand() % (max - min + 1) + min;
	}
};
class Multiplier {
	int mult;
public:
	Multiplier(int mult): mult(mult){}

	void operator() (int & elem)
	{
		 elem =  elem * mult;
	}
};
void main()
{
	srand(time(0));
	ofstream out("set.txt");
	set <int, greater<int>> s1 = { 78,6,54,0, 9,13, 6, 10,-3, 0, 6 };
	s1.insert(5);
	for (auto el : s1)
	{
		cout << el << " ";
	}
	cout << endl;
	multiset <int> ms1 = { 78,6,54,0, 9,13, 6, 10,-3, 0, 6 };
	for (auto el : ms1)
	{
		cout << el << "\t";
	}
	cout << endl;
	set <int> s2(ms1.begin(), ms1.end());
	cout << "set from multiset" << endl;
	if (out) {
		for (auto el : s2)
		{
			out << el << " ";
			cout << el << " ";
		}
		out << endl;
	}
	else cout << "file not found" << endl;
	out.close();
	cout << endl;

	set <int> s3;
	ifstream in("set.txt");
	if (in)
	{
		int temp;
		while (!in.eof())
		{
			in >> temp; //cin >> temp;
			s3.insert(temp);
		}
	}
	else  cout << "file not found" << endl;
	cout << "After read" << endl;
	for (auto el : s3)
	{
		cout << el << " ";
	}
	auto it = find(ms1.begin(), ms1.end(), 6);
	if (it != ms1.end())
	{
		cout << endl << "find in pos " << *it << endl;
	}
	else
		cout << "Not found" << endl;
	cout << endl << "Vector: " << endl;
	vector <int> v1;
	for (int i = 0; i < 10; i++) {
		v1.push_back(rand() % 100);
		cout << v1[i] << " ";
	}

	cout << endl << "After sort: " << endl;;

	sort(v1.begin(), v1.end()); //[](int el, int el2) {return el > el2; }
	for (int i = 0; i < 10; i++) {
		cout << v1[i] << " ";
	}

	cout << "Count 6 = " << count(ms1.begin(), ms1.end(), 6) << endl;
	cout << "Count 6 = " << count(ms1.begin(), ms1.end(), 66) << endl;
	cout << endl << "after shuffle v1" << endl;
	random_shuffle(v1.begin() + 3, v1.end() - 1);
	printVec(v1);
	int arr[10];

	copy(v1.begin(), v1.end(), arr);
	cout << "Algorithm copy" << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
	vector <int> v2(10);
	cout << "Generate: " << endl;
	generate(v2.begin(), v2.end(), randomT);
	printVec(v2);

	cout << "Generate lambda" << endl;
	deque <int> d(10);
	int a, b;
	//	cin >> a >> b;
		//generate(d.begin(), d.end(), [&a, &b]()
		//	{
		//		return rand() % a + b;
		//	});
	for (auto el : d)
	{
		cout << el << "\t";
	}
	cout << endl;

	vector <string> str = { "omh", "bla-bla", "hello", "ab" }; // ab, bla-bla, hello, omh

	sort(str.begin(), str.end());
	printVec(str);

	sort(str.begin(), str.end(), [](string a, string b) {
		return a.size() < b.size();
		});
	printVec(str);
	printVec(v2);
	cout << "Count even numbers " << count_if(v2.begin(), v2.end(), isEven) << endl;
	auto it2 = find_if(str.begin(), str.end(), [](string str) {
		return str.size() > 3;
		});

	if (it2 != str.end())
	{
		cout << "found in pos " << *it2 << endl;
	}
	else
		cout << "Not found" << endl;

	cout << "\nRandom r(5,20) - class functor" << endl;
	Random r(5, -5);
	generate(v1.begin(), v1.end(), r);
	printVec(v1);

	cout << "for_each Multiplier()" << endl;
	for_each(v1.begin(), v1.end(), Multiplier(10));
	printVec(v1);

}
// comment git

//25.08.2019
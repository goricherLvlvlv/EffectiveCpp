#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <stack>
#include <algorithm>
#include <ctime>
#include <functional>
#include "calc_time.h"

using namespace std;


// Item 02
#define call_Max(a,b) Item02_func((a)>(b)?(a):(b))
class Item02_class {
public:
	static const int NumTurns;

};
const int Item02_class::NumTurns = 1;

void Item02_func(int i) {
	cout << i;
}

template<class T>
inline void call_Item02_func_Max(T& a, T& b) {
	Item02_func(a > b ? a : b);
}

// Item 03
void Item03_test() {
	vector<int> vec = { 1,2,3 };
	const vector<int>::iterator c_it = vec.begin();
	vector<int>::iterator it = vec.begin();

	// ����, ����ת��, �Ǹ�����ָ��
	// c_it = vec.end();
	it = vec.end();

	*c_it = 5;
}

class Item03_class {
private:
	string str;
	mutable int val;
public:
	// ��const�������
	const char& operator[](int index) const { 
		/*
			...
			...
			...
			...
			����ǰ������ôһ�κ�������
		*/
		return str[index]; 
	}
	// ����const�������
	char& operator[](int index) { 
		// ����ͨ����this��Ϊconst����, ����const����
		// �ٽ�����ֵ����const, ��ʡ��...���ֵ��ظ�����
		return const_cast<char&> (
			static_cast<const Item03_class&>(*this)[index]
			);
	}

	// ��const�����ﷵ�ط�const����
	int& length() const{
		val = 8;	// ���Ա��ֵ
		return val;
	}

	Item03_class(string s, int v) :str(s),val(v) {}
};

// Item 04
class PhoneNumber {
public:
	PhoneNumber(int v, int i) :val(v), id(i) {  }
private:
	int val;
	int id;
};

class ABEntry {
public:
	// ��ֵ
	ABEntry(const std::string& name, const std::string& address, const std::vector<PhoneNumber>& phones) {
		theName = name;
		theAddress = address;
		thePhones = phones;
		numTimesConsulted = 0;
	}

	// ��ʼ��
	ABEntry(const std::string& name, const std::string& address, const std::vector<PhoneNumber>& phones, int times)
		:theName(name), theAddress(address), thePhones(phones), numTimesConsulted(times) {  }
private:
	std::string theName;
	std::string theAddress;
	std::vector<PhoneNumber> thePhones;
	int numTimesConsulted;
};

void ABE_ctr_copy() {
	PhoneNumber p1 = PhoneNumber(1, 1);
	PhoneNumber p2 = PhoneNumber(1, 1);

	vector<PhoneNumber> vp = { p1, p2 };
	ABEntry(string("goricher"), string("hz"), vp);
}

void ABE_ctr_init() {
	PhoneNumber p1 = PhoneNumber(1, 1);
	PhoneNumber p2 = PhoneNumber(1, 1);

	vector<PhoneNumber> vp = { p1, p2 };
	ABEntry(string("goricher"), string("hz"), vp, 0);
}

int main() {
	time_test(ABE_ctr_copy, ABE_ctr_init);
	
 	getchar();
}
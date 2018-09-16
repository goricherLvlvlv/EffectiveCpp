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

	// 报错, 不可转换, 是个常量指针
	// c_it = vec.end();
	it = vec.end();

	*c_it = 5;
}

class Item03_class {
private:
	string str;
	mutable int val;
public:
	// 被const对象调用
	const char& operator[](int index) const { 
		/*
			...
			...
			...
			...
			假设前面有这么一段函数内容
		*/
		return str[index]; 
	}
	// 被非const对象调用
	char& operator[](int index) { 
		// 这里通过将this变为const对象, 调用const函数
		// 再将返回值脱下const, 节省了...部分的重复内容
		return const_cast<char&> (
			static_cast<const Item03_class&>(*this)[index]
			);
	}

	// 在const函数里返回非const对象
	int& length() const{
		val = 8;	// 可以变更值
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

class Item04_class {
public:
	// 赋值
	Item04_class(const std::string& name, const std::string& address, const std::vector<PhoneNumber>& phones) {
		theName = name;
		theAddress = address;
		thePhones = phones;
		numTimesConsulted = 0;
	}

	// 初始化
	Item04_class(const std::string& name, const std::string& address, const std::vector<PhoneNumber>& phones, int times)
		:theName(name), theAddress(address), thePhones(phones), numTimesConsulted(times) {  }
private:
	std::string theName;
	std::string theAddress;
	std::vector<PhoneNumber> thePhones;
	int numTimesConsulted;
};

void Item04_class_copy() {
	PhoneNumber p1 = PhoneNumber(1, 1);
	PhoneNumber p2 = PhoneNumber(1, 1);

	vector<PhoneNumber> vp = { p1, p2 };
	Item04_class(string("goricher"), string("hz"), vp);
}

void Item04_class_init() {
	PhoneNumber p1 = PhoneNumber(1, 1);
	PhoneNumber p2 = PhoneNumber(1, 1);

	vector<PhoneNumber> vp = { p1, p2 };
	Item04_class(string("goricher"), string("hz"), vp, 0);
}

// Item 05
class Item05_class {
	// 下列函数在为主动定义时, 会自动生成

	// Item05_class() { ... }										// default构造函数
	// Item05_class(const Item05_class& i5) { ... }					// copy构造函数
	// ~Item05_class() { ... }										// 析构函数
	// Item05_class& operator=(const Item05_class& i5){ ... }		// copy assignment运算符

};

// Item 06
class Item06_class {
public:
	Item06_class() {}
	~Item06_class() {}
	
	// cpp 11 的用法
	Item06_class(const Item06_class& i6) = delete;
	Item06_class& operator=(const Item06_class& i6) = delete;
private:
	// 与上述定义成=delete效果雷同
	// Item06_class(const Item06_class& i6);
	// Item06_class& operator=(const Item06_class& i6);
};


int main() {
	
	
 	getchar();
}
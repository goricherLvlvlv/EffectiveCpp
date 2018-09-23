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

class Item04_class {
public:
	// ��ֵ
	Item04_class(const std::string& name, const std::string& address, const std::vector<PhoneNumber>& phones) {
		theName = name;
		theAddress = address;
		thePhones = phones;
		numTimesConsulted = 0;
	}

	// ��ʼ��
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

void Item04_test_1() {
	// �Աȿ����ͳ�ʼ��ʱ��Ļ���
	time_test(Item04_class_copy, Item04_class_init);
}

// Item 05
class Item05_class {
	// ���к�����Ϊ��������ʱ, ���Զ�����

	// Item05_class() { ... }										// default���캯��
	// Item05_class(const Item05_class& i5) { ... }					// copy���캯��
	// ~Item05_class() { ... }										// ��������
	// Item05_class& operator=(const Item05_class& i5){ ... }		// copy assignment�����

};

// Item 06
class Item06_class {
public:
	Item06_class() {}
	~Item06_class() {}
	
	// cpp 11 ���÷�
	Item06_class(const Item06_class& i6) = delete;
	Item06_class& operator=(const Item06_class& i6) = delete;
private:
	// �����������=deleteЧ����ͬ
	// Item06_class(const Item06_class& i6);
	// Item06_class& operator=(const Item06_class& i6);
};

// Item 07
class Item07_base_class {
public:
	Item07_base_class() {}
	virtual ~Item07_base_class() {
		cout << "delete base" << endl;
	}
};

class Item07_derived_class :public Item07_base_class {
public:
	Item07_derived_class() {}
	virtual ~Item07_derived_class() {
		cout << "delete derived" << endl;
	}
};

void Item07_test_1() {
	Item07_base_class* i7 = new Item07_derived_class();
	delete i7;
}

// Item 08
class Item08_class {
public:

	static Item08_class create() {
		Item08_class i8 = Item08_class();
		return i8;
	}

	void close() {}
};

class Item08_controll_class {
public:
	Item08_controll_class() {
		i8 = Item08_class::create();
	}
	~Item08_controll_class() {
		//i8.close();
		//try {
		//	i8.close();
		//}
		//catch (exception e) {
		//	// �������κ�������, ֱ�ӽ�������
		//	// ���ǽϼѵĲ���
		//	// std::abort();
		//}

		// �ϼѲ���
		if (!closed) {
			try {
				i8.close();
			}
			catch (exception e) {
				// ...
			}

		}
	}

	// �����ζ�����Ŀͻ�, �������������ڵڶ��ر���
	void close() {
		i8.close();
		closed = true;
	}
private:
	Item08_class i8;
	bool closed;
};

void Item08_test() {
	Item08_controll_class i8_con = Item08_controll_class();
}

// Item 09
class Item09_base_class {
public:
	Item09_base_class() {
		// ����
		// �ڴ���i9_1����ʱ, ���ȵ���base_class�Ĺ��캯��
		// ��ʱ���������log, ��δ�½���derived_class�Ĳ��, ����ô��麯��
		log();
	}

	~Item09_base_class() {
		log();
	}

	virtual void log() const {
		cout << 0;
	}
};

class Item09_derived_class_1 :public Item09_base_class {
public:
	Item09_derived_class_1() {
		log();
	}

	~Item09_derived_class_1() {
		log();
	}

	virtual void log() const{
		cout << 1;
	}
};

class Item09_derived_class_2 :public Item09_base_class {
public:
	Item09_derived_class_2() {
		log();
	}

	~Item09_derived_class_2() {
		log();
	}

	virtual void log() const {
		cout << 2;
	}
};

void Item09_test() {
	Item09_derived_class_1 i9_1;
	
}

// Item 10
class Item10_class {
public:
	Item10_class() :val(0) {}
	Item10_class(int v) :val(v) {}
	// Э��, ����*this��reference
	Item10_class& operator+=(const Item10_class& i10) {
		val += i10.val;
		return *this;
	}
	Item10_class& operator=(const Item10_class& i10) {
		val = i10.val;
		return *this;
	}
	Item10_class& operator=(int rhs) {
		val = rhs;
		return *this;
	}
private:
	int val;
};

// Item 11
class Item11_class {
public:
	void swap(const Item11_class& rhs) {
		// ����*this��rhs������
		// Item 29������ʱ����ϸд
	}

	Item11_class & operator=(const Item11_class& rhs) {

		// ������������Ҫ����Σ��, һ��new int�����쳣, ��᷵��һ��ָ����ɾ���ڴ��ָ��
		// C++11�п���ʹ��pint = nullptr;���������������, �����в���Ҫ����nullptr��д��
		/*if (this == &rhs) return *this;

		delete pint;
		pint = new int(*rhs.pint);
		return *this;*/
		
		// ���õķ���
		// ��ʹnew�����쳣, ��ôpint���ڴ����ɱ�����
		auto tmp = pint;
		pint = new int(*rhs.pint);
		delete tmp;
		return *this;

		// ����ķ���
		// ����swap, �ñ������Զ�ȥ�����ڴ�
	}
private:
	int* pint;
};

// Item 12
class Item12_base_class {
public:
	Item12_base_class(const Item12_base_class& i12_b) :base(i12_b.base) {}
	Item12_base_class& operator=(const Item12_base_class& i12_b) {
		base = i12_b.base;
		return *this;
	}
private:
	int base;
};

class Item12_derived_class :public Item12_base_class {
public:
	Item12_derived_class(const Item12_derived_class& i12_d) :Item12_base_class(i12_d), derived(i12_d.derived) {}
	Item12_derived_class& operator=(const Item12_derived_class& i12_d) {
		Item12_base_class::operator=(i12_d);
		derived = i12_d.derived;
		return *this;
	}
private:
	int derived;
};

// Item 13
class Item13_class {

};

void Item13_test() {
	int *p;
	{
		shared_ptr<int> sp(new int(5));
		p = sp.get();
	}
	cout << *p;
}

// Item 14
class Mutex {

};
void lock(Mutex* m) {}
void unlock(Mutex* m) {}
class Item14_class {
public:
	explicit Item14_class(Mutex* m) :mutexPtr(m, unlock) {
		lock(mutexPtr.get());
	}
	
private:
	shared_ptr<Mutex> mutexPtr;
};

// Item 15
class Item15_class {
	// APIs����Ҫ�����ԭʼ��Դ. ����ÿ��RAII classӦ���ṩһ��get����.
};

// Item 18
struct year {
	int val;
	explicit year(int y) :val(y) {}
};
class month {
public:
	// ��static����������캯��, ��֤�����ֳ���1-12��Χ���·�
	static month Jan() { return month(1); }
	static month Feb() { return month(2); }
	static month Mar() { return month(3); }
	static month Apr() { return month(4); }
	static month May() { return month(5); }
	static month Jun() { return month(6); }
	static month Jul() { return month(7); }
	static month Aug() { return month(8); }
	static month Sept() { return month(9); }
	static month Oct() { return month(10); }
	static month Nov() { return month(11); }
	static month Dec() { return month(12); }
private:
	int val;
	explicit month(int m) :val(m) {}
};
struct day {
	int val;
	explicit day(int d) :val(d) {}
};
class Item18_class {
public:
	Item18_class(const year& y, const month& m, const day& d) :y(y), m(m), d(d) {
		
	}
private:
	year y;
	month m;
	day d;
};

// Item 20
class Item20_class {
public:
	Item20_class() :name(""), id(0) {
		cout << "default construct" << endl;
	}
	Item20_class(const Item20_class& i20) :name(i20.name), id(i20.id) {
		cout << "copy construct" << endl;
	}
	~Item20_class() {
		cout << "default deconstruct" << endl;
	}
private:
	string name;
	int id;
};
void Item20_test(Item20_class i20) {}
void Item20_func() {
	Item20_class i20_1 = Item20_class();
	Item20_class i20_2(i20_1);
	// ����copy
	Item20_test(i20_2);
}

// Item 21
class Item21_class {
public:
	Item21_class(int numerator = 0, int denumerator = 1) :n(numerator), d(denumerator) {

	}
	~Item21_class(){
		cout << "deconstruct" << endl;
	}

	int n, d;
	friend const Item21_class& operator*(const Item21_class& lhs, const Item21_class& rhs);
};
// �������ñ��봴������, ���������ܹ�ܹ��캯���ĵ���
const Item21_class& operator*(const Item21_class& lhs, const Item21_class& rhs) {
	// ����ʵ�� stack
	// ������һ���ֲ������ĵ�ַ
	Item21_class res(lhs.n*rhs.n, lhs.d*rhs.d);
	return res;// ������������

	// ������ʵ�� heap
	// �ڴ�й©
	// w = x*y*z;ʱ��Ҫ����delete, ����û�а취����2��delete
	/*Item21_class* res = new Item21_class(lhs.n*rhs.n, lhs.d*rhs.d);
	return *res;*/

	
}

void Item21_func() {
	Item21_class a(1, 2); // 1/2
	Item21_class b(3, 5); // 3/5

	Item21_class c = a * b; // 3/10

	c.n = 5;
	cout << c.n << endl << c.d << endl;
}

// Item 24
class Item24_class {
public:
	// ��explicit
	Item24_class(int n = 0, int d = 1) :n(n), d(d) {

	}

	inline int num() const{
		return n;
	}

	inline int denum() const{
		return d;
	}

	//const Item24_class operator*(const Item24_class& i24) const {
	//	// i24 * 2 ---- ��ȷ
	//	// 2 * i24 ---- ����
	//	return Item24_class(this->n * i24.n, this->d * i24.d);
	//}
private:
	int n, d;
};
// i24 * 2 ---- ��ȷ
// 2 * i24 ---- ��ȷ
const Item24_class operator*(const Item24_class& i24_1, const Item24_class& i24_2) {
	return Item24_class(i24_1.num() * i24_1.num(), i24_2.denum() * i24_2.denum());
}



int main() {
	//1. time_test(function, function)	����������������1000��ʱ��Ĳ��
	Item21_func();
	
 	getchar();
}
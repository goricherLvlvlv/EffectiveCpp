#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <stack>
#include <algorithm>
#include <ctime>
#include <functional>
#include <memory>
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

// Item 25
class Item25_class_impl {
public:
private:

};

class Item25_class {
public:
	Item25_class(const Item25_class& rhs) {
		
	}

	Item25_class& operator=(const Item25_class& rhs) {
		*i25_impl = *(rhs.i25_impl);
	}

	void swap(Item25_class& other) {
		std::swap(this->i25_impl, other.i25_impl);
	}
private:
	Item25_class_impl * i25_impl;
};



// ������
namespace std {
	template<>
	void swap<Item25_class>(Item25_class& i25_1, Item25_class& i25_2) {
		// pimpl��˽�г�Ա, ���ǳ���һ��member����������˽�г�Ա.
		i25_1.swap(i25_2);
	}
}

// Item 27
class Item27_base_base_class {};
class Item27_base_class:public Item27_base_base_class {
public:
	virtual void print() {
		key = 7;
		cout << "window key: " << key << endl;
		
	}

	int key;
};
class Item27_derived_class:public Item27_base_class {
public:
	virtual void print() {
		// window key: 7
		// derived key : -858993460
		// ʵ���ϵ��õ�print��key���޸Ĳ����ǶԸ�derived���key�����޸�, ���ǵ�ǰ�����base class���ֵĸ��������޸�
		static_cast<Item27_base_class>(*this).print();
		cout << "derived key: " << key << endl;
	}
};
void Item27_func() {
	Item27_derived_class d;
	Item27_base_class* pb = &d;
	Item27_derived_class* pd = &d;
	// û����offset, ������������ʱ�Ѿ��������
	cout << "pb: " << pb << endl << "pd: " << pd << endl;

	
	
	// ����ֱ����ʾ����base�ĺ���
	pd->Item27_base_class::print();
	cout << pd->key;
}

// Item 28
class Item28_point {
public:
	Item28_point(int x, int y) :x(x), y(y) {
		
	}
	void setX(int newVal) {
		x = newVal;
	}
	void setY(int newVal) {
		y = newVal;
	}
private:
	int x;
	int y;
};

class Item28_RectData {
public:
	Item28_point u_lh_c;
	Item28_point l_rh_c;
};

class Item28_Rectangle {
public:
	// ����const, ���ⷵ�صĵ���Ա��û�ֱ���޸�
	// ���ǵ��û�����һ����ʱrectangle����ʱ, ���ܻᵼ�����溯���ķ���ֵ�����յ�ָ��
	const Item28_point& upperLeft() const { return data->u_lh_c; }
	const Item28_point& lowerRight() const { return data->l_rh_c; }
private:
	shared_ptr<Item28_RectData> data;
};

// Item 31
class Item31_date {};
class Item31_address {};

class Item31_person {
public:
	virtual ~Item31_person() {}
	virtual string name() const = 0;
	virtual string birthDate() const = 0;
	virtual string address() const = 0;
	static shared_ptr<Item31_person> create(const string& name, const Item31_date& date, const Item31_address& address);
private:

};

class Item31_real_person:public Item31_person {
public:
	Item31_real_person(const string& name, const Item31_date& birthday, const Item31_address& addr) :theName(name), theBirth(birthday), theAddr(addr) {  }
	virtual ~Item31_real_person() {}
	string name() const {
		return "name";
	}
	string birthDate() const {
		return "birthday";
	}
	string address() const {
		return "address";
	}
private:
	string theName;
	Item31_date theBirth;
	Item31_address theAddr;
};

// factory����ʵ��
shared_ptr<Item31_person> Item31_person::create(const string& name, const Item31_date& date, const Item31_address& address) {
	return shared_ptr<Item31_person>(new Item31_real_person(name, date, address));
}

void Item31_func() {
	string name = "goricher";
	Item31_date birth;
	Item31_address addr;

	shared_ptr<Item31_person> ptr(Item31_person::create(name, birth, addr));
	cout << ptr->name() << endl << ptr->birthDate() << endl << ptr->address() << endl;
}

// Item 33
class Item33_base_class {
public:
	virtual void mf1() = 0;
	virtual void mf1(int) { cout << "base::mf1(int)" << endl; }
	virtual void mf2() { cout << "base::mf2()" << endl; }
	virtual void mf3() { cout << "base::mf3()" << endl; }
	virtual void mf3(double) { cout << "base::mf3(double)" << endl; }
private:
	int x;
};

class Item33_derived_class : public Item33_base_class {
public:
	// ��ʾ����, ��base�е�mf1��mf3��derived�������пɼ�, ��ֹ������
	using Item33_base_class::mf1;
	using Item33_base_class::mf3;

	virtual void mf1() { cout << "derived::mf1()" << endl; }
	void mf3() { cout << "derived::mf3()" << endl; }
	void mf4() { cout << "derived::mf4()" << endl; }
};

class Item33_derived_2_class : private Item33_base_class {
public:
	virtual void mf1() {
		// inlineת������
		// ��ʽ����Ϊinline, ת����baseֱ�ӵ��ú���
		Item33_base_class::mf1(1);
	}
};

void Item33_func() {
	Item33_derived_class d;
	d.mf1();					// derived mf1()
	d.mf1(1);					// base mf1(int)
	d.mf3();					// derived mf3()
	d.mf3(1.1);					// base mf3(double)
	d.mf4();					// derived mf4()

	Item33_derived_2_class d2;
	d2.mf1();
	//d2.mf2();					// private�̳в���ʹ��
	//d2.mf3();
}

// Item 34
class Item34_shape {
public:
	// pure virtual function
	// ������ʵ�ֶ���, ��Ҫ��ʾ����
	virtual void draw() const = 0;
	// impure virtual function
	virtual void error(const string& msg) {}
	int objectID() const {}
};

// ����
class Item34_rectangle :public Item34_shape {
	void draw() const {}
	void error(const string& msg) {}
};
// ��Բ
class Item34_ellipse :public Item34_shape {
	void draw() const {}
	void error(const string& msg) {}
};

// Item 35

// Template Methodģʽ
class Item35_character {
public:
	// �����������Լ����麯��
	// non-virtual interface ==> NVI
	int healthValue() const { return doHealthValue(); }

	Item35_character() {}
	Item35_character(int val) :health(val) {}
private:
	virtual int doHealthValue() const { 
		cout << "Item35_character" << endl;
		return health; 
	}
	int health;
};

class Item35_player:public Item35_character {
public:
	Item35_player(int val) :health(val) {}
private:
	virtual int doHealthValue() const {
		cout << "Item35_player" << endl;
		return health;
	}
	int health;
};
class Item35_monster:public Item35_character {
public:
	Item35_monster(int val) :health(val) {}
private:
	virtual int doHealthValue() const {
		cout << "Item35_monster" << endl;
		return health;
	}
	int health;
};

void Item35_func() {
	Item35_character* p1 = new Item35_player(1);
	Item35_character p2(2);

	p1->healthValue();
	p2.healthValue();
}

// Strategyģʽ
class Item35_character_2;
int defaultHealthCalc(const Item35_character_2& gc) { return 1; }
class Item35_character_2 {
public:
	// ����ָ������
	//typedef int(*HealthCalcFunc)(const Item35_character_2&);
	// ��һ�ֺ���ָ��
	using HealthCalcFunc = function<int(const Item35_character_2&)>;

	explicit Item35_character_2(HealthCalcFunc hcf = defaultHealthCalc) :healthFunc(hcf) {}

	int healthValue() const { return healthFunc(*this); }
private:
	HealthCalcFunc healthFunc;
};

class Item35_player_2 :public Item35_character_2 {
public:
	explicit Item35_player_2(HealthCalcFunc hcf = defaultHealthCalc) :Item35_character_2(hcf) {}
};




int main() {
	//1. time_test(function, function)	����������������1000��ʱ��Ĳ��
	Item35_func();
	
 	getchar();
}
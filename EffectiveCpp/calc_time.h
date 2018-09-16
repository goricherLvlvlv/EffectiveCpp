#ifndef _CALC_TIME_H_
#define _CALC_TIME_H_
#include <iostream>
#include <functional>
#include <ctime>
using namespace std;
// 对比f1与f2操作时间
// void()类型
template <class T>
void time_test(T f1, T f2) {
	int t1 = 1000, t2 = 1000;

	auto t1b = (double)clock() / CLOCKS_PER_SEC;
	while (t1--)
		f1();
	auto t1a = (double)clock() / CLOCKS_PER_SEC;

	auto t2b = (double)clock() / CLOCKS_PER_SEC;
	while (t2--)
		f2();
	auto t2a = (double)clock() / CLOCKS_PER_SEC;

	cout << (t1a - t1b) << endl;
	cout << (t2a - t2b) << endl;
}


#endif
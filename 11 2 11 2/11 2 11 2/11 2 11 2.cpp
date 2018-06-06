#include <iostream>
#include  <fstream>
#include  <string>
#include <windows.h> 
using namespace std;
ofstream Ffout;
int   k1, k2, k3, k4, k5, k6, k7, k8, k9, k10,l; //обьявление переменных  
int per[10] = {k1,k2,k3,k4,k5,k6,k7,k8,k9,k10};  //обьявление массива
int N1 = 10;                                     //обьявление переменной
int *yrr = new int[N1];                          //обьявление массива 
void do1() {
	system("color F0");                          //Инвертация цвета в консоли                                                                           
	setlocale(LC_ALL, "rus");                    //подключение русской библиотеки
	l = 0;
	                                             //обьявление массива
	string rer[10]= { "k1","k2","k3","k4","k5","k6","k7","k8","k9","k10" };
	do {                                         //цикл do while                  
		cout << "Введите-" << rer[l] << endl;    //вывод номера аргумента
		cin >> per[l];
		l++;
	} while (l < 10);
	Ffout << per[l];
}
void do2() {
	int z = 0;                                   //обьявление переменной
	do {                                         //цикл do while 
		                                         //запись в массив функции
		yrr[z] = 20 * (per[z] - 2) - 10 * (per[z] - 1) + 25 * (per[z] - 2);
		z++;
	} while (z < 10);
	cout << endl;
}
void do3() {
	cout << endl;
	int s=0,x=0;                                 //обьявление переменных
	do {                                         //цикл do while 
		if (x < yrr[s])                          // использование if
			x = yrr[s];
		s++;
	} while(s<10);
	cout << "Максимум";                          //вывод текста в консоль
	cout << x<<endl;

	int c = 0, q =x;
	do {                                         //цикл do while 
		if (q > yrr[c])                          //использование if
			q = yrr[c];
		c++;
	} while (c<10);
	cout << " Минимум" ;                         //вывод текста в консоль
	cout << q <<endl;
	cout << " Аргумент";                         //вывод текста в консоль
	cout << endl;
	int si = 0, xi = 0;
	do {                                         //цикл do while 
		if (xi <per[si])                         // использование if
			xi = per[si];
		si++;
	} while (si<10);
	cout << "Максимум";                          //вывод текста в консоль
	cout << xi << endl;
    int ci = 0, qi = xi;                         //обьявление переменных
	do {                                         //цикл do while 
		if (qi >per[ci])                         // использование if
			qi = per[ci];
		ci++;
	} while (ci<10);
	cout << " Минимум";                          //вывод текста в консоль
	cout << qi << endl;
}
void zap() {
	char name[] = "perem.txt";
	fstream fs(name, ios::app);
	int a = 0;                                   //обьявление переменной
	do {                                         //цикл do while 
		fs << per[a]<<" ";
		fs << yrr[a] << endl;
		a++;
	} while (a < 10);
}
int main()
{
	do1();
	do2();
	zap();
	do3();
    system("pause"); 
	return 0;
}

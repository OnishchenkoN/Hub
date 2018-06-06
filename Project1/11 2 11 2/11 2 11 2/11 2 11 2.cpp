
#include <iostream>
#include  <fstream>
#include  <string>

using namespace std;
ofstream Ffout;
int   k1, k2, k3, k4, k5, k6, k7, k8, k9, k10,l;
int per[10] = {k1,k2,k3,k4,k5,k6,k7,k8,k9,k10};
int N1 = 10;
int *yrr = new int[N1];
void do1() {
	system("color F0");                           //Инвертация цвета в консоли                                                                           
	setlocale(LC_ALL, "rus");                     //подключение русской библиотеки
	l = 0;
	string rer[10]= { "k1","k2","k3","k4","k5","k6","k7","k8","k9","k10" };
	
	
	
	do {                      
		cout << "Введите-" << rer[l] << endl;
		cin >> per[l];
		
		l++;
	} while (l < 10);
	Ffout << per[l];
	
}
void do2() {
	int z = 0;
	
	do {
		yrr[z] = 20 * (per[z] - 2) - 10 * (per[z] - 1) + 25 * (per[z] - 2);
		z++;
		
	} while (z < 10);
	cout << endl;
	
	

}

void do3() {
	cout << endl;
	int s=0,x=0;
	do {
		if (x < yrr[s])
			x = yrr[s];
		s++;
	} while(s<10);
	cout << "Максимум";
	cout << x<<endl;

	int c = 0, q =x;
	do {
		if (q > yrr[c])
			q = yrr[c];
		c++;
	} while (c<10);
	cout << " Минимум" ;
	cout << q <<endl;


	//////////////////////////
	cout << " Аргумент";
	cout << endl;
	int si = 0, xi = 0;
	do {
		if (xi <per[si])
			xi = per[si];
		si++;
	} while (si<10);
	cout << "Максимум";
	cout << xi << endl;

	int ci = 0, qi = xi;
	do {
		if (qi >per[ci])
			qi = per[ci];
		ci++;
	} while (ci<10);
	cout << " Минимум";
	cout << qi << endl;
}


void zap() {
	char name[] = "perem.txt";
	fstream fs(name, ios::app);
	int a = 0;
	do {
		fs << per[a]<<" ";
		fs << yrr[a] << endl;
		
		a++;
	} while (a < 10);
}
//void spc() {}
int main()
{
	do1();
	do2();
	zap();
	//spc();
	do3();

	system("pause"); 
	return 0;
}

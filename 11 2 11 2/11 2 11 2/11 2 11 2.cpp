#include <iostream>
#include  <fstream>
#include  <string>
#include <windows.h> 
using namespace std;
ofstream Ffout;
int   k1, k2, k3, k4, k5, k6, k7, k8, k9, k10,l; //���������� ����������  
int per[10] = {k1,k2,k3,k4,k5,k6,k7,k8,k9,k10};  //���������� �������
int N1 = 10;                                     //���������� ����������
int *yrr = new int[N1];                          //���������� ������� 
void do1() {
	system("color F0");                          //���������� ����� � �������                                                                           
	setlocale(LC_ALL, "rus");                    //����������� ������� ����������
	l = 0;
	                                             //���������� �������
	string rer[10]= { "k1","k2","k3","k4","k5","k6","k7","k8","k9","k10" };
	do {                                         //���� do while                  
		cout << "�������-" << rer[l] << endl;    //����� ������ ���������
		cin >> per[l];
		l++;
	} while (l < 10);
	Ffout << per[l];
}
void do2() {
	int z = 0;                                   //���������� ����������
	do {                                         //���� do while 
		                                         //������ � ������ �������
		yrr[z] = 20 * (per[z] - 2) - 10 * (per[z] - 1) + 25 * (per[z] - 2);
		z++;
	} while (z < 10);
	cout << endl;
}
void do3() {
	cout << endl;
	int s=0,x=0;                                 //���������� ����������
	do {                                         //���� do while 
		if (x < yrr[s])                          // ������������� if
			x = yrr[s];
		s++;
	} while(s<10);
	cout << "��������";                          //����� ������ � �������
	cout << x<<endl;

	int c = 0, q =x;
	do {                                         //���� do while 
		if (q > yrr[c])                          //������������� if
			q = yrr[c];
		c++;
	} while (c<10);
	cout << " �������" ;                         //����� ������ � �������
	cout << q <<endl;
	cout << " ��������";                         //����� ������ � �������
	cout << endl;
	int si = 0, xi = 0;
	do {                                         //���� do while 
		if (xi <per[si])                         // ������������� if
			xi = per[si];
		si++;
	} while (si<10);
	cout << "��������";                          //����� ������ � �������
	cout << xi << endl;
    int ci = 0, qi = xi;                         //���������� ����������
	do {                                         //���� do while 
		if (qi >per[ci])                         // ������������� if
			qi = per[ci];
		ci++;
	} while (ci<10);
	cout << " �������";                          //����� ������ � �������
	cout << qi << endl;
}
void zap() {
	char name[] = "perem.txt";
	fstream fs(name, ios::app);
	int a = 0;                                   //���������� ����������
	do {                                         //���� do while 
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

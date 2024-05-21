#include<iostream>
using namespace std;
const int n = 10;
int *x = new int[n]{
	1000, 500, 200, 100, 500, 20, 10, 5, 2, 1
};

int A1(int m, int x[]){
	int p = 0; // dem so luong to tien
	for(int i = 0; i < n; i++){
		p += m / x[i];
		m = m % x[i];
	}
	return p;
}
int main(){
//	int m;
//	cout << "Nhap so tien can doi: ";
//	cin >> m;
//	cout << A1(m, x);
	cout << (int)(5/3.5);
	return 0;
}

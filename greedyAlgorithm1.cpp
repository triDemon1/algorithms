#include<iostream>
using namespace std;
const int n = 9;
// so luong chai rong co dung tich khac nhau
double *x = new double[n]{
	20, 15, 10, 5, 3.5, 2, 1.5, 1, 0.5
};
int A2(double d, double x[]){
	int q = 0; // dem so luong chai duoc do day nuoc
	for(int i = 0; i < n; i++){
		q += (int)(d / x[i]);
		cout << q << endl;
		d = d % q;
		cout << d << endl;
	}
	return q;
}
int main(){
	double d;
	cout << "Nhap so luong nuoc can doi: ";
	cin >> d;
	cout << A2(d, x);
	return 0;
}

#include<iostream>
#include<iomanip>
using namespace std;
string L[10] = {"Tri", "Trung", "Khanh", "Manh", "Hoan", "My"};
int count = 0;
void swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}
struct CONGVIEC{
	string maCV;
	double thoiGianBD;
	double thoiGianCan;
	void xuat(){
		cout << setw(15) << maCV;
		cout << setw(15) << thoiGianBD;
		cout << setw(15) << thoiGianCan << endl;
	}
};
void A1(CONGVIEC works[], int n){
	if(n < 0) return;
	works[n].xuat();
	A1(works, n-1);
}
int A2(CONGVIEC works[], int l, int r){
	if(l == r && works[l].thoiGianCan >= 0.5) return 1;
	else if(l == r) return 0;
	int m = (l+r) / 2;
	int left = A2(works, l, m);
	int right = A2(works, m + 1, r);
	
	return left + right;
}
void view_config(CONGVIEC works[], string L[], int x[], int n){
	for(int i = 1; i <= n; i++){
		cout << L[i-1] << "-" << works[x[i] - 1].maCV << "\t";
	}
	cout << endl;
}
void next_config(int x[], int n, int i){
	int k = n;
	while(x[k] < x[i]){
		k--;
	}
	swap(x[i], x[k]);
	int j = n;
	i++;
	while(i < j){
		swap(x[i], x[j]);
		i++;
		j--;
	}
}
void A3(CONGVIEC works[], int n){
	int i;
	int *x = new int [n+1];
	for(int i = 1; i <= n; i++){
		x[i] = i;
	}
	do{
		count++;
		view_config(works, L, x, n);
		i = n - 1;
		while(i > 0 && x[i] > x[i+1]){
			i--;
		}
		if(i > 0){
			next_config(x, n, i);
		}
	}while(i > 0);
}
int main(){
	int n = 6;
	CONGVIEC *works = new CONGVIEC[n]{
		{"CV001", 12, 0.5},
		{"CV002", 6, 0.3},
		{"CV003", 13, 1},
		{"CV004", 15, 2},
		{"CV005", 9, 2.5},
		{"CV006", 10, 1.5},
	};
	A1(works, n-1);
	cout << A2(works, 0, n - 1);
//	A3(works, n);
//	cout << count;
	return 0;
}

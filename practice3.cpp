#include<iostream>
#include<iomanip>
using namespace std;
int countA3 = 0;
struct FLIGHT{
	string soHieu;
	double giaVe;
	int soChoNgoi;
	void xuat(){
		cout << setw(15) << soHieu;
		cout << setw(15) << giaVe;
		cout << setw(15) << soChoNgoi<< endl;
	}
};

void A1(FLIGHT planes[], int n, int index){
	if(n == index) return;
	if(planes[index].giaVe > 700000){
		planes[index].xuat();
	}
	A1(planes, n, index+1);
}
FLIGHT A2(FLIGHT planes[], int l, int r){
	if(l == r) return planes[l];
	else{
		int m = (l + r) / 2;
		FLIGHT min_left = A2(planes, l, m);
		FLIGHT min_right = A2(planes, m + 1, r);
		if(min_left.giaVe < min_right.giaVe){
			return min_left;
		}
		else{
			return min_right;
		}
	}
}
void viewA3(FLIGHT planes[], int x[], int k){
//	cout << setw(15) << "MA SO";
//	cout << setw(15) << "SO CHO NGOI";
	for(int i = 1; i <= k; i++){
		cout << planes[x[i] - 1].soHieu << " ";
		cout << planes[x[i] - 1].soChoNgoi;
		cout << " - ";
	}
	cout << endl;
}
int x[4] = {0};
void A3(FLIGHT planes[], int i, int n, int k){
	for(int j = x[i - 1] + 1; j <= n - k + i; j++){
		x[i] = j;
		if(i == k){
			countA3++;
			viewA3(planes, x, k);
		}
		else{
			A3(planes, i + 1, n, k);
		}
	}
}
int main(){
	int n = 6;
	FLIGHT *planes = new FLIGHT[n] {
		{"VN001", 800000, 300},
		{"VN002", 400000, 200},
		{"VN003", 600000, 250},
		{"VN004", 900000, 350},
		{"VN005", 500000, 300},
		{"VN006", 700000, 320},
	};
	A1(planes, n, 0);
	FLIGHT min_flight = A2(planes, 0, n - 1);
	cout << "CHUYEN BAY CO GIA VE THAP NHAT LA: " << endl;
	min_flight.xuat();
	cout << "==========CACH CHON 4 CHUYEN BAY TRONG 6 CHUYEN BAY=========" << endl;
	A3(planes, 1, n, 4);
	cout << countA3 << " cach chon 4 chuyen bay trong 6 chuyen bay";
	return 0;
}

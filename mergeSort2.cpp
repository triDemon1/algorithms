#include<iostream>
#include<stdio.h>
#include<string.h>
#include<iomanip>
using namespace std;
struct XETAI{
	int bienSo;
	float taiTrong;
};

// tim xe co tai trong lon nhat = chia de tri
float findMax(XETAI trucks[], int l, int r){
	if(l == r){
		return trucks[l].taiTrong;
	}
	else{
		int m = (l+r)/2;
		float left_Max = findMax(trucks, l, m);
		float right_Max = findMax(trucks, m + 1, r);
		if(left_Max > right_Max){
			return left_Max;
		}
		else{
			return right_Max;
		}
	}
}

// sap xep tang dan bang thuat toan tron
void mergeTrucks(XETAI trucks[], int l, int m, int r){
	int n1 = m - l + 1;
	int n2 = r - m;
	
	// chia mang thanh 2 mang con
	XETAI Left[n1];
	XETAI Right[n2];
	for(int i = 0; i < n1; i++){
		Left[i] = trucks[l + i];
	}
	for(int j = 0; j < n2; j++){
		Right[j] = trucks[m + 1 + j];
	}
	// sap xep va gan vao danh sach ban dau
	int i = 0, j = 0;
	while( i < n1 && j < n2){
		if(Left[i].taiTrong < Right[j].taiTrong){
			trucks[l] = Left[i];
			i++;
		}
		else{
			trucks[l] = Right[j];
			j++;
		}
		l++;
	}
	while(i < n1){
		trucks[l] = Left[i];
		i++;
		l++;
	}
	while(j < n2){
		trucks[l] = Right[j];
		j++;
		l++;
	}
//	delete[] Left;
//	delete[] Right;
}
// dung chia de tri sau do dung ham mergeTrucks de tron
void mergeSort(XETAI trucks[], int l, int r){
	if(l >= r) return;
	else{
		int m = (l+r)/2;
		mergeSort(trucks, l, m);
		mergeSort(trucks, m + 1, r);
		mergeTrucks(trucks, l , m , r);
	}
}

// tim vi tri chen
int tim_vi_tri(XETAI trucks[], int n, XETAI &xe_moi){
	for(int i = 0; i < n; i++){
		if(trucks[i].taiTrong >= xe_moi.taiTrong){
			return i;
		}
	}
	return n;
}
int main(){
	int n = 7;
	XETAI *trucks = new XETAI[n] {
		{1, 5},
		{2, 6},
		{3, 4.5},
		{4, 7},
		{5, 5.5},
		{6, 4.8},
		{7, 6.5},
	};
	// xe co tai trong lon nhat !
	int max  = findMax(trucks, 0, 6);
	cout << "Xe co tai trong lon nhat la: " << max << endl;
	
	// sap xep danh sach xe theo tai trong tang dan
	mergeSort(trucks, 0, 6);
	cout << "BIEN SO ";
	cout << setw(15) << "TAI TRONG" << endl;
	for(int i = 0; i < 7; i++){
		cout << trucks[i].bienSo;
		cout << setw(15) << trucks[i].taiTrong << endl;
	}
	XETAI x({1, 10.6});
	int vt = tim_vi_tri(trucks, 7, x);
	cout << "Vi tri de chen xe tai moi: " << vt;
	delete[] trucks;
	return 0;
}

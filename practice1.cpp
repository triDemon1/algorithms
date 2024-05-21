#include<iostream>
#include<iomanip>
using namespace std;
const int n = 8;
// khoi tao danh sach bien so tu 1 -> n
int x[n + 1] = {1, 2, 3, 4, 5, 6, 7, 8};
int countBackTracking = 0;
struct APARTMENT{
	string tenChu;
	double dienTich;
	int soPhongNgu;
	void xuat(){
		cout << setw(15) << tenChu;
		cout << setw(15) << dienTich;
		cout << setw(15) << soPhongNgu << endl;
	}
};
void deQuy(APARTMENT rooms[], int n, int index){
	if(index == n) return;
	else{
		rooms[index].xuat();
		deQuy(rooms, n, index + 1);
	}
}
int chiaDeTri(APARTMENT rooms[], int l, int r){
	if(l == r && (rooms[l].dienTich >= 100 && rooms[l].dienTich <= 120)){
		return 1;
	}
	else if(l == r && (rooms[l].dienTich <= 100 || rooms[l].dienTich >= 120)){
		return 0;
	}
	else{
		int m = (l+r) / 2;
		int count_left = chiaDeTri(rooms, l , m);
		int count_right = chiaDeTri(rooms, m + 1, r);
		return count_left + count_right;
	}
}
void view_config(APARTMENT rooms[]){
	for(int i = 1; i <= n; i++){
		cout << rooms[i-1].tenChu << " - " << x[i]<< " ";
	}
	cout << endl;
}
int used[n] = {0};
int backTracking(APARTMENT rooms[], int i){
	for(int j = 1; j <= n; j++){
		if(used[j] == 0){
			x[i] = j;
			used[j] = 1;
			if(i == n){
				countBackTracking++;
				view_config(rooms);
			}
			else{
				backTracking(rooms, i+1);
			}
			used[j] = 0;
		}
	}
	return countBackTracking;
}
int main(){
	APARTMENT *rooms = new APARTMENT[n]{
		{"Tri", 50.5, 2},
		{"Trung", 60.5, 3},
		{"Khanh", 55.5, 2},
		{"Hong Anh", 100.5, 5},
		{"Manh", 65.5, 4},
		{"My", 45.5, 1},
		{"Long", 145.5, 4},
		{"Hoan", 65.5, 3},
	};
//	cout << "========= THONG TIN VE CAC CAN HO =========" << endl;
//	cout << setw(15) << "TEN CHU HO";
//	cout << setw(15) << "DIEN TICH";
//	cout << setw(15) << "SO PHONG NGU" << endl;
//	deQuy(rooms, n, 0);
//	cout << chiaDeTri(rooms, 0, n - 1);
	cout << "========= CAC PHUONG AN =========" << endl;
	cout << backTracking(rooms, 1);
	return 0;
} 

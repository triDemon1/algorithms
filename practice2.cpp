#include<iostream>
#include<iomanip>
using namespace std;
struct WORKS{
	string maCV;
	double startTime;
	double endTime;
	void outPut(){
		cout << setw(15) << maCV;
		cout << setw(15) << startTime;
		cout << setw(15) << endTime << endl;
	}
	void outPut2(){
		cout << setw(15) << maCV;
		cout << setw(15) << endTime - startTime << endl;
	}
};
const int n = 6;
const int k = 5;
WORKS *congViec = new WORKS[n+1]{
	{"CV1", 2, 5.30},
	{"CV2", 8.30, 12},
	{"CV3", 1, 3.30},
	{"CV4", 9, 10.30},
	{"CV5", 0, 2.30},
	{"CV6", 3, 4.30},
};
string N[n+1] = {"tri", "trung", "khanh", "nam", "manh", "my"};
// in danh sach cong viec
void recursive(WORKS congViec[], int n, int i){
	if( i == n) return;
	congViec[i].outPut();
	recursive(congViec, n, i + 1);
}
double tinhTong(WORKS congViec[], int n, int i){
	if(i == n) return 0;
	else{
		return congViec[i].startTime + tinhTong(congViec, n, i + 1);
	}
}
// in ra thong tin cong viec co excuteTime = endTime - startTime < 5
// ap dung thuat toan chia de tri
void divideAndConquer(WORKS congViec[], int l, int r){
	if(l == r && congViec[l].endTime < 5) congViec[l].outPut2();
	else if(l == r) return;
	else{
		int m = (l+r) / 2;
		divideAndConquer(congViec, l, m);
		divideAndConquer(congViec, m + 1, r);
	} 
}
// sap xep thoi gian bat dau tang dan
// thuat toan chia de tri
void merge(WORKS congViec[], int l, int m, int r){
	int n1 = m - l + 1;
	int n2 = r - m;
	WORKS left[n1];
	WORKS right[n2];
	for(int i = 0; i < n1; i++){
		left[i] = congViec[l+i];
	}
	for(int j = 0; j < n2; j++){
		right[j] = congViec[m + 1 + j];
	}
	int i = 0, j = 0;
	while( i < n1 && j < n2){
		if(left[i].startTime < right[j].startTime){
			congViec[l] = left[i];
			i++;
		}
		else{
			congViec[l] = right[j];
			j++;
		}
		l++;
	}
	while( i < n1){
		congViec[l] = left[i];
		i++;
		l++;
	}
	while( j < n2){
		congViec[l] = right[j];
		j++;
		l++;
	}
}
void mergeSort(WORKS congViec[], int l, int r){
	if(l >= r) return;
	int m = (l+r)/2;
	mergeSort(congViec, l, m);
	mergeSort(congViec, m + 1, r);
	merge(congViec, l, m, r);
}
// in ra cach chon 5 trong 6 cong viec ung voi thoi gian ket thuc cua cong viec day
// su dung phuong phap sinh
int x[n+1] = {0};
void view_config(WORKS congViec[]){
	for(int i = 1; i <= n; i++){
		cout << N[i - 1] << " - " << congViec[x[i] - 1].maCV << "  ";
	}
	cout << endl;
}
void swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}
void next_config(int x[], int i){
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
// hoan vi n
int count = 0;
void lists_config(WORKS congViec[], int n){
	int i;
	for(i = 1; i <= n; i++){
		x[i] = i;
	}
	do{
		count++;
		view_config(congViec);
		i = n - 1;
		while(i > 0 && x[i] > x[i+1]){
			i--;
		}
		if( i > 0){
			next_config(x, i);
		}
	}while(i > 0);
}
// su dung phuong backtracking
int used[n+1] = {0};
void backTracking(int i){
	for(int j = 1; j <= n; j++){
		if(used[j] == 0){
			used[j] = 1;
			x[i] = j;
			if(i == n){
				count++;
				view_config(congViec);
			}
			else{
				backTracking(i+1);
			}
			used[j] = 0;
		}
	}
}
int main(){
	cout << setw(15) << "MA CV";
	cout << setw(15) << "START TIME";
	cout << setw(15) << "END TIME" << endl;
	recursive(congViec, n, 0);
	cout << tinhTong(congViec, n, 0);
//	cout << "==========CAC CONG VIEC CO END TIME < 5=========" << endl;
//	cout << setw(15) << "MA CV";
//	cout << setw(15) << "EXECUTE TIME" << endl;
//	divideAndConquer(congViec, 0, n - 1);
//	cout << "\n\n\t\t==========CACH HOAN VI 6 CONG VIEC==========\t\t\n\n";
//	lists_config(congViec, n);
//	backTracking(1);
//	cout << count;
//	cout << "\n\n\t\t==========DANH SACH SAU KHI SAP XEP=========\n\n\t\t" << endl;
//	mergeSort(congViec, 0, n - 1);
//	recursive(congViec, n, 0);
	return 0;
}


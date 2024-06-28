#include<iostream>
#include<iomanip>
using namespace std;
const int n = 6;
struct PHONE{
	string brand;
	int size;
	int price;
	void output(){
		cout << setw(15) << brand;
		cout << setw(15) << size;
		cout << setw(15) << price << endl;
	}
};
PHONE *phones = new PHONE[n+1]{
	{"BRAND A", 8, 15},
	{"BRAND B", 1, 25},
	{"BRAND C", 3, 12},
	{"BRAND D", 5, 17},
	{"BRAND E", 4, 27},
	{"BRAND F", 2, 15},
};
void Q1(PHONE d[], PHONE a[], int n, int s, int &x){
	int dp[n+1][s+1];
	for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= s; ++j) {
            dp[i][j] = 0;
        }
    }
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= s; j++){
			dp[i][j] = dp[i-1][j];
			if(j >= d[i - 1].size){
				dp[i][j] = max(dp[i][j], dp[i-1][j - d[i - 1].size] + d[i - 1].price);
			}
		}
	}
	for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= s; ++j) {
            cout << dp[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
	int maxPrice = dp[n][s];
	x = 0;
	int remainSize = s;
	for(int i = n; i > 0 && maxPrice > 0; i--){ // n = 4; 
		if(maxPrice != dp[i - 1][remainSize]){ // dp[2][3];
			a[x] = d[i-1]; //
			x++;
			maxPrice -= d[i-1].price;
			remainSize -= d[i-1].size;
		}
	}
	
}
int main(){
	PHONE result[n];
	int s = 12;
	int x;
	Q1(phones, result, n, s, x);
	cout << "So luong chiec dien thoai da lay: " << x << endl;
	for(int i = 0; i < x; i++){
		result[i].output();
	}
	return 0;
}

#include<iostream>
#include<string>
using namespace std;
void generate_k(int x[], int n, int k){
	// cau hinh dau tien
	for(int i = 1; i <= k; i++){
		x[i] = i;
	}
	// sinh ra cau hinh ke tiep
	int i;
	do{
		for(int i = 1; i <= k; i++){
			cout << x[i] << " ";
		}
		cout << endl;
		i = k;
		while(i > 0 && x[i] == n - k + i){
			i--;
		}
		if( i > 0) {
			x[i]++;
			i++;
			while(i <= k){
				x[i] = x[i-1] + 1;
				i++;
			}
		}
	}while(i > 0);
}
int main(){
	int n = 6;
	int k = 4;
	int *x = new int[n];
	generate_k(x, n, k);
	delete[] x;
	return 0;
}

#include<iostream>
using namespace std;
int count = 0;
void swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}
void view_config(int x[], int n){
	for(int i = 1; i <= n; i++){
		cout << x[i] << " ";
	}
	cout << endl;
}
void next_config(int x[], int n, int i){
	// tim x[k] be nhat trong doan cuoi giam dan va lon hon x[i]
	int k = n;
	while(x[k] < x[i]){
		k--;
	}
	// dao gia tri cua x[i] va x[k]
	swap(x[i], x[k]);
	//dao nguoc doan cuoi
	int j = n; i++;
	while( i < j){
		swap(x[i], x[j]);
		i++;
		j--;
	}
}
int listing_configs(int n){
	int i;
	int *x = new int[n+1];
	for(int i = 1; i <= n; i++){
		x[i] = i;
	}
	do{
		count++;
		view_config(x, n);
		i = n - 1;
		while( i > 0 && x[i] > x[i+1]){
			i--;
		}
		if( i > 0){
			next_config(x, n, i);
		}
	}while( i > 0);
	return count;
}
int main(){
	int n = 4;
	cout << listing_configs(n);
	return 0;
}

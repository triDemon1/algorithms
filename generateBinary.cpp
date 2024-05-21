#include<iostream>
using namespace std;
// sinh cau hinh moi tu cau hinh dang co
void next_config(int x[], int n, int i){
	x[i] = 1;
	i++;
	while( i <= n){
		x[i] = 0;
		i++;
	}
}
// hien thi mot cau hinh
void view_config(int x[], int n){
	for(int i = 1; i <= n; i++){
		cout << x[i];
	}
	cout << endl;
}

// liet ke cac cau hinh
void listing_configs(int n){
	int i;
	int x[n+1] = {0};
	do{
		view_config(x, n);
		i = n;
		while( i > 0 && x[i] == 1){
			i--;
		}
		if(i > 0){
			next_config(x, n, i);
		}
	}while( i > 0);
}
int main(){
	int n = 3;
	listing_configs(n);
}

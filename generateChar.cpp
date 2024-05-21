#include<iostream>
#include<string>
using namespace std;
// ham sinh va in ra cac chuoi co do dai n chi chua ky tu 'a' va 'b'
void generate_strings(int n){
	// tao 1 mang de luu cac ky tu chuoi
	char* str = new char[n+1];
	str[n] = '\0'; // dat ky tu ket thuc chuoi
	
	// khoi tao chuoi ban dau la tat ca ky tu 'a'
	for(int i = 0; i < n; i++){
		str[i] = 'a';
	}
	
	// In ra chuoi ban dau
	cout << str << endl;
	
	// lap qua tung chuoi va thay doi ky tu cuoi cung cho
	// den khi tat ca cac ky tu deu la ky tu 'b'
	while(true){
		// tim vi tri ky tu 'a' cuoi cung tu phai -> trai
		int pos = n - 1;
		while(pos >= 0 && str[pos] == 'b'){
			pos--;
		}
		// neu khong tim thay  ky tu 'a', tuc la da dat den chuoi cuoi cung
		// thoat khoi vong lap
		if(pos == -1){
			break;
		}
		
		// thay doi ky tu 'a' thanh 'b' va tat ca ky tu sau no thanh 'a'
		str[pos] = 'b';
		for(int i = pos + 1; i < n; i++){
			str[i] = 'a';
		}
		cout << str << endl;
	}
	delete[] str;
}

int main(){
	int n = 3;
	generate_strings(n);
	return 0;
}

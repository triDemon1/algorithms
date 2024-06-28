#include<iostream>
using namespace std;
void computeZ(string &s, int z[]){
	int n = s.length();
	int l, r = 0;
	for(int i = 1; i < n; i++){
		if(i > r){
			l = r = i;
			while(r < n && s[r-l] == s[r]){
				r++;
			}
			z[i] = r - l;
			r--;
		}
		else if(z[i - l] < r - i + 1){
			z[i] = z[i - l];
		}
		else{
			l = i;
			while(r < n && s[r-l] == s[r]){
				r++;
			}
			z[i] = r - l;
			r--;
		}
	}
}
int countWord(string &s, string &w){
	string x = w + "$" + s;
	int n = x.length();
	int *z = new int[n+1];
	computeZ(x, z);
	int count = 0;
	for(int i = 0; i < n; i++){
		if(z[i] == w.length()){
			count++;
		}
	}
	delete []z;
	return count;
}
string removeWord(string &s, string &w){
	int pos = s.find(w);
	while(pos >= 0 && pos < s.size()){
		s.erase(pos, w.length());
		if(pos < s.size() && s[pos] == ' '){
			s.erase(pos, 1);
		}
		if(pos > 0 && s[pos - 1] == ' '){
			s.erase(pos - 1, 1);
		}
	}
	return s;
}
int main(){
	string s = "Ban Viet o Viet Nam";
	string w = "Viet";
	cout << countWord(s, w) << endl;
	string x = removeWord(s, w);
	cout << x;
	return 0;
}

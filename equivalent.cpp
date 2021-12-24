#include <bits/stdc++.h>

using namespace std;

vector<char> vect(string a){
	vector<char> v;
	int foo = 0;
	for(int i = 0; i < a.size(); i++){
		if (find(v.begin(), v.end(), a[i]) != v.end())
			foo++;
		else{
			v.push_back(a[i]);
		}
	}
	return v;
}

bool equivalent(string a, string b){
	vector<int> aa;
	vector<int> bb;

	vector<char> aav = vect(a);
	vector<char> bbv = vect(b);

	if 
}


int main(){

	string a, b;

	cin >>a >> b;

	vector<char> vec;
	vector<int> a;

	map<char, int> aa;
	map<char, int> bb;



	for(int i = 0; i < a.size(); i++){
		if (find(vec.begin(), vec.end(), a[i]) == vec.end()){
			vec.push_back(a[i]);
			aa[a[i]] = 0;
			a.push_back(1);
		}
	}

	for(int i = 0; i < a.size(); i++){
		if (find(vec.begin(), vec.end(), a[i]) == vec.end())
	}

	for(int i = 0; i < b.size(); i++){
		if (find(vec.begin(), vec.end(), b[i]) == vec.end())
			vec.push_back(b[i]);
	}



	int b;
	

	
	
}
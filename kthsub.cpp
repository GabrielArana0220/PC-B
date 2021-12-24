#include <bits/stdc++.h>

using namespace std;

vector<pair<string, int>> suffix(string s){
	set<pair<string, int>> suff;

	for(int i  = 0; i < s.size(); i++){
		suff.insert({(s.substr(i, s.size())), i});
	}

	vector<pair<string, int>> suffi;

	for(auto it = suff.begin(); it != suff.end(); it++)
		suffi.push_back(*it);

	return suffi;
}

vector<int> lcp(vector<pair<string, int>> &suffix){
	vector<int> array;
	array.push_back(0);
	for(int i = 1; i < suffix.size(); i++){
		int aux = 0;
		while(suffix[i].first[aux] == suffix[i-1].first[aux]){
			aux++;
		}
		array.push_back(aux);
	}
	return array;
}

int unique(string a){
	vector<pair<string, int>> v;
	v = suffix(a);
	vector<int> array = lcp(v);

	int t = 0;
	for(int i = 0; i < array.size(); i++){
		t += array[i];
	}
	return ((a.size()*(a.size() + 1))/2);
}

string kth(string a, int u){
	vector<pair<string, int>> v;
	v = suffix(a);

	vector<string> array;
	int aux = u;
	int pos = 0;
	
	while(true){
		string au= "";
		int s = 0;
		while(v[pos].first.size() > s){
			au += v[pos].first[s];
			if (find(array.begin(), array.end(), au) != array.end() )
				s++;
			else{
				array.push_back(au);
				s++;
				aux--;
				if (aux == 0)
					return au;
			}
		}
		pos ++;
	}

}

int main(){

	string a;
	int b;
	cin >>a >> b;

	cout << kth(a, b);

	/*
	string a = "babaacbaab";
	vector<pair<string, int>> v;
	v = suffix(a);
	vector<int> array = lcp(v);
	cout << "suffix array:\n";
	for (int i = 0; i < v.size(); i++)
		cout << v[i].first << " \t"<<v[i].second <<endl;
	cout << "\nlcp array\n";
	for (int i = 0; i < array.size(); i++)
		cout << array[i] <<  endl;
	*/
	
}
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
	int nc = a.size()*(a.size() + 1);
	nc /= 2;
	int t = 0;
	for(int i = 0; i < array.size(); i++){
		t += array[i];
	}
	return nc - t;
}

int repeated(string a){
	vector<pair<string, int>> v;
	v = suffix(a);
	vector<int> array = lcp(v);
	int t = 0;
	for(int i = 0; i < array.size(); i++){
		t += array[i];
	}
	return t;
}

int lcp2(vector<pair<string, int>> &suffix){
	vector<int> array;
	array.push_back(0);
	vector<string> auxx;
	for(int i = 1; i < suffix.size(); i++){
		int aux = 0;
		string aux2 = "";
		while(suffix[i].first[aux] == suffix[i-1].first[aux]){
			aux2 += suffix[i].first[aux];
			if (find(auxx.begin(), auxx.end(), aux2) != auxx.end() )
				aux++;
			else{
				auxx.push_back(aux2);
				aux++;
			}
		}
		array.push_back(aux);
	}
	return auxx.size();
}

int main(){

	int cases = 0;
	cin >> cases;
	string a;
	while(cases--){
		cin >> a;
		vector<pair<string, int>> v;
		v = suffix(a);
		cout << lcp2(v) << endl;
	}
	
}
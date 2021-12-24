#include <bits/stdc++.h>

using namespace std;

string sum_string(string a, string b){
	int pointer_a = a.size()-1;
	int pointer_b = b.size()-1;

	string result = "";

	int sobr = 0;
	while(pointer_b > -1 || pointer_a > -1){

		string aux = "";
		
		string aaux = "";
		string baux = "";

		if (pointer_a > -1)
			aaux += a[pointer_a];
		else
			aaux = "0";
		
		if (pointer_b > -1)
			baux += b[pointer_b];
		else
			baux = "0";
		
		aux = to_string(stoi(aaux) + stoi(baux) + sobr);
		//cout << aux << endl;
		//cout << baux << endl;

		if (aux.size() == 1){
			result = aux[0] + result;
			sobr = 0;
		}
		else{
			result = aux[1] + result;
			string sob = "";
			sob += aux[0];
			sobr =  stoi(sob);
		}

		pointer_a --;
		pointer_b --;
	}
	if (sobr != 0){
		result = to_string(sobr) + result;
	}
	return result;
}

/*
string sum_string(string a, string b){
	int pointer_a = a.size()-1;
	int pointer_b = b.size()-1;

	if (pointer_a == 0 && pointer_b == 0)
		return to_string(stoi(a)+stoi(b));

	string result = "";

	int sobr = 0;

	while(pointer_b > -1 || pointer_a > -1){
		if (pointer_a > -1 && pointer_b > -1){
			string aaux = "";
			string baux = "";
			aaux += a[pointer_a];
			baux += b[pointer_b];
			string aux = to_string(stoi(aaux) + stoi(baux) + sobr);
			if (aux.size() == 2){
				string saux = "";
				saux += aux[0];
				sobr = stoi(saux);
				result = aux[1] + result;
			}
			else{
				sobr = 0;
				result = aux[0] + result;
			}
		}
		else if (pointer_b <= -1 && pointer_a > -1){
			if (sobr != 0){
				string aaux = "";
				aaux += a[pointer_a];
				result = to_string(stoi(aaux) + sobr) + result;
				sobr = 0;
			}
			else
				result = a[pointer_a]+result;
		
		}
		else if (pointer_a <= -1 && pointer_b > -1){
			if (sobr != 0){
				string baux = "";
				baux += b[pointer_b];
				result = to_string(stoi(baux)+sobr) + result;
				sobr = 0;
			}
			else
				result = b[pointer_b]+result;
		}
		pointer_b--;
		pointer_a--;
	}
	if (sobr != 0)
		result = to_string(sobr) + result;
	return result;
}
*/
string multi(string a, string b){
	string result = "";
	int count = 0;
	for(int i = 0; i < stoi(b); i++){
		if (result == "")
			result += a;
		else
			result = sum_string(result,a);
		//cout << result << endl;
		
	}
	return result;
}

string factorial(string a){
	string s = "";
	for(int i = 1; i < stoi(a);i++){
		if (s == "")
			s = multi(to_string(i), to_string(i+1));
		else
			s = multi(s, to_string(i+1));
	}
	return s;
}

string resta(string a, string b){
	int pointer_a = a.size()-1;
	int pointer_b = b.size()-1;

	string result = "";

	int sobr = 0;
	while(pointer_b > -1 || pointer_a > -1){

		string aux = "";
		
		string aaux = "";
		string baux = "";

		if (pointer_a > -1){
			aaux += a[pointer_a];
			if (sobr == 1){
				aaux = to_string(stoi(aaux)-1);
				sobr = 0;
			}
		}
		else
			aaux = "0";
		
		if (pointer_b > -1)
			baux += b[pointer_b];
		else
			baux = "0";
		
		if ((stoi(aaux) < stoi(baux))){
			aaux = "1" + aaux;
			sobr = 1;
		}

		aux = to_string(stoi(aaux) - stoi(baux));
		//cout << aux << endl;
		//cout << baux << endl;

		result = aux + result;

		pointer_b--;
		pointer_a--;
	}

	return result;
}

string dividir(string a, string b){

}

int main(){
	string a;
	string b;

	cin >> a >> b;

	cout << resta(a,b);


	//string fact = factorial(to_string(a.size()));
}
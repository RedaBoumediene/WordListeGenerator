/****************************************************************
*			Author	:	Reda BOUMEDIENE 						*
*			E-mail	:	reda.boumediene@gmail.com				*
*			Language:	C++										*
*																*
*		Generate All Possible Password from a set of Word 		*
****************************************************************/
#include<bits/stdc++.h>
using namespace std;
const int N=254;
set <string> s;
set <string> :: iterator its;
int n,mx,mn;
string tab[N];
void WithoutRepetition(int n){
	do{
			for(int m = 1 ; m < (1<<n) ; m++){
				string res = "";
				for(int i = 0 ; i < n ; i++){
					if( (m & (1 << i) ) ){
						res += tab[i] ;
					}
				}
				s.insert(res);
			}
		}while(next_permutation(tab , tab + n));
		for(its = s.begin() ; its != s.end() ; its++)
			cout << *its << endl;
}
void WithRepetition(string s , int count){
	if(count > mx)
		return;
	if(count <= mx && count >= mn){
		cout << s << endl;
	}
	for(int i = 0 ; i < n ; i++){
		WithRepetition(s + tab[i] , count + 1);
	}
}
int main(){
	cout << "How many words ? ";
	cin >> n;
	cout << "Choose "<<n<<" words (or letters) : ";
	for(int i=0 ; i<n ;i++)
		cin >> tab[i] ;
	sort(tab , tab+n);
	cout << "Choose name for the Output FILE : ";
	string f;
	cin >> f;
	f += ".txt";
	const char *file;
	file = f.c_str();
	string choice;
	do{
		cout << "You wanna Wordlist with repetition or not ? (yes or no) ";
		cin >> choice;
	}while(choice != "yes" && choice != "no");
	if(choice == "no"){
		freopen(file , "w" , stdout);
		WithoutRepetition(n);
	}
	else{
		do{
			cout << "Minimum size of the password : ";
			cin >> mn;
			cout << "Maximum size of the password : ";
			cin >> mx;
		}while(mn > mx);
		freopen(file , "w" , stdout);
		WithRepetition("" , 0);
	}
	return 0;
}

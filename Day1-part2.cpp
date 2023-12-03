#include<bits/stdc++.h>
using namespace std;

int check(string s){
	if(s == "one") return 1;
	if(s == "two") return 2;
	if(s == "three") return 3;
	if(s == "four") return 4;
	if(s == "five") return 5;
	if(s == "six") return 6;
	if(s == "seven") return 7;
	if(s == "eight") return 8;
	if(s == "nine") return 9;
	return 0;
}

int num(int index, char a, string s){
	if(a == 'o'){
		if(check(s.substr(index,3))>0) return 1;
	}
	if(a == 't'){
		if(check(s.substr(index,3))>0) return 2;
		if(check(s.substr(index,5))>0) return 3;
	}
	if(a == 'f'){
		if(check(s.substr(index,4))>0) return check(s.substr(index,4));
	}
	if(a == 's'){
		if(check(s.substr(index,3))>0) return check(s.substr(index,3));
		if(check(s.substr(index,5))>0) return check(s.substr(index,5));
	}
	if(a == 'e'){
		if(check(s.substr(index,5))>0) return 8;
	}
	if(a == 'n'){
		if(check(s.substr(index,4))>0) return 9;
	}
	return 0;
}

int main(){
	string input;
	int sum = 0;
	while(getline(cin,input)){
		int h,l;
		string s = input;
		int n = s.length();
		//cout<<"n : "<<n<<endl;
		int low = 0, high = n-1;
		int loww = 0, highh = 0;
		while(low<=high and (loww==0 or highh==0)){
			if(isdigit(s[low])){
				l = s[low] - '0';
				//cout<<"L :"<<l<<endl;
				loww = 1;
			}
			else if(num(low,s[low],s)>0){
				l = num(low,s[low],s);
				//cout<<"L :"<<l<<endl;
				loww = 1;
			}
			else if(loww==0) {
				low++;
				//cout<<"low :"<<low<<endl;
			}
			if(isdigit(s[high])){
				h = s[high] - '0';
				//cout<<"H : "<<h<<endl;
				highh = 1;
			}
			else if(num(high,s[high],s)>0){
				h = num(high,s[high],s);
				//cout<<"H : "<<h<<endl;
				highh = 1;
			}
			else if(highh == 0) {
				high--;
				//cout<<"high :"<<high<<endl;
			}
		}
		int num = l*10 + h;
		//cout<<num<<endl;
		sum+=num;
	}
	cout<<"sum "<<sum;
}

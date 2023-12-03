#include<bits/stdc++.h>
using namespace std;

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
			else if(loww==0) {
				low++;
				//cout<<"low :"<<low<<endl;
			}
			if(isdigit(s[high])){
				h = s[high] - '0';
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

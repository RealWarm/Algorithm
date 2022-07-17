// http://blog.naver.com/PostView.nhn?blogId=sharonichoya&logNo=220513886595
// 길이는 적어도 6이상
// 1개 이상의 숫자.
// 1개 이상의 소문자.
// 1개 이상의 대문자.
// 1개 이상의 특수문자.
// 추가해야하는 문자 갯수의 최솟값을 찾아라.
// Strong Password
#include <bits/stdc++.h>
#include <cctype> 
using namespace std;

int minimumNumber(int sz, string pw) {
    // Return the minimum number of characters 
	// to make the password strong
	int dgnum=0;
	int lch=0;
	int uch=0;
	int sch=0;
	int leng=sz;
	
	for(int i=0; i<pw.size(); i++){
		if(isupper(pw[i])){
			uch++;
		}else if(islower(pw[i])){
			lch++;
		}else if(isdigit(pw[i])){
			dgnum++;
		}else{
			sch++;
		}//if
	}//for-i
	
	if(dgnum==0){
		dgnum++;
		leng++;
	}
	if(lch==0){
		lch++;
		leng++;
	}
	if(uch==0){
		uch++;
		leng++;
	}
	if(sch==0){
		sch++;
		leng++;
	}
	if(dgnum>0 && lch>0 && uch>0 && sch>0 && leng<6){
		leng+=(6-leng);
	}
	
	return (leng-sz);
	
}//minimumNumber

int main(){
	int a;
	string str;	
	cin >> a >> str;
	cout << minimumNumber(a, str);
    return 0;
}//main
















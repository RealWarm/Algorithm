#include<iostream> 
#include<string>
using namespace std;
int n;

string get(int n){
	if (n==1) {
        return (1+"");
    }
    return get(n-1) + n + get(n-1);
}//get

int main(){
	scanf("%d", &n);
	printf("%d", get(n));
	return 0;
}//main

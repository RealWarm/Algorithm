#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
vector<pair<string, vector<string> > > v1;
int n;	//������ �� 

int main() {
	scanf("%d", &n);
	v1.resize(n);
	for (int a = 0; a < n; a++) {
		int tnum;
		cin >> v1[a].first >> tnum;		
		for (int b = 0; b < tnum; b++) {
			int flag = 0; //�̹� �����ʴٸ�.
			string tmp; cin >> tmp;
			for (int c = 0; c < v1[a].second.size(); c++) {
				if (v1[a].second[c] == tmp) {
					//�̹� �Ȱ��� ������ �ִٸ�.
					flag = 1;
					break;
				}//if
			}//for-c

			if (flag == 0) {
				//������ ���ٸ�
				v1[a].second.push_back(tmp);
			}else if (flag == 1) {
				continue;
			}//if
		}//for-b		
	}//for-a
	
	sort(v1.begin(), v1.end());//�̰�!!! 
	int inx = -987987;
	int mmax = 0;
	for (int i = 0; i < n; i++) {
		if (mmax <= v1[i].second.size()) {
			inx = i;
			mmax = v1[i].second.size();
		}//if
	}//for-i
//	printf("\n\n\n");
//	for (int i = 0; i < n; i++) {
//		cout << v1[i].first << " " << v1[i].second.size() << endl;
//	}//for-i
//	printf("\n\n+++++");
	cout << v1[inx].first;

	

	return 0;
}//main

//cin >> v1[a].second[b];

//cout << "+++++++" << v1[a].first << " " << tnum << " ";
//for (int i = 0; i < tnum; i++) {
//	cout << v1[a].second[i] << " ";
//}//for-i
//printf("\n");

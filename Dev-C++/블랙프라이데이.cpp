�ʱ�ȭ
>> �Է�
>> ������� � ���忡 ������ ���Ѵ�(��� ch�迭) 
>> ������ ������ ��������� �Ÿ��� ���Ѵ�.
>> �ɾ��(�ð��� 1�� �帥��) >> for(time++)
>> ��� ����� ���Ͽ� üũ�Ѵ� >> for(a= 0~v3.size())




#include<iostream>
#include<cstring>
#include<cmath>
#include<vector>
#include<string>
using namespace std;
struct store {
	int pnum;	// �����ο� :: p
	int ltime;	// ���ѽð� :: s
	int x, y;	// ������ ��ǥ
	int npnum;	// ���� ���忡 ����� �ִ�?
};
struct pp {
	int x, y;		// ����� ��ġ
	int dis = 0;	// ������� �Ÿ�
	int is = 0;		// �� ���� ���忡 �ִ�?
	int stime = 0;	// ���忡�� �󸶳� �־���?		
	int st = 0;		// ������ ��� ���ƴ�?
};
int n, m, k;		// ����, ����, �����
vector<store>	v1;	// �������� ����
vector<pp>	v2, v3;	// ����� ������ �����ϴ� ����
vector<string> grp;	// �׷��� ����
int ch[10]; // ��ȭ�� ������ ��� �������� ������ >> ����Լ���
int r;		// ����� ��
int mmin = 987987987;

// ������ �ִٸ� �����ϵ��ؿ�
int go() {
	// ��� ������ �����ϸ� �ش� ����� st(flag����)�� 1�� �������� 
	// ������ �Ѽ� ���ϱ� ���� ���͸� �����Ѵ�.
	v3 = v2;	
	int stnum = 0;	// ������ ����ģ �ο����� ��
	int time = 1;	// �귯�� �ð�
	for (; ; ++time) {
		//�ð��� 1�ʾ� ������Ų��.		
		for (int a = 0; a < v3.size(); a++) {
			//����� ���ϰ�			
			if (v3[a].is == 1 && v3[a].st == 0) {
				//�̹� ���忡 �ְ� ������ ��ġ�� �ʾҴٸ�.
				v3[a].stime++;//���忡�� �ִ� �ð��� ������Ų��.
				if (v1[ch[a]].ltime <= v3[a].stime) {
					// ������ ���ѽð� <= �����ѽð�
					// ���νð��� �� ä���ٸ�
					v1[ch[a]].npnum--;	// ������ ���ο��� �Ѹ� ���δ�		
					v3[a].st = 1;		// �� ����� ������ ����ٰ� �����Ѵ�.
					stnum++;			// ������ ��ģ �ο��� ���� ������Ų��.
				}//if
			}else if (v3[a].is == 0 && v3[a].dis <= time) {
				//���忡 ���� �ʰ� && ����� ���忡 �����ߴٸ�				
				if (v1[ch[a]].pnum > v1[ch[a]].npnum) {
					//���� ���忡 ����� ��� �� �� �ִٸ�.
					v3[a].is = 1;		// �ش� ����� ���忡 �ִٰ� ǥ���Ѵ�.
					v3[a].stime++;		// �ش� ����� ���忡���� �ð��� 1���� ��Ų��.
					v1[ch[a]].npnum++;	// ������ ����� ���� 1���� ��Ų��.
				}//if-2
			}//if-1
		}//for-a

		if (stnum == r) break; //
	}//for-time

	return time+1; //!!!!!!!!!!���⸦ �� +1 �ؾ�����...?
}//go

void get(int x) {
	//������� ��� ���忡 ������ ���Ѵ�.
	if (x >= r) {
		for (int i = 0; i < r; i++) {
			//������ ��������� �Ÿ��� ���Ѵ�.
			v2[i].dis = abs(v1[ch[i]].x - v2[i].x) + abs(v1[ch[i]].y - v2[i].y);
		}//for-i
		//for (int i = 0; i < r; i++) {
		//	printf("%d��° ����� ������ store�� %d �̰� �������� �Ÿ��� %d �Դϴ�.\n",
		//		i, ch[i], v2[i].dis);
		//}//for-i
		//printf("==================================================================================\n");
		int result = go();
		if (mmin > result) {
			mmin = result;
		}//if
	}else {
		//������ ��ȣ�� 0������ k-1���� �̴�.
		for (int i = 0; i < k; i++) {
			ch[x] = i;
			get(x + 1);
		}//for-i
	}//if
}//get


int main() {
	int ts; scanf("%d", &ts);
	for (int tt = 1; tt <= ts; tt++) {				
		v1.clear();
		v2.clear();
		grp.clear();
		mmin = 987987987;
		memset(ch, -1, sizeof(ch));
		///////////////////////////////////////////////////////////////////////
		scanf("%d %d %d", &n, &m, &k);
		v1.resize(k);//������ ���� ���� �迭 ������
		for (int i = 0; i < k; i++) {
			scanf("%d %d", &v1[i].pnum, &v1[i].ltime);
		}//for-i
		grp.resize(n);
		for (int i = 0; i < n; i++) {
			cin >> grp[i];
		}//for-i
		///////////////////////////////////////////////////////////////////////
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (grp[i][j] <= 'Z' && grp[i][j] >= 'A') {
					v1[grp[i][j] - 'A'].x = i; //����
					v1[grp[i][j] - 'A'].y = j; //����
				}else if (grp[i][j] == '1') {
					pp temp;
					temp.x = i;
					temp.y = j;
					v2.push_back(temp);
				}//if
			}//for-j
		}//for-i		
		r = v2.size(); // ����� �� ��ŭ r�� for���� �ϰڴ�.
		if (r == 0) {
			//������ ���о��!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
			printf("#%d 0\n", tt);
			continue;
		}//if
		get(0);
		///////////////////////////////////////////////////////////////////////
		printf("#%d %d\n", tt, mmin);
	}//for-tt
	return 0;
}//main

//�Էµ� ����� ������ ��ǥ, �����ο�, ���ѽð� üũ
//printf("\n\n");
//printf("%d %d %d\n", n, m, k);
//for (int i = 0; i < k; i++) {
//	printf("%c :: %d %d %d %d\n",
//		i + 'A', v1[i].pnum, v1[i].ltime, v1[i].x, v1[i].y);
//}//for-i
//for (int i = 0; i < n; i++) {
//	cout << grp[i] << endl;
//}//for-i

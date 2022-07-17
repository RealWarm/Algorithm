# include <stdio.h>
int sorted[100010]; // �߰����� ������ �ʿ�

// i: ���ĵ� ���� ����Ʈ�� ���� �ε���
// j: ���ĵ� ������ ����Ʈ�� ���� �ε���
// k: ���ĵ� ����Ʈ�� ���� �ε���
/* 2���� ������ �迭 list[left...mid]�� list[mid+1...right]�� �պ� ���� */
/* (������ ���ڵ��� ���ĵǴ� ����) */
void merge(int list[], int left, int mid, int right){
  int i, j, k, l;
  i = left;
  j = mid+1;
  k = left;

  /* ���� ���ĵ� list�� �պ� */
  while(i<=mid && j<=right){
    if(list[i]<=list[j])
      sorted[k++] = list[i++];
    else
      sorted[k++] = list[j++];
  }

  // ���� �ִ� ������ �ϰ� ����
  if(i>mid){
    for(l=j; l<=right; l++)
      sorted[k++] = list[l];
  }
  // ���� �ִ� ������ �ϰ� ����
  else{
    for(l=i; l<=mid; l++)
      sorted[k++] = list[l];
  }

  // �迭 sorted[](�ӽ� �迭)�� ����Ʈ�� �迭 list[]�� �纹��
  for(l=left; l<=right; l++){
    list[l] = sorted[l];
  }
}

// �պ� ����
void merge_sort(int list[], int left, int right){
  int mid;

  if(left<right){
    mid = (left+right)/2; // �߰� ��ġ�� ����Ͽ� ����Ʈ�� �յ� ���� -����(Divide)
    merge_sort(list, left, mid); // ���� �κ� ����Ʈ ���� -����(Conquer)
    merge_sort(list, mid+1, right); // ���� �κ� ����Ʈ ���� -����(Conquer)
    merge(list, left, mid, right); // ���ĵ� 2���� �κ� �迭�� �պ��ϴ� ���� -����(Combine)
  }
}

int main(){
 	int n,i;
    int list[100010];   
    scanf("%d",&n);

	for(i = 0 ; i < n ; i++)
		 scanf("%d", &list[i]);

  // �պ� ���� ����(left: �迭�� ���� = 0, right: �迭�� �� = 7)
  merge_sort(list, 0, n-1);

  // ���� ��� ���
  for(i=0; i<n; i++){
    printf("%d ", list[i]);
  }
  return 0;
}

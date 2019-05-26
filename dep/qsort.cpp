/**
 * 1.中间位置上，其上面的值也要调整，使得左边大，右边小。
 * 2. 而非中间位置值不变，左边比其大，右边比其小。一是位置不够，二是快排这样不是最优 
 * ERROR 本题：1 2 3 3 2 1
 */
#include<iostream>
using namespace std;
void swap(int *a, int *b);
void qsort_me(int *data, int start, int end){
	if(start >= end) {
		return;
	}
	int mid = start + (end - start) / 2;
        for(int i =start,j = end; i < j ; i++,j--) {	
		while(j > i && data[i] < data[mid]) {i++;};
		swap(data[i], data[mid]);
		while(j > i && data[j] > data[mid]) {j--;};
		swap(data[j], data[mid]);
	}
	qsort_me(data, start, mid);
	qsort_me(data, mid+1, end);
}

void swap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}



int main() {
	int data[300];
	int ch=0, len=0;
	while(cin>>ch) {
		data[len++]=ch;
	}
	cout<<"output"<<endl;
	qsort_me(data, 0, len-1);
	for (int i = 0; i < len; i++) {
		cout<<data[i]<<endl;
	}
	return 0;
}


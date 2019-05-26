#include<iostream>
using namespace std;
/*
 * 真是两种不同的策略：
 * 传统：给定分区点，左右交换(直觉告诉我这种更好，减少不必要交换)
 * 这种：选择pivot，来找到分区点
 */
int partition(int * data, int start, int end);

void qsort_me_c(int * data, int start, int end) {
	if (start >= end) return;
	int p = partition(data, start, end);
	qsort_me_c(data, start, p - 1);
	qsort_me_c(data, p + 1, end);
}

void qsort_me(int * data, int len) {
	qsort_me_c(data, 0, len-1);
}
int partition(int * data, int start, int end) {
	int pivot = data[end];
	int i = start;
	int j = start;
	for(; j < end; j++) {
		if (data[j] < pivot) {
			int tmp = data[j];
			data[j] = data[i];
			data[i] = tmp;
			i++;
		}
	}

	int tmp = data[i];
	data[i] = pivot;
	data[end] = tmp;
	return i;
}






int main() {
	int data[300];
	int dtmp[300];
	int ch=0, len=0;
	while(cin>>ch) {
		data[len++]=ch;
	}
	cout<<"output"<<endl;
	qsort_me(data, len);
	for (int i = 0; i < len; i++) {
		cout<<data[i]<<endl;
	}
	return 0;
}


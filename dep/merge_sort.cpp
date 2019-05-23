/**
 * 1. 通识：mid 要用减法，而不可用加法，防止溢出
 * 2. len == 2 不需要额外计算，merge就好了。
 * 3. 合并后，copy回原数组
 */
#include<iostream>
using namespace std;
void merge(int *data, int start, int end, int * dtmp) ;
// TODO using non-recursion
void merge_sort(int *data, int start, int end, int * dtmp) {
	int len = end - start;
	if (len <= 1) {
		return;
	}

	int mid = start +  len / 2;
	merge_sort(data, start, mid, dtmp);
	merge_sort(data, mid, end, dtmp);
	merge(data, start, end, dtmp);
}
void merge(int *data, int start, int end, int * dtmp) {
	int mid = start + (start - end) / 2;
	int idx = start, i = start, j = mid;
	while(i < mid && j < end) {
		if (data[i] < data[j]) {
			dtmp[idx++] = data[i++];
		} else {
			dtmp[idx++] = data[j++];
		}
	}
	while(i < mid) {
		dtmp[idx++] = data[i++];
	}
	while(j < end) {
		dtmp[idx++] = data[j++];
	}

	for(int i = start; i < end; i++) {
		  data[i] = dtmp[i];
	}
}

int main() {
	int data[300];
	int dtmp[300];
	int ch=0, len=0;
	while(cin>>ch) {
		data[len++]=ch;
	}
	cout<<"output"<<endl;
	merge_sort(data, 0, len, dtmp);
	for (int i = 0; i < len; i++) {
		cout<<data[i]<<endl;
	}
	return 0;
}

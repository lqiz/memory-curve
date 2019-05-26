#include<iostream>
using namespace std;
int partation(int *data, int start, int end);
int kth_num(int *data, int start, int end, int k){
	if (start >= end) {
		return 0;
	}
	int p = partation(data, start, end);
	cout<<"p before: "<<p<<endl;
	if (p == k) {
		cout<<"p: "<<p<<endl;
		return data[p];
	}

	if (k < p) {
		return kth_num(data, start, p - 1, k);
	} else {
		return kth_num(data, p + 1, end, k);
	}
}

void swap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int partation(int *data, int start, int end) {
	int privot = data[end];
	int j = start;
	for (int i = j; i < end; i ++) {
		if (data[i] < privot) {
			if(i != j) {
				swap(data[i], data[j]);
			}
			j++;
		}
	}
	swap(data[end], data[j]);
	return j;
}

int main() {
	int data[300];
	int ch=0, len=0, k = 0;
	cin>>k;
	cout<<"k: "<<k<<endl;

	while(cin>>ch) {
		data[len++]=ch;
	}

	int a = kth_num(data, 0, len - 1, k);
	cout<<"result: "<<a<<endl;
	return 0;
}


#include<iostream>
using namespace std;
void insert_sort(int *data, int len) {
	for(int i = 0; i < len; i++) {
		int tmp = data[i];
		for(int j=i+1; j<len; j++) {
			if (tmp > data[j]) {
				data[i] = data[j];
				data[j] = tmp;
				tmp = data[i];
			}
		}
	}
}

int main() {
	int data[300];
	int ch=0, len=0;
	while(cin>>ch) {
		data[len++]=ch;
	}
	cout<<"output"<<endl;
	insert_sort(data, len);
	for (int i = 0; i < len; i++) {
		cout<<data[i]<<endl;
	}
	return 0;
}


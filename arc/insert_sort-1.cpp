#include<iostream>
using namespace std;
// 带哨兵
// 插入是往区间内插入
void insert_sort(int *data, int len){
	for(int i =2; i < len; i++) {
		int j = i;
		data[0] = data[i];
		for(; data[j] > data[0]; j--) {
			  data[j+1]= data[j];
		}
		data[j+1] = data[0];
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


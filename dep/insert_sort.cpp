/**
 * 哨兵：
 * 1 暂时存放待插入的元素
 * 2 防止数组下标越界
 * 注意插入排序是从遍历已排序区间!.
 */
#include<iostream>
using namespace std;
void bubble_sort(int *data, int len) {
	for(int i = 1; i < len; i++){
		int tmp = data[i];
		int j = 0;
		for(j = i - 1; j >= 0; j--) {
			cout<<"data["<<i<<"]: "<<data[i]<<" data["<<j<<"]: "<<data[j]<<endl;
			if (tmp < data[j]) {
				data[j+1] = data[j];
			}else {
				break;
			}
		}
		data[j+1] = tmp;
	}
}
int main() {
	int data[300];
	int ch=0, len=0;
	while(cin>>ch) {
		data[len++]=ch;
	}
	cout<<"output"<<endl;
	bubble_sort(data, len);
	for (int i = 0; i < len; i++) {
		cout<<data[i]<<endl;
	}
	return 0;
}

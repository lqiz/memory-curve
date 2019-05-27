/**
 * 桶事先确定，遍历次数事先确定。貌似和程序输入无关。
 */
#include<iostream>
using namespace std;

void bucket_sort(int *data, int bucket[][10], int k, int len) {
	int buc = 1;
      for(int i = 0; i < k; i ++) {
	      for (int c = 0; c < 10; c++ ) {
		      bucket[c][0] = 0;
	      }
	for(int j = 0; j < len; j ++) {
		int d = data[j];
		int tmp = d / buc ;
		int discs = tmp % 10;
		bucket[discs][0] ++;
		int idx = bucket[discs][0];
		bucket[discs][idx] = d;
		cout<<" discs "<<discs<<" idx "<<idx<<" bucket[discs][idx] "<<idx<<endl;
	}

	//
	int idx = 0;
	for(int j = 0; j < 10; j++) {
		for(int i = 1; i <= bucket[j][0]; i++) {
			data[idx++] = bucket[j][i];
		}
        }

	buc *= 10;
      }
}



int main() {
	int data[300];
	int bucket[10][10];
	int ch=0, len=0;
	while(cin>>ch) {
		data[len++]=ch;
	}
	cout<<"output"<<endl;
	bucket_sort(data, bucket, 3, len);
	for (int i = 0; i < len; i++) {
		cout<<data[i]<<endl;
	}
	return 0;
}


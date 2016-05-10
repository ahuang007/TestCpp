#include<iostream>

#include "Sales_item.h"

using namespace std;
int main()
{
	/*
	//1.2
	cout<<"Enter two numbers"<<endl;
	int v1, v2;
	cin>>v1>>v2;
	cout<<v1<<" + "<<v2<<" = "<<v1+v2<<endl;
	//1.4.1
	int sum = 0, val = 1;
	while(val <= 10){
		sum += val;
		val += 1;
	}
	cout<<"1到10 的总和为： "<<sum<<endl;
	//1.4.2
	sum = 0;
	for(int val = 1; val <= 100; val++){
		sum += val;
	}
	cout<<"1到100的总和为： "<<sum<<endl;
	//1.4.3 
	int lower, upper;
	cin>>v1>>v2;
	if(v1 > v2){
		upper = v1;
		lower = v2;
	} else {
		upper = v2;
		lower = v1;
	}
	sum = 0;
	for(int val = lower; val <= upper; val++){
		sum += val;
	}
	cout<<lower<<"到"<<upper<<"的总和为： "<<sum<<endl;
	sum = 0;
	while(cin>>val){
		if(val == 0)
			break;
		sum += val;
		cout<<"当前输入总和为："<<sum<<endl;
	}
	
	// 1.5.1
	Sales_item book;
	cin>>book;
	cout<<book<<endl;

	//1.5.2
	Sales_item item1, item2;
	cin>>item1>>item2;
	//cout<<item1+item2<<endl;

	//1.5.3
	if(item1.same_isbn(item2)){
		cout<<item1+item2<<endl;
	} else {
		cerr<<"data must refer to same ISBN"<<endl;
	}

	//1.6 
	Sales_item total, trans;
	if(cin>>total){
		while(cin>>trans){
			if(trans.isbn == 0)
				break;
			if(total.same_isbn(trans)){
				total += trans;
			} else {
				cout<<total<<endl;
				total = trans;
			}
		}
		cout<<total<<endl;
	} else {
		cout<<"No Data?!"<<endl;
	}
	*/

	//2.3
	int value = 2;
	int power = 10;
	int result = 1;
	for(int i = 0; i < power; i++){
		result = result * value;
	}
	cout<<value<<"的"<<power<<"次方："<<result<<endl;

	system("pause");
	return 0;
}
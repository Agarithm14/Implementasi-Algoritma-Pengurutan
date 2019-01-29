/*
	Implementasi pengurutan angka dengan algoritma bubble di C++
	- Audhika Gaindata
*/
#include<iostream>
#include<vector>
using namespace std;

void print(vector<int> v)
{
	for(int i=0;i<v.size();i++)
	{
		cout<<v[i]<<" ";
	}
	cout<<endl;
}

int main()
{
	vector<int> v = {5,10,12,3,21,7};
	
	for (int i=0;i<v.size();i++)
	{
		for (int j=0;j<v.size()-1-i;j++)
		{
			if (v[j]>v[j+1]) swap(v[j],v[j+1]);
		}
	}
	
	//print
	print(v);
	
	return 0;
}

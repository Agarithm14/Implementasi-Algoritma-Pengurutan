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
	//ini buat array
	vector<int> v;// = {5,10,12,3,21,7};
	v.push_back(5);
	v.push_back(10);
	v.push_back(12);
	v.push_back(3);
	
	for (int i=0;i<v.size();i++)
	{
		int indeksKecil = i;
		for (int j=i;j<v.size();j++)
		{
			if (v[indeksKecil]<v[j]) indeksKecil = j;
		}
		swap(v[i],v[indeksKecil]);
	}
	//print isi array
	print(v);
	return 0;
}

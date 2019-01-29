#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


vector<int> quicksort(vector<int> V)
{
	if (V.size() <= 1)
	{
		return V;
	}
	int pivot = V[0];
	vector<int> kiri;
	vector<int> kanan;
	for (int i = 1;i<V.size();i++)
	{
		if (pivot>V[i])
		{
			kiri.push_back(V[i]);
		}
		else
		{
			kanan.push_back(V[i]);
		}
	}
	kiri = quicksort(kiri);
	kanan = quicksort(kanan);
	
	vector<int> hasil;
	hasil.push_back(pivot);
	//menambahkan di depan;
	//method insert(mulai dari mana, awal vector yang akan di tambah, 
	//	akhir vector yang di tambah)
	hasil.insert(hasil.begin(),kiri.begin(),kiri.end());
	hasil.insert(hasil.end(),kanan.begin(),kanan.end());
	return hasil;
}

int main()
{
	vector<int> V = {31,19,18,17,16,10,100,35};
	//vector<int> hasil = quicksort(V);
	sort(V.begin(),V.end());
	for (int i=0;i<V.size();i++)
	{
		cout<<V[i]<<" ";
	}
	cout<<endl;
	return 0;
}

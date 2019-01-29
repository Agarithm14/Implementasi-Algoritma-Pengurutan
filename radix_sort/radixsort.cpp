/*
	Implementasi pengurutan angka dengan algoritma radix di C++
	- Audhika Gaindata
*/

#include<iostream>
#include<queue>
#include<math.h>
#include<stdio.h>
using namespace std;

#define ulong unsigned long long

int main()
{
	//baca input dari input.txt
	freopen("input.txt","r",stdin);
	
	//bucket untuk menyimpan grup angka
	queue<ulong> bucket[10];
	//list angka
	vector<ulong> v;
	
	//menyimpan input
	ulong input;
	//menyimpan banyak bilangan
	ulong n;
	
	//input
	cin>>n;
	for(ulong i=0;i<n;i++)
	{
		cin>>input;
		v.push_back(input);
	}
	
	//cari nilai maksimum, sehingga tahu berapa kali iterasi
	ulong maks = v[0];
	for (ulong i=0;i<v.size();i++)
	{
		maks = (maks<v[i])?v[i]:maks;
	}
	
	//ubah ke string untuk mengambil banyak digit
	string temp = to_string(maks);
	
	//dari digit 1 ke banyak digit
	for (ulong i=0;i<temp.length();i++)
	{
		
		//Memasukkan tiap angka sesuai dengan bucket
		for (ulong j=0;j<v.size();j++)
		{
			//Mengambil digit ke i di tiap angka
			//Bisa saja mengubah menjadi string dan ambil indeks ke berapa
			//Namun harus di tambahkan "leading zero" (nol di depan) di tiap angka yang lebih "pendek"
			//Dan juga fungsi to_string di c++ lumayan lambat untuk angka yang sangat banyak
			bucket[(v[j]/(ulong) pow(10,i))%10].push(v[j]);
		}
		
		//memasukkan kembali ke vektor dari bucket
		ulong tem = 0;
		for (ulong j=0;j<v.size();j++)
		{
			while(bucket[tem].empty()) tem++;
			v[j] = bucket[tem].front();
			bucket[tem].pop();
		}
	}
	
	//output
	for (int i=0;i<v.size();i++)
	{
		cout<<v[i]<<"\n";
	}
	
	return 0;
}

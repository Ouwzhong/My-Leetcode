#include <iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		int N,M;//һ��Nֻ���������±�1��N 
		cin>>N>>M;
		int array[10005];
		for(int i=1;i<N;i++)
		{
			array[i]=i+1;
		}
		array[N]=1;	
		int count=N;
		int number=1;//��ǰ�±�� 
		if(M==1)
		{
			cout<<N<<endl;
			continue;
		} 	
		while(count>1)
		{
			for(int i=0;i<M-2;i++)//��ȡҪ��ɾ���ĺ��ӱ�� ǰһ�� 
			{
				number=array[number];
			}
			array[number] = array[array[number]];//ɾ���ڵ� 
			count--;
			number = array[number];//ָ����� 
		}	
		cout<<number<<endl;
	}
 } 

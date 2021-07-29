#include <iostream>
#define max_degree 10
using namespace std;
void print(int* permutation)
{
	int current=permutation[0];
	while(current!=0)
	{
		cout<<current;
		current=permutation[current];
	}	
	cout<<endl;
	return;
} 
void permute(int n,int degree,int*permutation)
{
	if(n==degree+1)
	{
		print(permutation);//��ӡȫ����
		return; 
	} 
	if(permutation[0]==0)
	{
		permutation[0]=n;//������������û��Ԫ����ͷ�����±�Ϊ n��Ϊͷ
		permute(n+1,degree,permutation); 
	}
	else
	{
		int current = 0;//��ǰ���������±� 0�±�һ��Ϊ��һ�� 
		for(int i=0;i<n;i++)
		{
			//����һ��Ԫ�ؽ������� �� 
			permutation[n]=permutation[current];
			permutation[current]=n;
			//�ݹ飺 
			permute(n+1,degree,permutation);
			//�ָ�����ǰ״̬����һ��ѭ��������һ��λ�ã� 
			permutation[current]=permutation[n];
			permutation[n]=0;
			//current������һ��λ�ã� 
			current=permutation[current]; 
		}
	}
	return;
}
int main()
{
	int degree;//Ҫ�ŵ�1��degree��ȫ����
	int permutation[max_degree+1]={0};
	cin>>degree;
	permutation[0]=0;
	permute(1,degree,permutation);
	return 0;
}

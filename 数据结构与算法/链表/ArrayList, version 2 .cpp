#include <iostream>
using namespace std;
typedef int T;
class ArrayList2 {
   public:
    ArrayList2()//��������Ա�
    {
    	elems=NULL;
    	count=0;
		arraySize=0;    	
	}
    ArrayList2(int n)//���쳤�ȣ���size��Ϊn�����Ա�
    {
    	elems = new T[n];
    	count=n;
    	arraySize=n;
	}
    ~ArrayList2()
    {
    	delete []elems;
    	count=0;
    	arraySize=0;
	}
    ArrayList2(const ArrayList2 & c)
    {
    	elems = new T[c.arraySize];
    	for(int i=0;i<c.count;i++)
    	{
    		elems[i]=c.elems[i];
		}
		count=c.count;
		arraySize=c.arraySize;
	}
    const ArrayList2& operator = (ArrayList2 & c)
    {
    	if(elems!=NULL)
    	{
    		delete []elems;
		}
		elems = new T[c.arraySize];
    	for(int i=0;i<c.count;i++)
    	{
    		elems[i]=c.elems[i];
		}
		count=c.count;
		arraySize=c.arraySize;	
		return *this;
	}
    int size() const //�������Ա���Ԫ�ظ���
    {
    	return count;
	}
    int capacity()const//�������������
    {
    	return arraySize;
	}
    bool full() const //�������������true, ���򣬷���false.
    {
    	return count==arraySize;
	}
    bool empty() const //�����գ�����true, ���򣬷���false.
    {
    	return count==0;
	}
    void clear() //������Ϊ�ձ�
    {
    	count=0;
	}
    void traverse(void (*visit)(T &))//������ (*visit)Ӧ�õ�����ÿ��Ԫ���ϡ�
    {
    	for(int i=0;i<count;i++)
    	{
    		visit(elems[i]);
		}
	}  
    void retrieve(int position, T &x) const
    {
    	if(0<=position&&position<=size()-1)
    	{
    		x=elems[position];
		}
		else
			return;
	}
    //���0=<position<=size()-1, ����x����λ��position��Ԫ��
    //���򣬶���Ϊ��.
    void replace(int position, const T &x)
    {
    	if(0<=position&&position<=size()-1)
    	{
    		elems[position]=x;
		}
		else
			return;
	}
    //���0=<position<=size()-1, ��λ��position��Ԫ���޸ĳ�x.
    //���򣬶���Ϊ��.
    void erase(int position, T &x)
    {
    	if(0<=position&&position<=size()-1)
    	{
    		x=elems[position];
    		for(int i=position;i<count-1;i++)
    		{
    			elems[i]=elems[i+1];
			}
			count--;
		}
		else
			return;
	}
    //���0=<position<=size()-1, ��λ��position��Ԫ��ɾ����
    //����ɾ����Ԫ����x���أ����򣬶���Ϊ��.
    void erase(int position)
    {
    	if(0<=position&&position<=size()-1)
    	{
    		for(int i=position;i<count-1;i++)
    		{
    			elems[i]=elems[i+1];
			}
			count--;
		}
		else
			return;
	}
    T & operator [] (int position)
    {
    	return elems[position];
	}
    //���0=<position<=size()-1, �򷵻�λ��position��Ԫ��
    //���򣬶���Ϊ��.
    int find( T &x) const //return the position of the first occurrence of x if it exists, return -1 otherwise.
    {
    	for(int i=0;i<count;i++)
    	{
    		if(elems[i]==x)
    		{
    			return i;
			}
		}
		return -1;
	}
    void push_back(const T &x)//put x after the last item 
    {
    	insert(count,x);
	}
    void insert(int position, const T &x)
    {
    	if(0<=position&&position<=size())
    	{
    		if(full())
    		{
    			T* newlist = new T[arraySize+1];//��չ�����С,ÿ����չ5��С 
				for(int i=0;i<position;i++)
				{
					newlist[i]=elems[i];
				} 
				newlist[position]=x;
				for(int i=position+1;i<=count;i++)
				{
					newlist[i]=elems[i-1];
				}
				count++;
				arraySize++;
				delete []elems;
				elems=newlist;
				return;
			}
    		for(int i=count-1;i>=position;i--)
    		{
    			elems[i+1]=elems[i];
			}
			elems[position]=x;
			count++;
		}
		else
			return;
	}
    //���0=<position<=size(), ��x���뵽λ��position.
    //���򣬶���Ϊ��.
  private:
    T *elems;
    int count; //��¼����elems�д洢��Ԫ�ظ���
    int arraySize;//���鳤��
};
int main()
{
	ArrayList2 lst1(5);
	lst1.push_back(1);
	lst1.push_back(2);
	lst1.push_back(3);
	lst1.push_back(4);
	lst1.push_back(5);
	lst1.push_back(6);
	ArrayList2 lst2(lst1);
	lst2.erase(0);
	lst1=lst2;
	cout<<lst1[0];
	
}

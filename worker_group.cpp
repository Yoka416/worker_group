//����˾������Ƹ��10��Ա����ABCDEFGHJ����10��Ա�����빫˾֮����Ҫָ��Ա�����Ǹ����Ź���
//��Ա����Ϣ�У�����������ɣ����ŷ�Ϊ���߻�����������
//�������10��Ա�����䲿�ź͹���
//��ͨ��multimap������Ϣ�Ĳ���key�����ű�ţ�value��Ա����
//���ֲ�����ʾԱ����Ϣ

//1.����10��Ա�����ŵ�vector��
//2.����vector������ȡ��ÿ��Ա���������������3.����󣬽�Ա�����ű����Ϊkey������Ա����Ϊvalue�����뵽multimap������
//4.�ֲ�����ʾԱ����Ϣ

#include<iostream>
using namespace std;
#include<string>
#include<vector>
#include<map>
#include<ctime>

#define �߻� 0 
#define ���� 1 
#define ���� 2 

//����Ա������
class worker
{
public:
	/*worker(string name,int salary)
	{
		this->m_name =name;
		this->m_salary =salary;
	}*/
	string m_name;
	int m_salary;
};

//����10��Ա��
void createworker(vector<worker> &v)
{
	string nameseed="ABCDEFGHIJ";
	for(int i=0;i<10;i++)
	{
		worker workers;//!����û�к��ʵĹ��캯������Ϊ�������вι��캯�����������õ�!
		workers.m_name+=nameseed[i];//����
		workers.m_salary= rand()% 10001+10000; //10000-20000
		v.push_back(workers);//��Ա����������
	}
}

void setworker(vector<worker>&v,multimap<int,worker>&m)
{
	//Ա������
	for(vector<worker>::iterator  it=v.begin();it!=v.end();it++)
	{
		int deptId = rand()%3; //0 1 2
		m.insert(make_pair(deptId,*it));//!! 
	}
}

void showworker(multimap<int,worker>&m)
{
	cout<<"�߻����ţ�"<<endl;
	
	multimap<int,worker>::iterator pos = m.find(�߻�);
	int count = m.count(�߻�);
	int a=0;
	for(; pos!=m.end()&&a<count;  a++,pos++)//������pos++֮�������һ���߻�����Ϊmap���汾������ǰ���������еģ�
	{
		cout<<"������"<<pos->second.m_name<<"н�꣺"<<pos->second.m_salary<<endl;
	}

	cout<<"---------------------------------"<<endl;
	
	cout<<"�������ţ�"<<endl;
	pos = m.find(����);
	count = m.count(����);
	a=0;
	for(; pos!=m.end()&&a<count;  a++,pos++)//������pos++֮�������һ���߻�����Ϊmap���汾������ǰ���������еģ�
	{
		cout<<"������"<<pos->second.m_name<<"н�꣺"<<pos->second.m_salary<<endl;
	}
	cout<<"---------------------------------"<<endl;
	
	cout<<"�������ţ�"<<endl;
	pos = m.find(����);
	count = m.count(����);
	a=0;
	for(; pos!=m.end()&&a<count;  a++,pos++)//������pos++֮�������һ���߻�����Ϊmap���汾������ǰ���������еģ�
	{
		cout<<"������"<<pos->second.m_name<<"н�꣺"<<pos->second.m_salary<<endl;
	}


}


int main ()
{
	srand((unsigned int)time(NULL));//��֤ÿ�����������������һ��
	vector<worker>v;
	//����Ա��
	createworker(v);

	////����
	//for(vector<worker>::iterator  it=v.begin();it!=v.end();it++)
	//{
	//	cout<<"Ա����������"<<it->m_name<<"  Ա����н�꣺"<<it->m_salary<<endl;
	//}


	//��Ա���ŵ����������
	multimap<int,worker>m;
	setworker(v,m);//Ա������

	//��ʾ����Ա��
	showworker(m);



	


	system("pause");
	return 0;
}
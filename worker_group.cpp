//·公司今天招聘了10个员工（ABCDEFGHJ），10名员工进入公司之后，需要指派员工在那个部门工作
//·员工信息有：姓名工资组成；部门分为：策划、美术、发
//·随机给10名员工分配部门和工资
//·通过multimap进行信息的插入key（部门编号）value（员工）
//·分部门显示员工信息

//1.创建10名员工，放到vector中
//2.遍历vector容器，取出每个员工，进行随机分组3.分组后，将员工部门编号作为key，具体员工作为value，放入到multimap容器中
//4.分部门显示员工信息

#include<iostream>
using namespace std;
#include<string>
#include<vector>
#include<map>
#include<ctime>

#define 策划 0 
#define 美术 1 
#define 开发 2 

//建立员工的类
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

//创建10名员工
void createworker(vector<worker> &v)
{
	string nameseed="ABCDEFGHIJ";
	for(int i=0;i<10;i++)
	{
		worker workers;//!错误：没有合适的构造函数，因为设置了有参构造函数，不用设置的!
		workers.m_name+=nameseed[i];//！！
		workers.m_salary= rand()% 10001+10000; //10000-20000
		v.push_back(workers);//将员工放入容器
	}
}

void setworker(vector<worker>&v,multimap<int,worker>&m)
{
	//员工分组
	for(vector<worker>::iterator  it=v.begin();it!=v.end();it++)
	{
		int deptId = rand()%3; //0 1 2
		m.insert(make_pair(deptId,*it));//!! 
	}
}

void showworker(multimap<int,worker>&m)
{
	cout<<"策划部门："<<endl;
	
	multimap<int,worker>::iterator pos = m.find(策划);
	int count = m.count(策划);
	int a=0;
	for(; pos!=m.end()&&a<count;  a++,pos++)//！这里pos++之后就是下一个策划，因为map里面本身就是是按照序号排列的！
	{
		cout<<"姓名："<<pos->second.m_name<<"薪酬："<<pos->second.m_salary<<endl;
	}

	cout<<"---------------------------------"<<endl;
	
	cout<<"美术部门："<<endl;
	pos = m.find(美术);
	count = m.count(美术);
	a=0;
	for(; pos!=m.end()&&a<count;  a++,pos++)//！这里pos++之后就是下一个策划，因为map里面本身就是是按照序号排列的！
	{
		cout<<"姓名："<<pos->second.m_name<<"薪酬："<<pos->second.m_salary<<endl;
	}
	cout<<"---------------------------------"<<endl;
	
	cout<<"开发部门："<<endl;
	pos = m.find(开发);
	count = m.count(开发);
	a=0;
	for(; pos!=m.end()&&a<count;  a++,pos++)//！这里pos++之后就是下一个策划，因为map里面本身就是是按照序号排列的！
	{
		cout<<"姓名："<<pos->second.m_name<<"薪酬："<<pos->second.m_salary<<endl;
	}


}


int main ()
{
	srand((unsigned int)time(NULL));//保证每次随机产生的数都不一样
	vector<worker>v;
	//创建员工
	createworker(v);

	////测试
	//for(vector<worker>::iterator  it=v.begin();it!=v.end();it++)
	//{
	//	cout<<"员工的姓名："<<it->m_name<<"  员工的薪酬："<<it->m_salary<<endl;
	//}


	//将员工放到序号容器中
	multimap<int,worker>m;
	setworker(v,m);//员工分组

	//显示各组员工
	showworker(m);



	


	system("pause");
	return 0;
}
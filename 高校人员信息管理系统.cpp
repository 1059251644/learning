#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
#include <stdlib.h>
#define tmax 20
#define amax 20
#define lmax 20
using namespace std;

class teacher
{
public:
	string id;
	string name;
	string sex;
	int age;
	string dept;
	string specialty;
	string duty;
	void output();
    
    
};

void teacher::output()
{
	cout<<" ****************************************** "<<endl;
	cout<<"      教师的职工号:"<<id<<endl;
	cout<<"      教师的姓名： "<<name<<endl;
	cout<<"      教师的性别： "<<sex<<endl;
	cout<<"      教师的年龄： "<<age<<endl;
	cout<<"      教师的系部： "<<dept<<endl;
	cout<<"      教师的专业： "<<specialty<<endl;
	cout<<"      教师的职务： "<<duty<<endl;
	cout<<" ****************************************** "<<endl;
}

class tea_manage
{
	tea_teacher tea[tmax];
	
	int locate;
public:int top;
	   tea_manage(){top=0;}
       void Tadd();
       void Tsearch(int x);
       void Tedit();
       int Ttotal(int y);
       tea_manage TDelete();
       void Tshow();
       void Tsave();
	   tea_manage Tread();
};
tea_manage tea_manage::TDelete()
{
	int i;
    int a;
    
    string id;
	if(top==0)
	{
		cout<<"没有任何数据"<<endl;
	}
	else
	{
		cout<<"请输入要删除的人员的职工号：";
		cin>>id;
		for(i=0;i<top;i++)
		{
			if(id==tea[i].id)
			{
				cout<<"----------------"<<endl;
				cout<<"|是否确认删除？|"<<endl;
				cout<<"|1:是    2:不是|"<<endl;
				cout<<"----------------"<<endl;
				cin>>a;
				switch(a)
				{
				case 1:
					{
						for(int j=i;j<top;j++)
						{
							tea[j]=tea[j+1];
							top--;
						}
						cout<<"删除成功！"<<endl;
						break;
					}
				case 2:break;
				default:cout<<"输入错误！"<<endl;break;
				}
				break;
				
			}
			
			
		}
		if (i==top)
		{
			cout<<"查无此人"<<endl;
		}
		
	}
	return *this;
	
	
	

	
}
void tea_manage::Tadd()
{
	int i;
	int b=0;
	int c=0;
	teacher a;
	cout<<"新增教师人员信息："<<endl;
	
	if (top==tmax)
	{
		cout<<"行政人员已满，不可添加！"<<endl;
	}
	else
	{
		cout<<" ****************************************** "<<endl;
		cout<<"请输入教师的职工号：";
		cin>>a.id;
    	for(i=0;i<top;i++)
		{
		    if(a.id==tea[i].id)
			{
		    	cout<<"该教师人员的职工号已存在，请重新输入："<<endl;
				b=1;
		    	break;
			}
		
		}
		if (b==0)
		{
			tea[top].id=a.id;
			int a;
			int b;
			cout<<"|     教师的姓名：";
			cin>>tea[top].name;
			cout<<"|     教师的性别:1:男"<<endl;
			cout<<"|                2:女"<<endl;
			cout<<"|         请选择: ";
			cin>>a;
			switch(a)
			{
			case 1:tea[top].sex="男";break;
			case 2:tea[top].sex="女";break;
			default:cout<<"无此项，失败！自动匹配性别为：男。";
			}
			cout<<"|     教师的年龄：";
			cin>>tea[top].age;
			cout<<"|     教师的系部: 1:计算机系"<<endl;
			cout<<"|                 2:电子系"<<endl;
			cout<<"|                 3:经管系"<<endl;
			cout<<"|                 4:机械系"<<endl;
			cout<<"|                 5:建工系"<<endl;
			cout<<"|                 6:外语系"<<endl;
			cout<<"|                 7:其他"<<endl;
			cout<<"|          请选择:";
			cin>>a;
			switch(a)
			{
			case 1:
				{
					tea[top].dept="计算机系";
					cout<<"|     教师的专业: 1:软件工程"<<endl;
					cout<<"|                 2:网络工程"<<endl;
					cout<<"|                 3:其他"<<endl;
					cout<<"|         请选择:";
					cin>>b;
					switch(b)
					{
					case 1:tea[top].specialty="软件工程";break;
					case 2:tea[top].specialty="网络工程";break;
					case 3:
						{
						  cout<<"|          请输入:";
						  cin>>tea[top].specialty;
				       	  break;
						}
					}
					break;
				}
			case 2:
				{
					tea[top].dept="电子系";
					cout<<"|     教师的专业: 1:电子技术"<<endl;
					cout<<"|                 2:信息安全"<<endl;
					cout<<"|                 3:光电子信息科学"<<endl;
					cout<<"|                 4:其他"<<endl;
					cout<<"|         请选择:";
					cin>>b;
					switch(b)
					{
					case 1:tea[top].specialty="电子技术";break;
					case 2:tea[top].specialty="信息安全";break;
					case 3:tea[top].specialty="光电子信息科学";break;
					case 4:
						{
							cout<<"|         请输入:";
							cin>>tea[top].specialty;
							break;
						}
					}
					break;
				}
			case 3:
				{
					tea[top].dept="经管系";
					cout<<"|     教师的专业: 1:金融学"<<endl;
					cout<<"|                 2:会计学"<<endl;
					cout<<"|                 3:市场营销"<<endl;
					cout<<"|                 4:人力资源管理"<<endl;
					cout<<"|                 5:其他"<<endl;
					cout<<"|         请选择:";
					cin>>b;
					switch(b)
					{
					case 1:tea[top].specialty="金融学";break;
					case 2:tea[top].specialty="会计学";break;
					case 3:tea[top].specialty="市场营销";break;
					case 4:tea[top].specialty="人力资源管理";break;
					case 5:
						{
							cout<<"|         请输入:";
							cin>>tea[top].specialty;
							break;
						}
					}
					break;
				}
			case 4:
				{
					tea[top].dept="机械系";
					cout<<"|     教师的专业: 1:机械设计制造及其自动化"<<endl;
					cout<<"|                 2:工业设计"<<endl;
					cout<<"|                 3:其他"<<endl;
					cout<<"|         请选择:";
					cin>>b;
					switch(b)
					{
					case 1:tea[top].specialty="机械设计制造及其自动化";break;
					case 2:tea[top].specialty="工业设计";break;
					case 3:
						{
							cout<<"|         请输入:";
							cin>>tea[top].specialty;
							break;
						}
					}
					break;
				}
			case 5:
				{
					tea[top].dept="建工系";
					cout<<"|     教师的专业: 1:土木工程"<<endl;
					cout<<"|                 2:水利工程"<<endl;
					cout<<"|                 3:其他"<<endl;
					cout<<"|         请选择:";
					cin>>b;
					switch(b)
					{
					case 1:tea[top].specialty="土木工程";break;
					case 2:tea[top].specialty="水利工程";break;
					case 3:
						{
							cout<<"|         请输入:";
							cin>>tea[top].specialty;
							break;
						}
					}
					break;
				}
			case 6:
				{
					tea[top].dept="外语系";
					cout<<"|     教师的专业: 1:实用英语专业"<<endl;
					cout<<"|                 2:社会与文化英语专业"<<endl;
					cout<<"|                 3:其他"<<endl;
					cout<<"|         请选择:";
					cin>>b;
					switch(b)
					{
					case 1:tea[top].specialty="实用英语专业";break;
					case 2:tea[top].specialty="社会与文化英语专业";break;
					case 3:
						{
							cout<<"|         请输入:";
							cin>>tea[top].specialty;
							break;
						}
					}
			    	break;
				}
			case 7:
				{
					cin>>tea[top].dept;
					cout<<"|     教师的专业:";
					cin>>tea[top].specialty;
					break;
				}
			}	
			cout<<"      教师的职务：";
			cin>>tea[top].duty;
	        cout<<" ****************************************** "<<endl;
			
		    top++;
		}
		
	}
}
void tea_manage::Tshow()
{
	int i;
	for(i=0;i<top;i++)
	{
		tea[i].output();
		cout<<" ****************************************** "<<endl;
	}
	
}
int tea_manage::Ttotal(int y=0)
{
	int c=0;
	int a;
	int i;
	if (y==0)
	{
		while(a!=0)
	{	cout<<"| ****************************************** |"<<endl;
		cout<<"|                 【统计内容】               | "<<endl;
		cout<<"| -------------------------------------------|"<<endl;
		cout<<"|                 【1.男女人数数量】         |"<<endl;
		cout<<"|                 【2.计算机系人数】         |"<<endl;
		cout<<"|                 【3.电子系人数】           |"<<endl;
		cout<<"|                 【4.经管系人数】           |"<<endl;
		cout<<"|                 【5.机械系人数】           |"<<endl;
		cout<<"|                 【6.建工系人数】           |"<<endl;
		cout<<"|                 【7.外语系人数】           |"<<endl;
		cout<<"|                 【0.退出】                 |"<<endl;
		cout<<"| ****************************************** | "<<endl;
		cout<<"|请输入你的操作选项:";
		cin>>a;
		switch(a)
		{
		case 1:
			{
				for(i=0;i<top;i++)
				{	
					if (tea[i].sex=="男")
					{
						c++;
					}
				}
				cout<<"| ****************************************** |"<<endl;
				cout<<"|        教师一共"<<top<<"名               |"<<endl;
				cout<<"|        教师有: "<<c<<"名男性           |"<<endl;
				cout<<"|        教师有:"<<top-c<<"名女性            |"<<endl;
				cout<<"|****************************************** "<<endl;
				break;
			}
		case 2:
			{
				c=0;
				for(i=0;i<top;i++)
				{	
					if (tea[i].dept=="计算机系")
					{
						c++;
					}
				}
				cout<<"|        计算机系教师一共"<<c<<"名           |"<<endl;
				break;
			}
		case 3:
			{
				c=0;
				for(i=0;i<top;i++)
				{	
					if (tea[i].dept=="电子系")
					{
						c++;
					}
				}
				cout<<"|        电子系教师一共"<<c<<"名           |"<<endl;
				break;
			}
		case 4:
			{
				c=0;
				for(i=0;i<top;i++)
				{	
					if (tea[i].dept=="经管系")
					{
						c++;
					}
				}
				cout<<"|        经管系教师一共"<<c<<"名           |"<<endl;
				break;
			}
		case 5:
			{
				c=0;
				for(i=0;i<top;i++)
				{	
					if (tea[i].dept=="机械系")
					{
						c++;
					}
				}
				cout<<"|        机械系教师一共"<<c<<"名           |"<<endl;
				break;
			}
		case 6:
			{
				c=0;
				for(i=0;i<top;i++)
				{	
					if (tea[i].dept=="建工系")
					{
						c++;
					}
				}
				cout<<"|        建工系教师一共"<<c<<"名           |"<<endl;
				break;
			}
		case 7:
			{
				c=0;
				for(i=0;i<top;i++)
				{	
					if (tea[i].dept=="外语系")
					{
						c++;
					}
				}
				cout<<"|        外语系教师一共"<<c<<"名           |"<<endl;
				break;
			}
		}
			
	
			
	}
	} 
	else if(y==1)
	{
		for(i=0;i<top;i++)
		{	
			if (tea[i].sex=="男")
			{
				c++;
			}
		}
	
	}
	
	return c;
	
}
void tea_manage::Tsearch(int x=0)
{
	int a,i=0;
	string name;
	string id;
	if(top==0)
	{
		cout<<"没有任何数据"<<endl;
	}
	else
	{
		
		if (x==0)
		{
			cout<<"| ****************************************** |"<<endl;
		cout<<"|                 【查询方式】               | "<<endl;
		cout<<"| -------------------------------------------|"<<endl;
		cout<<"|                 【1.按名字】               |"<<endl;
		cout<<"|                 【2.按职工号】             | "<<endl;
		cout<<"|                 【0.退出】                 |"<<endl;
		cout<<"| ****************************************** | "<<endl;
		cout<<"请输入你的操作选项：";
		cin>>a;
		switch(a)
		{
		case 1:
			{
				cout<<"请输入查询人员的名字：";
				cin>>name;
				for(i=0;i<top;i++)
				{
					if(name==tea[i].name)
					{
						tea[i].output();
						locate=i;
						break;
					}
				}
				if (i==top)
				{
					cout<<"搜索无结果！"<<endl;
				}
				break;
			}
		case 2:
			{
				cout<<"请输入查询人员的职工号：";
				cin>>id;
				for(i=0;i<top;i++)
				{
					if(id==tea[i].id)
					{
						tea[i].output();
						locate=i;
						break;
					}
				}
				if (i==top)
				{
					cout<<"搜索无结果！"<<endl;
				}
				break;	
			}
		default:break;
			}
		} 
		else if(x==1)
		{
			cout<<"请输入查询人员的职工号：";
			cin>>id;
			for(i=0;i<top;i++)
			{
				if(id==tea[i].id)
				{
					tea[i].output();
					locate=i;
					break;
				}
			}
			if (i==top)
			{
				cout<<"搜索无结果！"<<endl;
					}
			
		}
	

	}
	
}
void tea_manage::Tedit()
{
	int a,i=0;
	Tsearch(1);
	i=locate;
	while(a!=0)
	{
		cout<<"| ****************************************** |"<<endl;
		cout<<"|                 【修改内容】               | "<<endl;
		cout<<"| -------------------------------------------|"<<endl;
		cout<<"|                 【1.职工号】               |"<<endl;
		cout<<"|                 【2.姓名】                 |"<<endl;
		cout<<"|                 【3.性别】                 |"<<endl;
		cout<<"|                 【4.年龄】                 |"<<endl;
		cout<<"|                 【5.系部】                 |"<<endl;
		cout<<"|                 【6.专业】                 |"<<endl;
		cout<<"|                 【7.职务】                 |"<<endl;
		cout<<"|                 【0.退出】                 |"<<endl;
		cout<<"| ****************************************** | "<<endl;
		cout<<"请输入你的操作选项：";
		cin>>a;
		switch(a)
		{
		case 1:
			{
				cout<<"职工号不可修改。"<<endl;
				break;
			}
		case 2:
			{
				cout<<" 请输入修改后的教师的姓名：";
				cin>>tea[i].name;
			
				break;
			}
		case 3:
			{
				cout<<"请输入修改后的教师的性别：";
				cin>>tea[i].sex;
		    	break;
			}
		case 4:
			{
				cout<<"请输入修改后的教师的年龄：";
				cin>>tea[i].age;
		    	break;
			}
		case 5:
			{
				cout<<"请输入修改后的 教师的系部：";
				cin>>tea[i].dept;
			  break;
			}
		case 6:
			{
				cout<<"请输入修改后的教师的专业：";
				cin>>tea[i].specialty;
				break;
			}
		case 7:
			{
				cout<<"请输入修改后的教师的职务：";
				cin>>tea[i].duty;
				break;
			}
		}
		
	}


	
}


void tea_manage::Tsave()
{
	ofstream ofs("D:\\teacher.txt",ios::out);
	if (!ofs)
	{
		cout<<"打开失败！"<<endl;

	} 
	else
	{
        cout<<"打开成功！"<<endl;
		for (int i=0;i<top;i++)
		{
			ofs<<tea[i].id<<" "<<tea[i].name<<" "<<tea[i].sex<<" "<<tea[i].age
				<<" "<<tea[i].specialty<<" "<<tea[i].dept<<" "<<tea[i].duty<<endl;
			
		}
		ofs.close();
	}
}

manage manage::Tread()
{
	int i=0;
	ifstream ifs("D:\\teacher.txt",ios::in);
	if(ifs)
	{
		
		
		while(ifs>>tea[i].id>>tea[i].name>>tea[i].sex>>tea[i].age>>tea[i].specialty>>tea[i].dept>>tea[i].duty)
		{
		
			if(ifs.eof())
				break;
			else
			{
			
				i++;
				top++;
				continue;
			}
			
		}
		ifs.close();
	}
	
	return *this;
	
}


class admin_staff
{
public: 
	string id;
    string name;
    string sex;
	int age;
	string political;
	string duty;
	void output();
	

};


void admin_staff::output()
{
	cout<<" ****************************************** "<<endl;
	cout<<"      行政人员的职工号:"<<id<<endl;
	cout<<"      行政人员的姓名： "<<name<<endl;
	cout<<"      行政人员的性别： "<<sex<<endl;
	cout<<"      行政人员的年龄： "<<age<<endl;
	cout<<"      行政人员的政治面貌： "<<political<<endl;
	cout<<"      行政人员的职务： "<<duty<<endl;
	cout<<" ****************************************** "<<endl;
}
class Adm_manage
{
	admin_staff adm[amax];
	
	int locate;
public:
	int top;
	Adm_manage(){top=0;}
	void add();
	void search(int x);
	void edit();
	int total(int y);
	Adm_manage Delete();
	void show();
	void save();
    Adm_manage read();
	
};
void Adm_manage::save()
{
	ofstream ofs("D:\\admin_staff.txt",ios::out);
	if (!ofs)
	{
		cout<<"打开失败！"<<endl;
		
	} 
	else
	{
        cout<<"打开成功！"<<endl;
		for (int i=0;i<top;i++)
		{
			ofs<<adm[i].id<<" "<<adm[i].name<<" "<<adm[i].sex<<" "<<adm[i].age
				<<" "<<adm[i].political<<" "<<adm[i].duty<<endl;
			
		}
		ofs.close();
	}
}

Adm_manage Adm_manage::read()
{
	int i=0;
	ifstream ifs("D:\\admin_staff.txt",ios::in);
	if(ifs)
	{
		
		
		while(ifs>>adm[i].id>>adm[i].name>>adm[i].sex>>adm[i].age>>adm[i].political>>adm[i].duty)
		{
			
			if(ifs.eof())
				break;
			else
			{
				
				i++;
				top++;
				continue;
			}
			
		}
		ifs.close();
	}
	
	return *this;
	
}
Adm_manage Adm_manage::Delete()
{
	int i;
    int a;
    
    string id;
	if(top==0)
	{
		cout<<"没有任何数据"<<endl;
	}
	else
	{
		cout<<"请输入要删除的人员的职工号：";
		cin>>id;
		for(i=0;i<top;i++)
		{
			if(id==adm[i].id)
			{
				cout<<"----------------"<<endl;
				cout<<"|是否确认删除？|"<<endl;
				cout<<"|1:是    2:不是|"<<endl;
				cout<<"----------------"<<endl;
				cin>>a;
				switch(a)
				{
				case 1:
					{
						for(int j=i;j<top;j++)
						{
							adm[j]=adm[j+1];
							top--;
						}
						cout<<"删除成功！"<<endl;
						break;
					}
				case 2:break;
				default:cout<<"输入错误！"<<endl;break;
				}
				break;
				
			}
			
		
		}
		if (i==top)
		{
			cout<<"查无此人"<<endl;
		}
		
	}
	return *this;
	
	
	
	
}
void Adm_manage::edit()
{
	int a,i=0;
	search(1);
	i=locate;
	while(a!=0)
	{
		cout<<"| ****************************************** |"<<endl;
		cout<<"|                 【修改内容】               | "<<endl;
		cout<<"| -------------------------------------------|"<<endl;
		cout<<"|                 【1.职工号】               |"<<endl;
		cout<<"|                 【2.姓名】                 |"<<endl;
		cout<<"|                 【3.性别】                 |"<<endl;
		cout<<"|                 【4.年龄】                 |"<<endl;
		cout<<"|                 【5.政治面貌】             |"<<endl;
		cout<<"|                 【6.职务】                 |"<<endl;
		cout<<"|                 【0.退出】                 |"<<endl;
		cout<<"| ****************************************** | "<<endl;
		cout<<"请输入你的操作选项：";
		cin>>a;
		switch(a)
		{
		case 1:
			{
				cout<<"职工号不可修改。"<<endl;
				break;
			}
		case 2:
			{
				cout<<" 请输入修改后的行政人员的姓名：";
				cin>>adm[i].name;
				break;
			}
		case 3:
			{
				cout<<"请输入修改后的行政人员的性别：";
				cin>>adm[i].sex;
				break;
			}
		case 4:
			{
				cout<<"请输入修改后的行政人员的年龄：";
				cin>>adm[i].age;
				break;
			}
		case 5:
			{
				cout<<"请输入修改后的行政人员的专业：";
				cin>>adm[i].political;
				break;
			}
		case 6:
			{
				cout<<"请输入修改后的行政人员的职务：";
				cin>>adm[i].duty;
				break;
			}
		}
		
	}
	
	
	
}
void Adm_manage::add()
{
	int i;
	int c;
	int b=0;
	teacher a;
	cout<<"新增行政人员信息："<<endl;
	
	if (top==amax)
	{
		cout<<"行政人员已满，不可添加！"<<endl;
	}
	else
	{
		cout<<" ****************************************** "<<endl;
		cout<<"请输入行政人员的职工号：";
		cin>>a.id;
		for(i=0;i<top;i++)
		{
			if(a.id==adm[i].id)
			{
				cout<<"该行政人员的职工号已存在，请重新输入："<<endl;
				b=1;
				break;
			}
			
		}
		if (b==0)
		{
			adm[top].id=a.id;
			cout<<"|     行政人员的姓名：";
			cin>>adm[top].name;
			cout<<"|     行政人员的性别:1:男 "<<endl;
			cout<<"                     2:女 "<<endl;
			cout<<"              请选择:";
			cin>>c;
			switch(c)
			{
			case 1:adm[top].sex="男";break;
			case 2:adm[top].sex="女";break;
			default:cout<<"无此项，失败！自动匹配性别为：男。";
			}
			cout<<"|      行政人员的年龄：";
			cin>>adm[top].age;
			cout<<"|      行政人员的政治面貌:1:共青团员"<<endl;
			cout<<"|                         2:中共党员"<<endl;
			cout<<"|                         3:群众"<<endl;
			cout<<"|                         4:其他"<<endl;
			cout<<"|          请选择:";
			cin>>c;
			switch(c)
			{
			case 1:adm[top].political="共青团员";break;
			case 2:adm[top].political="中共党员";break;
			case 3:adm[top].political="群众";break;
			case 4:
				{
					cout<<"|         请输入:";
					cin>>adm[top].political;
					break;
				}
			}
        	cout<<"|      行政人员的职务:1:招生办公室"<<endl;
			cout<<"|                     2:学生工作部"<<endl;
			cout<<"|                     3:团委办公室"<<endl;
			cout<<"|                     4:教务处"<<endl;
			cout<<"|                     5:学工处"<<endl;
			cout<<"|                     6:党办"<<endl;
			cout<<"|                     7:其他"<<endl;
			cout<<"|          请选择:";
			cin>>c;
			switch(c)
			{
			case 1:adm[top].duty="招生办公室";break;
			case 2:adm[top].duty="学生工作部";break;
			case 3:adm[top].duty="团委办公室";break;
			case 4:adm[top].duty="教务处";break;
			case 5:adm[top].duty="学工处";break;
			case 6:adm[top].duty="党办";break;
			case 7:
				{
					cout<<"|         请输入:";
					cin>>adm[top].duty;
					break;
				}
			}
			
			cout<<" ****************************************** "<<endl;
			cout<<"添加成功！"<<endl;
			top++;
		}
		
	}
}
void Adm_manage::show()
{
	int i;
	for(i=0;i<top;i++)
	{
		adm[i].output();
		cout<<" ****************************************** "<<endl;
	}
	
}
int Adm_manage::total(int y=0)
{
	int c=0;
	int a;
	int i;
	if (y==0)
	{
		while(a!=0)
		{	cout<<"| ****************************************** |"<<endl;
		cout<<"|                 【统计内容】               | "<<endl;
		cout<<"| -------------------------------------------|"<<endl;
		cout<<"|                 【1.男女人数数量】         |"<<endl;
		cout<<"|                 【2.共青团员人数】         |"<<endl;
		cout<<"|                 【3.中共党员人数】         |"<<endl;
		cout<<"|                 【4.群众人数】             |"<<endl;
		cout<<"|                 【0.退出】                 |"<<endl;
		cout<<"| ****************************************** | "<<endl;
		cout<<"|请输入你的操作选项:";
		cin>>a;
		switch(a)
		{
		case 1:
			{
				for(i=0;i<top;i++)
				{	
					if (adm[i].sex=="男")
					{
						c++;
					}
				}
				cout<<"| ****************************************** |"<<endl;
				cout<<"|        行政人员一共"<<top<<"名             |"<<endl;
				cout<<"|        行政人员有: "<<c<<"名男性         |"<<endl;
				cout<<"|        行政人员有:"<<top-c<<"名女性          |"<<endl;
				cout<<"|****************************************** "<<endl;
				break;
			}
		case 2:
			{
				c=0;
				for(i=0;i<top;i++)
				{	
					if (adm[i].political=="共青团员")
					{
						c++;
					}
				}
				cout<<"|        共青团员一共"<<c<<"名            |"<<endl;
				break;
			}
		case 3:
			{
				c=0;
				for(i=0;i<top;i++)
				{	
					if (adm[i].political=="中共党员")
					{
						c++;
					}
				}
				cout<<"|        中共党员一共"<<c<<"名            |"<<endl;
				break;
			}
		case 4:
			{
				c=0;
				for(i=0;i<top;i++)
				{	
					if (adm[i].political=="群众")
					{
						c++;
					}
				}
				cout<<"|        群众一共"<<c<<"名               |"<<endl;
				break;
			}
			
		}
		
		
		
	}
	} 
	else if(y==1)
	{
		for(i=0;i<top;i++)
		{	
			if (adm[i].sex=="男")
			{
				c++;
			}
				}
	}
	
	return c;
	
}
void Adm_manage::search(int x=0)
{
	int a,i=0;
	string name;
	string id;
	if(top==0)
	{
		cout<<"没有任何数据"<<endl;
		
	}
	else
	{
		if (x==0)
		{
			cout<<"| ****************************************** |"<<endl;
			cout<<"|                 【查询方式】               | "<<endl;
			cout<<"| -------------------------------------------|"<<endl;
			cout<<"|                 【1.按姓名】               |"<<endl;
			cout<<"|                 【2.按职工号】             |"<<endl;
			cout<<"|                 【0.退出】                 |"<<endl;
			cout<<"| ****************************************** | "<<endl;
			cout<<"请输入你的操作选项：";
			cin>>a;
			switch(a)
			{
				
				
			case 1:
				{
					cout<<"请输入查询人员的名字：";
					cin>>name;
					for(i=0;i<top;i++)
					{
						if(name==adm[i].name)
						{
							adm[i].output();
							locate=i;
							break;
						}
					}
					if (i==top)
					{
						cout<<"搜索无结果！"<<endl;
					}
					break;
					
				}
			case 2:
				{
					cout<<"请输入查询人员的职工号：";
					cin>>id;
					for(i=0;i<top;i++)
					{
						if(id==adm[i].id)
						{
							adm[i].output();
							locate=i;
							break;
						}
					}
					if (i==top)
					{
						cout<<"搜索无结果！"<<endl;
					}
					break;	
				}
			default:break;
				
	}

		} 
		else if(x==1)
		{
			cout<<"请输入查询人员的职工号：";
			cin>>id;
			for(i=0;i<top;i++)
			{
				if(id==adm[i].id)
				{
					adm[i].output();
					locate=i;
					break;
				}
			}
			if (i==top)
			{
				cout<<"搜索无结果！"<<endl;
					}
		}
	
	}
	
}


class laboratory
{
 public: 
    string id;
    string name;
    string sex;
	int age;
	string lab;
	string duty;
	void output();

};


void laboratory::output()
{
	cout<<" ****************************************** "<<endl;
	cout<<"      实验员的职工号:"<<id<<endl;
	cout<<"      实验员的姓名： "<<name<<endl;
	cout<<"      实验员的性别： "<<sex<<endl;
	cout<<"      实验员的年龄： "<<age<<endl;
	cout<<"      实验员的实验室： "<<lab<<endl;
	cout<<"      实验员的职务： "<<duty<<endl;
	cout<<" ****************************************** "<<endl;
}
class labor_manage
{
	laboratory labor[lmax];
	
	int locate;
public:
	int top;
	labor_manage(){top=0;}
	void add();
	void search(int x);
	void edit();
	int total(int y);
	labor_manage Delete();
	void show();
	void save();
    labor_manage read();

};
void labor_manage::save()
{
	ofstream ofs("D:\\laboratory.txt",ios::out);
	if (!ofs)
	{
		cout<<"打开失败！"<<endl;
		
	} 
	else
	{
        cout<<"打开成功！"<<endl;
		for (int i=0;i<top;i++)
		{
			ofs<<labor[i].id<<" "<<labor[i].name<<" "<<labor[i].sex<<" "<<labor[i].age
				<<" "<<labor[i].lab<<" "<<labor[i].duty<<endl;
			
		}
		ofs.close();
	}
}

labor_manage labor_manage::read()
{
	int i=0;
	ifstream ifs("D:\\laboratory.txt",ios::in);
	if(ifs)
	{
		
		
		while(ifs>>labor[i].id>>labor[i].name>>labor[i].sex>>labor[i].age>>labor[i].lab>>labor[i].duty)
		{
			
			if(ifs.eof())
				break;
			else
			{
				
				i++;
				top++;
				continue;
			}
			
		}
		ifs.close();
	}
	
	return *this;
	
}
labor_manage labor_manage::Delete()
{
	int i;
    int a;
    
    string id;
	if(top==0)
	{
		cout<<"没有任何数据"<<endl;
	}
	else
	{
		cout<<"请输入要删除的人员的职工号：";
		cin>>id;
		for(i=0;i<top;i++)
		{
			if(id==labor[i].id)
			{
				cout<<"----------------"<<endl;
				cout<<"|是否确认删除？|"<<endl;
				cout<<"|1:是    2:不是|"<<endl;
				cout<<"----------------"<<endl;
				cin>>a;
				switch(a)
				{
				case 1:
					{
						for(int j=i;j<top;j++)
						{
							labor[j]=labor[j+1];
							top--;
						}
						cout<<"删除成功！"<<endl;
						break;
					}
				case 2:break;
				default:cout<<"输入错误！"<<endl;break;
				}
				break;
				
			}
			
			
		}
		if (i==top)
		{
			cout<<"查无此人"<<endl;
		}
		
	}
	return *this;
	
	
	
	
}
void labor_manage::edit()
{
	int a,i=0;
	search(1);
	i=locate;
	while(a!=0)
	{
		cout<<"| ****************************************** |"<<endl;
		cout<<"|                 【修改内容】               | "<<endl;
		cout<<"| -------------------------------------------|"<<endl;
		cout<<"|                 【1.职工号】               |"<<endl;
		cout<<"|                 【2.姓名】                 |"<<endl;
		cout<<"|                 【3.性别】                 |"<<endl;
		cout<<"|                 【4.年龄】                 |"<<endl;
		cout<<"|                 【5.政治面貌】             |"<<endl;
		cout<<"|                 【6.职务】                 |"<<endl;
		cout<<"|                 【0.退出】                 |"<<endl;
		cout<<"| ****************************************** | "<<endl;
		cout<<"请输入你的操作选项：";
		cin>>a;
		switch(a)
		{
		case 1:
			{
				cout<<"职工号不可修改。"<<endl;
				break;
			}
		case 2:
			{
				cout<<" 请输入修改后的实验员的姓名：";
				cin>>labor[i].name;
				break;
			}
		case 3:
			{
				cout<<"请输入修改后的实验员的性别：";
				cin>>labor[i].sex;
				break;
			}
		case 4:
			{
				cout<<"请输入修改后的实验员的年龄：";
				cin>>labor[i].age;
				break;
			}
		case 5:
			{
				cout<<"请输入修改后的实验员的实验室：";
				cin>>labor[i].lab;
				break;
			}
		case 6:
			{
				cout<<"请输入修改后的实验员的职务：";
				cin>>labor[i].duty;
				break;
			}
		}
		
	}
	
	
	
}
void labor_manage::add()
{
	int i;
	int b=0;
	teacher a;
	cout<<"新增实验员信息："<<endl;
	
	if (top==lmax)
	{
		cout<<"实验员已满，不可添加！"<<endl;
	}
	else
	{
		cout<<" ****************************************** "<<endl;
		cout<<"请输入实验员的职工号：";
		cin>>a.id;
		for(i=0;i<top;i++)
		{
			if(a.id==labor[i].id)
			{
				cout<<"该实验员的职工号已存在，请重新输入："<<endl;
				b=1;
				break;
			}
			
		}
		if (b==0)
		{
			labor[top].id=a.id;
			int a;
			cout<<"|      实验员的姓名：";
			cin>>labor[top].name;
			cout<<"|      实验员的性别:1:男 "<<endl;
			cout<<"|                   2:女 "<<endl;
			cout<<"|            请选择:";
			cin>>a;
			switch(a)
			{
			case 1:labor[top].sex="男";break;
			case 2:labor[top].sex="女";break;
			default:cout<<"|无此项，失败！自动匹配性别为：男。";
			}
			cout<<"|      实验员的年龄：";
			cin>>labor[top].age;
			cout<<"|      实验员的实验室:1:生物实验室"<<endl;
            cout<<"|                     2:化学实验室"<<endl;
			cout<<"|                     3:物理实验室"<<endl;
			cout<<"|                     4:机器人实验室"<<endl;
			cout<<"|                     5:其他"<<endl;
            cout<<"|              请选择:";
			cin>>a;
			switch(a)
			{
			case 1:labor[top].lab="生物实验室";break;
			case 2:labor[top].lab="化学实验室";break;
			case 3:labor[top].lab="物理实验室";break;
			case 4:labor[top].lab="机器人实验室";break;
			case 5:
				{
					cout<<"|         请输入:";
					cin>>labor[top].lab;
					break;
				}
			}
			
			cout<<"|      实验员的职务:1:实验室主任"<<endl;
			cout<<"|                   2:实验室主任助理"<<endl;
			cout<<"|                   3:实验室普通实验员"<<endl;
			cout<<"|                   4:其他"<<endl;
            cout<<"|              请选择:";
			cin>>a;
			switch(a)
			{
			case 1:labor[top].duty="实验室主任";break;
			case 2:labor[top].duty="实验室主任助理";break;
			case 3:labor[top].duty="实验室普通实验员";break;
			case 4:
				{
					cout<<"|         请输入:";
					cin>>labor[top].duty;
					break;
				}
			}
			
			cout<<" ****************************************** "<<endl;
			cout<<"添加成功！"<<endl;
			top++;
		}
		
	}
}
void labor_manage::show()
{
	int i;
	for(i=0;i<top;i++)
	{
		labor[i].output();
		cout<<" ****************************************** "<<endl;
	}
	
}
int labor_manage::total(int y=0)
{
	int c=0;
	int a;
	int i;
	if (y==0)
	{
		while(a!=0)
		{	cout<<"| ****************************************** |"<<endl;
		cout<<"|                 【统计内容】               | "<<endl;
		cout<<"| -------------------------------------------|"<<endl;
		cout<<"|                 【1.男女人数数量】         |"<<endl;
		cout<<"|                 【2.生物实验室人数】       |"<<endl;
		cout<<"|                 【3.化学实验室人数】       |"<<endl;
		cout<<"|                 【4.物理实验室人数】       |"<<endl;
		cout<<"|                 【5.机器人实验室人数】     |"<<endl;
		cout<<"|                 【0.退出】                 |"<<endl;
		cout<<"| ****************************************** | "<<endl;
		cout<<"|请输入你的操作选项:";
		cin>>a;
		switch(a)
		{
		case 1:
			{
				for(i=0;i<top;i++)
				{	
					if (labor[i].sex=="男")
					{
						c++;
					}
				}
				cout<<"| ****************************************** |"<<endl;
				cout<<"|        实验室人员一共"<<top<<"名             |"<<endl;
				cout<<"|        实验室人员有: "<<c<<"名男性         |"<<endl;
				cout<<"|        实验室人员有:"<<top-c<<"名女性          |"<<endl;
				cout<<"|****************************************** "<<endl;
				break;
			}
		case 2:
			{
				c=0;
				for(i=0;i<top;i++)
				{	
					if (labor[i].lab=="生物实验室")
					{
						c++;
					}
				}
				cout<<"|        生物实验室一共"<<c<<"名            |"<<endl;
				break;
			}
		case 3:
			{
				c=0;
				for(i=0;i<top;i++)
				{	
					if (labor[i].lab=="化学实验室")
					{
						c++;
					}
				}
				cout<<"|        化学实验室一共"<<c<<"名            |"<<endl;
				break;
			}
		case 4:
			{
				c=0;
				for(i=0;i<top;i++)
				{	
					if (labor[i].lab=="物理实验室")
					{
						c++;
					}
				}
				cout<<"|        物理实验室一共"<<c<<"名            |"<<endl;
				break;
			}
		case 5:
			{
				c=0;
				for(i=0;i<top;i++)
				{	
					if (labor[i].lab=="机器人实验室")
					{
						c++;
					}
				}
				cout<<"|        机器人实验室一共"<<c<<"名            |"<<endl;
				break;
			}
		}
		
		
		
	}
	} 
	else if(y==1)
	{
		for(i=0;i<top;i++)
		{	
			if (labor[i].sex=="男")
			{
				c++;
			}
		}
	}
	
	return c;
}
void labor_manage::search(int x=0)
{
	int a,i=0;
	string name;
	string id;
	if(top==0)
	{
		cout<<"没有任何数据"<<endl;
	}
	else
	{
		if (x==0)
		{
			cout<<"| ****************************************** |"<<endl;
			cout<<"|                 【查询方式】               | "<<endl;
			cout<<"| -------------------------------------------|"<<endl;
			cout<<"|                 【1.按姓名】               |"<<endl;
			cout<<"|                 【2.按职工号】             |"<<endl;
			cout<<"|                 【0.退出】                 |"<<endl;
			cout<<"| ****************************************** | "<<endl;
			cout<<"请输入你的操作选项：";
			cin>>a;
			switch(a)
			{
			case 1:
				{
					cout<<"请输入查询人员的姓名：";
					cin>>id;
					for(i=0;i<top;i++)
					{
						if(id==labor[i].name)
						{
							labor[i].output();
							locate=i;
							break;
						}
					}
					if (i==top)
					{
						cout<<"搜索无结果！"<<endl;
					}
					break;
				}
			case 2:
				{
					cout<<"请输入查询人员的职工号：";
					cin>>id;
					for(i=0;i<top;i++)
					{
						if(id==labor[i].id)
						{
							labor[i].output();
							locate=i;
							break;
						}
					}
					if (i==top)
					{
						cout<<"搜索无结果！"<<endl;
					}
					break;	
				}
				
			default:break;
			}
			
			
	
		} 
		else if(x==1)
		{
			cout<<"请输入查询人员的职工号：";
			cin>>id;
			for(i=0;i<top;i++)
			{
				if(id==labor[i].id)
				{
					labor[i].output();
					locate=i;
					break;
				}
			}
			if (i==top)
			{
				cout<<"搜索无结果！"<<endl;
					}
		}
	
	
	}
	
}
class ALL_manage
{
public:
	ALL_manage();
	void Add();
	void Search(int x);
	void Edit();
	int Total(int y);
	ALL_manage Delete();
	void Show();
	void Save();
    ALL_manage Read();

};


void ALL_manage::Add()
{
	labor_manage L;
	tea_manage B;
	Adm_manage A;
	A.read();
	B.Tread();
	L.read();
	int a;
	int c;
//	system("cls");
	time_t curtime;
	time(&curtime);
	cout<<"当前时间："<<ctime(&curtime)<<"            "<<endl;
	cout<<"|                 【 添加人员信息】          | "<<endl;
	cout<<"| ****************************************** | "<<endl;
	cout<<"|                 【1、教师管理】            |"<<endl;
	cout<<"|                 【2、实验员管理】          | "<<endl;
	cout<<"|                 【3、行政人员管理】        | "<<endl;
	cout<<"|                 【0、退出】                | "<<endl;
	cout<<"| ****************************************** | "<<endl;
	cout<<"请输入你的操作选项：";
	cin>>a;
	switch(a)
	{
	case 1:{
	    	B.Tadd();
		    cout<<"是否进行保存？"<<endl;
	    	cout<<"1:yes   0:no"<<endl;
			cin>>c;
	    	if (c==1)
			{
				B.Tsave();
		    	cout<<"添加成功！"<<endl;
			} 
			break;
		   }
	case 2:
		{
             L.add();
			 cout<<"是否进行保存？"<<endl;
			 cout<<"1:yes   0:no"<<endl;
			 cin>>c;
			 if (c==1)
			 {
				 L.save();
				 cout<<"添加成功！"<<endl;
			 } 
			 break;
		  
		}
	case 3:{
		        A.add();
				break;
		   }
		
	}
	

}
void Delete()
{
	labor_manage L;
	manage B;
	Adm_manage A;
	A.read();
	B.Tread();
	L.read();
	int a;
	system("cls");
	time_t curtime;
	time(&curtime);
	cout<<"当前时间："<<ctime(&curtime)<<"            "<<endl;
	cout<<"|                 【 删除人员信息】          | "<<endl;
	cout<<"| ****************************************** | "<<endl;
	cout<<"|                 【1、教师管理】            |"<<endl;
	cout<<"|                 【2、实验员管理】          | "<<endl;
	cout<<"|                 【3、行政人员管理】        | "<<endl;
	cout<<"|                 【0、退出】                | "<<endl;
	cout<<"| ****************************************** | "<<endl;
	cout<<"请输入你的操作选项：";
	cin>>a;
	switch(a)
	{
	case 1:B.TDelete();break;
	case 2:L.Delete();break;
		case 3:A.Delete();break;
		
	}
}
void Edit()
{
	labor_manage L;
	manage B;
	Adm_manage A;
	A.read();
	B.Tread();
	L.read();
	int a;
	system("cls");
	time_t curtime;
	time(&curtime);
	cout<<"当前时间："<<ctime(&curtime)<<"            "<<endl;
	cout<<"|                 【 修改人员信息】          | "<<endl;
	cout<<"| ****************************************** | "<<endl;
	cout<<"|                 【1、教师管理】            |"<<endl;
	cout<<"|                 【2、实验员管理】          | "<<endl;
	cout<<"|                 【3、行政人员管理】        | "<<endl;
	cout<<"|                 【0、退出】                | "<<endl;
	cout<<"| ****************************************** | "<<endl;
	cout<<"请输入你的操作选项：";
	cin>>a;
	switch(a)
	{
	case 1:B.Tedit();break;
	case 2:L.edit();break;
	case 3:A.edit();break;
		
	}
}
void Show()
{
	labor_manage L;
	manage B;
	Adm_manage A;
	A.read();
	B.Tread();
	L.read();
	int a;
	system("cls");
	while(a!=0)
	{
		time_t curtime;
		time(&curtime);
		cout<<"当前时间："<<ctime(&curtime)<<"            "<<endl;
		cout<<"|                 【 显示人员信息】          | "<<endl;
		cout<<"| ****************************************** | "<<endl;
		cout<<"|                 【1、教师管理】            |"<<endl;
		cout<<"|                 【2、实验员管理】          | "<<endl;
		cout<<"|                 【3、行政人员管理】        | "<<endl;
		cout<<"|                 【0、退出】                | "<<endl;
		cout<<"| ****************************************** | "<<endl;
		cout<<"请输入你的操作选项：";
        cin>>a;
		switch(a)
		{
		case 1:B.Tshow();break;
		case 2:L.show();break;
		case 3:A.show();break;
			
		}
		
	}

}
void Read()
{
	labor_manage L;
	manage B;
	Adm_manage A;
	A.read();
	B.Tread();
	L.read();

}
void Save()
{
	labor_manage L;
	manage B;
	Adm_manage A;
	A.save();
	B.Tsave();
	L.save();

}
void Search()
{
	labor_manage L;
	manage B;
	Adm_manage A;
	A.read();
	B.Tread();
	L.read();
	int a;
//	system("cls");
	while(a!=0)
	{
		time_t curtime;
		time(&curtime);
		cout<<"当前时间："<<ctime(&curtime)<<"            "<<endl;
		cout<<"|                 【 搜索人员信息】          | "<<endl;
		cout<<"| ****************************************** | "<<endl;
		cout<<"|                 【1、教师管理】            |"<<endl;
		cout<<"|                 【2、实验员管理】          | "<<endl;
		cout<<"|                 【3、行政人员管理】        | "<<endl;
		cout<<"|                 【0、退出】                | "<<endl;
		cout<<"| ****************************************** | "<<endl;
		cout<<"请输入你的操作选项：";
        cin>>a;
		switch(a)
		{
		case 1:B.Tsearch();break;
		case 2:L.search();break;
		case 3:A.search();break;
			
		}
		
	}

}
void ALL_total()
{
	int a;
	int b;
	labor_manage L;
	manage B;
	Adm_manage A;
	A.read();
	B.Tread();
	L.read();
	a=L.total(1)+B.Ttotal(1)+A.total(1);
    b=L.top+B.top+A.top;
	cout<<"| ****************************************** |"<<endl;
	cout<<"|               一共"<<b<<"名             |"<<endl;
	cout<<"|           其中有: "<<a<<"名男性         |"<<endl;
	cout<<"|               有:"<<b-a<<"名女性          |"<<endl;
	cout<<"|****************************************** "<<endl;

	
	
}
void Total()
{
	labor_manage L;
	manage B;
	Adm_manage A;
	A.read();
	B.Tread();
	L.read();
	int a;
	system("cls");
	while(a!=0)
	{
		time_t curtime;
		time(&curtime);
		cout<<"当前时间："<<ctime(&curtime)<<"            "<<endl;
		cout<<"| ****************************************** | "<<endl;
		cout<<"|                 【1、教师管理】            |"<<endl;
		cout<<"|                 【2、实验员管理】          | "<<endl;
		cout<<"|                 【3、行政人员管理】        | "<<endl;
		cout<<"|                 【4、全校人员统计】        | "<<endl;
		cout<<"|                 【0、退出】                | "<<endl;
		cout<<"| ****************************************** | "<<endl;
		cout<<"请输入你的操作选项：";
        cin>>a;
		switch(a)
		{
		case 1:B.Ttotal();break;
		case 2:L.total();break;
		case 3:A.total();break;
		case 4:ALL_total();break;	
		}
		
	}

}

void main()
{
	
	int a;
    ALL_manage A;
	while(a!=0)
	{
		system("cls");
		time_t curtime;
		time(&curtime);
		cout<<"当前时间："<<ctime(&curtime)<<"            "<<endl;
		cout<<"            【高校人员信息管理系统】          "<<endl;
		cout<<" *******************************************"<<endl;
		cout<<"|                 【1.添加】                 |"<<endl;
		cout<<"|                 【2.查找】                 | "<<endl;
		cout<<"|                 【3.编辑】                 |"<<endl;
		cout<<"|                 【4.统计】                 |"<<endl;
		cout<<"|                 【5.删除】                 |"<<endl;
		cout<<"|                 【6.显示】                 |"<<endl;
		cout<<"|                 【7.保存】                 |"<<endl;
		cout<<"|                 【8.读取】                 |"<<endl;
		cout<<"|                 【0.退出】                 |"<<endl;
    	cout<<" *******************************************"<<endl;
		cout<<"             请输入你的操作选项：";
		cin>>a;
		switch(a)
		{
		case 1:A.Add();break;
		case 2:A.Search();break;
		case 3:A.Edit();break;
		case 4:A.Total();break;
		case 5:A.Delete();break;
		case 6:A.Show();break;
		case 7:A.Save();break;
		case 8:A.Read();break;
		}
		
	}
	cout<<"             再见!                  "<<endl;

}
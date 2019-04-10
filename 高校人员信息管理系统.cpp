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
	cout<<"      ��ʦ��ְ����:"<<id<<endl;
	cout<<"      ��ʦ�������� "<<name<<endl;
	cout<<"      ��ʦ���Ա� "<<sex<<endl;
	cout<<"      ��ʦ�����䣺 "<<age<<endl;
	cout<<"      ��ʦ��ϵ���� "<<dept<<endl;
	cout<<"      ��ʦ��רҵ�� "<<specialty<<endl;
	cout<<"      ��ʦ��ְ�� "<<duty<<endl;
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
		cout<<"û���κ�����"<<endl;
	}
	else
	{
		cout<<"������Ҫɾ������Ա��ְ���ţ�";
		cin>>id;
		for(i=0;i<top;i++)
		{
			if(id==tea[i].id)
			{
				cout<<"----------------"<<endl;
				cout<<"|�Ƿ�ȷ��ɾ����|"<<endl;
				cout<<"|1:��    2:����|"<<endl;
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
						cout<<"ɾ���ɹ���"<<endl;
						break;
					}
				case 2:break;
				default:cout<<"�������"<<endl;break;
				}
				break;
				
			}
			
			
		}
		if (i==top)
		{
			cout<<"���޴���"<<endl;
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
	cout<<"������ʦ��Ա��Ϣ��"<<endl;
	
	if (top==tmax)
	{
		cout<<"������Ա������������ӣ�"<<endl;
	}
	else
	{
		cout<<" ****************************************** "<<endl;
		cout<<"�������ʦ��ְ���ţ�";
		cin>>a.id;
    	for(i=0;i<top;i++)
		{
		    if(a.id==tea[i].id)
			{
		    	cout<<"�ý�ʦ��Ա��ְ�����Ѵ��ڣ����������룺"<<endl;
				b=1;
		    	break;
			}
		
		}
		if (b==0)
		{
			tea[top].id=a.id;
			int a;
			int b;
			cout<<"|     ��ʦ��������";
			cin>>tea[top].name;
			cout<<"|     ��ʦ���Ա�:1:��"<<endl;
			cout<<"|                2:Ů"<<endl;
			cout<<"|         ��ѡ��: ";
			cin>>a;
			switch(a)
			{
			case 1:tea[top].sex="��";break;
			case 2:tea[top].sex="Ů";break;
			default:cout<<"�޴��ʧ�ܣ��Զ�ƥ���Ա�Ϊ���С�";
			}
			cout<<"|     ��ʦ�����䣺";
			cin>>tea[top].age;
			cout<<"|     ��ʦ��ϵ��: 1:�����ϵ"<<endl;
			cout<<"|                 2:����ϵ"<<endl;
			cout<<"|                 3:����ϵ"<<endl;
			cout<<"|                 4:��еϵ"<<endl;
			cout<<"|                 5:����ϵ"<<endl;
			cout<<"|                 6:����ϵ"<<endl;
			cout<<"|                 7:����"<<endl;
			cout<<"|          ��ѡ��:";
			cin>>a;
			switch(a)
			{
			case 1:
				{
					tea[top].dept="�����ϵ";
					cout<<"|     ��ʦ��רҵ: 1:�������"<<endl;
					cout<<"|                 2:���繤��"<<endl;
					cout<<"|                 3:����"<<endl;
					cout<<"|         ��ѡ��:";
					cin>>b;
					switch(b)
					{
					case 1:tea[top].specialty="�������";break;
					case 2:tea[top].specialty="���繤��";break;
					case 3:
						{
						  cout<<"|          ������:";
						  cin>>tea[top].specialty;
				       	  break;
						}
					}
					break;
				}
			case 2:
				{
					tea[top].dept="����ϵ";
					cout<<"|     ��ʦ��רҵ: 1:���Ӽ���"<<endl;
					cout<<"|                 2:��Ϣ��ȫ"<<endl;
					cout<<"|                 3:�������Ϣ��ѧ"<<endl;
					cout<<"|                 4:����"<<endl;
					cout<<"|         ��ѡ��:";
					cin>>b;
					switch(b)
					{
					case 1:tea[top].specialty="���Ӽ���";break;
					case 2:tea[top].specialty="��Ϣ��ȫ";break;
					case 3:tea[top].specialty="�������Ϣ��ѧ";break;
					case 4:
						{
							cout<<"|         ������:";
							cin>>tea[top].specialty;
							break;
						}
					}
					break;
				}
			case 3:
				{
					tea[top].dept="����ϵ";
					cout<<"|     ��ʦ��רҵ: 1:����ѧ"<<endl;
					cout<<"|                 2:���ѧ"<<endl;
					cout<<"|                 3:�г�Ӫ��"<<endl;
					cout<<"|                 4:������Դ����"<<endl;
					cout<<"|                 5:����"<<endl;
					cout<<"|         ��ѡ��:";
					cin>>b;
					switch(b)
					{
					case 1:tea[top].specialty="����ѧ";break;
					case 2:tea[top].specialty="���ѧ";break;
					case 3:tea[top].specialty="�г�Ӫ��";break;
					case 4:tea[top].specialty="������Դ����";break;
					case 5:
						{
							cout<<"|         ������:";
							cin>>tea[top].specialty;
							break;
						}
					}
					break;
				}
			case 4:
				{
					tea[top].dept="��еϵ";
					cout<<"|     ��ʦ��רҵ: 1:��е������켰���Զ���"<<endl;
					cout<<"|                 2:��ҵ���"<<endl;
					cout<<"|                 3:����"<<endl;
					cout<<"|         ��ѡ��:";
					cin>>b;
					switch(b)
					{
					case 1:tea[top].specialty="��е������켰���Զ���";break;
					case 2:tea[top].specialty="��ҵ���";break;
					case 3:
						{
							cout<<"|         ������:";
							cin>>tea[top].specialty;
							break;
						}
					}
					break;
				}
			case 5:
				{
					tea[top].dept="����ϵ";
					cout<<"|     ��ʦ��רҵ: 1:��ľ����"<<endl;
					cout<<"|                 2:ˮ������"<<endl;
					cout<<"|                 3:����"<<endl;
					cout<<"|         ��ѡ��:";
					cin>>b;
					switch(b)
					{
					case 1:tea[top].specialty="��ľ����";break;
					case 2:tea[top].specialty="ˮ������";break;
					case 3:
						{
							cout<<"|         ������:";
							cin>>tea[top].specialty;
							break;
						}
					}
					break;
				}
			case 6:
				{
					tea[top].dept="����ϵ";
					cout<<"|     ��ʦ��רҵ: 1:ʵ��Ӣ��רҵ"<<endl;
					cout<<"|                 2:������Ļ�Ӣ��רҵ"<<endl;
					cout<<"|                 3:����"<<endl;
					cout<<"|         ��ѡ��:";
					cin>>b;
					switch(b)
					{
					case 1:tea[top].specialty="ʵ��Ӣ��רҵ";break;
					case 2:tea[top].specialty="������Ļ�Ӣ��רҵ";break;
					case 3:
						{
							cout<<"|         ������:";
							cin>>tea[top].specialty;
							break;
						}
					}
			    	break;
				}
			case 7:
				{
					cin>>tea[top].dept;
					cout<<"|     ��ʦ��רҵ:";
					cin>>tea[top].specialty;
					break;
				}
			}	
			cout<<"      ��ʦ��ְ��";
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
		cout<<"|                 ��ͳ�����ݡ�               | "<<endl;
		cout<<"| -------------------------------------------|"<<endl;
		cout<<"|                 ��1.��Ů����������         |"<<endl;
		cout<<"|                 ��2.�����ϵ������         |"<<endl;
		cout<<"|                 ��3.����ϵ������           |"<<endl;
		cout<<"|                 ��4.����ϵ������           |"<<endl;
		cout<<"|                 ��5.��еϵ������           |"<<endl;
		cout<<"|                 ��6.����ϵ������           |"<<endl;
		cout<<"|                 ��7.����ϵ������           |"<<endl;
		cout<<"|                 ��0.�˳���                 |"<<endl;
		cout<<"| ****************************************** | "<<endl;
		cout<<"|��������Ĳ���ѡ��:";
		cin>>a;
		switch(a)
		{
		case 1:
			{
				for(i=0;i<top;i++)
				{	
					if (tea[i].sex=="��")
					{
						c++;
					}
				}
				cout<<"| ****************************************** |"<<endl;
				cout<<"|        ��ʦһ��"<<top<<"��               |"<<endl;
				cout<<"|        ��ʦ��: "<<c<<"������           |"<<endl;
				cout<<"|        ��ʦ��:"<<top-c<<"��Ů��            |"<<endl;
				cout<<"|****************************************** "<<endl;
				break;
			}
		case 2:
			{
				c=0;
				for(i=0;i<top;i++)
				{	
					if (tea[i].dept=="�����ϵ")
					{
						c++;
					}
				}
				cout<<"|        �����ϵ��ʦһ��"<<c<<"��           |"<<endl;
				break;
			}
		case 3:
			{
				c=0;
				for(i=0;i<top;i++)
				{	
					if (tea[i].dept=="����ϵ")
					{
						c++;
					}
				}
				cout<<"|        ����ϵ��ʦһ��"<<c<<"��           |"<<endl;
				break;
			}
		case 4:
			{
				c=0;
				for(i=0;i<top;i++)
				{	
					if (tea[i].dept=="����ϵ")
					{
						c++;
					}
				}
				cout<<"|        ����ϵ��ʦһ��"<<c<<"��           |"<<endl;
				break;
			}
		case 5:
			{
				c=0;
				for(i=0;i<top;i++)
				{	
					if (tea[i].dept=="��еϵ")
					{
						c++;
					}
				}
				cout<<"|        ��еϵ��ʦһ��"<<c<<"��           |"<<endl;
				break;
			}
		case 6:
			{
				c=0;
				for(i=0;i<top;i++)
				{	
					if (tea[i].dept=="����ϵ")
					{
						c++;
					}
				}
				cout<<"|        ����ϵ��ʦһ��"<<c<<"��           |"<<endl;
				break;
			}
		case 7:
			{
				c=0;
				for(i=0;i<top;i++)
				{	
					if (tea[i].dept=="����ϵ")
					{
						c++;
					}
				}
				cout<<"|        ����ϵ��ʦһ��"<<c<<"��           |"<<endl;
				break;
			}
		}
			
	
			
	}
	} 
	else if(y==1)
	{
		for(i=0;i<top;i++)
		{	
			if (tea[i].sex=="��")
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
		cout<<"û���κ�����"<<endl;
	}
	else
	{
		
		if (x==0)
		{
			cout<<"| ****************************************** |"<<endl;
		cout<<"|                 ����ѯ��ʽ��               | "<<endl;
		cout<<"| -------------------------------------------|"<<endl;
		cout<<"|                 ��1.�����֡�               |"<<endl;
		cout<<"|                 ��2.��ְ���š�             | "<<endl;
		cout<<"|                 ��0.�˳���                 |"<<endl;
		cout<<"| ****************************************** | "<<endl;
		cout<<"��������Ĳ���ѡ�";
		cin>>a;
		switch(a)
		{
		case 1:
			{
				cout<<"�������ѯ��Ա�����֣�";
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
					cout<<"�����޽����"<<endl;
				}
				break;
			}
		case 2:
			{
				cout<<"�������ѯ��Ա��ְ���ţ�";
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
					cout<<"�����޽����"<<endl;
				}
				break;	
			}
		default:break;
			}
		} 
		else if(x==1)
		{
			cout<<"�������ѯ��Ա��ְ���ţ�";
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
				cout<<"�����޽����"<<endl;
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
		cout<<"|                 ���޸����ݡ�               | "<<endl;
		cout<<"| -------------------------------------------|"<<endl;
		cout<<"|                 ��1.ְ���š�               |"<<endl;
		cout<<"|                 ��2.������                 |"<<endl;
		cout<<"|                 ��3.�Ա�                 |"<<endl;
		cout<<"|                 ��4.���䡿                 |"<<endl;
		cout<<"|                 ��5.ϵ����                 |"<<endl;
		cout<<"|                 ��6.רҵ��                 |"<<endl;
		cout<<"|                 ��7.ְ��                 |"<<endl;
		cout<<"|                 ��0.�˳���                 |"<<endl;
		cout<<"| ****************************************** | "<<endl;
		cout<<"��������Ĳ���ѡ�";
		cin>>a;
		switch(a)
		{
		case 1:
			{
				cout<<"ְ���Ų����޸ġ�"<<endl;
				break;
			}
		case 2:
			{
				cout<<" �������޸ĺ�Ľ�ʦ��������";
				cin>>tea[i].name;
			
				break;
			}
		case 3:
			{
				cout<<"�������޸ĺ�Ľ�ʦ���Ա�";
				cin>>tea[i].sex;
		    	break;
			}
		case 4:
			{
				cout<<"�������޸ĺ�Ľ�ʦ�����䣺";
				cin>>tea[i].age;
		    	break;
			}
		case 5:
			{
				cout<<"�������޸ĺ�� ��ʦ��ϵ����";
				cin>>tea[i].dept;
			  break;
			}
		case 6:
			{
				cout<<"�������޸ĺ�Ľ�ʦ��רҵ��";
				cin>>tea[i].specialty;
				break;
			}
		case 7:
			{
				cout<<"�������޸ĺ�Ľ�ʦ��ְ��";
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
		cout<<"��ʧ�ܣ�"<<endl;

	} 
	else
	{
        cout<<"�򿪳ɹ���"<<endl;
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
	cout<<"      ������Ա��ְ����:"<<id<<endl;
	cout<<"      ������Ա�������� "<<name<<endl;
	cout<<"      ������Ա���Ա� "<<sex<<endl;
	cout<<"      ������Ա�����䣺 "<<age<<endl;
	cout<<"      ������Ա��������ò�� "<<political<<endl;
	cout<<"      ������Ա��ְ�� "<<duty<<endl;
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
		cout<<"��ʧ�ܣ�"<<endl;
		
	} 
	else
	{
        cout<<"�򿪳ɹ���"<<endl;
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
		cout<<"û���κ�����"<<endl;
	}
	else
	{
		cout<<"������Ҫɾ������Ա��ְ���ţ�";
		cin>>id;
		for(i=0;i<top;i++)
		{
			if(id==adm[i].id)
			{
				cout<<"----------------"<<endl;
				cout<<"|�Ƿ�ȷ��ɾ����|"<<endl;
				cout<<"|1:��    2:����|"<<endl;
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
						cout<<"ɾ���ɹ���"<<endl;
						break;
					}
				case 2:break;
				default:cout<<"�������"<<endl;break;
				}
				break;
				
			}
			
		
		}
		if (i==top)
		{
			cout<<"���޴���"<<endl;
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
		cout<<"|                 ���޸����ݡ�               | "<<endl;
		cout<<"| -------------------------------------------|"<<endl;
		cout<<"|                 ��1.ְ���š�               |"<<endl;
		cout<<"|                 ��2.������                 |"<<endl;
		cout<<"|                 ��3.�Ա�                 |"<<endl;
		cout<<"|                 ��4.���䡿                 |"<<endl;
		cout<<"|                 ��5.������ò��             |"<<endl;
		cout<<"|                 ��6.ְ��                 |"<<endl;
		cout<<"|                 ��0.�˳���                 |"<<endl;
		cout<<"| ****************************************** | "<<endl;
		cout<<"��������Ĳ���ѡ�";
		cin>>a;
		switch(a)
		{
		case 1:
			{
				cout<<"ְ���Ų����޸ġ�"<<endl;
				break;
			}
		case 2:
			{
				cout<<" �������޸ĺ��������Ա��������";
				cin>>adm[i].name;
				break;
			}
		case 3:
			{
				cout<<"�������޸ĺ��������Ա���Ա�";
				cin>>adm[i].sex;
				break;
			}
		case 4:
			{
				cout<<"�������޸ĺ��������Ա�����䣺";
				cin>>adm[i].age;
				break;
			}
		case 5:
			{
				cout<<"�������޸ĺ��������Ա��רҵ��";
				cin>>adm[i].political;
				break;
			}
		case 6:
			{
				cout<<"�������޸ĺ��������Ա��ְ��";
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
	cout<<"����������Ա��Ϣ��"<<endl;
	
	if (top==amax)
	{
		cout<<"������Ա������������ӣ�"<<endl;
	}
	else
	{
		cout<<" ****************************************** "<<endl;
		cout<<"������������Ա��ְ���ţ�";
		cin>>a.id;
		for(i=0;i<top;i++)
		{
			if(a.id==adm[i].id)
			{
				cout<<"��������Ա��ְ�����Ѵ��ڣ����������룺"<<endl;
				b=1;
				break;
			}
			
		}
		if (b==0)
		{
			adm[top].id=a.id;
			cout<<"|     ������Ա��������";
			cin>>adm[top].name;
			cout<<"|     ������Ա���Ա�:1:�� "<<endl;
			cout<<"                     2:Ů "<<endl;
			cout<<"              ��ѡ��:";
			cin>>c;
			switch(c)
			{
			case 1:adm[top].sex="��";break;
			case 2:adm[top].sex="Ů";break;
			default:cout<<"�޴��ʧ�ܣ��Զ�ƥ���Ա�Ϊ���С�";
			}
			cout<<"|      ������Ա�����䣺";
			cin>>adm[top].age;
			cout<<"|      ������Ա��������ò:1:������Ա"<<endl;
			cout<<"|                         2:�й���Ա"<<endl;
			cout<<"|                         3:Ⱥ��"<<endl;
			cout<<"|                         4:����"<<endl;
			cout<<"|          ��ѡ��:";
			cin>>c;
			switch(c)
			{
			case 1:adm[top].political="������Ա";break;
			case 2:adm[top].political="�й���Ա";break;
			case 3:adm[top].political="Ⱥ��";break;
			case 4:
				{
					cout<<"|         ������:";
					cin>>adm[top].political;
					break;
				}
			}
        	cout<<"|      ������Ա��ְ��:1:�����칫��"<<endl;
			cout<<"|                     2:ѧ��������"<<endl;
			cout<<"|                     3:��ί�칫��"<<endl;
			cout<<"|                     4:����"<<endl;
			cout<<"|                     5:ѧ����"<<endl;
			cout<<"|                     6:����"<<endl;
			cout<<"|                     7:����"<<endl;
			cout<<"|          ��ѡ��:";
			cin>>c;
			switch(c)
			{
			case 1:adm[top].duty="�����칫��";break;
			case 2:adm[top].duty="ѧ��������";break;
			case 3:adm[top].duty="��ί�칫��";break;
			case 4:adm[top].duty="����";break;
			case 5:adm[top].duty="ѧ����";break;
			case 6:adm[top].duty="����";break;
			case 7:
				{
					cout<<"|         ������:";
					cin>>adm[top].duty;
					break;
				}
			}
			
			cout<<" ****************************************** "<<endl;
			cout<<"��ӳɹ���"<<endl;
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
		cout<<"|                 ��ͳ�����ݡ�               | "<<endl;
		cout<<"| -------------------------------------------|"<<endl;
		cout<<"|                 ��1.��Ů����������         |"<<endl;
		cout<<"|                 ��2.������Ա������         |"<<endl;
		cout<<"|                 ��3.�й���Ա������         |"<<endl;
		cout<<"|                 ��4.Ⱥ��������             |"<<endl;
		cout<<"|                 ��0.�˳���                 |"<<endl;
		cout<<"| ****************************************** | "<<endl;
		cout<<"|��������Ĳ���ѡ��:";
		cin>>a;
		switch(a)
		{
		case 1:
			{
				for(i=0;i<top;i++)
				{	
					if (adm[i].sex=="��")
					{
						c++;
					}
				}
				cout<<"| ****************************************** |"<<endl;
				cout<<"|        ������Աһ��"<<top<<"��             |"<<endl;
				cout<<"|        ������Ա��: "<<c<<"������         |"<<endl;
				cout<<"|        ������Ա��:"<<top-c<<"��Ů��          |"<<endl;
				cout<<"|****************************************** "<<endl;
				break;
			}
		case 2:
			{
				c=0;
				for(i=0;i<top;i++)
				{	
					if (adm[i].political=="������Ա")
					{
						c++;
					}
				}
				cout<<"|        ������Աһ��"<<c<<"��            |"<<endl;
				break;
			}
		case 3:
			{
				c=0;
				for(i=0;i<top;i++)
				{	
					if (adm[i].political=="�й���Ա")
					{
						c++;
					}
				}
				cout<<"|        �й���Աһ��"<<c<<"��            |"<<endl;
				break;
			}
		case 4:
			{
				c=0;
				for(i=0;i<top;i++)
				{	
					if (adm[i].political=="Ⱥ��")
					{
						c++;
					}
				}
				cout<<"|        Ⱥ��һ��"<<c<<"��               |"<<endl;
				break;
			}
			
		}
		
		
		
	}
	} 
	else if(y==1)
	{
		for(i=0;i<top;i++)
		{	
			if (adm[i].sex=="��")
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
		cout<<"û���κ�����"<<endl;
		
	}
	else
	{
		if (x==0)
		{
			cout<<"| ****************************************** |"<<endl;
			cout<<"|                 ����ѯ��ʽ��               | "<<endl;
			cout<<"| -------------------------------------------|"<<endl;
			cout<<"|                 ��1.��������               |"<<endl;
			cout<<"|                 ��2.��ְ���š�             |"<<endl;
			cout<<"|                 ��0.�˳���                 |"<<endl;
			cout<<"| ****************************************** | "<<endl;
			cout<<"��������Ĳ���ѡ�";
			cin>>a;
			switch(a)
			{
				
				
			case 1:
				{
					cout<<"�������ѯ��Ա�����֣�";
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
						cout<<"�����޽����"<<endl;
					}
					break;
					
				}
			case 2:
				{
					cout<<"�������ѯ��Ա��ְ���ţ�";
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
						cout<<"�����޽����"<<endl;
					}
					break;	
				}
			default:break;
				
	}

		} 
		else if(x==1)
		{
			cout<<"�������ѯ��Ա��ְ���ţ�";
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
				cout<<"�����޽����"<<endl;
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
	cout<<"      ʵ��Ա��ְ����:"<<id<<endl;
	cout<<"      ʵ��Ա�������� "<<name<<endl;
	cout<<"      ʵ��Ա���Ա� "<<sex<<endl;
	cout<<"      ʵ��Ա�����䣺 "<<age<<endl;
	cout<<"      ʵ��Ա��ʵ���ң� "<<lab<<endl;
	cout<<"      ʵ��Ա��ְ�� "<<duty<<endl;
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
		cout<<"��ʧ�ܣ�"<<endl;
		
	} 
	else
	{
        cout<<"�򿪳ɹ���"<<endl;
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
		cout<<"û���κ�����"<<endl;
	}
	else
	{
		cout<<"������Ҫɾ������Ա��ְ���ţ�";
		cin>>id;
		for(i=0;i<top;i++)
		{
			if(id==labor[i].id)
			{
				cout<<"----------------"<<endl;
				cout<<"|�Ƿ�ȷ��ɾ����|"<<endl;
				cout<<"|1:��    2:����|"<<endl;
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
						cout<<"ɾ���ɹ���"<<endl;
						break;
					}
				case 2:break;
				default:cout<<"�������"<<endl;break;
				}
				break;
				
			}
			
			
		}
		if (i==top)
		{
			cout<<"���޴���"<<endl;
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
		cout<<"|                 ���޸����ݡ�               | "<<endl;
		cout<<"| -------------------------------------------|"<<endl;
		cout<<"|                 ��1.ְ���š�               |"<<endl;
		cout<<"|                 ��2.������                 |"<<endl;
		cout<<"|                 ��3.�Ա�                 |"<<endl;
		cout<<"|                 ��4.���䡿                 |"<<endl;
		cout<<"|                 ��5.������ò��             |"<<endl;
		cout<<"|                 ��6.ְ��                 |"<<endl;
		cout<<"|                 ��0.�˳���                 |"<<endl;
		cout<<"| ****************************************** | "<<endl;
		cout<<"��������Ĳ���ѡ�";
		cin>>a;
		switch(a)
		{
		case 1:
			{
				cout<<"ְ���Ų����޸ġ�"<<endl;
				break;
			}
		case 2:
			{
				cout<<" �������޸ĺ��ʵ��Ա��������";
				cin>>labor[i].name;
				break;
			}
		case 3:
			{
				cout<<"�������޸ĺ��ʵ��Ա���Ա�";
				cin>>labor[i].sex;
				break;
			}
		case 4:
			{
				cout<<"�������޸ĺ��ʵ��Ա�����䣺";
				cin>>labor[i].age;
				break;
			}
		case 5:
			{
				cout<<"�������޸ĺ��ʵ��Ա��ʵ���ң�";
				cin>>labor[i].lab;
				break;
			}
		case 6:
			{
				cout<<"�������޸ĺ��ʵ��Ա��ְ��";
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
	cout<<"����ʵ��Ա��Ϣ��"<<endl;
	
	if (top==lmax)
	{
		cout<<"ʵ��Ա������������ӣ�"<<endl;
	}
	else
	{
		cout<<" ****************************************** "<<endl;
		cout<<"������ʵ��Ա��ְ���ţ�";
		cin>>a.id;
		for(i=0;i<top;i++)
		{
			if(a.id==labor[i].id)
			{
				cout<<"��ʵ��Ա��ְ�����Ѵ��ڣ����������룺"<<endl;
				b=1;
				break;
			}
			
		}
		if (b==0)
		{
			labor[top].id=a.id;
			int a;
			cout<<"|      ʵ��Ա��������";
			cin>>labor[top].name;
			cout<<"|      ʵ��Ա���Ա�:1:�� "<<endl;
			cout<<"|                   2:Ů "<<endl;
			cout<<"|            ��ѡ��:";
			cin>>a;
			switch(a)
			{
			case 1:labor[top].sex="��";break;
			case 2:labor[top].sex="Ů";break;
			default:cout<<"|�޴��ʧ�ܣ��Զ�ƥ���Ա�Ϊ���С�";
			}
			cout<<"|      ʵ��Ա�����䣺";
			cin>>labor[top].age;
			cout<<"|      ʵ��Ա��ʵ����:1:����ʵ����"<<endl;
            cout<<"|                     2:��ѧʵ����"<<endl;
			cout<<"|                     3:����ʵ����"<<endl;
			cout<<"|                     4:������ʵ����"<<endl;
			cout<<"|                     5:����"<<endl;
            cout<<"|              ��ѡ��:";
			cin>>a;
			switch(a)
			{
			case 1:labor[top].lab="����ʵ����";break;
			case 2:labor[top].lab="��ѧʵ����";break;
			case 3:labor[top].lab="����ʵ����";break;
			case 4:labor[top].lab="������ʵ����";break;
			case 5:
				{
					cout<<"|         ������:";
					cin>>labor[top].lab;
					break;
				}
			}
			
			cout<<"|      ʵ��Ա��ְ��:1:ʵ��������"<<endl;
			cout<<"|                   2:ʵ������������"<<endl;
			cout<<"|                   3:ʵ������ͨʵ��Ա"<<endl;
			cout<<"|                   4:����"<<endl;
            cout<<"|              ��ѡ��:";
			cin>>a;
			switch(a)
			{
			case 1:labor[top].duty="ʵ��������";break;
			case 2:labor[top].duty="ʵ������������";break;
			case 3:labor[top].duty="ʵ������ͨʵ��Ա";break;
			case 4:
				{
					cout<<"|         ������:";
					cin>>labor[top].duty;
					break;
				}
			}
			
			cout<<" ****************************************** "<<endl;
			cout<<"��ӳɹ���"<<endl;
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
		cout<<"|                 ��ͳ�����ݡ�               | "<<endl;
		cout<<"| -------------------------------------------|"<<endl;
		cout<<"|                 ��1.��Ů����������         |"<<endl;
		cout<<"|                 ��2.����ʵ����������       |"<<endl;
		cout<<"|                 ��3.��ѧʵ����������       |"<<endl;
		cout<<"|                 ��4.����ʵ����������       |"<<endl;
		cout<<"|                 ��5.������ʵ����������     |"<<endl;
		cout<<"|                 ��0.�˳���                 |"<<endl;
		cout<<"| ****************************************** | "<<endl;
		cout<<"|��������Ĳ���ѡ��:";
		cin>>a;
		switch(a)
		{
		case 1:
			{
				for(i=0;i<top;i++)
				{	
					if (labor[i].sex=="��")
					{
						c++;
					}
				}
				cout<<"| ****************************************** |"<<endl;
				cout<<"|        ʵ������Աһ��"<<top<<"��             |"<<endl;
				cout<<"|        ʵ������Ա��: "<<c<<"������         |"<<endl;
				cout<<"|        ʵ������Ա��:"<<top-c<<"��Ů��          |"<<endl;
				cout<<"|****************************************** "<<endl;
				break;
			}
		case 2:
			{
				c=0;
				for(i=0;i<top;i++)
				{	
					if (labor[i].lab=="����ʵ����")
					{
						c++;
					}
				}
				cout<<"|        ����ʵ����һ��"<<c<<"��            |"<<endl;
				break;
			}
		case 3:
			{
				c=0;
				for(i=0;i<top;i++)
				{	
					if (labor[i].lab=="��ѧʵ����")
					{
						c++;
					}
				}
				cout<<"|        ��ѧʵ����һ��"<<c<<"��            |"<<endl;
				break;
			}
		case 4:
			{
				c=0;
				for(i=0;i<top;i++)
				{	
					if (labor[i].lab=="����ʵ����")
					{
						c++;
					}
				}
				cout<<"|        ����ʵ����һ��"<<c<<"��            |"<<endl;
				break;
			}
		case 5:
			{
				c=0;
				for(i=0;i<top;i++)
				{	
					if (labor[i].lab=="������ʵ����")
					{
						c++;
					}
				}
				cout<<"|        ������ʵ����һ��"<<c<<"��            |"<<endl;
				break;
			}
		}
		
		
		
	}
	} 
	else if(y==1)
	{
		for(i=0;i<top;i++)
		{	
			if (labor[i].sex=="��")
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
		cout<<"û���κ�����"<<endl;
	}
	else
	{
		if (x==0)
		{
			cout<<"| ****************************************** |"<<endl;
			cout<<"|                 ����ѯ��ʽ��               | "<<endl;
			cout<<"| -------------------------------------------|"<<endl;
			cout<<"|                 ��1.��������               |"<<endl;
			cout<<"|                 ��2.��ְ���š�             |"<<endl;
			cout<<"|                 ��0.�˳���                 |"<<endl;
			cout<<"| ****************************************** | "<<endl;
			cout<<"��������Ĳ���ѡ�";
			cin>>a;
			switch(a)
			{
			case 1:
				{
					cout<<"�������ѯ��Ա��������";
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
						cout<<"�����޽����"<<endl;
					}
					break;
				}
			case 2:
				{
					cout<<"�������ѯ��Ա��ְ���ţ�";
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
						cout<<"�����޽����"<<endl;
					}
					break;	
				}
				
			default:break;
			}
			
			
	
		} 
		else if(x==1)
		{
			cout<<"�������ѯ��Ա��ְ���ţ�";
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
				cout<<"�����޽����"<<endl;
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
	cout<<"��ǰʱ�䣺"<<ctime(&curtime)<<"            "<<endl;
	cout<<"|                 �� �����Ա��Ϣ��          | "<<endl;
	cout<<"| ****************************************** | "<<endl;
	cout<<"|                 ��1����ʦ����            |"<<endl;
	cout<<"|                 ��2��ʵ��Ա����          | "<<endl;
	cout<<"|                 ��3��������Ա����        | "<<endl;
	cout<<"|                 ��0���˳���                | "<<endl;
	cout<<"| ****************************************** | "<<endl;
	cout<<"��������Ĳ���ѡ�";
	cin>>a;
	switch(a)
	{
	case 1:{
	    	B.Tadd();
		    cout<<"�Ƿ���б��棿"<<endl;
	    	cout<<"1:yes   0:no"<<endl;
			cin>>c;
	    	if (c==1)
			{
				B.Tsave();
		    	cout<<"��ӳɹ���"<<endl;
			} 
			break;
		   }
	case 2:
		{
             L.add();
			 cout<<"�Ƿ���б��棿"<<endl;
			 cout<<"1:yes   0:no"<<endl;
			 cin>>c;
			 if (c==1)
			 {
				 L.save();
				 cout<<"��ӳɹ���"<<endl;
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
	cout<<"��ǰʱ�䣺"<<ctime(&curtime)<<"            "<<endl;
	cout<<"|                 �� ɾ����Ա��Ϣ��          | "<<endl;
	cout<<"| ****************************************** | "<<endl;
	cout<<"|                 ��1����ʦ����            |"<<endl;
	cout<<"|                 ��2��ʵ��Ա����          | "<<endl;
	cout<<"|                 ��3��������Ա����        | "<<endl;
	cout<<"|                 ��0���˳���                | "<<endl;
	cout<<"| ****************************************** | "<<endl;
	cout<<"��������Ĳ���ѡ�";
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
	cout<<"��ǰʱ�䣺"<<ctime(&curtime)<<"            "<<endl;
	cout<<"|                 �� �޸���Ա��Ϣ��          | "<<endl;
	cout<<"| ****************************************** | "<<endl;
	cout<<"|                 ��1����ʦ����            |"<<endl;
	cout<<"|                 ��2��ʵ��Ա����          | "<<endl;
	cout<<"|                 ��3��������Ա����        | "<<endl;
	cout<<"|                 ��0���˳���                | "<<endl;
	cout<<"| ****************************************** | "<<endl;
	cout<<"��������Ĳ���ѡ�";
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
		cout<<"��ǰʱ�䣺"<<ctime(&curtime)<<"            "<<endl;
		cout<<"|                 �� ��ʾ��Ա��Ϣ��          | "<<endl;
		cout<<"| ****************************************** | "<<endl;
		cout<<"|                 ��1����ʦ����            |"<<endl;
		cout<<"|                 ��2��ʵ��Ա����          | "<<endl;
		cout<<"|                 ��3��������Ա����        | "<<endl;
		cout<<"|                 ��0���˳���                | "<<endl;
		cout<<"| ****************************************** | "<<endl;
		cout<<"��������Ĳ���ѡ�";
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
		cout<<"��ǰʱ�䣺"<<ctime(&curtime)<<"            "<<endl;
		cout<<"|                 �� ������Ա��Ϣ��          | "<<endl;
		cout<<"| ****************************************** | "<<endl;
		cout<<"|                 ��1����ʦ����            |"<<endl;
		cout<<"|                 ��2��ʵ��Ա����          | "<<endl;
		cout<<"|                 ��3��������Ա����        | "<<endl;
		cout<<"|                 ��0���˳���                | "<<endl;
		cout<<"| ****************************************** | "<<endl;
		cout<<"��������Ĳ���ѡ�";
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
	cout<<"|               һ��"<<b<<"��             |"<<endl;
	cout<<"|           ������: "<<a<<"������         |"<<endl;
	cout<<"|               ��:"<<b-a<<"��Ů��          |"<<endl;
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
		cout<<"��ǰʱ�䣺"<<ctime(&curtime)<<"            "<<endl;
		cout<<"| ****************************************** | "<<endl;
		cout<<"|                 ��1����ʦ����            |"<<endl;
		cout<<"|                 ��2��ʵ��Ա����          | "<<endl;
		cout<<"|                 ��3��������Ա����        | "<<endl;
		cout<<"|                 ��4��ȫУ��Աͳ�ơ�        | "<<endl;
		cout<<"|                 ��0���˳���                | "<<endl;
		cout<<"| ****************************************** | "<<endl;
		cout<<"��������Ĳ���ѡ�";
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
		cout<<"��ǰʱ�䣺"<<ctime(&curtime)<<"            "<<endl;
		cout<<"            ����У��Ա��Ϣ����ϵͳ��          "<<endl;
		cout<<" *******************************************"<<endl;
		cout<<"|                 ��1.��ӡ�                 |"<<endl;
		cout<<"|                 ��2.���ҡ�                 | "<<endl;
		cout<<"|                 ��3.�༭��                 |"<<endl;
		cout<<"|                 ��4.ͳ�ơ�                 |"<<endl;
		cout<<"|                 ��5.ɾ����                 |"<<endl;
		cout<<"|                 ��6.��ʾ��                 |"<<endl;
		cout<<"|                 ��7.���桿                 |"<<endl;
		cout<<"|                 ��8.��ȡ��                 |"<<endl;
		cout<<"|                 ��0.�˳���                 |"<<endl;
    	cout<<" *******************************************"<<endl;
		cout<<"             ��������Ĳ���ѡ�";
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
	cout<<"             �ټ�!                  "<<endl;

}
#include<iostream>
#include<cstring>

const int Maxsize = 120;

int ct = 0; //建立哈希表是的冲突次数 

int judge; 

using namespace std;

struct tel
{
	char name[20];
	char num[12];
	char add[20];
	int conftime;
	char sign; 
};

struct Hash
{
	tel *data;
};

Hash Hashtab[Maxsize];


int Getkey_num(char str[]) 
{
	int len = strlen(str);
	int key = 0;

	for (int i = 0; i < len; i++)
	{
		key = key + str[i] - '0';
	}

	return key % Maxsize;
}

int Getkey_name(char str[])
{
	int len = strlen(str);
	int key;

	key = str[0]  + str[len - 1];
	
	return key % Maxsize;
}

void Menu()
{
	cout << endl;
	cout << "               -----------菜  单----------" << endl;
	cout << "               ---------------------------" << endl;
	cout << "               |        1. 添加          |" << endl;
	cout << "               |        2. 删除          |" << endl;
	cout << "               |        3. 查找          |" << endl;
	cout << "               |        4. 浏览          |" << endl;
	cout << "               |        5.平均查找长度   |" << endl;
	cout << "               |        6.退出           |" << endl; 
	cout << "               ---------------------------" << endl;
	cout << endl;
}


void Hashtable(tel t, int n)
{
	int key;
	
	if(n == 1)
	{
		key = Getkey_name(t.name);
	}
	else if(n == 2)
	{
		key = Getkey_num(t.num);
	}
	
	while (Hashtab[key].data)
	{ 
		key = (key + 1) % Maxsize;
		ct++;
	} 
	Hashtab[key].data = new tel;

	strcpy(Hashtab[key].data->name, t.name);
	strcpy(Hashtab[key].data->num, t.num);
	strcpy(Hashtab[key].data->add, t.add);
	Hashtab[key].data->conftime = ct;
	if(judge == true)
	{
		Hashtab[key].data->sign = '1';
	}
}

void Delete(char str[], int n)
{
	int key;
	
	if(n == 1)
	{
		key = Getkey_name(str);
		
		if (!Hashtab[key].data)
		{	
			cout << "查无此人!" << endl;
			return;
		}
	
		if (strcmp(str, Hashtab[key].data->name) == 0)
		{
			cout << "删除成功!" << endl;
			cout << Hashtab[key].data->name << " " << Hashtab[key].data->num << " " << Hashtab[key].data->add << endl;
			delete Hashtab[key].data;
			Hashtab[key].data = NULL;
			return;
		}
		else
		{
			key = (key + 1) % Maxsize;
	
			while (Hashtab[key].data != NULL && Getkey_name(str) != key)
			{
				if (strcmp(str, Hashtab[key].data->name) == 0)
				{
					cout << "删除成功!" << endl;
					cout << Hashtab[key].data->name << " " << Hashtab[key].data->num << " " << Hashtab[key].data->add << endl;
					delete Hashtab[key].data;
					Hashtab[key].data = NULL;
					
					return ;
				}
				else
				{
					key = (key + 1) % Maxsize;
				}
			}
		}	
	}
	
	else if(n == 2)
	{
		key = Getkey_num(str);
		
		if (!Hashtab[key].data)
		{	
			cout << "查无此号!" << endl;
			return;
		}
	
		else if (strcmp(str, Hashtab[key].data->num) == 0)
		{
			cout << "删除成功!" << endl;
			cout << Hashtab[key].data->name << " " << Hashtab[key].data->num << " " << Hashtab[key].data->add << endl;
			delete Hashtab[key].data;
			Hashtab[key].data = NULL;
			return;
		}
		else
		{
			key = (key + 1) % Maxsize;
	
			while (Hashtab[key].data != NULL && Getkey_num(str) != key)
			{
				if (strcmp(str, Hashtab[key].data->num) == 0)
				{
					cout << "删除成功!" << endl;
					cout << Hashtab[key].data->name << " " << Hashtab[key].data->num << " " << Hashtab[key].data->add << endl;
					delete Hashtab[key].data;
					Hashtab[key].data = NULL;
					return;
				}
				else
				{
					key = (key + 1) % Maxsize;
				}
			}
		}
		
	}
	
}

int cnt = 1;
char S[30];

int Hashfind(char *str, int n)  
{
	int key;
	
	if(n == 1)
	{
		key = Getkey_name(str);
		if (Hashtab[key].data == NULL)
		{
			strcpy(S, "查无此人!");
			return 0;
		}
		if (strcmp(str, Hashtab[key].data->name) == 0 && Hashtab[key].data->sign != '1')
		{
			cout<<".";
			cout << Hashtab[key].data->name << " " << Hashtab[key].data->num << " " << Hashtab[key].data->add << endl;
			strcpy(S, "查找成功!");
			return 1;
		}
		else if(strcmp(str, Hashtab[key].data->name) == 0 && Hashtab[key].data->sign == '1')
		{
			cout<<"...";
			cout << Hashtab[key].data->name << " " << Hashtab[key].data->num << " " << Hashtab[key].data->add << endl;
			strcpy(S, "查找成功!");
			return 1;
		}
		else
		{
			key = (key + 1) % Maxsize;
			cnt++;
	
			while (Hashtab[key].data != NULL&& Getkey_name(str) != key)
			{
				if (strcmp(str, Hashtab[key].data->name) == 0 && Hashtab[key].data->sign != '1')
				{
					cout << Hashtab[key].data->name << " " << Hashtab[key].data->num << " " << Hashtab[key].data->add << endl;
					strcpy(S, "查找成功!");
					return 1;
				}
				else if(strcmp(str, Hashtab[key].data->name) == 0 && Hashtab[key].data->sign == '1')
				{
					cout << Hashtab[key].data->name << " " << Hashtab[key].data->num << " " << Hashtab[key].data->add << endl;
					strcpy(S, "查找成功!");
					cnt++;
					key = (key+ 1) % Maxsize;
					return 1;
				}
			}
		}
		
		strcpy(S, "查无此人!");
		return 0;
	}
	
	else if(n == 2)
	{
		key = Getkey_num(str);
		
		if (Hashtab[key].data == NULL)
		{
			strcpy(S, "查无此号!");
			return 0;
		}
		
		if(strcmp(str, Hashtab[key].data->num) == 0)
		{
			cout << Hashtab[key].data->name << " " << Hashtab[key].data->num << " " << Hashtab[key].data->add << endl;
			strcpy(S, "查找成功！");
			return 1;
		}
		else
		{
			key = (key + 1) % Maxsize;
			cnt++;
	
			while (Hashtab[key].data != NULL&& Getkey_num(str) != key)
			{
				if (strcmp(str, Hashtab[key].data->num) == 0)
				{
					strcpy(S, "查找成功!");
					cout << Hashtab[key].data->name << " " << Hashtab[key].data->num << " " << Hashtab[key].data->add << endl;
					return 1;
				}
				else
				{
					cnt++;
					key = (key+ 1) % Maxsize;
				}
			}
		}
		
		strcpy(S, "查无此号!");
		return 0;
	}
}


void Add(int n)
{
	char s[20];

	cout << "请输入:" << endl;
	tel t;
	cin >> t.name >> t.num >> t.add;
	
	if(n == 1)
	{
		strcpy(s, t.name);
		if(Hashfind(s, n))
		{
			cout << "该联系人重名!" << endl; 
			int key = Getkey_name(t.name);
			key = (key + 1) % Maxsize;
			
//			while (Hashtab[key].data)
//			{ 
//				key = (key + 1) % Maxsize;
//			} 
//			Hashtab[key].data = new tel;
//			strcpy(Hashtab[key].data->name, t.name);
//			strcpy(Hashtab[key].data->num, t.num);
//          strcpy(Hashtab[key].data->add, t.add);
			Hashtable(t, n);
			Hashtab[key].data->sign == '1';
			judge = true;
	    
			return;
		}
	}
	else if(n == 2)
	{
		strcpy(s, t.num);
		if(strlen(t.num) > 11)
		{
			cout << "error" << endl;
			return;
		 } 
	}
	
	Hashtable(t, n);
	cout << "添加成功!" << endl; 
}

void Part(tel &t, char *str) 
{
	int flag = 0;
	char *p = str;

	for (int i = 0; *p != '\n'; i++, p++)
	{
		if (*p != ' ')
		{
			if (flag == 0)
			{
				t.name[i] = *p;
			}
			else if (flag == 1)
			{
				t.num[i] = *p;
			}
			else if(flag == 2)
			{
				t.add[i] = *p;
			}
		}
		else
		{
			if (flag == 0)
			{
				t.name[i] = '\0';
			}
			else if (flag == 1)
			{
				t.num[i] = '\0';
			}
			else if(flag == 2)
			{
				t.add[i] = '\0';
			}

			flag++;
			i = -1;
	    }
	}
	
	p = NULL;
}

void Read(int n)
{
	FILE *fp;
	char str[300];
	int i = 0;
	tel t;
	
	if (!(fp = fopen("Record.txt", "r")))
	{
		cout << "Can't open the file" << endl;
		exit(0);
	}

	while (i <= Maxsize)
	{
		fgets(str, 300, fp);
		
		if (feof(fp)) break;
	
		Part(t, str);

		Hashtable(t, n);
		i++;
	}
	
	fclose(fp);
}

void Write()
{
	FILE *fp;

	if (!(fp = fopen("Record.txt", "w")))
	{
		cout << "Can't open the file" << endl;
		exit(0);
	}

	for (int i = 0; i < Maxsize; i++)
	{
		if(Hashtab[i].data)
		{
			fputs(Hashtab[i].data->name, fp);
			fputc(32, fp);
			fputs(Hashtab[i].data->num, fp);
			fputc(32, fp);
			fputs(Hashtab[i].data->add, fp);
			fputc(32, fp);
			fputc(10, fp);
		}
	}

	fclose(fp);
}
float arevage()  //求平均查找长度 
{
	int i;
	float total = 0.0;
	int count;
	for(i = 0;i < Maxsize;i++)
	{
		if(Hashtab[i].data != NULL)
		{
			total = total + Hashtab[i].data->conftime;
			count++;
		}
	}
	return total / count;
}
void Output()
{
	for (int i = 0; i < Maxsize; i++)
	if (Hashtab[i].data)
	{
		cout << Hashtab[i].data->name << " " << Hashtab[i].data->num << " " << Hashtab[i].data->add << endl;
	}
}

int main()
{
	int x, n;

	for (int i = 0; i < Maxsize; i++)  //哈希表初始化 
	Hashtab[i].data = NULL;


	cout << "请选择建表方式：1.以姓名建表 2.以电话号码建表" << endl; 
	cin >> n;
	system("cls");

	if (n != 1 && n != 2)
	{
		cout << "error" << endl;
		return 0;
	}

	Read(n);

	Menu();

	while(1)
	{
		cin >> x;

		cnt = 1;
		strcpy(S, "查无此人!");

		switch(x)
		{
			case 1:
				Add(n);
				break;
	
			case 2:
				char str1[20];
				cin >> str1;
				Delete(str1, n); 
				break;

			case 3:
					char str2[20];	
					cin >> str2;
				
					int flag = Hashfind(str2, n);
					puts(S);
				
					if(flag == 1)
					{
						cout << "查找长度:" << cnt << endl;
					}
					
					break;	
					
				
			case 4:
				Output();
				break;	
			case 5:
				cout << arevage() << endl;
				break;
			case 6:
				Write();
				return 0;
				
			default:
				cout << "error" << endl; 
				break;
		}
	}
	
	system("pause");
	return 0;
}

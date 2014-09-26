#include <iostream>


using namespace std;
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;		//Status 是函数返回值类型，其值是函数结果状态代码。
typedef int ElemType;	 //ElemType 为可定义的数据类型，此设为char类型

#define MAXSIZE 100			//顺序表可能达到的最大长度

typedef struct{
	ElemType *elem;			//存储空间的基地址
	int length;				//当前长度
}SqList;


Status InitList_Sq(SqList &L){				//算法2.1 顺序表的初始化
	//构造一个空的顺序表L
	L.elem = new ElemType[MAXSIZE];		//为顺序表分配一个大小为MAXSIZE的数组空间
	if (!L.elem)  exit(OVERFLOW);		//存储分配失败
	L.length = 0;							//空表长度为0
	return OK;
}


typedef struct{
	ElemType *new_elem;			//存储空间的基地址
	int new_length;				//当前长度
}TempSqList;

Status Delete_Sq(TempSqList &H){				//临时顺序表的初始化
	//构造一个空的顺序表L
	H.new_elem = new ElemType[MAXSIZE];		//为顺序表分配一个大小为MAXSIZE的数组空间
	if (!H.new_elem)  exit(OVERFLOW);		//存储分配失败
	H.new_length = 0;							//空表长度为0

	return 0;
}

Status Delete(SqList &L, ElemType &e)	//删除顺序表中元素方法
{

	int i, j = 0;
	TempSqList H;
	Delete_Sq(H);

	for (i = 0; i < L.length; i++)  //遍历一次，将所需要的元素复制到另一线性表中
	{

		if (e == L.elem[i])
		{
			continue;
		}
		H.new_elem[j] = L.elem[i];
		++j;
		++H.new_length;
	}

	for (i = 0; i < H.new_length; i++)		//检查结果
	{
		cout << H.new_elem[i] << " " << endl;
	}
	cout << "@Author 隆宗益" << endl;


	return 0;
}

int main()
{
	SqList L;

	int i, e, choose;

	cout << "1. 建立顺序表\n";
	cout << "2. 输入数据\n";
	cout << "3. 执行算法作业(10)\n";


	choose = -1;
	while (choose != 0)
	{
		cout << "请选择:";
		cin >> choose;
		switch (choose)
		{
		case 1:
			if (InitList_Sq(L))						//创建顺序表
				cout << "成功建立顺序表\n\n";
			else
				cout << "顺序表建立失败\n\n";
			break;
		case 2:										//输入10个字符
			cout << "请输入10个数字:\n";
			for (i = 0; i < 10; i++)
			{
				cin >> L.elem[i];

				++L.length;
			}

			cout << endl;
			break;
		case 3:										//顺序表的删除
			cout << "请输入所要删除的数字:";
			cin >> e;			//输入e，代表所要删除的数值

			Delete(L, e);

			break;

		}
	}
	return 0;
}
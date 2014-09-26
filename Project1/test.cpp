#include <iostream>


using namespace std;
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;		//Status �Ǻ�������ֵ���ͣ���ֵ�Ǻ������״̬���롣
typedef int ElemType;	 //ElemType Ϊ�ɶ�����������ͣ�����Ϊchar����

#define MAXSIZE 100			//˳�����ܴﵽ����󳤶�

typedef struct{
	ElemType *elem;			//�洢�ռ�Ļ���ַ
	int length;				//��ǰ����
}SqList;


Status InitList_Sq(SqList &L){				//�㷨2.1 ˳���ĳ�ʼ��
	//����һ���յ�˳���L
	L.elem = new ElemType[MAXSIZE];		//Ϊ˳������һ����СΪMAXSIZE������ռ�
	if (!L.elem)  exit(OVERFLOW);		//�洢����ʧ��
	L.length = 0;							//�ձ���Ϊ0
	return OK;
}


typedef struct{
	ElemType *new_elem;			//�洢�ռ�Ļ���ַ
	int new_length;				//��ǰ����
}TempSqList;

Status Delete_Sq(TempSqList &H){				//��ʱ˳���ĳ�ʼ��
	//����һ���յ�˳���L
	H.new_elem = new ElemType[MAXSIZE];		//Ϊ˳������һ����СΪMAXSIZE������ռ�
	if (!H.new_elem)  exit(OVERFLOW);		//�洢����ʧ��
	H.new_length = 0;							//�ձ���Ϊ0

	return 0;
}

Status Delete(SqList &L, ElemType &e)	//ɾ��˳�����Ԫ�ط���
{

	int i, j = 0;
	TempSqList H;
	Delete_Sq(H);

	for (i = 0; i < L.length; i++)  //����һ�Σ�������Ҫ��Ԫ�ظ��Ƶ���һ���Ա���
	{

		if (e == L.elem[i])
		{
			continue;
		}
		H.new_elem[j] = L.elem[i];
		++j;
		++H.new_length;
	}

	for (i = 0; i < H.new_length; i++)		//�����
	{
		cout << H.new_elem[i] << " " << endl;
	}
	cout << "@Author ¡����" << endl;


	return 0;
}

int main()
{
	SqList L;

	int i, e, choose;

	cout << "1. ����˳���\n";
	cout << "2. ��������\n";
	cout << "3. ִ���㷨��ҵ(10)\n";


	choose = -1;
	while (choose != 0)
	{
		cout << "��ѡ��:";
		cin >> choose;
		switch (choose)
		{
		case 1:
			if (InitList_Sq(L))						//����˳���
				cout << "�ɹ�����˳���\n\n";
			else
				cout << "˳�����ʧ��\n\n";
			break;
		case 2:										//����10���ַ�
			cout << "������10������:\n";
			for (i = 0; i < 10; i++)
			{
				cin >> L.elem[i];

				++L.length;
			}

			cout << endl;
			break;
		case 3:										//˳����ɾ��
			cout << "��������Ҫɾ��������:";
			cin >> e;			//����e��������Ҫɾ������ֵ

			Delete(L, e);

			break;

		}
	}
	return 0;
}
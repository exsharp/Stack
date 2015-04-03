#include<iostream>
using namespace std;

//#define ARRAY_STACK
#define LINK_STACK

#include"Stack.h"

void conversion();
void matching();
void printElem(ElemType &e);
void changElem(ElemType &e);

int main(){
	Stack stack;
	if (InitStack(stack))
		cout << "��ʼ���ɹ�" << endl;
	else
		cout << "��ʼ��ʧ��" << endl;

	cout << "�����ʼջ��Ԫ�ظ���:" << endl;
	int number;
	cin >> number;
	cout << "�����ʼջ��Ԫ��:" << endl;
	for (int i = 0; i < number; i++){
		if (!Push(stack, i + 1))
			cout << "�������" << endl;
	}

	while (true){

		cout << "1.StackTraverse" << endl;
		cout << "2.Pop" << endl;
		cout << "3.Push" << endl;
		cout << "4.GetTop" << endl;
		cout << "5.StackLength" << endl;
		cout << "6.StackEmpty" << endl;
		cout << "7.ClearStack" << endl;
		cout << "8.DestroyStack" << endl;
		cout << "9.����ת��" << endl;
		cout << "10.����ƥ��" << endl;
		int choice;
		cin >> choice;

		system("cls");
		cout << "ջ�е�Ԫ��:" << endl;
		StackTraverse(stack, printElem);

		switch (choice)
		{
		case 1:
			StackTraverse(stack, changElem);
			break;
		case 2:
			if (Pop(stack, number)){
				cout << "��Pop����Ԫ����:" << number << endl;
				cout << "ջ�е�Ԫ��:" << endl;
				StackTraverse(stack, printElem);
			}
			else
				cout << "Popʧ��" << endl;
			break;
		case 3:
			cout << "����ҪPush��Ԫ��:" << endl;
			cin >> number;
			if (Push(stack, number)){
				cout << "Push�ɹ�" << endl;
				cout << "ջ�е�Ԫ��:" << endl;
				StackTraverse(stack, printElem);
			}
			else
				cout << "Pushʧ��" << endl;
			break;
		case 4:
			cout << "ջ����Ԫ����:";
			if (GetTop(stack, number))
				cout << number << endl;
			else
				cout << "ջ����Ԫ��" << endl;
			break;
		case 5:
			cout << "ջ��Ԫ�صĸ�����:" << StackLength(stack) << endl;
			break;
		case 6:
			cout << "��ǰջ" << (true == StackEmpty(stack) ? "��" : "����") << "��ջ" << endl;
			break;
		case 7:
			cout << "���" << (true == ClearStack(stack) ? "�ɹ�" : "ʧ��") << endl;
			break;
		case 8:
			cout << "Destroy" << (true == DestroyStack(stack) ? "�ɹ�" : "ʧ��") << endl;
			break;
		case 9:
			system("cls");
			conversion();
			break;
		case 10:
			system("cls");
			matching();
			break;
		default:
			exit(1);
			DestroyStack(stack);
		}
	}
}

void printElem(ElemType &e){
	cout << e << " ";
}

void changElem(ElemType &e){
	cout << "��ǰ������:" << e << endl;
	int temp;
	cout << "����Ҫ�滻����:" << endl;
	cin >> temp;
	e = temp;
}

void conversion(){
	Stack num;
	InitStack(num);
	int in, out, number;
	cout << "�����ת����ʮ��������:" << endl;
	cin >> number;
	cout << "����Ҫת���ɵĽ���" << endl;
	cin >> in;
	while (in < 2){
		cout << "�����������2����" << endl;
		cin >> in;
	}
	while (number){
		Push(num, number%in);
		//cout << number%in<<" ";
		number = number / in;
	}
	cout << "ת�������:" << endl;
	while (!StackEmpty(num)){
		Pop(num, out);
		if (out > -1 && out < 10)
			cout << out;
		else
			cout << (char)(out + 55);
	}
	cout << endl;
	DestroyStack(num);
}

void matching(){
	char string[100];
	bool flag = true;
	int tmp;

	Stack character;
	InitStack(character);

	cout << "�����ƥ��ı��ʽ:" << endl;
	cin >> string;

	for (int i = 0; string[i] != 0 && flag; i++){
		cout << string[i];
		char cmp = string[i];
		switch (cmp)
		{
		case '{':
		case '[':
		case '(':
			Push(character, (int)string[i]);
			break;
		case '}':
			if (GetTop(character, tmp)){
				'{' == (char)tmp ? Pop(character, tmp) : flag = false;
			}
			else{
				flag = false;
			}
			break;
		case ']':
			if (GetTop(character, tmp)){
				'[' == (char)tmp ? Pop(character, tmp) : flag = false;
			}
			else{
				flag = false;
				cmp = 'a';
			}
			break;
		case ')':
			if (GetTop(character, tmp)){
				'(' == (char)tmp ? Pop(character, tmp) : flag = false;
			}
			else{
				flag = false;
			}
			break;
		default:
			break;
		}
	}
	cout << (flag&&StackEmpty(character) ? "ƥ��ɹ�" : "ƥ��ʧ��") << endl;
}
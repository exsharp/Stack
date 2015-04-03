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
		cout << "初始化成功" << endl;
	else
		cout << "初始化失败" << endl;

	cout << "输入最开始栈的元素个数:" << endl;
	int number;
	cin >> number;
	cout << "输入最开始栈的元素:" << endl;
	for (int i = 0; i < number; i++){
		if (!Push(stack, i + 1))
			cout << "插入错误" << endl;
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
		cout << "9.进制转换" << endl;
		cout << "10.括号匹配" << endl;
		int choice;
		cin >> choice;

		system("cls");
		cout << "栈中的元素:" << endl;
		StackTraverse(stack, printElem);

		switch (choice)
		{
		case 1:
			StackTraverse(stack, changElem);
			break;
		case 2:
			if (Pop(stack, number)){
				cout << "被Pop掉的元素是:" << number << endl;
				cout << "栈中的元素:" << endl;
				StackTraverse(stack, printElem);
			}
			else
				cout << "Pop失败" << endl;
			break;
		case 3:
			cout << "输入要Push的元素:" << endl;
			cin >> number;
			if (Push(stack, number)){
				cout << "Push成功" << endl;
				cout << "栈中的元素:" << endl;
				StackTraverse(stack, printElem);
			}
			else
				cout << "Push失败" << endl;
			break;
		case 4:
			cout << "栈顶的元素是:";
			if (GetTop(stack, number))
				cout << number << endl;
			else
				cout << "栈内无元素" << endl;
			break;
		case 5:
			cout << "栈内元素的个数是:" << StackLength(stack) << endl;
			break;
		case 6:
			cout << "当前栈" << (true == StackEmpty(stack) ? "是" : "不是") << "空栈" << endl;
			break;
		case 7:
			cout << "清空" << (true == ClearStack(stack) ? "成功" : "失败") << endl;
			break;
		case 8:
			cout << "Destroy" << (true == DestroyStack(stack) ? "成功" : "失败") << endl;
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
	cout << "当前的数是:" << e << endl;
	int temp;
	cout << "输入要替换的数:" << endl;
	cin >> temp;
	e = temp;
}

void conversion(){
	Stack num;
	InitStack(num);
	int in, out, number;
	cout << "输入待转换的十进制数字:" << endl;
	cin >> number;
	cout << "输入要转换成的进制" << endl;
	cin >> in;
	while (in < 2){
		cout << "必须输入大于2的数" << endl;
		cin >> in;
	}
	while (number){
		Push(num, number%in);
		//cout << number%in<<" ";
		number = number / in;
	}
	cout << "转化后的数:" << endl;
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

	cout << "输入待匹配的表达式:" << endl;
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
	cout << (flag&&StackEmpty(character) ? "匹配成功" : "匹配失败") << endl;
}
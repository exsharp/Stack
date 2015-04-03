#include "Stack.h"
#include <iostream>

#ifdef ARRAY_STACK

bool InitStack(Stack &s){
	s.data = new int[MAXSIZE];
	s.top = 0;
	return s.data ? true : false;
}

bool DestroyStack(Stack &s){
	if (!s.data)
		return false;
	delete s.data;
	s.data = NULL;
	s.top = 0;
	return true;
}

bool ClearStack(Stack &s){
	s.top = 0;
	return true;
}

bool StackEmpty(Stack s){
	return 0 == s.top ? true : false;
}

int StackLength(Stack s){
	return s.top;
}

bool GetTop(Stack s, ElemType &e){
	if (0 == s.top)
		return false;

	e = s.data[s.top - 1];
	return true;
}

bool Push(Stack &s, ElemType e){
	if (MAXSIZE == s.top){
		return false;
	}
	s.data[s.top++] = e;
	return true;
}

bool Pop(Stack &s, ElemType &e){
	if (0 == s.top)
		return false;
	e = s.data[--s.top];
	return true;
}

void StackTraverse(Stack &s, void(*traverse)(ElemType&)){
	for (int i = s.top - 1; i >= 0; i--){
		traverse(s.data[i]);
	}
}
#endif
#include "Stack.h"
#include <iostream>

#ifdef LINK_STACK

bool InitStack(Stack &s){
	s = NULL;
	return true;
}

bool DestroyStack(Stack &s){
	
	Stack p;
	while (s)
	{
		p = s;
		s = s->next;
		delete p;
	}
	s = NULL;
	return true;
}

bool ClearStack(Stack &s){

	Stack p;
	while (s)
	{
		p = s;
		s = s->next;
		delete p;
	}
	s = NULL;
	return true;
}

bool StackEmpty(Stack s){
	return s == NULL ? true : false;
}

int StackLength(Stack s){

	int j = 0;

	while (s){
		s = s->next;
		j++;
	}

	return j;
}

bool GetTop(Stack s, ElemType &e){
	if (!s)
		return false;
	else{
		e = s->data;
		return true;
	}
}

bool Push(Stack &s, ElemType e){
	SNode *p = new SNode;
	p->data = e;
	p->next = s;
	s = p;
	return true;
}

bool Pop(Stack &s, ElemType &e){
	if (!s)
		return false;

	e = s->data;

	SNode *p = s->next;
	delete s;
	s = p;

	return true;
}

void StackTraverse(Stack &s, void(*traverse)(ElemType &e)){
	Stack p;
	p = s;
	while (p){
		traverse(p->data);
		p = p->next;
	}
	std::cout << std::endl;
}
#endif
#include<iostream>
#define SIZE 10

class deleteFirstNode
{
	public:
	int data;
	deleteFirstNode *next,*p;
	void read()
	{  
	    deleteFirstNode *q, *x;
		q=new deleteFirstNode;
		q->data=SIZE;
		q->next=NULL;
		p=q;
		x=p;
		for(int i=SIZE;i!=0;i--)
		{  
		    q=new deleteFirstNode;
			q->data=i;
			q->next=NULL;
			x->next=q;
			x=q;
		}
		std::cout<<"\n The Elements in the List are :";
		for (x=p;x!=NULL;x=x->next)
			std::cout<<"  "<<x->data;
	}
	deleteFirstNode() {	p=NULL; }
	void removeFirstNode()
	{	
		deleteFirstNode *x;
		x=p;
		p=p->next;
		delete(x);
		std::cout<<"\n After deleting First element \nThe Elements in the List are :";
		for(x=p;x!=NULL;x=x->next)
			std::cout<<"  "<<x->data;
	}
};
int main()
{
	deleteFirstNode d;
	d.read();
	d.removeFirstNode();
}

#include<bits/stdc++.h>

using namespace std;


struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

void print(Node *root)
{
	Node *temp =root;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp = temp->next;
	}
}




Node *compute(Node *head)
{
   if(!head || !head->next)
   {
      return head;
   }

   Node *temp=head;

   while(temp->next!=NULL)
   {
	   if(temp->data < temp->next->data)
	   {
	        temp->data = temp->next->data;
		Node *toDel = temp->next;
		temp->next = temp->next->next;
		delete toDel;
	        temp = head;
	   }
	   else
	   {
		temp = temp->next;
	   }
   }
   return head;
}


int main()

{
	int T;
	cin>>T;

        struct Node *head = NULL;

	struct Node *temp = head;

	while(T--)
	{
		int K;
		cin>>K;

		for(int i=0;i<K;i++)
		{
			int data;
			cin>>data;
			if(head==NULL)
			{
				head=temp=new Node(data);
			}
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}

	}

	Node *res = compute(head);
	print(res);
	cout<<endl;

	return 0;
}

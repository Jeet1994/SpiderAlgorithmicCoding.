/*I am not being able to do all the operations properly. Probably because I am new to programming, mainly to the concepts of Data Structures.
I have implemented add_user in a detailed way, where I take inputs as User_name and User_age(Doing this helped me to sort them in an effective 
way), I also implemented the del_user(working in two parts as del_age and del_name), I also wrote a function called sort_user() to sort them
with respect to age and name. Lastly an additional implementation to display the whole list. */

/*operations completed successfully: add_user, del_user, sort_user and reverse()
Operations not completed : median_age, average_age, max_occu, max_loc, suggest_friend, seggregate_age*/

/*The error I am getting is ['main' must return 'int'], I tried adding a "return 0" but it did not work.*/


#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;
struct ListNode
{
	string name;
	int age;
	ListNode * next;
};
ListNode * head = NULL;
void append (string, int);
void add_username(string, int);
void add_userage(string, int);
void del_age (int);
void del_name (string);
void del_users ();
void print_users ();
void sort_user ();
void exitprog ();
void reverse();
void segregate_age();
void main ()
{
	int select, age, num;
	string name;
	while (1)
	{
		cout<<"Press 1 for creating the node"<<endl; //adding a node to store data.
		cout<<"Press 2 for adding a user"<<endl;
		cout<<"Press 3 for deleting a user"<<endl;
		cout<<"Press 4 for deleting a list"<<endl;
		cout<<"Press 5 for printing the list"<<endl; //this function displays the list.
		cout<<"Press 6 for sorting the list"<<endl;
		cout<<"Press 7 to reverse the entire list"<<endl;
        cout<<"Press 8 to segregate the age as per even and odd "<<endl;		
		cout<<"Press 9 to exit the program"<<endl;
		
		cin>>select;
		switch (select)
		{
		case 1:
			cout<<"Please enter the name of the user: ";
			cin.ignore (10000,'\n');//clearing buffer
			getline (cin, name);
			cout<<"Please enter the age of the user: ";
			cin>>age;
			append (name, age);
			break;
		case 2:
			cout<<"Press 1 to sort on the basis of name or 2 to sort on the basis of age: ";
			cin>>num;
			cout<<"Please enter the name of the user: ";
			cin.ignore (10000,'\n');
			getline (cin, name);
			cout<<"Please enter the age of the user: ";
			cin>>age;
			if (num == 1)
			{
				add_username (name, age);
			}
			else if (num == 2)
			{
				add_userage(name, age);
			}
			break;
		case 3:
			cout<<"Press 1 to delete the node on the basis of name or 2 to delete on the basis of age: ";
			cin>>num;
			if (num == 1)
			{
				string value;
				cout<<"Please enter the name: ";
				cin.ignore (10000,'\n');
				getline (cin, value);
				del_name (value);
			}
			else if (num == 2)
			{
				int value;
				cout<<"Please enter the age: ";
				cin>>value;
				del_age (value);
			}
			else
			{
				cout<<"You have entered an invalid input...!"<<endl;
			}
			break;
		case 4:
			del_users ();
			break;
		case 5:
			print_users ();
			break;
		case 6:
			sort_user();
			break;
		case 7:
             reverse();
        case 8: 
             segregate_age();
		case 9:
			exitprog ();
		
		default:
			cout<<"You have entered an invalid input...!"<<endl;
			break;
		}
	}
}
void append (string name, int age)
{
	ListNode * temphead = head;
	ListNode * temp = new ListNode;
	temp->name = name;
	temp->age= age;
	temp->next = NULL;
	if (head == NULL) //if the list is empty
	{
		head = temp;	//create new
	}
	else//go to next node
	{
		while (temphead->next)
		{
			temphead = temphead->next;
		}
		temphead->next = temp;
	}
}
void add_username (string name, int age)
{
	ListNode * temp = new ListNode;
	temp->next = NULL;
	temp->name = name;
	temp->age= age;
	if (head == NULL)
	{
		head = temp;
	}
	else
	{
		ListNode * temphead = head;
		ListNode * previous = NULL;
		while (temphead != NULL && name > temphead->name)
		{
			previous = temphead;
			temphead = temphead->next;
		}
		if (previous == NULL)
		{
			head = temp;
			temp->next = temphead;
		}
		else if (temphead == NULL)
		{
			previous->next = temp;
		}
		else
		{
			previous->next = temp;
			temp->next = temphead;
		}
	}
}
void add_userage(string name, int age)
{
	ListNode * temp = new ListNode;
	temp->next = NULL;
	temp->name = name;
	temp->age= age;
	if (head == NULL)
	{
		head = temp;
	}
	else
	{
		ListNode * temphead = head;
		ListNode * previous = NULL;
		while (temphead != NULL && age> temphead->age)
		{
			previous = temphead;
			temphead = temphead->next;
		}
		if (previous == NULL)
		{
			head = temp;
			temp->next = temphead;
		}
		else if (temphead == NULL)
		{
			previous->next = temp;
		}
		else
		{
			previous->next = temp;
			temp->next = temphead;
		}
	}
}
void del_age (int age)
{
	ListNode * temphead = head;
	ListNode * previous = NULL;
	ListNode * tempnext = NULL;
	while (temphead->age!= age&& temphead != NULL)
	{
		previous = temphead;
		temphead = temphead->next;
	}
	if (temphead == NULL)
	{
		cout<<"Sorry no data found!!!"<<endl;
	}
	else if (previous == NULL)
	{
		tempnext = temphead->next;
		head = tempnext;
		delete temphead;
	}
	else
	{
		tempnext = temphead->next;
		previous->next = tempnext;
		delete temphead;
	}
}
void del_name (string name)
{
	ListNode * temphead = head;
	ListNode * previous = NULL;
	ListNode * tempnext = NULL;
	while (temphead->name != name && temphead != NULL)//traversing the list
	{
		previous = temphead;
		temphead = temphead->next;
	}
	if (temphead == NULL)
	{
		cout<<"Sorry no data found!!!"<<endl;
	}
	else if (previous == NULL)
	{
		tempnext = temphead->next;
		head = tempnext;
		delete temphead;
	}
	else
	{
		tempnext = temphead->next;
		previous->next = tempnext;
		delete temphead;
	}
}
void del_list()
{
	ListNode * temphead = head, * temp;
	while (temphead)
	{
		temp = temphead->next;
		delete temphead;
		temphead = temp;
	}
	head = NULL;
}
void print_list ()
{
	if (head == NULL)
	{
		cout<<"There is nothing to print."<<endl;
		return;
	}
	ListNode * temphead = head;
	while (temphead)
	{
		cout<<temphead->name<<' '<<temphead->age<<endl;
		temphead = temphead->next;
	}
}
void sort_list ()
{
	ListNode * temphead = head;
//	ListNode * tempnode = NULL;
	int tempage;
	string tempname;
	int counter = 0;
	while (temphead)
	{
		temphead = temphead->next;
		counter++;
	}
	for (int i=0; i<counter; i++)
	{
		for (int j=0; j<counter-i; j++)
		{
			if (temphead->age> temphead->next->age)
			{
//				tempnode = temphead;
//				temphead = temphead->next;
//				temphead->next = tempnode;
				tempage= temphead->age;
				temphead->age= temphead->next->age;
				temphead->next->age= tempage;

				tempname = temphead->name;
				temphead->name = temphead->next->name;
				temphead->next->name = tempname;
			}
		}
	}
}

void reverse( ListNode** head_ref)
{
     ListNode* previous= NULL;
     ListNode* current= *head_ref;
     ListNode* next;
     while(current != NULL)
     {
                   next = current->next;
                   current->next = previous;
                   previous = current;
                   current = next;
                   }
                   *head_ref = previous;
                   }
void exitprog ()
{
	exit (0);
}
void segregate_age(ListNode **head_ref)
{
     ListNode* end = *head_ref;
     ListNode* previous = NULL;
     ListNode* current = *head_ref;
     
     while(end->next != NULL)
     end = end->next;
 
    ListNode *new_end = end;
 
    
    while (current->age %2 != 0 && current != end)
    {
        new_end->next = current;
        current = current->next;
        new_end->next->next = NULL;
        new_end = new_end->next;
    }
 
    
    if (current->age%2 == 0)
    {
        
        *head_ref = current;
 
        
        while (current != end)
        {
            if ( (current->age)%2 == 0 )
            {
                previous = current;
                current = current->next;
            }
            else
            {
                
                previous->next = current->next;
 
                
                current->next = NULL;
 
                
                new_end->next = current;
 
                
                new_end = current;
 
                
                current = previous->next;
            }
        }
    }
 
    
    else previous = current;
 
   
    if (new_end!=end && (end->age)%2 != 0)
    {
        previous->next = end->next;
        end->next = NULL;
        new_end->next = end;
    }
    return;
}

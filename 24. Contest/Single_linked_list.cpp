#include<iostream>
using namespace std;

/*struct Item{
	char kytu;
	int count;
};
*/
struct node{
	//Item infor;
	int info;
	struct node *next;
}*start;

class single_linked_list{
	public:
		node *create_node(int);
		void input_begin();
		void input_last();
		void insert_begin();
		void insert_last();
		void insert_pos();
		void delete_pos();
		void sort();
		void search();
		void update();
		void reverse();
		void display();
		single_linked_list(){
			start = NULL;
		}
};

node *single_linked_list::create_node(int value){
	struct node *temp, *s;
	temp = new(struct node);
	if(temp == NULL){
		cout<<"Khong du bo nho"<<endl;
		return 0;
	}
	else{
		temp->info = value;
		temp->next = NULL;
		return temp;
	}
}

void single_linked_list::insert_begin(){
	int value; cout<<"Nhap gia tri: "; cin>>value;
	struct node *temp, *ptr;
	temp = create_node(value);
	if(start == NULL){
		start = temp;
		start->next = NULL;
	}
	else{
		ptr=start;
		start = temp;
		start->next = ptr;
	}

	struct node *last;
	temp->next = last->next;
	last->next=temp;
	//return last;	
}

void single_linked_list::input_begin(){
	int n; cin>>n;
	int value;
	struct node *temp, *ptr;
	//	for(int i=0; i<n; i++)	insert_begin();
	for(int i=0; i<n; i++){ 
		cin>>value;
		temp = create_node(value);
		if(start == NULL){
			start = temp;
			start->next = NULL;
		}
		else{
			ptr=start;
			start = temp;
			start->next = ptr;
		}
	}
}

void single_linked_list::insert_last(){
	int value;
	cout<<"Nhap gia tri: "; cin>>value;
	struct node *temp, *ptr;
	temp = create_node(value);
	if(start==NULL){
		start = temp;
		temp->next=NULL;
		return;
	}
	ptr = start;
	while(ptr->next != NULL){
		ptr=ptr->next;
	}
	//temp->next = NULL;
	temp->next = start;
	ptr->next=temp;
}

void single_linked_list::input_last(){
	int n; cin>>n;
	int value;
	struct node *temp, *ptr;
//	for(int i=0; i<n; i++)	insert_last();
	for(int i=0; i<n; i++){ 
		cin>>value;
		temp = create_node(value);
		if(start==NULL){
			start = temp;
			temp->next=NULL;
			return;
		}
		ptr = start;
		while(ptr->next != NULL){
			ptr=ptr->next;
		}
		temp->next = NULL;
		ptr->next=temp;
	}
}



void single_linked_list::display(){
		struct node *temp;
		if(start==NULL){
			cout<<"EMPTY!!"<<endl;
			return;
		}
		temp=start;
		cout<<"NOI DUNG DANH SACH LIEN KET: "<<endl;
		while(temp!=NULL){
				cout<<temp->info<<"->";
				temp=temp->next;
		}
		cout<<"NULL"<<endl;
}

int main(){
	single_linked_list X;
	X.insert_begin();
	//X.input_begin(); 
	//X.insert_last();
	//X.input_last();
	X.display();
}

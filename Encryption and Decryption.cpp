#include <iostream>
using namespace std;
#include <math.h>
#include <string.h>
#include <cstdlib>
#include <ctime>
#include<ctype.h>
#include<stdio.h>

char usr_dat [100000]={};
int usr_dat_2[100000]={};


int lvl_tot=0;
void l_tot(){
int a = strlen(usr_dat);
int level_elem_needed=0;
if (a>level_elem_needed){
level_elem_needed=level_elem_needed+pow(2,lvl_tot);
lvl_tot++;	
}
cout<<"levels needed "<<lvl_tot;	
}

class link_list{
public:
int data_link;
   link_list* next_link; 
link_list* head_link;
link_list* temp;

link_list(){head_link=NULL;temp=NULL;}

int insert_link(int d);
void display_link();

};

link_list* p_link=NULL;

int link_list :: insert_link(int d){

//p_link=NULL;

if (head_link == NULL)
{
temp=new link_list();
head_link=temp;
}
else
{
temp -> next_link = new link_list();
temp = temp->next_link;
}
temp->next_link=NULL;
temp->data_link=d;
}

void link_list ::display_link(){
p_link=head_link;
while(p_link!=NULL){
cout <<p_link->data_link<<" ";
p_link=p_link->next_link;
}
}

link_list usr_dat_num;   //stores the data taken from the user in its ASCII form
link_list usr_dat_num_2; //stores the data taken from the user in its ASCII form for decryption

link_list p_link_d_r;//storing data after read operation
link_list p_link_k_r;//storing key after read operation

class tree {
public:
int data_tree ;

tree* root;
tree* left ;
tree* right ;

tree () { data_tree=0; left=NULL ;right=NULL; root=NULL ; }

void write();
void write_2();
void read ();
void display(); //display result to user

};

tree* n= NULL;
tree* current=NULL;

tree encry;  //root of encry
tree decry;  //root of decry


class queue  //has obj. q:- for reading and q_w :- for write operation
{
public:
tree*  data;
queue* rear;
queue* front;
queue* next;
queue* head;
   queue* p1;
   
queue()
       	{
            rear=NULL;
            front=NULL;
           }
             
void insert(tree* d)
           {
            p1=new queue();
            p1->data=d;
   	 p1->next=NULL;
if   (front==NULL) front=p1;
            else  rear->next=p1;
   	 rear=p1;
           }
  
       tree* dequeue()
           {
            if(front==NULL)
              {
    cout<<"\nQueue is empty!!";
     	 }
  else
{
queue *temp;
  temp=front;
  front=front->next;
return (temp->data);
}
           }
            
       void display()
           {
            queue *ptr1=front;
 	 if(front==NULL)
  {
     	 cout<<"The Queue is empty!!";
     	 return;
  }
  while(ptr1!=NULL)
  {
     	  cout<<ptr1->data<<" ";
     	  ptr1=ptr1->next;
  }
           }
}q, q_w, q_w_2, q_d, q_r;



int level = 0;
int levelElem =0;

void levelElem_calc (){
levelElem = pow(2,level);
}

void encrypt();
void decrypt();

link_list usr_data_num;
link_list key;
link_list encry_data_init; //contains the encrypted data

//generating key for the data



void mat_mul(int size){


int a[size][size];
int b[size][size];
int c[size][size];
int k[size];

int t=0;

   p_link=key.head_link;
while(p_link!=NULL){

k[t]=p_link->data_link;
p_link=p_link->next_link;
   t++;
}

int count =0;
int count2=0;

for (int i=0;i<size;i++){
for (int j=0;j<size;j++){

a[i][j]=usr_dat[count];
count++;
}
}

for (int i=0;i<size;i++){
for (int j=0;j<size;j++){
if (i==j){
b[i][j]=k[count2];
count2++;
}
else{
b[i][j]=0;
}
}
}

   for (int i=0;i<size;i++){
   	for (int j=0;j<size;j++){
   	 c[i][j]=a[i][j]*b[i][i];
   	}
   }
   
   for (int i=0;i<size;i++){
   	for (int j=0;j<size;j++){
   	 encry_data_init.insert_link(c[i][j]);
   	}
   }

p_link=encry_data_init.head_link;
   while (p_link != NULL){
char d=p_link->data_link;
p_link=p_link->next_link;
}
}

void mat_mul_2(int size){

int   a[size][size];
float b[size][size];
float c[size][size];
float k[size];

int t=0;

   p_link=p_link_k_r.head_link;

int co=0;

while(p_link!=NULL){
k[t]=p_link->data_link;
p_link=p_link->next_link;
   t++;
   co++;
}

if (co<size){
while (co<size){
p_link=p_link_k_r.head_link;
while(p_link!=NULL || co<size){
k[t]=p_link->data_link;
p_link=p_link->next_link;
  t++;
   	}
co++;
}	

}

link_list* tem=NULL;
tem=p_link_d_r.head_link;

int count =0;
int count2=0;

for (int i=0;i<size;i++){
for (int j=0;j<size;j++){

if (tem!=NULL){
a[i][j]=tem->data_link;
tem=tem->next_link;
count++;
}
else{
a[i][j]=0;	
}
}
}

for (int i=0;i<size;i++){
for (int j=0;j<size;j++){
if (i==j){
b[i][j]=(1/k[count2]);
count2++;
}
else{
b[i][j]=0;
}
}
}

cout<<"\n\n DATA AFTER DECRYPTION IS :";
   for (int i=0;i<size;i++){
   	for (int j=0;j<size;j++){
   	 c[i][j]=a[i][j]*b[i][i];
   	 cout<<(char)c[i][j];

}
   }
   
}


int usr_data_len;
int mat_size;

void encrypt(){

usr_data_len=strlen(usr_dat);
   float temp=sqrt(usr_data_len);
   int temp2=temp;
   
   
   if (temp>temp2){
   	//sqrt(usr_data_len) not integer
   	mat_size=temp2+1;
   }
   else{
   	//it is integer
mat_size=temp2;	
   }

   
int k;

   link_list* p_link_temp;

//generating key for encryption

for(int i=0;i<mat_size;i++) { 

   p_link_temp=key.head_link;

if (level <= mat_size){
key.insert_link(rand()%3+1);
  }
  
else {
  p_link_temp=key.head_link;
key.insert_link(p_link_temp->data_link);
  p_link_temp=p_link_temp->next_link;
  
if(p_link_temp==NULL){
  p_link_temp=key.head_link;
  }
  else{
  //leave it blank
}
  }
}

for (int i=0;i<usr_data_len;i++){
k=usr_dat[i];
usr_dat_num.insert_link(k);
}
mat_mul(mat_size);
encry.write();
encry.display();
}


void tree::write() {        //make this function both for reading and writing

levelElem=0;
level=0;
levelElem_calc();

p_link   = encry_data_init.head_link;
link_list* p_link_k;
p_link_k = key.head_link;

int totalElem=0;      //used in else if loop

tree* current;
current=new tree();

root=new tree();
q_w.insert(root);

void l_tot();  //get lev_tot from it

while(p_link!=NULL){

    if (levelElem!=0){  

current = q_w.dequeue();  //current=current->right/left

if (totalElem % 2 ==0 || level==0){
   	      current->data_tree = p_link->data_link; 
   	 
p_link=p_link->next_link;
}
   
  else if (totalElem == 1){
   	 current->data_tree=p_link_k->data_link;
   	 
p_link_k=p_link_k->next_link;
}
   
  else if (totalElem % 2 !=0){
   	    	current->data_tree=rand()%7+1; //garbage value from 1 to 7

}
   
levelElem--;
totalElem++;
   	
   	
   	current->left=new tree();
q_w.insert(current->left);
current->right=new tree();
q_w.insert(current->right);
}

else{
level++;
levelElem_calc();
totalElem=0;
}
}
}

void tree::write_2() {        //make this function both for reading and writing

levelElem=0;
level=0;
levelElem_calc();

p_link = usr_dat_num_2.head_link;

int totalElem=0;      //used in else if loop

tree* current;
current=new tree();

root=new tree();

q_w_2.insert(root);

void l_tot();  //get lev_tot from it

while(p_link!=NULL){

if (levelElem!=0){ 

current = q_w_2.dequeue();  //current=current->right/left

current->data_tree = p_link->data_link; 
   	p_link=p_link->next_link;

   	levelElem--;
totalElem++;
   	
   	current->left=new tree();
q_w_2.insert(current->left);
current->right=new tree();
q_w_2.insert(current->right);
}

else{
level++;
levelElem_calc();
totalElem=0;
}
 
}
}


int usr_dat_len_2;
int mat_size_2;



void decrypt(){  

link_list* p_link_temp;

   for (int i=0;i<usr_dat_len_2;i++){
usr_dat_num_2.insert_link(usr_dat_2[i]);
}

decry.write_2();
decry.read();
mat_mul_2(mat_size_2);

}

void tree ::read (){ 
         
levelElem=0;
level=0;
levelElem_calc();

p_link = usr_dat_num_2.head_link;

int totalElem=0;      //used in else if loop

q_r.insert(root);
tree* current;

int x=0;


void l_tot();  //get lev_tot from it

for(int i=0;i<usr_dat_len_2;i++)
{
if (levelElem!=0){  

current = q_r.dequeue(); 

if (totalElem % 2 ==0 || level==0){
   	   p_link_d_r.insert_link(current->data_tree);
  x++; 
}
   
  else if (totalElem == 1){
  p_link_k_r.insert_link(current->data_tree);
}

   	levelElem--;
totalElem++;
   	
q_r.insert(current->left);
q_r.insert(current->right);
}

else{
level++;
levelElem_calc();
totalElem=0;
}
}


   float temp=sqrt(x);
   int temp2=temp;
   
   
   if (temp>temp2){
   	//sqrt(usr_data_len) not integer
   	mat_size_2=temp2+1;
   }
   else{
   	//it is integer
mat_size_2=temp2;	
   }

}

void tree :: display(){  //used for displaying result to the user
   
   
   q_d.insert(root);
tree* current;
int l=level;
int flag;
for (int i=0;i<=level;i++){
flag=flag+pow(2,i);
}

cout<<"\n";

while(flag){

   current=q_d.dequeue();
   cout<<current->data_tree<<" ";	

   q_d.insert(current->left);
q_d.insert(current->right);

flag--;
}	
}

main (){
int flag=1;
int flag_2=1;
int i=0;
int d;
int prev;
while(flag){
cout <<"\n\n\nSelect from the following :-";
   	cout <<"\n1.Encrypt \n2.Decrypt \n3.Exit\n";
   int choice;
   cout<<"\nEnter your choice: ";
   cin >>choice;
   fflush(stdin);
   
   switch (choice){
   	case 1:cout<<"\n Enter data: ";
   	   gets(usr_dat); 
   	   encrypt();
  prev=1;
  break;
   	
case 2:while(flag_2){
cout<<"Enter data and enter 999 to stop: ";
   	   cin>>d;
if(d==999){flag_2=0;}
  else{usr_dat_2[i]=d;  i++;}
  }
usr_dat_len_2=i;
decrypt();
prev=2;
  break;
   	
case 3:flag=0;
      break;
   
default :cout <<"enter corrrect choice !!!!";
   }
}
}

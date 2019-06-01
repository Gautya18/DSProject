#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
///structure for data to store
typedef struct info
{
    char firname[20]; ///first name
    char surname[20];
    char key[40];
    char phone[11];
    char edu[20];
    char salary[15];
    int state;
}INFO;

///structure for node of trie by key name
typedef struct  ntrie  /// by name
{
    struct ntrie* child[27];
    bool End;
    INFO *data;
}NTrie;

///structure for node of trie by key name
typedef struct ptrie
{
    struct ptrie* child[11];
    bool End;
    INFO *data;
}PTrie;

///create new node of data
INFO* newInfo(INFO obj)
{
    INFO *a=(INFO*)malloc(sizeof(INFO));
    strcpy(a->firname,obj.firname);
    strcpy(a->key,obj.key);
    strcpy(a->surname,obj.surname);
    strcpy(a->phone,obj.phone);
    strcpy(a->edu,obj.edu);
     strcpy(a->salary,obj.salary);
     a->state=obj.state;
    return a;
}

///create new node for trie by key name
NTrie* newNodeN()
{
    int i=0;
    NTrie *tnew= (NTrie*)malloc(sizeof(NTrie));
    tnew->End=false;
    for(i=0;i<27;i++)
        tnew->child[i]=NULL;
    return tnew;
}

///create new node for trie by key name
PTrie* newNodeP()
{
    int i=0;
    PTrie *tnew=(PTrie*)malloc(sizeof(PTrie));
    tnew->End=false;
    for(i=0;i<11;i++)
        tnew->child[i]=NULL;
    return tnew;
}

///insert by name
 void insertN(NTrie *root,INFO* infom)
 {
     NTrie *trav=root;
     int i=0,index,flg;
     for(i=0;infom->key[i]!='\0';i++)
     {
         index=infom->key[i]-'a';
         if(trav->child[index]==NULL)
           {
                trav->child[index]=newNodeN();
           }

        trav=trav->child[index];
     }
     trav->End=true;
     trav->data=infom;
 }

///insert by phone number
 void insertP(PTrie *root,INFO* infom)
 {
     PTrie *trav=root;
     int i=0,index;
     for(i=0;infom->phone[i]!='\0';i++)
     {
         index=infom->phone[i]-'0';
         if(trav->child[index]==NULL)
                trav->child[index]=newNodeP();
         trav=trav->child[index];
    }
     trav->End=true;
     trav->data=infom;
 }

 ///search by name
 void searchN(NTrie *root,char* key,char *str)
 {
     NTrie *trav=root;
     int i,index,flg=0;
     for(i=0;key[i]!='\0';i++)
     {
        index=key[i]- 'a';
        if(trav->child[index]==NULL)
         {
             flg=1;
             break;
         }
        trav=trav->child[index];
     }

     if(flg==0)
     {
             if(trav->End==true&&trav->data->state==1)
         {
             printf("\nName of Employee: %s %s",trav->data->firname,trav->data->surname);
             printf("\nPhone Number    : %s",trav->data->phone);
             printf("\nKey Name        : %s",trav->data->key);
             printf("\nEducation       : %s",trav->data->edu);
             printf("\nSalary          : %s",trav->data->salary);
             strcpy(str,trav->data->phone);

            return;
         }
         else
            {
                printf("\nData not found");
                strcpy(str,"0000000000");
            }

     }
     else
      {
          printf("\nData not found");
            strcpy(str,"0000000000");
      }
     return;
 }

 ///search by phone
  void searchP(PTrie *root,char* key)
 {
     PTrie *trav=root;
     int i,index,flg=0;
     for(i=0;key[i]!='\0';i++)
     {
        index=key[i]- '0';
        if(trav->child[index]==NULL)
         {
             trav=NULL;
             flg=1;
             break;
         }
        trav=trav->child[index];
     }
     if(flg==0)
     {
         if(trav->End==true&&trav->data->state==1)
         {
             printf("\nName of Employee: %s %s",trav->data->firname,trav->data->surname);
             printf("\nPhone Number    : %s",trav->data->phone);
             printf("\nKey Name        : %s",trav->data->key);
              printf("\nEducation      : %s",trav->data->edu);
             printf("\nSalary           : %s",trav->data->salary);
             return;
         }
         else
            printf("\nData not found");
     }
     else
         printf("\nData not found");
     return;
 }

///check if data already exists
int check_existN(NTrie *root,char *key)
{

     NTrie *trav=root;
     int i,index,flg=0;
     for(i=0;key[i]!='\0';i++)
     {
        index=key[i]- 'a';
        if(trav->child[index]==NULL)
         {
             trav=NULL;
             flg=1;
             break;
         }
        trav=trav->child[index];
     }
     if(flg==0)
     {
         if(trav->End==true&&trav->data->state==1)
             return 1;
         else
            return 0;
     }
     else
      return 0;

}

int check_existP(PTrie *root,char *key)
{

     PTrie *trav=root;
     int i,index,flg=0;
     for(i=0;key[i]!='\0';i++)
     {
        index=key[i]- '0';
        if(trav->child[index]==NULL)
         {
             trav=NULL;
             flg=1;
             break;
         }
        trav=trav->child[index];
     }
     if(flg==0)
     {
         if(trav->End==true&&trav->data->state==1)
             return 1;
         else
            return 0;
     }
     else
      return 0;

}

 ///deletion in trie by key name
 void delN(NTrie *root, char* key)///initially index 0;
 {
       int i,index;
	NTrie* travel=root;

	for(i=0;i<strlen(key);i++)
	{
		index=key[i]-'a';
		if(index<0 || index>=27)
		{
			printf("\tDATA NOT FOUND\n");
			return;
		}
		if(travel->child[index]==NULL)
		{
			travel=NULL;
			break;
		}
		travel=travel->child[index];
	}
	if(travel!=NULL)
	{
		if(travel->End==true)
		{
			travel->End=false;

			return;
		}
		else
		{
			printf("\tDATA NOT FOUND\n");
			return;
		}
	}
	else
	{
		printf("\tDATA NOT FOUND\n");
		return;
	}

 }


 ///deletion in trie by phone number
 void delP(PTrie *root, char* key)///initially index -1;
 {
   int i,index;
	PTrie* travel=root;

	for(i=0;i<strlen(key);i++)
	{

		index=key[i]-'0';
		if(index<0 || index>=11)
		{
			printf("\tDATA NOT FOUND\n");
			return;
		}
		if(travel->child[index]==NULL)
		{
			travel=NULL;
			break;
		}
		travel=travel->child[index];
	}
	if(travel!=NULL)
	{
		if(travel->End==true)
		{
			travel->End=false;

			return;
		}
		else
		{
			printf("\tDATA NOT FOUND\n");
			return;
		}
	}
	else
	{
		printf("\tDATA NOT FOUND\n");
		return;
	}
 }

 ///check whether input is valid
 int check_valid(char *str,int flg)
 {
     int validity=1,i;
     if(flg==1)
     {
         for(i=0;str[i]!='\0';i++)
         {
             if(str[i]>=97&&str[i]<=122)
                continue;
             else
             {
                 validity=0;
                 break;
             }
         }
     }
     else
     {
          for(i=0;str[i]!='\0';i++)
         {
             if(str[i]>=48&&str[i]<=57)
                continue;
             else
             {
                 validity=0;
                 break;
             }
         }
         if(i!=10&&flg==0)
            validity=0;
     }
     return validity;
 }

 ///take input for data
 int input(INFO *data,NTrie *ptr_n,PTrie *ptr_p)
 {

     int flg=0;
    printf("\n              ************   Enter FACULTY Data   ************           \n");
        while(flg<3)
        {   printf("\nEnter first name:");
            scanf("%s",data->firname);
            if(check_valid(data->firname,1))
                break;
            else
               printf("\nInvalid data\n");
                flg++;
        }
        if(flg==3)
            return 0;

/*/////////////////////////////////////////////////*/
        flg=0;
        while(flg<3)
        {   printf("\nEnter surname:");
            scanf("%s",data->surname);
            if(check_valid(data->surname,1))
                break;
            else
                printf("\nInvalid data");
            flg++;
        }
        if(flg==3)
            return 0;

/*/////////////////////////////////////////////////*/
             flg=0;
        while(flg<3)
         {
             printf("\nEnter Key name (should be unique):");
            scanf("%s",data->key);
            if(check_valid(data->key,1))
                break;
            else
                printf("\nInvalid data");
            flg++;
        }
        if(flg==3)
            return 0;
            if(check_existN(ptr_n,data->key))
            {
                printf("\nData Already Exists");
                return 0;
            }
/*/////////////////////////////////////////////////*/
        flg=0;
        while(flg<3)
        {
             printf("\nEnter phone number:");
            scanf("%s",data->phone);
            if(check_valid(data->phone,0))
                break;
            else
                printf("\nInvalid data");
            flg++;
        }
        if(flg==3)
            return 0;

             if(check_existP(ptr_p,data->phone))
            {
                printf("\nData Already Exists");
                return 0;
            }
/*/////////////////////////////////////////////////*/
            printf("\nEnter Education:");
            scanf("%s",data->edu);
/*/////////////////////////////////////////////////*/
        flg=0;
        while(flg<3)
        {
             printf("\nEnter Salary:");
            scanf("%s",data->salary);
            if(check_valid(data->salary,2))
                break;
            else
                printf("\nInvalid data");
            flg++;
        }
        if(flg==3)
            return 0;


            return 1;
 }

 ///modifications in file
void mod_in_File(FILE *file,INFO obj,NTrie *ptr_name,PTrie *ptr_phn)
{
    int pos;
    NTrie* num;
    PTrie* num1;
    INFO obj1;
    INFO *ptr;
    rewind(file);
    while(1)
    {
        pos=ftell(file);
        fscanf(file,"%s %s %s %s %s %s %d",&obj1.firname,&obj1.surname,&obj1.key,&obj1.phone,&obj1.edu,&obj1.salary,&obj1.state);

        if(feof(file))
            break;
        if(strcmp(obj.phone,obj1.phone)==0&&strcmp(obj.key,obj1.key)==0)
            break;

    }
    if(feof(file))
    {
        printf("\nData Not Found\n");
        return ;
    }
    printf("\n              ************   Enter Modified data   ************           \n");
    delN(ptr_name,obj.key);
    delP(ptr_phn,obj.phone);
    if(!input(&obj1,ptr_name,ptr_phn))
        return ;

    obj1.state=1;
    ptr=newInfo(obj1);
    fseek(file,pos,SEEK_SET);
    fprintf(file,"\n%s\n%s\n%s\n%s\n%s\n%s\n%d\n",obj1.firname,obj1.surname,obj1.key,obj1.phone,obj1.edu,obj1.salary,obj1.state);
    insertN(ptr_name,ptr);
    insertP(ptr_phn,ptr);
}

///add data in file
 void add_in_File(FILE *file,INFO obj1)
 {
     fseek(file,0,SEEK_END);
    fprintf(file,"\n%s\n%s\n%s\n%s\n%s\n%s\n%d\n",obj1.firname,obj1.surname,obj1.key,obj1.phone,obj1.edu,obj1.salary,obj1.state);
 }

 ///delete data in file
 void del_in_File(FILE *file,INFO obj)
 {
     int pos;
    INFO obj1;
    rewind(file);
    while(1)
    {
         pos=ftell(file);
        fscanf(file,"%s %s %s %s %s %s %d",&obj1.firname,&obj1.surname,&obj1.key,&obj1.phone,&obj1.edu,&obj1.salary,&obj1.state);

        if(feof(file))
            break;
        if(strcmp(obj.phone,obj1.phone)==0)
            break;

    }

    fseek(file,pos,SEEK_SET);
    obj1.state=0;
    fprintf(file,"\n%s\n%s\n%s\n%s\n%s\n%s\n%d\n",obj1.firname,obj1.surname,obj1.key,obj1.phone,obj1.edu,obj1.salary,obj1.state);

 }

void displayAll(FILE *file)
{
    INFO obj;
    rewind(file);
    system("cls");
    printf("\n======================================================================================================================\n");
    printf("\n     First-name              Surname               Phone No.                   Education                   Salary\n");
    printf("\n======================================================================================================================\n");

     while(1)
    {
        fscanf(file,"%s %s %s %s %s %s %d",&obj.firname,&obj.surname,&obj.key,&obj.phone,&obj.edu,&obj.salary,&obj.state);
        if(feof(file))
            break;
      if(obj.state==1)
     {
    printf(" %15s\t%15s  \t%15s  \t%15s  \t%15s\n",obj.firname,obj.surname,obj.phone,obj.edu,obj.salary);
     }
    }
    printf("\n\n\n");
}



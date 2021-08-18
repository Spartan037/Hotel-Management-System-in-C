#include<stdlib.h>
#include <stdio.h>
#include<string.h>
class details
{
	public:
		int ID, key_number;
		char name[30], status[30];
		details()
		{
			strcpy(status,"Available"); 
		}
		void roomkey();
		void displayoccupied();
		void displaydetails();
		void deleteroom();		
}obj[10];

void displayoccupied()
{
	int count=0;
	for(int i=0; i<10; i++)
	{
		if(strcmp(obj[i].status,"Available")==0)
			count++; 
	}
	printf("\nNumber of Occupied rooms:%d",10-count);
}

void displaydetails(int key)
{
	for(int i=0; i<10; i++)
	{
		if(obj[i].key_number==key)
		{
			if(strcmp(obj[i].status,"Available")==0)
			{
				printf("\nThe room is empty!!");
			}
			else
			{
				printf("\nName: %s", obj[i].name);
				printf("\nID: %d", obj[i].ID);	
			}
		}
	}
}

void deleteroom()
{
	int key;
	printf("\nEnter the room number:");
	scanf("%d",&key);
	for(int i=0; i<10; i++)
	{	
		if(obj[i].key_number==key)
		{
			strcpy(obj[i].name,"NULL");
			strcpy(obj[i].status,"Available");
			obj[i].ID=0;
		}
	}
}

void roomkey()
{
	int id;
	printf("\nEnter ID:");
	scanf("%d",&id);
	for(int i=0; i<10; i++)
	{	
		if(obj[i].ID==id)
		{
			printf("\nRoom key number:%d", obj[i].key_number);
			break;
		}
	}
}
 
int main()     
{
	int choice, key=10, i=0, key1;
	while(1)
	{
		printf("\n\nOPTIONS:");
		printf("\n1) Reserve a room. \n2) Remove customer details. \n3) Number of occupied rooms. \n4) Details of customer. \n5) Room key using ID number. \n6) Exit \n");
		printf("\nEnter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				if(i==9)
				{
					for(int j=0; j<10; j++)
					{
						if(strcmp(obj[j].status, "Available")==0)
						{
							printf("\nEnter the ID number:");
							scanf("%d", &obj[j].ID);
							printf("\nEnter the name:");
							scanf("%s", obj[j].name);
							strcpy(obj[j].status,"Not Available");
							printf("\nRoom number alloted:%d", obj[j].key_number);
							break;			
						}	
					}	
				}
				else
				{
					printf("\nEnter the ID number:");
					scanf("%d", &obj[i].ID);
					printf("\nEnter the name:");
					scanf("%s", obj[i].name);
					obj[i].key_number=key;
					strcpy(obj[i].status,"Not Available");
					printf("\nRoom number alloted:%d", obj[i].key_number);
					key++;
					i++;
				}
				break;
			case 2:
				deleteroom();
				break;
			case 3:
				displayoccupied();
				break;
			case 4: 
				printf("\nEnter key number:");
				scanf("%d",&key1);
				displaydetails(key1);
				i++;
				break;
			case 5:
				roomkey();
				break;
			case 6:
				exit(0);
				break;
			default:
				printf("n Wrong Choice:n");
				break;
		}
	}
	return 0;
}


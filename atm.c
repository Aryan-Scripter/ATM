/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <string.h>

int atm(int, int*);
int compareAccount(char *,int);

struct account {
	char user[30];
	int password;
	int balance;
};
//globally accessable users
struct account accounts[7]= {
	{"Aryan Sinha",123,10000},
	{"Samridhi Shakti Singh",38,10000},
	{"Prachi Gupta",672,10000},
	{"Rishikesh Singh",567,10000},
	{"Abhijeet Raj",678,100000},
	{"Gaurav Kumar",000,10000}
};




int atm(int wid, int *balance) {
	int FIVE_HUNDRED=10,TWO_HUNDRED=5,HUNDRED=0, FIFTY=1;
	int count5=0,count2=0,count1=0,count50=0;

	if(wid%50!=0 ) { 
		printf("Enter a valid ammount");
		return 0;
	}

	if (wid > *balance) {
        printf("Insufficient balance.\n");
        return 0;
    }

	*balance=*balance-wid;

	while(wid>0 ) {
		if(FIVE_HUNDRED==0 && TWO_HUNDRED==0 && HUNDRED==0 && FIFTY== 0) {
			printf("out of cash");
				return -1;
		}

		if(wid>=500 && FIVE_HUNDRED>0) {
			wid-=500;
			count5++;
			FIVE_HUNDRED--;
		}
		else if(wid>=200 && TWO_HUNDRED>0) {
			wid-=200;
			count2++;
			TWO_HUNDRED--;
		}
		else if(wid>=100 && HUNDRED>0) {
			wid-=100;
			count1++;
			HUNDRED--;
		}
			else if(wid>=50 && FIFTY>0) {
			wid-=50;
			count50++;
			FIFTY--;
		}

	}

	
	printf("The amount of 500 notes withdrawn=%d \n",count5);
	printf("The amount of 200 notes withdrawn=%d \n",count2);
	printf("The amount of 100 notes withdrawn=%d \n",count1);
	printf("The amount of 50 notes withdrawn=%d \n",count50);
	

}

int compareAccount(char username[50],int password) {

	int i,bal=0,flag=0;

	for(i=0; i<7 ; i++) {

		if(strcmp(accounts[i].user, username)==0 && accounts[i].password==password) {
			//bal=accounts[i].balance;
			return i;
		}

	}

	return -1; //account not found

}



int main() {

	int wid=5000,index,pass;
	char username[50];

	printf("Enter user: ");
	fgets(username, 50, stdin);
	username[strcspn(username,"\n")] = '\0';

	printf("Enter password: ");
	scanf("%d",&pass);

	index=compareAccount(username,pass);
	// printf("%d\n",accounts[index].balance);
    // printf("IT WORKED");

	if(index==-1) {
		printf("Invalid user or password!");
		return 0;
	}
	atm(wid,&accounts[index].balance);
	printf("Remaining balance %d \n",accounts[index].balance);
    
	return 0;
}
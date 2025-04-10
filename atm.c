#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int atm(int, int*);
int compareAccount(char *,int);
void printMenu();
void clearScreen();

void clearScreen() {
	system("cls");
}

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

typedef struct {
	char user[30];
	int pass;
} login;

login loginAuth();


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
	
	return 0;
}

int compareAccount(char username[30],int password) {

	int i,bal=0,flag=0;

	for(i=0; i<7 ; i++) {

		if(strcmp(accounts[i].user, username)==0 && accounts[i].password==password) {
			//bal=accounts[i].balance;
			return i;
		}

	}

	return -1; //account not found

}

void printMenu() {
	printf("Menu:- \n");
	printf("1. Check balance\n");
	printf("2. Withdraw Money\n");
	printf("3. Login to another account\n");
	printf("4. Exit ATM\n");
}

login loginAuth() {
    login log;

	printf("\nEnter user: ");
	fgets(log.user, 30, stdin);
	log.user[strcspn(log.user,"\n")] = '\0';

	printf("Enter password: ");
	scanf("%d",&log.pass);

    // // Use strncpy to safely copy the string into the structure's array.
    // strncpy(log.user, user, sizeof(log.user) - 1);
    // // Ensure the string is null-terminated.
    // log.user[sizeof(log.user) - 1] = '\0';

    // // Assign the password.
    // log.pass = pass;

    // // Return the structure.
    return log;
}



int main() {

	int index,menu=0;
	login data;


	while(1) {
		printf("Welcome to ATM\n");
		data=loginAuth();
	    index=compareAccount(data.user,data.pass);
		if(index==-1) {
			printf("Invalid user or password!");
			return 0;
		}

		while(1) {
			printMenu();
			scanf("%d",&menu);
			if(menu>4 || menu<1) {
				printf("wrong option\n"); 
				continue;
			}
		
			switch(menu) {
				case 1:

				case 2:
				case 3:
				case 4:
				break;
		}

	}
}
	
	// printf("%d\n",accounts[index].balance);
    // printf("IT WORKED");

	
	//printf("%d",accounts[index].balance);
	
	// atm(wid,&accounts[index].balance);
	// printf("Remaining balance %d \n",accounts[index].balance);
    
	return 0;
}
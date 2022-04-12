#pragma warning(disable:4996)
#include<stdio.h>/* include standard library stdio.h for use of scanf(), printf(), fscanf() and fprintf() */ 
#include<string.h>/* include standard library string.h for use of strcmp(), strcpy() and getchar() */
#include<stdlib.h>/* inlcude standard library stdlib.h for use of exit() */
#include<conio.h>/* include standard library conio.h for use of getch() */

typedef struct _movie{   /* define a structure whose structure type is _movie containing the movies' data, and typedef it as Movie */
	char title[2000];
	int copies;
	char director[200];
	char actor[200];
	char limit[200];
	char type[200];
	int charge;
	int duration;
}Movie;

typedef struct _customer{   /* define a structure whose structure type is _customer containing the customers' data, and typedef it as Customer */
	char name[200];
	char age[200];
	char telephone[200];
	char movie[200];
	int remaining;
}Customer;

typedef struct _history{   /* define a structure whose structure type is _history containing the customers' rental history, and typedef it as History */
	char name[200];
	char title[200];
}History;

typedef struct _movie_node{   /* define a structure whose structure type is _movie_node containing the movies' data and a structure pointer, and typedef it as Movie_Node */
	Movie movies;
	struct _movie_node *pNext;
}Movie_Node;

typedef struct _customer_node{  /* define a structure whose structure type is _customer_node containing the customers' data and a structure pointer, and typedef it as Customer_Node */
	Customer customers;
	struct _customer_node *pNext;
}Customer_Node;

typedef struct _history_node{   /* define a structure whose structure type is _history_node containing the customers' rental history and a structure pointer, and typedef it as History_Node */
	History historys;
	struct _history_node *pNext;
}History_Node;

void Free_Linkedlist_Movie(Movie_Node *p);  /* define a funciton named Free_Linkedlist_Movie to free the linked list of type of Movie_Node */

Movie_Node *Read_File_Movie(); /* define a function named Read_File_Movie to read the data from the file */

int Whether_Same_Movie(char title[200]); /* define a function named Whether_Same_Movie to check wheteher the title of movie has already existed or not */

void Save_Movies(Movie *temp);  /* define a function named Save_Movies to save the movie's data into the file */

void Print_Movie_Interface();  /* define a function named Print_Movie_Interface to print the interface */

void Add_Movie(); /* deifne a funtion named Add_Movie to add the new movie */

void Print_Edit_Interface();  /* define a function named Print_Edit_Interface to print the interface */

void Edit_Title(char title[200]); /* define a functionn named Edit_Title to edit the title of the movie */

void Edit_Copies(char title[200]); /* define a function named Edit_Copies to edit the copies of the movie*/

void Secondary_Interface_Edit(char title[200]); /* define a function Secondary_Interface_Edit to print the interface */

void Edit_Movie_Interface();  /* define a fuction named Edit_Movie_Interface to edit */

void Delete_Movie(char title[200]); /* define a function named Delete_Movie to delete the movie */

void Delete_Movie_Interface(); /* define a function named Delete_Movie_Interface to delete */

void View_Current_Movies(); /* define a function named View_Current_Movies to view current movies */

void Movie_Interface(); /* define a function named Movie_Interface */

void Print_Manger_Interface(); /* define Print_Manger_Interface to print the manager interface */

void Manger_Interface();  /* define a function named Manger_Interface */

void Print_Cust_Interface(); /* define a function named Print_Cust_Interface to print the customer interface */

void Free_Linkedlist_Customer(Customer_Node *p); /* define a fuction named Free_Linkedlist_Customer free the linked list of type of Customer_Node */

Customer_Node *Read_File_Customer(); /* define a function named Read_File_Customer to read the data from the file */

int Whether_Same_Customer(char name[200]); /* define a function named Whether_Same_Customer to check wheteher the customer's name has already existed or not */

void Save_Customer(Customer *p);  /* define a function named Save_Customers to save the Customers' data into the file */

void Add_Customer();  /* deifne a funtion named Add_Customer to add the new movie */

void Print_Edit_Customer_Interface(); /* define a function named Print_Edit_Customer_Interface to print the interface */

void Edit_Customer_Interface();  /* define a function named Print_Edit_Customer_Interface */

void Write_Into_File_Customer(Customer_Node *p);   /* define a function named Write_Into_File_Customer to save the data into the file */

void Edit_Name(char name[200]); /* define a function named Edit_Name to edit the customer's name */

void Edit_Age(char name[200]);  /* define a function named Edit_Age to edit the customer's age */

void Edit_Telephone(char name[200]);  /* define a function named Edit_Telephone to edit the customer's telephone number */

void Edit_Remaining(char name[200]);  /* define a function named Edit_Remaining to edit the customer's remaining */

void Secondary_Interface_EditCust(char name[200]); /* define a function named Secondary_Interface_EditCust */

void Delete_Customer(char name[200]); /* define a function named Delete_Customer to delete a customer */

void Delete_Customer_Interface(); /* define a function named Delete_Customer_Interface */

void View_Customer();  /* denfine a function named View_Customer to view all the customers */

void Cust_Interface(); /* define a function named Cust_Interface */

void Print_Main_Interface();  /* define a function named Print_Main_Interface to print the main interface */

const char *Login(); /* define a function named Login */

void Print_Customer_Interface(); /* define a function named Print_Customer_Interface to print the customer interface */

void Write_Into_History();  /* define a function named Write_Into_History to record the rental history */

int Check_Remaining_and_Copies(char name[200], char movie[200]); /* define a function named Check_Remaining_and_Copies */

void Change_Remaining_and_Copies(char name[200], char movie[200]);  /* define a function named Change_Remaining_and_Copies */

void Rent_Movie(char name[200]);  /* define a function named Rent_Movie to rent the movie */

void Renew_Copies(char movie[200]); /* define a function named Renew_Copies to renew the copies */

void Retuen_Movie(char name[200]); /* define a function named Retuen_Movie to return the movie */

History_Node *Read_File_History(); /* define a function named Read_File_History to read the data from the file "History.txt" */

void Free_Linkedlist_History(History_Node *p); /* define a fnction named Free_Linkedlist_History to free the linked list of type of History_Node */

void View_Rental_History(char name[200]); /* define a function named View_Rental_History to view the rental history */

void View_Account(char name[200]);/* define a funcion */

void Customer_Interface(char name[200]);  /* define a function named Customer_Interface */

void Search(); /* define a function named Search to search the movie */

void Manager_Login(); /* define a function named Manager_Login for manager to log into the system */

void Main_Interface(); /* define a function named Main_Interface */

void Free_Linkedlist_Movie(Movie_Node *p){  /* free the linked list of type of Movie_Node one by one */
	Movie_Node *temp;
	temp = p;
	while (p){
		p = p->pNext;
		free(temp);
		temp = p;
	}
}

Movie_Node *Read_File_Movie(){  /* read the movies' data from the file "Movie.txt" */
	Movie_Node *pNewNode = NULL;
	Movie_Node *head = NULL;
	Movie_Node *p1 = NULL; /* declare three variables of type of Movie_Node */
	FILE *pFile; /* declare a variable of type of FILE */
	if ((pFile = fopen("Movie.txt", "a+")) == NULL){
		printf("\t\t\t\t\tfail to open the file\n");
		printf("\t\t\t\t\t");
		system("pause");
		exit(0);
	}
	pNewNode = (Movie_Node *)malloc(sizeof(Movie_Node));
	pNewNode->pNext = NULL;
	while ((fscanf(pFile, "%s\t%d\t%s\t%s\t%s\t%s\t%d\t%d\n", pNewNode->movies.title, &pNewNode->movies.copies, pNewNode->movies.director, pNewNode->movies.actor, pNewNode->movies.limit, pNewNode->movies.type, &pNewNode->movies.charge, &pNewNode->movies.duration)) != EOF){
		if (head == NULL){
			head = p1 = pNewNode;
		}
		else {
			p1->pNext = pNewNode;
			p1 = pNewNode;
		}
		pNewNode = (Movie_Node *)malloc(sizeof(Movie_Node));
		pNewNode->pNext = NULL;
	}  /* use the malloc to creat the linked list to read the data from the file */
	free(pNewNode);
	fclose(pFile);
	return head;
}

int Whether_Same_Movie(char title[200]){  /* check whether the title of movie has already existed */
	int ret = 1;
	Movie_Node *head, *p_temp;
	head = p_temp = Read_File_Movie();  /* call the Read_File_Movie function defined before */
	while (p_temp){
		if ((strcmp(p_temp->movies.title, title)) == 0){
			return ret;
		}
		p_temp = p_temp->pNext;
	}
	Free_Linkedlist_Movie(head); /* call the Free_Linkedlist_Movie defined before to free the linked list */
	ret = 0;
	return ret;
}

void Save_Movies(Movie *temp){  /* save the movie's data into the file "Movie.txt" */
	FILE *pFile;
	if ((pFile = fopen("Movie.txt", "a+")) == NULL){    /* check whether the file has been opened successfully */
		printf("\t\t\t\t\tfail to open the file\n");
		printf("\t\t\t\t\t");
		system("pause");
		exit(0);   /* if fail to open the file, quit the program automatically */
	}
	fprintf(pFile, "%s\t%d\t%s\t%s\t%s\t%s\t%d\t%d\n", temp->title, temp->copies, temp->director, temp->actor, temp->limit, temp->type, temp->charge, temp->duration);
	fclose(pFile);
}

void Print_Movie_Interface(){  /* print the interface */
	system("cls");
	printf("\t\t\t\tChoose what operation you want to do on the movies:\n");
	printf("\n");
	printf("\t\t\t\t\t1.Add the movies\n");
	printf("\n");
	printf("\t\t\t\t\t2.Edit the movies\n");
	printf("\n");
	printf("\t\t\t\t\t3.Delete the movies\n");
	printf("\n");
	printf("\t\t\t\t\t4.View current stock status\n");
	printf("\n");
	printf("\t\t\t\t\t0.Quit\n");
	printf("\n");
}

void Add_Movie(){  /* add a new movie */
	system("cls");
	Movie NewMovie;
	char title[200];
	int copies;
	char director[200];
	char actor[200];
	char limit[200];
	char type[200];
	int charge;
	int duration;
	printf("\t\t\t\t\tPlease input the title of movie(NOTE: Spaces are not allowed here)\n");
	printf("\n");
	while (1){   /* check whether the title has already existed or not */
		printf("\t\t\t\t\t");
		scanf("%s", title);
		fflush(stdin);   /* clear the error data from the input buffer */
		if (Whether_Same_Movie(title)){
			printf("\t\t\t\t\tYour input movie has already existed, please try agian\n");
			printf("\n");
		}
		else {
			strcpy(NewMovie.title, title);
			break;
		}
	}
	printf("\t\t\t\t\tPlease input the copies of movie\n");
	while (1){
		printf("\n");
		printf("\t\t\t\t\t");
		if ((scanf("%d", &copies)) != 1){
			printf("\t\t\t\t\tYour input is wrong, please try again\n");
			fflush(stdin);     /* clear the error data from the input buffer */
		}
		else if (copies <= 0){
			printf("\t\t\t\t\tYour input is wrong, please try again\n");
			fflush(stdin);     /* clear the error data from the input buffer */
		}
		else {
			fflush(stdin);     /* clear the error data from the input buffer */
			break;
		}
	}
	NewMovie.copies = copies;  /* input the copies */
	printf("\t\t\t\t\tPlease input the directors of movie(NOTE: Spaces are not allowed here)\n");
	printf("\n");
	printf("\t\t\t\t\t");
	scanf("%s", director);
	fflush(stdin);   /* clear the error data from the input buffer */
	strcpy(NewMovie.director, director);  /* input the director */
	printf("\t\t\t\t\tPlease input the actors of movie(NOTE: Spaces are not allowed here)\n");
	printf("\n");
	printf("\t\t\t\t\t");
	scanf("%s", actor);
	fflush(stdin);   /* clear the error data from the input buffer */
	strcpy(NewMovie.actor, actor);  /* input the actor */
	printf("\t\t\t\t\tPlease input the limit of movie\n");
	printf("\n");
	printf("\t\t\t\t\tIs it suitable for children? Please ONLY input 'Y' or 'N'\n");
	printf("\n");
	while (1){ /* input the limit */
		printf("\t\t\t\t\t");
		scanf("%s", limit);
		fflush(stdin);   /* clear the error data from the input buffer */
		if ((strcmp(limit, "Y")) == 0 || (strcmp(limit, "N")) == 0){ /* check whether the input is "N" or "Y" onlt */
			strcpy(NewMovie.limit, limit);
			break;
		}
		else {
			printf("\t\t\t\t\tYour input is wrong, please try again");
			printf("\n");
		}
	}
	printf("\t\t\t\t\tPlease input the type of movie(NOTE: Spaces are not allowed here)\n");
	printf("\n");
	printf("\t\t\t\t\t");
	scanf("%s", type);
	fflush(stdin);   /* clear the error data from the input buffer */
	strcpy(NewMovie.type, type); /* input the type of the movie */
	printf("\t\t\t\t\tPlease input the charge of movie\n");
	while (1){
		printf("\n");
		printf("\t\t\t\t\t");
		if ((scanf("%d", &charge)) != 1){
			printf("\t\t\t\t\tYour input is wrong, please try again\n");
			fflush(stdin);   /* clear the error data from the input buffer */
		}
		else if (charge <= 0){
			printf("\t\t\t\t\tYour input is wrong, please try again\n");
			fflush(stdin);     /* clear the error data from the input buffer */
		}
		else {
			fflush(stdin);   /* clear the error data from the input buffer */
			break;
		}
	}
	NewMovie.charge = charge; /* input the charge of the movie */
	printf("\t\t\t\t\tPlease input the rental duration\n");
	while (1){
		printf("\n");
		printf("\t\t\t\t\t");
		if ((scanf("%d", &duration)) != 1){
			printf("\t\t\t\t\tYour input is wrong, please try again\n");
			fflush(stdin);  /* clear the error data from the input buffer */
		}
		else if (duration <= 0){
			printf("\t\t\t\t\tYour input is wrong, please try again\n");
			fflush(stdin);     /* clear the error data from the input buffer */
		}
		else {
			fflush(stdin);  /* clear the error data from the input buffer */
			break;
		}
	}
	NewMovie.duration = duration;
	Save_Movies(&NewMovie);  /* save all of the data into the file "Movie.txt" */
	printf("\t\t\t\t\tYou have added it successfully!\n");
	printf("\n");
	printf("\t\t\t\t\t");
	system("pause");
}

void Print_Edit_Interface(){  /* print the interface */
	printf("\t\t\t\t\tWhich do you want yo edit on?\n");
	printf("\n");
	printf("\t\t\t\t\t1.Title\n");
	printf("\n");
	printf("\t\t\t\t\t2.Copies\n");
	printf("\n");
	printf("\t\t\t\t\t0.Quit\n");
	printf("\n");
}

void Edit_Title(char title[200]){  /* edit the title of the movie */
	char title_temp[200];
	FILE *pFile; /* declare a variable of type of FILE */
	printf("\t\t\t\t\tPlease input the new title\n");
	while (1){               /* check whether the input title has already existed */
		printf("\t\t\t\t\t");
		scanf("%s", title_temp);
		fflush(stdin);  /* clear the error data from the input buffer */
		if (Whether_Same_Movie(title_temp)){       /* call the Whether_Same_Movie function defined before */
			printf("\t\t\t\t\tYou input title has already existed, please input again\n");
		}
		else break;
	}
	Movie_Node *ptemp1, *ptemp2, *ptemp3;
	ptemp1 = ptemp2 = ptemp3 = Read_File_Movie();   /* call the Read_File_Movie function defined before to read the movies' data from the file "Movie.txt" */
	while (ptemp1){
		if ((strcmp(ptemp1->movies.title, title) == 0)){
			strcpy(ptemp1->movies.title, title_temp);
			break;
		}
		ptemp1 = ptemp1->pNext;
	}
	if ((pFile = fopen("Movie.txt", "w")) == NULL){  /* check whether the file has been opened successfully */
		printf("\t\t\t\t\tfail to open the file\n");
		printf("\t\t\t\t\t");
		system("pause");
		exit(0);   /* if fail to open the file, quit the program automaticallu */
	}
	fclose(pFile);  /* empty the data in the file "Movie.txt" firstly */
	if ((pFile = fopen("Movie.txt", "a+")) == NULL){  /* check whether the file has been opened successfully */
		printf("\t\t\t\t\tfail to open the file\n");
		printf("\t\t\t\t\t");
		system("pause");
		exit(0);   /* if fail to open the file, quit the program automaticallu */
	}
	while (ptemp2){
		fprintf(pFile, "%s\t%d\t%s\t%s\t%s\t%s\t%d\t%d\n", ptemp2->movies.title, ptemp2->movies.copies, ptemp2->movies.director, ptemp2->movies.actor, ptemp2->movies.limit, ptemp2->movies.type, ptemp2->movies.charge, ptemp2->movies.duration);
		ptemp2 = ptemp2->pNext;
	}
	fclose(pFile);                     /* save the latest data into the file "Movie.txt" */
	Free_Linkedlist_Movie(ptemp3);     /* free the linked list of type of Movie_Node */
	printf("\t\t\t\t\tYou have edited it successfully\n");
	printf("\n");
	printf("\t\t\t\t\t");
	system("pause");
}

void Edit_Copies(char title[200]){    /* edit the copies of the movie */
	int copies;
	FILE *pFile;  /* declare a variable of type of FILE */
	printf("\t\t\t\t\tPlease input the new copies\n");
	printf("\t\t\t\t\t");
	while (1){
		if ((scanf("%d", &copies)) != 1){/* input the new copies of the movie */
			printf("\t\t\t\t\tYour input is wrong, please try again\n");
			fflush(stdin);  /* clear the error data in the input buffer */
		}
		else if (copies <= 0){
			printf("\t\t\t\t\tYour input is wrong, please try again\n");
			fflush(stdin);     /* clear the error data from the input buffer */
		}
		else{
			fflush(stdin);  /* clear the error data from the input buffer */
			break;
		}
	}
	Movie_Node *ptemp1, *ptemp2, *ptemp3;
	ptemp1 = ptemp2 = ptemp3 = Read_File_Movie();  /* call the Read_File_Movie function deefined before to read the movies' data from the file "Movie.txt" */
	while (ptemp1){
		if ((strcmp(ptemp1->movies.title, title) == 0)){
			ptemp1->movies.copies = copies;
			break;
		}
		ptemp1 = ptemp1->pNext;
	}
	if ((pFile = fopen("Movie.txt", "w")) == NULL){  /* check whether the file has been opened successfully */
		printf("\t\t\t\t\tfail to open the file\n");
		printf("\t\t\t\t\t");
		system("pause");
		exit(0);   /* if fail to open the file, quit the program automaticallu */
	}
	fclose(pFile);  /* empty the data in the file "Movie.txt" firstly */
	if ((pFile = fopen("Movie.txt", "a+")) == NULL){     /* check whether the file has been opened successfully */
		printf("\t\t\t\t\tfail to open the file\n");
		printf("\t\t\t\t\t");
		system("pause");
		exit(0);   /* if fail to open the file, quit the program automatically */
	}
	while (ptemp2){
		fprintf(pFile, "%s\t%d\t%s\t%s\t%s\t%s\t%d\t%d\n", ptemp2->movies.title, ptemp2->movies.copies, ptemp2->movies.director, ptemp2->movies.actor, ptemp2->movies.limit, ptemp2->movies.type, ptemp2->movies.charge, ptemp2->movies.duration);
		ptemp2 = ptemp2->pNext;
	}
	fclose(pFile);  /* save the latest data into the file "Movie.txt" */
	Free_Linkedlist_Movie(ptemp3);  /* free the linked list of type of Movie_Node */
	printf("\t\t\t\t\tYou have edited it successfully\n");
	printf("\n");
	printf("\t\t\t\t\t");
	system("pause");
}

void Secondary_Interface_Edit(char title[200]){ /* provide the edit interface */
	int ret = 0;
	while (1){
		system("cls");
		char ch;
		Print_Edit_Interface();  /* call the Print_Edit_Interface function defined before to print the interface */
		ch = getch();
		switch (ch){  /* use the switch case to offer choices */
		case '1':
			Edit_Title(title);  /* call the Edit_Title function defined before to edit the title of the movie */
			break;
		case '2':
			Edit_Copies(title);  /* call the Edit_Copies defined before to edit the copied of the movie */
			break;
		case'0':
			ret = 1;
			printf("\t\t\t\t\tGoodbye\n");
			printf("\n");
			printf("\t\t\t\t\t");
			system("pause");
			break;
		default:
			break;
		}
		if (ret){  /* go back to the previous interface */
			break;
		}
	}
}

void Edit_Movie_Interface(){   /* log in to the edit interface */
	system("cls");
	char title[200];
	printf("\t\t\t\tPlease input the title of the movie that you want to edit\n");
	while (1){
		printf("\t\t\t\t\t");
		scanf("%s", title);   /* input the title of the movie */
		if (strcmp(title, "0") == 0){         /* if input "0", go back to the previous interface */
			printf("\t\t\t\t\tGoodbye\n");
			printf("\n");
			printf("\t\t\t\t\t");
			system("pause");
			break;
		}
		else if (!Whether_Same_Movie(title)){  /* check whether the title exists or not */
			printf("\t\t\t\tYou input movie does not exist, please try again. You can exit by inputting '0'\n");
		}
		else {
			Secondary_Interface_Edit(title);  /* go to the edit interface */
			break;
		}
	}
}

void Delete_Movie(char title[200]){  /* delete the movie */
	int ret = 1;
	FILE *pFile;  /* declare a variable of type of FILE */
	Movie_Node *ptemp1, *ptemp2, *ptemp3, *ptemp4; /* declare four variables of type of Movie_Node */
	ptemp1 = ptemp2 = ptemp3 = ptemp4 = Read_File_Movie();   /* call the Read_File_Movie function defined before to read the movies' data from the file "Movie.txt" */
	if ((strcmp(ptemp1->movies.title, title) == 0)){    /* if the movie is in the first of the linked list */
		ptemp1 = ptemp1->pNext;
		ptemp2 = ptemp1;
		if ((pFile = fopen("Movie.txt", "w")) == NULL){  /* check whether the file has been opened successfully */
			printf("\t\t\t\t\tfail to open the file\n");
			printf("\t\t\t\t\t");
			system("pause");
			exit(0);   /* if fail to open the file, quit the program automaticallu */
		}
		fclose(pFile);  /* empty the data in the file "Movie.txt" firstly */
		if ((pFile = fopen("Movie.txt", "a+")) == NULL){  /* check whether the file has been opened successfully */
			printf("\t\t\t\t\tfail to open the file\n");
			printf("\t\t\t\t\t");
			system("pause");
			exit(0);   /* if fail to open the file, quit the program automatically */
		}
		while (ptemp1){
			fprintf(pFile, "%s\t%d\t%s\t%s\t%s\t%s\t%d\t%d\n", ptemp1->movies.title, ptemp1->movies.copies, ptemp1->movies.director, ptemp1->movies.actor, ptemp1->movies.limit, ptemp1->movies.type, ptemp1->movies.charge, ptemp1->movies.duration);
			ptemp1 = ptemp1->pNext;
		}
		fclose(pFile);
		Free_Linkedlist_Movie(ptemp2);  /* call the Free_Linkedlist_Movie function defined before to free the linked list one by one */
		ret = 0;
		printf("\t\t\t\t\tYou have deleted it successfully\n");
		printf("\n");
		printf("\t\t\t\t\t");
		system("pause");
	}  /* delete the movie by operating the linked list and save the latest data into the file "Movie.txt" */
	if (ret){                       /* if the movie is not in the first of the linked list */
		while (ptemp1){
			if ((strcmp(ptemp1->movies.title, title) == 0)){
				ptemp2->pNext = ptemp1->pNext;
				break;
			}
			ptemp2 = ptemp1;
			ptemp1 = ptemp1->pNext;
		}
		if ((pFile = fopen("Movie.txt", "w")) == NULL){  /* check whether the file has been opened successfully */
			printf("\t\t\t\t\tfail to open the file\n");
			printf("\t\t\t\t\t");
			system("pause");
			exit(0);   /* if fail to open the file, quit the program automaticallu */
		}
		fclose(pFile); /* empty the data in the file "Movie.txt" firstly */
		if ((pFile = fopen("Movie.txt", "a+")) == NULL){  /* check whether the file has been opened successfully */
			printf("\t\t\t\t\tfail to open the file\n");
			printf("\t\t\t\t\t");
			system("pause");
			exit(0);   /* if fail to open the file, quit the program automatically */
		}
		while (ptemp3){
			fprintf(pFile, "%s\t%d\t%s\t%s\t%s\t%s\t%d\t%d\n", ptemp3->movies.title, ptemp3->movies.copies, ptemp3->movies.director, ptemp3->movies.actor, ptemp3->movies.limit, ptemp3->movies.type, ptemp3->movies.charge, ptemp3->movies.duration);
			ptemp3 = ptemp3->pNext;
		}
		fclose(pFile);  /* write the latest data into the file "Movie.txt" */
		Free_Linkedlist_Movie(ptemp4);  /* call the Free_Linkedlist_Movie function defined before to free the linked list one by one */
		printf("\t\t\t\t\tYou have deleted it successfully\n");
		printf("\n");
		printf("\t\t\t\t\t");
		system("pause");
	}    /* delete the movie by operating the linked list and save the latest data into the file "Movie.txt" */
}

void Delete_Movie_Interface(){  /* input the title of the movie that you want to delete */
	system("cls");
	char title[200];
	printf("\t\t\t\t\tPlease input the title of the movie that you want to delete\n");
	while (1){
		printf("\t\t\t\t\t");
		scanf("%s", title);
		fflush(stdin);  /* clear the error data from the input buffer */
		if (strcmp(title, "0") == 0){  /* if input "0, go back to the previous interface */
			printf("\t\t\t\t\tGoodbye\n");
			printf("\n");
			printf("\t\t\t\t\t");
			system("pause");
			break;
		}
		else if (!Whether_Same_Movie(title)){ /* check whether the input movie exists or not  */
			printf("\t\t\t\t\tYou input movie does not exist, please try again. You can exit by inputting '0'\n");
		}
		else {
			Delete_Movie(title);   /* go to the delete interface */
			break;
		}
	}
}

void View_Current_Movies(){    /* view the current movies */
	Movie_Node *ptemp1, *ptemp2;   /* declare three variables of type of Movir_Node */
	ptemp1 = ptemp2 = Read_File_Movie();   /* call the Read_File_Movie function defined before to read the movies' data from the file "Movie.txt" */
	while (ptemp1){
		printf("\t\t\t\tTitle:¡¶%s¡·\tCopies:%d\tCharges:%d\n", ptemp1->movies.title, ptemp1->movies.copies, ptemp1->movies.charge);  /* print the current movies one by one */
		printf("\n");
		ptemp1 = ptemp1->pNext;
	}
	Free_Linkedlist_Movie(ptemp2);   /* call the Free_Linkedlist_Movie function defined before to free the linked list one by one */
	printf("\t\t\t\t\t");
	system("pause");
}

void Print_Manger_Interface(){  /* print the manager interface */
	system("cls");
	printf("\t\t\t\t\tWhich object do you want to operate on?\n");
	printf("\n");
	printf("\t\t\t\t\t\t1.Moives\n");
	printf("\n");
	printf("\t\t\t\t\t\t2.Customers\n");
	printf("\n");
	printf("\t\t\t\t\t\t0.Quit\n");
	printf("\n");
}

void Movie_Interface(){
	system("cls");
	int ret = 0;
	while (1){
		char ch;
		Print_Movie_Interface();  /* call the Print_Movie_Interface function defined before to print the interface */
		ch = getch();
		switch (ch){  /* do the switch case to provide the choices */
		case '1':
			Add_Movie(); /* call the Add_Movie function defined to add the movie */
			break;
		case '2':
			Edit_Movie_Interface(); /* call the Edit_Movie_Interface defined before */
			break;
		case '3':
			Delete_Movie_Interface();  /* call the Delete_Movie_Interface function defined before */
			break;
		case '4':
			View_Current_Movies();  /* call the View_Current_Movies function defined before */
			break;
		case'0':
			ret = 1;
			printf("\t\t\t\t\tGoodbye\n");
			printf("\n");
			printf("\t\t\t\t\t");
			system("pause");
			break;
		default:
			break;
		}
		if (ret){  /* if tet=1, go back to the previous interface */
			break;
		}
	}
}

void Print_Cust_Interface(){  /* print the interface */
	system("cls");
	printf("\t\t\t\tChoose what operation you want to do on the customers:\n");
	printf("\n");
	printf("\t\t\t\t\t1.Add a new customer\n");
	printf("\n");
	printf("\t\t\t\t\t2.Edit the customer\n");
	printf("\n");
	printf("\t\t\t\t\t3.Delete a customer\n");
	printf("\n");
	printf("\t\t\t\t\t4.View all the customers\n");
	printf("\n");
	printf("\t\t\t\t\t0.Quit\n");
	printf("\n");
}

void Free_Linkedlist_Customer(Customer_Node *p){    /* free the linked list of type of Customer_Node on by one */
	Customer_Node *temp;
	temp = p;
	while (p){
		p = p->pNext;
		free(temp);
		temp = p;
	}
}

Customer_Node *Read_File_Customer(){   /* read the customer' data from the file "Customer.text" */
	Customer_Node *pNewNode = NULL;
	Customer_Node *head = NULL;
	Customer_Node *p1 = NULL;  /* declare three variables of type of Customer_Node */
	FILE *pFile;  /* declare a variable of type of FILE */
	if ((pFile = fopen("Customer.txt", "a+")) == NULL){  /* check whether the file has been opened sucessfully */
		printf("\t\t\t\t\tfail to open the file\n");
		printf("\t\t\t\t\t");
		system("pause");
		exit(0);  /* if fail to open the file, quit the program automatically */
	}
	pNewNode = (Customer_Node *)malloc(sizeof(Customer_Node));
	pNewNode->pNext = NULL;
	while ((fscanf(pFile, "%s\t%s\t%s\t%s\t%d\n", pNewNode->customers.name, pNewNode->customers.age, pNewNode->customers.telephone, pNewNode->customers.movie, &pNewNode->customers.remaining)) != EOF){
		if (head == NULL){
			head = p1 = pNewNode;
		}
		else {
			p1->pNext = pNewNode;
			p1 = pNewNode;
		}
		pNewNode = (Customer_Node *)malloc(sizeof(Customer_Node));
		pNewNode->pNext = NULL;
	}   /* use the malloc to creat the linked list to read the data from the file */
	free(pNewNode);
	fclose(pFile);
	return head;
}

int Whether_Same_Customer(char name[200]){  /* check whether the customer's name has already existed */
	int ret = 1;
	Customer_Node *ptemp1, *ptemp2;
	ptemp1 = ptemp2 = Read_File_Customer();  /* call the Read_File_Customer function defined before to read the customers' data from the file "Customer.txt"*/
	while (ptemp1){
		if ((strcmp(ptemp1->customers.name, name)) == 0){
			Free_Linkedlist_Customer(ptemp2);
			return ret;
		}
		ptemp1 = ptemp1->pNext;
	}
	Free_Linkedlist_Customer(ptemp2);  /* call the Free_Linkedlist_Customer function to free the linked list one by one */
	ret = 0;
	return ret;
}

void Save_Customer(Customer *p){  /* save the customer's data into the file "Customer.txt" */
	FILE *pFile;  /* declare a pointer variable of type of FILE */
	if ((pFile = fopen("Customer.txt", "a+")) == NULL){  /* check whether the file has been opened sucessfully */
		printf("\t\t\t\t\tfail to open the file\n");
		printf("\t\t\t\t\t");
		system("pause");
		exit(0);  /* if fail to open the file, quit the program automatically */
	}
	fprintf(pFile, "%s\t%s\t%s\t%s\t%d\n", p->name, p->age, p->telephone, p->movie, p->remaining);
	fclose(pFile);
}

void Add_Customer(){  /* add a new customer */
	Customer NewCustomer;
	char name[200];
	char age[200];
	char telephone[200];
	int remaining;
	printf("\t\t\t\t\tPlease input the customer's name (CAUTION: Spaces are not allowed here)\n");
	printf("\n");
	while (1){
		printf("\t\t\t\t\t");
		scanf("%s", name);  /* input the customer's name */
		fflush(stdin);  /* clear the error data from the input buffer */
		if (Whether_Same_Customer(name)){  /* check whether the input customer's name has already existed */
			printf("\t\t\t\t\tYour input customer has already existed, please try agian\n");
			printf("\n");
		}
		else {
			strcpy(NewCustomer.name, name);
			break;
		}
	}
	printf("\t\t\t\t\tPlease input the customer's age(CAUTION: Spaces are not allowed here)\n");
	printf("\n");
	printf("\t\t\t\t\t");
	scanf("%s", age);  /* input the customer's age */
	fflush(stdin);  /* clear the error data from the input buffer */
	strcpy(NewCustomer.age, age);
	printf("\t\t\t\t\tPlease input the customer's telephone(CAUTION: Spaces are not allowed here)\n");
	printf("\n");
	printf("\t\t\t\t\t");
	scanf("%s", telephone); /* input the customer's telephone */
	fflush(stdin);  /* clear the error data from the input buffer */
	strcpy(NewCustomer.telephone, telephone);
	strcpy(NewCustomer.movie, "N");
	printf("\t\t\t\t\tPlease input the customer's remaining\n");
	while (1){
		printf("\n");
		printf("\t\t\t\t\t");
		if ((scanf("%d", &remaining)) != 1){ /* input the customer's remaining */
			printf("\t\t\t\t\tYour input is wrong, please try again\n");
			fflush(stdin);
		}
		else if (remaining <= 0){
			printf("\t\t\t\t\tYour input is wrong, please try again\n");
			fflush(stdin);     /* clear the error data from the input buffer */
		}
		else{
			fflush(stdin);
			break;
		}
	}
	NewCustomer.remaining = remaining;
	Save_Customer(&NewCustomer);  /* call the Save_Customer defined before to save all of the customer's data into the file "Customer.txt" */
	printf("\t\t\t\t\tYou have added it successfully!\n");
	printf("\n");
	printf("\t\t\t\t\t");
	system("pause");
}

void Print_Edit_Customer_Interface(){  /* print the interface */
	printf("\t\t\t\t\tWhich do you want yo edit on?\n");
	printf("\n");
	printf("\t\t\t\t\t1.Name\n");
	printf("\n");
	printf("\t\t\t\t\t2.Age\n");
	printf("\n");
	printf("\t\t\t\t\t3.Telephone\n");
	printf("\n");
	printf("\t\t\t\t\t4.Remaining\n");
	printf("\n");
	printf("\t\t\t\t\t0.Quit\n");
	printf("\n");
}

void Write_Into_File_Customer(Customer_Node *p){  /* save the customer's data which is in the linked list into the file "Customer.txt" */
	FILE *pFile;  /* declare a pointer variable of type of FILE */
	if ((pFile = fopen("Customer.txt", "w")) == NULL){  /* check whether the file has been opened successfully */
		printf("\t\t\t\t\tfail to open the file\n");
		printf("\t\t\t\t\t");
		system("pause");
		exit(0);   /* if fail to open the file, quit the program automaticallu */
	}
	fclose(pFile);  /* empty the data in the file "Customer.txt" firstly */
	if ((pFile = fopen("Customer.txt", "a+")) == NULL){  /* check whether the file has been opened sucessfully */
		printf("\t\t\t\t\tfail to open the file\n");
		printf("\t\t\t\t\t");
		system("pause");
		exit(0);  /* if fail to open the file, quit the program automatically */
	}
	while (p){    /* write the data into the file "Customer.text" one by one by using a while() loop */
		fprintf(pFile, "%s\t%s\t%s\t%s\t%d\n", p->customers.name, p->customers.age, p->customers.telephone, p->customers.movie, p->customers.remaining);
		p = p->pNext;
	}
	fclose(pFile);
}

void Edit_Name(char name[200]){   /* edit the customer's name */
	char name_temp[200];
	printf("\t\t\t\t\tPlease input the customer's new name\n");
	printf("\t\t\t\t\t");
	while (1){
		printf("\t\t\t\t\t");
		scanf("%s", name_temp);  /* input the customer's name */
		fflush(stdin);  /* clear the error data from the input buffer */
		if (Whether_Same_Customer(name_temp)){  /* check whether the customer's name has already existed */
			printf("\t\t\t\t\tYou input name has already existed, please input again\n");
			printf("\n");
		}
		else{
			fflush(stdin);  /* clear the error data from the input buffer */
			break;
		}
	}
	Customer_Node *ptemp1, *ptemp2, *ptemp3;  /* declare three structure variables of type of Customer_Node */
	ptemp1 = ptemp2 = ptemp3 = Read_File_Customer();  /* call the Read_File_Customer function defined before to read the customers' data from the file "Customer.txt"*/
	while (ptemp1){  /* find the linked list containing the corresponding customer's name */
		if ((strcmp(ptemp1->customers.name, name) == 0)){
			strcpy(ptemp1->customers.name, name_temp);
			break;
		}
		ptemp1 = ptemp1->pNext;
	}
	Write_Into_File_Customer(ptemp2);  /* call the Write_Into_File_Customer function defined before to save the latest data into the file "Customer.txt" */
	printf("\t\t\t\t\tYou have edited it successfully\n");
	printf("\n");
	printf("\t\t\t\t\t");
	system("pause");
	Free_Linkedlist_Customer(ptemp3);  /* call the Free_Linkedlist_Customer function to free the linked list one by one */
}

void Edit_Age(char name[200]){   /* edit the customer's age  */
	char age_temp[200];
	printf("\t\t\t\t\tPlease input the customer's new age\n");
	printf("\t\t\t\t\t");
	scanf("%s", age_temp);  /* input the customer's new age */
	fflush(stdin);  /* clear the error data from the input buffer */
	Customer_Node *ptemp1, *ptemp2, *ptemp3;   /* declare three structure variables of type of Customer_Node */
	ptemp1 = ptemp2 = ptemp3 = Read_File_Customer();  /* call the Read_File_Customer function defined before to read the customers' data from the file "Customer.txt"*/
	while (ptemp1){  /* find the linked list containing the corresponding customer's name */
		if ((strcmp(ptemp1->customers.name, name) == 0)){
			strcpy(ptemp1->customers.age, age_temp);
			break;
		}
		ptemp1 = ptemp1->pNext;
	}
	Write_Into_File_Customer(ptemp2);   /* call the Write_Into_File_Customer function defined before to save the latest data into the file "Customer.txt" */
	printf("\t\t\t\t\tYou have edited it successfully\n");
	printf("\n");
	printf("\t\t\t\t\t");
	system("pause");
	Free_Linkedlist_Customer(ptemp3);  /* call the Free_Linkedlist_Customer function to free the linked list one by one */
}

void Edit_Telephone(char name[200]){   /* edit the customer's telephone number */
	char telephone_temp[200];
	printf("\t\t\t\t\tPlease input the customer's new telephone\n");
	printf("\t\t\t\t\t");
	scanf("%s", telephone_temp);  /* input the customer's new telephone number */
	fflush(stdin);  /* clear the error data from the input buffer */
	Customer_Node *ptemp1, *ptemp2, *ptemp3;  /* declare three structure variables of type of Customer_Node */
	ptemp1 = ptemp2 = ptemp3 = Read_File_Customer();  /* call the Read_File_Customer function defined before to read the customers' data from the file "Customer.txt" */
	while (ptemp1){  /* find the linked list containing the corresponding customer's name */
		if ((strcmp(ptemp1->customers.name, name) == 0)){
			strcpy(ptemp1->customers.telephone, telephone_temp);
			break;
		}
		ptemp1 = ptemp1->pNext;
	}
	Write_Into_File_Customer(ptemp2); /* call the Write_Into_File_Customer function defined before to save the latest data into the file "Customer.txt" */
	printf("\t\t\t\t\tYou have edited it successfully\n");
	printf("\n");
	printf("\t\t\t\t\t");
	system("pause");
	Free_Linkedlist_Customer(ptemp3);    /* call the Free_Linkedlist_Customer function to free the linked list one by one */
}

void Edit_Remaining(char name[200]){   /* edit the customer's remaining */
	int remaining_temp;
	printf("\t\t\t\t\tPlease input the customer's new remaining\n");
	while (1){
		printf("\t\t\t\t\t");
		if ((scanf("%d", &remaining_temp)) != 1){ /* input the customer's new remaining */
			printf("\t\t\t\t\tYour input is wrong, please try again\n");
			fflush(stdin);
		}
		else {
			fflush(stdin);
			break;
		}
	}
	Customer_Node *ptemp1, *ptemp2, *ptemp3;  /* declare three structure variables of type of Customer_Node */
	ptemp1 = ptemp2 = ptemp3 = Read_File_Customer();  /* call the Read_File_Customer function defined before to read the customers' data from the file "Customer.txt" */
	while (ptemp1){   /* find the linked list containing the corresponding customer's name */
		if ((strcmp(ptemp1->customers.name, name) == 0)){
			ptemp1->customers.remaining = remaining_temp;
			break;
		}
		ptemp1 = ptemp1->pNext;
	}
	Write_Into_File_Customer(ptemp2); /* call the Write_Into_File_Customer function defined before to save the latest data into the file "Customer.txt" */
	printf("\t\t\t\t\tYou have edited it successfully\n");
	printf("\n");
	printf("\t\t\t\t\t");
	system("pause");
	Free_Linkedlist_Customer(ptemp3); /* call the Free_Linkedlist_Customer function to free the linked list one by one */
}


void Secondary_Interface_EditCust(char name[200]){  /* the edit_customer interface */
	int ret = 0;
	while (1){
		system("cls");
		char ch;
		Print_Edit_Customer_Interface();  /* call the Print_Edit_Customer_Interface function defined before to print the interfacce */
		ch = getch();
		switch (ch){  /* do the switch case to provide choices */
		case '1':
			Edit_Name(name);      /* call the Edit_Name function defined to edit the customer's name */
			break;
		case '2':
			Edit_Age(name);      /* call the Edit_Age funtcion defined before to edit the age */
			break;
		case '3':
			Edit_Telephone(name); /* call Edit_Telephone function defined before to edit the telephone */
			break;
		case'4':
			Edit_Remaining(name);  /* call the Edit_Remaining function defined before to edit the remaining */
			break;
		case'0':
			ret = 1;
			printf("\t\t\t\t\tGoodbye\n");
			printf("\n");
			printf("\t\t\t\t\t");
			system("pause");
			break;
		default:
			break;
		}
		if (ret){  /* if ret =1, go back to the previous interface */
			break;
		}
	}
}

void Edit_Customer_Interface(){   /* provide the interface */
	system("cls");
	char name[200];
	printf("\t\t\t\tPlease input the customer's name that you want to edit\n");
	while (1){
		printf("\t\t\t\t\t");
		scanf("%s", name); /* input the name */
		fflush(stdin);  /* clear the error data from the input buffer */
		if (strcmp(name, "0") == 0){  /* if input "0", go back to the previous interface */
			printf("\t\t\t\t\tGoodbye\n");
			printf("\n");
			printf("\t\t\t\t\t");
			system("pause");
			break;
		}
		else if (!Whether_Same_Customer(name)){  /* check whether the input name has already existed or not */
			printf("\t\t\t\tYou input name does not exist, please try again. You can quit by inputting '0'\n");
		}
		else {
			Secondary_Interface_EditCust(name);   /* go to the edit interface */
			break;
		}
	}
}

void Delete_Customer(char name[200]){  /* delete a customer */
	int ret = 1;
	FILE *pFile;  /* define a pointer variable of type of FILE */
	Customer_Node *ptemp1, *ptemp2, *ptemp3, *ptemp4; /* declare three structure variables of type of Customer_Node to */
	ptemp1 = ptemp2 = ptemp3 = ptemp4 = Read_File_Customer(); /* call the Read_File_Customer function defined before to read the customers' data from the file "Customer.txt" */
	if ((strcmp(ptemp1->customers.name, name) == 0)){ /* if the customer' name is in the first of the linked list */
		ptemp1 = ptemp1->pNext;
		ptemp2 = ptemp1;
		if ((pFile = fopen("Customer.txt", "w")) == NULL){  /* check whether the file has been opened successfully */
			printf("\t\t\t\t\tfail to open the file\n");
			printf("\t\t\t\t\t");
			system("pause");
			exit(0);   /* if fail to open the file, quit the program automaticallu */
		}
		fclose(pFile);  /* empty the data in the file "Customer.txt" firstly */
		if ((pFile = fopen("Customer.txt", "a+")) == NULL){  /* check whether the file has been opened sucessfully */
			printf("\t\t\t\t\tfail to open the file\n");
			printf("\t\t\t\t\t");
			system("pause");
			exit(0);  /* if fail to open the file, quit the program automatically */
		}
		while (ptemp1){
			fprintf(pFile, "%s\t%s\t%s\t%s\t%d\n", ptemp1->customers.name, ptemp1->customers.age, ptemp1->customers.telephone, ptemp1->customers.movie, ptemp1->customers.remaining);
			ptemp1 = ptemp1->pNext;
		}
		fclose(pFile);
		Free_Linkedlist_Customer(ptemp2);  /* call the Free_Linkedlist_Customer function defined before to free the linked list one by one */
		ret = 0;
		printf("\t\t\t\t\tYou have deleted it successfully\n");
		printf("\n");
		printf("\t\t\t\t\t");
		system("pause");
	}  /* delete the customer by operating the linked list and save the latest data into the file "Movie.txt" */
	if (ret){   /* if the customer's name is not in the first of the linked list */
		while (ptemp1){
			if ((strcmp(ptemp1->customers.name, name) == 0)){
				ptemp2->pNext = ptemp1->pNext;
				break;
			}
			ptemp2 = ptemp1;
			ptemp1 = ptemp1->pNext;
		}
		if ((pFile = fopen("Customer.txt", "w")) == NULL){  /* check whether the file has been opened successfully */
			printf("\t\t\t\t\tfail to open the file\n");
			printf("\t\t\t\t\t");
			system("pause");
			exit(0);   /* if fail to open the file, quit the program automaticallu */
		}
		fclose(pFile);  /* empty the data in the file "Customer.txt" firstly */
		if ((pFile = fopen("Customer.txt", "a+")) == NULL){  /* check whether the file has been opened sucessfully */
			printf("\t\t\t\t\tfail to open the file\n");
			printf("\t\t\t\t\t");
			system("pause");
			exit(0);  /* if fail to open the file, quit the program automatically */
		}
		while (ptemp3){
			fprintf(pFile, "%s\t%s\t%s\t%d\n", ptemp3->customers.name, ptemp3->customers.age, ptemp3->customers.telephone, ptemp3->customers.remaining);
			ptemp3 = ptemp3->pNext;
		}
		fclose(pFile);
		Free_Linkedlist_Customer(ptemp4); /* call the Free_Linkedlist_Customer function defined before to free the linked list one by one */
		printf("\t\t\t\t\tYou have deleted it successfully\n");
		printf("\n");
		printf("\t\t\t\t\t");
		system("pause");
	}   /* delete the customer by operating the linked list and save the latest data into the file "Movie.txt" */
}

void Delete_Customer_Interface(){  /* provide the delete interface */
	system("cls");
	char name[200];
	printf("\t\t\t\t\tPlease input the customer' name that you want to delete\n");
	while (1){
		printf("\t\t\t\t\t");
		scanf("%s", name);  /* input the name that ou want to delete */
		fflush(stdin);  /* clear the error data from the input buffer */
		if (strcmp(name, "0") == 0){   /* if input "0", go back to the previous interface */
			printf("\t\t\t\t\tGoodbye\n");
			printf("\n");
			printf("\t\t\t\t\t");
			system("pause");
			break;
		}
		else if (!Whether_Same_Customer(name)){  /* check whether the input name has already existed or not */
			printf("\t\t\t\tYou input customer does not exist, please try again. You can quit by inputting '0'\n");
		}
		else {
			Delete_Customer(name); /* go to the delete interface */
			break;
		}
	}
}

void View_Customer(){
	Customer_Node *temp1, *temp2;
	temp1 = temp2 = Read_File_Customer();  /* call the Read_File_Customer defiend before to read the data from the file "Customer.txt" */
	while (temp1){  /* print the corresponding data one by one */
		printf("\t\t\t\tName:%s\tAge:%d\tTelephone:%s\tRemainging:%d\n", temp1->customers.name, temp1->customers.age, temp1->customers.telephone, temp1->customers.remaining);
		temp1 = temp1->pNext;
	}
	printf("\t\t\t\t\t");
	system("pause");
	Free_Linkedlist_Customer(temp2);  /* call the Free_Linkedlist_Customer defined before to free the linked list of type of Customer_Node */
}

void Cust_Interface(){  /* provide the interface */
	system("cls");
	int ret = 0;
	while (1){
		char ch;
		Print_Cust_Interface();  /* call the Print_Cust_Interface function defined before to print the interface*/
		ch = getch();
		switch (ch){   /* do the switch case interface to provide the choices */
		case '1':
			Add_Customer(); /* call the Add_Customer fucntion to add a new customer */
			break;
		case '2':
			Edit_Customer_Interface();  /* call the Edit_Customer_Interface function defined before */
			break;
		case '3':
			Delete_Customer_Interface(); /* call the Delete_Customer_Interface function defined before */
			break;
		case'4':
			View_Customer();  /* call the View_Customer function defined before to view all the customers */
			break;
		case'0':
			ret = 1;
			printf("\t\t\t\t\tGoodbye\n");
			printf("\n");
			printf("\t\t\t\t\t");
			system("pause");
			break;
		default:
			break;
		}
		if (ret){  /* if ret =1, go back to the previous interface */
			break;
		}
	}
}

void Manger_Interface(){  /* provide the manager interface */
	system("cls");
	int ret = 0;
	while (1){
		char ch;
		Print_Manger_Interface();  /* call the Print_Manger_Interface defined before to print the interface */
		ch = getch();
		switch (ch){  /* do the switch case interface to provide the choices */
		case '1':
			Movie_Interface();   /* call the Movie_Interface function defined before */
			break;
		case '2':
			Cust_Interface();   /* call the Cust_Interface function defined before */
			break;
		case'0':
			ret = 1;
			printf("\t\t\t\t\tGoodbye\n");
			printf("\n");
			printf("\t\t\t\t\t");
			system("pause");
			break;
		default:
			break;
		}
		if (ret){ /* if ret=1, go back to the previous interface */
			break;
		}
	}
}

void Print_Main_Interface(){  /* print the interface */
	system("cls");
	printf("\t\t\t\t\t==================WELCOME==================\n");
	printf("\n");
	printf("\t\t\t\t\t================WHO ARE YOU================\n");
	printf("\n");
	printf("\t\t\t\t\t=========1.Manager========2.Customer========\n");
	printf("\n");
	printf("\t\t\t\t\t==================0.Exit===================\n");
	printf("\n");
}

const char *Login(){  /* provide the login interface to the customer */
	system("cls");
	static char name[200];
	printf("\t\t\t\t\t\tWELCOME\n");
	printf("\n");
	printf("\t\t\t\t\tPlease input you name\n");
	printf("\n");
	printf("\t\t\t\t\t");
	scanf("%s", name);  /* input the name */
	fflush(stdin);  /* clear the error data from the input buffer */
	if ((Whether_Same_Customer(name)) == 0){  /* check whether the input name exists or not */
		printf("\t\t\t\t\tYou input name does not exist\n");
		printf("\n");
		printf("\t\t\t\t\t");
		system("pause");
		return "0";
	}
	return name;
}

void Print_Customer_Interface(){  /* print the interface */
	system("cls");
	printf("\t\t\t\t\tWhich operation do you want to do?\n");
	printf("\n");
	printf("\t\t\t\t\t1.Rent movie\n");
	printf("\n");
	printf("\t\t\t\t\t2.Return movie\n");
	printf("\n");
	printf("\t\t\t\t\t3.Search the movies\n");
	printf("\n");
	printf("\t\t\t\t\t4.View current stock status\n");
	printf("\n");
	printf("\t\t\t\t\t5.View your rental history\n");
	printf("\n");
	printf("\t\t\t\t\t6.View your account remaining\n");
	printf("\n");
	printf("\t\t\t\t\t0.Quit\n");
	printf("\n");
}

int check(char name[200]){
	int ret = 0;
	Customer_Node *ptemp1, *ptemp2;  /* declare two structure variables of type of Customer_Node */
	ptemp1 = ptemp2 = Read_File_Customer();   /* call the Read_File_Customer function defined before to read the customers' data from the file "Customer.txt" */
	while (ptemp1){
		if (strcmp(ptemp1->customers.name, name) == 0){   /* check whether the customer has already rented one movie or not */
			if (strcmp(ptemp1->customers.movie, "N") == 0){
				ret = 1;
				Free_Linkedlist_Customer(ptemp2);  /* call the Free_Linkedlist_Customer function defined before to free the linked list one by one */
				return ret;
			}
		}
		ptemp1 = ptemp1->pNext;
	}
	Free_Linkedlist_Customer(ptemp2);  /* call the Free_Linkedlist_Customer function defined before to free the linked list one by one */
	return ret;
}

void Write_Into_History(History *temp){  /* save the customer's rental history into the file "History.txt" */
	FILE *pFile;
	if ((pFile = fopen("History.txt", "a+")) == NULL){  /* check whether the file has been opened sucessfully */
		printf("\t\t\t\t\tfail to open the file\n");
		printf("\t\t\t\t\t");
		system("pause");
		exit(0);  /* if fail to open the file, quit the program automatically */
	}
	fprintf(pFile, "%s\t%s\n", temp->name, temp->title);
	fclose(pFile);
}

int Check_Remaining_and_Copies(char name[200], char movie[200]){  /* check the copies of the movie and the customer's remaining */
	int ret = 0;
	int copies;
	Customer m;
	Movie n;
	Customer_Node *temp1, *temp2, *temp3; /* declare three strcucture variables of type of Customer_Node */
	temp1 = temp2 = temp3 = Read_File_Customer();   /* call the Read_File_Customer function defined before to read the customers' data from the file "Customer.txt" */
	Movie_Node *ptemp1, *ptemp2, *ptemp3;
	ptemp1 = ptemp2 = ptemp3 = Read_File_Movie();  /* call the Read_File_Customer function defined before to read the movies' data from the file "Movie.txt" */
	while (temp1){  /* find the corresponding linked list by the name */
		if ((strcmp(temp1->customers.name, name)) == 0){
			m.remaining = temp1->customers.remaining;
			break;
		}
		temp1 = temp1->pNext;
	}
	Free_Linkedlist_Customer(temp2);  /* call the Free_Linkedlist_Customer function defined before to free the linked list one by one */
	while (ptemp1){    /* find the corresponding linked list by the title of the movie */
		if ((strcmp(ptemp1->movies.title, movie)) == 0){
			n.charge = ptemp1->movies.charge;
			copies = ptemp1->movies.copies;
			break;
		}
		ptemp1 = ptemp1->pNext;
	}
	Free_Linkedlist_Movie(ptemp2);  /* call the Free_Linkedlist_Movie function defined before to free the linked list one by one */
	if ((m.remaining - n.charge) >= 0 && copies > 0){
		ret = 1;
		return ret;   /* if the customer can rent a movie, return ret = 1 */
	}
	return ret;  /* else return ret = 0 */
}

void Change_Remaining_and_Copies(char name[200], char movie[200]){  /* change the customer's remaining and the copies of the movie */
	FILE *pFile;
	int charge;
	Customer_Node *temp1, *temp2, *temp3; /* declare three strcucture variables of type of Customer_Node */
	temp1 = temp2 = temp3 = Read_File_Customer();  /* call the Read_File_Customer function defined before to read the customers' data from the file "Customer.txt" */
	Movie_Node *ptemp1, *ptemp2, *ptemp3;  /* declare three strcucture variables of type of Movie_Node */
	ptemp1 = ptemp2 = ptemp3 = Read_File_Movie();  /* call the Read_File_Movie function defined before to read the movies' data from the file "Movie.txt" */
	while (ptemp1){   /* find the corresponding linked list */
		if ((strcmp(ptemp1->movies.title, movie)) == 0){
			ptemp1->movies.copies--;
			charge = ptemp1->movies.charge;  /* find the corresponding charge of the movie */
			break;
		}
		ptemp1 = ptemp1->pNext;
	}
	if ((pFile = fopen("Movie.txt", "w")) == NULL){  /* check whether the file has been opened successfully */
		printf("\t\t\t\t\tfail to open the file\n");
		printf("\t\t\t\t\t");
		system("pause");
		exit(0);   /* if fail to open the file, quit the program automatically */
	}
	fclose(pFile);  /* empty the data in the file "Movie.txt" firstly */
	if ((pFile = fopen("Movie.txt", "a+")) == NULL){  /* check whether the file has been opened sucessfully */
		printf("\t\t\t\t\tfail to open the file\n");
		printf("\t\t\t\t\t");
		system("pause");
		exit(0);  /* if fail to open the file, quit the program automatically */
	}
	while (ptemp2){
		fprintf(pFile, "%s\t%d\t%s\t%s\t%s\t%s\t%d\n", ptemp2->movies.title, ptemp2->movies.copies, ptemp2->movies.director, ptemp2->movies.actor, ptemp2->movies.limit, ptemp2->movies.type, ptemp2->movies.charge);
		ptemp2 = ptemp2->pNext;
	}  /* write the latest data into the file "Movie.txt" */
	fclose(pFile);
	Free_Linkedlist_Movie(ptemp3);  /* call the Free_Linkedlist_Movie function defined before to free the linked list one by one */
	while (temp1){  /* find the corresponding linked list */
		if ((strcmp(temp1->customers.name, name)) == 0){
			temp1->customers.remaining -= charge;
			break;
		}
		temp1 = temp1->pNext;
	}
	Write_Into_File_Customer(temp2); /* call the Write_Into_File_Customer function defined before to save the latest data into the file "Customer.txt" */
	Free_Linkedlist_Customer(temp3);  /* call the Free_Linkedlist_Customer function defined before to free the linked list one by one */
}

void Rent_Movie(char name[200]){  /* rent a movie */
	History temp;
	if (check(name)){  /* check whether the customer has the qualification to rent a movie or not */
		char movie[200];
		printf("\t\t\t\tPlease input the movie that you want to rent(You can ONLY rent one movie a time)\n");
		printf("\n");
		printf("\t\t\t\t\t");
		scanf("%s", movie); /* input the title of the movie */
		fflush(stdin);  /* clear the error data from the input buffer */
		if (Whether_Same_Movie(movie)){  /* check whether the input movie exists or not */
			Customer_Node *temp1, *temp2, *temp3;   /* declare three structure variables of type of Customer_Node */
			temp1 = temp2 = temp3 = Read_File_Customer();  /* call the Read_File_Customer function defined before to read the customers' data from the file "Customer.txt" */
			Movie_Node *ptemp1, *ptemp2, *ptemp3;  /* declare three structure variables of type of Movie_Node */
			ptemp1 = ptemp2 = ptemp3 = Read_File_Movie();  /* call the Read_File_Movie function defined before to read the movies' data from the file "Movie.txt" */
			if (Check_Remaining_and_Copies(name, movie)){  /* check whether the copies of the input movie and the customer's remaining have a balance */
				while (temp1){
					if (strcmp(temp1->customers.name, name) == 0){   /* find the corresponding name  */
						strcpy(temp1->customers.movie, movie);
						strcpy(temp.name, name);
						strcpy(temp.title, movie);
						Write_Into_History(&temp);  /* call the Write_Into_History function defined before to save the rental history into the file "History.txt" */
						printf("\t\t\t\t\tYou have rented it successfully\n");
						printf("\t\t\t\t\t");
						system("pause");
						break;
					}
					temp1 = temp1->pNext;
				}
				Write_Into_File_Customer(temp2);  /* call the Write_Into_File_Customer function defined before to save the latest customers' data into the file "Customer.txt" */
				Change_Remaining_and_Copies(name, movie); /* call the Change_Remaining_and_Copies function */
				Free_Linkedlist_Customer(temp3);   /* call the Free_Linkedlist_Customer function defined before to free the linked list one by one */
			}
			else {
				printf("\tYou account remaining is not enough or the copies of the movies are not enough, please contact the manager\n");
				printf("\t\t\t\t\t");
				system("pause");
			}
		}
		else {
			printf("\t\t\t\t\tYou input movie does not exist\n");
			printf("\n");
			printf("\t\t\t\t\t");
			system("pause");
		}
	}
	else {
		printf("\t\t\t\t\tYou have already rented another movie, please return it first\n");
		printf("\t\t\t\t\t");
		system("pause");
	}
}

void Renew_Copies(char movie[200]){  /* renew the copies when returning the books */
	FILE *pFile;
	Movie_Node *temp1, *temp2, *temp3;  /* declare three structure variables of type of Movie_Node */
	temp1 = temp2 = temp3 = Read_File_Movie();  /* call the Read_File_Movie function defined before to read the movies' data from the file "Movie.txt" */
	while (temp1){   /* find the corresponding linked list */
		if ((strcmp(temp1->movies.title, movie)) == 0){
			temp1->movies.copies++; /* renew the copies */
			break;
		}
		temp1 = temp1->pNext;
	}
	if ((pFile = fopen("Movie.txt", "w")) == NULL){  /* check whether the file has been opened successfully */
		printf("\t\t\t\t\tfail to open the file\n");
		printf("\t\t\t\t\t");
		system("pause");
		exit(0);   /* if fail to open the file, quit the program automaticallu */
	}
	fclose(pFile);  /* empty the data in the file "Movie.txt" firstly */
	if ((pFile = fopen("Movie.txt", "a+")) == NULL){  /* check whether the file has been opened sucessfully */
		printf("\t\t\t\t\tfail to open the file\n");
		printf("\t\t\t\t\t");
		system("pause");
		exit(0);  /* if fail to open the file, quit the program automatically */
	}
	while (temp2){
		fprintf(pFile, "%s\t%d\t%s\t%s\t%s\t%s\t%d\n", temp2->movies.title, temp2->movies.copies, temp2->movies.director, temp2->movies.actor, temp2->movies.limit, temp2->movies.type, temp2->movies.charge);
		temp2 = temp2->pNext;
	}
	fclose(pFile);
	Free_Linkedlist_Movie(temp3);  /* call the Free_Linkedlist_Movie function defined before to free the linked list one by one */
}

void Retuen_Movie(char name[200]){   /* return the movie */
	char movie[200];
	if (!check(name)){  /* check whether the customer has rented a movie before */
		Customer_Node *temp1, *temp2, *temp3;  /* declare three structure variables of type of Customer_Node */
		temp1 = temp2 = temp3 = Read_File_Customer(); /* call the Read_File_Customer function defined before to read the movies' data from the file "Customer.txt" */
		while (temp1){  /* find the corresponding linked list */
			if ((strcmp(temp1->customers.name, name)) == 0){
				strcpy(movie, temp1->customers.movie);
				strcpy(temp1->customers.movie, "N");
				printf("\t\t\t\t\tYou have returned it successfully\n");
				printf("\t\t\t\t\t");
				system("pause");
				break;
			}
			temp1 = temp1->pNext;
		}
		Renew_Copies(movie);  /* call the Renew_Copies function defined before to renew the copies of the movie */
		Write_Into_File_Customer(temp2); /* call the Write_Into_File_Customer function defined before to save the latest customers' data into the file "Customer.txt" */
		Free_Linkedlist_Customer(temp3); /* call the Free_Linkedlist_Customer function defined before to free the linked list one by one */
	}
	else {
		printf("\t\t\t\t\tYou have not rented the movie before\n");
		printf("\t\t\t\t\t");
		system("pause");
	}
}

History_Node *Read_File_History(){  /* read all the rental history from the file "History.text" by linked list */
	History_Node *pNewNode = NULL;
	History_Node *head = NULL;
	History_Node *p1 = NULL; /* declare three structure varib]ables of type of History_Node */
	FILE *pFile;   /* declare a pointer variable of type of FILE */
	if ((pFile = fopen("History.txt", "a+")) == NULL){
		printf("\t\t\t\t\tfail to open the file\n");
		printf("\t\t\t\t\t");
		system("pause");
		exit(0);
	}
	pNewNode = (History_Node *)malloc(sizeof(History_Node));  /* use malloc() to creat dynamic memory for linked list */
	pNewNode->pNext = NULL;
	while ((fscanf(pFile, "%s\t%s\n", pNewNode->historys.name, pNewNode->historys.title)) != EOF){
		if (head == NULL){
			head = p1 = pNewNode;
		}
		else {
			p1->pNext = pNewNode;
			p1 = pNewNode;
		}
		pNewNode = (History_Node *)malloc(sizeof(History_Node));
		pNewNode->pNext = NULL;
	}
	free(pNewNode);
	fclose(pFile);
	return head;
}

void Free_Linkedlist_History(History_Node *p){  /* free the linked list of type of History_Node */
	History_Node *temp;
	temp = p;
	while (p){
		p = p->pNext;
		free(temp);
		temp = p;
	}
}

void View_Rental_History(char name[200]){  /* view the rental history */
	int ret = 0;
	History_Node *temp1, *temp2, *temp3;  /* declare two variables of type of History_Node */
	temp1 = temp2 = temp3 = Read_File_History(); /* call the Read_File_History function defined before to read the rental history from the file "History.txt" */
	while (temp1){
		if ((strcmp(temp1->historys.name, name)) == 0){
			ret = 1; /* if the user has rented a movie before, let ret be 1, otherwise ret = 0 */
			break;
		}
		temp1 = temp1->pNext;
	}
	if (ret){  /* if the use has rented the movie before, show the rental history  */
		printf("\t\t\t\t\tName\tRental history\n");
		while (temp2){  /* find the corresponding linked list */
			if ((strcmp(temp2->historys.name, name)) == 0){
				printf("\t\t\t\t\t%s\t¡¶%s¡·\n", temp2->historys.name, temp2->historys.title);
			}
			temp2 = temp2->pNext;
		}
		printf("\t\t\t\t\t");
		system("pause");
	}
	else {
		printf("\t\t\t\t\tYou have no rental history\n");
		printf("\t\t\t\t\t");
		system("pause");
	}
	Free_Linkedlist_History(temp3); /* call the Free_Linkedlist_History function defined before to free the linked list of type of History_Node one by one */
}

void View_Account(char name[200]){
	Customer_Node *temp1, *temp2;
	temp1 = temp2 = Read_File_Customer();
	while (temp1){
		if (strcmp(temp1->customers.name, name) == 0){
			printf("\t\t\t\tRemainings:%dyuan", temp1->customers.remaining);
			printf("\t\t\t\t\t");
			system("pause");
		}
		temp1 = temp1->pNext;
	}
	Free_Linkedlist_Customer(temp2);
}

void Customer_Interface(char name[200]){  /* provide the interface */
	system("cls");
	int ret = 0;
	while (1){
		char ch;
		Print_Customer_Interface(); /* call the Print_Customer_Interface function defined before to prinnt the interface */
		ch = getch();
		switch (ch){  /* do the switch case to provide the choices */
		case '1':
			Rent_Movie(name);  /* call the Rent_Movie function defined before to rent a movie */
			break;
		case '2':
			Retuen_Movie(name); /* call the Retuen_Movie defined before to return the movie */
			break;
		case '3':
			Search();  /* call the Search function defined before to search the movie */
			break;
		case '4':
			View_Current_Movies();  /* call the View_Current_Movies defined before to view the current movies */
			break;
		case'5':
			View_Rental_History(name); /* call the View_Rental_History defined before to view the rental history */
			break;
		case'6':
			View_Account(name);/* call the View_Account function defined before to view the account information */
			break;
		case'0':
			ret = 1;
			printf("\t\t\t\t\tGoodbye\n");
			printf("\n");
			printf("\t\t\t\t\t");
			system("pause");
			break;
		default:
			break;
		}
		if (ret){  /* if ret =1, go back to the previous interface */
			break;
		}
	}
}

void Manager_Login(){   /* provide the login interface for the manager */
	char account[200];
	char password[200];
	system("cls");
	printf("\t\t\t\t\tPlease input your manager account\n");
	printf("\n");
	printf("\t\t\t\t\t");
	scanf("%[^\n]", account); /* input the account that can contain the space */
	fflush(stdin); /* clear the error data in the input buffer */
	printf("\t\t\t\t\tPlease input your manager password\n");
	printf("\n");
	printf("\t\t\t\t\t");
	scanf("%[^\n]", password); /* input the password that can contain the space */
	fflush(stdin); /* clear the error data in the input buffer */
	if ((strcmp(account, "12345")) == 0 && (strcmp(password, "12345")) == 0){
		printf("\t\t\t\t\tYou have logged into the system successfully\n");
		printf("\t\t\t\t\t");
		system("pause");
		Manger_Interface(); /* call the Manger_Interface function defined before to go into the manager interface */
	}
	else {
		printf("\t\t\t\t\tYour account or password is wrong\n");
		printf("\t\t\t\t\t");
		system("pause");
	}
}

void Main_Interface(){  /* provide the main interface */
	char temp_name[200];
	while (1){
		Print_Main_Interface(); /* call the Print_Main_Interface function defined before to priint the interface */
		char ch;
		ch = getch();
		switch (ch){  /* do the switch case to provide the choices */
		case '1':
			Manager_Login();  /* call the Manager_Login function defined before to go into the manager interface */
			break;
		case '2':
			strcpy(temp_name, Login());  /* call the Login function defined before to log in */
			if (strcmp(temp_name, "0") == 0){ /* if not log in succcessfully, return "0" and go back to the main interface again */
				break;
			}
			else{
				printf("\t\t\t\t\tYou have logged into the system successfully\n");
				printf("\n");
				printf("\t\t\t\t\t");
				system("pause");
				Customer_Interface(temp_name); /* if log in successfullly, call the Customer_Interface function defined before to go into the customer interface */
				break;
			}
		case'0':
			printf("\t\t\t\t\tGoodbye\n");
			printf("\n");
			printf("\t\t\t\t\t");
			exit(0); /* exit the program */
		default:
			break;
		}
	}
}

void Search(){
	char ch[200];
	int ret = 1;
	Movie_Node *temp1, *temp2;  /* declare two structure variales of type of Movie_Node */
	temp1 = temp2 = Read_File_Movie();  /* call the Read_File_Movie defined before to read all of movies' data from the file "Movie.txt" */
	printf("\t\t\t\tPlease input the TITLE, or the DIRECTOR, or the ACTOR of the movie you want to search\n");
	printf("\n");
	printf("\t\t\t\t\t");
	scanf("%s", ch);
	fflush(stdin); /* clear the error data in the input buffer */
	while (temp1){  /* find the corresponding linked list */
		if ((strcmp(temp1->movies.title, ch)) == 0 || (strcmp(temp1->movies.director, ch)) == 0 || (strcmp(temp1->movies.actor, ch)) == 0){  /* print the corresponding information of the movie */
			printf("\t\t\t\t\tTitle:¡¶%s¡·\n", temp1->movies.title);
			printf("\t\t\t\t\tCopies:%d\n", temp1->movies.copies);
			printf("\t\t\t\t\tActor:%s\n", temp1->movies.actor);
			printf("\t\t\t\t\tDirector:%s\n", temp1->movies.director);
			printf("\t\t\t\t\tIs it suitable for children?: %s\n", temp1->movies.limit);
			printf("\t\t\t\t\tType:%s\n", temp1->movies.type);
			printf("\t\t\t\t\tCharge:%d\n", temp1->movies.charge);
			printf("\n");
			printf("\t\t\t\t\t");
			system("pause");
			ret = 0;
			break;
		}
		temp1 = temp1->pNext;
	}
	Free_Linkedlist_Movie(temp2);  /* call the Free_Linkedlist_Movie defined before to free the linked list of type of Movie_Node */
	if (ret){  /* check whether the movie that the customer wants to search exists or not */
		printf("\t\t\t\t\tThe movie you want to search does not exise\n");
		printf("\n");
		printf("\t\t\t\t\t");
		system("pause");
	}
}

int main(){
	Main_Interface();  /* call the Main_Interface function defined before to start the whole program */
	return 0;
}
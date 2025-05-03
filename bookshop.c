#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

typedef struct
{
    int id;
    char name[20];
    char contact[15];
} staff;

int staffCount = 0;
staff staffList[MAX];

typedef struct
{
    int id;
    char title[20];
    char author[15];
    float price;
} book;

int bookCount = 0;
book bookList[MAX];

typedef struct {
    int id;
    char bookTitle[50];
    int quantity;
    float unitPrice;
    float total;
} Sale;

Sale salesList[MAX];
int saleCount = 0;

typedef struct {
    int id;
    char bookTitle[50];
    int quantity;
    float costPrice;
    float totalCost;
} Purchase;

Purchase purchaseList[MAX];
int purchaseCount = 0;

typedef struct {
    int id;
    char name[50];
    char phone[20];
} Member;

Member memberList[MAX];
int memberCount = 0;

void password();
void heading();
void mainMenu();
void staffMenu();
void addStaff();
void viewStaff();
void bookMenu();
void addBook();
void viewBooks();
void salesMenu();
void makeSale();
void viewSale();
void purchaseMenu();
void recordPurchase();
void viewPurchases();
void membershipMenu();
void addMember();
void viewMembers();
void bookAvailabilityMenu();
void searchBookByID();
void searchBookByTitle();

int main()
{
    password();
    return 0;
}


void mainMenu()
{
    system( "cls");
    printf("\n\n\t\t ---------------------------------------------------\n");
    printf("\t\t ------------------- Main Menu ---------------------\n");
    printf("\t\t ---------------------------------------------------\n");
    printf("\n\t\t 1. Staff Management.\n");
    printf("\n\t\t 2. Book Management.\n");
    printf("\n\t\t 3. Sales & Purchase Management.\n");
    printf("\n\t\t 4. Membership Management.\n");
    printf("\n\t\t 5. Available Book Reports.\n");
    printf("\n\t\t 6. Exit.\n");
    printf("\n\t\t Please Select A Number: ");

    int n; scanf("%d", &n);
    if(n==1)
    {
        staffMenu();
    }
    else if(n==2)
    {
        bookMenu();
    }
    else if(n==3)
    {
        system("cls");
        int num;
        printf("\n\n\t\t 1. Sales Management.\n");
        printf("\n\t\t 2. Purchase Management.\n");
        printf("\n\t\t 3. Back \n\n");
        printf("\n\t\t Enter Your Choice: ");
        scanf("%d", &num);
        if(num == 1)
        {
            salesMenu();
        }
        else if(num == 2)
        {
            purchaseMenu();
        }
        else if(num == 3)
        {
            mainMenu();
        }
        else
        {
            system("cls");
            printf("\n\t\t Invalid Choice.\n");
            printf("\t\t Press any key to continue...");
            getchar();
            mainMenu();
        }
    }
    else if(n==4)
    {
        membershipMenu();
    }
    else if(n==5)
    {
        bookAvailabilityMenu();
    }
    else if(n==6)
    {
        exit(0);
    }
    else
    {
        system("cls");
        printf("\n\n\n\t\t Please Select A Correct Number.\n\n\t\t Press Any Key To Continue...");
        getchar();
        getchar();
        mainMenu();
    }
}


/*Staff Starts Here*/
void staffMenu()
{
    system("cls");
    int choice;
    while(1)
    {
         printf("\n\n\t\t 1. Add Staff\n");
         printf("\t\t 2. View Staff\n");
         printf("\t\t 3. Back\n");
         printf("\n\t\t Enter Your choice: ");
         scanf("%d", &choice);
         switch (choice) {
            case 1:
                addStaff();
                break;
            case 2:
                viewStaff();
                break;
            case 3:
                mainMenu();
            default:
                system("cls");
                printf("\n\n\t\t Invalid choice!\n");
         }
    }

}

void addStaff()
{
    system("cls");

    char id[100], name[100], contact[100];

    printf("Please enter the id number: ");
    scanf("%s", id);

    printf("Please enter staff name: ");
    scanf("%s", name);

    printf("Please enter the contact number: ");
    scanf("%s", contact);

    FILE *addstaff = fopen("staff.txt", "a");
    if (addstaff == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    fprintf(addstaff, "%s$%s$%s\n", id, name, contact);

    fclose(addstaff);
    printf("Staff info saved.\n");

}

void viewStaff() {
    system("cls");
    FILE *file = fopen("staff.txt", "r");
    if (file == NULL) {
        printf("No staff available.\n");
        return;
    }

    char line[300];
    int found = 0;

    while (fgets(line, sizeof(line), file)) {
        found = 1;
        line[strcspn(line, "\n")] = '\0';
        char *id = strtok(line, "$");
        char *name = strtok(NULL, "$");
        char *contact = strtok(NULL, "$");

        if (id && name && contact) {
            printf(" \n\n\t\t%s. %s: %s\n", id, name, contact);
        }
    }

    if (!found) {
        printf("No staff available.\n");
    }

    fclose(file);
}
/*Staff Ends Here*/


/*Book Starts Here*/
void bookMenu()
{
    system("cls");
    int choice;
    while(1)
    {
         printf("\n\n\t\t 1. Add Book\n");
         printf("\t\t 2. View Books\n");
         printf("\t\t 3. Back\n");
         printf("\n\t\t Enter Your choice: ");
         scanf("%d", &choice);
         switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                viewBooks();
                break;
            case 3:
                mainMenu();
            default:
                printf("\t\t Invalid choice!\n");
         }
    }
}

void addBook() {
    char id[100], title[100], author[100], price[100];

    printf("\n\n\t\t Enter ID : ");
    scanf("%s", id);

    printf("\t\t Enter Title : ");
    scanf("%s", title);

    printf("\t\t Enter Author Name : ");
    scanf("%s", author);

    printf("\t\t Enter Price: ");
    scanf("%s", price);

    FILE *books = fopen("book.txt", "a");
    if (books == NULL) {
        printf("Error opening book.txt!\n");
        return;
    }

    fprintf(books, "%s$%s$%s$%s\n", id, title, author, price);
    fclose(books);

    system("cls");
    printf("\n\n\t\t Book Added Successfully!\n");
}

void viewBooks() {
    system("cls");

    FILE *file = fopen("book.txt", "r");
    if (file == NULL) {
        printf("\n\n\t\tNo books available.\n");
        return;
    }

    char line[400];
    int found = 0;

    while (fgets(line, sizeof(line), file)) {
        found = 1;
        line[strcspn(line, "\n")] = '\0';

        char *id = strtok(line, "$");
        char *title = strtok(NULL, "$");
        char *author = strtok(NULL, "$");
        char *price = strtok(NULL, "$");

        if (id && title && author && price) {
            printf("\n\tID: %s\n\tTitle: %s\n\tAuthor: %s\n\tPrice: %s\n", id, title, author, price);
        }
    }

    if (!found) {
        printf("\n\n\t\tNo books available.\n");
    }

    fclose(file);
}

/*Book Ends Here*/

/*Sales starts here*/
void salesMenu()
{
    system("cls");
    int choice;
    while(1)
    {
         printf("\n\n\t\t 1. Make a Sale\n\n");
         printf("\t\t 2. View a sale\n\n");
         printf("\t\t 3. Back\n\n");
         printf("\n\t\t Enter Your choice: ");
         scanf("%d", &choice);
         switch (choice) {
            case 1:
                makeSale();
                break;
            case 2:
                viewSale();
                break;
            case 3:
                mainMenu();
            default:
                system("cls");
                printf("\n\n\t\t Invalid choice!\n");
         }
    }
}

void makeSale() {
    system("cls");

    char saleid[100], title[100], memberid[100];
    int qty;
    float unitprice;

    printf("\n\n\t\t Enter Sale ID: ");
    scanf("%s", saleid);

    printf("\t\t Enter Book Title: ");
    scanf("%s", title);

    printf("\t\t Enter Quantity: ");
    scanf("%d", &qty);

    printf("\t\t Enter Unit Price: ");
    scanf("%f", &unitprice);

    float total = qty * unitprice;

    printf("\t\t Enter Member ID (0 if not a member): ");
    scanf("%s", memberid);

    int isMember = 0;

    ///vheck for member ihd member.txt
    if (strcmp(memberid, "0") != 0) {
        FILE *memberFile = fopen("member.txt", "r");
        if (memberFile != NULL) {
            char line[200];
            while (fgets(line, sizeof(line), memberFile)) {
                if (strstr(line, memberid)) {
                    isMember = 1;
                    break;
                }
            }
            fclose(memberFile);
        }
    }

    if (isMember) {
        float discount = total * 0.10;
        total -= discount;
        printf("\n\t\t Member Discount Applied (10%%): -%.2f\n", discount);
    } else if (strcmp(memberid, "0") != 0) {
        printf("\n\t\t Member ID not found. No discount applied.\n");
    }

    system("cls");
    printf("\n\n\n\n\t\t Total Sale Amount: %.2f\n", total);
    FILE *sales = fopen("sale.txt", "a");
    if (sales != NULL) {
        fprintf(sales, "%s$%s$%d$%.2f$%s$%.2f\n", saleid, title, qty, unitprice, memberid, total);
        fclose(sales);
    } else {
        printf("\n\t\t Failed to save sale record!\n");
    }

    printf("\n\t\t Press any key to continue...\n");
    getchar(); getchar();
    system("cls");
}

void viewSale() {
    system("cls");

    FILE *file = fopen("sale.txt", "r");
    if (file == NULL) {
        printf("\n\n\t\tNo sales available.\n");
    } else {
        char line[400];
        printf("\n\n\t\t--- Sales Record ---\n");
        while (fgets(line, sizeof(line), file)) {
            line[strcspn(line, "\n")] = '\0';

            char *id = strtok(line, "$");
            char *title = strtok(NULL, "$");
            char *qty = strtok(NULL, "$");
            char *unitprice = strtok(NULL, "$");
            char *memberid = strtok(NULL, "$");
            char *total = strtok(NULL, "$");

            if (id && title && qty && unitprice && memberid && total) {
                printf("\t ID: %s, Book: %s, Qty: %s, Unit Price: %.2f, Total: %.2f\n",
                       id, title, qty, atof(unitprice), atof(total));
            }
        }
        fclose(file);
    }

    printf("\n\t Press any key to continue...\n");
    getchar(); getchar();
    system("cls");
}
/*Sales ends here*/

/*purchase starts here*/

void purchaseMenu() {
    system("cls");
    int choice;
    while (1) {
        printf("\n\n\t\t --- Purchase Management ---\n\n");
        printf("\t\t 1. Record Purchase\n\n");
        printf("\t\t 2. View Purchases\n\n");
        printf("\t\t 3. Back\n\n\n");
        printf("\t\t Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: recordPurchase(); break;
            case 2: viewPurchases(); break;
            case 3: mainMenu();
            default: system("cls"); printf("\n\n\t\t Invalid choice!\n");
        }
    }
}

#include <stdio.h>
#include <stdlib.h>

void recordPurchase() {
    system("cls");

    char purchaseID[100], title[100], qtyStr[100], costStr[100];
    int qty;
    float unitCost, totalCost;

    printf("\n\n\t\t Enter Purchase ID: ");
    scanf("%s", purchaseID);

    printf("\t\t Enter Book Title: ");
    scanf("%s", title);

    printf("\t\t Enter Quantity: ");
    scanf("%s", qtyStr);
    qty = atoi(qtyStr);

    printf("\t\t Enter Cost per Unit: ");
    scanf("%s", costStr);
    unitCost = atof(costStr);

    totalCost = qty * unitCost;

    FILE *file = fopen("purchase.txt", "a");
    if (file == NULL) {
        printf("\n\t\t Error opening purchase.txt!\n");
        return;
    }

    fprintf(file, "%s$%s$%d$%.2f$%.2f\n", purchaseID, title, qty, unitCost, totalCost);
    fclose(file);

    printf("\n\n\t Total Purchase Cost: %.2f\n", totalCost);
    printf("\n\t Purchase recorded!\n");
    printf("\n\t Press any key to continue...\n");
    getchar(); getchar();
    system("cls");
}

void viewPurchases() {
    system("cls");

    FILE *file = fopen("purchase.txt", "r");
    if (file == NULL) {
        printf("\n\n\t No purchase records available!\n");
        return;
    }

    char line[400];
    printf("\n\n\t\t--- Purchase Records ---\n");
    while (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\n")] = '\0';

        char *id = strtok(line, "$");
        char *title = strtok(NULL, "$");
        char *qty = strtok(NULL, "$");
        char *unitCost = strtok(NULL, "$");
        char *total = strtok(NULL, "$");

        if (id && title && qty && unitCost && total) {
            printf("\t\tID: %s, Book: %s, Quantity: %s, Cost: %.2f, Total: %.2f\n",
                   id, title, qty, atof(unitCost), atof(total));
        }
    }

    fclose(file);

    printf("\n\t Press any key to continue...\n");
    getchar(); getchar();
    system("cls");
}
/*Purchase ends here*/


/*Membership starts here*/
void membershipMenu() {
    system("cls");
    int choice;
    while (1) {
        printf("\n\n\t\t --- Membership Management ---\n");
        printf("\t\t 1. Add Member\n");
        printf("\t\t 2. View Members\n");
        printf("\t\t 3. Back\n");
        printf("\n\t\t Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addMember(); break;
            case 2: viewMembers(); break;
            case 3: mainMenu();
            default: system("cls"); printf("\n\n\t\t Invalid choice!\n");
        }
    }
}

void addMember() {
    ///for the sake of easy access we are string member id in 2 seperate files
    ///one only contains the id another one contains all the member details
    system("cls");

    char id[100], name[100], phone[100];

    printf("\n\n\n");
    printf("\t\t Enter Member ID: ");
    scanf("%s", id);

    printf("\t\t Enter Member Name: ");
    scanf("%s", name);

    printf("\t\t Enter Phone Number: ");
    scanf("%s", phone);

    FILE *details = fopen("memberdetails.txt", "a");
    if (details == NULL) {
        printf("\n\t\t Error opening memberdetails.txt!\n");
        return;
    }
    fprintf(details, "%s$%s$%s\n", id, name, phone);
    fclose(details);


    FILE *ids = fopen("member.txt", "a");
    if (ids == NULL) {
        printf("\n\t\t Error opening member.txt!\n");
        return;
    }
    fprintf(ids, "%s\n", id);
    fclose(ids);

    system("cls");
    printf("\n\n\t\t Member added successfully!\n");
    printf("\t\t Press any key to continue...\n");
    getchar(); getchar();
    system("cls");
}

void viewMembers() {
    system("cls");
    FILE *file = fopen("memberdetails.txt", "r");
    if (file == NULL) {
        printf("\n\n\t\t No member records available!\n");
    } else {
        printf("\n\n\t\t Member List:\n\n");
        char line[300];
        while (fgets(line, sizeof(line), file)) {
            char *id = strtok(line, "$");
            char *name = strtok(NULL, "$");
            char *phone = strtok(NULL, "$\n");
            if (id && name && phone) {
                printf("\t\t ID: %s, Name: %s, Phone: %s\n", id, name, phone);
            }
        }
        fclose(file);
    }

    printf("\n\t\t Press any key to continue...\n");
    getchar(); getchar();
    system("cls");
}
/*Membership ends here*/

/*Book availability starts here*/
void bookAvailabilityMenu() {
    system("cls");
    int choice;
    while (1) {
        printf("\n\n\t\t --- Book Availability ---\n\n");
        printf("\t\t 1. Search by Book ID\n");
        printf("\t\t 2. Search by Book Title\n");
        printf("\t\t 3. Back\n\n");
        printf("\t\t Enter choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1: searchBookByID(); break;
            case 2: searchBookByTitle(); break;
            case 3: mainMenu();
            default: system("cls"); printf("\n\n\t\t Invalid choice!\n");
        }
    }
}

void searchBookByID() {
    system("cls");

    char id[100], line[300];
    int found = 0;

    printf("\n\n\t\t Enter Book ID: ");
    scanf("%s", id);
    getchar();

    FILE *file = fopen("book.txt", "r");
    if (file == NULL) {
        printf("\n\t\t Unable to open book file!\n");
    } else {
        printf("\n\n\n");
        while (fgets(line, sizeof(line), file)) {
            char *bookID = strtok(line, "$");
            char *title = strtok(NULL, "$");
            char *author = strtok(NULL, "$");
            char *price = strtok(NULL, "$\n");

            if (bookID && strcmp(bookID, id) == 0) {
                printf("\t\t Book Found: ID: %s, Title: %s, Author: %s, Price: %s\n",
                       bookID, title, author, price);
                found = 1;
                break;
            }
        }
        fclose(file);

        if (!found) {
            printf("\t\t Book with ID %s not found.\n", id);
        }
    }

    printf("\n\t\t Press any key to continue...\n");
    getchar();
    system("cls");
}
void searchBookByTitle() {
    system("cls");

    char title[100], line[300];
    int found = 0;

    printf("\n\n\t\t Enter Book Title: ");
    fgets(title, sizeof(title), stdin);
    title[strcspn(title, "\n")] = 0;

    FILE *file = fopen("book.txt", "r");
    if (file == NULL) {
        printf("\n\t\t Unable to open book file!\n");
    } else {
        printf("\n\n\n");
        while (fgets(line, sizeof(line), file)) {
            char *bookID = strtok(line, "$");
            char *bookTitle = strtok(NULL, "$");
            char *author = strtok(NULL, "$");
            char *price = strtok(NULL, "$\n");

            if (bookTitle && strcasecmp(bookTitle, title) == 0) {
                printf("\t\t Book Found: ID: %s, Title: %s, Author: %s, Price: %s\n",
                       bookID, bookTitle, author, price);
                found = 1;
                break;
            }
        }
        fclose(file);

        if (!found) {
            printf("\t\t Book titled '%s' not found.\n", title);
        }
    }

    printf("\n\t\t Press any key to continue...\n");
    getchar();
    system("cls");
}

void heading()
{
    system( "cls");
    printf("\n\n\t\t ---------------------------------------------------\n");
    printf("\t\t ----------------Bookshop Management----------------\n");
    printf("\t\t ---------------------------------------------------\n");
}

void password()
{
    heading();

    char a[10] = "admin";
    char b[10];

    printf("\n\t\t Enter Password : ");
    scanf("%s",b);

    if(strcmp(a,b)==0)
    {
        printf("\n\n\t\t Password Matched!\n");
        printf("\t\t Press any key to continue...");

        getchar();
        getchar();

        mainMenu();
    }
    else {
        printf("\n\n\t\t Wrong Password!\n");
        printf("\n\n\t\t Try Again...");
        getchar();
        getchar();
        password();
    }
}

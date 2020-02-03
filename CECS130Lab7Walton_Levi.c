#include <stdlib.h>
#include <stdio.h>
#include <string.h>#include <time.h>

/*
Program creates a phone book that uses memory allocation
Walton Levi
Section 1
*/

typedef struct phoneBook
{
    char cFirstName[10];
    char cLastName[10];
    char cPhoneNumber[10];
} pb;

void vAddContact(pb*, int);
int iRemoveContact(pb*, int);
void vShowPhoneBook(pb*, int);void vAlphabetContact(pb*, int);void vNumberByName(pb*, int);void vRandomContact(pb*, int);void vEraseAll(pb*);

int main()
{
    pb *contact;
    int iIndex=0;
    int iSelection;
    contact = calloc(1, 5*sizeof(pb));

    while(iSelection != 8)
    {
        printf("\nPhone Book Application");
        printf("\n1) Add Contact");
        printf("\n2) Remove Contact");
        printf("\n3) Show Contacts");
        printf("\n4) Alphabetize Contacts");        printf("\n5) Number by Name");        printf("\n6) Random Contact");        printf("\n7) Erase Contacts");        printf("\n8) Exit");
        printf("\nSelection: ");
        scanf("%d", &iSelection);

        switch(iSelection)
        {
            case 1:
                contact = realloc(contact, (iIndex+1)*sizeof(pb));
                vAddContact(contact, iIndex);
                iIndex++;                system("cls");
                break;

            case 2:
                if(iRemoveContact(contact, iIndex))
                {
                    iIndex--;
                    contact = realloc(contact, (iIndex)*sizeof(pb));
                }                system("cls");
                break;

            case 3:
                vShowPhoneBook(contact, iIndex);
                break;            case 4:                vAlphabetContact(contact, iIndex);                system("cls");                break;            case 5:                vNumberByName(contact, iIndex);                system("cls");                break;            case 6:                vRandomContact(contact, iIndex);                break;            case 7:                iIndex = 0;                vEraseAll(contact);                contact = realloc(contact, (iIndex+1)*sizeof(pb));                system("cls");                break;
            case 8:
                free(contact);
                break;
        }
    }
    return 0;
}

void vAddContact(pb* contact, int c)
{
    printf("First Name: ");
    scanf("%s", &contact[c].cFirstName);
    printf("Last Name: ");
    scanf("%s", &contact[c].cLastName);
    printf("Phone Number: ");
    scanf("%s", &contact[c].cPhoneNumber);
}

int iRemoveContact(pb* contact, int c)
{
    int v = 0;
    int i=0;
    char fn[15];
    char ln[15];
    printf("First Name: ");
    scanf("%s", &fn);
    printf("Last Name: ");
    scanf("%s", &ln);

    for (i = 0; i < c; i++)
    {
        if(!strcmp(contact[i].cFirstName, fn) && !strcmp(contact[i].cLastName, ln) && v == 0)
        {
            v++;
        }
        if(v)
        {
            contact[i] = contact[i+1];
        }
    }
    printf("Record Deleted");
    return v;
}

void vShowPhoneBook(pb* contact, int c)
{
    int v=0;
    printf("Phone Book Contacts");
    for(v = 0; v < c; v++)
    {
        printf("\n%s %s %s\n", &contact[v].cFirstName, &contact[v].cLastName, &contact[v].cPhoneNumber);
    }
}
void vAlphabetContact(pb* contact, int c){    int iContSelect;    int v = 0;    int d = 0;    int b = 0;    pb book;    printf("Alphabetize by:");    printf("\n1) First Name");    printf("\n2) Last Name");    printf("\nSelection: ");    scanf("%d", &iContSelect);    switch(iContSelect)    {    case 1:        for(v = 0; v < c-1; v++)        {            for(b = v+1; b < c; b++)            {                if(strcmp(strlwr(contact[v].cFirstName), strlwr(contact[b].cFirstName))>0)                {                    book = contact[v];                    contact[v] = contact[b];                    contact[b] = book;                }            }        }        break;    case 2:        for(v = 0; v < c-1; v++)        {            for(b = v+1; b < c; b++)            {                if(strcmp(strlwr(contact[v].cLastName), strlwr(contact[b].cLastName))>0)                {                    book = contact[v];                    contact[v] = contact[b];                    contact[b] = book;                }            }        }        break;    }}void vNumberByName(pb* contact, int c){    int v = 0;
    int i=0;
    char fn[15];
    char ln[15];
    printf("First Name: ");
    scanf("%s", &fn);
    printf("Last Name: ");
    scanf("%s", &ln);

    for (i = 0; i < c; i++)
    {
        if(!strcmp(contact[i].cFirstName, fn) && !strcmp(contact[i].cLastName, ln) && v == 0)
        {
            printf("%s\n\n", contact[i].cPhoneNumber);
        }    }}void vRandomContact(pb* contact, int c){    srand(time(NULL));    int d = rand() %c;    printf("%s %s %s\n\n", &contact[d].cFirstName, &contact[d].cLastName, &contact[d].cPhoneNumber);}void vEraseAll(pb* contact){    int d = 0;    strcpy(contact[d].cFirstName, "");    strcpy(contact[d].cLastName, "");    strcpy(contact[d].cPhoneNumber, "");}
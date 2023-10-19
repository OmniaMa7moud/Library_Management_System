#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//addBook
//Borrow(num of copies--)
//PrintLibrary
//delete
//buyBook(num of copies++)
//exit


//bonus: Menu

static TotalNumOfCopies = 0;
static struct book
{
    char bookTitle[100];
    char authorName[100];
    int publicationYear;
    int numOfCopies;
    float price;
   //char status[50];
}library[100];

static int index = 0;

void addBook()
{
    char book_name[100];
    fflush(stdin);
    printf("Please enter Book Title Number %d:", index+1);
    scanf("%[^\n]s",book_name);
    fflush(stdin);

     for(int i=0; i<=index; i++)
    {

        if( !(strcmp(library[i].bookTitle, book_name )) )
        {
            printf("The Book already Exists.\n");
            library[i].numOfCopies++;
            TotalNumOfCopies++;
            checkTotalNumOfCopies();
            return;
        }


    }

     strcpy(library[index].bookTitle , book_name);

    printf("Please enter Author Name Number\ %d:", index+1);
    scanf("%[^\n]s", library[index].authorName);
    fflush(stdin);

    printf("Please enter Publication year Number\ %d:", index+1);
    scanf("%d", &library[index].publicationYear);
    fflush(stdin);

     library[index].numOfCopies = 1;
    TotalNumOfCopies ++;
    checkTotalNumOfCopies();

    printf("Please enter Price  Number %d:", index+1);
    scanf("%f", &library[index].price);
    fflush(stdin);
    /*
    printf("Please enter Status Number %d:", index+1);
    scanf("%[^\n]s", library[index].status);
    fflush(stdin);

    printf("%s", library[index].status);
    */
    printf("\n");
    index++;

}


void printLibrary()
{
    for(int i=0; i<=index; i++)
    {
         printf("The Book Title is: %s\n", library[i].bookTitle);
        printf("The authorName is: %s\n", library[i].authorName);
        printf("The publicationYear is: %d\n", library[i].publicationYear);
        printf("The numOfCopies is: %d\n", library[i].numOfCopies);
        printf("The price is: %f\n", library[i].price);
        printf("\n");
    }
}


void borrowBook()
{

    char book_name[100];
    fflush(stdin);
    printf("Please enter Book Title:  ");
    scanf("%[^\n]s",book_name);
    fflush(stdin);

     for(int i=0; i<=index; i++)
    {

        if( !(strcmp(library[i].bookTitle, book_name )) )
        {

            if(library[i].numOfCopies <= 0 )  {printf("The Book is not Available"); return;}
            else
            {
                 printf("The Book Exists.\n");
                library[i].numOfCopies--;
                TotalNumOfCopies--;
                checkTotalNumOfCopies();
                return;
            }


    }

    }
}




void deleteBook()
{

    char book_name[100];
    fflush(stdin);
    printf("Please enter Book Title:  ");
    scanf("%[^\n]s",book_name);
    fflush(stdin);

     for(int i=0; i<=index; i++)
    {

        if( !(strcmp(library[i].bookTitle, book_name )) )
        {

            if(library[i].numOfCopies <= 0 )  {printf("The Book is not Available"); return;}
            else
            {
                 printf("The Book Exists.\n");
                 TotalNumOfCopies-= library[i].numOfCopies;
                 checkTotalNumOfCopies();

                for(int j=i+1; j<=index; j++)
                {
                    strcpy(library[i].bookTitle, library[i+1].bookTitle);
                    strcpy(library[i].authorName, library[i+1].authorName);
                    library[i].numOfCopies = library[i+1].numOfCopies;
                    library[i].price = library[i+1].price;
                    library[i].publicationYear = library[i+1].publicationYear;
                    //status
                }
                index--;
                printf("The Book is deleted.\n");
                return;
            }


    }

    }

    printf("The Book is already deleted.\n");
}


void buyBook()
{

    char book_name[100];
    fflush(stdin);
    printf("Please enter Book Title Number %d:", index+1);
    scanf("%[^\n]s",book_name);
    fflush(stdin);

     for(int i=0; i<=index; i++)
    {

        if( !(strcmp(library[i].bookTitle, book_name )) )
        {
            int buyBookCopies = 0;
            printf("The Book already Exists.\n");
             printf("Enter the number of copies: \n");
            scanf("%d", &buyBookCopies);
            library[i].numOfCopies += buyBookCopies;
            TotalNumOfCopies += buyBookCopies;
            checkTotalNumOfCopies();
            return;
        }


    }

     strcpy(library[index].bookTitle , book_name);

    printf("Please enter Author Name Number\ %d:", index+1);
    scanf("%[^\n]s", library[index].authorName);
    fflush(stdin);

    printf("Please enter Publication year Number\ %d:", index+1);
    scanf("%d", &library[index].publicationYear);


    printf("Please enter Number of copies Number\ %d:", index+1);
    scanf("%d", &library[index].numOfCopies);
    TotalNumOfCopies = library[index].numOfCopies;
    checkTotalNumOfCopies();

    printf("Please enter Price  Number\ %d:", index+1);
    scanf("%f", &library[index].price);
    fflush(stdin);
    //status
    index++;

}

void checkTotalNumOfCopies()
{
    if(TotalNumOfCopies > 100 ) {printf("Max Library capacity only 100.\n"); TotalNumOfCopies -= (TotalNumOfCopies-100); }
    else if(TotalNumOfCopies < 0 ) {printf("The Library is empty Now.\n"); TotalNumOfCopies =0; }
    else {return;}
}



int main()
{
     int option;

    while(option != 6 )
    {
        printf("Add Your option:\n1: Add Book.\n2: Display Library.\n3: Borrow a Book.\n4: Delete a Book.\n5: Buy Books.\n6: Exit.\n");
        scanf("%d", &option);
        if(option == 1)       { if(TotalNumOfCopies >= 100) {printf("The library is Full.\n");continue;}addBook();}
        else if (option == 2) { if(TotalNumOfCopies <= 0) {printf("The library is Empty.\n");continue;} printLibrary(); }
        else if (option == 3) { if(TotalNumOfCopies <= 0) {printf("The library is Empty.\n");continue;} borrowBook(); }
        else if (option == 4) { if(TotalNumOfCopies <= 0) {printf("The library is Empty.\n");continue;} deleteBook(); }
        else if (option == 5) { if(TotalNumOfCopies >= 100) {printf("The library is Full.\n");continue;}  buyBook();}
        else if (option == 6) {  break; }
        else { printf("Not a correct option.\n");}


    }

    printf("index = %d\n", index);
    printf("Total Num Of Copies = %d\n", TotalNumOfCopies);

    return 0;

}


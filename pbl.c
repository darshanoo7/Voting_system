#include <stdio.h>
#include<windows.h>

void checkCandidate();
void castVote();
void textcolor();
void NameCandidate();
void votesCount();
void getLeadingCandidate();
void finalResult();



// variables for checkCandidate1
int rollno,flag[76]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

// Creating variables for candidate names.
char CANDIDATE1[100], CANDIDATE2[100], CANDIDATE3[100], CANDIDATE4[100], b1[3];

// Variables for vote count of candidates & one spoiled vote count for NOTA.
int votesCount1 = 0, votesCount2 = 0, votesCount3 = 0, votesCount4 = 0, nota = 0;

//SetConsoleTextAttribute is a function from the Windows API that allows you to modify the console output attributes, such as text color
// and background color.GetStdHandle(STD_OUTPUT_HANDLE) is a function that returns a handle to the standard output device, which is the 
//console in this case.SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_color) is the actual function call that sets the 
//text color of the console output to the specified color.
void textcolor(int color_color){

SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color_color);
}
// Function for taking input of names of candidates.
void NameCandidate() {
    printf("Enter Name of Candidate 1: ");
    textcolor(1);
    scanf(" %[^\n]", CANDIDATE1);
    textcolor(15);

    printf("\nEnter Name of Candidate 2: ");
    textcolor(1);
    scanf(" %[^\n]", CANDIDATE2);
    textcolor(15);

    printf("\nEnter Name of Candidate 3: ");
    textcolor(1);
    scanf(" %[^\n]", CANDIDATE3);
    textcolor(15);

    printf("\nEnter Name of Candidate 4: ");
    textcolor(1);
    scanf(" %[^\n]", CANDIDATE4);
    textcolor(15);
}

//This function makes sure a candidate can vote only once
void checkCandidate(){
printf("Enter your 2 digit roll number.");
textcolor(10);
scanf("%d",&rollno);
textcolor(15);

if (rollno>=1 && rollno<=76){
    if(flag[rollno-1]!=1){

        flag[rollno-1]=1;
        castVote();  

}
    else{
        textcolor(4);
        printf("You have already voted. You can't vote twice.");
    }

}
}

// Function for casting vote.
void castVote() {
    textcolor(9);
    int choice;
    printf("\n\n ### Please choose your Candidate ###\n\n");
    printf("\n 1. %s", CANDIDATE1);
    printf("\n 2. %s", CANDIDATE2);
    printf("\n 3. %s", CANDIDATE3);
    printf("\n 4. %s", CANDIDATE4);
    printf("\n 5. None of These");

    textcolor(1);
    printf("\n\n Input your choice (1 - 4): ");
    textcolor(10);
    scanf("%d", &choice);
    textcolor(15);
    switch (choice) {
        case 1:
            votesCount1++;
            break;
        case 2:
            votesCount2++;
            break;
        case 3:
            votesCount3++;
            break;
        case 4:
            votesCount4++;
            break;
        case 5:
            nota++;
            break;
        default:
            printf("\n Error: Wrong Choice! Please retry");
            
    }

    printf("\n Thanks for voting!");
}

// Function for displaying the votes given to candidates.
void votesCount() {
    textcolor(5);
    printf("\n\n ##### Voting Statistics ####");
    printf("\n %s - %d", CANDIDATE1, votesCount1);
    printf("\n %s - %d", CANDIDATE2, votesCount2);
    printf("\n %s - %d", CANDIDATE3, votesCount3);
    printf("\n %s - %d", CANDIDATE4, votesCount4);
    printf("\n %s - %d", "Spoiled Votes", nota);
}

//Creates a text file of result.
void votingresult(){
    textcolor(4);
    FILE *k;
    k= fopen("votingresult.txt","w");
    fprintf(k,"Voting statistics\n");
    fprintf(k,"Votes of %s : %d\n",CANDIDATE1, votesCount1);
    fprintf(k,"Votes of %s : %d\n",CANDIDATE2, votesCount2);
    fprintf(k,"Votes of %s : %d\n",CANDIDATE3, votesCount3);
    fprintf(k,"Votes of %s : %d\n",CANDIDATE4, votesCount4);
    fclose(k);
}
// Function to get the leading candidate.
void getLeadingCandidate() {
    textcolor(7);
    printf("\n\n  #### Leading Candidate ####\n\n");
    if (votesCount1 > votesCount2 && votesCount1 > votesCount3 && votesCount1 > votesCount4)
        printf("[%s]", CANDIDATE1);
    else if (votesCount2 > votesCount3 && votesCount2 > votesCount4 && votesCount2 > votesCount1)
        printf("[%s]", CANDIDATE2);
    else if (votesCount3 > votesCount4 && votesCount3 > votesCount2 && votesCount3 > votesCount1)
        printf("[%s]", CANDIDATE3);
    else if (votesCount4 > votesCount1 && votesCount4 > votesCount2 && votesCount4 > votesCount3)
        printf("[%s]", CANDIDATE4);
    else
        printf("----- Warning! No-win situation ----");
}

//prints result after we exit voting.
void finalResult(){
    textcolor(15);
        if (votesCount1 > votesCount2 && votesCount1 > votesCount3 && votesCount1 > votesCount4)
        printf("%s", CANDIDATE1);
    else if (votesCount2 > votesCount3 && votesCount2 > votesCount4 && votesCount2 > votesCount1)
        printf("%s", CANDIDATE2);
    else if (votesCount3 > votesCount4 && votesCount3 > votesCount2 && votesCount3 > votesCount1)
        printf("%s", CANDIDATE3);
    else if (votesCount4 > votesCount1 && votesCount4 > votesCount2 && votesCount4 > votesCount3)
        printf("%s", CANDIDATE4);
}


int main() {
    int choice;
    int a1;
    

    printf("Choose for whom do you want to take the election?\n");
    printf("1. CR\n");
    printf("2. BR\n");
    scanf("%d", &a1);
    if (a1 == 1) {
        printf("For which Division: ");
        textcolor(10);
        scanf(" %[^\n]", b1);
        textcolor(15);
    }
    if (a1 == 2) {
        printf("For which batch: ");
        textcolor(10);
        scanf(" %[^\n]", b1);
        textcolor(15);
    }

    NameCandidate();

    do {
        textcolor(14);
        printf("\n\n ###### Welcome to Election/Voting  #####");
        printf("\n\n 1. Cast the Vote");
        printf("\n 2. Find Vote Count");
        printf("\n 3. Find Leading Candidate");
        printf("\n 0. Exit");

        textcolor(1);
        printf("\n\n Please enter your choice: ");
        textcolor(10);
        scanf("%d", &choice);
        textcolor(15);

        switch (choice) {
            case 1:
                checkCandidate();
                break;
            case 2:
                votesCount();
                break;
            case 3:
                getLeadingCandidate();
                break;
            
            default:
                printf("\n Exited.\n");
                votingresult();
        }
    } while (choice != 0);

    if (choice == 0) {
        if (a1 == 1) {
            printf("The elected CR of division %s is ",b1);
            finalResult();
        } else if (a1 == 2) {
            printf("The elected BR of batch %s is ", b1);
            finalResult();
        }
    }

    return 0;
}


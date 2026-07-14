#include <stdio.h>

struct Patient
{
    int id;
    char name[50];
    int age;
    char disease[50];
};

struct Patient patients[100];
int count = 0;

void addPatient()
{
    printf("\nEnter Patient ID: ");
    scanf("%d", &patients[count].id);

    printf("Enter Patient Name: ");
    scanf(" %[^\n]", patients[count].name);

    printf("Enter Age: ");
    scanf("%d", &patients[count].age);

    printf("Enter Disease: ");
    scanf(" %[^\n]", patients[count].disease);

    count++;
    printf("\nPatient added successfully!\n");
}

void displayPatients()
{
    if(count == 0)
    {
        printf("\nNo patient records found.\n");
        return;
    }

    printf("\n----- Patient Records -----\n");

    for(int i = 0; i < count; i++)
    {
        printf("\nPatient %d\n", i + 1);
        printf("ID       : %d\n", patients[i].id);
        printf("Name     : %s\n", patients[i].name);
        printf("Age      : %d\n", patients[i].age);
        printf("Disease  : %s\n", patients[i].disease);
    }
}

void searchPatient()
{
    int id, found = 0;

    printf("\nEnter Patient ID to Search: ");
    scanf("%d", &id);

    for(int i = 0; i < count; i++)
    {
        if(patients[i].id == id)
        {
            printf("\nPatient Found\n");
            printf("ID       : %d\n", patients[i].id);
            printf("Name     : %s\n", patients[i].name);
            printf("Age      : %d\n", patients[i].age);
            printf("Disease  : %s\n", patients[i].disease);
            found = 1;
            break;
        }
    }

    if(!found)
        printf("\nPatient not found.\n");
}

void updatePatient()
{
    int id, found = 0;

    printf("\nEnter Patient ID to Update: ");
    scanf("%d", &id);

    for(int i = 0; i < count; i++)
    {
        if(patients[i].id == id)
        {
            printf("Enter New Name: ");
            scanf(" %[^\n]", patients[i].name);

            printf("Enter New Age: ");
            scanf("%d", &patients[i].age);

            printf("Enter New Disease: ");
            scanf(" %[^\n]", patients[i].disease);

            printf("\nPatient record updated successfully!\n");
            found = 1;
            break;
        }
    }

    if(!found)
        printf("\nPatient not found.\n");
}

void deletePatient()
{
    int id, found = 0;

    printf("\nEnter Patient ID to Delete: ");
    scanf("%d", &id);

    for(int i = 0; i < count; i++)
    {
        if(patients[i].id == id)
        {
            for(int j = i; j < count - 1; j++)
            {
                patients[j] = patients[j + 1];
            }

            count--;
            printf("\nPatient record deleted successfully!\n");
            found = 1;
            break;
        }
    }

    if(!found)
        printf("\nPatient not found.\n");
}

int main()
{
    int choice;

    do
    {
        printf("\n========== Hospital Management System ==========\n");
        printf("1. Add Patient\n");
        printf("2. Display Patients\n");
        printf("3. Search Patient\n");
        printf("4. Update Patient\n");
        printf("5. Delete Patient\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                addPatient();
                break;

            case 2:
                displayPatients();
                break;

            case 3:
                searchPatient();
                break;

            case 4:
                updatePatient();
                break;

            case 5:
                deletePatient();
                break;

            case 6:
                printf("\nThank you for using Hospital Management System!\n");
                break;

            default:
                printf("\nInvalid choice! Please try again.\n");
        }

    } while(choice != 6);

    return 0;
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct contact {
    long ph;
    char name[20], add[20], email[30];
} list;

FILE *fp, *ft;

int i, n, ch, l, found;

void addContact();
void listContacts();
void searchContact();
void editContact();
void deleteContact();

int main() {
    mainMenu:
    system("cls");

    printf("\n\t **** Welcome to Contact Management System ****");
    printf("\n\n\n\t\t\tMAIN MENU\n\t\t=====================\n\t\t[1] Add a new Contact\n\t\t[2] List all Contacts\n\t\t[3] Search for contact\n\t\t[4] Edit a Contact\n\t\t[5] Delete a Contact\n\t\t[0] Exit\n\t\t=================\n\t\t");
    printf("Enter the choice:");

    scanf("%d", &ch);

    switch (ch) {
        case 0:
            printf("\n\n\t\tAre you sure you want to exit?");
            break;

        case 1:
            addContact();
            break;

        case 2:
            listContacts();
            break;

        case 3:
            searchContact();
            break;

        case 4:
            editContact();
            break;

        case 5:
            deleteContact();
            break;

        default:
            printf("Invalid choice");
            break;
    }

    printf("\n\n\n..::Enter the Choice:\n\n\t[1] Main Menu\t\t[0] Exit\n");
    scanf("%d", &ch);

    switch (ch) {
        case 1:
            goto mainMenu;
            break;

        case 0:
            break;

        default:
            printf("Invalid choice");
            break;
    }

    return 0;
}

void addContact() {
    system("cls");
    fp = fopen("contact.dat", "a");

    for (;;) {
        fflush(stdin);
        printf("To exit enter blank space in the name input\nName (Use identical): ");
        scanf("%[^\n]", list.name);

        if (stricmp(list.name, "") == 0 || stricmp(list.name, " ") == 0)
            break;

        fflush(stdin);
        printf("Phone: ");
        scanf("%ld", &list.ph);

        fflush(stdin);
        printf("Address: ");
        scanf("%[^\n]", list.add);

        fflush(stdin);
        printf("Email address: ");
        gets(list.email);

        printf("\n");

        fwrite(&list, sizeof(list), 1, fp);
    }

    fclose(fp);
}

void listContacts() {
    system("cls");
    printf("\n\t\t================================\n\t\t\tLIST OF CONTACTS\n\t\t================================\n\nName\t\tPhone No\t    Address\t\tE-mail ad.\n=================================================================\n\n");

    for (i = 97; i <= 122; i = i + 1) {
        fp = fopen("contact.dat", "r");
        fflush(stdin);
        found = 0;

        while (fread(&list, sizeof(list), 1, fp) == 1) {
            if (list.name[0] == i || list.name[0] == i - 32) {
                printf("\nName\t: %s\nPhone\t: %ld\nAddress\t: %s\nEmail\t: %s\n", list.name, list.ph, list.add, list.email);
                found++;
            }
        }

        if (found != 0) {
            printf("=========================================================== [%c]-(%d)\n\n", i - 32, found);
            getch();
        }

        fclose(fp);
    }
}

void searchContact() {
    do {
        found = 0;
        printf("\n\n\t..::CONTACT SEARCH\n\t===========================\n\t..::Name of contact to search: ");
        fflush(stdin);
        scanf("%[^\n]", &query);
        l = strlen(query);
        fp = fopen("contact.dat", "r");
        system("cls");
        printf("\n\n..::Search result for '%s' \n===================================================\n", query);

        while (fread(&list, sizeof(list), 1, fp) == 1) {
            for (i = 0; i <= l; i++)
                name[i] = list.name[i];

            name[l] = '\0';

            if (stricmp(name, query) == 0) {
                printf("\n..::Name\t: %s\n..::Phone\t: %ld\n..::Address\t: %s\n..::Email\t: %s\n", list.name, list.ph, list.add, list.email);
                found++;

                if (found % 4 == 0) {
                    printf("..::Press any key to continue...");
                    getch();
                }
            }
        }

        if (found == 0)
            printf("\n..::No match found!");
        else
            printf("\n..::%d match(s) found!", found);

        fclose(fp);

        printf("\n ..::Try again?\n\n\t[1] Yes\t\t[0] No\n\t");
        scanf("%d", &ch);
    } while (ch == 1);
}

void editContact() {
    fp = fopen("contact.dat", "r");
    ft = fopen("temp.dat", "w");
    fflush(stdin);
    printf("..::Edit contact\n===============================\n\n\t..::Enter the name of contact to edit:");
    scanf("%[^\n]", name);

    while (fread(&list, sizeof(list), 1, fp) == 1) {
        if (stricmp(name, list.name) != 0)
            fwrite(&list, sizeof(list), 1, ft);
    }

    fflush(stdin);
    printf("\n\n..::Editing '%s'\n\n", name);
    printf("..::Name(Use identical):");
    scanf("%[^\n]", &list.name);

    fflush(stdin);
    printf("..::Phone:");
    scanf("%ld", &list.ph);

    fflush(stdin);
    printf("..::address:");
    scanf("%[^\n]", &list.add);

    fflush(stdin);
    printf("..::email address:");
    gets(list.email);

    printf("\n");

    fwrite(&list, sizeof(list), 1, ft);

    fclose(fp);
    fclose(ft);

    remove("contact.dat");
    rename("temp.dat", "contact.dat");
}

void deleteContact() {
    fflush(stdin);
    printf("\n\n\t..::DELETE A CONTACT\n\t==========================\n\t..::Enter the name of contact to delete:");
    scanf("%[^\n]", &name);

    fp = fopen("contact.dat", "r");
    ft = fopen("temp.dat", "w");

    while (fread(&list, sizeof(list), 1, fp) != 0)
        if (stricmp(name, list.name) != 0)
            fwrite(&list, sizeof(list), 1, ft);

    fclose(fp);
    fclose(ft);

    remove("contact.dat");
    rename("temp.dat", "contact.dat");
}

#include <stdio.h>
#include <string.h>

#define MAX 100

struct Expense {
    int id;
    char category[30];
    char description[100];
    float amount;
};

void addExpense(struct Expense *e, int *count);
void viewExpenses(struct Expense e[], int count);
void totalExpense(struct Expense e[], int count);
void searchExpense(struct Expense e[], int count);
void highestExpense(struct Expense e[], int count);
void checkBudget(struct Expense e[], int count, float budget);
void deleteExpense(struct Expense e[], int *count);
void categorySummary(struct Expense e[], int count);

int main() {

    struct Expense expenses[MAX];

    int count = 0;
    int choice;
    float budget = 0;

    do {

        printf("\n=========================================\n");
        printf("        PERSONAL EXPENSE TRACKER\n");
        printf("=========================================\n");

        printf("1. Add Expense\n");
        printf("2. View All Expenses\n");
        printf("3. Calculate Total Expense\n");
        printf("4. Search Expense by Category\n");
        printf("5. Find Highest Expense\n");
        printf("6. Set Monthly Budget\n");
        printf("7. Check Budget Status\n");
        printf("8. Delete Expense\n");
        printf("9. Category-wise Summary\n");
        printf("10. Exit\n");

        printf("=========================================\n");

        printf("\nEnter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input!\n");
            return 1;
        }

        switch (choice) {

            case 1:
                addExpense(expenses, &count);
                break;

            case 2:
                viewExpenses(expenses, count);
                break;

            case 3:
                totalExpense(expenses, count);
                break;

            case 4:
                searchExpense(expenses, count);
                break;

            case 5:
                highestExpense(expenses, count);
                break;

            case 6:
                printf("\nEnter monthly budget: Rs. ");
                scanf("%f", &budget);

                if (budget > 0) {
                    printf("Budget set successfully!\n");
                }
                else {
                    budget = 0;
                    printf("Invalid budget!\n");
                }

                break;

            case 7:
                checkBudget(expenses, count, budget);
                break;

            case 8:
                deleteExpense(expenses, &count);
                break;

            case 9:
                categorySummary(expenses, count);
                break;

            case 10:
                printf("\nThank you for using Expense Tracker!\n");
                break;

            default:
                printf("\nInvalid choice! Try again.\n");
        }

    } while (choice != 10);

    return 0;
}


void addExpense(struct Expense *e, int *count) {

    if (*count >= MAX) {
        printf("\nExpense storage is full!\n");
        return;
    }

    struct Expense *p = e + *count;

    p->id = *count + 1;

    printf("\n=========================================\n");
    printf("              ADD EXPENSE\n");
    printf("=========================================\n");


    printf("\nWHAT IS A CATEGORY?\n");
    printf("-----------------------------------------\n");

    printf("A category tells what type of expense\n");
    printf("you made. It helps you understand where\n");
    printf("your money is being spent.\n");

    printf("\nExamples of Categories:\n");
    printf("-----------------------------------------\n");

    printf("Food          - Meals, snacks and groceries\n");
    printf("Transport     - Bus, taxi, fuel and metro\n");
    printf("Shopping      - Clothes and electronics\n");
    printf("Education     - Books, stationery and fees\n");
    printf("Entertainment - Movies, games and subscriptions\n");
    printf("Bills         - Electricity, internet and recharge\n");
    printf("Health        - Medicines and doctor visits\n");
    printf("Other         - Any other type of expense\n");

    printf("\nExample:\n");
    printf("If you spent Rs. 200 on lunch,\n");
    printf("Category = Food\n");

    printf("-----------------------------------------\n");

    printf("\nEnter category: ");
    scanf(" %29[^\n]", p->category);


    printf("\nWHAT IS A DESCRIPTION?\n");
    printf("-----------------------------------------\n");

    printf("A description is a short detail explaining\n");
    printf("exactly what you spent your money on.\n");
    printf("It helps you remember the purpose of the\n");
    printf("expense later.\n");

    printf("\nExamples of Descriptions:\n");
    printf("-----------------------------------------\n");

    printf("Category: Food\n");
    printf("Description: Lunch at college\n\n");

    printf("Category: Transport\n");
    printf("Description: Auto fare from college to home\n\n");

    printf("Category: Shopping\n");
    printf("Description: Bought a new T-shirt\n\n");

    printf("Category: Education\n");
    printf("Description: Bought C programming book\n\n");

    printf("Category: Entertainment\n");
    printf("Description: Movie ticket\n\n");

    printf("Category: Bills\n");
    printf("Description: Monthly mobile recharge\n\n");

    printf("Category: Health\n");
    printf("Description: Bought medicines\n");

    printf("-----------------------------------------\n");

    printf("\nEnter description: ");
    scanf(" %99[^\n]", p->description);


    printf("\nEnter amount: Rs. ");
    scanf("%f", &p->amount);

    if (p->amount <= 0) {
        printf("\nInvalid amount!\n");
        return;
    }

    (*count)++;

    printf("\n=========================================\n");
    printf("       EXPENSE ADDED SUCCESSFULLY\n");
    printf("=========================================\n");

    printf("ID          : %d\n", p->id);
    printf("Category    : %s\n", p->category);
    printf("Description : %s\n", p->description);
    printf("Amount      : Rs. %.2f\n", p->amount);

    printf("=========================================\n");
}


void viewExpenses(struct Expense e[], int count) {

    if (count == 0) {
        printf("\nNo expenses recorded!\n");
        return;
    }

    printf("\n====================================================================\n");
    printf("                         ALL EXPENSES\n");
    printf("====================================================================\n");

    printf("%-5s %-20s %-25s %-10s\n",
           "ID", "Category", "Description", "Amount");

    printf("--------------------------------------------------------------------\n");

    for (int i = 0; i < count; i++) {

        printf("%-5d %-20s %-25s Rs. %.2f\n",
               e[i].id,
               e[i].category,
               e[i].description,
               e[i].amount);
    }

    printf("====================================================================\n");
}


void totalExpense(struct Expense e[], int count) {

    float total = 0;

    if (count == 0) {
        printf("\nNo expenses recorded!\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        total = total + e[i].amount;
    }

    printf("\n=========================================\n");
    printf("             TOTAL EXPENSE\n");
    printf("=========================================\n");

    printf("Total Expense = Rs. %.2f\n", total);

    printf("=========================================\n");
}


void searchExpense(struct Expense e[], int count) {

    char category[30];
    int found = 0;

    if (count == 0) {
        printf("\nNo expenses recorded!\n");
        return;
    }

    printf("\nEnter category to search: ");
    scanf(" %29[^\n]", category);

    printf("\n=========================================\n");
    printf("              SEARCH RESULTS\n");
    printf("=========================================\n");

    for (int i = 0; i < count; i++) {

        if (strcmp(e[i].category, category) == 0) {

            printf("ID          : %d\n", e[i].id);
            printf("Category    : %s\n", e[i].category);
            printf("Description : %s\n", e[i].description);
            printf("Amount      : Rs. %.2f\n", e[i].amount);

            printf("-----------------------------------------\n");

            found = 1;
        }
    }

    if (found == 0) {
        printf("No expenses found in this category!\n");
    }
}


void highestExpense(struct Expense e[], int count) {

    if (count == 0) {
        printf("\nNo expenses available!\n");
        return;
    }

    int maxIndex = 0;

    for (int i = 1; i < count; i++) {

        if (e[i].amount > e[maxIndex].amount) {
            maxIndex = i;
        }
    }

    printf("\n=========================================\n");
    printf("             HIGHEST EXPENSE\n");
    printf("=========================================\n");

    printf("ID          : %d\n", e[maxIndex].id);
    printf("Category    : %s\n", e[maxIndex].category);
    printf("Description : %s\n", e[maxIndex].description);
    printf("Amount      : Rs. %.2f\n", e[maxIndex].amount);

    printf("=========================================\n");
}


void checkBudget(struct Expense e[], int count, float budget) {

    float total = 0;

    if (budget <= 0) {
        printf("\nPlease set your monthly budget first!\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        total = total + e[i].amount;
    }

    printf("\n=========================================\n");
    printf("              BUDGET STATUS\n");
    printf("=========================================\n");

    printf("Monthly Budget : Rs. %.2f\n", budget);
    printf("Total Spent    : Rs. %.2f\n", total);

    if (total > budget) {

        printf("Exceeded By    : Rs. %.2f\n",
               total - budget);

        printf("\nWARNING! You have exceeded your budget!\n");
    }

    else if (total == budget) {

        printf("\nYou have used your entire monthly budget!\n");
    }

    else {

        printf("Remaining      : Rs. %.2f\n",
               budget - total);

        printf("\nYou are within your budget.\n");
    }

    printf("=========================================\n");
}


void deleteExpense(struct Expense e[], int *count) {

    int id;
    int index = -1;

    if (*count == 0) {
        printf("\nNo expenses available to delete!\n");
        return;
    }

    printf("\nEnter expense ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < *count; i++) {

        if (e[i].id == id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("\nExpense not found!\n");
        return;
    }

    for (int i = index; i < *count - 1; i++) {
        e[i] = e[i + 1];
    }

    (*count)--;

    for (int i = 0; i < *count; i++) {
        e[i].id = i + 1;
    }

    printf("\nExpense deleted successfully!\n");
}


void categorySummary(struct Expense e[], int count) {

    int visited[MAX] = {0};

    if (count == 0) {
        printf("\nNo expenses available!\n");
        return;
    }

    printf("\n=========================================\n");
    printf("         CATEGORY-WISE SUMMARY\n");
    printf("=========================================\n");

    for (int i = 0; i < count; i++) {

        if (visited[i] == 1) {
            continue;
        }

        float sum = 0;

        for (int j = i; j < count; j++) {

            if (strcmp(e[i].category,
                       e[j].category) == 0) {

                sum = sum + e[j].amount;
                visited[j] = 1;
            }
        }

        printf("%-20s : Rs. %.2f\n",
               e[i].category,
               sum);
    }

    printf("=========================================\n");
}
#include <stdio.h>
#include <string.h>

// Structure to hold bill info
struct Bill {
    char firstName[20];
    char lastName[20];
    char Address[50];
    float previousUnit;
    float presentUnit;
};

// Function to calculate bill based on units
double generateBill(struct Bill temp) {
    float diff = temp.presentUnit - temp.previousUnit;

    if (diff >= 1 && diff <= 100) {
        return diff * 13.51;
    } else if (diff <= 200) {
        return diff * 15.78;
    } else if (diff <= 300) {
        return diff * 30.00;
    } else if (diff <= 400) {
        return diff * 33.04;
    } else if (diff <= 500) {
        return diff * 35.26;
    } else if (diff <= 600) {
        return diff * 36.50;
    } else if (diff <= 700) {
        return diff * 37.90;
    } else {
        return diff * 42.95;
    }
}

int main() {
    struct Bill bill;

    printf("======== GENERATING ELECTRICITY BILL ========\n\n");

    // Input details
    printf("First Name: ");
    scanf("%19s", bill.firstName);

    printf("Last Name: ");
    scanf("%19s", bill.lastName);

    printf("Address: ");
    scanf(" %[^\n]s", bill.Address);  // To read full address including spaces

    printf("Previous Unit: ");
    scanf("%f", &bill.previousUnit);

    printf("Present Unit: ");
    scanf("%f", &bill.presentUnit);

    // Output Bill
    printf("\n\n********* ELECTRICITY BILL *********\n\n");
    printf("Name            : %s %s\n", bill.firstName, bill.lastName);
    printf("Address         : %s\n", bill.Address);
    printf("Previous Unit   : %.2f\n", bill.previousUnit);
    printf("Current Unit    : %.2f\n", bill.presentUnit);

    float total = generateBill(bill);
    printf("--------------------------------------\n");
    printf("Total Bill Cost : Rs. %.2lf\n", total);
    printf("**************************************\n");

    return 0;
}



#include <string.h>
#include <stdlib.h>
#include "employee.h"

int main(void) {
    // Defined in employeeSearchOne.c
    PtrToEmployee searchEmployeeByNumber(const Employee table[], int sizeTable, long numberToFind);
    PtrToEmployee searchEmployeeByName(const Employee table[], int sizeTable, char *nameToFind);
    PtrToEmployee searchEmployeeByPhoneNumber(const Employee table[], int sizeTable, char * phoneNumberToFind);
    PtrToEmployee searchEmployeeBySalary(const Employee table[], int sizeTable, double salaryToFind);

    // Defined in employeeTable.c
    extern Employee EmployeeTable[];
    extern const int EmployeeTableEntries;

    PtrToEmployee matchPtr; // Declaration
    matchPtr = searchEmployeeByNumber(EmployeeTable, EmployeeTableEntries, 1045);

    // Example not found
    if (matchPtr != NULL) {
        printf("Employee ID 1045 is in record %d\n", matchPtr - EmployeeTable);
    } else {
        printf("Employee ID is NOT found in the record\n");
    }

    // Example found
    matchPtr = searchEmployeeByName(EmployeeTable, EmployeeTableEntries, "Tony Bobcat");
    if (matchPtr != NULL) {
        printf("Employee Tony Bobcat is in record %d\n", matchPtr - EmployeeTable);
    } else {
        printf("Employee Tony Bobcat is NOT found in the record\n");
    }


    matchPtr = searchEmployeeByPhoneNumber(EmployeeTable, EmployeeTableEntries, "909-555-2134");
    if (matchPtr != NULL) {
        printf("Employee with phone number 909-555-2134 is in record %d\n", matchPtr - EmployeeTable);
    } else {
        printf("Employee with phone number 909-555-2134 is NOT found in the record\n");
    }

    matchPtr = searchEmployeeByPhoneNumber(EmployeeTable, EmployeeTableEntries, "714-532-4454");
    if (matchPtr != NULL) {
        printf("Employee with phone number 714-532-4454 is in record %d\n", matchPtr - EmployeeTable);
    } else {
        printf("Employee with phone number 714-532-4454 is NOT found in the record\n");
    }


    matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 4.50);
    if (matchPtr != NULL) {
        printf("Employee with salary of 4.50 is in record %d\n", matchPtr - EmployeeTable);
    } else {
        printf("Employee with salary of 4.50 is NOT found in the record\n");
    }

    matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 3.22);
    if (matchPtr != NULL) {
        printf("Employee with salary of 3.22 is in record %d\n", matchPtr - EmployeeTable);
    } else {
        printf("Employee with salary of 3.22 is NOT found in the record\n");
    }

    return EXIT_SUCCESS;
}
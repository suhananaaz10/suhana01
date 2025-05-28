#include <iostream>
using namespace std;

void displayBedOccupancy(int *patientIDs, int *bedIDs, int size)
{
    cout << "Hospital Bed Occupancy:\n";
    for (int i = 0; i < size; i++)
    {
        cout << "Bed ID:" << *(bedIDs + i) << " | Patient ID: " << *(patientIDs + i) << endl;
    }
    cout << endl;
}

int main()
{
    const int SIZE = 5;
    int bedIDs[SIZE] ={201, 202, 203, 204, 205};
    int patientIDs[SIZE] = {101, 102, 103, 105};

    int *ptrPatient = patientIDs;
    int *ptrBed = bedIDs;

    displayBedOccupancy(ptrPatient, ptrBed, SIZE);

    *(ptrPatient + 2) = 108;

    cout << "After Updating Patient in Bed 203:\n";
    displayBedOccupancy(ptrPatient, ptrBed, SIZE);

    return 0;
}
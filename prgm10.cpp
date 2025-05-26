#include <iostream>
using namespace std;
class person
{
protected:
    string name;
    int age;

public:
    void setBasicInfo(string n, int a)
    {
        name = n;
        age = a;
    }
};
class Patient : public person
{
protected:
    string disease;
    double billAmount;
    
public:
    void  setMedicalInfo(string d, double bill)
    {
        disease = d;
        billAmount = bill;
    }
    void showPatientDetails()
    {
        cout << "Patient Name:" << name << endl;
        cout << "Patient Age:" << age << endl;
        cout << "Disease:" << disease << endl;
        cout << "Bill Amount:" << billAmount << endl;
    }
    
    double getBill()
    {
        return billAmount;
    }

    string getDisease()
    {
        return disease;
    }
};

class Doctor
{
public:
    void diagnose(Patient &p)
    {
        cout << "Reviewing patient's condition:" << p.getDisease() << endl;
    }
};

int main()
{
    Patient p1;
    p1.setBasicInfo("John Doe", 45);
    p1.setMedicalInfo("Pneumonia", 3200.50);
    p1.showPatientDetails();

    Doctor doc;
    doc.diagnose(p1);

    return 0;
}
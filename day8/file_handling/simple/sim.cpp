#include <iostream>
#include <fstream>

int main()
{
    std::ofstream outFile("example.txt");
    if (outFile.is_open())
    {
        outFile << "Hello File Handling!";
        outFile.close();
        std::cout << "Data written to file succesfully.\n";
    }
    else
    {
        std::cout << "Unable to open file for writing.\n";
    }
    return 0;


}
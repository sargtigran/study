#include <iostream>
#include <fstream>
#include <string>


int main ()
{
    std::string data;

    std::ofstream outfile;

    outfile.open("ofile.dat", std::ios::out );

    std::cout << "Մուտքագրեք Ձեր անունը՝ ";
    std::cin >> data;

    outfile << data;

    outfile.close();

    std::ifstream read;

    read.open("ofile.dat");

    std::cout << "Ձեր անունը ";
    read >> data;
    std::cout << data << " է " << std::endl;

    return 0;
}

#include <iostream>
#include <fstream>
#include <string>


int main ()
{
    char data;

    std::ofstream outfile;

    outfile.open("ofile.dat", std::ios::out );

    std::cout << "Մուտքագրեք տեքստը՝ ";

    while (std::cin >> data) {
        outfile << data;
    }

    outfile.close();

    std::ifstream read;

    read.open("ofile.dat");

    std::cout << "Մուտքագրված տեքստ՝ ";
    while (! read.eof()) {
        read >> data;
        std::cout << data; 
    }

    return 0;
}

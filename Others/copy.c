#include<fstream>
int main()
{
    std::ifstream  input("input");
    std::ofstream  output("ouptut");

    output << input.rdbuf();
}

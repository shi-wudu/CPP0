#include <iostream>

int main(int ac, char **argv)
{
    if (ac > 1)
    {
        for(int i = 1; argv[i]; i++)
        {
            for(int j = 0; argv[i][j]; j++)
                std::cout << (char)std::toupper(argv[i][j]);
        }
        std::cout << "\n";
    }
    else
        std::cout << "* LOUD AND UNBERABLE FEEDBACK NOISE *" << "\n";
    return 0;
}
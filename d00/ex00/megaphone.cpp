#include  <iostream>

int main(int ac, char **av)
{
    int i;
    int j;
    char *s;

    i = 0;
    if (ac == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 0;
    }
    while(++i < ac)
    {
        s = av[i];
        j = -1;
        while (s[++j]) 
            if(s[j] >= 'a' && s[j] <= 'z')
            {
                s[j] -= 32;
            }
        std::cout << s;
    }
    std::cout << std::endl;
    return 0;   
}
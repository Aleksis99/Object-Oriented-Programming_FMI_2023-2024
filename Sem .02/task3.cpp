#include <iostream>
#include <fstream>

void replaceInFile(std::fstream& file, char toReplace, char replaceWith)
{
    char token;
    file.get(token);

    while (!file.eof())
    {
        if (token == toReplace)
        {
            file.seekp(-1, std::ios::cur);
            file.put(replaceWith);
            file.flush();
        }

        file.get(token);
    }

}

int main()
{
    std::fstream file("file.txt", std::ios::in | std::ios::out);

    if (!file.is_open())
    {
        std::cout << "Error";
        return -1;
    }

    replaceInFile(file, 'a', '1');

    file.close();
}


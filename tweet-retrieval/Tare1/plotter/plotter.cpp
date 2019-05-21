#include <iostream>
#include <fstream>
#include <vector>
#include </home/jose/DB/tweet-retrieval/parser/json.hpp>
using json = nlohmann::json;

bool checkEquals(std::string a, std::vector<std::string> vec)
{
    for (auto &i : vec)
    {
        if (i == a)
        {
            return true;
        }
    }
    return false;
}

std::pair<std::string, std::string> split(std::string line, std::string delimiter)
{
    std::string token = line.substr(0, line.find(delimiter));
    line.erase(0, line.find(delimiter) + delimiter.length());
    std::pair<std::string, std::string> sub_strings;
    sub_strings.first = token;
    sub_strings.second = line;
    return sub_strings;
}

int main()
{
    std::string id;
    std::vector<std::string> ids;
    while (std::getline(std::cin, id))
    {
        ids.push_back(id);
    }
    std::fstream arc("/home/jose/DB/tweet-retrieval/tweets-text.txt", std::ios::in);
    std::map<std::string, std::string> results;
    std::string line;
    while (std::getline(arc, line))
    {
        auto new_pair = split(line, " ");
        if (checkEquals(new_pair.first, ids))
        {
            results[new_pair.first] = new_pair.second;
        }
    }

    int cont=1;
    for (auto &i : ids)
    {
        std::cout <<"Resultado #"<<cont<<":  "<< results[i] << '\n';
        cont++;
    }

    return 0;
}
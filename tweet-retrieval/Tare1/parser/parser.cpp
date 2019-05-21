#include <iostream>
#include <fstream>
#include </home/jose/DB/tweet-retrieval/parser/json.hpp>
using json = nlohmann::json;

int main()
{

    std::vector<std::string> texts;
    std::fstream arc("tweets-text.txt",std::ios::out|std::ios::trunc);

    std::ifstream ifs("tweets_2018-09-30.json");
    json j = json::parse(ifs);
    json k;

    for (auto iter = j.begin(); iter != j.end(); ++iter)
    {
        k=*iter;
        
         std::string text = k.value("text","NONE");
         texts.push_back(text);
    }
    std::string id;
    unsigned long int cont = 0;
    while(std::getline(std::cin,id)){
        std::cout<<id<<"|"<<texts[cont]<<'\n';
        //arc<<id<<" "<<texts[cont]<<'\n';
        cont++;
    }

    return 0;
}
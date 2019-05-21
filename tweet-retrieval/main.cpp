#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <vector>
#include <math.h>

#define NUM_TWEETS 46250
#define K 10

std::pair<std::string, std::string> split(std::string line, std::string delimiter)
{
    std::string token = line.substr(0, line.find(delimiter));
    line.erase(0, line.find(delimiter) + delimiter.length());
    std::pair<std::string, std::string> sub_strings;
    sub_strings.first = token;
    sub_strings.second = line;
    return sub_strings;
}

void normalize(std::string &word)
{
    for (auto &&i : word)
    {
        if (i >= 65 && i <= 92)
        {
            i = i + 32;
        }
    }
}


std::vector<std::string> splitWord(std::string line)
{
    std::vector<std::string> words;
    auto substr = split(line, " ");
    while (substr.first != substr.second)
    {
        words.push_back(substr.first);
        substr = split(substr.second, " ");
    }
    words.push_back(substr.first);
    return words;
}

int findInVector(std::string &word, std::string *vec)
{
    for (int i = 0; i < 16; i++)
    {
        if (word.find(vec[i]) != std::string::npos)
        {
            return i;
        }
    }
    return -1;
}

void checkSpecialCharacters(std::string &word)
{
    std::string special_character[] = {"@", "/", ",", ".", "#", "\"", "_", "-", "[", "]", "{", "}", "?", "!", "¿", ":", ";"};
    while (findInVector(word, special_character) != -1)
    {

        int pos = findInVector(word, special_character);
        std::string delimiter = special_character[pos];
        std::string token = word.substr(0, word.find(delimiter));
        word.erase(0, word.find(delimiter) + delimiter.length());
        word = token + word;
    }
    //normalize(word);
}

bool checkIfStop(std::map<std::string, bool> the_map, std::string word)
{
    if (the_map.find(word) != the_map.end())
    {
        return true;
    }
    else if (the_map.find(word) == the_map.end())
    {
        return false;
    }
}

void printInvertedIndex(std::map<std::string, std::map<std::string, double>> inverted_index)
{
    for (auto iter = inverted_index.begin(); iter != inverted_index.end(); ++iter)
    {
        std::cout << iter->first << '\t';
        for (auto &i : iter->second)
        {
            std::cout << i.first << "(" << i.second << ")"
                      << "  ";
        }
        std::cout << std::endl;
    }
}


int main()
{
    std::map<std::string, bool> stop_words;

    std::fstream stopWords("stop-words.txt", std::ios::in);
    std::string stop_word;
    while (std::getline(stopWords, stop_word))
    {
        stop_words[stop_word] = true;
    }

    std::map<std::string, std::map<std::string, unsigned long int>> inverted_index;
    std::string data;
    int cont = 0;
    while (std::getline(std::cin, data))
    {
        std::pair<std::string, std::string> substr = split(data, "|");
        auto line = splitWord(substr.second);
        for (auto &word : line)
        {
            if (checkIfStop(stop_words, word) == false)
            {
                checkSpecialCharacters(word);
                normalize(word);
                inverted_index[word][substr.first] += 1;
            }
        }
    }

    std::map<std::string, double> query;
    std::string query_text;
    std::fstream queryText("query.txt", std::ios::in);
    std::getline(queryText, query_text);
    double sum_quad_query = 0;
    auto vec_query = splitWord(query_text);
    for (auto &word : vec_query)
    {
        normalize(word);
        query[word] += 1;
    }
    for (auto &i : query)
    {
        i.second = log2(1 + i.second) * log2(NUM_TWEETS / inverted_index[i.first].size() + 1);
        sum_quad_query += pow(i.second, 2);
    }
    for (auto &i : query)
    {
        i.second = i.second / sqrt(sum_quad_query);
    }

    int cont1 = 0;
    std::map<std::string, std::pair<double, std::vector<double>>> documents;
    for (auto &term : vec_query)
    {
        for (auto &id : inverted_index[term])
        {
            if (documents.find(id.first) == documents.end())
            {
                documents[id.first].second.resize(vec_query.size());
            }
            documents[id.first].first += pow(id.second, 2);
            documents[id.first].second[cont1] = (log2(1 + id.second)) * (log2(NUM_TWEETS / inverted_index[term].size() + 1));
        }
        cont1++;
    }

    for (auto &i : documents)
    {
        for (int j = 0; j < i.second.second.size(); j++)
        {
            i.second.second[j] = i.second.second[j] / sqrt(i.second.first);
        }
    }

    for (auto &i : documents)
    {
        double current_value = 0;
        for (int j = 0; j < i.second.second.size(); j++)
        {
            current_value += query[vec_query[j]] * i.second.second[j];
        }
        i.second.first = current_value;
    }

    std::vector<std::string> result(K);
    for (size_t i = 0; i < K; i++)
    {
        double big = 0;
        std::string biggest = "";
        for (auto &i : documents)
        {
            if (i.second.first > big)
            {
                if (i.first != " ")
                {
                    biggest = i.first;
                }
            }
        }
        result[i] = biggest;
        documents[biggest].first = -1;
    }

    for (auto &&i : result)
    {
        std::cout << i << std::endl;
    }

    
}
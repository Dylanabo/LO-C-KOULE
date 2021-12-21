/*
** EPITECH PROJECT, 2021
** conf
** File description:
** rtype
*/

#include "config_parser.hpp"

void Config_parser::printVectorElements(std::vector<std::pair<std::string, std::string>> &vec)
{
    for (auto i = 0; i < vec.size(); ++i) {
        std::cout << "(" << vec.at(i).first << ","
            << vec.at(i).second << ")" << "; ";
    }
    std::cout << std::endl;
}

Config_parser::Config_parser(std::string path)
{
    int i = 0;
    int x = 0;
    std::string line;
    std::size_t pos;
    std::ifstream conf(path, std::ios::in);
        if(conf)
        {
            
            while (getline(conf, line))
            {
                if (line.find(';') != std::string::npos) {
                    nbr.push_back(line);
                } else
                    component.push_back(line);
            }
            conf.close();
            std::cout << component[0] << std::endl;
        } else {
            std::cerr << "Impossible d'ouvrir le fichier !" << std::endl;
        }
        for (auto i = 0; i < component.size(); ++i) {
            res.push_back(std::make_pair(component[i].substr(0, component[i].find(':') + 1),
                                    component[i].substr(component[i].find(':') + 1)));
        }
        printVectorElements(res);
        std::cout << res.at(5).second << std::endl;
        getTextParallax("background");

}

Config_parser::~Config_parser()
{
}

std::string Config_parser::getText(std::string block)
{
    if (block == "player1" || block == "ennemy") {
        return res.at(0).second;
    }
    if (block == "player2") {
        return res.at(7).second;
    }
    if (block == "player3") {
        return res.at(14).second;
    }
    if (block == "player4") {
        return res.at(21).second;
    }
}

int Config_parser::getHealth(std::string block)
{
    if (block == "player1" || block == "ennemy") {
        return  std::stoi(res.at(1).second);
    }
    if (block == "player2") {
        return  std::stoi(res.at(8).second);
    }
    if (block == "player3") {
        return std::stoi(res.at(15).second);
    }
    if (block == "player4") {
        return std::stoi(res.at(22).second);
    }
}

std::vector<int> Config_parser::getSize(std::string block)
{
    std::vector<int> size;
    if (block == "player1" || block == "ennemy") {
        std::string x = res.at(2).second.substr(1, res.at(2).second.find(',') - 1);
        std::string y = res.at(2).second.substr(res.at(2).second.find(' '), res.at(2).first.size() - 1);
        int xi = (int) std::stoi(x);
        int yi = (int) std::stoi(y);
        return size = {xi, yi};
    }
    if (block == "player2") {
        std::string x = res.at(9).second.substr(1, res.at(9).second.find(',') - 1);
        std::string y = res.at(9).second.substr(res.at(9).second.find(' '), res.at(9).first.size() - 1);
        int xi = (int) std::stoi(x);
        int yi = (int) std::stoi(y);
        return size = {xi, yi};
    }
    if (block == "player3") {
        std::string x = res.at(16).second.substr(1, res.at(16).second.find(',') - 1);
        std::string y = res.at(16).second.substr(res.at(16).second.find(' '), res.at(16).first.size() - 1);
        int xi = (int) std::stoi(x);
        int yi = (int) std::stoi(y);
        return size = {xi, yi};
    }
    if (block == "player4") {
        std::string x = res.at(23).second.substr(1, res.at(23).second.find(',') - 1);
        std::string y = res.at(23).second.substr(res.at(23).second.find(' '), res.at(23).first.size() - 1);
        int xi = (int) std::stoi(x);
        int yi = (int) std::stoi(y);
        return size = {xi, yi};
    }
}

std::vector<int> Config_parser::getPos(std::string block)
{
    std::vector<int> size;
    if (block == "player1" || block == "ennemy") {
        std::string x = res.at(3).second.substr(1, res.at(3).second.find(',') - 1);
        std::string y = res.at(3).second.substr(res.at(3).second.find(' '), res.at(3).first.size() - 1);
        int xi = (int) std::stoi(x);
        int yi = (int) std::stoi(y);
        return size = {xi, yi};
    }
    if (block == "player2") {
        std::string x = res.at(10).second.substr(1, res.at(10).second.find(',') - 1);
        std::string y = res.at(10).second.substr(res.at(10).second.find(' '), res.at(10).first.size() - 1);
        int xi = (int) std::stoi(x);
        int yi = (int) std::stoi(y);
        return size = {xi, yi};
    }
    if (block == "player3") {
        std::string x = res.at(17).second.substr(1, res.at(17).second.find(',') - 1);
        std::string y = res.at(17).second.substr(res.at(17).second.find(' '), res.at(17).first.size());
        int xi = (int) std::stoi(x);
        int yi = (int) std::stoi(y);
        return size = {xi, yi};
    }
    if (block == "player4") {
        std::string x = res.at(24).second.substr(1, res.at(24).second.find(',') - 1);
        std::string y = res.at(24).second.substr(res.at(24).second.find(' '), res.at(24).first.size());
        int xi = (int) std::stoi(x);
        int yi = (int) std::stoi(y);
        return size = {xi, yi};
    }
}

int Config_parser::getSpeed(std::string block)
{
    if (block == "player1" || block == "ennemy") {
        return std::stoi(res.at(4).second);
    }
    if (block == "player2") {
        return  std::stoi(res.at(11).second);
    }
    if (block == "player3") {
        return std::stoi(res.at(18).second);
    }
    if (block == "player4") {
        return std::stoi(res.at(25).second);
    }
}

int Config_parser::getSpawntime(std::string block)
{
    if (block == "ennemy") {
        return std::stoi(res.at(5).second);
    }
    
}

std::vector<std::string> Config_parser::getTextParallax(std::string block)
{
    std::vector<std::string> size;
    if (block == "background") {
        std::string x = res.at(0).second.substr(1, res.at(0).second.size() - 2);
        std::string y = res.at(1).second.substr(1, res.at(1).second.size() - 2);
        std::string z = res.at(2).second.substr(1, res.at(2).second.size() - 2);
        std::cout << x << ' ' << y << ' ' << z << std::endl;
        return size = {x, y, z};
    }
}

std::vector<int> Config_parser::getParallaxSpeed(std::string block)
{
    std::vector<int> size;
    if (block == "background") {
        std::string x = res.at(3).second.substr(1, res.at(3).second.size() - 2);
        std::string y = res.at(4).second.substr(1, res.at(4).second.size() - 2);
        std::string z = res.at(5).second.substr(1, res.at(5).second.size() - 2);
        int xi = (int) std::stoi(x);
        int yi = (int) std::stoi(y);
        int zi = (int) std::stoi(z);
        return size = {xi, yi, zi};
    }
}
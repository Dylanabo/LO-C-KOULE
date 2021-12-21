/*
** EPITECH PROJECT, 2021
** conf
** File description:
** rtype
*/

#ifndef CONF_HPP_
#define CONF_HPP_

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

class Config_parser {
    public:
        Config_parser(std::string path);
        ~Config_parser();

        std::string getText(std::string);
        int getHealth(std::string);
        std::vector<int> getSize(std::string);
        std::vector<int> getPos(std::string);
        int getSpeed(std::string);

        int getSpawntime(std::string);

        std::vector<std::string> getTextParallax(std::string);
        std::vector<int> getParallaxSpeed(std::string);
        
        void printVectorElements(std::vector<std::pair<std::string, std::string>> &vec);

    protected:
    private:

    std::string config_path;
    std::vector<std::string> nbr;
    std::vector<std::string> component;
    std::vector<std::pair<std::string, std::string>> res;
};

#endif /* !CONF_HPP_ */
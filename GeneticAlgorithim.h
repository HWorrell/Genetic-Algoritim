//
// Created by cworrell on 7/21/2017.
//

#ifndef GENETICALGORITHIM_GENETICALGORITHIM_H
#define GENETICALGORITHIM_GENETICALGORITHIM_H

#include <vector>
#include <random>
#include "cmake-build-debug/DataTracker.h"

const double euler = 2.71828182845904523536028747135266249775724709369995;

class GeneticAlgorithim{
public:

    GeneticAlgorithim(std::mt19937 &engine);

    GeneticAlgorithim(std::vector<char> values);

    char generateRandSign(std::mt19937 &engine);
    char generateRandInt(std::mt19937 &engine);
    char generateRandVariable(std::mt19937 &engine);
    char generateRandOperator(std::mt19937 &engine);
    char generateRandTrig(std::mt19937 &engine);

    char getCharAt(int var){return this->contents[var];};
    double evaluate();

    double returnVariableValue(char variable) {
        if(variable == 'Z'){
            return 1.06;
        }
        if(variable == 'Y'){
            return 11.43;
        }
        if(variable == 'X'){
            return -7.62;
        }
    };

    static void sort(std::vector<GeneticAlgorithim*> &list);

    static GeneticAlgorithim* crossover(std::vector<GeneticAlgorithim*> container, std::mt19937 &engine);

    void mutate(std::mt19937 &engine);

    static void record(std::vector<GeneticAlgorithim*> &list, DataTracker &tracker);

    std::vector<char> getContents();


private:

    std::vector<char> contents;
    std::mt19937* rand;

};

#endif //GENETICALGORITHIM_GENETICALGORITHIM_H

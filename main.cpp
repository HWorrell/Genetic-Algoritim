#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include "GeneticAlgorithim.h"
#include "UnboundedNumber.h"
#include "cmake-build-debug/DataTracker.h"

const double mutateRate = .05;
const int samples = 6;

int main() {


    std::mt19937* rng = new std::mt19937(time(NULL));

    /*

    GeneticAlgorithim* test = new GeneticAlgorithim(*rng);

    GeneticAlgorithim* test2 = new GeneticAlgorithim(*rng);

    GeneticAlgorithim* test3 = new GeneticAlgorithim(*rng);

    for(int i = 0; i < 30; i++){
        std::cout << test->getCharAt(i);
    }

    std::cout << std::endl << " Value of " << test->evaluate() << std::endl;

    for(int i = 0; i < 30; i++){
        std::cout << test2->getCharAt(i);
    }

    std::cout << std::endl << " Value of " << test2->evaluate() << std::endl;

    for(int i = 0; i < 30; i++){
        std::cout << test3->getCharAt(i);
    }

    std::cout << std::endl << " Value of " << test3->evaluate() << std::endl;

*/

    //generate random set once

    std::vector<GeneticAlgorithim*>* container = new std::vector<GeneticAlgorithim*>();

    DataTracker* tracker = new DataTracker();

    GeneticAlgorithim* test;

    for(int i = 0; i < samples; i++){
        test  = new GeneticAlgorithim(*rng);
        container->push_back(test);
    }
    //std::cout << "Pre-Sort:" << std::endl;
    //for(int i = 0; i < container->size(); i++){
    //    std::cout << container->at(i)->evaluate() << std::endl;
    //}

    GeneticAlgorithim::sort(*container);
    //std::cout << "Post-Sort:" << std::endl;
    //for(int i = 0; i < container->size(); i++){
    //    std::cout << container->at(i)->evaluate() << std::endl;
    //}

    //start looping

    for(int i = 0; i < 10; i++) {

        //evaluate
        GeneticAlgorithim::sort(*container);

        GeneticAlgorithim::record(*container, *tracker);

        //select

        std::vector<GeneticAlgorithim*>* newVector = new std::vector<GeneticAlgorithim*>;
        //crossover
        for(int j = 0; j < samples; j++){
            newVector->push_back(GeneticAlgorithim::crossover(*container, *rng));
        }

        delete container;

        container = newVector;

        //mutate

        for(int j = 0; j < 6; j++){
            container->at(j)->mutate(*rng);
        }

        //std::cout << tracker->getBest() << std::endl;

        //std::vector<char> bestSeq = tracker->bestSeq();



        //for(int a = 0; a < 30; a++){
        //    std::cout << bestSeq[a];
        //}

        //std::cout << std::endl;

        //loop up
    }
    std::cout << "Averages: " << std::endl;
    tracker->printAverages();

    std::cout << "Max: " << std::endl;
    std::cout << tracker->getBest() << std::endl;
    /*
    for(int i = 0; i < 10; i++){
        std::cout << tracker->getBest() << std::endl;

        std::vector<char> bestSeq = tracker->bestSeq();

        for(int k = 0; k < 30; k++){
            std::cout << bestSeq[k];
        }
        std::cout << std::endl;

    }
*/

    delete test;
    //delete test2;
    //delete test3;

    delete container;

    return 0;


}
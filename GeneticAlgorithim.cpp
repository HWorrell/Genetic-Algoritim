//
// Created by cworrell on 7/21/2017.
//

#include <random>
#include <ctime>
#include <iostream>
#include <cfloat>
#include "GeneticAlgorithim.h"

GeneticAlgorithim::GeneticAlgorithim(std::mt19937 &rng){


    bool validNumber = false;

    while(!validNumber) {

        this->contents.clear();

        for (int i = 0; i < 30; i++) {

            if (i == 0 || i == 3 || i == 6 || i == 9 || i == 11 || i == 14 || i == 17 || i == 21 || i == 25 ||
                i == 28) {
                this->contents.push_back(GeneticAlgorithim::generateRandSign(rng));
            } else if (i == 1 || i == 4 || i == 7 || i == 10 || i == 12 || i == 15 || i == 18 || i == 22 || i == 26 ||
                       i == 29) {
                this->contents.push_back(GeneticAlgorithim::generateRandInt(rng));
            } else if (i == 2 || i == 8 || i == 16 || i == 27) {
                this->contents.push_back(GeneticAlgorithim::generateRandVariable(rng));
            } else if (i == 5 || i == 13 || i == 19 || i == 23) {
                this->contents.push_back(GeneticAlgorithim::generateRandOperator(rng));
            } else if (i == 24) {
                this->contents.push_back(GeneticAlgorithim::generateRandTrig(rng));
            } else if (i == 20) {
                this->contents.push_back('e');
            }

        }


        if(this->evaluate() != DBL_MAX && this->evaluate() != DBL_MIN && this->evaluate() != 1.762575757){
            validNumber = true;
        }

    }

};

GeneticAlgorithim::GeneticAlgorithim(std::vector<char> values) {

    for(int i = 0; i < 30; i++){
        this->contents.push_back(values[i]);
    }

}

char GeneticAlgorithim::generateRandSign(std::mt19937 &engine) {

    std::uniform_int_distribution<int> gen(0, 1);

    switch (gen(engine)){
        case 0: return 'p';
            break;
        case 1: return 'n';
            break;
    }

}

char GeneticAlgorithim::generateRandTrig(std::mt19937 &engine) {

    std::uniform_int_distribution<int> gen(0, 2);

    switch (gen(engine)){
        case 0: return 'S';
            break;
        case 1: return 'C';
            break;
        case 2: return 'T';
            break;
    }

}

char GeneticAlgorithim::generateRandVariable(std::mt19937 &engine) {

    std::uniform_int_distribution<int> gen(0, 2);

    switch (gen(engine)){
        case 0: return 'X';
            break;
        case 1: return 'Y';
            break;
        case 2: return 'Z';
            break;
    }

}

char GeneticAlgorithim::generateRandInt(std::mt19937 &engine) {

    std::uniform_int_distribution<int> gen(0, 9);

    switch (gen(engine)){
        case 0: return '0';
            break;
        case 1: return '1';
            break;
        case 2: return '2';
            break;
        case 3: return '3';
            break;
        case 4: return '4';
            break;
        case 5: return '5';
            break;
        case 6: return '6';
            break;
        case 7: return '7';
            break;
        case 8: return '8';
            break;
        case 9: return '9';
            break;
    }

}

char GeneticAlgorithim::generateRandOperator(std::mt19937 &engine) {

    std::uniform_int_distribution<int> gen(0, 3);

    switch (gen(engine)) {
        case 0:
            return '+';
            break;
        case 1:
            return '-';
            break;
        case 2:
            return '*';
            break;
        case 3:
            return '/';
            break;
    }

}

double GeneticAlgorithim::evaluate() {

    double var1, var2, var3, var4, var5;

    double exp1, exp2, exp3, exp4, exp5, expParen;

    bool nan = false;

    //set var 1 (0-4)
    var1 = this->contents.at(1) - '0';

    var1 *= this->returnVariableValue(this->contents.at(2));

    if (this->contents.at(0) == 'n') {
        var1 *= -1;
    }

    exp1 = this->contents.at(4) - '0';

    if (this->contents.at(3) == 'n') {
        exp1 *= -1;
    }

    if (var1 != 0) {
        var1 = pow(var1, exp1);
    }

    //set var 2 (6-10)

    var2 = this->contents.at(7) - '0';

    var2 *= this->returnVariableValue(this->contents.at(8));

    if (this->contents.at(6) == 'n') {
        var2 *= -1;
    }

    exp2 = this->contents.at(10) - '0';

    if (this->contents.at(9) == 'n') {
        exp2 *= -1;
    }

    if (var2 != 0) {
        var2 = pow(var2, exp2);
    }

    //set var 3 (14-18)

    var3 = this->contents.at(15) - '0';

    var3 *= this->returnVariableValue(this->contents.at(16));

    if (this->contents.at(14) == 'n') {
        var3 *= -1;
    }

    exp3 = this->contents.at(18) - '0';

    if (this->contents.at(17) == 'n') {
        exp3 *= -1;
    }

    if (var3 != 0) {
        var3 = pow(var3, exp3);
    }

    //set var 4 (20-22)

    exp4 = this->contents.at(22);

    if(this->contents.at(21) == 'n'){
        exp4 *= -1;
    }

    var4 = pow(euler, exp3);

    var5 = this->contents.at(26) - '0';

    if(this->contents.at(25) == 'n'){
        var5 *= -1;
    }

    exp5 = this->contents.at(29) - '0';

    if(this->contents.at(28) == 'n'){
        exp5 *= -1;
    }

    if(var5 != 0) {
        var5 = pow(var5, exp5);
    }

    if(this->contents.at(24) == 'S'){
        var5 = sin(var5);
    }
    else if(this->contents.at(24) == 'C'){
        var5 = cos(var5);
    }
    else if(this->contents.at(24) == 'T'){
        var5 = tan(var5);
    }

    //std::cout << " Var 1 = " << var1 << " Var 2 = " << var2 << " Var 3 = " << var3 << " Var 4 = " << var4 << " Var 5 = " << var5 << " " << std::endl;

    double var1and2;

    if(this->contents.at(5) == '*'){
        var1and2 = var1 * var2;
    }
    else if(this->contents.at(5) == '/'){
        if(var2 == 0){
            nan = true;
        }
        else {
            var1and2 = var1 / var2;
        }
    }
    else if(this->contents.at(5) == '+'){
        var1and2 = var1 + var2;
    }
    else if(this->contents.at(5) == '-'){
        var1and2 = var1 - var2;
    }

    expParen = this->contents.at(12);
    if(this->contents.at(11) == 'n'){
        expParen *= -1;
    }

    var1and2 = pow(var1and2, expParen);

    // + + +

    double result = 0;
    double resultaux = 0;

    if(!nan) {

        if (((contents.at(13) == '+') || (contents.at(13) == '-')) &&
            ((contents.at(19) == '+') || (contents.at(19) == '-')) &&
            ((contents.at(23) == '+') || (contents.at(23) == '-'))) {

            if(contents.at(13) == '+'){
                result = var1and2 + var3;
            }
            else if(contents.at(13) == '-'){
                result = var1and2 - var3;
            }

            if(contents.at(19) == '+'){
                result += var4;
            }
            else if(contents.at(19) == '-'){
                result -= var4;
            }

            if(contents.at(23) == '+'){
                result += var5;
            }
            else if(contents.at(23) == '-'){
                result -= var5;
            }

        }

        // * + +

        if (((contents.at(13) == '*') || (contents.at(13) == '/')) &&
            ((contents.at(19) == '+') || (contents.at(19) == '-')) &&
            ((contents.at(23) == '+') || (contents.at(23) == '-'))) {

            if(contents.at(13) == '*'){
                result = var1and2 * var3;
            }
            else if(contents.at(13) == '/'){
                if(var3 == 0){
                    nan = true;
                }
                else {
                    result = var1and2 / var3;
                }
            }

            if(contents.at(19) == '+'){
                result += var4;
            }
            else if(contents.at(19) == '-'){
                result -= var4;
            }

            if(contents.at(23) == '+'){
                result += var5;
            }
            else if(contents.at(23) == '-'){
                result -= var5;
            }

        }

        // + * +

        if (((contents.at(13) == '+') || (contents.at(13) == '-')) &&
            ((contents.at(19) == '*') || (contents.at(19) == '/')) &&
            ((contents.at(23) == '+') || (contents.at(23) == '-'))) {


            if(contents.at(19) == '*'){
                result = var3 * var4;
            }
            else if(contents.at(19) == '/'){
                if(var4 == 0){
                    nan = true;
                }
                else{
                    result = var3 / var4;
                }
            }

            if(contents.at(13) == '+'){
                result += var1and2;
            }
            else if(contents.at(13) == '-'){
                result = var1and2 - result;
            }

            if(contents.at(23) == '+'){
                result += var5;
            }
            else if(contents.at(23) == '-'){
                result -= var5;
            }


        }

        // + + *

        if (((contents.at(13) == '+') || (contents.at(13) == '-')) &&
            ((contents.at(19) == '+') || (contents.at(19) == '-')) &&
            ((contents.at(23) == '*') || (contents.at(23) == '/'))) {


            if(contents.at(23) == '*'){
                result = var4 * var5;
            }
            else if(contents.at(23) == '/'){
                if(var5 == 0){
                    nan = true;
                }
                else{
                    result = var4 / var5;
                }
            }

            if(contents.at(13) == '+'){
                resultaux = var1and2 + var3;
            }
            else if(contents.at(13) == '-'){
                resultaux = var1and2 - var3;
            }

            if(contents.at(13) == '+'){
                result = resultaux + result;
            }
            if(contents.at(13) == '-'){
                result = resultaux - result;
            }

        }

        // * * +

        if (((contents.at(13) == '*') || (contents.at(13) == '/')) &&
            ((contents.at(19) == '*') || (contents.at(19) == '/')) &&
            ((contents.at(23) == '+') || (contents.at(23) == '-'))) {

            if(contents.at(13) == '*'){
                result = var1and2 * var3;
            }
            else if(contents.at(13) == '/'){
                if(var3 == 0){
                    nan = true;
                }
                else{
                    result = var1and2 / var3;
                }
            }

            if(contents.at(19) == '*'){
                result *= var4;
            }
            else if(contents.at(19) == '/'){
                if(var4 == 0){
                    nan = true;
                }
                else{
                    result /= var4;
                }

            }

            if(contents.at(23) == '+'){
                result += var5;
            }
            else if(contents.at(23) == '-'){
                result -= var5;
            }

        }

        // * + *

        if (((contents.at(13) == '*') || (contents.at(13) == '/')) &&
            ((contents.at(19) == '+') || (contents.at(19) == '-')) &&
            ((contents.at(23) == '*') || (contents.at(23) == '/'))) {

            if(contents.at(13) == '*'){
                result = var1and2 * var3;
            }
            else if(contents.at(13) == '/'){
                if(var3 == 0){
                    nan = true;
                }
                else{
                    result = var1and2 / var3;
                }
            }

            if(contents.at(23) == '*'){
                resultaux = var4 * var5;
            }
            else if(contents.at(23) == '/'){
                if(var5 == 0){
                    nan = true;
                }
                else{
                    resultaux = var4 / var5;
                }
            }

            if(contents.at(19) == '+'){
                result += resultaux;
            }
            else if(contents.at(19) == '-'){
                result -= resultaux;
            }

        }

        // + * *

        if (((contents.at(13) == '+') || (contents.at(13) == '-')) &&
            ((contents.at(19) == '*') || (contents.at(19) == '/')) &&
            ((contents.at(23) == '*') || (contents.at(23) == '/'))) {

            if(contents.at(19) == '*'){
                result = var3 * var4;
            }
            else if(contents.at(19) == '/'){
                if(var4 == 0){
                    nan = true;
                }
                else{
                    result = var3 / var4;
                }
            }

            if(contents.at(23) == '*'){
                result *= var5;
            }
            else if(contents.at(23) == '/'){
                if(var5 == 0){
                    nan = true;
                }
                else{
                    result /= var5;
                }
            }

            if(contents.at(13) == '+'){
                result += var1and2;
            }
            else if(contents.at(13) == '-'){
                result = var1and2 - result;
            }

        }

        // * * *

        if (((contents.at(13) == '*') || (contents.at(13) == '/')) &&
            ((contents.at(19) == '*') || (contents.at(19) == '/')) &&
            ((contents.at(23) == '*') || (contents.at(23) == '/'))) {

            if(contents.at(13) == '*'){
                result = var1and2 * var3;
            }
            else if(contents.at(13) == '/'){
                if(var3 == 0){
                    nan = true;
                }
                else{
                    result = var1and2 / var3;
                }
            }

            if(contents.at(19) == '*'){
                result *= var4;
            }
            else if(contents.at(19) == '/'){
                if(var4 == 0){
                    nan = true;
                }
                else{
                    result /= var4;
                }
            }

            if(contents.at(23) == '*'){
                result *= var5;
            }
            else if(contents.at(23) == '/'){
                if(var5 == 0){
                    nan = true;
                }
                else{
                    result /= var5;
                }
            }

        }

    }

    if(nan){
        return 1.762575757;
    }
    else if(std::isinf(result)){
        //std::cout << " Max " << std::endl;
        return DBL_MAX;
    }
    else{
        return result;
    }


}

void GeneticAlgorithim::sort(std::vector<GeneticAlgorithim *> &list) {

    std::vector<double> values;

    for(int i = 0; i < list.size(); i++){
        values.push_back(list[i]->evaluate());
    }

    double swap;
    GeneticAlgorithim* swapPnt;
    for(int i = 0; i < values.size(); i++){
        for(int j = 0; j < values.size() - 1; j++){
            if(values[j] > values[j + 1]){
                swap = values[j];
                swapPnt = list[j];

                values[j] = values[j + 1];
                list[j] = list[j + 1];

                values[j + 1] = swap;
                list[j + 1] = swapPnt;
            }
        }
    }

    std::cout << "List 5: " << list[5]->evaluate() << std::endl;

}

void GeneticAlgorithim::record(std::vector<GeneticAlgorithim *> &list, DataTracker &tracker) {

    double average = 0;

    for(int i = 0; i < list.size(); i++){
        average += list[i]->evaluate();
    }

    average /= list.size();

    tracker.addAverage(average);
    //std::cout<< list[5]->evaluate() <<std::endl;
    if(list[5]->evaluate() > tracker.getBest()){
        tracker.setBest(list[5]->getContents(), list[5]->evaluate());
    }

}

std::vector<char> GeneticAlgorithim::getContents() {

    return this->contents;

}

GeneticAlgorithim* GeneticAlgorithim::crossover(std::vector<GeneticAlgorithim*> container, std::mt19937 &rnd) {

    std::uniform_int_distribution<int> gen(3, 5);

    std::uniform_int_distribution<int> dist(1, 29);

    std::vector<char> sequence;

    int rand1, rand2;

    rand1 = gen(rnd);

    rand2 = gen(rnd);

    int splitPoint;

    splitPoint = dist(rnd);

    for(int i = 0; i < splitPoint; i++){
        sequence.push_back(container[rand1]->getCharAt(i));
    }

    for(int i = splitPoint; i < 30; i++){
        sequence.push_back(container[rand2]->getCharAt(i));
    }

    GeneticAlgorithim* newString = new GeneticAlgorithim(sequence);

    return newString;

}

void GeneticAlgorithim::mutate(std::mt19937 &rnd) {

    std::uniform_int_distribution<int> dice(1, 20);

    for(int i = 0; i < 30; i++){
        if(dice(rnd) == 1){
            if (i == 0 || i == 3 || i == 6 || i == 9 || i == 11 || i == 14 || i == 17 || i == 21 || i == 25 ||
                i == 28) {
                this->contents[i] = GeneticAlgorithim::generateRandSign(rnd);
            } else if (i == 1 || i == 4 || i == 7 || i == 10 || i == 12 || i == 15 || i == 18 || i == 22 || i == 26 ||
                       i == 29) {
                this->contents[i] = GeneticAlgorithim::generateRandInt(rnd);
            } else if (i == 2 || i == 8 || i == 16 || i == 27) {
                this->contents[i] = GeneticAlgorithim::generateRandVariable(rnd);
            } else if (i == 5 || i == 13 || i == 19 || i == 23) {
                this->contents[i] = GeneticAlgorithim::generateRandOperator(rnd);
            } else if (i == 24) {
                this->contents[i] = GeneticAlgorithim::generateRandTrig(rnd);
            } else if (i == 20) {
                this->contents[i] = 'e';
            }
        }
    }

}
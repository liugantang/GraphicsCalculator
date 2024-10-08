//
// Created by liugantang on 24-8-23.
//

#ifndef GRAPHICCALCULATOR_LINERARGUMENTSGENERATOR_H
#define GRAPHICCALCULATOR_LINERARGUMENTSGENERATOR_H

#include <QString>
#include "FunctionDefinitions.h"

struct LinerArgumentsGeneratorPrivate;

#include <QList>

struct LinerArguments{
    QList<std::array<double, 2>>  points;
    double xMin = 0, xMax = 0;
    double yMin = 0, yMax = 0;
};

class LinerArgumentsGenerator {
public:
    LinerArgumentsGenerator(QString expression, FunctionDefinitions defs);
    ~LinerArgumentsGenerator();
    LinerArguments generate();
private:
    std::unique_ptr<LinerArgumentsGeneratorPrivate> d;
};


#endif //GRAPHICCALCULATOR_LINERARGUMENTSGENERATOR_H

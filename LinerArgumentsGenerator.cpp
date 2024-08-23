//
// Created by liugantang on 24-8-23.
//

#include "LinerArgumentsGenerator.h"
#include "LinerArgumentsGeneratorPrivate.h"
#include <limits>

LinerArgumentsGenerator::LinerArgumentsGenerator(QString expression, FunctionDefinitions defs):
d(new LinerArgumentsGeneratorPrivate){
    d->expression = std::move(expression);
    d->definitions = defs;

}

LinerArgumentsGenerator::~LinerArgumentsGenerator() {

}

LinerArguments LinerArgumentsGenerator::generate() {
    double yMin = std::numeric_limits<double>::max();
    double yMax = std::numeric_limits<double>::min();

    LinerArguments args;
    args.xMin = d->definitions.range.first;
    args.xMax = d->definitions.range.second;
    for (double val = d->definitions.range.first;
    val < d->definitions.range.second;
    val+= d->definitions.step
    )
    {
        std::array<double, 2> point{0,0};
        point[0] = val;

        QString expressIns = d->expression;
        expressIns.replace("x", QString::number(val));
        auto exList = expressIns.split(" ");
        std::vector<QString> operators;
        std::vector<double> numbers;

        for (auto & elem : exList)
        {
           if (elem == "*" || elem == "*" || elem == "+" || elem == "-")
           {
               operators.push_back(elem);
           }
           else {
               numbers.push_back(elem.toDouble());
           }
        }

        for (auto i = 0; i < operators.size(); i++)
        {
            if (operators[i] == "*" || operators[i] == "/")
            {
                double res = operators[i] == "*"
                        ? numbers[i]*numbers[i+1] : numbers[i]/numbers[i+1];
                numbers[i+1] = res;
                numbers.erase(numbers.begin()+i);
                operators.erase(operators.begin()+i);
                --i;
            }
        }

        double result = numbers[0];
        for (auto i = 1; i < numbers.size(); i++)
        {
            result = operators[i - 1] == "+" ? result+numbers[i] : result-numbers[i];
        }
        point[1] = result;
        if (result > yMax)
        {
            yMax = result;
        }
        if (result < yMin)
        {
            yMin = result;
        }

        args.points.append(point);
    }
    args.yMin = yMin;
    args.yMax = yMax;

    return args;
}

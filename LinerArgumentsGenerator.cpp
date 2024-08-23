//
// Created by liugantang on 24-8-23.
//

#include "LinerArgumentsGenerator.h"
#include "LinerArgumentsGeneratorPrivate.h"

LinerArgumentsGenerator::LinerArgumentsGenerator(QString expression, FunctionDefinitions defs):
d(new LinerArgumentsGeneratorPrivate){
    d->expression = std::move(expression);
    d->definitions = defs;
}

LinerArgumentsGenerator::~LinerArgumentsGenerator() {

}

LinerArguments LinerArgumentsGenerator::generate() {

    return {};
}

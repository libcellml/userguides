/* The content of this file was generated using the C profile of libCellML 0.3.104. */

#include "PredatorPrey.h"

#include <math.h>
#include <stdlib.h>

const char VERSION[] = "0.3.0";
const char LIBCELLML_VERSION[] = "0.3.104";

const size_t STATE_COUNT = 2;
const size_t VARIABLE_COUNT = 4;

const VariableInfo VOI_INFO = {"time", "month", "predator_prey_component", VARIABLE_OF_INTEGRATION};

const VariableInfo STATE_INFO[] = {
    {"y_s", "number_of_sharks", "predator_prey_component", STATE},
    {"y_f", "thousands_of_fish", "predator_prey_component", STATE}
};

const VariableInfo VARIABLE_INFO[] = {
    {"a", "per_month", "predator_prey_component", CONSTANT},
    {"b", "per_shark_month", "predator_prey_component", CONSTANT},
    {"d", "per_1000fish_month", "predator_prey_component", CONSTANT},
    {"c", "per_month", "predator_prey_component", COMPUTED_CONSTANT}
};

double * createStatesArray()
{
    return malloc(STATE_COUNT*sizeof(double));
}

double * createVariablesArray()
{
    return malloc(VARIABLE_COUNT*sizeof(double));
}

void deleteArray(double *array)
{
    free(array);
}

void initialiseVariables(double *states, double *variables)
{
    variables[0] = -0.8;
    variables[1] = 0.3;
    variables[2] = -0.6;
    states[0] = 1.0;
    states[1] = 2.0;
}

void computeComputedConstants(double *variables)
{
    variables[3] = variables[0]+2.0;
}

void computeRates(double voi, double *states, double *rates, double *variables)
{
    rates[0] = variables[0]*states[0]+variables[1]*states[0]*states[1];
    rates[1] = variables[3]*states[1]+variables[2]*states[0]*states[1];
}

void computeVariables(double voi, double *states, double *rates, double *variables)
{
}

#include "fuel.h"

float computeEnrichment(float ethanol) {
    float afr_query = afr_ethanol*ethanol + (1-ethanol)*afr_gasoline; // 14.7 is the stoichiometric ratio for gasoline
    return afr_gasoline/afr_query;
}

float flashpoint(float ethanol) {
    return flashpoint_ethanol*ethanol + (1-ethanol)*flashpoint_gasoline;
}


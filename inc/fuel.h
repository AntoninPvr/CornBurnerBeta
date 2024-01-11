#ifndef FUEL_H
#define FUEL_H

const float afr_ethanol = 9.0f;
const float afr_gasoline = 14.7f;
const float flashpoint_ethanol = 13.0f;
const float flashpoint_gasoline = -43.0f;

float computeEnrichment(float ethanol);
float flashpoint(float ethanol);


#endif // FUEL_H
///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab12a_fatCat - EE 205 - Spr 2022
///
/// @file Weight.cpp
/// @version 1.0
///
/// @author Lyon Singleton <lyonws@hawaii.edu>
/// @date   15_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#include <cassert>
#include <iostream>
#include <stdexcept>
#include <iomanip>
#include "Weight.h"
using namespace std ;
const float Weight::KILOS_IN_A_POUND = 0.453592 ;
const float Weight::SLUGS_IN_A_POUND = 0.031081 ;
const float Weight::UNKNOWN_WEIGHT = -1 ;
const string Weight::POUND_LABEL = "Pound" ;
const string Weight::KILO_LABEL = "Kilo" ;
const string Weight::SLUG_LABEL = "Slug" ;





float Weight::fromKilogramToPound(const float kilogram) noexcept {
    return kilogram / KILOS_IN_A_POUND;
}

float Weight::covertWeight(float fromWeight, Weight::UnitOfWeight fromUnit, Weight::UnitOfWeight toUnit) noexcept {
    return 0;
}

Weight::Weight() noexcept {

}

Weight::Weight(float newWeight) {

}

Weight::Weight(Weight::UnitOfWeight newUnitOfWeight) noexcept {

}

Weight::Weight(float newWeight, Weight::UnitOfWeight newUnitOfWeight) {

}

Weight::Weight(float newWeight, float newMaxWeight) {

}

Weight::Weight(Weight::UnitOfWeight newUnitOfWeight, float newMaxWeight) {

}

Weight::Weight(float newWeight, Weight::UnitOfWeight newUnitOfWeight, float newMaxWeight) {

}

bool Weight::isWeightKnown() const noexcept {
    return false;
}

bool Weight::hasMaxWeight() const noexcept {
    return false;
}

float Weight::getWeight() const noexcept {
    return 0;
}

float Weight::getWeight(Weight::UnitOfWeight weightUnits) const noexcept {
    return 0;
}

float Weight::getMaxWeight() const noexcept {
    return 0;
}

Weight::UnitOfWeight Weight::getWeightUnit() const noexcept {
    return Weight::Pound;
}

void Weight::setWeight(float newWeight) {

}

void Weight::setWeight(float newWeight, Weight::UnitOfWeight weightUnits) {

}

bool Weight::isWeightValid(float checkWeight) const noexcept {
    return false;
}

bool Weight::validate() const noexcept {
    return false;
}

void Weight::dump() const noexcept {

}

bool Weight::operator==(const Weight &rhs_Weight) const {
    return false;
}

bool Weight::operator<(const Weight &rhs_Weight) const {
    return false;
}

Weight Weight::operator+=(float rhs_addToWeight) {
    return 0;
}

float Weight::fromPoundToKilogram(float pound) noexcept {
    return 0;
}

float Weight::fromSlugToPound(float slug) noexcept {
    return 0;
}

float Weight::fromPoundToSlug(float pound) noexcept {
    return 0;
}

void Weight::setMaxWeight(float newMaxWeight) {

}

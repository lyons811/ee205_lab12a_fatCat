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

int main () {
    cout << "hello" << endl ;
    return 0 ;
}



float Weight::fromKilogramToPound(const float kilogram) noexcept {
    return kilogram / KILOS_IN_A_POUND;
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

float Weight::covertWeight(float fromWeight, Weight::UnitOfWeight fromUnit, Weight::UnitOfWeight toUnit) noexcept {
    if(fromUnit == KILO and toUnit == Pound) {
        return fromKilogramToPound(fromWeight) ;
    }
    if(fromUnit == Pound and toUnit == KILO) {
        return fromPoundToKilogram(fromWeight) ;

    }

    if(fromUnit == SLUG and toUnit == Pound) {
        return fromSlugToPound(fromWeight) ;
    }
    if(fromUnit == Pound and toUnit == SLUG) {
        return fromPoundToSlug(fromWeight) ;
    }

    return 0 ;
}


Weight::Weight() noexcept {
    weight = weight ;
}

Weight::Weight(float newWeight) {
 Weight::setWeight(newWeight) ;
}

void Weight::setUnitOfWeight(Weight::UnitOfWeight unitOfWeight) {
    unitOfWeight = unitOfWeight;
    }

Weight::Weight(Weight::UnitOfWeight newUnitOfWeight) noexcept {
    Weight::setUnitOfWeight(newUnitOfWeight) ;
}

Weight::Weight(float newWeight, Weight::UnitOfWeight newUnitOfWeight) {
    Weight::setWeight(newWeight, newUnitOfWeight) ;
}

Weight::Weight(float newWeight, float newMaxWeight) {
    Weight::setWeight(newWeight) ;
    Weight::setMaxWeight(newMaxWeight) ;
}

Weight::Weight(Weight::UnitOfWeight newUnitOfWeight, float newMaxWeight) {
    Weight::setUnitOfWeight(newUnitOfWeight) ;
    Weight::setMaxWeight(newMaxWeight) ;
}

Weight::Weight(float newWeight, Weight::UnitOfWeight newUnitOfWeight, float newMaxWeight) {
    Weight::setWeight(newWeight) ;
    Weight::setUnitOfWeight(newUnitOfWeight) ;
    Weight::setMaxWeight(newMaxWeight) ;
}

bool Weight::isWeightKnown() const noexcept {
    if( weight == -1){
        return false;
    }
    return true;
}

bool Weight::hasMaxWeight() const noexcept {
    if(maxWeight > 0) {
        return true ;
    }

    return false;
}

float Weight::getWeight() const noexcept {
    if(weight == 0.0) {
        return UNKNOWN_WEIGHT ;
    }
    return weight ;
}

float Weight::getWeight(Weight::UnitOfWeight weightUnits) const noexcept {
    cout << weight << endl;
    return weightUnits ;
}

float Weight::getMaxWeight() const noexcept {
    if(weight == 0.0) {
        return UNKNOWN_WEIGHT ;
    }
    return maxWeight ;
}

Weight::UnitOfWeight Weight::getWeightUnit() const noexcept {
    return unitOfWeight ;
}

void Weight::setWeight(float newWeight) {
    weight = newWeight ;

}

void Weight::setWeight(float newWeight, Weight::UnitOfWeight weightUnits) {
    weight = newWeight ;
    unitOfWeight = weightUnits ;
}

bool Weight::isWeightValid(float checkWeight) const noexcept {
    if(bHasMax == true) {
        if(checkWeight <= maxWeight){
            return true ;
        }
    }
    if(checkWeight > 0) {
       return true;
   }

   return false ;
}

bool Weight::validate() const noexcept {
    if(weight > 0 ) {
        return true ;
    }

    return false ;
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

void Weight::setMaxWeight(float newMaxWeight) {
    maxWeight = newMaxWeight ;
}

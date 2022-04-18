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
#include <stdexcept>
using namespace std ;
const float Weight::KILOS_IN_A_POUND = 0.453592 ;
const float Weight::SLUGS_IN_A_POUND = 0.031081 ;
const float Weight::UNKNOWN_WEIGHT = -1 ;
const string Weight::POUND_LABEL = "POUND" ;
const string Weight::KILO_LABEL = "Kilo" ;
const string Weight::SLUG_LABEL = "Slug" ;




int main () {
    cout << "hello" << endl ;
    Weight  myWeight( 3.14, Weight::KILO, 20 );
    myWeight.dump();


    return 0;
}



float Weight::fromKilogramToPound(const float kilogram) noexcept {
    return kilogram / KILOS_IN_A_POUND;
}


float Weight::fromPoundToKilogram(float pound) noexcept {
    return pound * KILOS_IN_A_POUND ;
}

float Weight::fromSlugToPound(float slug) noexcept {
    return slug / SLUGS_IN_A_POUND ;
}

float Weight::fromPoundToSlug(float pound) noexcept {
    return pound * SLUGS_IN_A_POUND ;
}

float Weight::convertWeight(float fromWeight, Weight::UnitOfWeight fromUnit, Weight::UnitOfWeight toUnit) noexcept {
    float pounds ;
    // convert to pounds
    switch (fromUnit) {
        case KILO :
            pounds = fromKilogramToPound(fromWeight);
            break;
        case SLUG :
            pounds = fromSlugToPound(fromWeight);
            break;
        case POUND :
            break ;
    }
 // convert to desired unit
    switch(toUnit) {
        case KILO :
            return fromPoundToKilogram(pounds);
        case SLUG :
            return fromPoundToSlug(pounds);
        case POUND :
            break ;
    }

}

Weight::Weight() noexcept {
    weight  ;
}

Weight::Weight(float newWeight) {
 Weight::setWeight(newWeight) ;
}

void Weight::setUnitOfWeight(Weight::UnitOfWeight WeightUnit) {
    unitOfWeight = WeightUnit;
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
    if( weight == -1 or weight == 0.0){
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
    if(weight == -1) {
        return UNKNOWN_WEIGHT ;
    }
    return weight ;
}

float Weight::getWeight(Weight::UnitOfWeight weightUnits) const noexcept {
    return weightUnits ;
}

float Weight::getMaxWeight() const noexcept {
    if(weight == -1) {
        return UNKNOWN_WEIGHT ;
    }
    return maxWeight ;
}

Weight::UnitOfWeight Weight::getWeightUnit() const noexcept {
    return unitOfWeight ;
}

void Weight::setWeight(float newWeight) {
    blsKnown = true ;
    weight = newWeight ;

}

void Weight::setWeight(float newWeight, Weight::UnitOfWeight weightUnits) {
    blsKnown = true ;
    weight = newWeight ;
    unitOfWeight = weightUnits ;
}

bool Weight::isWeightValid(float checkWeight) const noexcept {
    if(bHasMax) {
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

void Weight::dump() const {
   string weightUnit;
    switch (getWeightUnit()) {
        case POUND:
            weightUnit = "POUND" ;
            break ;
        case KILO :
            weightUnit = "KILO" ;
            break ;
        case SLUG :
            weightUnit = "SLUG" ;
            break ;
    }

    cout << "==============================================" << endl ;
    cout << "Weight  " << "this " << this << endl ;
    cout << boolalpha << "Weight\t" << "isKnown\t" << isWeightKnown() << endl;
    cout << "Weight  " << "weight " << weight << endl ;
    cout << "Weight  " << "unitOfWeight " << weightUnit << endl;
    cout << boolalpha << "Weight\t" << "hasMax\t" << hasMaxWeight() << endl;
    cout << "Weight  " << "maxWeight " << maxWeight << endl ;
}

bool Weight::operator==(const Weight &rhs_Weight) const {
    float lhs_weight = (blsKnown) ? getWeight(Weight::POUND) : 0;
    float rhs_weight = (rhs_Weight.blsKnown) ? rhs_Weight.getWeight(Weight::POUND) : 0;

    return lhs_weight == rhs_weight;
}

bool Weight::operator<(const Weight &rhs_Weight) const {
    float lhs_weight = (blsKnown) ? getWeight(Weight::POUND) : 0;
    float rhs_weight = (rhs_Weight.blsKnown) ? rhs_Weight.getWeight(Weight::POUND) : 0;

    return lhs_weight < rhs_weight ;

}

Weight& Weight::operator+=(float rhs_addToWeight) {
    if (weight == -1) {
        throw std::out_of_range("Weight is invalid") ;
    }
    float lhs_weight = (blsKnown) ? getWeight(Weight::POUND) : 0;
    return reinterpret_cast<Weight &>(lhs_weight += rhs_addToWeight);

}

void Weight::setMaxWeight(float newMaxWeight) {
    bHasMax = true ;
    maxWeight = newMaxWeight ;
}

/*
  @file weather_utils.c
  @brief implements weather statistics function
*/
#include "array_helpers.h"
#include "weather.h"
#include "weather_utils.h"

int min_temp_hist(WeatherTable array){
    int min = array[0u][0u][0u]._min_temp;

    for(unsigned int year = 0u; year < YEARS; year++){
        for(month_t month = january; month <= december; month ++){
            for (unsigned int day = 0u; day < DAYS; day ++){
                if( min > array[year][month][day]._min_temp){
                    min = array[year][month][day]._min_temp;
                }
            }
        }
    }
    return (min);
}

int max_temp(WeatherTable array, unsigned int year){
    int result = array[year][0u][0u]._max_temp;

    for(month_t month = january; month <= december; month ++){
        for (unsigned int day = 0u; day < DAYS; day ++){
            if( result < array[year][month][day]._max_temp){
                result = array[year][month][day]._max_temp;
            }
        }
    }   
    return (result);
}

void anual_max_temp(WeatherTable array, int result[YEARS]){
    for (unsigned int year = 0; year < YEARS; year++){
        result[year] = max_temp(array,year); // la mayor temperatura máxima del año 'year' + 1980
    }
}

unsigned int total_rainfall_in_month(WeatherTable array, unsigned int year, month_t month){
    unsigned int result = 0u;

    for(unsigned int day = 0u; day < DAYS; day++){
        result = result + array[year][month][day]._rainfall;
    }
    return (result);
}
month_t more_rainfall_month_in_year(WeatherTable array, unsigned year){
    month_t result = january;
    unsigned int rainfall_in_result = total_rainfall_in_month(array,year,result);

    for(month_t month = february; month <= december; month++){
        unsigned int rainfall_in_month = total_rainfall_in_month(array,year,month);

        if( rainfall_in_result < rainfall_in_month){
            result = month;
            rainfall_in_result = rainfall_in_month;
        }
    }
    return (result);
}

void anual_rainfall_month(WeatherTable array, month_t result[YEARS]){
    for(unsigned int year = 0u; year < YEARS; year++){
        result[year] = more_rainfall_month_in_year(array, year); 
    }
}
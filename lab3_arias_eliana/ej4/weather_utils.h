/*
  @file weather_utils.h
  @brief Defines weather statistics functions
*/

#ifndef _WEATHER_UTILS_H
#define _WEATHER_UTILS_H

#include "array_helpers.h"
#include "weather.h"

int min_temp_hist(WeatherTable array);

void anual_max_temp(WeatherTable array, int result[YEARS]);

void anual_rainfall_month(WeatherTable array, month_t result[YEARS]);

#endif

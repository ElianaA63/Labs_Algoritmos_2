/*
  @file weather.c
  @brief Implements weather mesuarement structure and methods
*/
#include <stdlib.h>
#include <stdbool.h>
#include "weather.h"

static const int AMOUNT_OF_WEATHER_VARS = 6 ;

bool valid_weather(Weather weather){
  bool b = weather._max_temp >= weather._average_temp && 
            weather._average_temp >= weather._min_temp && 
            weather._min_temp >= -2731 && weather._moisture <= 100u;
  return b;
}

Weather weather_from_file(FILE* file)
{
    Weather weather;
    /* Completar aqui */
    int k = fscanf(file,EXPECTED_WEATHER_FILE_FORMAT,&weather._average_temp,&weather._max_temp,
                  &weather._min_temp,&weather._pressure,&weather._moisture,&weather._rainfall);
    if(k != AMOUNT_OF_WEATHER_VARS){
      printf("ERROR:Error al leer el archivo");
      exit(EXIT_FAILURE);
    }

    if(!valid_weather(weather)){
      printf("ERROR: invalid data\n");
      exit(EXIT_FAILURE);
    }
    return weather;
}

void weather_to_file(FILE* file, Weather weather)
{
    fprintf(file, EXPECTED_WEATHER_FILE_FORMAT, weather._average_temp, 
            weather._max_temp, weather._min_temp, weather._pressure, weather._moisture, weather._rainfall);
}

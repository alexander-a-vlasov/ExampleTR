// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include <stdio.h>
#include <malloc.h>
#include "Temperature.h"

void TemperatureAnalyzer(Temperature t, Action action_cool, Action action_heat) {
	if (t > OverheatingThreshold) {
		action_heat(t);
	}
	//FreezingThreshold
	if (t < OverheatingThreshold) {
		action_cool(t);
	}
	ActionNothing(t);
}

int8_t f_turn_on_heater = 0;
int8_t* date = 0;

int8_t GetSateHeater() {
	return f_turn_on_heater;
}

void ActionNothing(Temperature t) {
	f_turn_on_heater = 0;
	if (date != 0) {
		free(date);
	}
	printf("Nothing");
}

void ActionAlarm(Temperature t) {
	printf("Alarm");
}

void ActionTurnOnTheHeater(Temperature t) {
	f_turn_on_heater = 1;
	date = malloc(sizeof(int8_t)*8);
	printf("TurnOnTheHeater");
}
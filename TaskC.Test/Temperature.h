#pragma once

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

	//! Константа нулевой температуры
#define Temperature0 55
//! Порог перегрева оборудования 
#define OverheatingThreshold (Temperature0+70)
//! Порог переохлаждения оборудования
#define FreezingThreshold (Temperature0-20)

//! Температура в формате от -54 до 200, 0=-54°C, 55=0°C, 255=200°C
	typedef uint8_t Temperature;
	//! Дествие на событие по температуре
	//  \param t[in] - зарегестрированная текущая температура
	typedef void(*Action) (Temperature t);

	//! Анализируем действия для принятия решения
	//  \param t[in] - зарегестрированная текущая температура
	//  \param action_freezing[in] - действие при замерзании
	//  \param action_overheat[in] - действие при перегреве 
	void TemperatureAnalyzer(Temperature t, Action action_freezing, Action action_overheat);

	//! Возвращает текущее состояние нагревателя
	//  \return 0 - не работает, 1 работает
	int8_t GetSateHeater();

	//! Ничего не делать
	void ActionNothing(Temperature t);
	//! Вызвать действие Alarm
	void ActionAlarm(Temperature t);
	//! Вызвать действие включение обогревателя
	void ActionTurnOnTheHeater(Temperature t);

#ifdef __cplusplus
}
#endif
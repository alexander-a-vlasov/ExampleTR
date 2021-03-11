#pragma once

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

	//! ��������� ������� �����������
#define Temperature0 55
//! ����� ��������� ������������ 
#define OverheatingThreshold (Temperature0+70)
//! ����� �������������� ������������
#define FreezingThreshold (Temperature0-20)

//! ����������� � ������� �� -54 �� 200, 0=-54�C, 55=0�C, 255=200�C
	typedef uint8_t Temperature;
	//! ������� �� ������� �� �����������
	//  \param t[in] - ������������������ ������� �����������
	typedef void(*Action) (Temperature t);

	//! ����������� �������� ��� �������� �������
	//  \param t[in] - ������������������ ������� �����������
	//  \param action_freezing[in] - �������� ��� ����������
	//  \param action_overheat[in] - �������� ��� ��������� 
	void TemperatureAnalyzer(Temperature t, Action action_freezing, Action action_overheat);

	//! ���������� ������� ��������� �����������
	//  \return 0 - �� ��������, 1 ��������
	int8_t GetSateHeater();

	//! ������ �� ������
	void ActionNothing(Temperature t);
	//! ������� �������� Alarm
	void ActionAlarm(Temperature t);
	//! ������� �������� ��������� ������������
	void ActionTurnOnTheHeater(Temperature t);

#ifdef __cplusplus
}
#endif
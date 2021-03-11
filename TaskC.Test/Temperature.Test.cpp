#include "gtest/gtest.h"
#include "Temperature.h"

void ActionBadRun(Temperature t) {
	FAIL();
}

//! Отладка состояния что все нормально
TEST(TemperatureAnalyzer, TestNotRunDebug) {
	Temperature t = 50;
	TemperatureAnalyzer(t, &ActionBadRun, &ActionBadRun);
	SUCCEED();
}

bool f_run_good;

void ActionGoodRun(Temperature t) {
	f_run_good = true;
	SUCCEED();
}

//! Отладка состояния перегрева
TEST(TemperatureAnalyzer, TestOverheatingDebug) {
	f_run_good = false;
	Temperature t = 200;
	TemperatureAnalyzer(t, &ActionBadRun, &ActionGoodRun);
	if (!f_run_good) {
		FAIL();
	}
}

//! Отладка состояния заморозки
TEST(TemperatureAnalyzer, TestFreezingDebug) {
	f_run_good = false;
	Temperature t = 5;
	TemperatureAnalyzer(t, &ActionGoodRun, &ActionBadRun);
	if (!f_run_good) {
		FAIL();
	}
	//EXPECT_EQ(1, 1);
	//EXPECT_TRUE(true);
}

//! Проверяем что если у нас перегрев, то нагреватель должен быть выключен
TEST(TemperatureAnalyzer, TestHeating) {
	f_run_good = false;
	Temperature t = 5;
	TemperatureAnalyzer(t, &ActionGoodRun, &ActionBadRun);
	uint8_t cur_state = GetSateHeater();
	EXPECT_TRUE(cur_state != 0);
	t = 200;
	TemperatureAnalyzer(t, &ActionBadRun, &ActionGoodRun);
	cur_state = GetSateHeater();
	EXPECT_TRUE(cur_state==0);
	//EXPECT_EQ(1, 1);
	//EXPECT_TRUE(true);
}

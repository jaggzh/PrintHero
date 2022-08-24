#ifndef PRINTHERO_H
#define PRINTHERO_H
//Define this in your code before including this header:
//#define DEBUG_PRINT 1
#if defined(ARDUINO) || defined(ESP_PLATFORM)
	#include <Arduino.h>
	#define sp(a)  (Serial.print(a))
	#define spl(a) (Serial.println(a))
	#ifdef DEBUG_PRINT
		#define dbsp(a)  (Serial.print(a))
		#define dbspl(a) (Serial.println(a))
		#define dbprintf(...) // printf(__VA_ARGS__) // not in mcu, sorry
	#else // versions that do nothing if no DEBUG_PRINT
		#define dbsp(a)
		#define dbspl(a)
		#define dbprintf(...)
	#endif
#else
	#define sp(a)  (std::cout << (a))
	#define spl(a) (std::cout << (a) << std::endl)
	#ifdef DEBUG_PRINT
		#define dbsp(a)  (std::cout << (a))
		#define dbspl(a) (std::cout << (a) << std::endl)
		#define dbprintf(...) printf(__VA_ARGS__)
	#else // versions that do nothing if no DEBUG_PRINT
		#define dbsp(a)
		#define dbspl(a)
		#define dbprintf(...)
	#endif
#endif

enum spt_type {
	T_END=0, // they'll terminate args with 0 so make it clear
	T_CH,
	T_UCH,
	T_INT,
	T_UINT,
	T_CHP,
	T_LON,
	T_ULON,
	T_FLO,
	T_DOUB,
	T_STR,
};

#ifdef __cplusplus
extern "C" {
#endif

void spt(int type, ...); // terminate with T_END
/* Ex: spt(T_CHAR, 'H', T_CHARP, "ello world", T_END); */

#ifdef __cplusplus
}
#endif

#endif // PRINTHERO_H



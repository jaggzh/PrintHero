# PrintHero

Tiny library for convenience and especially to save the precious time of your
life for better things, and your joints from abuse, and your wrists, and your
precious heartbeats.

Mostly this library is just a few macros, like "#define sp(v) Serial.print(v)"
"#define spl(v) Serial.println(v)", but some other good things are here too.

Use like:

```c++
#define DEBUG_PRINT     // enables dbsp*() calls
#include <PrintHero.h>

void fn(void) {
	sp(whatever);   /* This will Serial.print() with ARDUINO or ESP_PLATFORM
	                   but will std::cout otherwise */
	spl(whatever);  /* Serial.println(v) (or cout << v << endl) */

	/* Versions which only output if DEBUG_PRINT is defined.
	   
	dbsp(whatever);  /* Same as sp(), but DEBUG_PRINT must be defined, or it
	                    expands to nothing */
	dbspl(whatever); /* Same as spl() ... std::cout << whatever << std::endl */
}
```

There's an `spt()` call in here which I've not tested much. It's an actual
C routine that lets you print multiple values like:

```c++
 spt(T_CHAR, 'H', T_CHARP, "ello world", T_END);
 /* Make sure to end list with T_END !!  ^^^^^ */
```

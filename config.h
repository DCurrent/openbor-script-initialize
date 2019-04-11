// Dependencies
#include "data/scripts/dc_d20/main.c"
#include "data/scripts/dc_fidelity/main.c"

#ifndef DC_INITIALIZE_CONFIG
#define DC_INITIALIZE_CONFIG 1

// Default values.
#define DC_INITIALIZE_DEFAULT_INSTANCE		0
#define DC_INITIALIZE_DEFAULT_ENT			getlocalvar("self")

// Variable indentifiers.
#define DC_INITIALIZE_VAR_KEY_INSTANCE		"dcini_0"
#define DC_INITIALIZE_VAR_KEY_ENT			"dcini_1"
#define DC_INITIALIZE_VAR_KEY_ALIAS_LIST	"dcini_2"

#endif // !DC_INITIALIZE

#pragma once


#define TAPPING_FORCE_HOLD
#define IGNORE_MOD_TAP_INTERRUPT
#define COMBO_COUNT 5

/* Charybdis-specific features. */

// Enable pointer acceleration, which increases the speed by ~2x for large
// displacement, while maintaining 1x speed for slow movements.  See also:
// - `CHARYBDIS_POINTER_ACCELERATION_FACTOR`
#define CHARYBDIS_POINTER_ACCELERATION_ENABLE

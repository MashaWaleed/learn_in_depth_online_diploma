#define STATE_define(_statFUN_) void ST_##_statFUN_ ()
#define STATE(_statFUN_) ST_##_statFUN_

void US_set_distance(int d);
void DC_motor(int s);

#include "data/scripts/dc_initialize/config.h"

#import "data/scripts/dc_initialize/config.c"

// Set up a generic flash spawn.
void dc_initialize_flash_default()
{
	void ent;
	int force;
	int	rotate;
	int drawsize;
	int intensity;
	int sound_speed;
	int size;
	void drawmethod;

	ent = getlocalvar("self");

	drawmethod = get_entity_property(ent, "drawmethod");

	// Get random numbers for rotation.
	dc_d20_set_range_lower(0);
	dc_d20_set_range_upper(359);

	rotate = dc_d20_random_int();

	// Get attack force.
	force = get_attack_property(openborvariant("lasthit_attack"), openborconstant("ATTACK_PROP_DAMAGE_FORCE"));

	// Get an intensity value. Think of this as a percentage of base hit
	// force. We start with a base force and subtract that from the real force. 
	// Then we mutiply the result to give it more variance and subtract the total 
	// value from 100. So if we have a base value of 10, an attack damage of 10 
	// is 100 (i.e. 100% intensity). If the attack is 5 damage, and mutiplier 
	// is 4, then intensity will be 80. Damage of 15 would produce an intensity 
	// of 120. We can then use the intensity value to control size of flash
	// and speed of sound playback to create a dynamic experience. This is based
	// on OpenBOR's native damage based hitfx playback speed.
	intensity = 100 - ((force - 10) * 4);

	// For size, we'll start with a bit of oversize and subtract our intensity
	// value to get the final size.
	size = 200 - intensity;

	// Apply the drawmethods for blending, rotation, and size.
	//dc_kanga_z_position_autoscale(ent);
	set_drawmethod_property(drawmethod, "alpha", 1);
	set_drawmethod_property(drawmethod, "enable", 1);
	set_drawmethod_property(drawmethod, "rotate", rotate);
	set_drawmethod_property(drawmethod, "scale_x", size);
	set_drawmethod_property(drawmethod, "scale_y", size);

	// We'll cap our intenstiy ranges here and then use it for sound playback speed.
	if (intensity > 130)
	{
		intensity = 130;
	}
	else if (intensity < 70)
	{
		intensity = 70;
	}

	// Set the sound speed and play.
	dc_fidelity_set_sound_speed(intensity);
	dc_fidelity_quick_play(DC_FIDELITY_TYPE_SOUND_SPAWN);
}

#include <ansi.h>
#include <weapon.h>
inherit BLADE;
void create()
{
	set_name(WHT"ŒË‘∆µ∂"NOR, ({ "blade" }) );
	set_weight(2000);
	if( clonep() )
			set_default_object(__FILE__);
	else {
			set("unit", "∞—");
			set("value", 10);
			set("material", "silk");
	}
	::init_blade(10);
}


/*

°°°°°°°°°°°°°°®X®Y
°°°°°°°°°°°°°°®U®t®r
°°°°°°°°°°°°°°®U©¶®t®r
°°°°°°°°°°°°°°®U©¶©¶®t®r
°°°°°°°°°°°°°°®U©¶©¶©¶©¶
°°°°°°°°°°°°°°®^®k®k®k®_

°°°°°°°°°°°°°°- FengYun - °°°°°°
°°°°°°°°°°°°annie 08.2003
°°°°°°dancing_faery@hotmail.com
*/


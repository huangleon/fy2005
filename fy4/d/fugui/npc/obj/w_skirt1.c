// cloth.c
//

#include <armor.h>

inherit CLOTH;
#include <ansi.h>
void create()
{
    set_name(GRN"ËØæı³¤È¹"NOR, ({ "greenskirt" }) );
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "¼ş");

		set("long", "Ò»¼şÂÌÈ¹ËÆºÉÒ¶Æ®µ´£¬ÂŞÍàÎ¢³¾¡£\n");
		set("material", "cloth");
        set("value", 1000);
         set("armor_prop/armor", 3);
		set("female_only", 1);
	}
	::init_cloth();
}

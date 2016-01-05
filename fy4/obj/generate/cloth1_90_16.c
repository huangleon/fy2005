#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create() {
	set_name(MAG"ìµ°ßµã²Ô"NOR, ({ "cloth"}) );
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "¼þ");
		set("generate_item",1);
		set("lore",1);
		set("material", "cloth");
		set("female_only", 1);
		set("level_required", 70);
		set("armor_prop/armor", 85);
		set("armor_prop/strength", 6);
		set("armor_prop/intelligence", 6);
		set("armor_prop/composure", 6);
		set("armor_prop/constitutionx", 0);	// ÒÑ·ÏÆú
		set("armor_prop/agility", 6);
		set("armor_prop/karma", 6);
		set("armor_prop/max_gin", 270);
		set("armor_prop/max_kee", 600);
		set("armor_prop/max_sen", 270);
//		set("long","\n");	// ÒÑ·ÏÆú
	}
	::init_cloth();
}

// ÄýÝp¡¤dancing_faery@hotmail.com


#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create() {
	set_name(HIM"Ê¥Áé·¨Ã±"NOR, ({ "hat"}) );
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "¼þ");
		set("generate_item",1);
		set("lore",1);
		set("material", "cloth");
		set("male_only", 1);
		set("level_required", 50);
		set("armor_prop/armor", 10);
		set("armor_prop/strength", 5);
		set("armor_prop/intelligence", 25);
		set("armor_prop/composure", 5);
		set("armor_prop/constitutionx", 0);	// ÒÑ·ÏÆú
		set("armor_prop/agility", 5);
		set("armor_prop/karma", 5);
		set("armor_prop/max_gin", 500);
		set("armor_prop/max_kee", 220);
		set("armor_prop/max_sen", 500);
//		set("long","ÃèÊö\n");	// ÒÑ·ÏÆú
	}
	::init_head();
}

// ÄýÝp¡¤dancing_faery@hotmail.com


#include <ansi.h>
#include <armor.h>

inherit BOOTS;

void create() {
	set_name(HIR BLK"ÂíÑ¥"NOR, ({ "boots"}) );
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "¼þ");
		set("generate_item",1);
		set("lore",1);
		set("material", "cloth");
		set("male_only", 1);
		set("level_required", 20);
		set("armor_prop/armor", 2);
		set("armor_prop/strength", 2);
		set("armor_prop/intelligence", 2);
		set("armor_prop/composure", 2);
		set("armor_prop/constitutionx", 0);	// ÒÑ·ÏÆú
		set("armor_prop/agility", 10);
		set("armor_prop/karma", 2);
		set("armor_prop/max_gin", 24);
		set("armor_prop/max_kee", 30);
		set("armor_prop/max_sen", 24);
//		set("long","ÃèÊö\n");	// ÒÑ·ÏÆú
	}
	::init_boots();
}

// ÄýÝp¡¤dancing_faery@hotmail.com


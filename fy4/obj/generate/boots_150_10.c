#include <ansi.h>
#include <armor.h>

inherit BOOTS;

void create() {
	set_name(HIY"¼â¼×Ðý·æ"NOR, ({ "boots"}) );
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "¼þ");
		set("generate_item",1);
		set("lore",1);
		set("material", "cloth");
		set("male_only", 1);
		set("level_required", 120);
		set("armor_prop/armor", 9);
		set("armor_prop/strength", 9);
		set("armor_prop/intelligence", 9);
		set("armor_prop/composure", 9);
		set("armor_prop/agility", 45);
		set("armor_prop/karma", 9);
		set("armor_prop/max_gin", 136);
		set("armor_prop/max_kee", 170);
		set("armor_prop/max_sen", 136);
//		set("long","ÃèÊö\n");	// ÒÑ·ÏÆú
	}
	::init_boots();
}

// ÄýÝp¡¤dancing_faery@hotmail.com


#include <ansi.h>
#include <armor.h>

inherit BOOTS;

void create() {
	set_name(MAG"¼²·ç²ÝÐ¬"NOR, ({ "shoes"}) );
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "¼þ");
		set("generate_item",1);
		set("lore",1);
		set("material", "cloth");
		set("male_only", 1);
		set("level_required", 10);
		set("armor_prop/armor", 1);
		set("armor_prop/strength", 1);
		set("armor_prop/intelligence", 1);
		set("armor_prop/composure", 1);
		set("armor_prop/constitutionx", 0);	// ÒÑ·ÏÆú
		set("armor_prop/agility", 5);
		set("armor_prop/karma", 1);
		set("armor_prop/max_gin", 8);
		set("armor_prop/max_kee", 10);
		set("armor_prop/max_sen", 8);
//		set("long","ÃèÊö\n");	// ÒÑ·ÏÆú
	}
	::init_boots();
}

// ÄýÝp¡¤dancing_faery@hotmail.com


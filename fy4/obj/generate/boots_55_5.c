#include <ansi.h>
#include <armor.h>

inherit BOOTS;

void create() {
	set_name(CYN"»¢Ð¥Ð¬"NOR, ({ "shoes"}) );
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "¼þ");
		set("generate_item",1);
		set("lore",1);
		set("material", "cloth");
		set("male_only", 1);
		set("level_required", 40);
		set("armor_prop/armor", 4);
		set("armor_prop/strength", 4);
		set("armor_prop/intelligence", 4);
		set("armor_prop/composure", 4);
		set("armor_prop/constitutionx", 0);	// ÒÑ·ÏÆú
		set("armor_prop/agility", 20);
		set("armor_prop/karma", 4);
		set("armor_prop/max_gin", 56);
		set("armor_prop/max_kee", 70);
		set("armor_prop/max_sen", 56);
//		set("long","ÃèÊö\n");	// ÒÑ·ÏÆú
	}
	::init_boots();
}

// ÄýÝp¡¤dancing_faery@hotmail.com


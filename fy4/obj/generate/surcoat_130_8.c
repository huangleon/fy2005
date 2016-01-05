#include <ansi.h>
#include <armor.h>

inherit SURCOAT;

void create() {
	set_name(BLK"ÒµÕÏÅû²«"NOR, ({ "coat"}) );
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "¼þ");
		set("generate_item",1);
		set("lore",1);
		set("material", "cloth");
		set("male_only", 1);
		set("level_required", 105);
		set("armor_prop/armor", 16);
		set("armor_prop/strength", 40);
		set("armor_prop/intelligence", 8);
		set("armor_prop/composure", 8);
		set("armor_prop/constitutionx", 2);	// ÒÑ·ÏÆú
		set("armor_prop/agility", 8);
		set("armor_prop/karma", 8);
		set("armor_prop/max_gin", 120);
		set("armor_prop/max_kee", 150);
		set("armor_prop/max_sen", 120);
//		set("long","ÃèÊö\n");	// ÒÑ·ÏÆú
	}
	::init_surcoat();
}

// ÄýÝp¡¤dancing_faery@hotmail.com


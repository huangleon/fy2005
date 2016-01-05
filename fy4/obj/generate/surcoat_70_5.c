#include <ansi.h>
#include <armor.h>

inherit SURCOAT;

void create() {
	set_name(BLU"ÁèÔÆÅû·ç"NOR, ({ "pifeng"}) );
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
		set("armor_prop/strength", 25);
		set("armor_prop/intelligence", 5);
		set("armor_prop/composure", 5);
		set("armor_prop/constitutionx", 0);	// ÒÑ·ÏÆú
		set("armor_prop/agility", 5);
		set("armor_prop/karma", 5);
		set("armor_prop/max_gin", 72);
		set("armor_prop/max_kee", 90);
		set("armor_prop/max_sen", 72);
//		set("long","ÃèÊö\n");	// ÒÑ·ÏÆú
	}
	::init_surcoat();
}

// ÄýÝp¡¤dancing_faery@hotmail.com


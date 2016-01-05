#include <ansi.h>
#include <armor.h>

inherit SURCOAT;

void create() {
	set_name(HIR"»ðÑÞÒÂ"NOR, ({ "surcoat"}) );
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "¼þ");
		set("generate_item",1);
		set("lore",1);
		set("material", "cloth");
		set("female_only", 1);
		set("level_required", 10);
		set("armor_prop/armor", 2);
		set("armor_prop/strength", 5);
		set("armor_prop/intelligence", 1);
		set("armor_prop/composure", 1);
		set("armor_prop/constitutionx", 0);	// ÒÑ·ÏÆú
		set("armor_prop/agility", 1);
		set("armor_prop/karma", 1);
		set("armor_prop/max_gin", 8);
		set("armor_prop/max_kee", 10);
		set("armor_prop/max_sen", 8);
		set("long","ÏÊºìÈç»ðµÄÒÂÉÑ¡£\n");	// ÒÑ·ÏÆú
	}
	::init_surcoat();
}

// ÄýÝp¡¤dancing_faery@hotmail.com


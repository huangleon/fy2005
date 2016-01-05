#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create() {
	set_name(RED"·çÕÖÏ¼ÒÂ"NOR, ({ "cloth"}) );
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "¼þ");
		set("generate_item",1);
		set("lore",1);
		set("material", "cloth");
		set("female_only", 1);
		set("level_required", 105);
		set("armor_prop/armor", 115);
		set("armor_prop/strength", 8);
		set("armor_prop/intelligence", 8);
		set("armor_prop/composure", 8);
		set("armor_prop/constitutionx", 7);	// ÒÑ·ÏÆú
		set("armor_prop/agility", 8);
		set("armor_prop/karma", 8);
		set("armor_prop/max_gin", 370);
		set("armor_prop/max_kee", 800);
		set("armor_prop/max_sen", 370);
//		set("long","ÃèÊö\n");	// ÒÑ·ÏÆú
	}
	::init_cloth();
}

// ÄýÝp¡¤dancing_faery@hotmail.com


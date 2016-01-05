#include <ansi.h>
#include <armor.h>

inherit BOOTS;

void create() {
	set_name(YEL"ÉÆÃ¢Ñ¥"NOR, ({ "boots"}) );
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "¼þ");
		set("generate_item",1);
		set("lore",1);
		set("material", "cloth");
		set("male_only", 1);
		set("level_required", 90);
		set("armor_prop/armor", 7);
		set("armor_prop/strength", 7);
		set("armor_prop/intelligence", 7);
		set("armor_prop/composure", 7);
		set("armor_prop/agility", 35);
		set("armor_prop/karma", 7);
		set("armor_prop/max_gin", 104);
		set("armor_prop/max_kee", 130);
		set("armor_prop/max_sen", 104);
//		set("long","ÃèÊö\n");	// ÒÑ·ÏÆú
	}
	::init_boots();
}

// ÄýÝp¡¤dancing_faery@hotmail.com


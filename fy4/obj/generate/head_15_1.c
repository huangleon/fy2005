#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create() {
	set_name(YEL"»¢Æ¤Ã±"NOR, ({ "hat"}) );
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
		set("armor_prop/armor", 2);
		set("armor_prop/strength", 1);
		set("armor_prop/intelligence", 5);
		set("armor_prop/composure", 1);
		set("armor_prop/constitutionx", 0);	// ÒÑ·ÏÆú
		set("armor_prop/agility", 1);
		set("armor_prop/karma", 1);
		set("armor_prop/max_gin", 100);
		set("armor_prop/max_kee", 20);
		set("armor_prop/max_sen", 100);
//		set("long","ÃèÊö\n");	// ÒÑ·ÏÆú
	}
	::init_head();
}

// ÄýÝp¡¤dancing_faery@hotmail.com


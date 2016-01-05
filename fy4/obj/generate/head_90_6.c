#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create() {
	set_name(YEL"½ð¸Õ¶·óÒ"NOR, ({ "hat"}) );
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "¼þ");
		set("generate_item",1);
		set("lore",1);
		set("material", "cloth");
		set("male_only", 1);
		set("level_required", 70);
		set("armor_prop/armor", 12);
		set("armor_prop/strength", 6);
		set("armor_prop/intelligence", 30);
		set("armor_prop/composure", 6);
		set("armor_prop/constitutionx", 0);	// ÒÑ·ÏÆú
		set("armor_prop/agility", 6);
		set("armor_prop/karma", 6);
		set("armor_prop/max_gin", 600);
		set("armor_prop/max_kee", 270);
		set("armor_prop/max_sen", 600);
//		set("long","ÃèÊö\n");	// ÒÑ·ÏÆú
	}
	::init_head();
}

// ÄýÝp¡¤dancing_faery@hotmail.com


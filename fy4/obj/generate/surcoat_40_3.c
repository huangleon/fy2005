#include <ansi.h>
#include <armor.h>

inherit SURCOAT;

void create() {
	set_name(HIY"»¢Æ¤´óÒÂ"NOR, ({ "coat"}) );
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "¼þ");
		set("generate_item",1);
		set("lore",1);
		set("material", "cloth");
		set("male_only", 1);
		set("level_required", 30);
		set("armor_prop/armor", 6);
		set("armor_prop/strength", 15);
		set("armor_prop/intelligence", 3);
		set("armor_prop/composure", 3);
		set("armor_prop/constitutionx", 2);	// ÒÑ·ÏÆú
		set("armor_prop/agility", 3);
		set("armor_prop/karma", 3);
		set("armor_prop/max_gin", 40);
		set("armor_prop/max_kee", 50);
		set("armor_prop/max_sen", 40);
//		set("long","ÃèÊö\n");	// ÒÑ·ÏÆú
	}
	::init_surcoat();
}

// ÄýÝp¡¤dancing_faery@hotmail.com


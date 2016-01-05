#include <ansi.h>
#include <armor.h>

inherit WRISTS;

void create() {
	set_name(YEL"¼ªÏéÊÖïí"NOR, ({ "wrists"}) );
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "¼ş");
		set("material", "cloth");
		set("generate_item",1);
		set("level_required", 10);
		set("armor_prop/armor", 1);
		set("armor_prop/strength", 1);
		set("armor_prop/intelligence", 1);
		set("armor_prop/composure", 1);
		set("armor_prop/constitutionx", 0);	// ÒÑ·ÏÆú
		set("armor_prop/agility", 1);
		set("armor_prop/karma", 5);
		set("armor_prop/max_gin", 8);
		set("armor_prop/max_kee", 10);
		set("armor_prop/max_sen", 8);
//		set("long","ÃèÊö\n");	// ÒÑ·ÏÆú
	}
	::init_wrists();
}

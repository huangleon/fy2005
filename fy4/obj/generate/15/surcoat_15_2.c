#include <ansi.h>
#include <armor.h>

inherit SURCOAT;

void create() {
	set_name(CYN"ÄýÓêÁ«É´"NOR, ({ "surcoat"}) );
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "¼þ");
		set("material", "cloth");
		set("female_only", 1);
		set("level_required", 10);
		set("armor_prop/armor", 1);
		set("armor_prop/strength", 1);
		set("armor_prop/intelligence", 0);
		set("armor_prop/composure", 0);
		set("armor_prop/constitutionx", 0);	// ÒÑ·ÏÆú
		set("armor_prop/agility", 0);
		set("armor_prop/karma", 0);
		set("armor_prop/max_gin", 0);
		set("armor_prop/max_kee", 20);
		set("armor_prop/max_sen", 10);
//		set("long","ÃèÊö\n");	// ÒÑ·ÏÆú
	}
	::init_surcoat();
}

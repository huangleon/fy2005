#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create() {
	set_name(CYN"·ÉÐõÍâÈ¹"NOR, ({ "cloth"}) );
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "¼þ");
		set("generate_item",1);
		set("lore",1);
		set("material", "cloth");
		set("female_only", 1);
		set("level_required", 90);
		set("armor_prop/armor", 100);
		set("armor_prop/strength", 7);
		set("armor_prop/intelligence", 7);
		set("armor_prop/composure", 7);
		set("armor_prop/constitutionx", 0);	// ÒÑ·ÏÆú
		set("armor_prop/agility", 7);
		set("armor_prop/karma", 7);
		set("armor_prop/max_gin", 320);
		set("armor_prop/max_kee", 700);
		set("armor_prop/max_sen", 320);
//		set("long","ÃèÊö\n");	// ÒÑ·ÏÆú
	}
	::init_cloth();
}

// ÄýÝp¡¤dancing_faery@hotmail.com


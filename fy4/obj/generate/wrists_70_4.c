#include <ansi.h>
#include <armor.h>

inherit WRISTS;

void create() {
	set_name(HIY"ÉÁÀ×ÊÖÁ´"NOR, ({ "wrists"}) );
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "¼þ");
		set("generate_item",1);
		set("lore",1);
		set("material", "cloth");
		set("1_only", 1);
		set("level_required", 50);
		set("armor_prop/armor", 5);
		set("armor_prop/strength", 5);
		set("armor_prop/intelligence", 5);
		set("armor_prop/composure", 5);
		set("armor_prop/constitutionx", 0);	// ÒÑ·ÏÆú
		set("armor_prop/agility", 5);
		set("armor_prop/karma", 25);
		set("armor_prop/max_gin", 72);
		set("armor_prop/max_kee", 90);
		set("armor_prop/max_sen", 72);
//		set("long","ÃèÊö\n");	// ÒÑ·ÏÆú
	}
	::init_wrists();
}

// ÄýÝp¡¤dancing_faery@hotmail.com


#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create() {
	set_name(WHT"�䳾��"NOR, ({ "hat"}) );
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("generate_item",1);
		set("lore",1);
		set("material", "cloth");
		set("male_only", 1);
		set("level_required", 120);
		set("armor_prop/armor", 18);
		set("armor_prop/strength", 9);
		set("armor_prop/intelligence", 45);
		set("armor_prop/composure", 9);
		set("armor_prop/constitutionx", 7);	// �ѷ���
		set("armor_prop/agility", 9);
		set("armor_prop/karma", 9);
		set("armor_prop/max_gin", 900);
		set("armor_prop/max_kee", 420);
		set("armor_prop/max_sen", 900);
//		set("long","����\n");	// �ѷ���
	}
	::init_head();
}

// ���p��dancing_faery@hotmail.com


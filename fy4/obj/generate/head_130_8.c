#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create() {
	set_name(HIW"�޳���ñ"NOR, ({ "hat"}) );
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("generate_item",1);
		set("lore",1);
		set("material", "cloth");
		set("male_only", 1);
		set("level_required", 105);
		set("armor_prop/armor", 16);
		set("armor_prop/strength", 8);
		set("armor_prop/intelligence", 40);
		set("armor_prop/composure", 8);
		set("armor_prop/constitutionx", 0);	// �ѷ���
		set("armor_prop/agility", 8);
		set("armor_prop/karma", 8);
		set("armor_prop/max_gin", 800);
		set("armor_prop/max_kee", 370);
		set("armor_prop/max_sen", 800);
//		set("long","����\n");	// �ѷ���
	}
	::init_head();
}

// ���p��dancing_faery@hotmail.com


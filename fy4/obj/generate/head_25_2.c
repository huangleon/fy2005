#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create() {
	set_name(HIM"�Ͻ��"NOR, ({ "hat"}) );
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("generate_item",1);
		set("lore",1);
		set("material", "cloth");
		set("male_only", 1);
		set("level_required", 20);
		set("armor_prop/armor", 4);
		set("armor_prop/strength", 2);
		set("armor_prop/intelligence", 10);
		set("armor_prop/composure", 2);
		set("armor_prop/constitutionx", 0);	// �ѷ���
		set("armor_prop/agility", 2);
		set("armor_prop/karma", 2);
		set("armor_prop/max_gin", 200);
		set("armor_prop/max_kee", 70);
		set("armor_prop/max_sen", 200);
//		set("long","����\n");	// �ѷ���
	}
	::init_head();
}

// ���p��dancing_faery@hotmail.com


#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create() {
	set_name(CYN"�Ű�ͷ��"NOR, ({ "hat"}) );
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("generate_item",1);
		set("lore",1);
		set("material", "cloth");
		set("male_only", 1);
		set("level_required", 135);
		set("armor_prop/armor", 20);
		set("armor_prop/strength", 10);
		set("armor_prop/intelligence", 50);
		set("armor_prop/composure", 10);
		set("armor_prop/constitutionx", 7);	// �ѷ���
		set("armor_prop/agility", 10);
		set("armor_prop/karma", 10);
		set("armor_prop/max_gin", 1000);
		set("armor_prop/max_kee", 470);
		set("armor_prop/max_sen", 1000);
//		set("long","����\n");	// �ѷ���
	}
	::init_head();
}

// ���p��dancing_faery@hotmail.com


#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create() {
	set_name(YEL"�����"NOR, ({ "clasp"}) );
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("generate_item",1);
		set("lore",1);
		set("material", "cloth");
		set("female_only", 1);
		set("level_required", 90);
		set("armor_prop/armor", 14);
		set("armor_prop/strength", 7);
		set("armor_prop/intelligence", 35);
		set("armor_prop/composure", 7);
		set("armor_prop/constitutionx", 0);	// �ѷ���
		set("armor_prop/agility", 7);
		set("armor_prop/karma", 7);
		set("armor_prop/max_gin", 700);
		set("armor_prop/max_kee", 320);
		set("armor_prop/max_sen", 700);
		set("long","�����������õķ�����\n");	// �ѷ���
	}
	::init_head();
}

// ���p��dancing_faery@hotmail.com


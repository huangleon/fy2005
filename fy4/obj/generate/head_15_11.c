#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create() {
	set_name(YEL"��裷���"NOR, ({ "hairclamp"}) );
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("generate_item",1);
		set("lore",1);
		set("material", "cloth");
		set("female_only", 1);
		set("level_required", 10);
		set("armor_prop/armor", 2);
		set("armor_prop/strength", 1);
		set("armor_prop/intelligence", 5);
		set("armor_prop/composure", 1);
		set("armor_prop/constitutionx", 0);	// �ѷ���
		set("armor_prop/agility", 1);
		set("armor_prop/karma", 1);
		set("armor_prop/max_gin", 100);
		set("armor_prop/max_kee", 20);
		set("armor_prop/max_sen", 100);
		set("long","һ��С���������裷��С�\n");	// �ѷ���
	}
	::init_head();
}

// ���p��dancing_faery@hotmail.com


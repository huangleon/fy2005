#include <ansi.h>
#include <armor.h>

inherit NECK;

void create() {
	set_name(HIY"������"NOR, ({ "necklace"}) );
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("generate_item",1);
		set("lore",1);
		set("material", "cloth");
		set("female_only", 1);
		set("level_required", 105);
		set("armor_prop/armor", 8);
		set("armor_prop/strength", 8);
		set("armor_prop/intelligence", 8);
		set("armor_prop/composure", 40);
		set("armor_prop/constitutionx", 7);	// �ѷ���
		set("armor_prop/agility", 8);
		set("armor_prop/karma", 8);
		set("armor_prop/max_gin", 120);
		set("armor_prop/max_kee", 150);
		set("armor_prop/max_sen", 120);
		set("long","������ɵ�������ټ�����һ�Ҹ�������ϡƷ��\n");	// �ѷ���
	}
	::init_neck();
}

// ���p��dancing_faery@hotmail.com


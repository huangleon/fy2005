#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create() {
	set_name(HIG"��Ҷ����"NOR, ({ "cloth"}) );
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("generate_item",1);
		set("lore",1);
		set("material", "cloth");
		set("female_only", 1);
		set("level_required", 50);
		set("armor_prop/armor", 70);
		set("armor_prop/strength", 5);
		set("armor_prop/intelligence", 5);
		set("armor_prop/composure", 5);
		set("armor_prop/constitutionx", 1);	// �ѷ���
		set("armor_prop/agility", 5);
		set("armor_prop/karma", 5);
		set("armor_prop/max_gin", 220);
		set("armor_prop/max_kee", 500);
		set("armor_prop/max_sen", 220);
		set("long","�������ӳֹ����·����������⻹����߶�����\n");	// �ѷ���
	}
	::init_cloth();
}

// ���p��dancing_faery@hotmail.com


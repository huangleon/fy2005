#include <ansi.h>
#include <armor.h>

inherit SURCOAT;

void create() {
	set_name(BLU"��������"NOR, ({ "surcoat"}) );
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
		set("armor_prop/armor", 16);
		set("armor_prop/strength", 40);
		set("armor_prop/intelligence", 8);
		set("armor_prop/composure", 8);
		set("armor_prop/constitutionx", 2);	// �ѷ���
		set("armor_prop/agility", 8);
		set("armor_prop/karma", 8);
		set("armor_prop/max_gin", 120);
		set("armor_prop/max_kee", 150);
		set("armor_prop/max_sen", 120);
		set("long","�õ���ɫ��ë֯�ɵ����磬�ޱ�������\n");	// �ѷ���
	}
	::init_surcoat();
}

// ���p��dancing_faery@hotmail.com


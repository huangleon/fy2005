#include <ansi.h>
#include <armor.h>

inherit BOOTS;

void create() {
	set_name(RED"�಻մ"NOR, ({ "shoes"}) );
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "˫");
		set("value",800);	// ��value���������ù��������̵ꣻ����������ǰ�ڱ��ܴ����б��档
		set("generate_item_common",1);
		set("lore",1);
		set("material", "cloth");
		set("male_only", 1);
		set("level_required", 0);
		set("armor_prop/armor", 1);
		set("armor_prop/strength", -10);
		set("armor_prop/intelligence", 0);
		set("armor_prop/composure", 0);
		set("armor_prop/constitutionx", 0);	// �ѷ���
		set("armor_prop/agility", -20);
		set("armor_prop/karma", 0);
		set("armor_prop/max_gin", 0);
		set("armor_prop/max_kee", 100);
		set("armor_prop/max_sen", 0);
		set("long","�������Ҵܵ�С�к���������Ь�Ͳ���Ū���ѾѾ��\n");	// �ѷ���
	}
	::init_boots();
}

// ���p��dancing_faery@hotmail.com


#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create() {
	set_name(BLU"���ƿ��ɿ�"NOR, ({ "cloth"}) );
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value",2400);	// ��value���������ù��������̵ꣻ����������ǰ�ڱ��ܴ����б��档
		set("generate_item_common",1);
		set("lore",1);
		set("material", "cloth");
		set("male_only", 1);
		set("level_required", 0);
		set("armor_prop/armor", 5);
		set("armor_prop/strength", 0);
		set("armor_prop/intelligence", 0);
		set("armor_prop/composure", 0);
		set("armor_prop/constitutionx", 0);	// �ѷ���
		set("armor_prop/agility", 0);
		set("armor_prop/karma", 0);
		set("armor_prop/max_gin", 0);
		set("armor_prop/max_kee", 100);
		set("armor_prop/max_sen", -120);
		set("long","һ�����Ƴ��е�С���ǰ��õ����\n");	// �ѷ���
	}
	::init_cloth();
}

// ���p��dancing_faery@hotmail.com


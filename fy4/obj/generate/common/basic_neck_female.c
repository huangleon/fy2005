#include <ansi.h>
#include <armor.h>

inherit NECK;

void create() {
	set_name(CYN"ϲ�ֻ����"NOR, ({ "amulet"}) );
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value",1800);	// ��value���������ù��������̵ꣻ����������ǰ�ڱ��ܴ����б��档
		set("generate_item_common",1);
		set("lore",1);
		set("material", "cloth");
		set("female_only", 1);
		set("level_required", 0);
		set("armor_prop/armor", 1);
		set("armor_prop/strength", 0);
		set("armor_prop/intelligence", 0);
		set("armor_prop/composure", -10);
		set("armor_prop/constitutionx", 0);	// �ѷ���
		set("armor_prop/agility", 0);
		set("armor_prop/karma", -20);
		set("armor_prop/max_gin", 0);
		set("armor_prop/max_kee", 100);
		set("armor_prop/max_sen", 0);
		set("long","���������ɮ�ӳֹ��Ļ�����ÿ����ĸ����Ϊ��������һö�Ա�ϲ�֡�\n");	// �ѷ���
	}
	::init_neck();
}

// ���p��dancing_faery@hotmail.com


#include <ansi.h>
#include <armor.h>

inherit WRISTS;

void create() {
	set_name(WHT"�ݱ�����"NOR, ({ "wrists"}) );
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("generate_item_common",1);
		set("lore",1);
		set("material", "cloth");
		set("common_only", 1);
		set("value",1200);	// ��value���������ù��������̵ꣻ����������ǰ�ڱ��ܴ����б��档
		set("level_required", 0);
		set("armor_prop/armor", 1);
		set("armor_prop/strength", -10);
		set("armor_prop/intelligence", 0);
		set("armor_prop/composure", -10);
		set("armor_prop/constitutionx", 0);	// �ѷ���
		set("armor_prop/agility", -10);
		set("armor_prop/karma", -10);
		set("armor_prop/max_gin", 0);
		set("armor_prop/max_kee", 100);
		set("armor_prop/max_sen", 0);
		set("long","һ��С�ݱ�͵���������С���ǵ����\n");	// �ѷ���
	}
	::init_wrists();
}

// ���p��dancing_faery@hotmail.com


#include <ansi.h>
#include <armor.h>

inherit BOOTS;

void create() {
	set_name(WHT"�Ʋ���"NOR, ({ "cloud shoes","shoes"}) );
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("material", "cloth");
		set("female_only", 1);
		set("level_required", 120);
		set("armor_prop/armor", 1);
		set("armor_prop/strength", 0);
		set("armor_prop/intelligence", 2);
		set("armor_prop/composure", 8);
		set("armor_prop/constitutionx", 0);	// �ѷ���
		set("armor_prop/agility", 25);
		set("armor_prop/karma", 8);
		set("armor_prop/max_gin", 0);
		set("armor_prop/max_kee", 0);
		set("armor_prop/max_sen", 0);
		set("long","��һ˫Ь��������������Ʋ��ţ�������ȥ�����谭��\n");	// �ѷ���
	}
	::init_boots();
}

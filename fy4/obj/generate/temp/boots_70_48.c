#include <ansi.h>
#include <armor.h>

inherit BOOTS;

void create() {
	set_name(MAG"���Ƿ�ѥ"NOR, ({ "boots"}) );
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("material", "cloth");
		set("male_only", 1);
		set("level_required", 50);
		set("armor_prop/armor", 1);
		set("armor_prop/strength", 0);
		set("armor_prop/intelligence", 0);
		set("armor_prop/composure", 0);
		set("armor_prop/constitutionx", 3);	// �ѷ���
		set("armor_prop/agility", 14);
		set("armor_prop/karma", 0);
		set("armor_prop/max_gin", 0);
		set("armor_prop/max_kee", 0);
		set("armor_prop/max_sen", 80);
		set("long","�Ե����ӳֹ���ѥ�ӣ�����Ч��ߴ����ߵ��ٶȡ�\n");	// �ѷ���
	}
	::init_boots();
}

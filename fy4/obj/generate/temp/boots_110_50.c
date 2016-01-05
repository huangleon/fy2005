#include <ansi.h>
#include <armor.h>

inherit BOOTS;

void create() {
	set_name(YEL"��âѥ"NOR, ({ "boots"}) );
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("material", "cloth");
		set("male_only", 1);
		set("level_required", 90);
		set("armor_prop/armor", 1);
		set("armor_prop/strength", 0);
		set("armor_prop/intelligence", 0);
		set("armor_prop/composure", 0);
		set("armor_prop/constitutionx", 0);	// �ѷ���
		set("armor_prop/agility", 16);
		set("armor_prop/karma", 6);
		set("armor_prop/max_gin", 60);
		set("armor_prop/max_kee", 0);
		set("armor_prop/max_sen", 0);
		set("long","��˵ֻ���������˲��ܴ�����âѥ��\n");	// �ѷ���
	}
	::init_boots();
}

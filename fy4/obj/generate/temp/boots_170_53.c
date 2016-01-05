#include <ansi.h>
#include <armor.h>

inherit BOOTS;

void create() {
	set_name(HIR"����"NOR, ({ "shoes"}) );
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("material", "cloth");
		set("male_only", 1);
		set("level_required", 135);
		set("armor_prop/armor", 1);
		set("armor_prop/strength", 9);
		set("armor_prop/intelligence", 0);
		set("armor_prop/composure", 9);
		set("armor_prop/constitutionx", 0);	// �ѷ���
		set("armor_prop/agility", 21);
		set("armor_prop/karma", 0);
		set("armor_prop/max_gin", 0);
		set("armor_prop/max_kee", 370);
		set("armor_prop/max_sen", 0);
		set("long","��ϡ�е���ɽ�𾧵�ɵ�Ь�ӣ���ֵ���ǡ�\n");	// �ѷ���
	}
	::init_boots();
}

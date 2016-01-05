#include <ansi.h>
#include <armor.h>

inherit BOOTS;

void create() {
	set_name(HIR"Ѫ��Ь"NOR, ({ "shoes"}) );
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("material", "cloth");
		set("female_only", 1);
		set("level_required", 70);
		set("armor_prop/armor", 1);
		set("armor_prop/strength", 5);
		set("armor_prop/intelligence", 0);
		set("armor_prop/composure", 0);
		set("armor_prop/constitutionx", 0);	// �ѷ���
		set("armor_prop/agility", 10);
		set("armor_prop/karma", 3);
		set("armor_prop/max_gin", 0);
		set("armor_prop/max_kee", 0);
		set("armor_prop/max_sen", 0);
		set("long","մѪ�Ĵ�Ь��˵��������Ĳ���֮����\n");	// �ѷ���
	}
	::init_boots();
}

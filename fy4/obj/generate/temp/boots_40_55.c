#include <ansi.h>
#include <armor.h>

inherit BOOTS;

void create() {
	set_name(WHT"����Ь"NOR, ({ "shoes"}) );
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("material", "cloth");
		set("female_only", 1);
		set("level_required", 30);
		set("armor_prop/armor", 1);
		set("armor_prop/strength", 0);
		set("armor_prop/intelligence", 1);
		set("armor_prop/composure", 2);
		set("armor_prop/constitutionx", 0);	// �ѷ���
		set("armor_prop/agility", 5);
		set("armor_prop/karma", 2);
		set("armor_prop/max_gin", 0);
		set("armor_prop/max_kee", 0);
		set("armor_prop/max_sen", 0);
		set("long","��˵������˫Ь���ܱ�������һ�����ݡ�\n");	// �ѷ���
	}
	::init_boots();
}

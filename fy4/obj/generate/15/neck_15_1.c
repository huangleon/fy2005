#include <ansi.h>
#include <armor.h>

inherit NECK;

void create() {
	set_name(MAG"������"NOR, ({ "necklace"}) );
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("material", "cloth");
		set("male_only", 1);
		set("level_required", 10);
		set("armor_prop/armor", 1);
		set("armor_prop/strength", 0);
		set("armor_prop/intelligence", 0);
		set("armor_prop/composure", 1);
		set("armor_prop/constitutionx", 0);	// �ѷ���
		set("armor_prop/agility", 0);
		set("armor_prop/karma", 0);
		set("armor_prop/max_gin", 10);
		set("armor_prop/max_kee", 0);
		set("armor_prop/max_sen", 20);
		set("long","һ����ɫʯ�ӵ�ɵķ��飬�����а��Ķ���֮Ч��\n");	// �ѷ���
	}
	::init_neck();
}

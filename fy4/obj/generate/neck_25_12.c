#include <ansi.h>
#include <armor.h>

inherit NECK;

void create() {
	set_name(YEL"����֮��"NOR, ({ "necklace"}) );
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("generate_item",1);
		set("lore",1);
		set("material", "cloth");
		set("female_only", 1);
		set("level_required", 20);
		set("armor_prop/armor", 2);
		set("armor_prop/strength", 2);
		set("armor_prop/intelligence", 2);
		set("armor_prop/composure", 10);
		set("armor_prop/constitutionx", 1);	// �ѷ���
		set("armor_prop/agility", 2);
		set("armor_prop/karma", 2);
		set("armor_prop/max_gin", 24);
		set("armor_prop/max_kee", 30);
		set("armor_prop/max_sen", 24);
		set("long","û�����ֵ�һ����ʯ������ֵǮ��\n");	// �ѷ���
	}
	::init_neck();
}

// ���p��dancing_faery@hotmail.com


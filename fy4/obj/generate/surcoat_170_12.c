#include <ansi.h>
#include <armor.h>

inherit SURCOAT;

void create() {
	set_name(HIR BLK"��ǳ���"NOR, ({ "robe"}) );
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("generate_item",1);
		set("lore",1);
		set("material", "cloth");
		set("male_only", 1);
		set("level_required", 135);
		set("armor_prop/armor", 20);
		set("armor_prop/strength", 50);
		set("armor_prop/intelligence", 10);
		set("armor_prop/composure", 10);
		set("armor_prop/constitutionx", 0);	// �ѷ���
		set("armor_prop/agility", 10);
		set("armor_prop/karma", 10);
		set("armor_prop/max_gin", 152);
		set("armor_prop/max_kee", 190);
		set("armor_prop/max_sen", 152);
		set("long","����һ�ǵ����û���\n");	// �ѷ���
	}
	::init_surcoat();
}

// ���p��dancing_faery@hotmail.com


#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create() {
	set_name(HIW"��սͷ��"NOR, ({ "helm"}) );
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("generate_item",1);
		set("lore",1);
		set("material", "cloth");
		set("male_only", 1);
		set("level_required", 30);
		set("armor_prop/armor", 6);
		set("armor_prop/strength", 3);
		set("armor_prop/intelligence", 15);
		set("armor_prop/composure", 3);
		set("armor_prop/constitutionx", 2);	// �ѷ���
		set("armor_prop/agility", 3);
		set("armor_prop/karma", 3);
		set("armor_prop/max_gin", 300);
		set("armor_prop/max_kee", 120);
		set("armor_prop/max_sen", 300);
//		set("long","����\n");	// �ѷ���
	}
	::init_head();
}

// ���p��dancing_faery@hotmail.com


#include <ansi.h>
#include <armor.h>

inherit BOOTS;

void create() {
	set_name(HIG"����Ь"NOR, ({ "shoes"}) );
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("generate_item",1);
		set("lore",1);
		set("material", "cloth");
		set("female_only", 1);
		set("level_required", 105);
		set("armor_prop/armor", 8);
		set("armor_prop/strength", 8);
		set("armor_prop/intelligence", 8);
		set("armor_prop/composure", 8);
		set("armor_prop/agility", 40);
		set("armor_prop/karma", 8);
		set("armor_prop/max_gin", 120);
		set("armor_prop/max_kee", 150);
		set("armor_prop/max_sen", 120);
		set("long","��Ь��������Ϊ��˧��֯����֪��ʱ����ʧ���⡣\n");	// �ѷ���
	}
	::init_boots();
}

// ���p��dancing_faery@hotmail.com


#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create() {
	set_name(CYN"�ط���ñ"NOR, ({ "cap"}) );
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value",2000);	// ��value���������ù��������̵ꣻ����������ǰ�ڱ��ܴ����б��档
		set("generate_item_common",1);
		set("lore",1);
		set("material", "cloth");
		set("male_only", 1);
		set("level_required", 12);
		set("armor_prop/armor", 6);
		set("armor_prop/strength", 0);
		set("armor_prop/intelligence", 0);
		set("armor_prop/composure", -5);
		set("armor_prop/constitutionx", 0);	// �ѷ���
		set("armor_prop/agility", 0);
		set("armor_prop/karma", -10);
		set("armor_prop/max_gin", 0);
		set("armor_prop/max_kee", 0);
		set("armor_prop/max_sen", 0);
		set("long","�����ط��ӻ���������ܱ������������˺���\n");	// �ѷ���
	}
	::init_head();
}

// ���p��dancing_faery@hotmail.com


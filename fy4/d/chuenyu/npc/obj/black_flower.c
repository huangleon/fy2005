// pink_cloth.c

#include <armor.h>

inherit HEAD;

void create()
{
	set_name("��ĵ��", ({ "black flower", "flower" }) );
	set_weight(10);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "�������ĺ�ĵ����\n");
		set("unit", "��");
		set("value", 6);
		set("material", "plant");
		set("armor_prop/armor", 0);
		set("wear_msg", "$N����ذ�һ��$n����ͷ�ϡ�\n");
		set("unwield_msg", "$N����ذ�$n��ͷ�ϳ���������\n");
		set("female_only", 1);

	}
	::init_head();
}


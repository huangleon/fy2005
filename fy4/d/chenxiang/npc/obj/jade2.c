// pink_cloth.c

#include <armor.h>

inherit HEAD;

void create()
{
	set_name("����", ({ "jade flower"}) );
	set_weight(1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ���������ε���\n");
		set("unit", "��");
		set("value", 1500);
		set("armor_prop/armor", 0);
		set("wear_msg", "$N����ذ�һ��$n����ͷ�ϡ�\n");
		set("unwield_msg", "$N����ذ�$n��ͷ�ϳ���������\n");


	}
    ::init_head();
}


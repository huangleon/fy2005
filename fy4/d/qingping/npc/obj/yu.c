// pink_cloth.c

#include <armor.h>

inherit HEAD;

void create()
{
	set_name("������", ({ "yu pei"  }) );
	set_weight(10);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "���岻�󵫾�Ө��͸��������һ�����ߴ��š�\n");
		set("unit", "��");
		set("value", 6);
		set("material", "plant");
		set("armor_prop/armor", 0);
		set("wear_msg", "$N��$n�׵��˲����ϡ�\n");
		set("unwield_msg", "$N����ذ�$n�Ӿ���ժ��������\n");
	}
	::init_head();
}


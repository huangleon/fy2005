// jade
#include <ansi.h>
#include <armor.h>

inherit NECK;

void create()
{
	set_name(HIC"����"NOR, ({"jade", "yu pei"}) );
	set_weight(10);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ����Ө��͸�����塣\n");
		set("unit", "��");
		set("value", 500);
		set("wear_msg", "$N����ذ�һ��$n���ھ��ϡ�\n");
		set("unwield_msg", "$N����ذ�$n�Ӿ��ϳ���������\n");
	}
	::init_neck();
}


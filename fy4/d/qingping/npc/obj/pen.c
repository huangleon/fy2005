// sword.c : an example weapon

#include <weapon.h>

inherit SWORD;

void create()
{
	set_name("��", ({ "bi" }) );
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "֧");
		set("long", "����һ֧�����൱��ͨ�ıʣ���ͨ����ڡ�\n");
		set("value", 400);
		set("material", "steel");
	}
	init_sword(25);
}

// Tie@fengyun
#include <weapon.h>

inherit SWORD;

void create()
{
    set_name("��ذ��", ({ "dagger" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ�Ѷ̶�������ذ��\n");
		set("value", 1000);
		set("material", "steel");
		set("wield_msg", "$N���к�Ȼ������һ��ذ�ס�\n");
		set("unwield_msg", "$N�����е�ذ������\n");
	}
	init_sword(30);
}

#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
	set_name("����", ({ "sword" }) );
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�����߳��������������Ǵ�ʲô�ط��ֶ������ġ�\n");
		set("value", 400);
		set("nodrop_weapon",1);
		set("material", "steel");
		set("wield_msg", "$N�ѱ��������$n�γ��������С�\n");
		set("unwield_msg", "$N�����е�$n�������䡣\n");
	}
	init_sword(35);
}

// xiesword.c : master xie's weapon

#include <weapon.h>

inherit SWORD;

void create()
{
	set_name("��ʮ���Ľ�", ({ "yan13-sword" }) );
	set_weight(9000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ����ڵĽ�����ڵĽ����ϣ�����ʮ������Ө�����顣 \n");
		set("value", 4000);
		set("material", "steel");
		set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n��������Ľ��ʡ�\n");
	}
	::init_sword(25);


}

// sword.c

#include <weapon.h>

inherit SWORD;

void create()
{
	set_name("��潣", ({ "sword" }) );
	set_weight(400);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ��רΪ�䵱����ʹ�õı�����\n");
		set("value", 2);
		set("material", "steel");
		set("rigidity", 80);
		set("wield_msg", "$N�ӽ����г��һ�����������$n�������С�\n");
		set("unwield_msg", "$N�����е�$n��������Ľ��ʡ�\n");
	}
	::init_sword(10);
}

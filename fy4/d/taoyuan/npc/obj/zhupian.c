#include <weapon.h>
inherit SWORD;
void create()
{
	set_name("��Ƭ", ({ "zhu pian", "bamboo", "��Ƭ" }) );
	set_weight(400);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 10);
		set("material", "wood");
		set("long", "һ������ɫ����Ƭ��������ϡ����һ��ɽˮͼ��\n");
	    set("wield_msg", "$N�ó�һ������Ƭ�������С�\n");
	    set("unequip_msg", "$N�������е�$n��\n");
	}
	::init_sword(2);
}


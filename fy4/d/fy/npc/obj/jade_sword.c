#include <ansi.h>
#include <weapon.h>

inherit SWORD;
void create()
{
	set_name("����̽�", ({ "jade sword", "sword"}) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 0);
		set("material", "stone");
		set("rigidity", 2000);
		set("long", "һ�ѷǽ������С����͸����ɫ�Ĺ�â��\n");
		set("wield_msg", "$N���һ��$n���������С�\n");
		set("unequip_msg", "$N�������е�$n��\n");
	}
	::init_sword(10);
}


#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void create()
{
	set_name( "������", ({ "sword" }) );
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ������ɫ�ĵĳ�����������Լ��ʮ�������ҡ�\n");
		set("value", 2000);
		set("material", "crimsonsteel");
		set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
		set("unequip_msg", "$N�����е�$n���뱳��Ľ��ʡ�\n");
		}
	::init_sword(10);
}

// echowhip.c

#include <ansi.h>
#include <weapon.h>
inherit WHIP;

void create()
{
	set_name(BLK"�ڱ�"NOR, ({ "black whip", "whip" }) );
	set_weight(17000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 100);
		set("material", "leather");
		set("level_required",40);
		set("rigidity", 70);
		set("wield_msg", "$N���������һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n�������䡣\n");
	}
	init_whip(55);
}

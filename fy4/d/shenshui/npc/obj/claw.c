//  An example non-weapon type of weapon
#include <ansi.h>
#include <weapon.h>
inherit RING;
void create()
{
	set_name(WHT"�����̵Ĵ���"NOR, ({ "claw", "hand" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "ֻ");
		set("long", "һֻ������׵�ǧ���������Ͽ��µĴ��֣�����������ϸС�����̡�\n");
        	set("lore",1);
		set("value", 1);
		set("experience",3000000);
		set("material", "steel");
	}
    	init_ring(25);
	set("wield_msg", "$N�ӻ�������һ��$n�������ϡ�\n");
	set("unwield_msg", "$N�����ϵ�$n���������뻳�С�\n");
       
}

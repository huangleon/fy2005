#include <ansi.h>
#include <weapon.h>
inherit WHIP;

void create() {
	set_name( WHT"ѩ����"NOR, ({ "whip" }) );
	set_weight(500);
	if(clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 1000);
		set("long","һ��ɢ���������â�ı��ӡ�\n");
		set("material", "skin");        
		set("wield_msg", "$N����������һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n�������䡣\n");
	}
	::init_whip(20);
}


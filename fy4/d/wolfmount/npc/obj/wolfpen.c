#include <weapon.h>
#include <ansi.h>
inherit STAFF;
void create()
{
	set_name(WHT"�Ǻ���"NOR, ({ "wolf pen" }) );
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "֧");
		set("jungle",1);
		set("material", "iron");
		set("value", 600);
		set("long", "����һ��������ϸ���Ǻ�ë�ʡ�\n");
		set("wield_msg", "$N�ó�һ֧$n�������С�\n");
		set("unequip_msg", "$N�����е�$n���뻳�С�\n");
	}
	::init_staff(2);
}

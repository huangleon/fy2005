#include <ansi.h>
#include <weapon.h>
inherit AXE;

void create()
{
	set_name(HIY"�̹ſ��츫"NOR, ({ "pangu axe", "axe" }) );
	set_weight(100000);
	if( clonep() )
		set_default_object(__FILE__);
	else 
	{
		set("unit", "��");
		set("long", CYN"\nһ�Ѿ޴��ʯ�����������ž���ɽ�������´�ӣ��ݴ������̹�\n����ٵ����µ��񸫣����о���أ�������֮������\n"NOR);
		set("value", 0);
		set("material", "stone");
		set("wield_msg", "$N����ǧ�����������һ��������߬��$n��\n");
		set("unwield_msg", "$N�����е�$n���ڼ��ϡ�\n");
		set("level_required",130);
	}
	init_axe(130);
}
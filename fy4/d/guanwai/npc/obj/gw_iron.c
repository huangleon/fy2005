#include <weapon.h>
#include <ansi.h>
inherit DAGGER;
void create()
{
	set_name(BLU "��ɽ������"NOR, ({ "rare iron" }) );
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ����ڱ������ɽ�����������ķ������⡣\n");
		set("value", 2000000);
		set("rigidity",2000);	
		set("material", "steel");
		set("max_enchant",6);
		set("for_create_weapon",1);
		set("base_damage",25);
	set("wield_msg", "$N�ӻ�������һ��$n�������С�\n");
	set("unwield_msg", "$N�����е�$n���뻳�С�\n");
	}
	::init_dagger(25);
}

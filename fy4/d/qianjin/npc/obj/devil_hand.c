//  An example non-weapon type of weapon
#include <ansi.h>
#include <weapon.h>
inherit RING;
void create()
{
	set_name(HIB"��ħ��"NOR, ({ "devil hand", "hand" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "ֻ");
		set("long", "һֻ����ɫ�����ף����������������һЩ���֡������׵����ӹ��죬\nҲʵ�������ж���ʲô���ʣ�͸��һ��������״��а����\n");
		set("value", 50);
		set("material", "steel");
	}
	init_ring(5);

	set("wield_msg", "$N�ӻ�������һ��$n�������ϡ�\n");
	set("unwield_msg", "$N�����ϵ�$n���������뻳�С�\n");


}

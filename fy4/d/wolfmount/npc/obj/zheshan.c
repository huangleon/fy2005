#include <weapon.h>
#include <ansi.h>
inherit BLADE;

void create()
{
	set_name( "��ߡ��" , ({ "zheshan" }) );
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�ѿ����൱���µ�ߡ�ȣ���Ʈɢ����ζ��\n");
		set("value", 400);
		set("material", "steel");
		set("wield_msg", "$N��ৡ���һ����$nչ�����������������¡�\n");
		set("unwield_msg", "$N�����е�$n�����������С�\n");
	}
	::init_blade(10);
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	int dam;
    if (userp(me))	return;
    dam = (int) me->query("max_kee");
    victim->receive_damage("kee",dam/10);
	return BLU "��ߡ����ͻȻ���һ�ɻ��̣�$n⧲�������������ס��\n"NOR;
	tell_object(me,"\n��ͻȻ����һ��ѣ�Σ��������˶���\n\n");
}

#include <ansi.h>
#include <weapon.h>
inherit HAMMER;

void create()
{
	set_name(HIG"������"NOR, ({ "cactus" }) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ�곤��ʮ�ֿɰ��������ƣ�������Щ����Ĵ��롣\n");
		set("value", 10);
        set("material", "wood");
        set("wield_msg", "$N����һ��$n��������ʹ�á�\n");
        set("unwield_msg", "$N�������е�$n��\n");
		set("count",2);
    }
    ::init_hammer(30);
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	if (!query("count")) return 0;
	add("count",-1);
	victim->receive_wound("kee", damage_bonus,me);
	if (query("count"))
		return HIG "�������ϵĴ���������$n��Ƥ����ʹ��$n֨�۴�С�\n"NOR;
	else
		return HIG "�������ϵ����һЩ����������$n��Ƥ����ʹ��$n֨�۴�С�\n"NOR;
}

/*

���������������X�Y
���������������U�t�r
���������������U���t�r
���������������U�����t�r
���������������U��������
���������������^�k�k�k�_

��������������- FengYun - ������
������������annie 08.2003
������dancing_faery@hotmail.com
*/


#include <weapon.h>
#include <ansi.h>

inherit BLADE;

void create()
{
    	set_name(HIW"���Ǻ��⵶"NOR, ({ "ice blade","blade" }) );
		set_weight(7000);
		if( clonep() )
		set_default_object(__FILE__);
		else {
		set("unit", "��");
        set("long", "���Ǻ��⵶,ÿһ������,���Ǳ�֮�ꡢѩ֮�ǡ�˪֮�顢��֮����\n");
        set("value", 900);
        set("level_required",100);
		set("material", "steel");
		set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n��������ĵ��ʡ�\n");
	}
    	init_blade(70);
}

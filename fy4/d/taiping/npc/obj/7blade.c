#include <ansi.h>
#include <weapon.h>

inherit BLADE;

void create()
{
	set_name(HIG"���Ǳ���"NOR, ({ "blade" }) );
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
        	set("value", 500);
		set("class","bat");
	     	set("level_required",105);
		set("material", "iron");
        	set("long", "���Ǻ�����������ʱɱ��Խ�����õı�����\n");
		set("wield_msg", "$N���һ�����λε�$n�������С�\n");
		set("unequip_msg", "$N�����е�$n��������ĵ��ʡ�\n");
	}
    init_blade(80);
}

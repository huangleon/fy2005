
#include <ansi.h>
#include <weapon.h>

inherit STICK;

void create()
{
        set_name(HIG"�򹷹�"NOR , ({ "doggie stick", "stick" }) );
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        set("unit", "��");
        set("long", GRN"һ�������ͣ���Ө��͸�������\n"NOR);
        set("value", 1);
		set("no_give", 1);
		set("class","beggar");
		set("experience",3000000);
		set("material", "wood");
        	set("wield_msg", "$N���һ��$n�����������С�\n");
		set("unwield_msg", "$N�������е�$n��\n");
	}
//	ITEM_D->setup_unique(this_object());  
    ::init_stick(35);
}

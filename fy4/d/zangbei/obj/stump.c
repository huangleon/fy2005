#include <weapon.h>
#include <ansi.h>

inherit HAMMER;

void create()
{
        set_name("������", ({ "stump"}) );
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "�ִ��ִ����ص���������\n");
                set("unit", "��");
                set("value", 1);
                set("weight",40000);
                set("material", "plant");
                set("wield_msg", "$N�����ؾ���һ��$n���ڼ��ϡ�\n");
                set("unwield_msg", "$N��$n����������\n");
		
        }
        	::init_hammer();

}



// rope.c

#include <ansi.h>
#include <weapon.h>

inherit WHIP;

void create()
{
        set_name( "��β��", ({ "whip" }) );
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
        set("long", "�ر߳��õ�����޸��ƶ��ɣ���ţƤ�Ƴɣ������쳣��\n");
                set("value", 500000);
                set("material", "skin");
        }
        ::init_whip(25);

        set("wield_msg", "$N����������һ��$n�������С�\n");
        set("unwield_msg", "$N�����е�$n�������䡣\n");

}


#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void create()
{
        set_name( "����", ({ "wuqi" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long","һ�Ѻ��������ϸϸ�����������ǻ�״��\n");
                set("value", 1);
                set("material", "woord");     
                set("timbre",20);
        }
        ::init_sword(1);
}



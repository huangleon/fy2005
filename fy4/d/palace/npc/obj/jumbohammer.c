// hammer.c

#include <weapon.h>

inherit HAMMER;
#include <ansi.h>
void create()
{
        set_name(HIG"���촸"NOR, ({ "jumbohammer" }) );
        set_weight(200000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�����صĻ��촸��������൱��ʵ��\n");
                set("value", 300);
                set("material", "iron");
                set("wield_msg", "$N�ó�һ˫$n��������������Ȼ���������С�\n");
                set("unwield_msg", "$N�������е�$n��\n");
        }

        init_hammer(60);
}

// hammer.c

#include <weapon.h>

inherit HAMMER;

void create()
{
    set_name("��ʯ��", ({ "stone hammer","hammer" }) );
    set_weight(50000);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit", "��");
        set("long", "����һ���ٰ�ʮ��Ĵ�ʯ����\n");
        set("value", 1000);
        set("material", "stone");
        set("wield_msg", "$N��������������һ��$n�������С�\n");
        set("unwield_msg", "$N�������е�$n��\n");
    }
    
    ::init_hammer(20);
}

// sixhammer.c
#include <ansi.h>
#include <weapon.h>

inherit AXE;

void create()
{
        set_name("��ͷ��", ({ "axe" }) );
        set_weight(6000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����ɳ���Ͻ�ʿ���õķ�ͷ����\n");
                set("value", 1);
                set("material", "iron");
                set("wield_msg", "$N�ӱ�����$n��������������Ȼ���������С�\n");
                set("unwield_msg", "$N�������е�$n��\n");
        }

        init_axe(4);
}

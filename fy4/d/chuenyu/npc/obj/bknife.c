// knife.c

#include <weapon.h>

inherit DAGGER;

void create()
{
        set_name("����", ({ "knife" }) );
        set_weight(6500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�ѵ����ż�����������ʱ���ϴ͵ı���\n");
                set("value", 200);
                set("material", "crimsonsteel");
        set("wield_msg", "$N��������һ����������$n�������С�\n");
        set("unwield_msg", "$N�����е�$n�������䡣\n");
        }

        ::init_dagger(15);


}


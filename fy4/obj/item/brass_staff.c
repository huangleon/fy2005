// brass_staff.c

#include <weapon.h>

inherit STAFF;

void create()
{
        set_name("��ͭ����", ({ "brass staff", "staff" }) );
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ���ִ��ֳ����ǳ����صĻ�ͭ���ȣ�������������ͭ����\n");
                set("value", 1200);
                set("material", "brass");
                set("wield_msg", "$N�ó�һ������Ȼ��$n�������С�\n");
                set("unwield_msg", "$N�������е�$n��\n");
        }

        ::init_staff(34);
}

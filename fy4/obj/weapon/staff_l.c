// staff.c : Gun zi

#include <weapon.h>

inherit STAFF;

void create()
{
        set_name("��ͭ��", ({ "staff" }) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ��ɳ�������õ���ͭ����\n");
                set("value", 1);
                set("material", "copper");
        }
        init_staff(2);
}

// throwing_knife.c

#include <weapon.h>

inherit THROWING;

void create()
{
        set_name("�ɵ�", ({ "throwing knife", "knife" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "Щ");
                set("base_unit", "��");
                set("base_weight", 200);
                set("base_value", 40);
                set("material", "iron");
                set("long",     "һ�ѱ����ĵ�Ƭ�����Ĵ���֣���������Ǯ��\n");
                set("volumn",50);
        }
        set_amount(50);
        init_throwing(25);
        setup();
}

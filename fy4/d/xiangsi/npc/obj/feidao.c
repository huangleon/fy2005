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
                set("base_weight", 69);
                set("base_value", 0);
                set("material", "iron");
                set("long",     "һ�ѱ����ĵ�Ƭ�����Ĵ���֣���������Ǯ��\n");
                set("volumn",50);
        }
        set_amount(500);
		::init_throwing(17);
}


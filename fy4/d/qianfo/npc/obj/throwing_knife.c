// throwing_knife.c

#include <weapon.h>

inherit THROWING;

void create()
{
        set_name("���ַɵ�", ({ "throwing knife", "knife" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "Щ");
                set("base_unit", "��");
                set("base_weight", 300);
                set("base_value", 0);
                set("material", "iron");
                set("long",     "�ɵ���һ��ʮ���ᡢ������ذ�ף�������������ʹ�á�\n");
        }
        set_amount(20);
        ::init_throwing(20);
}

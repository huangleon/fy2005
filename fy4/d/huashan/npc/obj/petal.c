#include <weapon.h>
inherit THROWING;

void create()
{
    set_name("�һ���", ({ "petal" , "�һ���"}) );
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit", "��");
        set("long", "�ۺ�ɫ���һ����ϻ����ż���¶�顣\n");
        set("base_unit", "Ƭ");
        set("base_value", 1);
        set("base_weight", 1);
        set("marks/deerfood", 1);
    }
    set_amount(1);
    ::init_throwing(2);
}



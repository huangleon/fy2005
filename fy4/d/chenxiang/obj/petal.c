#include <weapon.h>
#include <ansi.h>
inherit THROWING;

void create()
{
    set_name(MAG"��Ѫ�����ٻ����"NOR, ({ "blood petal" , "petal"}) );
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit", "��");
        set("long", "һ����Ѫ���������ٻ��������. \n");
        set("base_unit", "��");
        set("base_value", 1);
        set("base_weight", 1);
    }
    set_amount(1);
    ::init_throwing(2);
}
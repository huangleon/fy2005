#include <weapon.h>
inherit HAMMER;
void create()
{
    set_name("����", ({ "tiger bone","bone" }) );
    set_weight(15000);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit", "��");
    set("long", "���Ǿ��ϻ��ĺ��ǣ������ƴ�������ͷ˶����ͭ��һ�㡣\n");
        set("value", 3);
        set("material", "iron");
    }
    ::init_hammer(10);
}

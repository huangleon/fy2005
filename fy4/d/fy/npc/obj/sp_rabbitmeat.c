#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("��������", ({ "fried rabbit meat","meat"}) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ�鿾�ƺõ�������ļ����⡣\n");
                set("value", 1000);
        }
        ::init_item();
}

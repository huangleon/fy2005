// tblade.c
#include <ansi.h>
#include <weapon.h>
inherit AXE;
void create()
{
    set_name(HIR"�����޸�"NOR, ({ "axe" }) );
    set_weight(20000);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit", "��");
        set("long",
    
    "һ������޴�ĸ�ͷ��\n"
    );
        set("value", 0);
        set("material", "steel");
        set("rigidity", 2000);
        
    }

        ::init_axe(30);
}
 

#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("��ʯ", ({ "jade" }) );
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
            	set("unit", "��");
            	set("for_create_ring",1);
               	set("material", "jade");
            	set("long","һ������ĵ���ʯ���Ǵ�������ĺò��ϡ�\n");
    		set("riddle_award",1);
    		set("value",20);
        }
        ::init_item();
}

#include <ansi.h>
inherit ITEM;

void create()
{
    	int	i;
        set_name(HIW"������"NOR, ({ "pearl"}) );
    	set("unit", "��");
    	set_weight(200);
    	set("value",1000000);
    	set("lore",1);
    	set("long", "һ����׹�Բ�Ĵ����飬��ֵ���ǡ�\n");
                                            
   	::init_item();
}

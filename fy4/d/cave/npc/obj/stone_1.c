inherit ITEM;
#include <ansi.h>

void create()
{
    	int	i;

    	string *names = ({
        	HIY"��ˮ��"NOR ,HIG"��ˮ��"NOR ,
    	});
	
	string *ids = ({"yellow crystal", "green crystal",});
	
    	i = random(2);
    	set_name(names[i], ({ ids[i],"crystal",}) );
    	set_weight(100);
	set("unit", "��");
        set("long", "һ��ɢ��������Ө���ˮ��ʯ��\n");
        set("value", 200);
        set("lore",1);
	::init_item();
}
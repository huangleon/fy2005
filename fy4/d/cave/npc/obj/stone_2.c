inherit ITEM;
#include <ansi.h>

void create()
{
    	int	i;

    	string *names = ({
        	HIR"��ˮ��"NOR ,HIB"��ˮ��"NOR,
    	});
	
	string *ids = ({"red crystal","blue crystal",});
	
    	i = random(2);
    	set_name(names[i], ({ ids[i],"crystal",}) );
    	set_weight(100);
	set("unit", "��");
        set("long", "һ��ɢ��������Ө���ˮ��ʯ��\n");
        set("value", 500);
        set("lore",1);
	::init_item();
}
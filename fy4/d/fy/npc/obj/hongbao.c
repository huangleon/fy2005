inherit ITEM;
#include <ansi.h>
void create()
{
    int i;
    string *names = ({
        	RED"���ŷ�"NOR,	WHT"���ŷ�"NOR,	BLU"���ŷ�"NOR,	YEL"���ŷ�"NOR,
    });
	
    	i = random(4);
    	set_name( names[i], ({ "envelope" }));
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ���ʨ�ھ���ͷ�ļ��š�\n");
		set("value", 1000);
	}
}




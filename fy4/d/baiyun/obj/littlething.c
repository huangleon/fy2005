// book.c

#include <ansi.h>
inherit ITEM;

void create()
{
    int	i;

   string *names = ({
        WHT"����"NOR,YEL"����"NOR, BLU"����"NOR,RED"ɺ��"NOR,
        MAG"С�з"NOR
    });

    i = random(5);
    set_name( names[i], ({ "littlething" }));
    set("unit", "��");
    set_weight(200);
	set("value",0);
    set("long", "�����ں��߲����ҵ���С���⡣\n");                            
	::init_item();
}

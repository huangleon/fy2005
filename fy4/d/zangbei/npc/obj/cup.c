inherit ITEM;
#include <ansi.h>
inherit F_LIQUID;
void create()
{
    	set_name(HIB "волы╠╜" NOR,({"cup"}));
    	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        set("long", "р╩╦Жволы╬ф╠╜║ё\n");
		set("unit", "╦Ж");
        	set("value", 0);
        	set("max_liquid", 10);
	}
	set("liquid", ([
        	"type": "alcohol",
        	"name": "фоля╬ф",
		"remaining": 5,
        	"drunk_apply": 20,
	]) );
}

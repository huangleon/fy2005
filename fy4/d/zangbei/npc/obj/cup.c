inherit ITEM;
#include <ansi.h>
inherit F_LIQUID;
void create()
{
    	set_name(HIB "���ٱ�" NOR,({"cup"}));
    	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        set("long", "һ�����پƱ���\n");
		set("unit", "��");
        	set("value", 0);
        	set("max_liquid", 10);
	}
	set("liquid", ([
        	"type": "alcohol",
        	"name": "���Ѿ�",
		"remaining": 5,
        	"drunk_apply": 20,
	]) );
}

// icy_band.c

#include <ansi.h>
#include <armor.h>

inherit NECK;

void create()
{
    set_name(  "�ʽ�" , ({ "color ribbon", "ribbon" }) );
    set_weight(20);
    if( clonep() )
	set_default_object(__FILE__);
    else {
	set("unit", "��");
	//  set("value", 400);
	set("material", "cloth");
    }
    ::init_neck();
}

// icy_girth.c

#include <ansi.h>
#include <armor.h>

inherit WAIST;

void create()
{
    set_name(  "�ʴ�" , ({ "color girth", "girth" }) );
    set_weight(60);
    if( clonep() )
	set_default_object(__FILE__);
    else {
	set("unit", "��");
	//  set("value", 7000);
	set("material", "cloth");
	set("female_only", 1);
    }
    ::init_waist();
}

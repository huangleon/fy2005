// maple_leaf
#include <ansi.h>
inherit ITEM;
void create()
{
	set_name("С����", ({ "small flag", "flag" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",	"һ�澫�µ�С���죬��װ׻������š��������ס��ĸ����֡�\n");
		set("unit", "��");
		set("weight",50);
		set("value", 100);
	}
	::init_item();
}

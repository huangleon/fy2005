#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIY"СҰ��"NOR, ({"daisy", "ye ju"}) );
	set_weight(20);
	if( clonep() )
  	  set_default_object(__FILE__);
	else {
	    set("unit", "��");
	    set("long", "һ���ۻ�ɫ��СҰ�գ�ɢ�������ŵ�������\n");
	    set("value", 10);
	}
	::init_item();
}




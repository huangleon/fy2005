#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIW"�׾�˿����"NOR, ({"handkerchief", "luo pa"}) );
	set_weight(20);
	if( clonep() )
  	  set_default_object(__FILE__);
	else {
	    set("unit", "��");
	    set("long", "һ����ɫ��˿�����������һ������һ��ɰ��İ�ɫС�ջ���\n");
	    set("value", 100);
	}
	::init_item();
}




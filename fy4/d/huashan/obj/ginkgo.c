#include <ansi.h>
inherit ITEM;

void create()
{
	set_name("�׹�", ({"baiguo"}) );
	set_weight(5);
	if( clonep() )
  	  set_default_object(__FILE__);
	else {
	    set("unit", "��");
	    set("long", "һ����ɫ���ż�Ӳ��ǵĹ�ʵ��\n");
	    set("value", 10);
	}
	::init_item();
}




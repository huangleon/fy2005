inherit ITEM;
#include <ansi.h>
void create()
{
  set_name("��֦һҶ��",({ "flower" }) );
  if( clonep() )
                set_default_object(__FILE__);
        else {
	  	  	set("wanchunliu",1);
	  	  	set("value",10);
	  	  	set("no_drop",1);
	  		set("unit","��");
	  		set("long", "һ�俴��ȥʮ����ͨ��Ұ����ɢ�����������ζ��\n");
       	}
}

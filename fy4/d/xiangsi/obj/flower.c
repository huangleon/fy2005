#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(WHT"��ɽǧ��"NOR, ({"flower"}) );
	set_weight(20);
	if( clonep() )
  	  set_default_object(__FILE__);
	else {
	    set("unit", "��");
	    set("long", "��仨ֻ��Ĵָ��С����׵Ļ����д��ż���ǳǳ�����ƣ�
Ψ���紺�ļ����²��л��������\n");
	    set("value", 100);
	}
	::init_item();
}




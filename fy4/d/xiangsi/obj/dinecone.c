#include <ansi.h>
inherit ITEM;

void create()
{
	set_name("�ɹ�", ({"pinecone"}) );
	set_weight(20);
	if( clonep() )
  	  set_default_object(__FILE__);
	else {
	    set("unit", "ö");
	    set("long", "һöСС�ġ������ɹ���\n");
	    set("value", 100);
	}
	::init_item();
}


/*
�X[ ��- FengYun -�� ]���������[
��[dancing_faery@hotmail.com]�������[
��[ ��annie 09.2003�� ]�������a    ��
��[ ������������¶������ʱ������˪ ��
�^��������������������������������-�a
*/

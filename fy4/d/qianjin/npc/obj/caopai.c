
inherit ITEM;
#include <ansi.h>
void create()
{
	set_name("�����", ({ "caoyu" , "���"}) );
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ����赣�������˸����ݣ��֣�
������Щ��ֵĻ��ƣ���ֻ����һ����赣����Ѿ��е�һ�������������
��赲�ʱ��������ɫ�Ĺ�ã��\n");
		set("value", 1);
	}
}




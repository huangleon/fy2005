#include <ansi.h>
inherit ITEM;
void create()
{
	set_name("ʬ��", ({ "corpse"}) );
	set("no_get", 1);
	set_weight(1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "���Ÿ����𳤵���ϼɽ�μ���Ѫƽ�ܴ����޲��ǰ�����һ�ľ�Ӣ��\n���ǵ���ѧ�����ڽ�����ͨ���������˼���\nȻ�������Ѿ����ˣ�ֻʣ��һ��ʬ�徲�����������\n������ò��... ���Ѿ����ˣ�����ʲô�ÿ��ģ�\n\n");
		set("unit", "��");
		set("value", 0);
	}
	::init_item();
}



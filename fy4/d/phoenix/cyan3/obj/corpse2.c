#include <ansi.h>
inherit ITEM;
void create()
{
	set_name("����ֱԭ��ʬ��", ({ "corpse"}) );
	set("no_get", 1);
	set_weight(1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "����ֱԭ (Samurai)\nȻ�������Ѿ����ˣ�ֻʣ��һ��ʬ�徲�����������\n������ò��... ���Ѿ����ˣ�����ʲô�ÿ��ģ�\n\n");
		set("unit", "��");
		set("value", 0);
	}
	::init_item();
}



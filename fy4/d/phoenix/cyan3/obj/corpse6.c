#include <ansi.h>
inherit ITEM;
void create()
{
	set_name("���õ���ʬ", ({ "corpse"}) );
	set("no_get", 1);
	set_weight(1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "���ʬ����Ȼ�Ѿ�����������һ��ʱ���ˣ���ɢ����һ�ɸ�ʬ��ζ����\n������ò��... ���Ѿ����ˣ�����ʲô�ÿ��ģ�\n\n");
		set("unit", "��");
		set("value", 0);
	}
	::init_item();
}



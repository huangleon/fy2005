// maple_leaf

#include <weapon.h>
#include <ansi.h>

inherit ITEM;


void create()
{
	set_name(HIR"��Ҷ"NOR, ({ "maple leaf", "leaf" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
	set("no_split",1);
		set("long",	"һƬѤ���ķ�Ҷ�������м��о���Ŀ��顣\n
����˪������ 
������������Զ�� 
������ҹ�ﳤ��ʱ�̡� 
������һ���Ҷ�� 
����Ʈ��Ϫͷ���ݰ��� 
�����������Цǳ��

���������������� 
�����ǹ߾����� 
�����ܰ���˼����Ⱦ�� 
�����Ǻӵ������ɢ���� 
�����������޴�ǲ˫�㡣 
�����Ҽ����岨�� 
�����������顣 
\n");
		set("unit", "Ƭ");
		set("weight",1);
	}
	set("castable",1);
	::init_item();
}

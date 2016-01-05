#include <ansi.h>
#include <condition.h>
inherit ITEM;

void create()
{
    set_name(HIG "�����" NOR,({"wine-hulu"}));
	set_weight(1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("material", "wood");
		set("long",
            GRN"һ������ɫ�ľƺ�«������֮�з�����͵Ĺ��Σ�����ʢ���˺���ơ�\n"NOR);
		}
    ::init_item();
}

void init()
{
	if(this_player()==environment())
	add_action("do_drink","drink");
}

int do_drink(string arg)
{
	object me;
	me = this_player();
	if (!arg)
		return notify_fail("��Ҫ��ʲô��\n");
    if (arg != "wine-hulu")
		return notify_fail("��Ҫ��ʲô��\n");
	if (query("used")) 
		return notify_fail(this_object()->name()+"�Ѿ����ȹ��ˡ�\n");
    message_vision(HIC"$N�������ƣ���ཹ�ཱི�������......\n"NOR,me);
	me->clear_condition_type(LOW_POISON);
    message_vision(HIW"\nͻȻ$N���ø���һ�ȣ�����һ�ſڣ�һ�������ƵľƼ��������......\n$N������ĺ���磬���������ޱȡ�\n\n"NOR,me);
	set("used",1);
	return 1;
}

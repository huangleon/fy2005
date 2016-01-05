#include <ansi.h>
inherit ITEM;
void create()
{
	set_name("����ɽ���ϵĻ���", ({ "bamboo stick","stick"}) );
	set("no_get", 1);
	set_weight(1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ������̧������ɽ·�Ļ��ͣ����˾��ȵ���������һͷ\n�����ڼ�Ӳ��ɽ������������������(pull)һ������\n");
		set("unit", "��");
		set("value", 0);
	}
	::init_item();
}



void init()
{
	add_action("do_pull","pull");
}

int do_pull(string arg)
{
	object bamboo,me = this_player();
	string msg;
	if (!arg)
		return notify_fail("��Ҫ��ʲô��\n");
	if (!bamboo = present(arg,environment()))
		return notify_fail("��Ҫ��ʲô��\n");
	if (bamboo != this_object())
		return notify_fail("��Ҫ��ʲô��\n");
	if (me->is_busy())
		return notify_fail("��������æ��\n");
	me->perform_busy(3);
	message_vision(CYN"$N˫����ס���ͣ��ŵ�ʯ�ڣ���ȵ�����\n"NOR,me);
	msg="�����ƺ���������һ�㣮����";
	if (me->query_str() < 30)
		msg="���ǻ��Ͷ�Ҳ�������ߵ�$N����ͨ�졣";
	if (me->query_str() < 50)
		msg="��������ҡ���������ָֻ�ԭ״���ߵ�$N����ͨ�졣";
	if (me->query_str() < 70)
		msg="�����ƺ��е���ɶ��ļ��󣬵�$N��������Ȼ���ǲ�����";
	if (me->query("force") < 100)
		msg="����$N��Ȼ�Ѿ���ƣ�����ˣ�����û��һ���ɶ��ĺۼ���";
	message_vision(CYN+msg+"\n"NOR,me);
	me->add("force",-me->query("force") / 3);
	if (me->query("force") < 0) me->set("force",0);
	return 1;
}
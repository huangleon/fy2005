#include <ansi.h>
#include <combat.h>
inherit WALL;

void create()
{
	set_name("�Ŷ��׻�", ({ "launch mechanism","mechanism" }) );
	set("race","Ԫ��");
	set("long","\n�������������ڻ�������֮ѧ�϶���������ʮ����ǰ��������Ϊ��͢��
���������֮ͼ������ٱ�����������֮���л��˺��˶�ʮ�������
������������������񣬳�͢�ཫ�䲼����ÿһ��Ҫ���ذ�����������
������������������������Ӵ���������䣬����������ǰ�ı��ǲt
��̨�ϴ����ǣ�������\n"CYN"������ðڷ���һ�ߵ�ľ��������������(repair)\n"NOR);
	set("combat_exp",100000);
	set("no_fly",1);
	set("no_curse",1);
	set("no_arrest",1);

	set("no_heal",1);

	setup();
}

// ajouter une fonction de "r��paration"


void init()
{
	add_action("do_start","repair");
}

int do_start()
{
	object me = this_player();
	if (me->is_busy())
		return notify_fail("��������æ����\n");
	if (query("repairing"))
		return notify_fail("������������Ŷ��׻���\n");
	if (query("max_kee") == query("kee"))
		return notify_fail("�Ŷ��׻���û���ܵ��κ��𺦡�\n");
	set("repairing",1);
	me->perform_busy(10);	// 20 sec: kee + 5%
	message_vision(HIY"\n$N���ұܵ�һ�ߣ�������ʼ����Ŷ��׻�������\n\n"NOR,me);
	call_out("r2",20,me);
	return 1;
}

void r2(object me)
{
	set("repairing",0);
	if (!me)
		return;
	if (environment(me) != environment())
		return;
	receive_fulling("kee",query("max_kee")/20);
	message_vision(HIY"\n$N�޺��˾Ŷ��׻���ĨĨ��վ�����ӡ�\n\n"NOR,me);
		return;

}




// ajouter une fonction de "broken"->la mission a ��chou��
void die()
{
	object me = this_object();
	tell_room(environment(this_object()),HIR"\n�����Ѫ�����죬һ������ڻ��������������ϣ�����\n"HIW"\n������ϼ�ذ���ʧ�أ������º����˺�������ֱ�룬������ɱ����ԭ���һʱ��\n������Ұ�����������ʮ���������ʧ����������Ǩ������"HIY"\n\n���ź�������ʧ���ˡ�\n\n"NOR);
	environment(this_object())->failed();
	// not real die..
//	::die();
}




/*
�X[ ��- FengYun -�� ]���������[
��[dancing_faery@hotmail.com]�������[
��[ ��annie 09.2003�� ]�������a    ��
��[ ������������¶������ʱ������˪ ��
�^��������������������������������-�a
*/

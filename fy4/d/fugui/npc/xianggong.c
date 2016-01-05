#include <ansi.h>
#define GOLD_COST 50
inherit NPC;

void create()
{
	set_name("�����๫", ({ "playman" }) );
	set("title", HIM "��������"NOR);
	set("gender", "����" );
	set("age", 22);
	set("per", 30);
	set("long", @LONG
���۶�ô�ܸɵĽ���Ů�ӣ�������Ҫ���˵�ʱ���������봫�ڽӴ�
����������һ�²�ͬ���ܵ�Ů�ˡ���������Ȥ�Ļ����루����������
LONG
);
	set("combat_exp", 10000);
	set("no_arrest",1);
	set("attitude", "friendly");

	setup();
	carry_object(__DIR__"obj/cyan_cloth")->wear();
}

int accept_fight(object me)
{
	command("say С�����������Ķ��֣�");
	return 0;
}

int accept_object(object me, object obj)
{
        command("smile");
        command("say ��л��λ" + RANK_D->query_respect(me) +
"����һ�����������Ŀ��ĵģ�");
}

void init()
{
        ::init();
	add_action("do_enjoy","enjoy");
	
}

int do_enjoy()
{
	object me,gold;
	me = this_player();
	gold = present("gold_money", me);
	if( (string)me->query("gender") == "����" )
		return notify_fail("�����๫��æ�ܵ�һ�ԣ��������ϵ������»������𣬲����пͣ�\n");
        if(!gold) 
        	return notify_fail("������û�н��ӣ�����氡��\n");
        if((int) gold->query_amount() < GOLD_COST)
        	return notify_fail("������û��"+chinese_number(GOLD_COST)+"�����ӣ��ܹ����������ɡ�\n");
	message_vision(HIM"$N��ƮƮ����$n�߹�����Ϊ$n���½��������
һ�������ĸо���$n�������ԣ�����Ƿǣ�\n\n"NOR,this_object(),me);
	call_out("enjoyit",20,me);
	return 1;
}

void enjoyit(object me)
{
	if (living(this_object()) && environment(me) == environment())
	{
		message_vision(HIR"���ţ�ม���������������ѽ����$N���޹˼ɵĽ�����������ƽ̹��С��������
�޳������ȣ�������������ȫ��¶�ţ�������\n\n"NOR,me);
		call_out("finishit",20,me);      
	}
	else
		remove_call_out("enjoyit");
}	

void finishit(object me)
{
	object *inv;
	int i;
	if (living(this_object()) && environment(me) == environment())
	{
		message_vision(HIY"$N�������о����ڷɣ�����ͻȻ��
$N����~~����~~����~~����~~����һ��һ���˷ܵļ�����������Ż�����ȥ��������\n"NOR,me);
     		me->change_condition_duration("hehe");
     		me->unconcious();
   	} 	else
		remove_call_out("finishit");
}


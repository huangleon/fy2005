#include <ansi.h>
inherit NPC;

void create()
{
	set_name("С�Һ�", ({ "xiao taohong","taohong" }) );
	set("title", HIR "�������һ����"NOR);
	set("gender", "Ů��" );
	set("age", 22);
	set("str", 10);
	set("per", 30);
    	set("long", 
    "һ���ޱ����������޵���һ����ŵ���ҩ�������ף������������ǰ��\n�Ǵ�������Ĺ���������Ŀ�Ĺˡ��������ǲ�����ϼ��Ц�ݣ��㲻�ɵ�\n��Ѫ���ڣ�����˺�������·�������(rape)����\n"
);
	set("combat_exp", 100000);
	set("attitude", "friendly");
	set ("no_arrest",1);
        set("chat_chance", 1);
        set("chat_msg", ({
		"С�Һ캦�ߵ�����˵����˵��������˳�ʲô�������ͺ�ɢ�����Ĵ�\n��������ҪС���ˡ�\n",
		"С�Һ�����Ц��Ц��һ˫��˵���Ĵ��۾�������ġ���ͨ~��ͨ~��������\n",
		"С�Һ�ճյ������Լ��⻬����Ө�����壬�����Ȼ������һ��˵��\n���ļ�į��\n",
        }) );

	setup();
	carry_object(__DIR__"obj/color_cloth")->wear();
}

int accept_fight(object me)
{
	command("say СŮ�����������Ķ��֣�");
	return 0;
}

int accept_object(object me, object obj)
{
        command("smile");
        command("say ��л��λ" + RANK_D->query_respect(me) +
"��������ã�");
}

void init()
{
	add_action("do_rape","rape");
}

int do_rape()
{
	object me,gold;
	me = this_player();
	gold = present("gold_money", me);
	if( (string)me->query("gender") == "Ů��" )
		return notify_fail("��Ҳ��Ů��ѽ����ô�ܸ����������أ���\n");
	if(!me->query_condition("hehe") && me->query("cps")>=16)
		return notify_fail("��ͻȻ�����Լ��������������������Ϊ����æ������������˻�����\n");
	if (me->query_temp("inrape",1))
	{
		return notify_fail("�ף��㲻�����ڽ�������\n");
	}
	me->set_temp("inrape",1);
	me->set("marks/crime","rape");
	if (me->query_condition("hehe"))
	{	
		message_vision(HIM"$N��Ұ�ް����$n�˹�ȥ����$n���·�˺�ã�����
ҩ��ʹ$Nʧȥ���˵����ǣ�\n\n"NOR,me,this_object());
	}else
	{
		if (random(3) || me->query("marks/crime") == "rape")
		{
			message_vision(HIR"$N��Ұ�ް����$n�˹�ȥ��$n����$N����һЦ��������������Ҫ��ô�Լ��������\n\n"NOR,me,this_object());
			message_vision(HIW"$N��������ͣ�����֣�ϲ������������ҲԸ�⣬��Ǹ��á��������Һú������㡣��
��˵�ţ��ߴ�����ǰ��\n\n"NOR,me);
			message_vision(HIY"$nЦ�ø��Ӳ��ã����Ƶ�������λ"+RANK_D->query_respect(me)+"�����������ء����ǻ��������𣿡�\n\n"NOR,me,this_object());
			call_out("arresthim",4,me);
			return 1;

		}else
		{
			message_vision(HIM"$N��Ұ�ް����$n�˹�ȥ����$n���·�˺�ã�����\n"NOR,me,this_object());
		}
	}
	this_object()->set("chat_chance", 0);
	call_out("rapeit",20,me);
	return 1;
}

void arresthim(object me)
{
	object bukuai1,bukuai2,*inv;
	if (objectp(me) && present(me,environment()))
	{
		me->delete_temp("inrape");
		message_vision("ͻȻ�Ӱ������������������$N��Ц���������Ǵ�������λ"+RANK_D->query_respect(me)+"�������ء���\n\n", me);
		tell_object(me,"�����д������ɺ����̫�١�\n");
		message_vision("�����$N��Ц����������������׷�����Ǹ��ɻ����ܾ��ˣ��ԹԸ������߰ɣ��� \n",me,bukuai1);
		message_vision("���콫$NѺ����Ρ� \n",me,bukuai1);
		me->set("vendetta/authority", 1);
		me->move("/d/jinan/laofang1");
		message_vision(HIY"$N���ѿ����еĶ�����һ���߽����η���\n"NOR,me);
		inv = all_inventory(me);
		for(int i=0; i<sizeof(inv); i++) 
		{
			if (inv[i]->query("id")=="treasure box")	
				inv[i]->do_qqsave(me);
        	else if (!inv[i]->query("no_drop"))
        		destruct(inv[i]);
		}
	}
	return;
}


void rapeit(object me)
{
	if (living(this_object()) && objectp(me) && environment(me) == environment())
	{
		message_vision(HIR"С�Һ�������ȣ�����ѽ�����컯����ǿ����Ů����,
$N��Ϊ��������$n��Ө��������ϴ�Ϣ�ţ�˻ҧ�ţ�����\n\n"NOR,me,this_object());
		call_out("finishit",20,me);      
	}
	else
		remove_call_out("rapeit");
}	

void finishit(object me)
{
	object *inv;
	int i;
	if (living(this_object()) && objectp(me) && environment(me) == environment())
	{
		me->delete_temp("inrape");
		if (me->query_condition("hehe"))
		{
			message_vision(HIY"$N��ҩ�Դ߷�����ȫ��ʧ�Լ�������ͻȻ��
$N����~~����~~�����˷ܵļ�����������Ż�����ȥ��������\n"NOR,me);
			inv = all_inventory(me);
	        for(i=0; i<sizeof(inv); i++)
		    {
				destruct(inv[i]);
			}
			me->change_condition_duration("hehe",0);
     		me->unconcious();
     		
		}else
		{
			message_vision(YEL"$N��������ش�$n��������������\n\n"NOR,me,this_object());
			message_vision(HIC"$N��Ȼ����$n���۹�һֱ�������ض����㣬�ǳ����˷�ŭ����ⲻ����������ս��\n\n"NOR,me,this_object());
			message_vision(HIC"$n�ӵ���վ������ص�������һ��ҪΪ��������һ�и������ۡ���˵�ϣ�ת���ȥ��\n"NOR,me,this_object());
		}
		me->set("vendetta/authority", 1);
		destruct(this_object());
	}		 	
    else
		remove_call_out("finishit");
}

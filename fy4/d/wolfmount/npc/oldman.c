inherit NPC;
#include <ansi.h>
#define MONEY_VALUE 3000
#define GUEST_MONEY_VALUE 30000

void create()
{
	set_name("��������", ({ "lame oldman", "oldman"}) );
	set("gender", "����" );
	set("age", 54);
	set("reward_npc", 1);
	set("difficulty", 3);
	set("per", 35);
	set("attitude","friendly");

	set("long","һ���׷��ԲԵ��������ˣ���ͣ�ؿ��ţ��ƺ���Ҫ�ȳ�Ѫ������\n");
	set("combat_exp", 3000000);
	set_skill("move", 120);
	set_skill("dodge", 300);
	set_skill("parry", 300);
	set_skill("unarmed",300);
	set("inquiry", ([
        	"ҹ����": "ҹ��������ɽ���������ص�����....��...û����֪\n���������\n",
        	"����̫ү": "����̫ү����ɽ�����������ף����ָ������Ƕ�Ҫ��\n��������\n",
	]) );
	setup();
	carry_object(__DIR__"obj/cloth")->wear();
}

void init()
{	
	object me;
	::init();
	me = this_player();
	if( interactive(me) && !is_fighting() && !me->query("marks/wolf_pass_oldman") )
	{
		remove_call_out("greeting");
		call_out("greeting", 0, me);
	}
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() )
		return;
   
	if (ob->query("class") != "wolfmount")
	{
        	message_vision(HIW"$N����̧ͷ�����������û�����������ȥ����\n"NOR,this_object());
		return;
	}
	else
	{
        	message_vision("$NЦ��������������������ʲô�û�Т��үү����\n",this_object());
		return;
	}
	return;
}

int accept_object(object me, object obj)
{	
       	object npc;
       	npc = this_object();
       	if (me->query("class") != "wolfmount")
       	{
		if( (int) obj->query("value") >= GUEST_MONEY_VALUE || (int) obj->value() >= GUEST_MONEY_VALUE )
        	{
        		message_vision(YEL"$NͻȻЦ�ˣ�һ˫˥��ƣ����۾���Ҳ����Ц�ݣ�\n"NOR,npc);
        		message_vision(YEL"$N������$n��Ц��˵���߽�ȥ������һ�ȴ��ţ������£������Ž�ȥ��\n"NOR,npc,me);
        		me->set("marks/wolf_pass_oldman",1);
        		return 1;       
        	}
		else
		{
        		tell_object(me,"��������һ���Ĳ�м��������ʲô�������Ϸ���Ҫ��\n");
			return 0;
		}
	}
       	else
       	{
       		if( (int) obj->query("value") >= MONEY_VALUE || (int) obj->value() >= MONEY_VALUE )
        	{
        		command("say �ã��ã����Т˳���Һ������㣡\n");
        		command("whisper "+me->query("id")+" һֱ�ߣ�����һ�ȴ��ţ������£���\n���Ž�ȥ��\n");
        		me->set("marks/wolf_pass_oldman",1);
        		return 1;       
        	}
		else
		{
        		tell_object(me,"��������һ���Ĳ�м��������ʲô�������Ϸ���Ҫ��\n");
			return 0;
		}
	}
	return 1;
}
#include <ansi.h>
inherit NPC;
void checking();

void create()
{
        set_name("ë��ͷĿ", ({ "thief leader", "leader" }) );
        set("gender", "����" );
        set("age", 27);
        set("str", 20);
        set("int", 12);
        set("per", 10);
        set("long", @LONG
���ë�����в�ɫ������������죬�·��������ã������еĵ�������ġ�
LONG
);
        set("attitude", "friendly");
        set("combat_exp", 10000);
        set("chat_chance", 3);
        set("chat_msg", ({
			(: checking :),
        }) );

        set("chat_chance_combat", 1);
        set("chat_msg_combat", ({
              "ë��ͷĿ��Ȼ�Ǹո����У�����ƫ��Ŀ�����ߡ�\n",
              "ë��ͷĿ�ߺ��������Ӱ����������ӣ����ź��Ӿ��з����ˡ�\n",
        }) );

        set("force",500);
        set("force_factor",10);
        set_skill("unarmed", 100);
        set_skill("blade", 100);
        set_skill("dodge", 100);
        set_skill("parry", 100);
        setup();
        carry_object(__DIR__"obj/caidao")->wield();
        carry_object(__DIR__"obj/pocloth")->wear();
}

void init()
{
        ::init();
	add_action("do_accept", "accept");
	add_action("do_forgive", "forgive");
}

void win_enemy(object loser)
{
	object cart;
	object robber;
	cart = present("silver cart",environment());
	robber = this_object();
	
	command("laugh");
	command("say ��λ" + RANK_D->query_respect(loser)+ "���������ֻ��������ڣ�Ц�����ӵĴ����ˣ�\n");
        if ( present("silver cart",environment(this_object())) )
        {
        	message_vision("$N�����ڳ���Х��ȥ��\n", robber);
        	destruct(cart);
        }
        destruct(robber);
        return;
}

void lose_enemy( object winner )
{
	object robber;
	robber = this_object();
	winner->set_temp("marks/winner",1);

	command("cry");
	command("say С�����а�ʮ��ĸ������������Ů��һ������ȫ���ҳ��Ű���\n");
	command("say ��λ" + RANK_D->query_respect(winner)+ "������ʴ��壬������(forgive yes/no)С��һ�������ɣ�\n");
}

int do_forgive(string arg)
{
	object me,ob;
	me = this_player();
	ob = this_object();
	if (me->query_temp("marks/forgiveok") || me->query_temp("marks/forgiveno"))
		return 0;
	if(arg == "yes" && me->query_temp("marks/winner")) 
	{
		me->set_temp("marks/forgiveok", 1);
		message_vision(HIY"$N��ͨһ���򵽵��ϣ�Ӣ�۰��������������޵У�������ƥ��������\n"NOR,ob);
		message_vision(HIY"$Nʹ�����飺С��һ��ϴ�ĸ��棬�������ˣ�\n"NOR,ob);
		call_out("goingon",2,ob);
		return 1;
	}
	if(arg == "no")
	{
		message_vision("$N��У��Ҹ���ƴ�ˣ�������\n",ob);
		me->set_temp("marks/forgiveno",1);
		this_object()->kill_ob(me);
		return 1;
	}
	else
		return 0;
}

void goingon(object ob)
{
	message_vision(HIY"$N̾Ϣ����ֻ��С�����޳���������������ʵ�ڲ�֪������ʲô.....\n"NOR,ob);
	message_vision(HIY"$N�ֵ���������������ҲҪ�б�Ǯ������С��.....\n"NOR,ob);
	message_vision(HIY"$N͵͵���ڳ����˳�¶����Ľ��Ŀ��.....\n"NOR,ob);
}


int accept_object(object me, object ob)
{
	object robber;
	robber = this_object();
	
	if(ob->query("name") == "���˧������" && ob->query_amount() == 4000 && me->query_temp("marks/�õ�����") && me->query_temp("marks/forgiveok"))
	{
		message_vision("$N��������Щ�������˸ж��Ŀ���.....\n",me);
		message_vision("$Nָ��ָ�ڳ�������Ҫ��������Ǯ�ǰɣ����У�.....\n",me);
		me->set("marks/�ȼýٷ�",1);
		me->delete_temp("marks/�õ�����");
		message_vision("$Nǧ����л�������������ˡ�\n",robber);
		call_out("robber_gone",2,robber);
		me->start_busy(3);
		return 1;
	}
	else
	{
	       	tell_object(me,"ë��ͷĿ˵������������һ���������У��������Ҫ���Ķ�����\n");
        	return 0;  
        }    
}

void checking()
{
        object robber;
        robber = this_object();
        if (robber->is_fighting()) 
        {
        	if((int)robber->query("kee")* 100 / (int)robber->query("max_kee") <= 80)
        	{
                	if (!living(robber)) 
                		return;
               		else 
                	{
               			message_vision("\n$N�е����������֣��ӰѾ�����\n\n",robber);
                        	return;
                	}
       		}
        }
}

void robber_gone(object ob)
{
	destruct(ob);
}

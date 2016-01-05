// hawktrainer.c
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
int train_animal();
void create()
{
	set_name("��ұ��", ({ "gongye chang","gongye" }) );
	set("gender", "����" );
	set("age", 34);
	set("long", "�����۾��������ŵġ��ƺ���Զ�����ڲ������ʲô��\n");
	set("skill_public",1);
	set("inquiry",([
        	"ѵ����" : (: train_animal :),
        	"animal training" : (: train_animal :),
    	]) );
//	set_skill("animal-talk",200);
	set_skill("animal-training",200);
//	map_skill("animal-training","animal-talk");
    set("combat_exp", 10000000);
	set("attitude", "friendly");
	setup();
	carry_object("/obj/armor/cloth")->wear();
}


void init()
{
	object me;
	::init();
	if(interactive(me = this_player()) && !is_fighting() && userp(me))
	{
			remove_call_out("greeting");
			call_out("greeting", 1, me);
			
	}
}

int greeting(object me)
{
	object crow;
	if( !me || environment(me) != environment() ) return 0;
	if (random(3) || me->query("kar")< 32)		// 30 = L150 foreknowledge,+2 from elsewhere.
	{
	    	message_vision("$N����$nһ�ۣ�������ֹ�� \n",this_object(),me);
	}else
	{
		if (crow = present("crow",environment()))
		{
			message_vision("$N����$nһ�ۣ�Ц��$n˵������֪������˵ʲô������˵��\n\n"
			
			YEL"��ұ�� ��ұ�� ,\n �º�ˤ��һͷ�ǡ�\n ��ʳ�⣬��ʳ������ \n\n"NOR,this_object(),me);
			crow->followme(me);
		}
	}
	
}


void accept_player(object player)
{
	object wolfmeat;
	if (player && present(player,environment()))
	{
		message_vision("��һ�������$N��ʰ�������ǡ�\n",this_object());
		message_vision("$N��$n���������������Ÿ��ҵ���ѻ��������㡣��\n",this_object(),player);
		wolfmeat = new(__DIR__"obj/wolfmeat");
		if (wolfmeat->move(player))
		{
			message_vision("$N�ݸ�$nһ�����⸬��\n",this_object(),player);
		}
		if( player->query_temp("followcrow") && !player->query("marks/getwolf")) 
		{
			message_vision("$N��������һֱ�����ҵ�ѵ����ʧ������λ"+ RANK_D->query_respect(player) +"������ͶԵ��
�����������ҿ��Խ��㼸�֡���\n",this_object());
			player->set("free_learn/animal-training",1);
			REWARD_D->riddle_set(player,"ѱӥ��ɽ",1);
			player->delete_temp("followcrow");
		}

	}
}

int accept_object(object who, object ob)
{
	if(ob->query("id") != "deadwolf" || !ob->query("deadwolf"))
    	return 0;
    	
    message_vision("$NЦ�����$n��������λ"+ RANK_D->query_respect(who) +"���Ǵ���!��\n",this_object(),who);
	message_vision("$N���˵ؽӹ����ǣ���ʼ��Ƥ���\n \n",this_object());
	call_out("accept_player",2,who);
	return 1;
}


int train_animal()
{
	message_vision("$N������ѵ������һ�ź����õļ��ܣ������������ѵ������
��Ϳ�ѵ�����ޣ������������㣬Ϊ����񡣡�\n\n", this_object());
	return 1;
}


int recognize_apprentice(object ob)
{
	if (this_player()->query("free_learn/animal-training"))
		return 1;
	else
		return 0;
}




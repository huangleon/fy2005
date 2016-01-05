
#include <ansi.h>

inherit NPC;


void create()
{
        set_name("������", ({ "di qinglin","di","qinglin" }) );
        set("long",
                "һ��ѩ�׵����ѣ�һ����Ⱦ��һ�Ų԰���������ϣ����Ǵ������䵭����
�ı��顣������ӹ��������糾����ȴ�������������������ĵ�С��ү��\n");

        set("attitude", "friendly");
        set("reward_npc", 1);
	set("difficulty", 20);
	set("age",27);
        set("str", 100);
        set("cor",50);
        set("agi",50);
        set("cps",75);
        set("con",70);
	set("title", HIY"��Ϯһ�Ⱥ�"NOR);

        set("combat_exp", 3000000+random(1000000));
        set("max_force",2000);
        set("force",2000);
        set("force_factor",50);
        

	set_skill("unarmed",200);
    	set_skill("dagger",200);
    	set_skill("xinyue-dagger",150);
	set_skill("parry",1000);
	set_skill("dodge",200);
	set_skill("fall-steps",200);
    	map_skill("dagger","xinyue-dagger");
	map_skill("dodge","fall-steps");
        set("chat_chance", 1);
        set("chat_msg", ({
"���������ᶶ����һ����Ⱦ��ѩ�׳��£����ͻȻ����һ������Ц�⡣��\n"
}) );
/*
        set("inquiry", ([
                "���ڰ�" : (: answer_robery :),
                "robery" : (: answer_robery :),
                "���" : (: answer_yang :),
                "yang" : (: answer_yang :),
                "yang zheng" : (: answer_yang :),
                "������" : (: answer_di :),
                "di" : (: answer_di :),
                "di qinglin" : (: answer_di :),
        ]));

*/
        setup();

        carry_object(__DIR__"obj/shirt")->wear();
        carry_object(__DIR__"obj/thinblade")->wield();
}

void init()
{
	::init();
	add_action("do_sitdown","sitdown");
	add_action("do_answer","answer");
}

int kill_him(object ob)
{
	if(!ob||environment(ob)!=environment())
		return 0;
	message_vision(HIC"�������$N΢΢��̾�˿������������Ǿ��Ʋ��ԳԷ��ơ�������\n"NOR,ob);
	//dont allow player answer now
	ob->delete_temp("answering");
	kill_ob(ob);
	ob->kill_ob(this_object());
	return 1;
}

int greeting(object ob)
{
	message_vision(HIY"��������$N΢һ��ף�˵����������sitdown������\n"NOR,ob);
	call_out("kill_him",10,ob);
	return 1;
}

int do_sitdown(string arg)
{
	object me=this_player();
	
	message_vision(HIW"$N�ϻ̳Ͽֵ������������ϡ�\n"NOR,me);
	message_vision(HIC"�������������$N�ʵ�������λ"+RANK_D->query_respect(me)+"���ٱִ�������Ϊ�������һ�ٰ�ʮ��������������
��answer yes/no��\n"NOR,me);
	me->set_temp("answering",1);
	remove_call_out("kill_him");
	call_out("kill_him",10,me);	
	return 1;
}

int player_leave(object me)
{
	message_vision("�����뽫$N�ϳ��������\n",me);
	me->move("/d/libie/corrider");
	return 1;
}

int do_answer(string arg)
{
	object me=this_player();
	
	if(!me->query_temp("answering"))
		return 0;
	if(arg=="yes")
	{
		remove_call_out("kill_him");		
		if(me->query("libie/���_С���ӵľ���"))
		{
			message_vision(HIW"�������Ȼ΢Ц��������������Ҳ����ô���ѡ���\n"NOR,me);
			message_vision(HIR"�����벻����İ���һ����ߵ�һ�����棬$N���µ����ź�Ȼ����֨֨�����졣\n"NOR,me);
			if(me->query("libie/���_����ү������"))
			{
				tell_object(me,HIW"������һ������Ȼ������ү�Ľ��档\n"NOR);
				message_vision(CYN"$N��æ����������ֻ�������µĵذ��Ȼ������ȥ��¶����һ���ڶ����������붴�У�һ���Ӿ���ʧ�ˡ�\n"NOR,me);
				message_vision(HIY"������΢΢һ㵣��漴��΢Ц�Ŷ�$N�������ο࣬��ʵ����ʹ�෴����һЩ��������\n"NOR,me);
				this_object()->kill_ob(me);
				me->kill_ob(this_object());
			}
			else
			{
				message_vision(HIC"�����µĵ����Ȼ�ѿ���$Nֻ������һ�ᣬ��ֱ׹��ȥ����\n"NOR,me);
				message_vision(RED"������ڶ���һ˲�䣬$N�����Ϻ�Ȼ��¶���ޱȿ־�ı��飬��Ϊ$P�����ľ�������������������
���޷�����Ŀֲ�������\n"NOR,me);
				me->set("kee",-1000);
				me->move("/d/libie/void");
			}
			return 1;
		}
		else
		{
			message_vision(HIC"�������Ȼ��Ц��������ô�����������飬ֻ�����Ǹ���˰ɡ���\n"NOR,me);
			me->set_temp("libie/СҶ��ɱ",1);
			call_out("player_leave",2,me);
			return 1;
		}
	}
	if(arg=="no")
	{
		remove_call_out("kill_him");		
		message_vision(HIC"�������������Ȼ��������ˡ�������ˣ����߰ɡ���\n"NOR,me);
		call_out("player_leave",2,me);
		return 1;
	}
	return 0;
}
int return_home(object home)
{
	destruct(this_object());
	return 1;
}

	

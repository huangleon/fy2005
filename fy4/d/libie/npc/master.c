inherit NPC;
inherit F_MASTER;
#include <ansi.h>

int	story1();
void	leg_bye();

void create()
{
        set_name("��һ��", ({ "master yichen", "master", "master lan" }) );
        set("nickname", HIC "������"NOR);
        set("gender", "����" );
        set("long","
�����ͷ���Ŷ������ǩ�����úܵͣ�������ס��üë��ס���۾�����
һ���������������ҵ���Ӱ�ֻ�ܿ�������һ˫�֡��������ƺܿ�
��ָȴ�ܳ��������ݣ�ָ�׼��ụ́ܶ���ϴ�úܸɾ��������ϴ��ż���
��ϴ�÷��׵����û�����ϴ�÷ǳ��ǳ��ɾ������󻹱��ű�װ��СţƤ
������ĳ�������ƽ�����õĽ����ٳ��߰˴硣�����Ѿ����ƾɣ�����
��ȴ����ո�µ���籣��û�ͭ��ɵĽ��ɺͽ��ʵ��̿�Ҳ���ú����� \n");

        set("reward_npc", 1);
	set("difficulty", 10);
		
        set("age", 54);
        set("skill_public",1);
	
	set("attitude","friendly");
        
        set("combat_exp", 6000000);
        set("score", 200000);
                
        set("chat_chance", 1);
        set("chat_msg", ({
                "��һ����ɫ���������������һ���ֵ�������ж�����ԡѪ���飬��Ȼ̤����\n",
        }) );

	set("inquiry", ([
                "����" : 	"��������������ͷ��Ů����\n",
                "lian gu" :  	"��������������ͷ��Ů����\n",
                "���" : 	"����˹������֮�ӣ���˵�����ڵ���һ׮�ذ���\n",
                "yang" : 	"����˹������֮�ӣ���˵�����ڵ���һ׮�ذ���\n",
                "yang zheng" : 	"����˹������֮�ӣ���˵�����ڵ���һ׮�ذ���\n",
                "������":	"�����������֮�ޣ���Ů�Ӱ�����\n",
                "lu suwen":	"�����������֮�ޣ���Ů�Ӱ�����\n",
                "�ذ�":		(: story1() :),
                "����":		(: story1() :),
                "����ʧ��":	(: story1() :),
                "����":		(: story1() :),
                "���³���":	"������������������ʮ����ֶ棬�����³������ʹ��������µ�һ���ֶ�Ķ���",
                "di qinglin" :  "��˵�Ŀ����ӹ��������糾����ȴ�������������������ĵ�С��ү�����룡\n",
                "������" : 	"��˵�Ŀ����ӹ��������糾����ȴ�������������������ĵ�С��ү�����룡\n",
                "������":	"��������һ�����Ӵ��������֯���İ������������д���δ�й���
��������Ӵ����ܵ���֯�� \n",
        ]));
        
        create_family("��ɽ����", 3, "����");
        	
	set("chat_chance_combat", 5);
    	set("chat_msg_combat", ({
	     (: leg_bye() :),
        }) ); 	
	
        set_skill("move", 120);
	set_skill("parry", 120);
        set_skill("dodge", 120);
	set_skill("sword", 150);
	set_skill("unarmed",120);
	set_skill("sky-steps",100);
	set_skill("whip",150);
	set_skill("xiaohun-sword",150);
	set_skill("xiaohun-whip",150);
		
	map_skill("dodge", "sky-steps");
	map_skill("sword", "xiaohun-sword");
	map_skill("parry", "xiaohun-sword");
	map_skill("whip","xiaohun-whip");

        setup();
        carry_object(__DIR__"obj/bluesword")->wield();
        carry_object(__DIR__"obj/shirt")->wear();
		add_temp("apply/damage",80);
}

void attempt_apprentice(object me)
{
	command("shake "+me->query("id"));

}
 
int accept_object(object who, object ob)
{
	if (is_fighting() || query_temp("in_talk"))
		return notify_fail("��һ����æ��û�����㡣\n");
	
	if(ob->query("name") == "����һ������" ) 
	{
		if(ob->query("������")==who)
		{
    			message_vision(HIY "
��һ��Ŷ��һ�������������İ��Ȼ��̾�����������������֮�ӣ�����

���㣬��$N���˵�ͷ������������֮�£�ĳ�պ����н���������ʵΪ���ˣ��粻
����������ĳ��ɴ�������ѧ���������»��м�����������´��͡�����ľ�������
�����ʾӡ�������Ѷ�������δ������ɹ�Щ������ȥ����\n"NOR,this_player());
			who->set_temp("libie/���_���ųɹ�",1);
			return 1;
		}
		else
		{
    			say(HIR"��һ�������˵��������һ����Լ���ƭ�ң�ȴҲû��ô���ס�\n"NOR);
			return 1;
		}
	}
			
	if (ob->query("real_leavehook") && ob->query("hook_owner")== who)
	{ 
		if (REWARD_D->riddle_check(who,"���")==3 && !ob->query("blood"))
		{
			message_vision(HIG"
��һ�������к�Ȼ͸����ֵĳ��ȵĹ�â��

������Ľ�����

����է�䣬ֻ����Ǻ����һ����������ɽ�Ž��ѳ��ʣ�ɭɭ�������������˴��֡�\n\n\n"NOR, who);
			full_me();
			fight_ob(who);
			who->fight_ob(this_object());
			who->set_temp("libie/fight_lan",1);
		} else
		{
			message_vision(CYN"��һ�������к�Ȼ͸����ֵĳ��ȵĹ�â��\n"NOR, who);
		}
	}	
	return 0;
}

int recognize_apprentice(object ob)
{
	if(REWARD_D->check_m_success(ob, "���"))
		return 1;
}

int prevent_shown(object me, string skill)
{
	if (REWARD_D->check_m_success(me,"���괫��"))	return 0;
		
	if(REWARD_D->check_m_success(me, "���") && skill!="xiaohun-sword")
		return 0;
		
	return 1;
}


int	story1()
{
	
	object me= this_player();
	
	if (!REWARD_D->riddle_check(me,"���"))
	{
		message_vision(CYN"
��һ��˵�����Ǻ��ˣ�Ϊ�δ������£��ѵ��Ǽ�ϸ���ɣ���\n"NOR,me);
		command("stare");
		return 1;
	}
	
	if (REWARD_D->riddle_check(me,"���")==4)
	{
		message_vision(CYN"
��һ��˵�������ף�����������������Ӧ�ã���\n"NOR, me);
		return 1;
	}
	
	if (REWARD_D->riddle_check(me,"���")==3)
	{
		message_vision(CYN"
��һ��˵������Ѵ������Σ��֮�У�������ȥ������\n"NOR, me);
		return 1;
	}
	
	if (REWARD_D->riddle_check(me,"���")==2)
	{
		if (!me->query_temp("libie/di_1") && !me->query_temp("libie/di_2"))
		{
			message_vision(CYN"
��һ��˵���˵����ҿ����������ٲ�������һ�����࣬����ϴ�����ԩ����\n"NOR, me);
			return 1;
		}
		if (!me->query_temp("libie/di_2"))
		{
			message_vision(CYN"
��һ��̾����˵�����������ã����Ǿ�ƾСҶ���ǵ��������ͯ��һ֤�ݣ�
���»��ⲻ�������Ϯһ�Ⱥ����ʲô����ô��\n"NOR, me);
			return 1;
		}
		if (!me->query_temp("libie/di_1"))
		{
			message_vision(CYN"
��һ����˼����ԭ������������ô�����ı�����Ǿ�ƾ��ͬ��ļ��仰����
�»��ⲻ�������Ϯһ�Ⱥ����ʲô����ô��\n"NOR, me);
			return 1;
		}
	
		message_vision(CYN"
��һ��ŭ����ԭ����ˣ���ɱ��Ҳ�������������ǹ����������һ������
֮��Ҳ���ƷŲ����������Ҵ����������������������ȥ������

��һ������Ƭ���ֵ���������ˣ�����Ѵ������Σ��֮�У�������ȥ������\n"NOR,me);
		REWARD_D->riddle_set(me,"���",3);
		return 1;
	}
				
	message_vision(CYN"
��һ��˵������ǰ���߰�̫ү���˽�����ԭ�ھֵ�һ�ٰ�ʮ��������������Ĳ�ͷ
�������׷ɱ�߰�̫ү�������������˭֪��벶������ȸ�ں�������δ�˻�
����������Ѻ�˵�����һ������ʧ�٣�����������������������ɷ������¾�
���˳�͢������Ϯһ�Ⱥ�����붼�ϸ��˵ء�������ڹ��۶��ϣ����ǡǡ�ֲ���
���𣬲�֪ȥ�򡣡�����

��һ���ս�����˵������Ǽ�������֮���������ǲ��Ѵ��²��ˮ��ʯ��������
ԩ�������޷�ϴ�ѣ�������������Ϊɱ����ڣ�Ҳ���������ٻ��š�

��һ��̾�˿���˵���ұ�������˰��������֮���ڴˣ�������������ɱ��ǰ����
����������������ˣ������ڴ��������⡢�⡢�������Ǻã�

��һ����ϣ�����۹⿴�˿�������������ܴ��Ҳ���˰���ϴ�����ԩ�������µ�
�������ڣ��м�����������

"NOR, this_object());
	REWARD_D->riddle_set(this_player(),"���",2);
	return 1;
}


string *event1_msg=	({
	YEL"
�����ַ��������㴦ʲô�������ַ�������𹳸��Ӱ������ı仯�У���û��
���ֱ仯����������ս������������һ��ȴ�����е����ˣ���û�г��ַ�����
ȴ�ԡ����ذδС�������Ӳ�������Լ���������հ��� \n"NOR,
	
	YEL"
��������ȫû��Ծ��׼���ģ�������һ����������ʱ����������һ�㣬��Ȼ���
���Ҳֻ������һɲ�Ǽ䣬��һɲ�Ǽ�ȴ����������һɲ�ǡ�\n"NOR,

 	YEL"
����Ĺ����ѹ�������һ�����ȡ� 
��֪���������ѽ���������������ˣ���Զ��� 
"HIR"��Ѫ�ɽ���Ѫ���ס��$N���ۡ�"NOR YEL" 
��$N��������ʱ����һ���ѵ������£��Ұ׵�����ȫ��Ѫɫ��һ��������ϥ���ϡ�\n"NOR,

    	
});


void event1(object ob, object me, int count)
{
	if (environment(me)!=environment(ob) || ob->is_fighting()) {
		delete_temp("in_talk");
		return;
	}
	
	message_vision(event1_msg[count]+"\n",me);
	
	if(++count==sizeof(event1_msg))
	{
		message_vision(CYN"

��һ��ֻ������˵��һ�䣺�ã�����ٽ��˹��������\n\n"NOR,me);
		delete_temp("in_talk");
		if (ob->query("eff_kee")>ob->query("max_kee")/4)
		{
			ob->set("eff_kee",ob->query("max_kee")/4);
			ob->set("kee",ob->query("max_kee")/4);
		}
		me->stop_busy();
		return;
	}
	else call_out("event1",2,ob, me,count);
	return ;
}

void leg_bye()
{
	object *enemy,me,weapon;
	enemy = this_object()->query_enemy();
	if (sizeof(enemy)>1)	return;
	
	me= enemy[0];
	
//	message_vision("enmey is "+ me->query("id")+"\n",this_object());
		
	if (REWARD_D->riddle_check(me,"���")!=3
		|| !me->query_temp("libie/fight_lan")
		|| !(weapon = me->query_temp("weapon")))
		return;
	
	if (!weapon->query("real_leavehook") || weapon->query("blood"))
		return;
	
	if (query("kee")<0 || me->query("kee")<0 )return;
	
	weapon->set("blood",1);
	me->remove_all_killer();
	remove_all_killer();
	me->start_busy(40);
	set_temp("in_talk",1);
	message_vision(YEL"$N�Ĺ���Ȼ��һ��˿����������ַ�����һ���κ��˶�����õ��Ĳ�λ���˳�ȥ��
$N�Ĺ��̳�ȥʱ��$N����Ҳ���˹�ȥ��\n"NOR,me);
	call_out("event1",1,this_object(),me,0);
	return;
}

void	win_enemy(object me)
{
	message_vision("��һ����̾һ��˵��ƾ����书������ֻ�ǰװ�������\n", me);
	return;
}


void	lose_enemy(object me)
{
	message_vision("��һ����̾һ����ҡҡͷĬȻ���\n", me);
	return;
}


int prevent_learn(object me, string skill){
	if(REWARD_D->check_m_success(me, "���"))
		return 0;
}
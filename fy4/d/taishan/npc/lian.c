/*
�����Ǳڵ��������þ���һ�з�������������������Ƹ�����λ�����ﵽ�۷壬Ȼ��������������������������ߣ�
���ҳ�ȥ����Щ��ͽ��������������һ���Ѿ���ͨ�ˡ���

��һ�мƻ��󹦸��֮�󣬱�������ң��Ϳ���������ˣ�������Ҳ�Ͳ���������֪���ҵ����ܣ����������˻���
���Ҿ������ڵ����ˣ������һ��Ǹ���ǰһ�����ǰױ���覣�������˫�����Ǳڡ��� 

���٣���֤����һ���£�ӵ�о����书����һ������ǿ�ߣ����߳����ǻۣ����ܵ���ƣ������������ֵ�������Ǯ�� 

�ӽ���޹�ɽׯ����Զ��Ϊ������Ŀ�С����塱�����������Ǳ������֣�Ҳ����Զ�������࣬��Ϊ����֮����Ӣ���е�Ӣ�ۡ� 


*/

inherit SMART_NPC;
#include <ansi.h>

int time_period(int timep, object me);
int give_hint();
string sysmsg;

void create()
{
	set_name(HIG"�����"NOR, ({ "lian chengbi", "chengbi","lian" }) );
	set("gender", "����");
	set("title", "�޹�ɽׯ ��ׯ��");
   	set("nickname", HIR"������˫"NOR);
	set("age", 29);
	set("long", "
һ�����ŵ����ҹ��ӣ���������ȴ�ִ��������˾��ø߲����ʵ��廪֮����
��Ȼ���ǵ�����������һ���е����䣬�޹�ɽׯ��������������Ľ�ľ���
��š�\n");
	
	set("attitude", "peaceful");
	set("reward_npc", 1);
	set("difficulty", 10);
   	set("combat_exp", 10000000);
        
    set("chat_chance", 1);
    set("chat_msg", ({
                "��������㹰�˹��ֵ�������λӢ�ۣ�������������ĳ������ң���\n",
        }) );
        set("inquiry", ([
                "����" : 	(: give_hint:),
                "tianzong" : 	(: give_hint:)
        ]));

	set("fly_target",1);

	set_temp("apply/damage",100);
	set_temp("apply/haste",300);
	
	auto_npc_setup("wang",300,200,0,"/obj/weapon/","fighter_w","taiji",1);
   	setup();
	carry_object("/obj/armor/cloth")->wear();
	carry_object("/obj/armor/hat",([	"name": "���",
    						"long": "һ�������˳����Ĳ�ñ��\n",
    						 ]))->wear();  
}

int accept_fight(object me)
{
        command("say ���д��书���ã�����ĳ��Ӧ���㣬��ȭ�����飬��С���ˣ�");
        return 1;
}

void init()
{
	::init();
//      add_action("give_quest", "quest");
//		add_action("join_in","join");
}

int accept_object(object who, object ob)
{
        int  exp, pot, score, val;
	string test;
	string quest;
// Let's see if this player is one of us
        if((string)who->query("guild") != "����")
                return 0;
	val = ob->value();
        if(!(quest =  who->query("quest")))
	{
        tell_object(who,"�����˵�����ⲻ������Ҫ�ġ�\n");
	return 0;
	}
        if( (string)ob->query("unit")+(string)ob->query("name") != quest)
        {
        tell_object(who,"�����˵�����ⲻ������Ҫ�ġ�\n");
        return 0;
        }
	if( ob->is_character())
        {
        tell_object(who,"�����˵�����ⲻ������Ҫ�ġ�\n");
        return 0;
        }
        if ((int) who->query("task_time") < time() )
        {
        tell_object(who,"�����˵�������ϧ����û����ָ����ʱ������ɣ�\n");
                        return 1;
        }
        else
        {
        tell_object(who,"�����˵�����ã����úã����ھ���Ҫ���������˲ţ�\n");
	exp = random(150) + 10;
// put a cap
	exp = exp * (int) who->query_temp("quest_number")/3;
	exp += 1;
	pot = exp / 5 + 1;
	score = 1;
	who->add("potential",pot);
	who->add("score",-score);
        tell_object(who,HIW"�㱻����������ˣ�\n" +
	chinese_number(pot) + "��Ǳ��\n"NOR);
//	chinese_number(score)+"���ۺ�����\n"NOR);
	who->set("quest", 0 );
	who->add("QUEST",1);
                        return 1;
        }
                return 1;
}

int give_quest(string arg)
{
	string quest ;
	object me;
	int j, combatexp, timep, lvl=0;
        mixed *local;
	string *npcs,*objs,file;
        int  t;
	me = this_player();
// Let's see if this player is one of us
	if((string)me->query("guild") != "����")
		return 0;
	if((int)me->query("last_good_kill") < ((int)me->query("mud_age") - 24*3600))
	{
		tell_object(me,"����赶�����Ц��˵��
���ҿ���ԡ����ڡ����������ģ�������ȥɱһ�������书�൱�ġ��ˡ��\n");
		return 1;
	}

// Let's see if this player is a ghost
	if((int) me->is_ghost())
	{
		write("��겻��Ҫ����\n");
		return 1;
	}
// Let's see if this player still carries an un-expired task
        if((quest =  me->query("quest")))
	{
	if( ((int) me->query("task_time")) >  time() )
		return 0;
	else
		me->set("kee", me->query("kee")/2+1);
		me->delete_temp("quest_number");
	}
	file = read_file("/quest/NPC");
	npcs = explode(file,"\n");
	file = read_file("/quest/OBJ");
	objs = explode(file,"\n");
	timep = random(300)+60;   //  big random factor
// A factor here to make time random
	timep = random(timep/2)+timep/2;
	time_period(timep, me);
	if(random(2))
	{
	quest = npcs[random(sizeof(npcs))];
        tell_object(me,"������ɱ��"+quest+"��\n"NOR);
        sysmsg +="ɱ��"+quest+"��";
	}
	else
	{
	quest = objs[random(sizeof(objs))];
        tell_object(me,"ȥ��"+quest+"�����ڡ�\n"NOR);
        sysmsg +="ȥ��"+quest+"��";
	}
 	me->set("quest", quest);
	me->add("vendetta/authority",1);
	me->set("task_time", (int) time()+(int) timep);
	if((int)me->query_temp("quest_number") < 5)
	me->add_temp("quest_number",1);
	CHANNEL_D->do_sys_channel("qst", sprintf("%s(%s)��%s",
	me->query("name"),me->query("id"),sysmsg));

return 1;
}

int time_period(int timep, object me)
{
        int t, d, h, m, s;
        string time;
        t = timep;
        s = t % 60;             t /= 60;
        m = t % 60;             t /= 60;
        h = t % 24;             t /= 24;
        d = t;

        if(d) time = chinese_number(d) + "��";
        else time = "";

        if(h) time += chinese_number(h) + "Сʱ";
        if(m) time += chinese_number(m) + "��";
        time += chinese_number(s) + "��";

        tell_object(me,HIW + sprintf("%s",this_object()->name()) +"˵����\n��" + time + "��");
	sysmsg = "��" + time + "��";
        return 1;
}

int give_hint()
{
	object me,obj;
	me = this_player();
	obj = this_object();
//	if(me->query_temp("num_of_ask") < random(4)+5)
//	{
//		me->add_temp("num_of_ask",1);
		tell_object(me,"����赵����������ڡ��ǵ��������������أ�а��İ�ᣬ���������¸�
�ɸ��֣��԰�ɱ��ʽ�������켺�������ڡ������ˣ�����������Ҳ�Ǹ������ԡ�
�����ڡ������޹ʲ�ɱ��������Ӣ�ۣ��Թ����Լ��������еĵ�λ��\n");
		return 1;
//	}
//	else{
//	tell_object(me,"����赵��������ƺ��ԡ����ڡ��ܸ���Ȥ���Ƿ�������أ�join yes/no������\n");
//	return 1;
//	}

}
int join_in(string arg)
{
	object me;
	me = this_player();
	if((int)me->query_temp("num_of_ask") < 5) return 0;
	if(!arg || arg != "yes" || me->query("combat_exp") < 800000)
	{
	me->delete_temp("num_of_ask");
        me->set_temp("in_doubt",1);
	return notify_fail("����赵����������ڡ���а���������������롲���ڡ���
�Ҿ����Ź��㣡��\n");
	}
	tell_object(me,"��������������������
����ʵ�Ҿ��ǡ����ڡ����������ӽ��Ժ����Ϊ�����ڡ������ɣ��Ҿ��Բ��������ģ�
���������Ҫ����quest��������һ��Ҫ֤������ǿ�ߣ���\n");
	me->set("guild","����");
        me->delete_temp("num_of_ask");

	return 1;

}

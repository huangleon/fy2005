
inherit SMART_NPC;
inherit F_MASTER;
#include <ansi.h>

string *list = ({
"�����ջؽ�������ƬƬ��Ӱ����ȴ��Ȼ�����������$N��ȥ",
"�����հν����裬һʱ��������âһƬ�����¹������$N",
"������һ����ƮƮ�̳����������ޱ仯�����Ǳ仯��Ȼ������ˣ�\n���þ�������ˮ������Ȼ���д���һ���������������$N",
"���������г�������㴺��������û����֪�������������Ҳ���޷��ֵ�",
"�����յ���һ��ֻ�д̣��򵥶���Ч����$N��С����ȥ",
"���������г��������������������",
"���������г�����â�������������������",
"���������г������һζ���ٿȻ�й�ֱ����������ǰ�ء��Ϲ�Ѩ��",
"���������г�����һ������һɨ��������Ư�������ƣ����赭д�ػ���",
"������������ע��������򵥵��ĺỮ��ȥ��һ��ƽ���ġ�������\n�ڡ����������о�����˹����",
"���������ΰεض������г����趯�����콣��ɭɭ������������",
"�������������ӻ���һ���뻡�����ֳ������㣬�����Ľ�����Ȼ������˷�������",
"����������һԾ�����г���ǣ������������������а�����������ȥ",
"�����ոߺ�������Խ��Խ�ݣ����Ƿ��˿��Ұ��һ�㣬������ɨ�ͻ��������Ҵ�",

"����������΢΢һ�𣬳��������һ�������",
"�������͵ػӶ��������㵱ͷ���£�������һ�����������Ľ����������ĵ�Ϯ��",
"������һ����Х����̤����ǰ���������г���ƽƽ�ݳ���ֱȡ�������",
"���������г����ζ���������У�ͻȻ��Ӱ�з���һ�����������ü��",
"����������Ʈ�����ߣ����г���ն�����ü��",
"�����ս��ƽ������������߶���������Ȼ�����͵͵����죬��֮һ\n����ۣ������������֮���������������",
"���������������һš�����ֳ������������ü�Ļ�ȥ",
"�����վ�߳һ����˫�ֲ��٣����ⶸ�ɣ���ʱ�˽���һ�����ֱ��$N��ȥ",

});
string *list2 = ({
"��Ȼ���꽣��",
"�����߾�",
"��ʮ������",
"���ϸ�����ὣ",
"���ֽ���",
"���촵Ѫ����",
"���𵶷�",
"�򹷰���",
"�����ȷ�",
"Ѫսǹ��",
"���潣��",
"���ʮ��ʽ",
"��ԯ����",
"��ħ�ȷ�",
"����������",
"һ��������",
"������ƽǹ��",
"�ϻ�ǹ",
"ѩӰ����",
"������ɱ",
"̫������",
"������",
});

int go_fight();
int good_boy();

void create()
{
    	set_name("������", ({ "bai sankong","bai" }) );
    	set("nickname", HIY"��ƽ����"NOR);
    	set("gender", "����" );
    	set("title", "��ƽɽׯ  ׯ��");
    	set("class","shenshui");
    	set("long", "
һ����Ĺ˳�������˿�����������������룬��òʮ����������ˣ�
����ɽ��ʡ��������������ƽ���͡������ա�\n");
    	
 		set("guard_msg",HIW"$N��$n�ȵ����Ϸ������ˮ���Ŀ��ˣ����ݲ�������������Ұ��\n"NOR);	
 	    
    	set("reward_npc", 1);
    	set("difficulty", 5); 
    	set("age", 64);
    	
    	set("skill_public",1);
    	set("attitude","peaceful");
    
    	set("no_busy",10);
       	set("atman",1000);
    	set("max_atman",1000);
    	set("fly_target",1);
 	   
    	set("toughness", 200);
    	
    	set("inquiry",([
    		"������":		(: go_fight() :),
    		"��ɣ������":	(: go_fight() :),
    		"����������":	(: go_fight() :),
    		"ʧ��":			(: good_boy() :),
    		"ս��":			(: good_boy() :),
    	]));		
    			
    	 	        
    	set("chat_chance", 1);
    	set("chat_msg", ({
			"������ҡͷ̾��������ƽɽׯ������ϣ��˶�˥������������\n",	
        }) );
        
    	set("combat_exp", 3800000);
    	set("score", 200000);

    	set_skill("move", 150);
    	set_skill("parry", 150);
    	set_skill("dodge", 150);
    	set_skill("force", 150);
    	set_skill("sword",200);
    	set_skill("qingpingsword",200);
    	set_skill("qingpingforce",150);
    	set_skill("chaos-steps",150);
    	set_skill("bai-quan", 200);
    	set_skill("unarmed", 150);
    	
    	map_skill("unarmed", "baiquan");
    	map_skill("force", "qingpingforce");
    	map_skill("parry","qingpingsword");
    	map_skill("sword","qingpingsword");
    	map_skill("dodge","chaos-steps");
    	map_skill("move","chaos-steps"); 
    	map_skill("unarmed","bai-quan"); 
	
		set("perform_busy_w", "shenshui/sword/qingpingsword/fengzijue");
	
		set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(100) :),
        }) );

    	setup();
    	carry_object("/obj/armor/cloth")->wear();
    	carry_object("/obj/weapon/sword")->wield();
    	carry_object(__DIR__"obj/shuzhi")->wield();

}

int demo(object me) {

	int k;
	k=random(sizeof(list));

	if (me->query("class")!= "shenshui")
	{
    		command("sigh");
    		command("say ���������Ļ����䣬����ʲôͽ�ܡ���\n");
			return 1;
		}
		else if (REWARD_D->check_m_success(me,"��ƽ����"))
		{
    		message_vision("���������͵����������ͷ˵�����ú�Ŭ���ɡ���\n", me);
			return 1;
    	} 

		if (me->query_temp("marks/shenshui/bai_ask") ==1)
			k=me->query_temp("marks/shenshui/bai_answer");

		if (me->query_temp("marks/shenshui/bai_ask") ==2)
			k=me->query_temp("marks/shenshui/bai_answer");


		if (me->query_temp("marks/shenshui/bai_ask")<=1)
		{
    		message_vision(CYN+list[k]+"��\n"NOR, me);
    		tell_object(me, WHT"������˵�����֪������һ�ŵ���ʽ�书��\n"NOR);
    		add_action("do_answer","answer");
    		me->set_temp("marks/shenshui/bai_ask",1);
    		me->set_temp("marks/shenshui/bai_answer",k);
    	}
		else  
		{
    		message_vision(CYN+list[k]+"��\n"NOR, me);
    		tell_object(me, WHT"������˵�����֪��������һ�ŵ���ʽ�书��\n"NOR);
    		add_action("do_answer","answer");
    		me->set_temp("marks/shenshui/bai_ask",2);
    		me->set_temp("marks/shenshui/bai_answer",k);
    	} 
    	return 1;
	
}

int do_apprentice(string arg)
{
	object me = this_player();
	
    	if (arg == "bai sankong" || arg == "bai") {
		demo(me);
	    	return 1;
	}
	return 0;
}

int do_answer(string arg){
	object me = this_player();
	int k;
	k=me->query_temp("marks/shenshui/bai_answer");
	
	if (!me->query_temp("marks/shenshui/bai_ask"))	return 0;
	if ( me->query_temp("marks/shenshui/bai_ask") == 1) {
		if (arg == list2[k])
		{
			k=random(sizeof(list));
    		message_vision(CYN+list[k]+"��\n"NOR, me);
    		tell_object(me, WHT"������˵�����֪��������һ�ŵ���ʽ�书��\n"NOR);
    		add_action("do_answer","answer");
    		me->set_temp("marks/shenshui/bai_ask",2);
    		me->set_temp("marks/shenshui/bai_answer",k);
    			return 1;
    		}
    	}
    	if ( me->query_temp("marks/shenshui/bai_ask") == 2) {
		if (arg == list2[k]) {
			message_vision(CYN"
���������͵�������$N��ͷ˵����ѧ֮�������ⲻ���Σ���ѧ�ҵ���ƽ�书��
�಻�ɾ�����һ��һʽ�����轫���ڻ��ͨ�������似�з��гɾͣ��м��мǣ�\n"NOR,me);
			me->delete_temp("marks/shenshui/bai_ask");
			REWARD_D->riddle_done( me, "��ƽ����", 10, 1);
			return 1;
    		}
    	}
//	me->delete_temp("marks/shenshui/bai_ask");
	command("shake");
	return 1;
}
	

int recognize_apprentice(object ob)
{
	if(ob->query("class")=="shenshui" ) {

		if (REWARD_D->check_m_success(ob,"��ƽ����"))
			return 1;
		else
			demo(ob);
	}	
	return 0;
}


void init()
{
    	object me;

    	::init();
		add_action("do_killing", "kill");
		add_action("do_apprentice","apprentice");
}


int go_fight(){
	
		object ob;
		ob = this_player();
		
		if (REWARD_D->check_m_success(ob,"��ƽ����")
			|| REWARD_D->riddle_check( ob, "��ƽ����")>2)
		{
			command("hmm");
			return 1;
		}	
			
		command("say ʮ��ǰ��ɣ��������ս���֣���������ɱ������ɡ�˫����ʿ�衢
���ɽ�����硢�����ڽ��ǣ�Ϊʦ�಻�Ƕ��֣��������º�������ַ��������ߡ�");
		command("say ���º����ţ������˸�������ԭ���֣������ܵ���棡");
		
		if (!REWARD_D->riddle_check(ob, "��ƽ����"))
			return 1;
		
		if (REWARD_D->riddle_check(ob,"��ƽ����")==1)
			REWARD_D->riddle_set(ob,"��ƽ����",2);
			
		command("say ������Ұ����յ��ӣ��ٸ���������һս��ֻ�ɳɹ�����"YEL"ʧ��"CYN"��");
		
		return 1;
		
}
		
int good_boy() {
	
		object ob;
		ob = this_player();
		
		if (!REWARD_D->riddle_check( ob,"��ƽ����"))
		{
			command("dunno");
			return 1;
		}
		
		if (REWARD_D->check_m_success(ob,"��ƽ����"))
		{
			command("say ѧ��֮�ˣ������������ģ������ڽ������������ƽ��֮��ꡣ");
			return 1;
		}
		
		if (REWARD_D->riddle_check(ob,"��ƽ����") == 2
			|| REWARD_D->riddle_check(ob,"��ƽ����") == 1)
		{
			command("say δս���԰ܣ�������ѧ��֮����Ϊ��");
			return 1;
		} 
		
		if (REWARD_D->riddle_check(ob,"��ƽ����") == 4)	// ����ô��
		{	
			command("ack");
			command("spank");
			command("say �ã��������Ұ����յ�ͽ�ܣ�");
			command("super");
			
			REWARD_D->riddle_done( ob,"��ƽ����",50,2);
			return 1;
		}
		
		if (REWARD_D->riddle_check(ob,"��ƽ����") == 3)	// �������
		{	
			command("smile");
			command("say ��ͽ����");
			command("say ѧ��֮�ˣ������������ģ������ڽ���");
			command("say ��������������Ϊ��������Ϊ��������Ϊ��");
			command("say �������ڱ�����ֻҪ�����д��ۣ����ֺη���");
			command("say ���������ƽ��֮��꣡");
			command("super");
			REWARD_D->riddle_done( ob,"��ƽ����",50,1);
			return 1;
		}
		
		if (REWARD_D->riddle_check(ob,"��ƽ����") == 5)	// �ӱ�
		{
			command("puke");	
			command("say �Ұ�����һ��Ӣ������������̰��������ͽ�ܣ�");
			command("sigh");
			command("say ��ס����������������Ϊ��������Ϊ��������Ϊ��");
			command("say ���������ƽ��֮��꣡");
			REWARD_D->riddle_done( ob,"��ƽ����",0,2);
			return 1;
		}	
		write ("hmm, please report to wizard, you shouldn't see this.\n");
		return 1;
}		
			
			
		
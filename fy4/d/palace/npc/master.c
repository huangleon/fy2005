inherit NPC;
inherit F_MASTER;
#include <ansi.h>
int ask_challenge();
int leave();

void create()
{
    	set_name("������", ({ "master xiao", "xiao","master" }) );
    	set("gender", "����" );
    	set("nickname",HIY "���¿�" NOR);
    	set("reward_npc", 1);
    	set("difficulty", 15);
    
    	set("age", 45);
    	set("per", 30);
    	set("attitude","friendly");
    	set("class","yinshi");
    	set("apprentice_available", 50);
    	create_family("������", 1, "����");
    	set("rank_nogen",1);
		set("ranks",({ "��ͯ","��ͯ","��ͯ","����","���","�Ƴ�",
			"��ʿ","����","����","����","����","����",CYN"���"NOR,
			CYN"���"NOR,CYN"�Ƶ�"NOR,HIC"���µ���"NOR}));
		set("rank_levels",({ 16000, 32000,64000, 128000,
					256000,512000,1024000,1536000,2048000,
					3064000,4096000, 5120000,6144000,8192000,
					9999999}));
					
    	set("long","�����������û���κ���֪����Ҳû���˸Ҵ�����\n" );
    
    	set("combat_exp", 20000000);
    	set("score", 90000);
    	set("guard_msg","$N�ȵ��������ȵ��ˣ��ݲ��ø������̣ܽ�\n");
    	set_temp("apply/haste",400);
    	
    	set_skill("move",200);
    	set_skill("perception", 190);
    	set_skill("foreknowledge", 180);
    	
    	set_skill("flying-dragon", 200);
    	set_skill("unarmed",160);
    	set_skill("thunderwhip", 200);
    	set_skill("whip", 200);
    	set_skill("force", 160);
    	set_skill("parry", 160);
    	set_skill("literate", 100);
    	set_skill("zuixian-steps", 200);
    	set_skill("dodge", 160);
    	set_skill("chanting",100);
    	set_skill("cursism",200);
    	set_skill("celecurse",200);
    	set_skill("iceheart", 150);
    	
    
    	map_skill("cursism","celecurse");
    	map_skill("unarmed", "flying-dragon");
    	map_skill("whip", "thunderwhip");
    	map_skill("force", "iceheart");
    	map_skill("parry", "thunderwhip");
    	map_skill("dodge", "zuixian-steps");
	
	set("inquiry",([
        	"challenge" : 	(: ask_challenge :),
        	"��ս": 	(: ask_challenge :),
			"tiaozhan": 	(: ask_challenge :),
			"���촸" : 	(: ask_challenge :),
			"master lan" : 	(: ask_challenge :),
			"leave" : 	(: leave :),
    	]) );
    	
    	set("chat_chance_combat", 40);
    	set("chat_msg_combat", ({
        		(: perform_action, "whip.yunlongjiuxian" :),
        }) );
    
    	setup();
    	carry_object(__DIR__"obj/shenxue")->wear();
    	carry_object(__DIR__"obj/baojia")->wear();
    	carry_object(__DIR__"obj/zhiai")->wear();
    	carry_object(__DIR__"obj/sidai")->wield();
}


void reset()
{
    	delete_temp("learned");
}

void attempt_apprentice(object ob)
{
	if((int) ob->query_temp("wait_time") < 360)    {
        	command("think");
        	command("say ���Ĳ��ϣ�����\n");
        	ob->set_temp("xiao_failed",1);
	return;
    }
    else {
		command("smile");
       	command("say ���պ���д�ɣ�");
       	command("smile");
       	command("recruit " + ob->query("id") );
    }
}

int ask_challenge()
{
	object me;
	me = this_player();
	if ( me->query("class") == "yinshi" 
		&& REWARD_D->riddle_check(me,"�촸֮ս") == 1)
	{	
		command("say ���϶�����������"NOR);
		if (me->query("level")>= 50)
		{
			REWARD_D->riddle_set(me,"�촸֮ս",2);
			message_vision(CYN"$N�����Ķ�$n˵������ѧҵ�гɣ���ô����Ϊʦ��һ��ɡ����������������촸
���̹ž�ʽ(challenge master lan).��\n"NOR,this_object(),me);
		}else
		{
			message_vision(CYN"$NЦ���������϶��Ĵ�������һ����ֻ��ϧ����δ�������ܴ�Ϊʦ��ѵ����������\n "NOR,this_object());
			tell_object( me,WHT"����ȼ�50��\n"NOR);
		}
		return 1;
	}
	if (REWARD_D->check_m_success(me,"�촸֮ս"))	{
		command("say ��ͽ����ΪʦҲ�����й⣡");
		return 1;
	}
	
	if (REWARD_D->riddle_check(me,"�촸֮ս")==2) {
		command("say ͽ����������ȥ��ս������");
		return 1;
	}
	
	return 0;
}

void init()
{	
	::init();
	add_action("do_killing", "kill");

}

int leave() {
	if (this_player()->query("class")!="yinshi") return 0;
	message_vision(CYN"$N�������Ҳ���ǿ�����¡���\n"NOR, this_object());
	message_vision(CYN"$N˵��ֻ����ͨ�콵̫Ϊ�ն񣬲��������������\n"NOR,this_object());
	return 1;
}
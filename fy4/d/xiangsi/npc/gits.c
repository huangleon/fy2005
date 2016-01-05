// annie 07.2003
// dancing_faery@hotmail.com

inherit NPC;
inherit F_MASTER;
#include <ansi.h>
#include <combat.h>

void smart_fight();
int leave();

void create()
{
        set_name("ͭ��", ({"master tongban", "tongban","master" }) );
		set("class","moon");

		create_family("��¹�", 3, "");
		set("nickname",CYN"�������幬���˵�"NOR);
		set("title","����칬");

        set("gender", "����");
        set("apprentice_available", 3);

		set("max_force",2000);
		set("force",2000);

		set("fly_target",3);	// �޷�3��....

        set("reward_npc", 1);
		set("difficulty", 2);
		set("per", 32);
		set("age",20);
		set("attitude","peaceful");

        set("combat_exp", 1000000);
        
		set("long","ͭ���������ߣ�����ִһյ���裬������˫�ۣ�������硣\n");

		set("chat_chance", 1);
		set("chat_msg", ({
		CYN"ͭ��΢һ���񣬱����۾����˼������ʩչ�������ۡ�������\n"NOR,
		CYN"ͭ��Ц��������ļ��գ���Ҳ���Լǵ�һЩ��\n"NOR,
		CYN"ͭ��˵�����뵱�������幬 ���� ͭ��(Tongban)�����µ�һ�������޵С�\n"NOR,
		CYN"ͭ���Ժ���˵�������뵱�꣬�������ٷ�һ���˲ţ�׷�ҵ�Ů�������ϻ�ɽ���ŵ�������ˮ����������\n"NOR,
		}) );


		set("inquiry",([
       		"����": 	"����ɱҵ��������Ե�������������£��о�ȴҲ����\n",
            "leave": (: leave :),
    	]) );

		set("guard_msg",CYN"$N�ȵ���Ī��Ϊ���������꣬����ݵ������ڴ˷�����\n"NOR);

		set("chat_chance_combat", 100);
		set("chat_msg_combat", ({
			   (: smart_fight() :),
		}) );

        set("rank_nogen",1); 
//		set("ranks",({ "С���","�����","СͷĿ","��ͷĿ","��ͷ��",RED"���"NOR,RED"��˧"NOR,HIR"��ɽ��"NOR }));
                
		set_skill("force", 140);    
		set_skill("dodge", 100);    
		set_skill("move", 100);    
		set_skill("parry", 120);    
		set_skill("literate", 100);
		set_skill("blade", 120);    
		set_skill("perception",100);
		set_skill("chanting",80);
		set_skill("spells", 100);
		set_skill("foreknowledge", 80);

		set_skill("snowforce",90);
		set_skill("chillblade",100);
		set_skill("stormdance",90);

	    map_skill("force","snowforce");
	    map_skill("blade","chillblade");
	    map_skill("parry","chillblade");
	    map_skill("move","stormdance");
	    map_skill("dodge","stormdance");
     	setup();

		carry_object(__DIR__"obj/fapao")->wear();
		carry_object(__DIR__"obj/snakeblade")->wield();

}

void reset()
{
	set("apprentice_available", 3);
	set("fly_target",3);
}

void attempt_apprentice(object ob)
{
	if( query("apprentice_available") ) 
	{
		if( find_call_out("do_recruit") != -1 )
				command("say ������һ��һ������\n");
		else
				call_out("do_recruit", 2, ob);
	} 
	else
		command("mian tongban");
}

int do_flatter(string arg)
{
	object me;
	me = this_player();
	if (!userp(me))
		return 0;
	if (arg != "tongban" && arg != "master tongban" && arg!="master")
		return 0;
	if (!me->query_temp("annie/flatter"))
		return 0;

	message_vision(CYN+me->name()+"ָ��ͭ�����̵�����ͭ���书������Ȼ���˿ɱȣ������Ÿ�ƨҲ������������������̣���\n"NOR,me);
	command("flatter master tongban");
	command("say Ҳ�գ�Ҳ�գ����㻹��һƬ���ģ����������������Ը���ҡ�");
	command("recruit " + me->query("id") );
	command("pat " + me->query("id") );
	command("mapi " + me->query("id") );
	me->delete_temp("annie/flatter");
	return 1;
}

void do_recruit(object me)
{
		command("hmm " + me->query("id") );
		command("mapi master tongban" );
		command("say ������ƨ��flatter tongban���������ͽ���ˣ��ɲ�Ҫ������ģ�");
		command("say ���������£���������пɣ�������Ͳ����ˣ��պ�Ҫ̫�౧Թ��");
		command("flatter" );
		me->set_temp("annie/flatter",1);

}
		
int recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) )
		ob->set("class", "moon");
	add("apprentice_availavble", -1);
}

void init()
{	
	::init();
	add_action("do_killing", "kill");
	add_action("do_flatter", "flatter");
    if( !query_heart_beat(this_object()) )
		set_heart_beat(1); 
	if (!this_player()->query_temp("annie/gits") && userp(this_player()))
	{
		if (query("fly_target"))
			add("fly_target",-1);
		if (query("fly_target"))
			ccommand("noairport");
		else
			ccommand("noairport master tongban");
	}
}

object select_opponent() 	
{
	object * enemy;
	int i;
	enemy = query_enemy();
	if(!sizeof(enemy))
		return 0;
	clean_up_enemy();
	if(!sizeof(enemy))
		return 0;
	for(i=0; i<sizeof(enemy); i++)
		if (userp(enemy[i]))
			return enemy[i]; // focus user. ; annie 6.25.03
	return enemy[random(sizeof(enemy))];
}


int kill_ob(object who)
{
	::kill_ob(who);
	smart_fight();
	return 1;
}

void smart_fight()
{
	object target;
	int i;
	target = select_opponent();
	i = query("combat_exp") * 100 / target->query("combat_exp") ;

	ccommand("exert yinlingkouming");
	ccommand("exert bingpojingbi");
	ccommand("perform dodge.shuangtianxuewu");
	set("force",2000);

	if (!query_temp("weapon"))
		if (ccommand("get twilight blade"))
			if (ccommand("wield twilight blade"))
				stop_busy();
	
	if (i > 180 && (userp(target) || query("test")))
		SKILL_D("chillblade")->perform_target(this_object(),"leidianjiaohong",target);
}

int leave()
{
    if (this_player()->query("class")!="moon") return 0;
	message_vision(CYN"$N������ɨ��$nһ�ۡ�\n"NOR, this_object(),this_player());
	message_vision(CYN"$N˵����Ȼ��һ��Ҫ�ߣ���Ҳ������ǿ��\n"NOR,this_object(),this_player());
	message_vision(CYN"$N˵��ֻ�����и��յľ��裬���Ƕ��޷����õ��ˡ�\n"NOR,this_object(),this_player());
    return 1;
}


/*
ͭ��Ŀǰ��ѧ��ʮ���ּ��ܣ�

  �������� (blade)                         - ����似 120/    0
�������߾� (chillblade)                    - ������� 100/    0
  ��Ծ����֮�� (dodge)                     - ������� 100/    0
  �ڹ��ķ� (force)                         - �����뻯 140/    0
  ռ��ѧ (foreknowledge)                   - ����С��  80/    0  <-- 16kar,ȥ��ƽ��5��move.... *doubt mingyue
  ����ʶ�� (literate)                      - ��Ȼ��� 120/    0
  �����Ṧ (move)                          - �������  95/    0��<-- �¸�master��Ҫ100lv
  ����ж��֮�� (parry)                     - ����似 120/    0
  �������֮�� (perception)                - ������� 100/    0
����ѩ�ľ� (snowforce)                     - ������� 100/    0
  ���� (spells)                            - ������� 100/    0	<-- ͭ��Ц��������ļ��գ���Ҳ���Լǵ�һЩ��
��������� (stormdance)                    - �������  90/    0  



*/

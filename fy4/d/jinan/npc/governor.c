// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
int yuefei();
int leave();

int jice();
int jice2();

void create()
{
    	set_name("������", ({ "master yin", "master","yin" }) );
    	set("long", "���ϳ�����ߵĹ٣����������ϵ�Ȩ��\n");
    	set("nickname", RED"��ͼ���ѧʿ"NOR);
    	set("class","official");
    	set("attitude", "heroism");
    	set("reward_npc", 1);
		set("difficulty", 35);
        set("chat_chance", 1);
        set("chat_msg", ({
                "�������������ϵ���͸��ҵ��з����������ˡ�����\n",
                "������ҡҡͷ�������������ˣ�û�������ѧ��������\n",
        }) );
    // Make this before create_family will prevent generation in title
    	set("rank_nogen",1);
    	create_family("��͢����",6,"̫��̫�� �ؼ��ϸ�");
    	set("student_title","��Ա");
    	set("ranks",({ "׼����","����","����","��ͳ��","ͳ��","��Ӫ��ͳ��",
                       "��Ӫͳ��","��Ӫ��ͳ��","���������ᶼָ��ʹ","�����������ᶼָ��ʹ",
                       "�����׾��������ݺ�","�����׾�������ݺ�",RED"��ǰ���ݺ�"NOR,
                       CYN"�����׾�������ָ��ʹ"NOR,YEL"�����׾������ָ��ʹ"NOR,BLU"��ǰ��ָ��ʹ"NOR,
                       CYN"�����׾�������ָ��ʹ"NOR,YEL"�����׾������ָ��ʹ"NOR,RED"��ǰ��ָ��ʹ"NOR }));
    	set("rank_levels",({ 32000,64000,128000,256000,384000,
                             512000,800000,1024000,1556000,
                             2048000,3652000,5000000,
                             6258000,8848000,10800000,
                             14580000,20048000,26244000 }));

	set("inquiry", ([
		"zonghengtianxia" : (: yuefei :),
		"�ݺ�����" : (: yuefei :),
		"yuefei" : (: yuefei :),
		"����" : (: yuefei :),
		"yue fei" : (: yuefei :),
		"�Ʋ�" : (: jice :),
		"ɱʯ��" : (: jice2 :),

		"leave" : (: leave :),
	]));
    	set("vendetta_mark", "authority");
    	set("guard_msg",HIW"$N�ȵ����󵨲��񣬾�Ȼ�����Ϸ���ǰ��Ұ���۳�͢����ô��\n"NOR);
    	 	
	set("age",55);
    	set("chat_chance_combat", 40);
    	set("chat_msg_combat", ({
        	(: perform_action, "unarmed.yuhuan" :),
        }) );
    	set("combat_exp", 90000000);
    	set_temp("apply/damage",500);
    	set_temp("apply/dodge",200);
    
    	set_skill("chanting",100);
    	set_skill("unarmed", 180);
    	set_skill("force",160);
    	set_skill("parry", 140);
    	set_skill("dodge", 140);
    	set_skill("changquan",220);
    	set_skill("yue-spear",120);
    	set_skill("manjianghong",130);
    	set_skill("move", 140);
    	set_skill("leadership",200);
    	set_skill("strategy",200);
    	set_skill("puti-steps",170);
    	set_skill("spear",200);
    	set_skill("perception", 100);
		set_skill("literate", 100);
		set_skill("foreknowledge",100);
		
    	map_skill("unarmed","changquan");
    	map_skill("dodge","puti-steps");
    	map_skill("parry","changquan");
    	map_skill("force","manjianghong");
    	map_skill("spear","yue-spear");

    	setup();
//    	if(random(4)==2) set("env/no_teach",1);
    	carry_object(__DIR__"obj/guanfu")->wear();
}

int yuefei(){
	object me;
	me = this_player();
	if (REWARD_D->check_m_success(me,"�ݺ�����")){
		message_vision("$N����$n�������ã�����һ�\n", this_object(),me);
		return 1;
	}
		
	
	if (REWARD_D->riddle_check(me,"�ݺ�����")==2)	{
//	if(me->query("marks/����������ƽǹ��")){
		message_vision("$N��$n˵��������Ȼ���Ѿ�ȥ���������ϣ�����ȥ��⿴���ҵ��ָ塣��\n", this_object(), me);
		return 1;
	}
	message_vision(CYN"\n$N����$n��̾��һ�������������µ���ĳ����������ݺ����£���Ҳ����ȫ������\n"NOR,
			this_object(), this_player());
	if (me->query_skill("strategy",1)< 150)
		message_vision(CYN"�ഫ�����ǽ��о��ñ�֮������ǹ��֮�С�����ú����б�����150�����ǡ�\n"NOR, this_player());
	else if (me->query_skill("yue-spear",1)<120)
		message_vision(CYN"�������ǹ�������ǳ���͸�û��ϣ���ˡ����裱��������\n"NOR,this_player());
	else
		{		
		message_vision(CYN"�м�İ��ء� ��˵������������������ƽ��֮�����㲻��ȥ��������\n"NOR, this_object());
		REWARD_D->riddle_set(this_player(),"�ݺ�����",1);
	//	this_player()->set("marks/���������ݺ�����", 1);
	}
	return 1;
}


int jice()
{
	object me;
	me = this_player();
	if(REWARD_D->riddle_check(me,"�䵱����") != 2 && REWARD_D->riddle_check(me,"�䵱����") != 3 )
		return 0;

	REWARD_D->riddle_set(me,"�䵱����",3);
	ccommand("say ��ɽ��������ɽ������");
	ccommand("consider");
	ccommand("say Ī����ħ�����ˣ�");
	ccommand("hmm");
	ccommand("say ����ȥ�����ϵ����ӣ���˵�������ţ�"HIG"��������"NOR CYN"Ҫ���ݻ����֡�"NOR);
	ccommand("say �Ȱ�����ɽׯ��ס������˼��Ӧ��֮�ߡ�");
	return 1;
}


int jice2()
{
	object me;
	me = this_player();
	if(REWARD_D->riddle_check(me,"�䵱����") != 4)
		return 0;

	REWARD_D->riddle_set(me,"�䵱����",5);
	ccommand("bite");
	ccommand("say ���ϵ����ӹ�Ȼ�ƻ���");
	ccommand("say ֻ������һ����ȥɱʯ�㣬�����бض���թ����");
	ccommand("consider");
	ccommand("say ����ȥ�䵱ɽ����ʯ����Σ���Ҫɱ������������������������������");
	return 1;
}


void attempt_apprentice(object me)
{
    	if( !me->query("class")||me->query("class")=="official")
    	{
			if (!REWARD_D->check_m_success( me,"ʧ���粨"))
			{
				command("hmm");
				command("say ���ٵ��з�����Ϊ�����ԣ����������˴˰���˵��");
			} else if( me->query_skill("strategy",1) >= 80 ) {
				command("smile");
				command("say �ܺã���͢��������֮ʱ��Ŭ���ɣ�\n");
        		command("recruit " + me->query("id") );
			} else 
				command("say ��ı���̫���ˣ���80��������ô����͢Ч����\n");
    	}
    	else 
    			command("say ��͢����Ҫ�����ֲ������ģ���������֮�ˣ�\n");
}

void recruit_apprentice(object ob)
{
    	if( ::recruit_apprentice(ob) ) {
        	ob->set("class", "official");
    		ob->set("vendetta_mark", "authority");
    	}

}


int accept_object(object who, object ob)
{
    if( ob->query("shangfang") ){
		this_object()->delete("env/no_teach");
		if (REWARD_D->riddle_check(who,"ʧ���粨")==5) {
			REWARD_D->riddle_done(who, "ʧ���粨",10,1);
			command("nod");
			command("say ������η���������㻹����ô�����ӣ���Ȼ������������");
			command("say ����������Դ����ǰ��������˵���ﾮ���й���㿡�");
			command("say ��֪С���������ǲ���׽Ӱ֮˵������ȥ��һ�ˣ�����������α��");
		       REWARD_D->riddle_set(who,"�ž�����",1);
		} else 
		{
			command("ah");
			command("say �󵨣�͵���Ϸ�ı�����Ȼ���ҵ�����թ��\n");
			kill_ob(who);
		}
		return 1;
	}
	
	if (ob->query("name")=="ͷ­��" && ob->query("id")=="skull" 
		&& REWARD_D->riddle_check(who,"�ž�����") == 2)	{
		if (!ob->query("recovered"))
		{
			command("consider");
			command("say ��Դ���ﾹȻ�������ôһ����ֵ�ͷ­�ǣ����´������Σ�");
			message_vision(CYN"
����������ͷ­�Ƿ��������ֿ���ҡҡͷ˵������֮��������̽�ó�������
Ϊ���ˣ�������������������ر���\n"NOR, who);
			return 0;
		}
		command("ack");
		command("say �⡢�⡢�⡢������ԭ�����ڷ����������䵱�������β��٣�");
		command("say ��������ʯ��Ǹ����Ҫ�⿪�����������ĵ������֡�
�ر����Ǹ��չ��ģ���ʱ�����Ų���ʱ���������ź�ġ�
�����㻹����ȥ����ɽׯһ�ˣ��һ��ɴ���������Ҳ��ǣ����\n\n");
		REWARD_D->riddle_set(who,"�ž�����",3);
		return 1;
	}

	if (ob->query("name")=="���ǽ�" && ob->query("real") 
		&& REWARD_D->riddle_check(who,"�ž�����") == 7)	{
		command("consider");
		REWARD_D->riddle_set(who,"�䵱����",1);
		REWARD_D->riddle_set(who,"�ž�����",8);

		command("say ����ȥ�ѽ��ø��ϵ����ӣ���������ô˵��");
		command("say Ȼ���������ң�����������������һ����"HIG"�Ʋ�"NOR"��\n\n");
		return 0;
	}



        return 0;
}


void init()
{
	object ob;
	::init();
	add_action("do_killing", "kill");
	if(interactive(ob = this_player()) && !is_fighting()) {
		remove_call_out("greeting");
		call_out("greeting", 1, this_player());
	}
}

void greeting(object ob) {
	if(!ob || environment(ob) != environment()) return;
	if (this_object()->query("env/no_teach")==1 && ob->query("family/master_id")=="master yin")
	message_vision("$N�����˵�������з��������Ϸ�����û��˼���㡣\n",this_object());
}


int leave() {
	if (this_player()->query("class")!="official") return 0;
	message_vision(CYN"$N��ɫ��������Ч��͢���Ҿ�����֮�£���ô�ܰ�;�����ء���\n"NOR, this_object());
	message_vision(CYN"$N˵����ִ��Ҫ����Ҳ����ǿ��ֻ�ǴӴ˾���һ��ƽ�񣬳�֮͢����Ҳ��Ȩ���ʡ�\n"NOR,this_object());
	message_vision(CYN"$N˵����ԧ��ȭҲ������ʹ����˼����˼��\n"NOR,this_object());
	return 1;
}
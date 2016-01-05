// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
string ask_for_join();

void create()
{
    set_name("�λ���ʦ", ({ "master can", "master", "can" }) );
    set("long", "
�λ���ʦ���˹���ʦ��ʦ�ܣ�����������Ժ�Լ����ӳ�����ȣ�
ֻ�а��˲λ���ʦ�����������������������С�\n");
    	set("gender", "����");
    	set("age", 74);
    	set("attitude", "peaceful");
    	set("class", "bonze");
    	set("apprentice_available", 3);
    	set("reward_npc", 1);
    	set("difficulty", 5);
    	    	
	set("guard_msg",HIW"$N�ȵ��������ӷ�,����������������ȴҲ���������꣬ʩ�����ˣ���\n"NOR);
    	set("combat_exp", 2000000);
    	set("score", 9000);

    	set("inquiry", ([
        	"���" : (: ask_for_join :),
        	"����" : (: ask_for_join :),
        	"apprentice" : (: ask_for_join :),
        ]) );

    	set_skill("staff", 180);
    	set_skill("unarmed", 160);
    	set_skill("dabei-strike",150);
    	set_skill("force", 150);
    	set_skill("dodge", 150);
    	set_skill("literate", 150);
    	set_skill("chanting", 150);
    	set_skill("parry", 150);
    	set_skill("magic", 150);
	set_skill("cloudstaff", 150);
    	set_skill("lotusforce", 150);
    	set_skill("buddhism", 150);
    	set_skill("nodust-steps",150);
    	set_skill("essencemagic",150);
    	set_skill("perception", 100);
	set_skill("foreknowledge", 100);
 	set_skill("move", 150);
	
    	map_skill("staff", "cloudstaff");
    	map_skill("parry", "cloudstaff");
    	map_skill("force", "lotusforce");
    	map_skill("dodge","nodust-steps");
    	map_skill("unarmed","dabei-strike");
    	map_skill("magic","essencemagic");
    
     	set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.qianshouqianbian" :),
                (: perform_action, "staff.longxianyuye" :),
        }) );
    
    
    	create_family("�˹�����", 4, "ס��");
		set("rank_nogen",1);
		set("rank_levels",({ 16000, 32000,64000, 128000,
					256000,512000,1024000,1536000,2048000,
					3064000,4096000, 5120000,6144000,8192000,
					9999999}));
		set("ranks",({"Сɳ��","С����","��ɽɮ","����ɮ","����ɮ","����ɮ","����ɮ","����ɮ",
		"���´�ʦ","�����޺�","�������","������ɮ",YEL"����ʥɮ"NOR,YEL"�������"NOR,
		YEL"�����ڴ���"NOR,HIY"����������"NOR}));				
		
    	setup();
    	carry_object(__DIR__"obj/staff")->wield();
    	carry_object("/obj/armor/cloth")->wear();

}


string ask_for_join()
{
    	object me;

    	me = this_player();
	if (me->query("family/master_id")!="master dingbang"
		|| me->query("family/master_name") != "�����ʦ"
		|| me->query("class") != "bonze") {
		command("shake");
		command("say ʩ��������ң���������ʦ�ܶ��ĥ�����꣬��Щ�̻�֮����");
		return "\n";
	}
	
	if (me->query("once_menpai/bonze") && me->query("class")!="bonze") {
		command("shake");
		command("say ʩ�������޳���û�����֮�ġ�\n");
		return "\n";
	}
 	if(me->query("marry") && !me->query("jiebai")){
		message_vision("$Ņͷ���˿�$n����λʩ������δ����������ذɡ�\n", 
				this_object(), me);
		return "\n";
	}	
    	
    	if( (string)me->query("gender") != "����" )
        	return "�����ӷ�Ůʩ�����������������㵽����ȥ��Ȱɡ�\n";
    	
    	if( (string)me->query("family/master_name")=="�λ���ʦ" || me->query("marks/���"))
        	return "�����ӷ�����ͬ�ǳ����ˣ��ιʸ����Ŀ������Ц��\n";
    	
    	if (me->query_skill("buddhism",1)< 100) 
    		return "�����ӷ�ʩ���Ĵ�˷����л������ң��裱����������\n";

    	me->set_temp("pending/join_bonze", 1);
    	return "�����ӷ����գ����գ�ʩ������������ҷ������(kneel)�ܽ䡣\n";
}

int do_kneel()
{
    	string *prename =
        	({ "��", "��", "Բ", "��", "��", "��",
           		"��", "��", "��", "��" });
    	string name, new_name;

    	if( !this_player()->query_temp("pending/join_bonze") ) return 0;
    	message_vision(
        	HIC "$N˫�ֺ�ʮ�����������ع���������\n\n"
        	"$n������ƣ���$Nͷ�������Ħ���˼��£���$N��ͷ���������£�\n\n"NOR,
        	this_player(), this_object() );
    	name = this_player()->query("name");
//    	new_name = prename[random(sizeof(prename))] + name[0..1];
//    	command("say �ӽ�������ķ�������" + new_name + "��");
    	command("smile");
    	this_player()->delete_temp("pending/join_bonze");
    	this_player()->delete_temp("pending/apprentice");
//    	this_player()->set("name", new_name);
    	this_player()->set("class", "bonze");
    	this_player()->set("marks/���",1);
    	return 1;
}

void attempt_apprentice(object me)
{
if (me->query("family/master_id")!="master dingbang"
		|| me->query("family/master_name") != "�����ʦ"
		|| me->query("class") != "bonze") {
		command("shake");
		command("say ʩ��������ң���������ʦ�ܶ��ĥ�����꣬��Щ�̻�֮����");
		return;
	}
	
	if (me->query("once_menpai/bonze") && me->query("class")!="bonze") {
		command("shake");
		command("say ʩ�������޳���û�����֮�ġ�\n");
		return;
	}
   	if(me->query("marry")&& !me->query("jiebai")){
		message_vision("$Ņͷ���˿�$n����λʩ������δ����������ذɡ�", 
				this_object(), me);
		return ;
	}	
    	
    	if( (string)me->query("gender") != "����" ) {
        	command("say �����ӷ�Ůʩ�����������������㵽����ȥ��Ȱɡ�");
        	return;
        }
    	
    	if( (string)me->query("family/master_name")=="�λ���ʦ" ){
        	command("say �����ӷ�����ͬ�ǳ����ˣ��ιʸ����Ŀ������Ц��");
        	return;
        }
    	
    	if (me->query_skill("buddhism",1)< 100) {
    		command("say �����ӷ�ʩ���Ĵ�˷����л������ң��裱����������");
    		return;
    	}

		if (!REWARD_D->check_m_success( me,"�߲ʶд�")){
			command("say ʩ����Ȼ�������Ե��ֻ����ɮ��һ����δ�ˡ�");
			command("say �˹�������һ��ɮ��ʵ��������ʵ��ʵ����ʵ��������棬��һ���ء�");
			command("say ��������ʵ���������������˶�Ź��ʵ���ҵ������ޡ�");
			command("say ����ȥ����һ�ԣ�����֪�Ѷ��˾����ˣ����򲻿�����������");
			return;
		}
				
		if( !me->query("marks/���")) {
        	command("say �����ӷ�ʩ���������ˣ�Ը����ţ�������ȳ��ҡ�");
        	return;
        }
        	
    	command("say �����ӷ����գ����գ�");
        command("recruit " + me->query("id") );
}

int accept_fight(object me)
{
    	if( (string)me->query("class")=="bonze" )
        	command("say �����ӷ𣡳����˽��ǿ�񶷣����Ĳ���Υ����档");
    	else
        	command("say ʩ����Ȼ�����գ�����������ǣ�Ҳ���ؽ����ˡ�");

    	return 0;
}

void init()
{	
	::init();
	add_action("do_killing", "kill");
	add_action("do_kneel","kneel");

}

	

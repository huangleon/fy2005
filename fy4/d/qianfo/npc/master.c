// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void smart_fight();
int leave();
void create()
{
    set_name("�˹���ʦ", ({ "master xing", "master", "xing" }) );
    set("gender", "����");
    set("nickname", HIY "���ޱ�"NOR);
    set("long", "�˹�����ס�֣����������������е���ɮ��\n");
    set("age", 74);
    set("attitude", "peaceful");
    set("class", "bonze");
    set("apprentice_available", 3);

    create_family("�˹�����", 3, "ס��");
    set("rank_nogen",1);
	set("rank_levels",({ 16000, 32000,64000, 128000,
					256000,512000,1024000,1536000,2048000,
					3064000,4096000, 5120000,6144000,8192000,
					9999999}));
					
	set("ranks",({"Сɳ��","С����","��ɽɮ","����ɮ","����ɮ","����ɮ","����ɮ","����ɮ",
		"���´�ʦ","�����޺�","�������","������ɮ",YEL"����ʥɮ"NOR,YEL"�������"NOR,
		YEL"�����ڴ���"NOR,HIY"����������"NOR}));				
    set("reward_npc", 1);
    set("difficulty", 10);

    set("chat_chance_combat", 70);
    set("chat_msg_combat", ({
	(: smart_fight() :),
      }) );
    set("fly_target",1);

    set("combat_exp", 20000000);
    set("guard_msg",HIW"$N�ȵ��������ӷ�,����������������ȴҲ���������꣬ʩ�����ˣ���\n"NOR);

    set_temp("apply/haste",400);
    set_temp("apply/armor", 200);
    set_temp("apply/damage", 200);
    set("score", 9000);

    set_skill("force", 180);
    set_skill("chanting", 200);
    set_skill("magic", 200);
    set_skill("unarmed", 170);
    set_skill("literate", 150);	
    
    set_skill("parry", 160);
    set_skill("staff", 250);
    set_skill("dodge", 160);
    set_skill("move",160);
    
    set_skill("foreknowledge", 100);
    set_skill("perception", 100);

    set_skill("cloudstaff", 180);
    set_skill("lotusforce", 150);
    set_skill("buddhism", 220);
    set_skill("essencemagic", 220);
    set_skill("nodust-steps",200);
    set_skill("dabei-strike",180);

    map_skill("staff", "cloudstaff");
    map_skill("parry", "cloudstaff");
    map_skill("force", "lotusforce");
    map_skill("magic", "essencemagic");
    map_skill("dodge","nodust-steps");
    map_skill("unarmed","dabei-strike");
    map_skill("move","nodust-steps");

    set("inquiry", ([
	"leave" : (: leave :),
      ]));   	

    setup();
    carry_object(__DIR__"obj/buddha_staff")->wield();
    carry_object("/obj/armor/cloth")->wear();

}

void attempt_apprentice(object ob)
{
    if(ob->query("marry") && !ob->query("jiebai")){
	message_vision("$Ņͷ���˿�$n����λʩ������δ����������ذɡ�\n", 
	  this_object(), ob);
	return;
    }	
    if( (string)ob->query("gender") != "����" ) {
	command("say �����ӷ�Ůʩ����Ҫ�����ɿ���Ц��");
	return;
    }
    if (ob->query("family/master_id")!="master can"
      || ob->query("family/master_name") != "�λ���ʦ"
      || ob->query("class") != "bonze") {
	command("shake");
	command("say ���Ĳ�������ͽ��");
	return;
    }

    command("say �����ӷ����գ����գ�");
    if (ob->query_skill("buddhism",1)<150) {
		command("say ��ķ���Ϊ̫�ͣ�������ȥ����������ɡ����裱��������");
		return;
    }

	if (!REWARD_D->check_m_success( ob,"����")) {
		command("say ��ɮ����һ�����У�����ǰ���ѳ���˧"WHT"�ɸ봫��"CYN"���������ɮǰȥ��");
		ob->set_temp("marks/xg_master",1);
		return;
	}	
		
    command("say ��Ȼ�ǲλ���ʦ�Ƽ����㣬���ľ���������Ϊͽ��");
    command("recruit " + ob->query("id") );

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

}


int leave() {
    if (this_player()->query("class")!="bonze") return 0;
    message_vision(CYN"$N���Ƶ��������ӷ𣬼�����Ե���α��������Ժ�Ҳ��Ҫ�ٻ����ˡ�\n"NOR, this_object(),this_player());
    message_vision(CYN"$N˵�����ŵ���ͨ�����ķ��ǵ��Ӳ���ʹ�á�\n"NOR,this_object(),this_player());
    return 1;
}

smart_fight()
{
    int i;
    object *enemy, who;
    who = this_object();
    enemy = this_object()->query_enemy();
    i = sizeof(enemy);
    if (i>3) {
	command("conjure light_sense");
	return;
    }
    who->perform_action("staff.longxianyuye"); 
    return;
} 

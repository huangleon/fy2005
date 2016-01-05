#include <ansi.h>
inherit QUESTNPC;
inherit F_MASTER;
//inherit SSERVER;

void create()
{
	set_name("�����", ({ "jiang biehe", "jiang" }) );
	set("gender", "����" );
	set("nickname",HIM"���ϴ���"NOR);
        set("title","���ׯ   ����ׯ��");
        set("quality","evil");
	set("age", 45);
	set("int", 25);
	set("per", 20);
	set("str", 30);
	set("dur", 35);
	set("cor", 35);
	set("fle",20);
	set("long",
"һ��ü��Ŀ�㣬������񣬷��������Ѽ���������ʿ��\n");
        set("force_factor", 35);
	set("max_force",3000);
	set("force",5000);
        set("combat_exp", 7000000);
        set("score", -16000);
        set("hunting",1);
        set("strategy","default");
        set("w_type","sword");
        set_skill("unarmed", 250);
        set_skill("force", 280);
        set_skill("parry", 360);
        set_skill("literate", 130);
        set_skill("hanshan-sword",200);
        set_skill("yue-strike",150);
        set_skill("sword",150);
	set_skill("dodge", 220);
	set_skill("wuchen-steps",200);
//	set_skill("wuchenforce",150);
	map_skill("sword","hanshan-sword");
	map_skill("unarmed", "yue-strike");
	map_skill("parry","hanshan-sword");
	map_skill("dodge","wuchen-steps");
	map_skill("force","wuchenforce");
	set("chat_chance",2);
	set("chat_msg",	({
	"�����̾����'����'���������ս����������ķ��ŵĵ��ͣ�Ҳ��ǧ�������������� 
�����������ӣ���ΪС��ȡ'����'�����֣���Ҳ��Ϊ�˼������ġ�\n",
	})	);  
 
	setup();
	carry_object("/obj/armor/cloth")->wear();
	carry_object("/obj/weapon/sword")->wield();
	add_money("gold",10);
	
}



int universe_busy(object *all_enm)
{
	int i,*busy_object;
	string e_name,e_name1;

	
	set("class","quanli");
//	delete("busy_object");
	for(i=0;i<sizeof(all_enm);i++)
	{
		if(!objectp(all_enm[i])) continue;
		add("busy_object/"+all_enm[i]->get_id(),1);
		if(all_enm[i]->query_busy())
			continue;
		say("haha1\n");
		SKILL_D("wuchen-steps")->perform_target(this_object(),"changmengwuchen",all_enm[i]);

		
	}
	
	delete("class");
	if(!query_busy())
		return 0;
	return 1;
}
	
int normal_busy(object opp)
{
	if(random(100)>90)
	{
		set("class","quanli");

		SKILL_D("wuchen-steps")->perform_target(this_object(),"changmengwuchen",opp);

		delete("class");
	}
	return 1;
}

int normal_att(object opp)
{
	if(random(100)<50) return 0;
	set("force_factor",90);
	SKILL_D("hanshan-sword")->perform_target(this_object(),"yueyinghanshan",opp);

	return 1;
}

int alert_busy(object opp)
{

	if(random(100)>50)
	{
		set("class","quanli");

		SKILL_D("wuchen-steps")->perform_target(this_object(),"changmengwuchen",opp);

		delete("class");
	}
	return 1;
}

int alert_att(object opp)
{
	if(random(100)<30) return 0;	
	set("force_factor",130);
	SKILL_D("hanshan-sword")->perform_target(this_object(),"yueyinghanshan",opp);

	return 1;
}

int flee_busy(object opp)
{
	if(random(100)>20)
	{
		set("class","quanli");

		SKILL_D("wuchen-steps")->perform_target(this_object(),"changmengwuchen",opp);

		delete("class");
	}
	return 1;
}

int flee_att(object opp)
{
	if(random(100)<20) return 0;	
	set("force_factor",170);
	SKILL_D("hanshan-sword")->perform_target(this_object(),"yueyinghanshan",opp);
	return 1;
}

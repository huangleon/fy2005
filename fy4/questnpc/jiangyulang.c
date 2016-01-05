#include <ansi.h>
inherit QUESTNPC;
inherit F_MASTER;
//inherit SSERVER;

void create()
{
	set_name("������", ({ "jiang yulang", "jiang" }) );
	set("gender", "����" );
	set("nickname",HIR"С����"NOR);
        set("title","���ׯ     ��ׯ��");
        set("quality","evil");
	set("age", 21);
	set("int", 25);
	set("per", 20);
	set("str", 30);
	set("dur", 35);
	set("cor", 35);
	set("fle",20);
	set("long",
"�⺢������üĿ���㣬��ȴ��Ƽ��ݣ����Ƿ�����ȫ��ģ����һ˫�۾������� 
����ʱ��¶���ֵ����Ц�ݡ�\n");
        set("force_factor", 35);
	set("max_force",3000);
	set("force",5000);
        set("combat_exp", 4000000);
        set("score", -16000);
        set("strategy","conservative");
        set("alert_rate",70);
        set("flee_rate",50);
        set("hunting",1);
        set_skill("unarmed", 250);
        set_skill("force", 280);
        set_skill("parry", 260);
        set_skill("literate", 130);
	set_skill("dodge", 250);
	set_skill("shadowsteps", 150);
	set_skill("qiankunstrike",400);
	set_skill("meihua-shou",150);
	map_skill("unarmed", "qiankunstrike");
	map_skill("dodge","shadowsteps");
	set("chat_chance",2);
	set("chat_msg",	({
	"������ͻȻһЦ������������С�㡣���ٺ٣������Է����µ�һ�����ˣ����������ҵļơ�\n",
	})	);  

	setup();
	carry_object("/obj/armor/cloth")->wear();
	carry_object(__DIR__"obj/lihuading");
	add_money("gold",10);
}


	
int normal_busy(object opp)
{
	if(random(100)>90)
	{
		set("class","legend");
		map_skill("unarmed","meihua-shou");
		SKILL_D("meihua-shou")->perform_target(this_object(),"meihai",opp);
		map_skill("unarmed","qiankunstrike");
		delete("class");
	}
	return 1;
}

int normal_att(object opp)
{
	if(random(100)<50) return 0;

	set("force_factor",90);
	say("90\n");
	if(random(10)>5)
	{
		set("class","taoist");
		SKILL_D("qiankunstrike")->perform_target(this_object(),"niuzhuanqiankun",opp);
		delete("class");
	}
	else
	{
		set("class","swordsman");
		SKILL_D("shadowsteps")->perform_target(this_object(),"lianhuanjiao",opp);
		delete("class");
	}
	return 1;
}

int alert_busy(object opp)
{

	if(random(100)>50)
	{

		set("class","legend");
		map_skill("unarmed","meihua-shou");
		SKILL_D("meihua-shou")->perform_target(this_object(),"meihai",opp);
		map_skill("unarmed","qiankunstrike");
		delete("class");
	}
	return 1;
}

int alert_att(object opp)
{
	if(random(100)<30) return 0;	
	set("force_factor",130);
	say("130\n");
	if(random(10)>5)
	{
		set("class","taoist");
		SKILL_D("qiankunstrike")->perform_target(this_object(),"niuzhuanqiankun",opp);
		delete("class");
	}
	else
	{
		set("class","swordsman");
		SKILL_D("shadowsteps")->perform_target(this_object(),"lianhuanjiao",opp);
		delete("class");
	}
	return 1;
}

int flee_busy(object opp)
{
	if(random(100)>20)
	{
	if(present("needle box",this_player()))
	{
		message_vision("��������Цһ�����ӻ����ͳ�һ���Ƴγε�ԲͲ����\n",this_player());
		command("shoot "+opp->get_id());
	}
		set("class","legend");
		map_skill("unarmed","meihua-shou");
		SKILL_D("meihua-shou")->perform_target(this_object(),"meihai",opp);
		map_skill("unarmed","qiankunstrike");
		delete("class");
	}
	return 1;
}

int flee_att(object opp)
{

	say("150\n");
	set("force_factor",150);
	if(random(10)>5)
		{
			set("class","taoist");
			SKILL_D("qiankunstrike")->perform_target(this_object(),"niuzhuanqiankun",opp);
			delete("class");
		}
		else
		{
			set("class","swordsman");
			SKILL_D("shadowsteps")->perform_target(this_object(),"lianhuanjiao",opp);
			delete("class");
		}
	return 1;
}

#include <ansi.h>
inherit QUESTNPC;

void create()
{
        set_name("�", ({ "li huai", "li" }) );
        set("nickname",HIC"�ɵ��ּ��ɵ�"NOR);
        set("title","����һ��     ����");
        set("long",
                "����������糾���������ڣ�����ȥʮ�����ǣ�������ȥȴ����˵���������š�
\n");
    set("attitude", "heroism");
    set("str", 40);
    set("cor", 70);
    set("cps", 12);
	set("agi",32);
	set("int",20);
	set("per",41);
	set("con",25);
	set("dur",60);
	set("fle",85);
	set("tol",70);
	set("chat_chance",10);
	set("chat_msg",	({
"�ʱ��Ŀ����ͣ�ʱ����Ц������Ϊʲô��Ϊʲô���ң�Ϊʲô�ǿɿɣ�
ֻ��������������ֻ��ʤ������ܣ�Ϊʲô���ѵ�����Ϊ����С��ɵ��ĺ��ˣ���\n"
				})  );
                set("quality","good");
	set("strategy","hero");
	set("hunting",1);
	set("alert_rate",80);
	set("flee_rate",60);

        set("combat_exp", 6000000);
		set("max_gin",8000);
		set("max_kee",15000);
		set("max_sen",10000);
        set_skill("throwing", 280);
		set_skill("feidao",320);
		set_skill("force",70);
        set_skill("dodge", 280);
        set_skill("tanzhi-shentong",180);
		set_skill("move",180);
		set_skill("parry",760);
		set_skill("huanhua-steps",200);
		map_skill("dodge","huanhua-steps");
	map_skill("throwing","tanzhi-shentong");

	setup();

        carry_object("/d/fugui/npc/obj/cloth")->wear();
		carry_object(__DIR__"obj/leaf")->wield();
}


int universe_busy(object *all_enm)
{
	int i;
	string e_name,e_name1;
	set("class","huashan");
	
	for(i=0;i<sizeof(all_enm);i++)
	{
		if(!objectp(all_enm[i])) continue;
		add("busy_object/"+all_enm[i]->get_id(),1);
		if(all_enm[i]->query_busy())
			continue;
		if(random(all_enm[i]->query("combat_exp"))>3000000)
			continue;
		SKILL_D("tanzhi-shentong")->perform_target(this_object(),"tanzhijinghun",all_enm[i]);
		stop_busy();
		
	}
	
	delete("class");
	if(!query_busy())
		return 0;
	return 1;
}
	

int normal_att(object opp)
{
	if(random(100)<50) return 0;
	set("force_factor",90);
	SKILL_D("tanzhi-shentong")->perform_target(this_object(),"mantianhuayu");

	return 1;
}

int alert_att(object opp)
{
	if(random(100)<30) return 0;	
	set("force_factor",130);
	SKILL_D("tanzhi-shentong")->perform_target(this_object(),"mantianhuayu");

	return 1;
}


int flee_att(object opp)
{
	if(random(100)<20) return 0;	
	set("force_factor",170);
	if(random(10)>5)
		SKILL_D("tanzhi-shentong")->perform_target(this_object(),"mantianhuayu");
	else
	{
		map_skill("throwing","feidao");
		SKILL_D("feidao")->perform_target(this_object(),"xiaoli-feidao",opp);
		map_skill("throwing","tanzhi-shentong");
	}
	return 1;
}
















/*







int accept_object(object me,object obj)
{
	if(obj->query("keke"))
	{
		message_vision("$N����һ��ս�飬˫Ŀ��죬���һ���Ц������������ƴ���಻ֹ��\n",this_object());
		obj->destruct();
		call_out("obj_drunk",10+random(10),this_object(),0);
		return 1;
	}
	return 0;
}

void do_drunk(object obj);
void obj_drunk(object obj,int i)
{	
	
	message_vision("$N����ƴ���������ƴ�������й�ơ�\n",obj);
	i++;
	if (i<2) call_out("obj_drunk",10+random(10),obj,i);
	else do_drunk(obj);
}

void do_drunk(object obj)
{	int busy_time;
	message_vision("$N���ˣ�$N��û�б��ˡ��ʵ���ʧ�⡢ʧ�ܣ�$Nֻ����������һ��$P�����ܽ�������⣬����$N���ˣ����׵����ˡ�",obj);
	busy_time=6+random(4);
	obj->start_busy(100);
	call_out("obj_revive",busy_time,obj);
}

void obj_revive(object obj)
{
	if (objectp(obj))
	{
		message_vision("$N�������ѹ����ˡ�\n",obj);
		obj->stop_busy();
	}

}



 
*/
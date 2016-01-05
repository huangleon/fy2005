#include <ansi.h>
inherit QUESTNPC;
inherit F_MASTER;
//inherit SSERVER;

void create()
{
	set_name("��ͩ��", ({ "du tongxuan", "du" }) );
	set("gender", "����" );
	set("nickname",BLU"����ѧʿ"NOR);
        set("title","Ȩ�㾩��     �ϰ�");
        set("quality","evil");
	set("age", 47);
	set("int", 25);
	set("per", 20);
	set("str", 40);
	set("dur", 35);
	set("cor", 35);
	set("fle",20);
	set("long",
"���˺ܸߣ����ݣ�������������̬�ȼ�˹�ģ�����䲻��������ȴ�Ѱ�
�ף�һ���������������ϣ��·�������ֲ��ݣ�ȴ�ִ����߷����ϣ�����
�����Ҷ�����˿�����ӡ�\n");
        set("force_factor", 35);
	set("max_force",2000);
	set("force",2000);
        set("combat_exp", 3300000);
        set("score", 12000);
        set_skill("unarmed", 180);
        set_skill("force", 80);
        set_skill("parry", 160);
        set_skill("literate", 130);
	set_skill("dodge", 150);
	set_skill("puti-steps",150);
	set_skill("changquan", 290);
	map_skill("unarmed", "changquan");
	map_skill("dodge","puti-steps");
	set("class","official");
 
	setup();
	carry_object(__DIR__"obj/bluecloth")->wear();
	carry_object(__DIR__"obj/baiyubi");
	carry_object(__DIR__"obj/yubanzhi");
	add_money("gold",5);
}

int normal_busy(object opp)
{
	if(random(opp->query("combat_exp"))>1500000)
		return 0;
	if(opp->query_temp("weapon"))
		message_vision(HIB"��ͩ��˫�۰�ʩ�ھ�������$N�ı���ճ�����ϣ���\n"NOR,opp);
	else
		message_vision(HIB"��ͩ��˫�۰�ʩ�ھ�������$N�ĳ���ճ�����ϣ���\n"NOR,opp);
	opp->start_busy(3);
	return 1;
}

int normal_att(object opp)
{
	if(random(100)>70)
	command("perform yuhuan "+opp->get_id());
	return 1;
}

int alert_busy(object opp)
{
	if(random(opp->query("combat_exp"))>2500000)
		return 0;
	if(opp->query_temp("weapon"))
		message_vision(HIB"��ͩ��˫�۰�ʩ�ھ�������$N�ı���ճ�����ϣ���\n"NOR,opp);
	else
		message_vision(HIB"��ͩ��˫�۰�ʩ�ھ�������$N�ĳ���ճ�����ϣ���\n"NOR,opp);
	opp->start_busy(3);
	return 1;
}

int alert_att(object opp)
{
	if(random(100)>50)
	command("perform yuhuan "+opp->get_id());
	return 1;
}

int flee_busy(object opp)
{
	if(random(opp->query("combat_exp"))>4000000)
		return 0;
	if(opp->query_temp("weapon"))
		message_vision(HIB"��ͩ��˫�۰�ʩ�ھ�������$N�ı���ճ�����ϣ���\n"NOR,opp);
	else
		message_vision(HIB"��ͩ��˫�۰�ʩ�ھ�������$N�ĳ���ճ�����ϣ���\n"NOR,opp);
	opp->start_busy(3);
	return 1;
}

int flee_att(object opp)
{
	if(random(100)>10)
	command("perform yuhuan "+opp->get_id());
	return 1;
}
/*
object offensive_target(object me)
{
	int sz;
	object *enemy;

	enemy = me->query_enemy();
	if( !enemy || !arrayp(enemy) ) return 0;

	sz = sizeof(enemy);
	if( sz > 4 ) sz = 4;

	if( sz > 0 ) return enemy[random(sz)];
	else return 0;
}


*/

#include <ansi.h>

inherit NPC;
int tell_him();
int well();

void create()
{
	set_name("��Ա���Ů��", ({ "jianu" }) );
	set("gender", "Ů��" );
	set("age", 15);
	set("combat_exp", 3500);
	set("attitude", "friendly");
	set("per",30);
    set("chat_chance", 3);
    set("chat_msg", ({
                "��Ա���Ů���ʵ�������˭ѽ��\n",
                "��Ա���Ů���������ǲ����ҵ��ĺ����ѣ�\n",
        }) );
        set("inquiry", ([
                "��Ա��" : 	(: tell_him :),
                "��" : 	(: tell_him :),
                "jia" : 	(: tell_him:),
                "��"	  : 	(: well :),
                "�ݾ�"	  : 	(: well :),
                "well":  	(: well :),
                "��һ��": 	(: well :),
        ]));
	setup();
	carry_object("/obj/armor/cloth")->wear();
}

int tell_him()
{
 	object me;
 	me = this_player();
 	if(me->query_temp("marks/cured_jia")) 
	{
 		tell_object(me,"
��Ů�����ҵ����Ǹ���Ϊ��������ܱ������ˣ�����������й�����Ļ������
�����ˣ���һ������취ɱ����ġ�\n");
 	} else 
		tell_object(me,"��Ů���������ҵ�ѽ���⻹���ʣ�\n");
	return 1;
}


int well ()	{
 	object me;
 	me = this_player();
 	
 	command("say �������úܣ�óóȻ��ȥ�˳ɻ�ˤ����\n");
 	
 	if(me->query_temp("marks/cured_jia")) 
	{
 		tell_object(me,CYN"��Ů����������������ҽ�����ҵ��ķ��ϣ��Ȼ���Ҿ�����������һ�ѡ�\n"NOR);
 		me->set_temp("marks/asked_jianu",1);
 	} 
	return 1;

}
#include <ansi.h>
inherit NPC;  
int tell_test();

void create()
{
        set_name("ˮ���", ({ "shui lingguang","shui","lingguang" }) );
        set("gender", "Ů��");
        set("age", 18);
		set("long","��������ݣ�������Ȼ���ű��飬ȴֻ�Ǵ����ĳ���\n");
		set("combat_exp", 50000); 
		set("per",50);
		set("attitude", "friendly");
		set("rank_info/respect", "С��Ů"); 
        set("inquiry", ([
			"������":(: tell_test:),
			"tie zhongtang" : (: tell_test:),
			"tie" : (: tell_test:)
        ]) );
		set("chat_chance", 1);
        set("chat_msg", ({
                "ˮ������һ���������С��������˶�������ô��\n"
        }) ); 
        setup(); 
		carry_object("/obj/armor/cloth")->wear();
	
}


int tell_test()
{
	object	me,silkbook;
	me = this_player(); 
	if( query_temp("mark/been_get") > 5) 
	{
		command("say ����������Ѫ�����ŵ��������ţ����ں��ⳣ�����ϡ�");
		return 1;
	}
	if(me->query_temp("mark/silkbook")+120 < time() )
	{
		command("say ����������Ѫ�����ŵ��������ţ����ں��ⳣ�����ϡ�");
		command("say ��������������д��һ���飬����ת����" );
		silkbook=new(BOOKS"skill/jiayiforce_50");
		silkbook->move(me);
		me->set_temp("mark/silkbook",time());
		add_temp("mark/been_get",1);
	}
	else
	{
		command( "say ��ô�������Ұ�����ȥ��" );
	}
	return 1;
}


void reset()
{   
    	delete_temp("mark/been_get");
}

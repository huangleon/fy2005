inherit NPC;
#include <ansi.h>

int do_duel();

void create()
{
		set_name("�̵��ڶ�", ({ "pan deng"}) );
		set("gender", "����" );
		set("title",HIY"�������"NOR);
		set("age", 70+random(10));
		set("class","lama");        
		set("long",
			"���ø�ɮ���˴ξ��ڵ�������,��ͼһͳ���֡�\n"
			);
		set("class","lama");
	    set("combat_exp", 4500000);
	    set("score", 900);
	    set("reward_npc", 1);
		set("difficulty",5);
		
		set("inquiry", 	([
			"�ϻ�����":		(: do_duel :),
				
			]));
			
		set("no_busy",5);
	        	
		set("chat_chance", 1);
        set("chat_msg", ({
                "�̵��ڶ�˵���ٺ٣���ʵ���ֻ����С�ӣ������ֵ����������ܸĳɡ��ƺ�����
�ǿ�������˼��\n",
                }) );
        
		set_skill("iron-cloth", 200);
	  	set_skill("unarmed", 200);
		set_skill("dragonstrike", 200);
		set_skill("force", 200);
		set_skill("dragonstrike", 200);
		set_skill("spells",200);
		set_skill("parry",200);
		set_skill("kwan-yin-spells",200);
		set_skill("jin-gang",150);
		set_skill("perception",200);
		set_skill("nodust-steps",200);
		set_skill("dodge",200);
		map_skill("dodge","nodust-steps");		
		map_skill("iron-cloth","jin-gang");
		map_skill("spells","kwan-yin-spells");
		map_skill("unarmed", "dragonstrike");
		map_skill("force", "bolomiduo");
    	
	
/*        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
               (: smart_fight() :),
        }) );*/

		setup();
        carry_object(__DIR__"obj/lamacloth1")->wear();
        carry_object(__DIR__"obj/ring1")->wear();
        
}

void win_enemy(object loser)
{
	say("�̵��ڶ�����һЦ˵������˵����˵��\n");

}

int	do_duel(){
	object me = this_player();
	
	if (is_fighting())
	{
		tell_object(me,"�̵��ڶ���æ���أ�û�մ����㡣\n");
		return 1;
	}
		
	if (REWARD_D->check_m_success( me, "��������"))
	{
		command("say ���ǣ���ʦ�ֵ���Ͷ�������֮�겻����ԭ�ˡ�");
		return 1;
	}
	
	if (REWARD_D->riddle_check(me,"��������") == 1)
	{
		command("smile");
		command("say ���Ļ�����ô���꣬���ǵ�һ������������ϡ��֡�");
		command("say ��ԭ֮������߯ҲС�㣬����һ��СС�ĺ�Ӷ�Ҳ�ݲ��£��ѹ�����ʽ΢��");
		command("say ��ȷ�ʦ��������������");
		
		message_vision(CYN"�̵��ڶ�ָ��ָ�͹���˵�����ľ������浥������������������"YEL"
		
�̵��ڶ�˵�գ�Ҳ��������������Ȼһ�ξ�����������\n\n"NOR, me);
		
		REWARD_D->riddle_set(me,"��������",2);
		destruct( this_object());
		
		return 1;
	}
	
		command("say ʩ����������������ᣬ����������Ծ�ʤ����");
		
		return 1;
}
			
		
		
		
		
	
	
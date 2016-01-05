#include <ansi.h>
inherit SMART_NPC;

void create()
{
    	set_name( "������", ({ "wang ruolan", "wang","ruolan" }) );
		set("long", "��������������ͷ�Ķ���Ů����Ҳ�ǵ������ǹ����Ψһ���ˡ�
һϮ���£��Գ�����͹���µĽ�����ġ�һ����ˮ���˫��������Թ�����Ŷ�ϲ��\n");
		set("attitude", "friendly");
		set("title", HIM "�绨����"NOR);
		set("age", 17);
        set("gender", "Ů��" );
		set("per", 60);
		set("class","fugui");
		set("combat_exp", 4000000);
        set("reward_npc", 1);
		set("difficulty", 5);
        
		set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	    	 (: auto_smart_fight(20) :),
     	}) ); 		

		auto_npc_setup("wang",200,200,0,"/obj/weapon/","fighter_w","xuezhan-spear3",1); 
	
		setup();
        carry_object(__DIR__"obj/white_cloth")->wear();
        carry_object(__DIR__"obj/gold_spear")->wield();
}

int accept_object(object me, object obj)
{
		object book;
		if( (string) obj->query("name") == HIR"����ǹ"NOR)
		{
	        message_vision("$N��$n���˸��򸣣�\n",this_object(),me);
	        command("smile");
			command("say ��л��λ" + RANK_D->query_respect(me) + "�����һ��˶�ʧ�İ���ǹ��\n");
		
			if ( REWARD_D->riddle_check( me, "�ھ��ڼ�")==2) {
				command ("say ��������ʶ���˹鶫������ı����Ϊ��л���Ȿ����ǹ�ף����͸����ɣ�");
				book = new(BOOKS"skill/xuezhan-spear_50");
				if(book) book->move(me);
				book = new(BOOKS"spear_75");
				if(book) book->move(me);
		        message_vision("$N�ӻ����ͳ�����ǹ���͸�$n��\n",this_object(),me);
				REWARD_D->riddle_done( me, "�ھ��ڼ�", 50, 1);
			} 		
		return 1;	
	}
	else
	{
		command("lean");
		command("say ��л��λ" + RANK_D->query_respect(me) + "��ʲô�Ҷ���Ҫ��ֻҪ��������߾ͺá�\n");
		return 0;
	}


        return 1;
}

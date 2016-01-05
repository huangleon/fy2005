// silencer@fy4.
// last modified by annie 6.28.03, added a part of demon riddle.
// a cool man? *snicker

#include <ansi.h>
inherit SMART_NPC;

string ask_for_help();

void create()
{
        seteuid(getuid());
    	set_name("���ƺ�",({"ding yunhe","ding","yunhe"}));
	set("title","����ׯ ����ү");
   	set("long","
��װ�߹ڣ���ɷ�����ƺ��Ƕ��˷�ĳ��ӣ��������书�������������
�ѵ��丸�洫�������������������������������ʤ����֮�ơ�\n");
     	set("gender","����");
    	set("age",42);
    	set("class","taoist");
    	 	   	
    	set("combat_exp",8000000);  
    	set("attitude", "friendly");
    	    	
    	set("death_msg",CYN"\n���ƺ�����ͻȻ���ɶ�������������������顱��һ��ײ��������
�ٵ������������ѿ�����Ѫɫ������ǰȴ�Ѷ�����Ѫ�ڡ�\n"NOR);  	
    	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([

        ]) );    	
        
        set("inquiry",	([
        	
        	"��������":	"action���ƺ�ĬĬ�ؿ����㣬һ�ﲻ����\n",
        	"���":		"�Ҵ���㶼��֪��������ʲô��\n",
        	"��֪��":	"��֪�����¾ͱ���ʡ�\n",
        ]));
        	
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(40) :),
        }) );
		set("chat_chance",1);
		set("chat_msg", ({
			(: ask_for_help :),
		}) );

		auto_npc_setup("wang",200,220,0,"/obj/weapon/","fighter_w","necromancy",1);
		
		setup();
    	carry_object(__DIR__"obj/c_cloth")->wear();    
    	carry_object(__DIR__"obj/y_sword")->wield();
    
}

string ask_for_help()
{
	object me;
	me = this_object();
	// callout 20��,û�����ĵ���..�Բ�����>"<
	message_vision(CYN"���ƺ���Ժ��������ȥ������üͷ��\n"NOR,me);
	remove_call_out("ask_help");
	call_out("ask_help",20);
	return CYN""NOR;
}

void ask_help()
{
	object me,room,*olist,target;
	int i;

	me = this_object();
	room = environment(me);
	olist = all_inventory(room);
	if (me->is_fighting())	// ս���в�����.
		return;
	message_vision(CYN"$N̾��һ��������̾һ�����������������š�\n"NOR,me);
	for(i=0; i<sizeof(olist); i++)
	{
		target = olist[i];
		if (!REWARD_D->check_m_success(target,"��������") 
			&& !REWARD_D->riddle_check(target,"��������"))
		{
			tell_object(target,CYN"�����ƺ����˸�Ҿ������Ĵ�������λ���ӿ�����ʲô���գ�\n"NOR);
			tell_object(target,CYN"���ƺ�˵������������һֱ�������⣬����ڵ������������⣬�����ѻ�ɽѯ�̡�\n"NOR);
			tell_object(target,CYN"���ƺ�˵�������Ұ�˼������Ǹ�����ת���������ڱ�������ؼ�֮�ϣ��Ҽǵ����������\n"NOR);
			tell_object(target,CYN"���ƺ�˵�������Ǵ��ƫ��˵�ҼǴ�Ӳ�ǲ��Ͻ�����ҡ�\n"NOR);
			tell_object(target,CYN"���ƺ�˵������������\n"NOR);
			REWARD_D->riddle_set(target,"��������",1);
		}
	}
	return;
}



int accept_object(object who, object ob)
{
	int i = REWARD_D->riddle_check(who,"��������");

	if (ob->query("is_xbook"))
	{
		ccommand("ack");
		ccommand("say �ҵ��ˣ�");
		ccommand("say ����ȥ�����Ҵ�ðɣ����������������ˡ�");
		return 0;
	}

	if (ob->query("is_fake_necbookx"))
	{
		ccommand("emote ŭ�����㾹���ûٱ����ؼ���");
	//	kill_ob(ob);		ɱ�鰡
	//	ob->perform_busy(4);
		return 1;
	}

    if (!ob->query("is_fake_necbook"))
	{
		ccommand("heng2 "+who->query("id"));
		return 0;
	}
	if (!i)
	{
		ccommand("emote �ȵ�����Ȼ��͵�ҽ��ؼ�����ô�ĵ��ӣ�");
		ccommand("kill "+who->query("id"));
		return 1;
	}
	if (i != 1)
	{
		ccommand("shake");
		ccommand("say ���Ȼ�Ǽٵģ���Ҫ������ʲô���أ�");
		ccommand("sigh");
		return 0;
	}
	ccommand("ah");
	if (who->query("gender") != "Ů��")
		ccommand("thank "+who->query("id"));
	else
		ccommand("ppp "+who->query("id"));
	ccommand("emote �ӹ��飬�ɿ�ķ���һҳ���ɿ���ַ���һҳ��");
	ccommand("faint");
	ccommand("say �⣮���⣮���Ȿ������ôһ���ֶ�û�У�Ī�ǣ����Ȿ���Ǽٵģ�");
	ccommand("say �⣮�������ȥ���ʴ�ã�");
	REWARD_D->riddle_set(who,"��������",2);
	return 1;
}
 
/*
 
               (\~~~/)            
               ( ����)        

               (_____)~��      
   
��������������- FengYun - ������
������������annie 10.2003
������dancing_faery@hotmail.com
*/


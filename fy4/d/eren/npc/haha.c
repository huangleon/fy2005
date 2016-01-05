#include <ansi.h>
inherit SMART_NPC;
inherit INQUIRY_MSG;
int give_mission();

void create()
{
	set_name("������",({"haha er", "haha"}));
    	set("nickname","Ц��ص�");
	set("long", "���˰������֣�Ц��ԲԲ�������Ǹ��������ƵľƵ��ƹ񡣡�\n");
	set("age",45);
	set("attitude", "friendly");
	set("combat_exp", 8000000);
			
	set("inquiry", ([
        	"����" : (: give_mission :),
        	"��æ" : (: give_mission :),
        	"����" : (: give_mission :),
        	"ԭ��" : (: give_mission :),
        	"��������" : (: give_mission :),
          	"ŷ��������" : (: give_mission :),
           	"ŷ����" : (: give_mission :),
           	"ŷ����" : (: give_mission :),
          	"ouyang ding" : (: give_mission :),
          	"ouyang dang" : (: give_mission :),
	   		"��ԯ����": "�����ֻʣ���Ǽ䵱���ˡ�",
	   		"С�����ͷ": "�������ǰ���������Ҫ�ϵȵĻᳪ����������ͷ���С�",
	   		"��ɽ����": "֪���һ�Ҫ���æ��",
	   		"ɳ���": "�洫���ܣ������⴫��",
	   		"����": "Ҫ���ʵĲ��У���ͷ��ɱ�˾�����",
	   		"����������":	"action�����������㣬ҡҡͷ��˵����\n",
	   		"�ҹ�������˽�":	"action�����������㣬ҡҡͷ��˵����\n",
	   		"������ĺڷ��ҵ���":	"action�����������㣬ҡҡͷ��˵����\n",
   			"ɽ�亣ζ":		"С�궼�С����У��͹�������\n",
   	]));

   	  	
	set("chat_chance", 1);
        set("chat_msg", ({
        	"Բ������Ц��������̨Զ������ض��ˣ�������Щ��������̸���¡���\n",
        	"������ƤЦ�ⲻЦ�ص������������������ҹ����������\n", 
        	"��������ü������˵������������˺ö࣬���������������Ķ������ӡ���\n",       	      	   	
        }) );
        
	set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
        	(: auto_smart_fight(30) :),    
        }) );
		
	auto_npc_setup("guardian",250,200,0,"/obj/weapon/","fighter_w","demon-strike",2);
	set("smartnpc_busy",1);
	setup();
	carry_object("/obj/armor/hat",([	"name": "Сձñ",
    						"long": "һ�������˳�����Сձñ��\n",
    						 ]))->wear();    
    carry_object("/obj/armor/cloth")->wear();
	
}


void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) 
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{   
	if( !ob || !interactive(ob) || environment(ob) != environment() ){
		return;
	}
	message_vision("$NЦ�������˹���������Ц��������̨Զ�������ˡ���\n", this_object() );
   	return;
}


int give_mission() {
	object me,ob;
	
	ob=this_object();
	me=this_player();
		
	tell_object(me, CYN"
������̾�˿���˵�����ⲻ���������Թ�ֻ��˵��������ʩ��û�뵽
��������Ҳ��ô��������������˿�Խ��Խ���ˣ��͹��Ƿ��ܰ�С��
��һ��Сæ��
	
������˵��Ҫ�ǹ��������ӣ��͵����������洫�����ˡ�

������������ָ��ʼ���䣬�Ǿ���

��a��"HIR"����������"NOR"

��b��"WHT"�ҹ�������˽�"NOR"

��c��"HIM"������ĺڷ��ҵ���"NOR+CYN"

�������������Ƨ����ֻ��Щ���ϣ�û�����ϰ��������͹��Ǹ�����
�ˣ�����������ĵ����أ���answer a/b/c��\n"NOR);
	me->set_temp("marks/eren/haha_1",1);
	add_action("do_answer","answer");
	return 1;
}


int do_answer(string arg){
	
	object me;
	me = this_player();
	
	if (!me->query_temp("marks/eren/haha_1"))	return 0;
		
	if (!arg || (arg!="a" && arg!="b" && arg!="c")) {
		tell_object(me,"�ش��ʽ��answer a/b/c\n");
		return 1;
	}
	
	me->delete_temp("marks/eren/haha_1");
	
	switch (arg) {
		case "a": tell_object(me,CYN"������˵���������ȱ����С�����ͷ��\n"NOR);
					break;
		case "b": tell_object(me,CYN"������˵���������ȱ���ǿ�ɽ���⡣\n"NOR);
					break;
		case "c": tell_object(me,CYN"������˵���������ȱ�������ơ�\n"NOR);
					break;
	}
	tell_object(me,CYN"������˵�����ԭ���ҵ��������ҵĳ�ʦ������Ʒ������\n"NOR);
	if (!REWARD_D->riddle_check(me,"ɽ�亣ζ"))
		REWARD_D->riddle_set(me,"ɽ�亣ζ",1);
	
	return 1;
}

		
/*
����������			��������������	easy bird, 2k
�ҹ�������˽�		��ѿ����ͷ��	easy pickup in chuenyu 10k
������ĺڷ��ҵ��� ���ư躣��		can be given by others, easy as well.	
*/	
	
int accept_object(object me, object obj)
{
		string *material_names=({ HIR"����������"NOR,WHT"�ҹ�������˽�"NOR,HIM"������ĺڷ��ҵ���"NOR });
		string ob_name;
		int success, makeup_ok,i;
		object book;
			
		if (!REWARD_D->riddle_check(me,"ɽ�亣ζ")) {
			command("say ����ʲô�������Ƕ�������������ƭ�ҵ�ô��");
			return 0;
		}
					
		ob_name= obj->query("name");
		success=1;
		makeup_ok=0;
		for(i=0;i<3;i++)
		{
			if(ob_name==material_names[i])
			{
				if(me->query("marks/eren/haha"+ob_name))
				{
					command("say ��������Ѿ��������ˡ���\n");
					return 0;
				}
				me->set("marks/eren/haha/"+ob_name,1);
				message_vision(CYN"����������"+obj->name()+CYN"ϸϸ��Ʒ��Ʒ��Ʒ�����ζ��Żع�������\n"NOR,me);
				command("say �ã������������ҹ��Ұ���洫��ζ��");
				makeup_ok=1;
			}
			success=success*me->query("marks/eren/haha/"+material_names[i]);
		}
		if(!success) return makeup_ok; 
			
		me->delete("marks/eren/haha");	
		
		tell_object(me,CYN"
����������ӯ����˵����ѽѽ���㾹Ȼ������ˣ��ü����ü���
���Ҵ�����洫�������ˣ��Ѷ������ӵ�����ͳͳ��������		

������˵�����������ô��æ���Ҹ����л���ء�����

����������������һ��С����˵������Ҳ�Ǹ�ѧ����ˣ��Ȿ����
�Ķ�����������ʱ�ģ������ò����ˣ�����ȥ�����ɡ�\n"NOR);
		
		book = new(BOOKS"magic_75");
		book->move(me);
		
		REWARD_D->riddle_done(me,"ɽ�亣ζ",20,1);       
        QUESTS_D->special_reward(me,"ɽ�亣ζ");		
        return 1;
}


/*
int accept_object(object who, object ob)
{	
	if (ob->query("name")=="��ɽ����" && who->query_temp("eren/haha_1"))
	{
		ccommand("spank "+who->query("id"));
		if (!who->query("eren/haha_1")) {
			who->add("potential",100);
			who->set("eren/haha_1",1);
			tell_object(who,WHT"�㱻�����ˣ�һ��Ǳ�ܣ�\n"NOR);
		}
		message_vision("$N˵:�����Ҹ�Щɽȸ��ɡ�\n",this_object());
		who->set_temp("eren/haha_2",1);
		return 1;
	}
	if (ob->query("name")==HIG"ɽȸ��"NOR && who->query_temp("eren/haha_2")
		&& who->query("eren/haha_1"))
	{
		ccommand("spank "+who->query("id"));
		if (!who->query("eren/haha_2")) {
			who->add("potential",100);
			who->set("eren/haha_2",1);
			tell_object(who,WHT"�㱻�����ˣ�һ��Ǳ�ܣ�\n"NOR);
		}
		message_vision("$N˵:�����Ҹ�Щ"+YEL"����"NOR+"�ɡ�\n",this_object());
		who->set_temp("eren/haha_3",1);
		return 1;
	}
	if (ob->query("name")==YEL"����"NOR && who->query_temp("eren/haha_3")
		&& who->query("eren/haha_1") && who->query("eren/haha_2"))
	{
		ccommand("spank "+who->query("id"));
		if (!who->query("eren/haha_3")) {
			who->add("potential",100);
			who->set("eren/haha_3",1);
			tell_object(who,WHT"�㱻�����ˣ�һ��Ǳ�ܣ�\n"NOR);
		}
		message_vision("$N˵:�ã��ã������ܸ㵽ɳ��Σ���һ���ܰ����ӱ���ȥ��\n",this_object());
		message_vision("$N˵���ұ�����л��������$N��$n���˻��֡�\n",this_object(),who);
		who->set_temp("eren/haha_4",1);
		return 1;
	}	
	if (ob->query("name")==YEL"ɳ���"NOR && who->query_temp("eren/haha_4")
		&& who->query("eren/haha_1") && who->query("eren/haha_2")
		&& who->query("eren/haha_3"))
	{
		ccommand("ack "+who->query("id"));
		message_vision("$N���Ͱ͵�˵��������������Ź���������\n",this_object());
		who->set("marks/���˿�",1);
		who->delete_temp("eren/haha",1);
		who->delete_temp("eren/haha",2);
		who->delete_temp("eren/haha",3);
		who->delete_temp("eren/haha",4);
		tell_object(who,"���������������˵������������Ļ��ܣ���������������ű���������ˡ�\n",this_object());
		ccommand("grin");
		return 1;
	}	
	return 0;	
}
*/
inherit NPC;
inherit F_MASTER;
#include <ansi.h>

int leave();
int back();

void create()
{
        set_name("Ҷ�³�", ({ "master ye", "master" }) );
        set("nickname", HIC"һ������"NOR+HIR" �������"NOR);
        set("long","
һ������΢�룬������ѩ�׳��۵��ˡ��������ܰף��Ȳ��ǲ԰ף�Ҳ���ǲҰף�
����һ�ְ���㾧Ө�������ɫ�������۾���������ڵģ���ȴ���ÿ��£���
�������ź��ǡ�����ڵ�ͷ���ϣ�������̴��ľ������ڣ����ϵ��·�Ҳ���
��ѩ���·������ϵ�����һ�㡣
\n"
	);
        set("gender", "����" );
        set("class","baiyun");
        set("age", 44);
        set("str", 100);
       	set("per", 20);
	    set("combat_exp", 15000000);

		set("no_heal",1);
		set("max_kee",10000000);
		set("max_gin",100000);
		set("max_sen",100000);
		set("eff_kee",100000);
		set("kee",100000);
        
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.tianwaifeixian" :),
        }) );
	
		set("attitude","friendly");
                
        set("chat_chance", 0);
        set("chat_msg", ({
			(: back() :),
        }) );

        create_family("���Ƴ�",1, "����");
		set("rank_nogen",1);
    	set("ranks",({"��ʹ","��ʹ","��ʹ","��ʹ","��ʿ",
                      CYN"��ʹ"NOR,CYN"��ʦ"NOR,HIC"��ʦ"NOR}));

        set("score", 200000);
    	set("reward_npc", 1);
	set("difficulty", 40);
        
        set("inquiry",  ([
                "leave": (: leave :),
        ]) );
     
        set_skill("move", 180);
	set_skill("daode",200);
        set_skill("parry", 170);
        set_skill("dodge", 170);
        set_skill("force", 180);
        set_skill("literate", 150);
	set_skill("sword", 220);
	set_skill("unarmed",150);
    set_skill("music",130);
	
	set_skill("feixian-steps",200);
	set_skill("feixian-sword",200);
	set_skill("calligraphy",160);
	set_skill("chessism",160);
	set_skill("magic",150);
	set_skill("painting",200);
	
	map_skill("magic","music");
	map_skill("dodge", "feixian-steps");
	map_skill("sword", "feixian-sword");
	map_skill("force", "chessism");
	map_skill("parry", "feixian-sword");
	map_skill("unarmed", "calligraphy");
	map_skill("move","feixian-steps");

        setup();
        carry_object(__DIR__"obj/whitecloth")->wear();
        carry_object(__DIR__"obj/bsword")->wield();
	carry_object(__DIR__"obj/bcloth")->wear();
}


void init()
{       
        object ob;
        ::init();
        if ( interactive(ob = this_player()) && !is_fighting() ) 
           {
             remove_call_out("greeting");
             call_out("greeting", 1, ob);
           }

}

/*
int recognize_apprentice(object ob)
{
	if (!ob->query("free_learn/magic"))
	{
		ccommand("heihei "+ob->id(1));
		return 0;
	}


    return 1;
}



int prevent_learn(object me, string skill)
{
  	if (skill != "magic")
  	{
      		command("haha");
      		return 1;
  	}
  	return 0;
}


int prevent_shown(object me, string skill)
{
	if (me->query("free_learn/magic") && (skill == "magic"))
		return 0;
	
	return 1;
}*/

void greeting(object ob)
{
        object corpse;
		object me = ob;
		object box;
		mapping data;
		
        if( !ob || environment(ob) != environment() ) return;
		if (REWARD_D->riddle_check(ob,"��ͼһ��") ==14)
		{
			message_vision(YEL"Ҷ�³ǲ������������ʮ�꣬ɱ�����㣬��Ϊ��һ��֣������ô������ô����������\n"NOR,me);
			message_vision(YEL"Ҷ�³��������ң�"CYN"ն��̨"YEL"�������������ұ�֤����һʧ����������������\n\n"NOR,me);
			message_vision(MAG"ʮ���λã��ճ���Ӱ��Ҷ�³Ǿ�Ȼվ�����ȣ�һ�������ڵ��ϡ�\n\n"NOR,me);
			ob->set("free_learn/music",1);
			REWARD_D->riddle_done(ob,"��ͼһ��",100,1);
			
			data = ([
				"name":		"��ͼһ��",
				"target":	ob,
				"att_1":	"con",
				"att_1c":	1,
				"mark":		1,
			]);
		
			REWARD_D->imbue_att(data);
					
			start_busy(20);	// grin...
			return;
		}

		if (REWARD_D->riddle_check(ob,"��ͼһ��") !=10 && REWARD_D->riddle_check(ob,"��ͼһ��") !=11 )
			return;
		if (REWARD_D->riddle_check(ob,"��ͼһ��") ==11 && ob->query_temp("annie_by_1_2_5"))
			return;
		ob->set_temp("annie_by_1_2_5",1);
    	message_vision(HIC"Ҷ�³�����Զ������������������������£��������� \n\n          �Ͻ�֮�ۣ�һ��������\n\n"NOR,me);
    	message_vision(HIC"Ҷ�³Ǻ����������Ŵ�ѩ���������Ŵ�ѩ�����ٺ٣��ã��á�\n"NOR,me);
    	message_vision(HIW"Ҷ�³�����������һֻ��̴ľ�У�����򿪺иǡ�\n\n"NOR,me);
    	message_vision(HIW"Ҷ�³�˫���и����㣬һ���ֵ������ҽ����ж�ʮ��������ʹ��������������\n����ʮ�壬�Ͻ�֮�۹�Ҷĳ������֮ս���ٺ٣�����ʮ�壬ն��֮�ա�����\n��������Ӣ��������\n\n"NOR,me);
    	command("emote �����ӽ���"+me->name(1)+"��");
    	message_vision(HIR"Ҷ�³���ɫһ�ݵ�����ȥ�ٻأ�����֮������ͻء�\n\n"NOR,me);
		box=new(__DIR__"obj/box");
		box->move(me);
		REWARD_D->riddle_set(ob,"��ͼһ��",11);
		return;
}


int back()
{
	object room = load_object("/d/baiyun/baiyunguan");
	move(room);
    set("chat_chance", 0);
	return 1;
}

int accept_object(object me, object obj)
{
	if (!obj->query("annie/real_by_box") && !obj->query("thief_obj"))
	{
        message_vision(HIY"Ҷ�³ǽ��˹�������üһ��������һ��������һ����"+obj->name()+"���˳�ȥ��\n"NOR,me);
		return 1;
	}

	else if (REWARD_D->riddle_check(this_player(),"��ͼһ��") ==11)
	{
		if (obj->query("letters") && sizeof(obj->query("letters")))
		{
            message_vision(HIR"Ҷ�³���ɫһ����ŭ����������֮����δ��ɣ��꾹�����������ң� \n"NOR,me);
			return 0;
		}
         message_vision(HIR"Ҷ�³�΢���ף���Ц�����������յõǴ󱦣��굱Ҳ��һ�ݹ��͡� \n\n"NOR,me);
         message_vision(CYN"Ҷ�³�����$N�ļ��Ц�����������ֻ�農��ʱ��������ȥ�������ߣ����ʵ��ʾ���\n\n"NOR,me);
//      message_vision(CYN"Ҷ�³�Ц���������������¶�ѧ���ֱ��£��¼�Ҳ�ɴ��㡣\n\n"NOR,me);
		REWARD_D->riddle_set(me,"��ͼһ��",12);
//		me->set("free_learn/magic",1);
		return 1;
	}
	message_vision("Ҷ�³ǽ��˹�������Ҳ�������ͽ�"+obj->name()+"�Դ������˳�ȥ��\n",me);
	return 1;
}



void inv(object *enemy,object room)
{
	int i;
	move(room);
   	message_vision(HIC"\n���ڵ���ͻȻһ������ɽ������������������\nҶ�³���ɫ���˱䣬��Ц�������Ҵ�ҵ�ߣ�����\n" NOR, this_object());   
    set("chat_chance", 100);
	i = sizeof(enemy);
	while(i--)
	{
		if( enemy[i] && living(enemy[i]) && environment(enemy[i]) == room)
		{
			kill_ob(enemy[i]);
			enemy[i]->kill_ob(this_object());
		}
	}

}

void die()
{
	object who, owner;
	
	if(objectp(who = query_temp("last_damage_from")))
    {
    	if ( objectp(owner = killer->query("possessed")))
    		who = owner;		
		if (query("chat_chance") == 100 
			&& REWARD_D->riddle_check(who, "��ͼһ��") == 13)
		{
			message_vision(CYN"
Ҷ�³�Ż����Ѫ����ɫ��ʤѩ�ĳ��ۻ�Ҫ�԰ף���ȻһЦ���� 
����ͼ��ҵ���ѵ����ǻ���һ�Σ��Ҳ��ʰ����� "WHT"

Ҷ�³�ŭ��һ������â��ʢ���������ֶ���������֮�����$N�������� 

��ʹ���ٲ��õ����ǣ��ٻԻ͵��׵磬Ҳ��������������һ���� "HIR"


$N�߾�ȫ�������������ջ��ḹ������\n\n"NOR,who);
			who->set("kee",1);
			COMBAT_D->report_status(who);
			who->unconcious();
			who->move(load_object("/d/baiyun/nujiao"));
		}
	}
	::die();
	return;

}

void invocation(object who,object room)
{
	object owner,*enemy,*t;
	int i;
	enemy = who->query_enemy();
	t = ({ });
	for (i=0;i<sizeof(enemy) ;i++)
		t += ({ enemy[i] });
	call_out("inv",16,t,room);
}




/*
 
               (\~~~/)            
               ( ����)        

               (_____)~��      
   
��������������- FengYun - ������
������������annie 10.2003
������dancing_faery@hotmail.com
*/

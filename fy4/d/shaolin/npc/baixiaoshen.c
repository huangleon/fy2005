inherit NPC;
#include <ansi.h>

int guardd();
int failit();
int dont();
int dontt();

void create()
{
        set_name("������", ({ "bai xiaosheng", "bai"}) );
        set("gender", "����" );
        set("age", 42);
        set("long", "���ǵ����������ֵĵ�һ���ӣ������������ж���Ӣ�۶�����
���ı������ϡ�\n");
        set("combat_exp", 7000000);
        set("attitude", "friendly");

    	set_skill("move", 200);
    	set_skill("dodge", 200);
    	set_skill("force", 200);
    	set_skill("literate", 200);
    	set_skill("unarmed",200);
    	set_skill("puti-steps",200);
    	set_skill("yizhichan",200);
    	set_skill("buddhism",250);
    	set_skill("chanting",200);
    	set_skill("xiaochengforce",200);
    	set_skill("staff",200);
    	set_skill("parry",200);
    
    	map_skill("parry","yiyangzhi");
    	map_skill("dodge", "puti-steps");
    	map_skill("force", "xiaochengforce");
    	map_skill("unarmed", "yizhichan");
    	map_skill("move", "puti-steps");
    	
    	

	    	set("inquiry", ([
        	"���γ���": (: dont :),
        	"��": (: dontt :),
        	"�ݰ�": (: dontt :),
        	"�ݣ������ݣ�����": (: dontt :),
        	"�ݣ�����": (: dontt :),
    	]));

		set("intellgent",1);
        set("chat_chance", 10);
        set("chat_msg", ({
                name()+"����ʲô����Ҳ�����Ұ�����������ף�������\n",
                name()+"�����ҵı����׿���Ҫд����ǧ����������㡣\n",
        }) );
	
	setup();
        carry_object("/obj/armor/cloth")->wear();
}

int dont()
{
	object me;
	me = this_player();
	if (REWARD_D->riddle_check(me,"����֮��") != 8)  
	{
		ccommand("dunno "+me->query("id"));
		return 1;
	}
	ccommand("emote ������������˫�ֳ���������");
	ccommand("say �ǲ���"YEL"�������"CYN"���ñ���ô��Ī����������������ΪʲôҪ������");	 // ������ָ���ͣ�������pplȥ��tianfeng
	REWARD_D->riddle_set(me,"����֮��",9);
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



int dontt()
{
	object me;
	me = this_player();
	if (REWARD_D->riddle_check(me,"����֮��") != 12
		 && REWARD_D->riddle_check(me,"����֮��") != 13)  
	{
		ccommand("heihei "+me->query("id"));
		return 1;
	}
	ccommand("emote ��ɫһ�䣬��Ц�����ã������Լ���������ֲ����ң�");
	REWARD_D->riddle_set(me,"����֮��",13);
	kill_ob(me);
	me->kill_ob(this_object());
	return 1;
}

void killed_enemy(object who)
{
    command("heng");
    command("say �ҷ��������ֶΣ������ĳ�����������Թ�����ң�");
}

void unconcious()
{
	die();
}

void die()
{
	int i;
	object killer, owner,me;
	object room;
	mapping data;
	
	room = environment();
	if(objectp(killer = query_temp("last_damage_from")))
	{
		if(owner=killer->query("possessed"))
			killer = owner;

			me=killer;

		if(REWARD_D->riddle_check(me,"����֮��") != 13 
			&& !REWARD_D->check_m_success(me,"����֮��"))
		{
			// rob��?
			::die();
			return ;
		}

		message_vision(HIR"\n$NĿ�����ѣ���ȵ����ã��ã�\n$N������𣬼�ȫ������$n��ȥ��\n"NOR,this_object(),killer);

		killer->set("annie/demon_gao",1);
		
		if (random(killer->query_skill("move",1)) > 100)
		{
			message_vision("$n������ת������һ�ԣ�$N������������ǽ�ϣ�����ǽ�ں��һ���󶴣�\n\n",this_object(),killer);
		}
		else
		{
			message_vision(CYN"$n���㲻������$N�����������۵�һ��ӡ���ؿڣ���ʱ����߷��ݰ�ɳ���\n$n�ɵ����ɿ��⣬��Ȼײ��ǽ�ϣ�����ǽ��ײ��һ���󶴣�\n"NOR,this_object(),killer);
			killer->receive_wound("kee",(400-random(killer->query_skill("parry",1)))*20,this_object());
			COMBAT_D->report_status(killer);
		}
        
        REWARD_D->riddle_done(me,"����֮��",100,1);
        
        data = ([
			"name":		"����֮��",
			"target":	killer,
			"att_1":	"con",
			"att_1c":	1,
			"mark":		1,
		]);
	
		REWARD_D->imbue_att(data);	
             
        room->opengate();
	}
	::die();
}


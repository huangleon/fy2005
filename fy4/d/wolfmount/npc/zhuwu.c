inherit NPC;
inherit F_MASTER;
#include <ansi.h>

void create()
{
	set_name("����̫ү", ({ "master zhuwu", "master", "zhuwu" }) );
	set("gender", "����" );
	set("age", 75);

    set("per", 40);
	set("attitude","heroism");
	set("apprentice_available", 5);
	set("long",		"
��ȫ���ѱ��佩Ӳ�����ϵļ���Ҳ����ή����Ť����һ�ű�����ׯ
�ϵ������ѱ��˵������а��ɲ���\n"
		);
		
	create_family("��ɽ", 3, "ɽ��");
	set("rank_nogen",1); 
	    set("rank_levels",({ 16000, 32000,64000, 128000,
					256000,512000,1024000,1536000,2048000,
					3064000,4096000, 5120000,6144000,8192000,
					9999999}));
	set("ranks",({ "С���","�����","���ǵ�","ҹ�ǵ�","ս�ǵ�",
				"СͷĿ","��ͷĿ","Сͷ��","��ͷ��","���","����",
				"����",RED"��ʥ"NOR,RED"��˧"NOR,RED"����"NOR,HIR"����֮��"NOR}));
				
	set("class", "wolfmount");
	
	set("inquiry", ([
		"����":		"�������¡��������Գ�Ϊ̫��ʹ�ߣ�\n",
		"��":		"�������¡��������Գ�Ϊ̫��ʹ�ߣ�\n",
		"����":		"�������¡��������Գ�Ϊ̫��ʹ�ߣ�\n",
	]));
			
	set("combat_exp", 20000000);
	set("difficulty", 40);
	set("reward_npc", 1);
	
	set_skill("parry", 190);
	set_skill("unarmed", 200);
	set_skill("foreknowledge",170);
	set_skill("move", 180);
	set_skill("perception",180);
	
	set_skill("hammer", 300);
	set_skill("assassin-hammer", 180);
	set_skill("cursism", 200);
	set_skill("force", 160);
	set_skill("wolf-force",170);
	set_skill("wolf-curse",200);
	set_skill("dodge", 160);
	set_skill("xueyeqianzong", 160);
	set_skill("literate",100);
	set_skill("wolf-strike", 200);
	set_skill("summonwolf", 270);
	set_skill("chanting",100);
	
	map_skill("dodge","xueyeqianzong");
	map_skill("unarmed","wolf-strike");
	map_skill("parry","assassin-hammer");
	map_skill("hammer","assassin-hammer");
	map_skill("force","wolf-force");
	map_skill("cursism","wolf-curse");
	
	setup();
	carry_object(__DIR__"obj/graycloth")->wear();
	carry_object(__DIR__"obj/juque");
	carry_object(__DIR__"obj/rockhammer")->wield();
}

int is_ghost()
{ 
	return 1; 
}

void init(){	
	::init();
	add_action("do_kill","kill");
}

int do_kill(string arg)
{
	object me,ob;
	object player, victim;
    	string id,id_class;
	me = this_player();
	if(arg == "master zhuwu" || arg == "master" )
	{
		if ( ob=present("wanyan tie",environment(this_object())) )
		{
			message_vision("$N��$n���һ�������㲻���������������֣������������㣡\n",ob,me);
			ob->kill_ob(me);
			return 1;
		}
		else if ( ob=present("wanyan gang",environment(this_object())) )
		{
			message_vision("$N��$n���һ�������㲻���������������֣������������㣡\n",ob,me);
			ob->kill_ob(me);
			return 1;
		}
		else 
		{
			return 0;
		}
	}
	player = this_player();
    if(!arg || arg == "") return 0;
    	victim = present(arg, environment(player));
	if(!objectp(victim))
		return notify_fail("����û������ˡ�\n");
    	if(living(victim))
    	{
        	id_class=victim->query("class");
        	id=victim->query("id");
       		if(id_class == "wolfmount"&& userp(victim)&&player!=victim)
        	{
			message_vision(HIW"$N��$n�ȵ������ӵ�ͽ��Ҳ������ɱ�ģ�\n"NOR, this_object(),player);
			this_object()->kill_ob(player);
			player->kill_ob(this_object());
            		if (!player->is_busy()) player->start_busy(2);
			return 0;
        	} 
    	}
    	return 0;
}

void reset()
{
                set("apprentice_available", 5);
}

void attempt_apprentice(object ob)
{
        if( query("apprentice_available") ) 
        {
                if( find_call_out("do_recruit") != -1 )
                        command("say ������һ��һ������");
                else
                        call_out("do_recruit", 2, ob);
        } 
        else 
        {
                command("say ��ɽ���ӣ��󾫲���࣬���첻�������ˡ�");
        }
}

void do_recruit(object me){
	
		if( (string)me->query("class") != "wolfmount" )
        {
            command("say ��ֻ����ɽ�ӵܣ��㻹����ı�߾Ͱɣ�\n");
        }
        else if(!me->query("marks/ɱ̫��ʹ��") && !REWARD_D->check_m_success(me,"��ɽ����"))
        {				// ɱ�� sun legate, ���� ���� riddle �����԰�
        	switch ( random(2) )
			{
		  		case 0:
					command("say ��ɽ����������֮�֣���������㣿\n");
			//		me->set_temp("marks/������̫ү",1);
				break;
				case 1:
		  	//		me->set_temp("marks/������̫ү",1);
		  			command("say ��ԩ�겻�𣬾��ǵ�������Ϊ�ұ��˳��ٴ���һ���书��\n");
		  			break;
			}
		} else  {
		 		if (me->query_skill("assassin-hammer",1) < 150)
            	{
            		command("say ����ұ��˴�𣬣�\n");
            		command("say ������Ĳ�����ɱ������ǳ��ѧ�䲻�ܺô�ϲ����������һ���������ҡ�\n");
            		tell_object( me, "����150��������ɱ��\n");
            		return;
            	}
		
		command("say ����ұ��˴���Ҿ�����Ϊͽ�ɣ�\n");
		command("recruit " + me->query("id") );
	}
}
		
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "wolfmount");
        add("apprentice_availavble", -1);
}
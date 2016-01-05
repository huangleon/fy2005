#include <ansi.h>
inherit F_MASTER;
inherit NPC;
int leave();
int show_me();

void create()
{
        set_name("�����", ({ "master chai","master","chai" }) );
        set("gender", "����" );
        set("long","
����ȧ������������һ�����ף������С���ü���Բϣ�˫Ŀϸ������
΢΢�´���üĿ���������Ź⣬�������Ÿ߸����������Ĺ��ǣ���������
�ȵ���Ȩ�������ǣ�Ҳ���������Ǿ��ǳ��˿ɱȵ���ʢ������\n");

        set("nickname", HIY"�������"NOR );
	set("apprentice_available", 5);
	set("class","knight");
	
	create_family("�����", 1, "����֮��");
		set("rank_nogen",1);
	    set("rank_levels",({ 16000, 32000,64000, 128000,
					256000,512000,1024000,1536000,2048000,
					3064000,4096000, 5120000,6144000,8192000,
					9999999}));
    	set("ranks",({"�̾�ͯ","Ѱ����","���ƿ�","ҩʦ","����ʿ","������",
    			"����ͳ��","����ʹ","��ʹ","ɫʹ","��ʹ","��ʹ",
    			RED"�����ʹ"NOR,RED"�����ʹ"NOR,RED"һ�ֲ�����"NOR,HIR"�����"NOR}));
        set("attitude", "peaceful");
        
        set("reward_npc", 1);
	set("difficulty", 40);
	
	set("age", 57);
        set("per", 10);
        set("agi", 80);
                
        set("combat_exp", 20000000);
        
	set("chat_chance_combat",80);
        set("chat_msg_combat",({
	        (:perform_action,"axe.jiuqipoxiao":),
	        (:perform_action,"dodge.fengliu":),
        }));
        
        set_temp("apply/haste",400);
        set("toughness",200);      
            
    	set("inquiry", ([
            	"leave" : (: leave :),
    	]));
        	        
        set("chat_chance", 1);
        set("chat_msg", ({
		"��������۳��״�Ц�������մ�ϲ��ϣ������Ҳ������̤��ԭ֮ʱ��\n",
		"���������ҹ�Ɑ��һ�����£���Ц����׳־���ͺ�²�⣬Ц̸������ūѪ��\n����������������ƣ����յ�����ԭ�˵�Ѫ�ƣ�\n",
		}) );

        
        set_skill("foreknowledge", 190);
	set_skill("axe", 300);
	set_skill("dodge", 170);
	set_skill("parry", 170);
	    
	    set_skill("force", 160);    
        set_skill("unarmed", 160);
        set_skill("move", 170);
        set_skill("perception",170);
        set_skill("chanting",100);
        set_skill("literate",100);
        
        set_skill("xuanyuan-axe", 180);
        set_skill("dream-herb", 200);
        set_skill("windy-steps", 200);
        set_skill("longlife-force", 180);
        set_skill("herb", 300);
        set_skill("hanshan-strike",200);
        
                      
          map_skill("unarmed","hanshan-strike");
          map_skill("herb","dream-herb");
          map_skill("axe","xuanyuan-axe");
          map_skill("parry","xuanyuan-axe");
          map_skill("dodge","windy-steps");
          map_skill("force","longlife-force");
          map_skill("move","windy-steps");
          
        setup();
        carry_object(__DIR__"obj/mangpao")->wear();
        carry_object(__DIR__"obj/panguaxe")->wield();
        carry_object(__DIR__"obj/lightcup");
}


void reset()
{
	set("apprentice_available", 5);
}


void attempt_apprentice(object me)
{
        if( (string)me->query("class") != "knight" )
        {
            command("say ��ֻ�ձ��ŵ��ӣ��㻹����Ѱ��ʦ�ɣ�\n");
        }
        else if (!REWARD_D->check_m_success(me,"¥����Ե"))
        {
        	command("say ���Ϸ���֮����˵�ɣ�\n");
        }
        else if(!me->query_temp("marks/knight_win_dugu"))
        {
        	switch ( random(2) )
		{
		  	case 0:
				command("say ���Ź��ɭ�ϣ��ȴ�Ӯ���ʦ���������ң�\n");
				break;
			case 1:
		  		command("say ѧ��Ҫѭ�򽥽����㻹�Ǵ�û��������ɡ�\n");
		  		break;
		}
		}
		else
		{
			command("say ������Ӣ�ţ���������ϣ������һ���������˰����Ǻǣ�\n");
			command("recruit " + me->query("id") );
		}
}

void init()
{	
	object me;
	::init();
	me = this_player();
	if( interactive(me) && !is_fighting() )
	{
		remove_call_out("greeting");
		call_out("greeting", 0, me);
	}
	add_action("do_answer","answer");
	add_action("do_accept","accept");
}


void greeting(object me)
{
	object *inv;
	int i;
	object ob;
	ob = this_object();
	if( userp(me))
	{
		inv = all_inventory(me);
		for(i=0; i<sizeof(inv); i++)
		{
			if(inv[i]->query("item_owner")=="������" 
					&& (int)inv[i]->query("equipped"))
			{
				if (!me->query_temp("marks/chai_talkto_you"))
				{
					message_vision(HIY"$NĿ���絶���������˹��������� \n"NOR,ob);
					message_vision(HIY"$N��׵��������ȥ��֪������ȥ�ٻ�����ױ��ϲ���Ƕ����ˣ�֪��ô��\n��answer yes or not) ��\n"NOR,ob);
					me->set_temp("marks/chai_talkto_you",1);
				}
				else
				{
					message_vision(HIY"$N�ʵ��������������������\n"NOR,ob);	
				}
			}
		}
	}
}

int do_answer(string arg)
{    
	object me;
	
	me=this_player();
	if (!arg) return notify_fail("�ش�ʲô��\n");
	if (!me->query_temp("marks/chai_talkto_you")) return notify_fail("�ش�ʲô��\n");
	if (arg == "yes")
	{
		message_vision("$N�Ϲ��Ͼ������Ӧ��\n",me);
		me->set_temp("marks/chai_get_command",1);
		return 1;
	}
	else if (arg == "no")
	{
		message_vision("$N����΢һ��ԥ������ \n",me);
		message_vision("$N��ɫһ�����ô�ĵ������������Ļ����㵽���Ǻ��ˣ� ������ \n",this_object());
		me->delete_temp("marks/chai_talkto_you");
		this_object()->kill_ob(me);
      		me->kill_ob(this_object());
      		return 1;
	}
	else
		return notify_fail("�ش�ʲô��\n");
}

int accept_object(object me, object obj)
{	
       	object npc;
       	object book;
       	object *inv;
	int i;
	int j;
	j = 0;
	npc = this_object();
	if( userp(me))
	{
		inv = all_inventory(me);
		for(i=0; i<sizeof(inv); i++)
		{
			if(inv[i]->query("item_owner")=="������" && (int)inv[i]->query("equipped"))
			{
				j = 1;
			}
		}
	}
       	if (me->query_temp("marks/knight_kill_wang") && obj->query("name") == "��ľ�����" && j == 1)
       	{
			if (obj->query("closed")){
				message_vision(YEL"$Nһ��ü˵��������㲻��ȥ���£����������������������\n"NOR,npc);
				return 0;
			}
			message_vision(HIY"$N��Ȼվ�𣬿������������������\n"NOR,npc);
			message_vision(HIY"$N�Բ�üһ���������Ц��������������Ī��������֪���ٺ٣����� \n"NOR,npc);
			message_vision(HIY"$N��������$n�ļ������ã��������Ϊ���������һ� 
�����˴󹦣��ɰ���������ѧϰ�� \n"NOR,npc,me);
	        REWARD_D->riddle_done( me, "¥����Ե",50,1);	
	         	
	        return 1;
        }
        else
        	return notify_fail("���������΢Ц��ĬȻ���\n");	
}



int leave() {
	if (this_player()->query("class")!="knight") return 0;
	message_vision(CYN"$Nһ������$n��ƨ���ϡ�\n"NOR, this_object(),this_player());
	message_vision(CYN"$N˵���Ժ������ԯ��ʹ�������ɱ���ҡ�\n"NOR,this_object(),this_player());
	message_vision(CYN"$N˵�������������廨��Ҳ�����¡�\n"NOR,this_object(),this_player());
	return 1;
}


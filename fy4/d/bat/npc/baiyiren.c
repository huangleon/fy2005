inherit NPC;
#include <ansi.h>


void create()
{
        set_name("����������", ({ "white cloth man", "man" }) );
        set("nickname", HIC "һ��������" NOR );
        set("gender", "����");
        set("age", 32);
        set("long","
����һλ�书�����Ķ����ʿ������һ����ɨ��ԭ����,
�����޵У������������º�����У��첻֪��ȥ��
\n"
        );
        create_family("ӣ��", 1, "��ʿ");

        set("attitude", "heroism");
        set("combat_exp", 4500000);
        set("score", 200000);
 
		set("reward_npc", 1);
		set("difficulty", 5);
		set("class","ninja");
        set("chat_chance", 1);
        set("chat_msg", ({
			"��������������ĵ��������й���ʿ���ǲ���һ����\n",
			"���������˰�Ȼ�����Ҵ�������ʿ������ս���Ҳ��ҽ��ܣ�\n",
			"�������������������һ���Ϳ��Ժ�ɨ���ǵĽ�����\n",
        }) );

        set("agi",45);
                       
        set_skill("unarmed", 200);
    	set_skill("ghosty-force",300);
    	set_skill("enmeiryu",180);
    	set_skill("ittouryu",160);
    	set_skill("dodge", 180);
		set_skill("ghosty-steps",200);
		set_skill("blade",200);
   		set_skill("force", 180);
    	set_skill("parry", 200);
    	    	   	
    	map_skill("unarmed", "enmeiryu");
    	map_skill("blade", "ittouryu");
    	map_skill("parry", "ittouryu");
   		map_skill("force", "ghosty-force");
   		map_skill("dodge", "ghosty-steps");
   	
   	
   		set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
                (: perform_action,"unarmed.shiden" :),
                (: perform_action, "unarmed.shimon" :), 
        }) ); 

        setup();
        carry_object("/obj/weapon/sword_katana");
        carry_object("/obj/armor/cloth",
        		([	"name"	:	HIW"ӣ����ʿ��"NOR,
        			"armor_prop/armor":	8,
        			"long"	: "һ��ӣ����ʿ����\n" ])
        		)->wear();
}

void init(){
		::init();
		add_action("do_answer","answer");
}


int accept_fight(object me)
{
		
		command("say ���Ǻ��ˣ�����Ϊ�����������������ȫ������Щ��֪ç��
������������������Ҫ������ֻ���Լ�ȥ���ɣ��������������֡���answer��\n");
			return 0;
}

int		do_answer(string arg){
		
		object ob, room;
		string msg;
		
		ob = this_player();
		
		if (!room = find_object(AREA_BAT"duelboat"))
			room = load_object(AREA_BAT"duelboat");
		
		if (room->usr_in())
		{
			message_vision(YEL"���������˱�Ŀ����������һ�ԡ�\n"NOR, ob);
			return 1;
		}
		
		if (arg == "������")
		{
			message_vision(CYN"���������˵�����˵�����Ѱ��ˣ��α���ս��\n"NOR, ob);
			return 1;
		}
		
		if (arg == "��ս")
		{
			message_vision(CYN"���������˵�����˵����Ƥ�������ѵ���ԭ����ֻ�������ɫ��\n"NOR, ob);	
			return 1;
		}
		
		if (REWARD_D->riddle_check(ob,"��ƽ����") == 5 
			|| REWARD_D->check_m_success(ob,"��ƽ����") == 2)
		{
			command("say ̰���������㲻���Ҷ��֡�");
			return 1;
		}
			
		if (REWARD_D->riddle_check(ob,"��ƽ����")!=2
			|| (arg != "�����յ���" && arg != "ս��"))	
		{
			message_vision(YEL"��������������ؿ�����һ�ۣ����ݾ���˿�����顣\n"NOR,ob);
			return 1;
		}
				
		if ( arg == "�����յ���" )	{	
			message_vision(CYN"
���������˲������㣬���𳤵����������죬΢΢������
		
����������˵�������շ��Ҷ��֣����������ӣ����������һս��

����������˵������֮�书��Ψ��ս��һ;����answer��\n"NOR, ob);
			ob->set_temp("marks/baiyiren_a1",1);
			return 1;
		}

		if (!ob->query_temp("marks/baiyiren_a1"))
		{
			command("say ����Ϊ�����������������ȫ������Щ��֪ç��������������
������Ҫ������ֻ���Լ�ȥ���ɣ��������������֡�\n");
			return 1;
		}

		message_vision(CYN"
$N��Ȼ˵������Ϊ���о���ѧ�������ϧɱ�ˣ�����Ϊ����ѧ�������ϧս����
��;��ͬ�飬���ұ���ͬ·�ˣ���������Ȼ����ɱ������Ҳ�����㣡\n\n"NOR, ob);
		ob->delete_temp("marks/baiyiren_a1");
		
		message_vision(CYN"
������������Į����������������Ҫ�������Ҳ����㣬����ս�ں���֮�ۣ�"WHT"

һҶ���������Ӻ��г�����"CYN"

���������˻���է�䣬����һ��$N���ɼ������Ϸ��˳�ȥ��\n", ob);

		msg = NATURE_D->game_time()+ "����ԭ��ʿ"+ ob->name(1)+"Լս�������ڶ���֮����";
		CHANNEL_D->do_sys_channel("info", msg);   		
		ob->move(room);
	
		destruct(this_object());
		return 1;
}
		
		
		
		


		


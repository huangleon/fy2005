#include <ansi.h>
inherit F_MASTER;
inherit NPC;
int leave();

void create()
{
	set_name("С��", ({ "xiao ji","xiaoji" }) );
	set("gender", "Ů��" );
	set("long","��Ŀ��ת����Цٻ�⡣
˭Ҳ�޷��뵽�������ǿ�����е�λ�������Ҳ����翵�ҩʹ��\n"
	);
        create_family("�����", 3, "ҩʹ");
        set("nickname", MAG "�껪��ˮ"NOR);
        set("attitude", "peaceful");
        set("rank_nogen",1);
        set("class","knight");
        
        set("rank_levels",({ 16000, 32000,64000, 128000,
					256000,512000,1024000,1536000,2048000,
					3064000,4096000, 5120000,6144000,8192000,
					9999999}));
    	set("ranks",({"�̾�ͯ","Ѱ����","���ƿ�","ҩʦ","����ʿ","������",
    			"����ͳ��","����ʹ","��ʹ","ɫʹ","��ʹ","��ʹ",
    			RED"�����ʹ"NOR,RED"�����ʹ"NOR,RED"һ�ֲ�����"NOR,HIR"�����"NOR}));
	
		set("reward_npc", 1);
		set("difficulty", 5);
    	
    	
		set("chat_chance_combat",80);
		set("chat_msg_combat",({
        	(:perform_action,"herb.canyunbi":),
          (:perform_action,"axe.pangukaitian":),
        	(:perform_action,"herb.kaixiehua":),
		}));
	
		set("age", 23);
        set("per", 4);
                
        set("combat_exp", 9500000);
        
        set("chat_chance", 1);
        set("chat_msg", ({
                "С����м�غ���һ����������ɽѩ����û�У���Ȼ��û���գ�\n",
                "С��̾����������ԭ��ˮ�����˰���������Щ����Ƥ�����˲����ǡ�\n",
                "С����м�������ϰ�ҩ�����������ڵ�ҩ��Ҳ�ܳԣ�������\n",
        }) );
        
        set("inquiry", ([
    
    	]));
        
        set_skill("foreknowledge",100);
        set_skill("unarmed", 100);
        set_skill("force", 120);
        set_skill("longlife-force", 130);
        set_skill("axe", 200);
        set_skill("xuanyuan-axe", 130);
        set_skill("dodge", 100);
        set_skill("parry", 100);
        set_skill("move", 100);
        set_skill("literate",100);
        set_skill("chanting",100);
        set_skill("windy-steps", 130);
        set_skill("hanshan-strike", 120);
        set_skill("perception", 100);
        set_skill("dream-herb",100);
        set_skill("herb",100);
        
        map_skill("herb","dream-herb");
        map_skill("dodge", "windy-steps");
        map_skill("unarmed", "hanshan-strike");
        map_skill("force", "longlife-force");
        map_skill("axe", "xuanyuan-axe");
        map_skill("parry", "xuanyuan-axe");
        
        setup();
  		carry_object("/obj/weapon/axe_l")->wield();
        carry_object(__DIR__"obj/foxcloth")->wear();
}

void attempt_apprentice(object me)
{
	command("say ��ͽ�� :)");
	command("pat " + me->query("id") );
  command("recruit " + me->query("id") );
    tell_object(me,"С������Ķ�������˵�������Źر�����è������̤�루wade��ɳ�������һ������¥����ַ��\n");
    tell_object(me,"С������Ķ�������˵�����һ�Ҫ����������һЩʱ�䡣\n");
    tell_object(me,"С������Ķ�������˵������ɻ�ȥ�Ҷ����ˣ���������������ѧ��\n");
	return;
}

void recruit_apprentice(object ob)
{
    if( ::recruit_apprentice(ob) )
    	ob->set("class", "knight");
}

int accept_fight(object me)
{
        object ob;
        ob = this_object();
	
	 {
	 	command("heng");
		command("say ����������");
		return 0;
	}

   
}




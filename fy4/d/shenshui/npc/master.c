//XXDER

inherit NPC;
inherit F_MASTER;
int leave();

#include <ansi.h>

void create()
{
    	set_name("��ˮ����", ({ "master baishui", "master", "baishui" }) );
       	set("gender", "Ů��");
    	set("class", "shenshui");
    	set("age", 53);
    	set("long","
һ���˶����޹������룬�����ϴ���ǧ�ٲ㱡���������ɴ������Ҳ����ʮ��
����ɴ����Ȼ�޷磬����ɴ�Բ�ס��Ʈ��������Ȼ�������ﶯҲĩ������������
ȴ����Ҫ�𻯵��ɣ��˷��ȥ���������������еľ��飬���е����ӡ�\n");
    	set("attitude", "peaceful");
    	set("class", "shenshui");
    	   
    	create_family("��ˮ��", 11, "����");
    	set("rank_nogen",1);
        set("rank_levels",({ 16000, 32000,64000, 128000,
					256000,512000,1024000,1536000,2048000,
					3064000,4096000, 5120000,6144000,8192000,
					9999999}));
		set("ranks",({"����Ů","��Ů","С��Ů","��Ů","�������","��������",
			"��������","��������","��","�ɼ�","ħ��","����",RED"��������"NOR,
			RED"�����Ů"NOR,RED"���ڴ���"NOR,HIR"��������"NOR}));
					
    	set("reward_npc", 1);
	set("difficulty", 30);
    	set("inquiry", ([
        	"leave" : (: leave :),
    	]));  
	
    	set("per", 40);
    	    	
    	set("chat_chance_combat", 30);
    	set("chat_msg_combat", ({
        	(: exert_function, "powerup" :),
        	(: perform_action, "dodge.lianhuanbu" :),
         }) );
    

    	set("combat_exp", 15000000);
    	set("score", random(90000));

		set_skill("unarmed", 180);
		
		set_skill("advanced-unarmed", 200);
		
		set_skill("chanting", 150);
		set_skill("foreknowledge",100);
		set_skill("perception",100);
		set_skill("sword", 300);
		set_skill("force", 160);
		set_skill("parry", 200);
		set_skill("dodge", 160);
		set_skill("move",160);
		set_skill("literate",100);
		    
		set_skill("nine-moon-spirit", 200);	
		set_skill("nine-moon-sword", 200);
		set_skill("nine-moon-claw", 200);
		set_skill("nine-moon-steps", 180);
		set_skill("nine-moon-force", 180);
		    
		map_skill("dodge", "nine-moon-steps");
		map_skill("unarmed", "nine-moon-claw");
		map_skill("force", "nine-moon-force");
		map_skill("sword", "nine-moon-sword");
		map_skill("move","nine-moon-steps");

	
		set_temp("nine-moon-force_poison", 500);
    	set_temp("damage_shield/type","kee");
		set_temp("damage_shield/amount",250);
		set_temp("damage_shield/msg",MAG"$n�ƺ�մ����$N��Χ�Ķ����ֽſ�ʼ�����������\n"NOR);
	
    	set_temp("apply/dodge", 100);
		set_temp("apply/parry", 100);

    	setup();
    	carry_object(__DIR__"obj/ghostyboots")->wear();
    	carry_object(__DIR__"obj/ghostycloth")->wear();
    	carry_object(__DIR__"obj/ghostygirth")->wear();
    	carry_object(__DIR__"obj/ghostyribbon")->wear();
}


void attempt_apprentice(object ob)
{
   	if (ob->query("class")!= "shenshui") 
   		message_vision(CYN"��ˮ���￴�˿�$N˵����ˮ�����������������ˡ�\n"NOR,ob);
   	else if( ob->query("gender") != "Ů��" )
    	{
		command("shake");
		command("say ��ˮ�����书����Ů�Ӳ������������߾��硣");

	} else if (F_LEVEL->get_level(ob->query("combat_exp"))< 66) {
		command("say ����书��򲻹���������ĥ�����ǣ���66������");
	} else	if (!REWARD_D->check_m_success( ob, "��ƽ����")) {
		command("say "WHT"��ɣ������"CYN"������ԭ�������ȥ��ƽ���ʹ���ս��");
		if (!REWARD_D->riddle_check(ob,"��ƽ����"))
			REWARD_D->riddle_set(ob,"��ƽ����",1);
	} else			
	{
        	command("smile");
        	command("say �ܺã��ܺã��ܺá�");
        	command("recruit " + ob->query("id") );
			tell_object(ob, CYN"\n��ֻ��һ��ϸ΢���������˹��������㼴��������ˮ����֪��ˮ�ܾ���\n"NOR);
   			tell_object(ob, CYN"����ˮ���ɻ��Ҷ��ڴ��ƿ�ɽʯ����·������ƽɽׯ���֣����ǡ����ǡ�\n"NOR);
   			message("vision", ob->name()+ "�ƺ��ڲ������ʲô����ȴʲôҲ��������\n", environment(ob), ob);
   	}
}

void init()
{	
	::init();
	add_action("do_killing", "kill");
}


int leave() {
	if (this_player()->query("class")!="shenshui") return 0;
	message_vision(CYN"$N˵�����߿��ԣ����Ӵ˲����ڽ�����ʹ�þ����񹦡�\n"NOR,this_object(),this_player());
	return 1;
}
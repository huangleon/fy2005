
inherit NPC;
inherit F_MASTER;

/*ֻ�������ڶ�������������Ա��������ùý����ľͷ׽Ū����Ȥô?������������
�࣬Զʤ������ԧ��

 ֻ��ˮ�켧�����ƣ������������ḧ����ֻҪ�������ŵĵط�������˵�������������
����˫�ֶ��������ص�ħ��������������������С��ֻҪ����˫������һ����ʹҪ���Ʈ
������ó���

ʴ�Ļ��ǽ��ú�ɥ�Ż�
��������һ������ֻ��Ͳ�����һ���һ��ţ�������ɱ���ɫ��

*/

int leave();

#include <ansi.h>
void create()
{
    	set_name("ˮ�켧", ({ "shui tianji","shui", "master", "master shui"}) );  
    	set("gender", "Ů��");
    	set("class", "shenshui");
    	set("age", 21);
    	set("long","
�ﲨ��ˮ����Ȧ�绨�ľ�ɫ��Ů���������������������Ƿ�Ц�ݣ�����
���κ��˼��˶������ߵ��������Լ�����������ħ��������ˮ�����
Ů���������кڰ׶����˼��˳��ˮ�켧��");
    	
    	set("attitude", "peaceful");
    	set("class", "shenshui");
    	set("apprentice_available", 5);
    
    	create_family("��ˮ��", 12, "�ٹ���");
    	set("rank_nogen",1);
        set("rank_levels",({ 16000, 32000,64000, 128000,
					256000,512000,1024000,1536000,2048000,
					3064000,4096000, 5120000,6144000,8192000,
					9999999}));
		set("ranks",({"����Ů","��Ů","С��Ů","��Ů","�������","��������",
			"��������","��������","��","�ɼ�","ħ��","����",RED"��������"NOR,
			RED"�����Ů"NOR,RED"���ڴ���"NOR,HIR"��������"NOR}));
			
    	set("reward_npc", 1);
    	set("difficulty", 5);
    	set("inquiry", ([
        	"leave" : (: leave :),
    	]));  
    
    	set("chat_chance_combat", 50);
    	set("chat_msg_combat", ({
        	(: perform_action, "dodge.lianhuanbu" :),
    	}) );
    
    	set("combat_exp", 5000000);
    	set("score", random(90000));
    	
    
    	set_skill("unarmed", 150);
    	set_skill("sword", 200);
    	set_skill("force", 150);
    	set_skill("parry", 150);
    	set_skill("dodge", 150);
    	set_skill("literate",100);
    	set_skill("move",150);
    	set_skill("chanting",150);
    	set_skill("foreknowledge",100);
    	set_skill("perception",100);
    	
    	set_skill("nine-moon-spirit",150);	
    	set_skill("nine-moon-steps", 150);
    	set_skill("nine-moon-claw",  150);
    	set_skill("nine-moon-force", 150);
    	set_skill("nine-moon-sword", 180);

    	map_skill("dodge",   "nine-moon-steps");
    	map_skill("unarmed", "nine-moon-claw");
    	map_skill("force",   "nine-moon-force");
    	map_skill("sword",   "nine-moon-sword");
    	map_skill("move",     "nine-moon-steps");
    
    	set_temp("nine-moon-force_poison", 340);
    	set_temp("damage_shield/type","kee");
		set_temp("damage_shield/amount",180);
		set_temp("damage_shield/msg",MAG"$n�ƺ�մ����$N��Χ�Ķ����ֽſ�ʼ�����������\n"NOR);
	
    	set_temp("apply/dodge", 100);
    	set_temp("apply/attack", 100);

    	setup();
    	carry_object(__DIR__"obj/cloth")->wear();
}

void attempt_apprentice(object ob)
{
 		object girl;

   		if( ob->query("gender") != "Ů��" )
    		message_vision(CYN"ˮ�켧Ц�û�֦�Ҳ�������һ�������ˣ�ȴ�������ʦ������Ҳ���ߣ���\n"NOR, ob);
		else {
    		message_vision(CYN"ˮ�켧Ц������˵������Ȼ����ô���ģ��Ҿ�������ͽ�ܰɡ���\n"NOR, ob);
        	command("recruit " + ob->query("id") );        	
		}
		/*
   	else if (ob->query("marks/shenshui/С����") || ob->query("marks/shenshui/ʤ�켧")) {
    		message_vision(CYN"ˮ�켧Ц������˵����Ȼ����ô���ģ��Ҿ�������ͽ�ܰɡ���\n"NOR, ob);
        	command("recruit " + ob->query("id") );
    	
	} else 	{
        	message_vision(CYN"ˮ�켧Ц������˵����������ô�๤����ͽ�ܡ���
�����ɣ����ұ��Ա��ԣ�����㹻���飬�Ҿ����㡣��\n"NOR, ob);
		command("fight "+ ob->get_id());
   	}*/
}

void init()
{	
		object ob;
		::init();
		if( interactive(ob = this_player()) && !is_fighting() 
			&& ob->query("class")=="shenshui"
			&& ob->query("level")< 30 			// Each Login one..don't think they can carry over
			&& !ob->query_temp("marks/pfm/ss_shui")) {
				remove_call_out("greeting");
				call_out("greeting", 1, ob);
		}
		add_action("do_killing", "kill");

}

int leave() {
	if (this_player()->query("class")!="shenshui") return 0;
	message_vision(CYN"$N��Ц��һ����\n"NOR, this_object(),this_player());
	message_vision(CYN"$N˵�����߿��ԣ����Ӵ˲����ڽ�����ʹ�þ����񹦡�\n"NOR,this_object(),this_player());
	return 1;
}

void killed_enemy(object who)
{
    	command("say ��Ӵ����ôһ�¾͹��ˣ�\n");
}

void	greeting( object ob)
{
	object pipe;
	
	if (!ob || environment(ob) != environment())	return;
		
	if (ob->query("marry"))
	{
		message_vision(CYN"$N����������$n������˵�����Ա���������ɰ���"+ ob->query("marry_name")+
"������С������\n"NOR, this_object(), ob);
		return;
	}
	
	if (ob->query("age") > 25)
	{
		message_vision(CYN"$N����������$n������˵����һ�ζ����ɴ�����ˣ���û�������˰���\n"NOR,
				this_object(), ob);
		return;
	}
	
	
	message_vision(CYN"$N����������$n������˵�����Ա������Ŀ���ɰ���������֪��˭�и����ˡ���
˵��һ�Ѱ�$n���ڻ��\n"NOR,this_object(), ob);
	tell_object(ob, YEL"\n��ֻ����ˮ�켧�����ƣ������������ḧ����ֻҪ�������ŵĵط�������˵����
�������������˫�ֶ��������ص�ħ����\n"NOR);
	ob->set_temp("marks/pfm/ss_shui",1);
	// ob->delete("timer/ss_heart");
	tell_object(ob, YEL"\nˮ�켧������������˵���Ժ��ӣ��ù��ٽ���һ�У����ĸ������˸Ҵ������⣡\n"NOR);
	message_vision(CYN"$N��$n�������˼�������\n"NOR, this_object(), ob);
	pipe = new(__DIR__"obj/pipe");
	if (!pipe->move(ob)) destruct(pipe);
	return;
}	
	
int accept_object(object who, object ob)
{
        if (ob->query("name") == HIM"����"NOR && ob->query("ss_shui"))
        {
			if ( who->query("level")>= 30 )
			{
				message_vision(CYN"ˮ�켧գ��գ��˵���Ա��������ˣ������ﲻҪҲ�ա�\n"NOR, who);
				return 1;
			}
			
			if (who->query("level")> 24)	// it's the easiest way to remove the mark...
				who->delete_temp("marks/pfm/ss_shui");
			
        	if (ob->query("ammo")<1)
        	{
        		message_vision(CYN"ˮ�켧������"+ ob->name() + CYN"�Ϸɿ�ز��˼���˵��������\n"NOR, who);
				ob->set("ammo", 10);
				who->delete("timer/ss_heart");
				return 0;
        	}	
        
        	message_vision(CYN"ˮ�켧˵��" + ob->name()+ CYN"���ǻ�����ô��\n"NOR, who);
    	}		
		return 0;
}
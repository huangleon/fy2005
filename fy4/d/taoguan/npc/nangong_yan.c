//XXDER ������������ˮ���Ľ������� ͻ��һ����Ӱ��������һƬѩ����

//Ʈ������

//    ҹ����ˮ����ɽ����һ�ߴ���������磬����þ���ͬ������ë���������ǹ�������

//���ϡ�����ӯ�������ݷ�������������ҹ�С�

inherit NPC;
int leave();

#include <ansi.h>
void create()
{
    	set_name("������", ({ "gong nanyan","gong"}) );  
    	set("gender", "Ů��");
    	set("class", "shenshui");
    	set("age", 21);
    	set("long","
���Ǹ�����������Ů������ѩ�׵��·����ںڵĳ�����ѩ�׵�����ͬ
ʱ�ڷ���Ʈ����������ᳬȺ���ס�");
    	
    	set("attitude", "peaceful");
    	set("class", "shenshui");
    	set("apprentice_available", 5);
    
    	
    	set("reward_npc", 1);
    	set("difficulty", 5);
    	
    	set("chat_chance_combat", 50);
    	set("chat_msg_combat", ({
        	(: perform_action, "dodge.lianhuanbu" :),
    	}) );
    
    	set("combat_exp", 5000000);
    	set("score", random(90000));
    	
    
    	set_skill("unarmed", 140);
    	set_skill("sword", 150);
    	set_skill("force", 150);
    	set_skill("parry", 120);
    	set_skill("dodge", 120);
    	set_skill("literate",140);
    	set_skill("move",120);
    	set_skill("charm",140);
    	set_skill("move",120);
    	set_skill("nine-moon-spirit", 120);	
    	set_skill("nine-moon-steps", 150);
    	set_skill("nine-moon-claw", 120);
    	set_skill("nine-moon-force", 150);
    	set_skill("nine-moon-sword", 150);

    	map_skill("dodge", "nine-moon-steps");
    	map_skill("unarmed", "nine-moon-claw");
    	map_skill("force", "nine-moon-force");
    	map_skill("sword", "nine-moon-sword");
    	map_skill("move","nine-moon-steps");
    
    	set_temp("nine-moon-force_poison", 340);
    	set_temp("damage_shield/type","kee");
	set_temp("damage_shield/amount",180);
	set_temp("damage_shield/msg",MAG"$n�ƺ�մ����$N��Χ�Ķ����ֽſ�ʼ�����������\n"NOR);
	
    	set_temp("apply/dodge", 100);
    	set_temp("apply/attack", 100);

    	setup();
    	carry_object(__DIR__"obj/white_cloth")->wear();
}

/*
void reset()
{
    delete_temp("learned");
    set("apprentice_available", 5);
}

void attempt_apprentice(object ob)
{
    if( query("apprentice_available") ) {
        if( find_call_out("do_recruit") != -1 )
            command("say ������һ��һ������");
        else
            call_out("do_recruit", 2, ob);
    } else {
        command("say ��ʹ�߽����Ѿ�����������ӣ���������ͽ�ˡ�");
    }
}

void do_recruit(object ob)
{
    	object girl;

   	if( ((int)ob->query("cor") < 10) || ((int)ob->query("cps") < 10)
        	|| ((int)ob->query("int") < 10)
        	||      ((int)ob->query("con") < 10)) {
        	command("say ����ˮ����Ҫ��Ե�ݣ����ҿ�" +
                	RANK_D->query_respect(ob) + "�;���������Ե��");
        	return;
    	}
    	if( (string)ob->query("gender") != "Ů��" )
    	{
		command("shake");
		command("say ��ˮ�����书����Ů�Ӳ������������߾��硣");

	} else {
        	command("smile");
        	command("say �ܺã��ܺã��ܺá�");
        	command("recruit " + ob->query("id") );
		tell_object(ob, HIY"\n��ֻ��һ��ϸ΢���������˹����������������ˮ����֪��ˮ�ܾ���\n"NOR);
   		tell_object(ob, HIY"����ˮ���ӿ������������������´�ʦ�����������أ���������ˮ�ܵ���\n"NOR);
   		message("vision", ob->name()+ "�ƺ��ڲ������ʲô��ȴʲôҲ��������\n",
   				environment(ob), ob);
   	}
}

int recruit_apprentice(object ob)
{
    	if( ::recruit_apprentice(ob) )
        	ob->set("class", "shenshui");
    	add("apprentice_availavble", -1);
}

void init()
{	
	::init();
	add_action("do_killing", "kill");
}

int do_killing(string arg)
{
    object player, victim;
    string id,id_class;
    player = this_player();
    if(!arg || arg == "") return 0;
    victim = present(arg, environment(player));
        if(!objectp(victim))
		return notify_fail("����û������ˡ�\n");
    if(living(victim))
    {
        id_class=victim->query("class");
        id=victim->query("id");
       	if(id_class == "shenshui"&& userp(victim)&&player!=victim)
        {
message_vision(HIW"$N����$n�ȵ���" + RANK_D->query_rude(player) 
						+ "����ɱ" + RANK_D->query_self_rude(this_object()) 
						+ "��ͽ�ܣ�ȥ���ɡ�\n"NOR, this_object(), player);
            this_object()->kill_ob(player);
            player->kill_ob(this_object());
            if (!player->is_busy()) player->start_busy(2);
            return 0;
        } 
    }
    return 0;
}


int leave() {
	if (this_player()->query("class")!="shenshui") return 0;
	message_vision(CYN"$N��Ц��һ����\n"NOR, this_object(),this_player());
	message_vision(CYN"$N˵�����߿��ԣ����Ӵ˲����ڽ�����ʹ�þ����񹦡�\n"NOR,this_object(),this_player());
	return 1;
}

*/
inherit NPC;
#include <ansi.h>
int do_hint();

void create()
{
		set_name("����", ({ "afei", "fei" }) );
		set("gender", "����" );
        set("title", HIG "��Ϊ����" NOR);
		set("age", 20);
		set("class","assassin");
		set("per", 30);
		set("long","�����޵У���������\n");
	        
        set("reward_npc", 1);
		set("difficulty", 30);
                
        set("inquiry", ([
	         "÷����" : (: do_hint :),
		]) );
        
        set("combat_exp", 10000000);
        set("score", 90000);
        set("fy41/jq_sharenruma",1);
       	set_temp("apply/haste",300);         
        
        set_skill("sword", 400);
        set_skill("force", 400);
        set_skill("parry", 400);
        set_skill("dodge", 400);
        set_skill("sharen-sword", 250);
		set_skill("lefthand-sword",300);
		set_skill("jinhong-steps",250);
		set_skill("unarmed",400);
		set_skill("flame-strike",200);
		set_skill("move",200);
		
		map_skill("unarmed","flame-strike");
		map_skill("sword", "sharen-sword");
		map_skill("parry","lefthand-sword");
		map_skill("dodge","jinhong-steps");
		map_skill("move","jinhong-steps");
	        
        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: perform_action, "sword.sharenruma" :),
        }) );
	
		setup();
		carry_object("/obj/armor/cloth")->wear();
        carry_object(__DIR__"obj/toysword")->wield();
}

int do_hint(){
	message_vision("����������üͷ˵����÷�������˺��ˣ���������ȥ��˭����rescue��\n",this_object());
	return 1;
}

int accept_fight(object me)
{
        command("grin");
        command("say �ҵĽ�������ɱ�˵ģ����������Ȼ�����ġ�");
        return 0;
}

void init()
{
	add_action("do_killing", "kill");
	add_action("do_rescue", "rescue");
	::init();
}

int do_killing(string arg)
{
	
	object player, victim, weapon;
	string name;
	player = this_player();
	if( !arg) return 0;
	if( objectp(victim = present(arg, environment(this_object()))) && living(victim))
	{
		name = (string)victim->name();
		if( (string)name == "���ɶ�")
		{
		message_vision("$N��Цһ�������ҿ�����̫���ˡ�\n", this_object());
		this_object()->kill_ob(player);
		player->kill_ob(this_object());
		return 1;
		}
	}
	return 0;		
}



int do_rescue(string arg)
{
	
	object player, victim, room;
	string name;
	player = this_player();
	if( !arg) return notify_fail("�����ð��ɾ�˭��\n");
	victim = find_player(arg);
	if( !objectp(victim)) return notify_fail("û������˰���\n");
	message_vision("\n$N���Ż̵̻ض԰��ɺ����ɽ��ͣ������ˣ�" + victim->name() + "��÷���������ˡ�\n\n", player);
	if( !victim->query_temp("marks/meihuadao") )
		return notify_fail("��������üͷ˵��������˱�÷���������ˣ���ҥ���ɣ���\n");

	message_vision("\n$N���еؿ������ɶ�һ�ۣ���$n˵������ȥ��԰�ú���Ѱһ�£������Ͼ͵���\n", this_object(),player);
	player->set_temp("afei_on_the_way", 1);
	return 1;
}

int kick_player(object ob)
{
    	if( ob->query("gender") == "Ů��")
         	call_out("do_kick", random(20)+10,ob);
    	else
         	call_out("do_kick", random(10)+5,ob);
    	if(!random(8))
    		ccommand("heihei "+ob->query("id"));
    	else
    		command("heng");
    	return 1;
}


void do_kick(object ob)
{
    	object room;
    	if(environment(ob) == environment(this_object()))
    	{
        
        	message_vision(CYN"$Nĥ��ĥ����\n"NOR, this_object());
        	message_vision(CYN"$N��ݺݵص���$nһ�ۡ�\n"NOR, this_object(), ob);
	        message_vision(HIB"\n���ɵĽ��ƺ����˶���$Nֻ���ú���һ�ۣ��Բ��߸󶥳��Ƽ������˳�ȥ������\n\n"NOR,ob);
        	room=find_object(AREA_QIANJIN"boat3");
        	if(!objectp(room))
             		room=load_object(AREA_QIANJIN"boat3");
        	ob->move(room);
        	message_vision(BLU"\nֻ��һ����Ӱ�ƴ�������$N������͸�˵�����һ��׹�䣬����ˮ���Ľ���\n����ͨ��һ��������У����ô��Ϻ�����Ů���С��������\n\n"MAG"$Nʪ���ܵĴӺ�����������������\n\n"NOR,ob);
        	ob->receive_damage("kee",100);
        	ob->set_temp("last_damage_from","Ī�����������ǧ��¥�\n");
       		ccommand("emote ������������֡�");
    	}
}


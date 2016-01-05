inherit SMART_NPC;
inherit F_MASTER;
#include <ansi.h>
void smart_fight();
int jice();

void create()
{
    	set_name("�ϵ�����", ({ "master lao dao", "master"}) );
    	set("gender", "����" );
    	set("class","wudang");
    	set("long", "�������ۣ�ͷ�����ң�������������ʵĹ�ꡣ\n" );
    	set("age", 45);

    	set("per", 30);
    	set("reward_npc", 1);
    	set("difficulty", 25);
    	set("fly_target",1);
    
    	create_family("����ɽׯ", 1, "ׯ��");
    	
    	set("inquiry", ([
        	"�����ķ�":  "�����ķ�������ʮ��չ��������ã���[����Ʊ�]������һ����\n",
        	"����Ʊ�":  "�˾�������������ǿ��ֻ�ִ�У��������ú����书��������ʹ�á�\n",
        	"ʯ��":  "�㲻�������£�����������㣿\n",
        	"������":  "�㲻�������£�����������㣿\n",
			"��������" : (: jice :),

        ]) );

    	set_temp("apply/haste",300);
    	set("combat_exp", 10000000);
    	set("score", random(90000));
    
    	set("skill_public", 1);

		set("perform_busy_w", "wudang/sword/three-sword/nianzijue");
//		set("perform_weapon_attack","wudang/sword/three-sword/sancai");
		
		set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(100) :),
        }) );
    
    	set_skill("foreknowledge", 160);
    	set_skill("liangyi-force",180);
    	
    	
    	set_skill("changelaw",220);
    	set_skill("perception", 300);
    	set_skill("changelaw", 150);
    	set_skill("unarmed", 200);
    	set_skill("sword", 300);
    	set_skill("move", 200);
    	set_skill("force", 200);
    	set_skill("parry", 300);
    	set_skill("dodge", 250);
    	set_skill("three-sword", 220);
    	set_skill("taiji", 200);
    	set_skill("five-steps",200);
    	
    	map_skill("force","liangyi-force");
    	map_skill("unarmed", "taiji");
    	map_skill("sword", "three-sword");
    	map_skill("parry", "three-sword");
    	map_skill("dodge","five-steps");
	
    	setup();
    	carry_object(__DIR__"obj/cloth3")->wear();
    	carry_object(__DIR__"obj/hat")->wear();
    	carry_object(__DIR__"obj/swordd")->wield();
}


void attempt_apprentice(object ob)
{
       	call_out("do_recruit", 2, ob);
}

int recognize_apprentice(object ob)
{
    	return ( ob->query("free_learn/foreknowledge"));
}


int jice()
{
	object me;
	me = this_player();
	if(REWARD_D->riddle_check(me,"�䵱����") != 3)
		return 0;

	REWARD_D->riddle_set(me,"�䵱����",4);
	ccommand("hmm");
	ccommand("say ������ϵ���������ǰ�����������ô���ڻ����ˣ�");
	ccommand("emote ������ɵش������㣺��ò�����ƭ�Ұɣ�");
	ccommand("hmm");
	ccommand("say �Ϸ��Ѿ����ͷ��ˣ��������ǣ������Լ����֣�");
	ccommand("say �㣬����ȥ"HIG"ɱʯ��"NOR CYN"���������������ң�");
	ccommand("say �һ����˰�����Ҫ�Ķ����ص�"MAG"�䵱ɽ��һ����"NOR"����Լ�ȥ�ðɡ�");
	ccommand("wave");
	tell_object(me,WHT"������ɱʯ���¹��ش󣮣���������ȥ��������˵һ˵�ɡ�\n"NOR);
	return 1;
}


void do_recruit(object ob)
{
    	if((int)ob->query_temp("marks/���Ʒ�")) {
        	command("stare " + ob->query("id"));
        	command("say �㲻��������ϸ�İɣ�\n");
        	return;
    	}
    	else  if((int)ob->query_temp("marks/����ɽׯ")) {
        	say("\n");
			ccommand("hmm");

			if (REWARD_D->riddle_check(ob,"�ž�����") == 3)
			{ 

	        	command("say �����ݺ����顣\n");
	        	command("say ����ȥ���䵱ɽ����ɽ֮�����ǽ��������ң�������չ������㣮����\n");
				ccommand("heihei");
	        	command("say ��������ǡ�"HIG"��­��"NOR CYN"��������ʲô��\n");
				REWARD_D->riddle_set(ob,"�ž�����",4);
			}

        	return;
    	}
    	else {
		command("sigh");
        	command("say �����Ѳ���ͽ���ˣ�");
    	return;
    }
}


int accept_object(object who, object ob)
{


	if (ob->query("name")=="��ʯ����" 
		&& ob->query("id") == "fried meat" 
		&& REWARD_D->riddle_check(who,"�䵱����") == 6)
	{
	// �ðɣ�����������pet��ʯ�㣬�û����Ѿ���ɹ�ɱ���������ˡ���

		command("haha");
		command("laugh master");

		command("say �ã��ã�ʯ�㰡ʯ�㣬�������������³���\n");
		command("say ��������ɵ��Ϸ��洫��\n");
		REWARD_D->riddle_done(who,"�䵱����",50,1);
		return 1;
	}

    	if((string)ob->name() != "���ǽ�") return 0;
    	if(REWARD_D->riddle_check(who,"�ž�����") < 7) return 0;
    	if(REWARD_D->riddle_check(who,"�ž�����") == 7)
		{
			tell_object(who,HIG"��ͻȻ���û����Ȱѱ�����ȥ������������Ϊ�ϡ�\n"NOR);
			return notify_fail(" ");
		}

    	if(ob->query("real") && (object)ob->query_temp("marks/owner") == who)
    	{

			REWARD_D->riddle_set(who,"�䵱����",2);

        	command("spank " + who->query("id"));

			REWARD_D->riddle_done(who,"�ž�����",50,1);

	    	who->set("free_learn/foreknowledge", 1);
        	command("say ����Ҫ�书�ؼ�����������ѧ�䣿"HIY"(accept book/teach?)"NOR);
        	say("\n");
        	command("sigh");
        	command("say ���֤�����֣�Ҫ�Ҵ�ʯ�㣬�����䵱��λ���練�ƣ�");
        	command("say ֻ��Լ�����޽�������ô�Ǳ߻�û����Ϣ��");
        	say("\n");
        	command("consider");
        	command("say �����пգ��������ȥ��ɽ�������ǣ���һ����ô���㡣");
        	say("\n");
			who->set_temp("marks/�õ����Ǳ���", 1);
        	add_action("do_accept", "accept");
    	}
    	else
    	{
        	say("�ϵ����ӽӹ����ǽ�����ϸ�ؿ��˿���\n");
        	command("sigh");
        	command("say ��һ�����Ǽٵģ�");
    	}
    	return 1;
}

int do_accept(string arg)
{
    	object me, book;
    
    	if(!arg || (arg != "book" && arg != "teach")) 
        	return notify_fail("����Ҫʲô��\n");
    	me = this_player();
    	if(!me->query_temp("marks/�õ����Ǳ���")) return 0;
    	me->delete_temp("marks/�õ����Ǳ���", 0);
    	if(arg == "book")
    	{
        	book = new(BOOKS"skill/wudang_40");
        	book->move(this_object());
        	book->move( me);
       		message_vision("�ϵ����ӵݸ�$Nһ��������С���ӡ�\n", me); 	
     //   	command("give book to " + me->get_id());
        	command("say �㹦�Ͳ�С�������㻹��������ѧ�䣨�����ķ���ռ��ѧ��");
    	}
    	else 
        	command("say �ӽ��쿪ʼ�������ͬ��ѧ���ˣ������ķ���ռ��ѧ��");
    	return 1;
}


smart_fight()
{
	int i;
	object *enemy, who;
	who = this_object();
	enemy = this_object()->query_enemy();
	for(i=0; i<sizeof(enemy); i++) {
	if (!enemy[i]->is_zombie() && enemy[i]->query("id")!="guard") 
		if (random(2)) who->perform_action("sword.nianzijue"); 
			else who->perform_action("dodge.bazhentu");
	}
	return;
}  

	
int prevent_learn(object me, string skill)
{
	if (!REWARD_D->check_m_success(me,"�ž�����"))
  	{
      		command("heihei");
      		command("say ���������£�����ѧ�䣬�������������ô�õ����飿");
      		return 1;
  	}
	

  	if (skill != "foreknowledge" && skill != "liangyi-force")
  	{
      		command("shake");
      		command("say �ҿ�ֻ��Ӧ���������ķ���ռ��������");
      		return 1;
  	}


	if (me->query_skill("foreknowledge",1) >= 150 && skill != "liangyi-force" && !REWARD_D->check_m_success(me,"�䵱����"))
	{
      		command("sigh");
      		command("say �Ϸ����û�����飬����������ɡ�");
			return 1;
	}

	if (me->query_skill("liangyi-force",1) >= 150 && skill != "foreknowledge" && !REWARD_D->check_m_success(me,"�䵱����"))
	{
      		command("sigh");
      		command("say �Ϸ����û�����飬����������ɡ�");
			return 1;
	}

  	return 0;
}


int prevent_shown(object me, string skill)
{
	if (me->query("free_learn/foreknowledge") 
		&& (skill == "liangyi-force" || skill == "foreknowledge"))
		return 0;
	
	return 1;
}
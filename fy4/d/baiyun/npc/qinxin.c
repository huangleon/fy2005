// XXDER@FY3
inherit NPC;
#include <ansi.h>

int leave();

void create()
{
    set_name("����" , ({ "qin xin","qin" }) );
    set("nickname",HIC"������"NOR);
    set("long", "
һ������Ů��ϯ�ض�����ϥ�Ϸ���һ�Ž�β�٣����Ե��ࡣ������ľ��ͣ����
�������������һ��һ�𣬻������ͳ���\n");
	set("attitude", "friendly");
    set("age", 22);
    set("per",40);
    set("class","huashan");
    set("gender", "Ů��" );      
    create_family("���Ƴ�",1, "��Ů");
    set("combat_exp", 2500000);
        set("chat_chance", 1);
        set("chat_msg", ({
        "�������ϥ�����٣����������ﻥ��Ӧ�𣬼��عأ���ת������\n",
        "������ü΢�����������ߺ��ͣ�������죬�����һ����һ�������ҡ���Ȼ���ˡ�\n",
	}) );
         set("inquiry",  ([
				"���ν���" :  (: leave :),
        ]) );

set_skill("music", 150);
   	set_skill("magic", 150);
   	
   	set_skill("dodge", 200);
    set_skill("anxiang-steps", 200);
    set_skill("qingfeng-sword", 200);
    set_skill("sword", 200);
    set_skill("unarmed", 100);
    set_skill("iron-cloth", 100);
    set_skill("spring-water", 100);
    map_skill("iron-cloth","spring-water");
    map_skill("sword","qingfeng-sword");
    map_skill("dodge","anxiang-steps");
        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.yexuechiji" :),
        }) );

	setup();
    carry_object("/obj/armor/cloth")->wear();
    carry_object(__DIR__"obj/lvqi");
    carry_object("/obj/weapon/sword")->wield();
}

void attempt_apprentice(object ob)
{
    command("say  СŮ��ֻ���գ�����ͽ��");
	return;
    	
}

void init()
{       
        object ob;
        ::init();
        if ( interactive(ob = this_player()) && !is_fighting() ) 
           {
             remove_call_out("greeting");
             call_out("greeting", 1, ob);
           }
}


void greeting(object ob)
{
        object qin;
        if( !ob || environment(ob) != environment() ) return;
		
		qin = this_object();
		
		if (ob->query("free_learn/music") && !ob->query("annie/music_choose"))
		{			
			message_vision(CYN"������$Nӯӯ���£�˫�������������Զ��꣬����һ��������ˡ�\n"NOR,ob);
			tell_object(ob,CYN"ϸϸ������������СŮ������ΪЩ��Ը���������ڡ�\n"NOR);
		}
		return ;
}

int leave()
{
	object room = load_object("/d/baiyun/dragonplace");
	int i = REWARD_D->riddle_check(this_player(),"��ͼһ��");
	if (is_fighting())
	{
		tell_object(this_player(),name()+"��æ���˲���������\n");
		return 1;
	}
	
	if ( i !=4 && i != 5 && i != 6)
		return 0;
	if (environment() == room)
		return 0;
	delete("chat_msg");
	message_vision(WHT"$Nüͷһ�壬����̾�˿�������Ҷʦ�֣������ڶ����ǿ�ʼ������ô��\n$N����һ������β�����Ҿ�ϣ����׶�ȥ��\n"NOR, this_object());
	move(room);
	return 1;
}


int do_answer(string arg) // ȥ����!!!! ><"
{
	object me;
	int a;
	me = this_player();
	
	if (!arg || sscanf(arg, "%d", a)!=1)
		return notify_fail("��Ҫѡ��ʲô��\n");
	if (a<1 || a>5)
		return notify_fail("��Ҫѡ��ʲô��\n");

	if (a== 5)
	{
		message_vision(CYN"������ɫ����תΪ�԰ף��૵�����Ȼ�������У���Ȼ������\n"NOR,me,this_object());
		message_vision(CYN"�����������������$N����Զ�������ǣ����ǣ��������ţ���Ϊ����һ��ĩ�����꣮����\n"NOR,me,this_object());
		message_vision(HIR"\n���ĺ��Խ�β���³��һ��ذ��,̧�ִ������Լ��ؿڣ���Ѫ�ɽ�������Ⱦ�������ɷ�Բ��\n"NOR,me,this_object());
		message_vision(WHT"\nһ����ң������ԶԶ�԰��Ƴ��д������ڷ�������Ʈɢ��\n"NOR,me,this_object());
//		me->set("annie/music_choose",-1);	// you can choose again
		delete_temp("last_damage_from");
		die();
		return 1;
	}

	me->set("annie/music_choose",a);
	message_vision(CYN"����ĬȻ���Σ�������˵�ͷ��\n"NOR,me,this_object());
	return 1;
}

int recognize_apprentice(object ob)
{
	
	if (!ob->query("free_learn/music"))
	{
		if (ob->query("free_learn/by_magic"))
			return 1;
		ccommand("bored "+ob->id(1));
		return 0;
	}
		
	if (!ob->query("annie/music_choose"))
	{
		message_vision(CYN"\n����΢һ���ң�������̾�˿��������˵�ͷ�����ж�����ģ������Ե��౨��\n"NOR,ob,this_object());
		message_vision(CYN"����̧�������峺����һϴ���յ�˫��������$N���ϣ����������Ժ���ر���\n"NOR,ob,this_object());
		message_vision(HIW"����1"HIY"ʮ������� "HIW"2"HIY"����ˮ���� "HIW"3"HIY"�̺������� "HIW"4"HIY"���������� "
		HIW"5"HIY"��������� \nѡ��һ�answer 1-5\n"NOR,ob,this_object());
		add_action("do_answer","answer");
		ob->set_temp("annie/choose_music",1);
		return 1;
	}

    return 1;
}



int prevent_learn(object me, string skill)
{
  	if (skill == "magic" && me->query("free_learn/by_magic"))
  		return 0;
  	
  	if (skill == "music" && me->query("free_learn/music"))
  		return 0;
  
   	command("emote ����������ң�����ӯӯˮ�⡣");
   	command("flook");
   	return 1;
   	
}


int prevent_shown(object me, string skill)
{
	
	if (skill == "magic" && me->query("free_learn/by_magic"))
		return 0;
		
	if (me->query("annie/music_choose") == -1)
		return 1;

	if (me->query("free_learn/music") && (skill == "music"))
		return 0;
	
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

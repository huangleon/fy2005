inherit SMART_NPC;
#include <ansi.h>

int smart_fight();

void create()
{
    set_name("�����۵�������" , ({ "nanwang prince","prince" }) );
    set("long", "һ����Ӣͦ�������ˣ����ϴ��ż����ۣ��·�����ʯ���ֵİ˱�\n��ˮȹ���⣮�������ѵ��ǵ�������ӣ���������������������һ��\n���ص�С��� \n");
	set("attitude", "friendly");
    set("age", 22);
	set("gender", "����" );
	set("title",HIY"��������"NOR);
    set("per",40);
    set("combat_exp", 3000000);
    set_skill("dodge", 200);
    set_skill("fall-steps", 200);
    set_skill("sky-sword", 200);
    set_skill("sword", 200);
    set_skill("unarmed", 100);
    set_skill("iron-cloth", 100);
    set_skill("henglian", 200);
	set("NO_KILL","�������������ǣ����ɺ��Ҷ��֣�����ٸ�׷ɱ��\n");
    map_skill("iron-cloth","henglian");
    map_skill("sword","sky-sword");
	set("nb_chat_chance", 100);
	set("nb_chat_msg_combat", ([
		100: 	(: smart_fight() :),
	]) );    	

	setup();
    carry_object(__DIR__"obj/byrobe")->wear();
    carry_object(__DIR__"obj/hanguang")->wield();
}

void init()
{       
	object ob;
	::init();
	add_action("do_kneel", "kneel");
	add_action("do_reject", "reject");
	if ( interactive(ob = this_player()) && !is_fighting() ) 
	   {
	     remove_call_out("greeting");
	     call_out("greeting", 1, ob);
	   }
}

void greeting(object ob)
{
	if (userp(ob))
		message_vision(HIY"
�����۵������������������������죬��گ���ȵۣ��˾���֮�����֮����
���Ȼ����¹�(kneel/reject)��\n"NOR, ob);

}

int do_kneel()
{
	object me = this_player();
	if (me->is_fighting() || me->is_busy())	return 1;
	message_vision("$N����һ�������˻��֣��������¡�\n", this_object()); 
	me->move(load_object("/d/baiyun/changlang2"));
	return 1;
}

int do_reject()
{
	object me;
	me = this_player();
	message_vision(CYN"$N��ɫ�ޱ䣬��Х������ŭ�ȵ���������˴󵨣����˰���
�����˵���նɱ֮�� \n"NOR, this_object()); 
	me->kill_ob(this_object());
	this_object()->kill_ob(me);
	smart_fight();
	return 1;
}


int summon_master()
{
	object me=this_object(),room,ye,env=environment(me);
   	message_vision(HIB "\n$N˻���е���Ҷ��ң������������ݣ�\n" NOR, me);   
	room=load_object("/d/baiyun/baiyunguan");
	ye = present("master ye",room);
	if (!ye)
		return 0;
	ye->invocation(me,env);
	return 1;
}

void die()
{
	object killer, owner;
	object *enemy, ob;
	int i;
	
	enemy = query_enemy();
	
	if (enemy && sizeof(enemy)>0)
	for (i=0;i<sizeof(enemy);i++) {
		ob = enemy[i];
		if (objectp(enemy[i]->query("possessed")))
			ob = enemy[i]->query("possessed");
		if (!userp(ob)) continue;
		if (REWARD_D->riddle_check(ob,"��ͼһ��") ==12)
			REWARD_D->riddle_set(ob,"��ͼһ��",13);	
	}			
	
	if (present("master ye",environment()))
	{
		message_vision(CYN"$N�ҽе�����������������������\n"NOR, this_object());
		::die();
		return;
	}
	if (!query("summoning"))
	   	summon_master();
	
	if (enemy && sizeof(enemy)>0)
	for (i=0;i<sizeof(enemy);i++) {
		ob = enemy[i];
		if (objectp(enemy[i]->query("possessed")))
			ob = enemy[i]->query("possessed");
		if (!userp(ob)) continue;
		if (REWARD_D->riddle_check(ob,"��ͼһ��") ==13)
			tell_object(ob,WHT"
����ͷ��ת�������Ҷ�³ǽ���׿�����������У�����ѽ������ʥ�Ͻ����
������ֹҶ�³ǵ���ı����Ҷ�³�����Ұ�ģ�һ�Ʋ��ɣ�����������������
�߻��ǲ��ߣ���leave)\n"NOR); 
	}

	::die();
	return;
}

int smart_fight()
{
	object me = this_object(),soldier,*inv;
	int i;
	add_temp("max_guard",1);
	inv=all_inventory(environment());
	for (i=0; i<sizeof(inv); i++)
		if (inv[i]->query("master") == me)
			inv[i]->invocation(me);
	if (!SMART_D->check_health(me,25) && !query("summoning"))
	{
		set("summoning",1);
		summon_master();
	}
	if (query_temp("max_guard") >= 7)	// ����ٻ�7��guard.
		return 1;
   	message_vision(HIB "\n$N����һ����Х��Ԯ��\n" NOR, me);   
	seteuid(getuid());
	soldier= new(__DIR__"annguard");
	soldier->move(environment(me));
	message_vision(HIB "\n$NӦ��������\n" NOR, soldier);
	soldier->invocation(me);
	if (soldier)
       	me->remove_all_killer();
}

/*
 
               (\~~~/)            
               ( ����)        

               (_____)~��      
   
��������������- FengYun - ������
������������annie 10.2003
������dancing_faery@hotmail.com
*/

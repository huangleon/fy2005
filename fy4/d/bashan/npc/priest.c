

inherit NPC;
#include <ansi.h>
#include <combat.h>
void smart_fight();

void create()
{
	object armor,weapon;
	set_name("����", ({ "jia ruo","jia","ruo"}) );
	set("gender", "����");
	set("title",YEL"�Ϲ�¥�� "NOR HIB"���˾��"NOR);
	set("nickname",WHT"����֮��"NOR);
	set("age", 20+random(10));
	set("long","\n");
    set("combat_exp", 8000000);	
    set("score", 10000);
	set("fle",50);
	set("cor",40);
	set("cps",30);
	set("str",40);
	set("force_factor",180);
	set("per",40);

	set("no_fly",1);
	set("no_curse",1);
	set("no_arrest",1);

	set("max_kee",24000);
	set("max_gin",16000);
	set("max_sen",16000);

	set_skill("demon-blade",240);
	set_skill("blade",200);

	set_skill("demon-steps",200);
	set_skill("fall-steps",340);
	set_skill("anxiang-steps",200);
	set_skill("cloud-dance",200);
	set_skill("move",200);
	set_skill("dodge",200);

	set_skill("demon-force",200);

    set_skill("perception",200);

	set_skill("meihua-shou",210);
  	set_skill("unarmed", 300);
	set_skill("force", 200);

	set_skill("lingxi-zhi", 170);
	set_skill("spells",200);
	set_skill("parry",200);
	set_skill("kwan-yin-spells",200);
	set_skill("five-steps",180);
	set_skill("move",200);
	set_skill("dodge",200);
	set_skill("divineforce",200);	

	set_skill("qiuzhi-sword",250);
	set_skill("daimonsword",250);
	set_skill("zensword",250);
	set_skill("sword",200);

	map_skill("spells","kwan-yin-spells");
	map_skill("unarmed", "lingxi-zhi");
	map_skill("force", "divineforce");
	map_skill("dodge","cloud-dance");
	map_skill("move","anxiang-steps");
	map_skill("sword","daimonsword");
	map_skill("parry","qiuzhi-sword");
	
    	
        add_temp("apply/iron-cloth", 200);
	
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
               (: smart_fight() :),
        }) );

	setup();


	setup();
    armor=new("/obj/armor/cloth");
	armor->set_name("���İ�ɳ���",({"cloth"}) );
	armor->move(this_object());
	armor->wear();

    carry_object(__DIR__"obj/chusword1")->wield();
    carry_object(__DIR__"obj/chusword2")->wield();

    set("reward_npc", 1);
	set("difficulty",7);
	set("resistance/kee",100);

}

object select_opponent() 	
{
	object * enemy;
	int i;
	enemy = query_enemy();
	if(!sizeof(enemy)) {
		return 0;
	}
	clean_up_enemy();
	if(!sizeof(enemy)) {
		return 0;
	}
	for(i=0; i<sizeof(enemy); i++)
		if (userp(enemy[i]))
			return enemy[i]; // focus user. ; annie 6.25.03
	return enemy[0];	// ��0ɱ��
}

int kill_ob(object who)
{
	int a = query_busy();

	if (base_name(who) == "/obj/npc/danei" || base_name(who) == "/obj/npc/danei_guard")
	{
		message_vision(HIW "$N�������֣������е���ǹ���˸��ɲ�Ǽ�����������ţ�����\n" NOR,this_object());
		who->die();
		return 1;
	}

	::kill_ob(who);
	smart_fight();
	return 1;
}

int bbqthem(object me, object obj) 
{
	int spells, busy_num,mod,magic;
	string id_enemy;
	
	spells = 750;        

	mod = COMBAT_D->can_busy(me, obj, "kwan-yin-spells");   
	
	obj->set_temp("last_damage_from",me);
	if(obj->is_ghost()) {
			obj->die();
			return 1;
	}
	if(obj->is_zombie()) {
			obj->die();
			return 1;
	}

	if(obj->query("combat_exp") /10 * mod >random(me->query("combat_exp")/100 * spells))
	{
		message_vision(CYN"$N��æת��ͷȥ������$n��\n"NOR,obj,me);
		return 1;
	}

    magic = 4*random(400)+1;

	if(userp(obj))
	{
		tell_object(obj,HIW"��ֻ������ǰ��ãã��һƬ��ʲô���������ˡ�����\n"NOR);
		obj->add_temp("block_msg/all",1);
		obj->start_busy(3 + random(2));
		message_vision(CYN"$Nʹ�����ס�۾���ֱ�ڵ��ϴ����\n"NOR,obj);
		obj->add_temp("block_msg/all",-1);
		obj->receive_damage("sen",magic,me);
		obj->set_temp("damaged_during_attack", 1);
		COMBAT_D->report_status(obj);
		obj->add_temp("block_msg/all",1);
		call_out ("recovers",10, obj);
	}
	else
	{
		obj->start_busy(3+random(2));
		message_vision(CYN"$Nʹ�����ס�۾���ֱ�ڵ��ϴ����\n"NOR,obj);
		obj->receive_damage("sen",magic,me);
		obj->set_temp("damaged_during_attack", 1);
		COMBAT_D->report_status(obj);
	}
	return 1;
}

int bbqthem2(object me, object obj) 
{
	int spells, busy_num,mod,magic;
	string id_enemy;
	
	spells = 750;        

	mod = COMBAT_D->can_busy(me, obj, "kwan-yin-spells");   
	
	obj->set_temp("last_damage_from",me);
	if(obj->is_ghost()) {
			obj->die();
			return 1;
	}
	if(obj->is_zombie()) {
			obj->die();
			return 1;
	}

	if(obj->query("combat_exp") /10 * mod >random(me->query("combat_exp")/100 * spells))
	{
		message_vision(CYN"$N�������Σ��������ߣ��㿪�������������硣\n"NOR,obj,me);
		return 1;
	}

    magic = 4*random(800)+1;
	message_vision(HIB BLK"$N����������һ�����Ŀ����ͣ�����ȫ��������������һ����\n"NOR,obj);
	obj->receive_wound("gin",magic,me);
	obj->set_temp("damaged_during_attack", 1);
	COMBAT_D->report_status(obj);

	return 1;
}


int recovers(object obj)
{
	if (obj->query_temp("block_msg/all")>=1)
	    	obj->add_temp("block_msg/all", -1);
	tell_object(obj, HIG"���������ģ�����۾���ʼ���Էֱ���Χ�������ˡ�\n" NOR);
	return 1;
}	

void smart_fight()
{
	int i,max_busy=99;
	object *enemy,target,sword,me=this_object();
	string action;
	object env, *inv;

	env = environment(me);
	inv = all_inventory(env);
	enemy = me->query_enemy();

	if (is_busy())
		return;

	i = random(2);
	switch (i)
	{
	case 0:
		// �߹�����
		message_vision(HIY"\n$N˫��������̨ӡ���૶������ϼ֮�⣬�����컪������ӳ�ԣ���ڤ�𰵣���Ϊ������ͣ�����\n" NOR,this_object());
		message_vision(HIW"������ֻ��$N˫��һ˲�䷢����̫����Ҫҫ�۵Ĺ�â������\n\n" NOR,this_object());

		if (sizeof(enemy))
	        for(i=0; i<sizeof(enemy); i++)
				bbqthem(me, enemy[i]);
		
		perform_busy(3);
		break;
	case 1:
		// �������
		message_vision(HIB"\n$Nһָ����ü�䣬�������������գ����»�������Ļ���ţ���꼯�棬����ӯ񷣬ڤ�����𣮣���\n"NOR,this_object());
		message_vision(WHT"������ɲʱ��·���������������İ��Ĺ�Ӱ���Ʒ������㿹�Ļ�д������󰧺ţ�����\n\n" NOR,this_object());

		if (sizeof(enemy))
	        for(i=0; i<sizeof(enemy); i++)
				bbqthem2(me, enemy[i]);

		perform_busy(3);
		break;
	}

	return;
}


void die()
{
	object me=this_object(),owner,enemy,paper,*sy_inv,things,env=environment(me),soul;
	int j;
	if (!query_temp("last_damage_from"))
	{
		sy_inv = all_inventory(this_object());
		for(j=0;j<sizeof(sy_inv);j++){
			things = sy_inv[j];
			destruct(things);
		}
		delete("reward_npc");
		::die();
		return;
	}
    if(objectp(enemy=query_temp("last_damage_from")))
        if(owner=enemy->query("possessed"))
			enemy = owner;
	::die();
	return;
}

	
void switch_defense(int i)
{
	if (i == 1)
	{
		add("resistance/gin",100);
		add("resistance/sen",100);
		add("resistance/kee",-100);
		set_temp("shield_force/type","atman");
		set_temp("shield_force/ratio",10000);
		set_temp("shield_force/msg",
			BLU"$N"BLU"��ʽ��$n"BLU"��������ϻ���һ������ɫ���ǻ���ʧ���١�\n"NOR);
		message_vision(HIB"\n$N"HIB"����ָ������һ�������Ļ��ڿ����黮����������\n"HIW"һ�����ɫ�����ݶ���$N"HIW"�����֣�Խ��Խ�󣬽�����ס$N"HIW"ȫ��\n"NOR,this_object());
	}
	else
	{
		add("resistance/kee",100);
		add("resistance/gin",-100);
		add("resistance/sen",-100);
		delete_temp("shield_force");
	}
}


void heart_beat()
{
	if (is_fighting())
	{
		set("atman",10000);
		add("counter",1);
		if (query("counter") >= 30)
		{
			set("counter",0);
			switch_defense(1-query("def_type"));
			set("def_type",1-query("def_type"));
		}
	}
	::heart_beat();
}
	
mapping ob_hit(object attacker, object victim,int damage)
{
	mapping data = ([]);
	if (!victim->is_busy())
		return 0;
	victim->stop_busy();
	data["msg"] = CYN"$n���۹Ķ�����$Nһ��֮�������ƮƮ�����˿�ȥ��\n"NOR;
	return data;
}

/*
update here;ask ke about silencer;call mingyue->delete_temp(inquiry_time);ask ke about silencer;updatep /d/bashan/npc/;clone /d/bashan/npc/chu;call chu->ccommand(kill fighter);call chu->ccommand(kill fighter 2);
update here;clone /d/bashan/npc/yawnboy;clone /d/bashan/npc/yawngirl;updatep /d/bashan/npc/;clone /d/bashan/npc/chu;call chu->ccommand(kill justdoit);call chu->ccommand(kill sinny);
*/

/*
�X[ ��- FengYun -�� ]���������[
��[dancing_faery@hotmail.com]�������[
��[ ��annie 09.2003�� ]�������a    ��
��[ ������������¶������ʱ������˪ ��
�^��������������������������������-�a
*/



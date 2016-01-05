inherit NPC;
#include <ansi.h>
#include <combat.h>

void smart_fight();
string do_flee();

void create()	
{
    object weapon;

	set_name("������", ({ "du xiansheng","boss","du"}) );
	set("gender", "Ů��" );
	set("nickname",BLU"�߰�ɽ��"NOR);
    set("title","��ɽׯ");
	set("class","shenshui");

	set("age",44);

	set("spawn_location","/d/eastcoast/village3");

set("long","һλ����ҷ�س�ȹ�ĸ��ˣ�һ�ַǷ����ŵķ��ˡ������껪������ȥ
��ȴ����Ը����֬�����������۽ǵ����ơ������������ž�����Զɽ
����һ�����Ƶİ��ƣ����������۾���ȴ����һ����������ʵ�����
\n���ƺ����ڵȴ���ʲô����ķ��������١���\n\n");

		set("per",30);
    	set("gold", 40);
		set("real_boss",1);
		set("boss",1);	// immune to some rascal skill and ghostcurse.
						// busy resist but not immune.

        set("attitude","friendly");
    
        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: smart_fight() :),
             }) );

        set("combat_exp", 11100000);	// L140. CAP @ L110.
    
        set_skill("dodge", 400);
        set_skill("nine-moon-steps", 300);
        set_skill("force", 200);
        set_skill("nine-moon-force", 300);
        set_skill("sword", 200);
        set_skill("nine-moon-sword", 400);
        set_skill("nine-moon-spirit", 300);
        set_skill("nine-moon-claw",250);
        set_skill("unarmed",250);
        set_skill("parry",200);

		set("pfm/qingpingforce-9moon",1);

		map_skill("unarmed","nine-moon-claw");
        map_skill("force", "nine-moon-force");
        map_skill("dodge", "nine-moon-steps");
        map_skill("sword", "nine-moon-sword");
        map_skill("parry", "nine-moon-sword");
		
		set("max_kee",300000);
		set("max_gin",300000);
		set("max_sen",300000);
        
		setup();

		weapon=carry_object("/obj/weapon/sword");
		weapon->set_name(YEL"ɽ�軨֦"NOR, ({ "branch" }) );
		weapon->set("long"," ");
		weapon->set("value",0);
		weapon->set("nodrop_weapon",1);
		weapon->set("no_get",1);
		weapon->wield();


		weapon=carry_object("/obj/armor/cloth");
		weapon->set_name("ҷ�س�ȹ", ({ "cloth" }) );
		weapon->set("long","ҷ�س�ȹ(Cloth)��");
		weapon->set("value",0);
		weapon->set("no_get",1);
		weapon->wear();
	set("drop/bg",0);
	set("drop/common",100);
	set("drop/rare",0);	
	set("drop/amount",3);
	set("drop/common_drop",({
"/obj/generate/neck_170_10.c",
"/obj/generate/head_170_21.c",
"/obj/generate/cloth2_170_20.c",
"/obj/generate/cloth2_170_10.c",
"/obj/generate/boots_170_11.c",
__DIR__"obj/duf_flower.c",
	}) );
	set("drop/rare_drop",({
"none",
	}) );

}


void die()
{
	object who = query_max_damage_dealer();
	object lotus;
	
	if (random(2)) {
		lotus = new(AREA_XINJIANG"obj/lotus");
		if (lotus) lotus->move(this_object());
	}

	if (!objectp(who))
		who = query_temp("last_damage_from");
		
	if (objectp(who))
		ANNIE_D->generate_drop_item(this_object(),who);

	::die();
	return;
}

int kill_ob(object who)
{
        ::kill_ob(who);
        smart_fight();
        return 1;
}



void smart_fight()
{
	object ob;
	mapping buff;
	object me = this_object();
	int i;
	string msg;
	object ghost;
	object target,*enemy;

	set("force",query("max_force")*2);
	ccommand("exert npc_hurtless");

	if (!ANNIE_D->check_buff(me,"damageshield") && !random(3))
		ccommand("exert chill");

	stop_busy();
	
	if (!ANNIE_D->check_buff(me,"damage_to_heal") && !random(3))
		ccommand("exert huaxue");

	stop_busy();
	
	if (!ANNIE_D->check_buff(me,"powerup") && !random(3))
		ccommand("exert powerup");

	stop_busy();
	
	target = select_opponent();
	ccommand("exert mihunshu");

	if (!random(3))
	{
		add_temp("apply/attack",700);
		add_temp("apply/damage",2000);
		ccommand("perform shuanglengcanxia");
		add_temp("apply/damage",-2000);
		add_temp("apply/attack",-700);
		stop_busy();
		return;
	}

	ob=this_object();
	enemy = ob->query_enemy();
	
	if (query("annie/sh")+24 < time())
	{
		add_temp("apply/attack",480);
		add_temp("apply/damage",3000);
		
		msg=YEL"\n����������Ļ�֦ͻȻһ������һ�������ѻ�������ǧ�����������ˣ�\n"NOR;
		message_vision(msg, ob,target);
		
		for (i=0;i<sizeof(enemy);i++){
			enemy[i]->add_temp("cant_dodge",1);
			COMBAT_D->do_attack(me,enemy[i],TYPE_PERFORM,"");
			enemy[i]->add_temp("cant_dodge",-1);
			stop_busy();
		}			
		
		add_temp("apply/damage",-3000);			
		add_temp("apply/attack",-480);	 
		set("annie/sh",time());
		return;
	}

//	һ����������Main TANK �ļ���

	message_vision("\n    "BMAG HIW"ɽ�迪л\n"NOR,this_object());
	msg=CYN"����$N�����Ŀ���ƿ�а�ɫɽ�軨��������ɫ����Ҳ����һ����а�Ƭ��Ĳ軨һ����
    ���š��������԰ף�һƬƬ��һ��ꡢһ���ص���һ��
    �����Ȼɢ���ˡ�
    ������ָ��Ȼ����һ���������ɢ���ˣ������ͷף�ɢ����$n��ǰ��ɢ����$n���ۡ�
    "HIC"����������ָ����������һ����֦����֦һ��������$n��˫�ۣ�\n"NOR;
	
	message_vision(msg, ob, target);
	
	add_temp("apply/attack",720);
	add_temp("apply/damage",150);

	target->add_temp("apply/no_abs",1);
	COMBAT_D->do_attack(this_object(),target,TYPE_PERFORM,"");
	target->add_temp("apply/no_abs",-1);
	
	if (!random(5))
	if (target->query_temp("damaged_during_attack"))
	{
		ANNIE_D->debuff(target,"powerup");

		if (!ANNIE_D->check_buff(target,"blind"))
		{
			buff =
			([
				"caster":this_object(),
				"who":target,
				"type":"blind",
				"att":"curse",
				"name":"��ħ���ࡤɽ�迪л",
				"buff1":"block_msg/all",
				"buff1_c":1,
				"buff2":"apply/attack",
				"buff2_c":-200,
				"buff3":"apply/parry",
				"buff3_c":-200,
				"time":45,
				"buff_msg":YEL"$N"YEL"ֻ�����۾�һ���ʹ����ʱʲôҲ�������ˡ�\n"NOR,
			]);
			ANNIE_D->buffup(buff);
		}
	}

	add_temp("apply/damage",-150);
	add_temp("apply/attack",-720);

	return;
}


/*
 
               (\~~~/)            
               ( ����)        

               (_____)~��      
   
��������������- FengYun - ������
������������annie 10.2003
������dancing_faery@hotmail.com
*/

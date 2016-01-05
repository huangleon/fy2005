inherit NPC;
#include <ansi.h>
#include <combat.h>

void smart_fight();
string do_flee();

void create()	
{
    object weapon;

	set_name("������", ({ "mingyue xin","boss","mingyue"}) );
	set("gender", "Ů��" );
	set("nickname",BLU"������"NOR);
    set("title","��¥����");
	set("class","legend");

	set("age",17);

	set("spawn_location","/d/biancheng/tas");

set("long","���������ܺ�����Ц�ø��ÿ�������̬�Ⱥ����ţ�װ�����嵭��Ҳ��������������
�������ǵľ�ɫ���ˣ��������߽�����ʱ�򣬾�����ĺ�������ϣ�һƬ��������
���ս����������������������˵����������˵���������Ҹ���\n");
		set("agi", 70);
		set("per",40);
		set("gold", 40);
		set("real_boss",1);
		set("boss",1);	// immune to some rascal skill and ghostcurse.
						// busy resist but not immune.

        set("attitude","friendly");
    
        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: smart_fight() :),
             }) );

        set("combat_exp", 12000000);	// L140. CAP @ L110.
    
        set_skill("dodge", 400);
        set_skill("fall-steps", 300);
        set_skill("force", 200);
        set_skill("divineforce", 300);
        set_skill("sword", 200);
        set_skill("xiaohun-sword", 200);
        set_skill("parry",200);

		set_skill("iron-cloth",200);
        set_skill("spring-water",300);

        map_skill("iron-cloth", "spring-water");
        map_skill("force", "divineforce");
        map_skill("dodge", "fall-steps");
        map_skill("sword", "xiaohun-sword");
        map_skill("parry", "xiaohun-sword");
		
		set("max_kee",500000);
		set("max_gin",500000);
		set("max_sen",500000);
        
		setup();

		weapon=carry_object("/obj/weapon/sword");
		weapon->set_name(HIR"��Ө"NOR, ({ "dagger" }) );
		weapon->set("long"," ");
		weapon->set("value",0);
		weapon->set("nodrop_weapon",1);
		weapon->set("no_get",1);
		weapon->wield();


		weapon=carry_object("/obj/armor/cloth");
		weapon->set_name(CYN"������ˮ�ĳ�ȹ"NOR, ({ "cloth" }) );
		weapon->set("long","������ˮ�ĳ�ȹ(Cloth)��");
		weapon->set("value",0);
		weapon->set("no_get",1);
		weapon->wear();



	set("drop/bg",0);
	set("drop/common",100);
	set("drop/rare",0);	
	set("drop/amount",3);
	set("drop/common_drop",({
"/obj/generate/wrists_170_9.c",
"/obj/generate/surcoat_170_22.c",
"/obj/generate/surcoat_170_12.c",
"/obj/generate/neck_170_20.c",
"/obj/generate/head_170_10.c",
"/obj/generate/boots_170_21.c",
__DIR__"obj/myx_heart.c",
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



int hurting()
{
	message_vision(HIY"\n$N"HIY"�³�һ���೤����Ϣ����ɫת˲���ú���\n"NOR,this_object());
	receive_fulling("kee",query("max_kee")/3);
	receive_fulling("sen",query("max_sen")/3);
	receive_fulling("gin",query("max_gin")/3);
	set("annie/ec",time());
	return 1;

}

int hurting2()
{
	// heal here; ��>��<����gin/sen�˺�.
	message_vision(HIY"\n$N"HIY"�����³�һ�ڳ��������ϵ����ƾ���ת�ۼ価����ʧ��\n"NOR,this_object());
	receive_fulling("kee",query("max_kee"));
	receive_fulling("gin",query("max_gin"));
	receive_fulling("sen",query("max_sen"));
	set("annie/ec2",time());
	return 1;

}

int hurting3()
{
	int i,j;
	object *enemy;
	string msg;
	object me = this_object();
	enemy = query_enemy();
	if (!enemy || !sizeof(enemy))
		return 1;
	msg=HIW"\n������������֡�\n\n���𴦣�����С¥���������磬����������������â��֯������ǧ���Ǻۣ�\n\n"NOR;
	message_vision(msg,me);
	j=0;
	add_temp("apply/damage",730);
	add_temp("apply/attack",420);
	for(i=1;i<=12;i++)
	{
		stop_busy();
		COMBAT_D->do_attack(me,enemy[j],TYPE_PERFORM,WHT"һ��㺮����������Ϯ��$n��"NOR);
		if (j==sizeof(enemy)-1) j=0;
		else j++;
	}
	add_temp("apply/damage",-730);
	add_temp("apply/attack",-420);
	return 1;
}


void smart_fight()
{
	object ob;
	mapping buff;
	object me = this_object();
	int i;
	object ghost;
	object target;

	ccommand("exert npc_hurtless");
//		25 mins
	if (!random(3) && time()>query("annie/ec2")+1500 && query("kee") < query("max_kee")/3)
	{
		message_vision(BBLU HIW"\n����˳��\n"NOR,this_object());
		message_vision(HIG"\n$N"HIG"˫�ֺ�ʮ��������ӽ������\n\n"NOR,this_object());
		perform_busy(10);
		// delay 20,��ȡ�����ʱ����ҵ�����
		call_out("hurting2",20);
	}

	if (is_busy())
		return;

//		5 mins
	if (!random(3) && time()>query("annie/ec")+300 && (
		query("kee") < query("max_kee")/3*2
		|| query("sen")< query("max_sen")/3*2
		|| query("gin")< query("max_gin")/3*2)
		)
	{
		message_vision(BBLU HIW"\n���ݻ�Ԫ\n"NOR,this_object());
		message_vision(HIG"\n$N"HIG"Ʈ�����ˣ����ػ�ӡ��ת��Ϣ�����������Ƴ�������\n\n"NOR,this_object());
		perform_busy(10);
		// delay 20,��ȡ�����ʱ����ҵ�����
		call_out("hurting",20);
	}

	if (is_busy())
		return;

	if (!random(3))
		if (ccommand("perform force.check_gspm"))
			ccommand("perform force.guishenpomie");

	if (is_busy())
		return;

	switch (random(5))
	{
	case 0:
	case 1:
		if (time()>query("annie/ex")+8)
		{
			set("annie/ex",time());
			target = select_opponent();

			message_vision(BGRN WHT"\n������\n"NOR,this_object());
			message_vision(BCYN WHT"\n�ƹ���ֻ��һ���������ɵ���Ӱ����һ����С��¥��ɲʱ����������\n"NOR,this_object());

			add_temp("apply/attack",720);
			add_temp("apply/damage",150);

			COMBAT_D->do_attack(this_object(),target,TYPE_PERFORM,CYN"һ�󵭵����������������$nϮȥ������"NOR,"�˺���
"CYN"$nһ�����ԣ�������������"NOR);
			if (target->query_temp("damaged_during_attack"))
				target->add("force",target->query("force")>250?-250:-target->query("force"));
			add_temp("apply/damage",-150);
			add_temp("apply/attack",-720);
		}
		break;
	case 2:		
		if (time()>query("annie/exxx")+ 10)		// hmm, ���ǲ��Ǹð������ӿ�������ɵɵ����������
		{
			set("annie/exxx",time());
			message_vision(BMAG HIW"\nǧ���Ǻ�\n"NOR,this_object());
			message_vision(HIW"\n��������ɫӫ�࣬˫��΢�����У�С¥�ڵĵƹ��������ƺ�Ҳ���˼��֡�\n"NOR,this_object());
			perform_busy(4);
			call_out("hurting3",8);
		}
	}

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


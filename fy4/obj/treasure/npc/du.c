inherit NPC;
#include <ansi.h>
#include <combat.h>

void smart_fight();
string do_flee();

void create()	
{
    	object weapon;

		set_name("��ͩ��", ({ "du tongxuan","boss", "du" }) );
		set("gender", "����" );
		set("nickname",BLU"����ѧʿ"NOR);
    	set("title","Ȩ�㾩�� �ϰ�");
		set("class","official");
set("long","����ʩʩ��վ����ˮͤ���ϣ��ܸߣ����ݣ�������������̬�ȼ�˹�ģ���
���䲻��������ȴ�Ѱ߰ף�һ���������������ϣ��·�������ֲ��ݣ�
ȴ�ִ����߷����ϣ����˾����Ҷ�����˿�����ӡ�\n");

		set("spawn_location","/d/jinan/pavtop");

        set("gender", "����" );
    	set("agi", 70);
    	set("gold", 40);
		set("real_boss",1);
		set("boss",1);	// immune to some rascal skill and ghostcurse.
						// busy resist but not immune.

        set("attitude","friendly");
    
        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: smart_fight() :),
             }) );

        set("combat_exp", 8600000);	// L125. CAP @ L110.
    
        set_skill("unarmed", 400);
        set_skill("changquan",400);
		set_skill("perception",500);
		set_skill("dodge",300);
		set_skill("puti-steps",400);
		
		map_skill("dodge","puti-steps");
        map_skill("unarmed", "changquan");
		
		set("max_kee",150000);
		set("max_gin",150000);
		set("max_sen",150000);
        
		setup();

		weapon=carry_object("/obj/armor/cloth");
		weapon->set_name(HIB"����ɫ�ĳ���"NOR, ({ "cloth" }) );
		weapon->set("long","����ɫ�ĳ���(Cloth)��");
		weapon->set("value",0);
		weapon->wear();

		set_temp("apply/attack",230);	// ��һ������ʵ����̫���㡤�⡤�ˣ�����

	
	set("drop/fixed_amount",1);
	set("drop/fixed_drop", ({		// L80-90 books
			BOOKS"class/cloud-dance_yegui_2",
			BOOKS"class/dragonstrike_zjbl_3",
			BOOKS"class/iceheart_buffup_3",
			BOOKS"class/xueyeqianzong_wolverine_3",
			BOOKS"class/nine-moon-claw_weiwoduzun_2",
			BOOKS"class/yijinjing_shield_2",
			BOOKS"class/yue-spear_juechufengsheng_2",
	}));
	set("drop/bg",0);
	set("drop/common",100);
	set("drop/rare",0);	
	set("drop/amount",3);
	set("drop/common_drop",({
"/obj/generate/surcoat_130_8.c",
"/obj/generate/surcoat_130_20.c",
"/obj/generate/neck_130_18.c",
"/obj/generate/head_130_8.c",
"/obj/generate/cloth3_130_18.c",
"/obj/generate/cloth1_130_8.c",
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
	// heal here; �� �� ����gin/sen�˺�.
	message_vision(HIY"\n$N"HIY"�³�һ���೤����Ϣ����ɫת˲���ú���\n"NOR,this_object());
	receive_fulling("kee",query("max_kee")/3);
	receive_fulling("sen",query("max_sen")/3);
	receive_fulling("gin",query("max_gin")/3);
	set("annie/ec",time());
	return 1;

}

void smart_fight()
{
	object ob, me;
	mapping buff;
	object *enemy;
	int i;
	
	me = this_object();
	
	// All str down please ....., sq's game now
	enemy=query_enemy();
	if (!random(3))
	{
		message_vision(BCYN WHT"\n�żų���\n"NOR,this_object());
		message_vision(CYN"\n����䳤�����Σ�����ڤڤ������һƬ�ռš�ԶԶ�ģ��д���ɹ�������������\n\n"NOR,this_object());
		for (i=0;i<sizeof(enemy);i++) {
			if (objectp(ob = enemy[i])) {
				if (ANNIE_D->check_buff(ob,"strup"))	continue;
				buff =
				([
					"caster":this_object(),
					"who":ob,
					"type":"strup",
					"att":"curse",
					"name":"��ħ���ࡤ�żų���",
					"buff1":"apply/strength",
					"buff1_c":-20-random(50),
					"time":60,
					"buff_msg":CYN"$N"CYN"ͻ����̬��Ȼ��һʱ�侹�²������֣���������\n"NOR,
				]);
				ANNIE_D->buffup(buff);
			}
		}	
	}
	
	if (!random(3) && time()>query("annie/ec")+ 220 && 
		(query("kee")<query("max_kee")/3 || query("sen")< query("max_sen")/3
		|| query("gin")< query("max_gin")/3))	// 4min/cast.
	{
		message_vision(BBLU HIW"\n���ݻ�Ԫ\n"NOR,this_object());
		message_vision(HIG"\n$N"HIG"Ʈ�����ˣ����ػ�ӡ��ת��Ϣ�����������Ƴ�������\n\n"NOR,this_object());
		perform_busy(10);
		// delay 20,��ȡ�����ʱ����ҵ�����
		call_out("hurting",20);
	}

	set("force",query("max_force")*2);
	
	// about 4k dmg/5 hits	enough time to heal
	if (me->query_temp("xxx/1")+ 30 < time()) {
		ccommand("perform yuhuan");	
		me->set_temp("xxx/1", time());
		me->stop_busy();
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


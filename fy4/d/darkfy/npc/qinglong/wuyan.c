//Tushen@Fygroup
//Based on Silencer's code.Copyrights all reserved.
#include <ansi.h>
inherit SMART_NPC;
int curse_me();

void create()
{
    	set_name("����",({"wuyan","wu","wu yan"}));
    	set("title",HIG"����"NOR);
    	set("nickname",HIY"Married But Available"NOR);
    	set("long","
����һ�������ӳ�����ͷ��һ��Ѽ��ñ����Ȼ���ϵ�Ц�ݺܺͰ���������Ȼ
���β�����ǵ���Ĩ��Ц��\n");
    	set("gender","����");
    	set("age",37);
    	set("no_arrest",1);
		  set("always_duxin",1);
		  set("combat_exp",20000000);
		  set("attitude","friendly");
      set("reward_npc",1);
		  set("difficulty",50);      
		  set("perform_weapon_attack", "assassin/sword/lefthand-sword/duxin");
		  set("perform_buff_1", "berserker/force/gaunforce/damageup");
		  set("perform_buff_2", "berserker/force/gaunforce/powerup");
			set("perform_buff_3", "berserker/force/gaunforce/forceup");
		  set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([
	     		50: 	(: curse_me() :),
        ]) );    
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(40) :),
        }) );
    	set("chat_chance",1);
    	set("chat_msg",({
			"���԰�Ȼ���������ǳ����ٵĳ��������ǳ����ٵĴ����٣��ǳ����ٵ��٣�����\n",	
			"����˵������֪��TJJTDS������д��ô��"
		}) );
        set_skill("move", 270);
        set_skill("perception", 300);
        set_skill("force", 270);
        set_skill("spells", 300);
        set_skill("unarmed", 280);
        set_skill("parry", 300);
        set_skill("dodge", 280);
        set_skill("magic", 300); 
        set_skill("sword", 300);
        
        set_skill("gaunforce", 200);
		    set_skill("fengyu-piaoxiang", 200);
        set_skill("lefthand-sword", 230);
        
        map_skill("sword","lefthand-sword");
        map_skill("force", "gaunforce");
        map_skill("dodge","fengyu-piaoxiang");
        map_skill("move","fengyu-piaoxiang");
        map_skill("parry","lefthand-sword");
		setup();
    	carry_object("/obj/weapon/sword",([	
    						"name":  HIB"����"NOR,
    						"long": "����û���дʲô��\n",
    						 ]))->wield();
    						 
    						 carry_object("/obj/armor/cloth",([	
    						"name":  "����T��",
    						"long": "���������T-shirt����ֵ���ǡ�\n",
    						 ]))->wield(); 
    						 carry_object("/obj/armor/hat",([	
    						"name":  "Ѽ��ñ",
    						"long": "һ��Ѽ��ñ������ȥ�������\n",
    						 ]))->wield(); 
}


int curse_me() {
	object ob, *enemy;
	ob=this_object();
	enemy=query_enemy();
	switch (random(4)) {
		case 0: message_vision(HIG"\n$N΢Ц�����ˣ������������ģ�������Ҫ���������ġ�\n"NOR,ob);
			break;
		case 1: message_vision(HIW"\n$N���е��ʵ���������գ���\n"NOR,ob);
			break;
		case 2: message_vision(HIR"\n$N̾�˿�����ֻҪ�������ʴȵ��ģ���Ͳ�������������������\n"NOR,ob);
			break;
			case 3: message_vision(HIR"\n$N��˵�ţ�ȥ�����ڳ¼Ҵ���ʶ��һλ������\n
				���ֹ���������Ǯ������ͯ�����ۡ���\n"NOR,ob);
			break;
	}	
	foreach (object x in enemy){
		tell_object(x,YEL"�������Եĺ�����������ͷʹ����Ҫ�ѿ���һ������������\n"NOR);
		x->receive_wound("sen",500,ob);
	}
	return 1;
}
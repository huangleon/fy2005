//Tushen@Fygroup
//Based on Silencer's code.Copyrights all reserved.
inherit SMART_NPC;
#include <ansi.h>

void create()
{
        set_name("�ú�", ({ "haohao" }) );
        set("gender", "Ů��");
        set("age", 23);     
      	set("chat_chance", 1);
/*	set("chat_msg", ({
"�ú�������������ӣ������̺���ǧ�����飬������⡣\n",
"�úö�ݺݵĵ�������һ�ۡ�\n"
	}) );*/
        set("attitude", "friendly");
        set("title",HIR"��ȸ"NOR);
        set("nickname", HIG"����ǧ�ؿ����� �ﻻ���Ƽ�����"NOR);
        set("score", 200000);
        set("reward_npc", 1);
		    set("difficulty",50);
		    set("class","baiyun");
        set("death_msg",CYN"\n$N������������ң�\n"NOR);
        set("combat_exp", 16000000);        
        
    set("perform_busy_d", "bat/dodge/fengyu-piaoxiang/zonghengsihai");
		set("perform_weapon_attack", "baiyun/magic/music/bainiao");
		set("perform_weapon_attack2", "baiyun/magic/music/guanglingsan");
		set("perform_weapon_attack3", "demon/blade/heavendance/yuexierenjing");
		set("perform_buff_1", "berserker/force/gaunforce/damageup");
		set("perform_buff_2", "berserker/force/gaunforce/powerup");
		  set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(100) :),
        }) );
          
        set_skill("move", 270);
        set_skill("perception", 300);
        set_skill("force", 270);
        set_skill("spells", 300);
        set_skill("unarmed", 280);
        set_skill("parry", 300);
        set_skill("dodge", 280);
        set_skill("magic", 300); 
        set_skill("blade", 300);
        
        set_skill("gaunforce", 180);
		    set_skill("fengyu-piaoxiang", 200);
        set_skill("heavendance", 230);
        set_skill("music", 200);
        
        map_skill("blade","heavendance");
        map_skill("force", "gaunforce");
        map_skill("dodge","fengyu-piaoxiang");
        map_skill("move","fengyu-piaoxiang");
        map_skill("parry","heavendance");
        map_skill("magic","music");
        setup();

    	carry_object("/obj/weapon/blade",([	
    						"name":  "����",
    						"long": "����û���дʲô��\n",
    						 ]))->wield();  
    						 
    	carry_object("obj/music/chunlei");
    	
    	carry_object("/obj/armor/cloth",([	
    						"name":  "��������",
    						"long": "һ��������ë��֯�ɵ��·���͸������Ĺ�â��\n",
    						 ]))->wear();  
}
/*int direct()
{   
    	message_vision("�ú����Ƶ�����Զ�����ǣ����Ѿ��Ǻܾ���ǰ�����飬
    	��ȥ�ģ���������ȥ���ˡ�\n\n",this_object(),me);
    	return 1;
}*/


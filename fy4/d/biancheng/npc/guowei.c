#include <ansi.h>
inherit SMART_NPC;


void create()
{
    	set_name("����",({"guo wei","guo","guowei"}));
	set("title","��");
   	set("long","
��ɫ���׵����ˣ������Ǹ���ĺ�����ˣ���վ��������˻���ͦ�ñ�ֱ��
�紵�����ĳ��ף�����˿��ɾ��ţ������۾���ȴ����Ѫ˿��\n");
     	set("gender","����");
    	set("age",72);
    	set("group","guo");
    	 	
    	set("combat_exp",7500000);  
    	set("attitude", "friendly");
    	
    	set("reward_npc",1);
    	set("difficulty",3);
    	    	
    	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([

        ]) );    	
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(20) :),
        }) );
    	set("chat_chance",1);
    	set("chat_msg",({
		"���������Ц���е������ã��ú��ӣ��������չ��ģ��� \n",
    	}) );    	    	
    	    	
	auto_npc_setup("wang",200,160,0,"/obj/weapon/","fighter_w","shenji-blade",2);
	
	setup();
    	carry_object("/obj/armor/cloth",([	
    						"name":  WHT"������"NOR,
    						"long": "һ���Ұ׵����¡�\n",
    						 ]))->wear();
    	carry_object("/obj/weapon/blade",([
    						"name": "��ͷ��",
    						"long": "һ���󵶣�����������������\n",
    						"value": 0,
    						  ]))->wield();  
}

/*
void die()
{
        object me, owner;
        if(objectp(me=query_temp("last_damage_from") ))     
        if(owner=me->query("possessed")) {
		me = owner;
	} 
        if(me->query("marks/wanma/�ײ�֮��"))
                        me->set_temp("marks/wanma/�����嶾e",1);
        ::die();
}*/
#include <ansi.h>
inherit SMART_NPC;

void create()
{
    	set_name("���",({"sun ju","sun","sunju"}));
	set("long","
һ�ŰͶ�����ͷ­�����Ϲ�ͺͺ�ģ���һ��ͷ����û�У�һ��������͸�࣬
���﷢�ף������Ǵ��Ÿ���ͭ��ߡ���ȴ��������ߣ���Ϊ���ı����ڶ�����
�ڳ��������������������������ӣ����������кܾö�û�к������ˣ����ѵ�
�����ˣ��ѵ��Ǹ��մӵ������ӳ����Ķ��\n");
   	
     	set("gender","����");
     	set("title","����");
    	set("age",52); 	 	
    	
    	set("combat_exp",9500000);  
    	set("attitude", "friendly");
    	
    	set_skill("lingxi-zhi",200);
    	set_skill("iron-cloth",200);
    	set_skill("jin-gang",200);
    	set_skill("unarmed",250);
    	set_skill("parry",200);
    	set_skill("dodge",200);
    	set_skill("five-steps",200);
    	
    	map_skill("unarmed","lingxi-zhi");
    	map_skill("iron-cloth","jin-gang");
    	map_skill("dodge","five-steps");
    	
    	setup();
    	carry_object("/obj/armor/cloth")->wear();
 
}


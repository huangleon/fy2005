#include <ansi.h>
inherit SMART_NPC;
inherit INQUIRY_MSG;

void create()
{
    	set_name("����ͷ",({"old zhang","zhang"}));
//    	set("title","�����ͻ�");
   	set("long","
����ͷ�Ǹ��¿�����ˣ�һ������ĬĬ������˸��ţ�Ψһ���䱦������
����Ů����ÿ�����գ������ὫԺ�����ĹϺ������������������ȥ��
��һ���ˣ���ʾ�������˵İ����𾴣�����˾��Ǿջ�԰���ϲ���\n");
   	
     	set("gender","����");
     	     	
    	set("age",62); 	 	
    	set("int",52);
    	set("cor",30);
    	set("cps",20);
    	
    	set("combat_exp",500000);  
    	set("attitude", "friendly");
    	
    	set_skill("staff",200);
    	set_skill("parry",200);
    	set_skill("dodge",200);
    	
    	set("inquiry", ([
 		"����Ů��": "��������ϲ�������С�����û���ˣ��ⲻ����������Щ����ȥл��
 ���ء�\n",
 		"Ů��":	     "��������ϲ�������С�����û���ˣ��ⲻ����������Щ����ȥл��
 ���ء�\n",
 		"�ϲ�":	"�ϲ�������һ����Ψһ�����������ˡ��������Ŷ�ô�����
�ѣ��ϲ�����Ϊ�ҽ�����������˶�ô���ί�����ϲ������ҳ�����Ϊ��
���ֹ�����ֻ����Щɥ�������˲Ż���ϲ����ԡ�\n",
		"�ϲ�":	"�ϲ�������һ����Ψһ�����������ˡ��������Ŷ�ô�����
�ѣ��ϲ�����Ϊ�ҽ�����������˶�ô���ί�����ϲ������ҳ�����Ϊ��
���ֹ�����ֻ����Щɥ�������˲Ż���ϲ����ԡ�\n",
   	]));
    	
    	set("death_msg",CYN"\n$N�϶�������˵�����ϲ�������Ϊ�����ҡ������𡣡��ġ�����\n"NOR);  	
    	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([

        ]) );    	
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({

        }) );
    	set("chat_chance",1);
    	set("chat_msg",({
		"����ͷ˵�����ϲ����Ǹ�����ѽ����\n",
    	}) );    	    	
    	
		
	setup();
    	carry_object("/obj/armor/cloth")->wear();
 	carry_object("/obj/item/biandan")->wield();
 	carry_object("/obj/food_item/watermelon");
}


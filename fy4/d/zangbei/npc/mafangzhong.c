#include <ansi.h>
inherit SMART_NPC;
inherit INQUIRY_MSG;

int estate();

void create()
{
    	set_name("����",({"ma fangzhong","ma"}));
	set("title","��������");
   	set("long","
��������˾�����������һ�����������������ؾأ��ӳ��������ڣ�
����û�������κ�һ�����˾��þ���������¡����˾���Ӧ�ó��׵�ʱ��
���ͳ����ף����˾���Ӧ��������Ů��ʱ�����Ͳ��಻��������������
�����������Ⱥá�\n");
     	
     	set("gender","����");
     	set("group","ma");
     	set("age",32); 	 	
    	
    	set("marry_name","������");
    	set("marry","ma yueyun");
    	
    	set("combat_exp",5100000);  
    	set("attitude", "friendly");
    	
    	set("inquiry", ([
 		"�ϲ�":	"�ϲ����ҵ��ֵܣ��ҵ����ѣ�Ҳ���ҵĸ�ĸ����û����������ʮ����
��ʱ���Ѿ�����ɱ���ˡ�",
		"����":	"�ϲ����ҵ��ֵܣ��ҵ����ѣ�Ҳ���ҵĸ�ĸ����û����������ʮ����
��ʱ���Ѿ�����ɱ���ˡ�",
   	]));
    	
    	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([

        ]) );    	
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	    	 (: auto_smart_fight(30) :),
        }) );
    	set("chat_chance",1);
    	set("chat_msg",({
		"\n�����ˬ���紵�����ϣ�����Ҳ���ȡ����л���Ժ���������ţ����������
�Ƕ��ΰΣ��᲻�ûط�˯����\n",
    	}) );    	    	
    	
		auto_npc_setup("wang",200,200,0,"/obj/weapon/","fighter_u","dragonstrike",1);
	
		setup();
    	carry_object("/obj/armor/cloth")->wear();
    	carry_object(__DIR__"obj/cup");
 
}


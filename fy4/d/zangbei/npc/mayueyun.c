#include <ansi.h>
inherit SMART_NPC;

int estate();

void create()
{
    	set_name("������",({"ma yueyun","ma"}));
    	set("title","�����ͻ�");
   	set("long","
���е�̫̫���ͻۡ����յúܺã���������һ���һ�췢����������
������Ǹ�����С�����ӡ���̫̫����˵ʲô�����ж�ǧ���ٹˡ�
���������̫̫��Сϱ���ǣ�������Ľ��̫̫��һ�����ϱ��ӻ��˵£���
�Բż޵�����һλ���ɷ�\n");
   	
     	set("gender","Ů��");
     	set("group","ma");
     	
    	set("age",32); 	 	
    	
    	set("marry_name","����");
    	set("marry","ma fangzhong");
    	
    	set("combat_exp",500000);  
    	set("attitude", "friendly");
    	
    	set("inquiry", ([
 		"*":	"�Һ��ٳ��ţ����ʵ���Щ�Ҷ���֪��ѽ��\n",
   		]));

    	set("chat_chance",1);
    	set("chat_msg",({
		"�����ƿ��˿���ߵ�һ˫��Ů�����������Ц�š�\n",
    	}) );    	    	
    	
		
		setup();
    	carry_object("/obj/armor/cloth",([	"name": "�಼ȹ",
    						"long": "һ���ҳ����Ĳ�ȹ��\n",
    						 ]))->wear();    
 
}


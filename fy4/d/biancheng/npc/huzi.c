#include <ansi.h>
inherit SMART_NPC;


void create()
{
    	set_name("С����",({"xiao huzi","huzi"}));
   	set("long","
����������£�ͷ��һ��������С���ӣ�Ҳ��������ϵס�����ӳ�����Ȼ
�ر���С�����۾�ȴ�ر��һ˫������������ӣ���ͣ��ת��תȥ���Ե�
�ֻ��á��ֻ��顣��\n");
     	
     	set("gender","����");
    	set("age",12);
		set("group","guo");
		
		set("max_kee",3000);
		set("max_sen",3000);
		set("max_gin",3000);
		
    	set("combat_exp",1000000);  
    	set("attitude", "friendly");
    	
    	setup();
    	carry_object("/obj/armor/cloth",([	"name": RED"��籰�"NOR,
					"long": "һ����籰���\n",
					 ]))->wear();   
    
}

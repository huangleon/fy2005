#include <ansi.h>
inherit SMART_NPC;

void create()
{
    	set_name("÷����",({"meihuadao","dao"}));
	set("title",MAG"ǧ�滨��"NOR);
   	set("long","
��Ȼ������㣬����������׺��÷������ɴ����ʹ��ˣ����Ǽ������������
�����壬�����ϸ����֫������޳���˫�ȣ���˼�ͦ�ġ�������˭��������
�º����أ�\n");
     	set("gender","Ů��");
    	set("class","huashan");
    	set("combat_exp",400000);  
    	set("age",22);
    	 	
    	set("cor",40);
    	set("per",40);
    	
    	set("NO_KILL","�������������ĺ��֣�\n");   	 	
    	   	 	
    	set_skill("anxiang-steps",100);
    	set_skill("dodge",100);
    	set_skill("move",100);
    	set_skill("unarmed",100);
    	set_skill("zhaixin-claw",100);
    	set_skill("throwing",100);
    	set_skill("tanzhi-shentong",100);
    	set_skill("force",100);
    	set_skill("hanmei-force",100);
    	
    	map_skill("force","hanmei-force");
    	map_skill("unarmed","zhaixin-claw");
    	map_skill("throwing","tanzhi-shentong");
    	map_skill("move","anxiang-steps");
    	map_skill("dodge","anxiang-steps");
    	
    	set("inquiry", ([
   	]));
    	
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({

        }) );  	
    		
	setup();
    	carry_object(__DIR__"obj/meihua_cloth")->wear();    
}

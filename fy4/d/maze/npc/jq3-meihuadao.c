#include <ansi.h>
inherit SMART_NPC;

void create()
{
    	set_name("÷����",({"meihuadao","dao"}));
	set("title",MAG"�����"NOR);
   	set("long","�����鱧�ڻ���İ��������һ�Ų��ڷ�ɫ��ɴ����������ֳ�����֮ɫ��\n");
     	set("gender","Ů��");
     	set("age",20);
    	
    	set("attitude","friendly");
    	set("class","huashan");
    	set("combat_exp",400000);  
    	    	   	 	
    	set_skill("anxiang-steps",100);
    	set_skill("dodge",100);
    	set_skill("move",100);
    	set_skill("unarmed",100);
    	set_skill("zhaixin-claw",100);
    	set_skill("throwing",100);
    	set_skill("tanzhi-shentong",100);
    	set_skill("force",100);
    	set_skill("hanmei-force",100);
    	set_skill("perception",200);
    	
    	map_skill("force","hanmei-force");
    	map_skill("unarmed","zhaixin-claw");
    	map_skill("throwing","tanzhi-shentong");
    	map_skill("move","anxiang-steps");
    	map_skill("dodge","anxiang-steps");
    	
	set("NO_KILL","÷���������ڰ��֮�У�������޷������� ��\n");
	set_temp("condition_type",WHT "<�����>" NOR);
    		
	setup();
    	carry_object(__DIR__"obj/meihua_cloth")->wear();    
}

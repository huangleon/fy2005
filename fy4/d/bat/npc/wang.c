inherit NPC;
#include <ansi.h>
void create()
{
    	set_name("������", ({ "wang tian shou","wang" }) );
    	set("title", HIR "��������" NOR);
    	set("gender", "����" );
    	set("age", 55);
    
    	set("long","
�����˵�һ˫���ֻ����ݣ������ľ�����ǻ���ӥצ�ŵĵ�һ���֡���ʮ 
��ǰ�ѽ�����֮λ����������ֶ����ά�ܣ��������Ѻ����ڽ����߶��� 
\n"
        );
    	set("chat_chance", 1);
    	set("chat_msg", ({
        	"��������Ϊ���صĵ�������֪��֪���½��������ֳ��˸����µ����\n",
            }) );
    	set("attitude", "friendly");
    
    	set_skill("unarmed", 200);
    	set_skill("move", 80);
    	set_skill("dodge",150);
    	set_skill("parry",150);
    	set_skill("five-steps",100);
    	set_skill("eagle-claw",150);
    	map_skill("unarmed", "eagle-claw");
    	map_skill("dodge","five-steps");
    
    	set("combat_exp", 1000000);
    	
    	setup();
    	carry_object("/obj/armor/cloth")->wear();
    	carry_object(__DIR__"obj/mengui");
}

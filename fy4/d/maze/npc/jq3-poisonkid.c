#include <ansi.h>
inherit MAZE_NPC;

void create()
{
    	set_name("�嶾ͯ��",({"nefarious kid","kid"}));
	set("title",HIR"������"NOR);
        set("nickname",HIB"�嶾����"NOR);
        set("long",WHT"
�嶾ͯ���������˼�Ϊ����࣬����Ϊ��Ѱ��һ���������������ֳ��������
��ǰ�������ΰ�С����ͯ�����ϴ�������ȹ��¶��һ˫С�ȣ�����ͷҲ��С��
�۾�ȴ�������ƣ�������Թ����\n"NOR);
     	set("gender","����");
    	
     	set("age",12);
        set("combat_exp", 8000000);
	set("boss",1);
	set("zombie-killer",1);
	
        set("attitude", "aggressive");
        
        set("experience",1000);
	set("potential",1000);
	set("money",2000);
	set("toughness",300);
        
        set("chat_chance", 1);
        set("chat_msg", ({
                name()+"�ȵ���ʲô�˸�˽���ƽ�����\n",
        }) );

	set("officer-killer",1);		
	set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
	       	(: auto_smart_fight(100) :),    
        }) );
	
	auto_npc_setup("liaoyin",300,250,1,"/obj/weapon/","fighter_w","herb",1);

	setup();
    	carry_object("/obj/armor/skirt",([	"name": "��ȹ",
					"long": "һ��ɫ�������Ķ�ȹ��\n",
					 ]))->wear();     
}
